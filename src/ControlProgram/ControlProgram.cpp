#include "ControlProgram.h"

ControlProgram::ControlProgram()
{
    informationSource = NULL;
    processingUnit = NULL;
    statisticsBlock = NULL;
    memory = NULL;

    endModelingTime = 0.0;
    currentModelingTime = 0.0;
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
                     double a, double b, double matExp, double sigma, double maxBorderForNormalGenerator)
{
    try
    {
        if (endModelingTime <= 0 || maxMemorySize <= 0 || sigma < 0 || sigma == maxBorderForNormalGenerator)
            throw ErrorInputDataException("Error input parameters in ControlProgram::ConfigureSystem");
        informationSource = new InformationSource(sigma, matExp, 0, maxBorderForNormalGenerator, 12);
        processingUnit = new ProcessingUnit(a, b);
        statisticsBlock = new StatisticsBlock();
        memory = new Memory(maxMemorySize);

        connect(statisticsBlock, SIGNAL(CollectStatisticsSignal(int)), this, SLOT(StatisticsCollected(int)));

        this->endModelingTime = endModelingTime;

        timeArray[INFORMATION_SOURSE_INDEX] = informationSource->GenerateRequestTime();
        timeArray[PROCESSING_UNIT_INDEX] = processingUnit->GetProcessTime();
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
        statisticsBlock->CollectStatistics(memory->Size());
        currentModelingTime = GetMinTime();
        RealizeEvents();
    }
}

double ControlProgram::GetMinTime()
{
    double minTime = timeArray[0];
    for (int i = 1; i < ARRAY_SIZE; i++)
    {
        if (timeArray[i] < minTime)
            minTime = timeArray[i];
    }
    return minTime;
}
void ControlProgram::RealizeEvents()
{
    if (timeArray[INFORMATION_SOURSE_INDEX] <= currentModelingTime)
    {
        Request request(currentModelingTime);
        memory->PutRequest(request);
        timeArray[INFORMATION_SOURSE_INDEX] = informationSource->GenerateRequestTime();
    }
    if (timeArray[PROCESSING_UNIT_INDEX] <= currentModelingTime)
    {
        if (!memory->isEmpty())
        {
            Request request = memory->GetRequest();
            timeArray[PROCESSING_UNIT_INDEX] = processingUnit->GetProcessTime();
        }
    }
}

void ControlProgram::CleanTimeArray()
{
    for (int i = 0; i < ARRAY_SIZE; i++)
        timeArray[i] = 0.0;
}

void ControlProgram::StatisticsCollected(int currentRequestsNumberInMemory)
{
    emit StatisticsCollectedSignal(currentRequestsNumberInMemory);
}
