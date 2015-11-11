#include "ControlProgram.h"

ControlProgram::ControlProgram()
{
    informationSourse = NULL;
    processingUnit = NULL;
    statisticsBlock = NULL;
    memory = NULL;

    endModelingTime = 0.0;
    currentModelingTime = 0.0;
    timeStep = 0.0;
}

ControlProgram::~ControlProgram()
{
    if (informationSourse)
    {
        delete informationSourse;
        informationSourse = NULL;
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

void ControlProgram::ConfigureSystem(double timeStep, double endModelingTime, int maxMemorySize,
                     double a, double b, double matExp, double sigma, double maxBorderForNormalGenerator)
{
    informationSourse = new InformationSource(sigma, matExp, 0, maxBorderForNormalGenerator, 12);
    processingUnit = new ProcessingUnit(a, b);
    statisticsBlock = new StatisticsBlock();
    memory = new Memory(maxMemorySize);

    this->timeStep = timeStep;
    this->endModelingTime = endModelingTime;
}

void ControlProgram::StartModeling()
{
    //for (currentModelingTime = 0.0; currentModelingTime )
}
