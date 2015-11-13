#include "ControlProgram.h"

ControlProgram::ControlProgram()
{
    informationSource = NULL;
    processingUnit = NULL;
    statisticsBlock = NULL;
    memory = NULL;
    endModelingTime = 0.0;
    currentModelingTime = 0.0;
    requestDropNumber = 0;
    requestReturnNumber = 0;
    requestCounter = 0;
    CleanTimeArray();
}

ControlProgram::~ControlProgram()
{
    if (informationSource)
    {
        delete informationSource;
        informationSource = NULL;
    }
    if (processingUnit)
    {
        delete processingUnit;
        processingUnit = NULL;
    }
    if (statisticsBlock)
    {
        delete statisticsBlock;
        statisticsBlock = NULL;
    }
    if (memory)
    {
        delete memory;
        memory = NULL;
    }
}

void ControlProgram::ConfigureSystem(double endModelingTime, int maxMemorySize,
                     double a, double b, double matExp, double sigma, double maxBorderForNormalGenerator,
                     int requestDropPercent, int requestReturnPercent)
{
    try
    {
        if (endModelingTime <= 0 || maxMemorySize <= 0 || sigma < 0 || sigma == maxBorderForNormalGenerator ||
                requestDropPercent < 0 || requestDropPercent > 100 || requestReturnPercent < 0 ||
                requestReturnPercent > 100)
            throw ErrorInputDataException("Error input parameters in ControlProgram::ConfigureSystem");
        informationSource = new InformationSource(sigma, matExp, 0, maxBorderForNormalGenerator, 12);
        processingUnit = new ProcessingUnit(a, b);
        statisticsBlock = new StatisticsBlock();
        memory = new Memory(maxMemorySize);

        connect(statisticsBlock, SIGNAL(CollectStatisticsSignal(int,int,int,double)), this,
                SLOT(StatisticsCollected(int,int,int,double)));

        this->endModelingTime = endModelingTime;

        timeArray[INFORMATION_SOURSE_INDEX] = informationSource->GenerateRequestTime();
        timeArray[PROCESSING_UNIT_INDEX] = IDLE_TIME;

        requestDropNumber = requestDropPercent / 100;
        requestReturnNumber = requestReturnPercent / 100;
    }
    catch (std::bad_alloc& exception)
    {
        throw AllocMemoryException("Erro allocate memory in ControlProgram::ConfigureSystem");
    }
}

void ControlProgram::StartModeling()
{
    for (currentModelingTime = 0.0; currentModelingTime <= endModelingTime; currentModelingTime)
    {
        statisticsBlock->CollectStatistics(memory->Size(), memory->GetDropRequestNumber(), currentModelingTime,
                                           processingUnit->GetWorkingTime());
        currentModelingTime = GetMinTime();
        RealizeEvents();
    }
    emit ModelingFinishedSignal();
}

double ControlProgram::GetMinTime()
{
    double minTime = timeArray[0];
    for (int i = 1; i < ARRAY_SIZE; i++)
    {
        if (timeArray[i] < minTime && timeArray[i] != IDLE_TIME)
            minTime = timeArray[i];
    }
    return minTime;
}
void ControlProgram::RealizeEvents()
{
    if (fabs(timeArray[PROCESSING_UNIT_INDEX] - currentModelingTime) < EPSILON &&
            timeArray[PROCESSING_UNIT_INDEX] != IDLE_TIME)
    {
        timeArray[PROCESSING_UNIT_INDEX] = IDLE_TIME;
        if (requestCounter < requestReturnNumber)
        {
            Request request(currentModelingTime);
            memory->PutRequest(request);
            requestCounter++;
        }
        else
            requestCounter = 0;
    }
    if (fabs(timeArray[INFORMATION_SOURSE_INDEX] - currentModelingTime) < EPSILON)
    {
        Request request(currentModelingTime);
        memory->PutRequest(request);
        timeArray[INFORMATION_SOURSE_INDEX] = informationSource->GenerateRequestTime() + currentModelingTime;
    }
    if ((int)timeArray[PROCESSING_UNIT_INDEX] == IDLE_TIME)
    {
        if (!memory->isEmpty())
        {
            Request request = memory->GetRequest();
            timeArray[PROCESSING_UNIT_INDEX] = processingUnit->GetProcessTime() + currentModelingTime;
        }
    }
}

void ControlProgram::CleanTimeArray()
{
    for (int i = 0; i < ARRAY_SIZE; i++)
        timeArray[i] = 0.0;
}

void ControlProgram::StatisticsCollected(int currentRequestsNumberInMemory, int dropRequestNumber,
                                         int optimalQueueSize, double procUnitLoadKoff)
{
    emit StatisticsCollectedSignal(currentRequestsNumberInMemory, dropRequestNumber, optimalQueueSize, procUnitLoadKoff);
}
