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
    informationSource = new InformationSource(sigma, matExp, 0, maxBorderForNormalGenerator, 12);
    processingUnit = new ProcessingUnit(a, b);
    statisticsBlock = new StatisticsBlock();
    memory = new Memory(maxMemorySize);


    this->endModelingTime = endModelingTime;

    timeArray[INFORMATION_SOURSE_INDEX] = informationSource->GenerateRequestTime();
    timeArray[PROCESSING_UNIT_INDEX] = processingUnit->GetProcessTime();
}

void ControlProgram::StartModeling()
{
    for (currentModelingTime = 0.0; currentModelingTime <= endModelingTime; currentModelingTime)
    {
        statisticsBlock->CollectStatistics();
        currentModelingTime = GetMinTime();
        RealizeEvents();
    }
}

double ControlProgram::GetMinTime()
{
    double minTime = timeArray[0];
    for (int i = 1; i < ARRAY_SIZE; i++)
    {
        if (timeArray[i] > minTime)
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
