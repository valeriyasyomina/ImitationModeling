#include "ControlProgram.h"

ControlProgram::ControlProgram()
{
    informationSourse = new InformationSource();
    processingUnit = new ProcessingUnit();
    statisticsBlock = new StatisticsBlock();
    memory = new Memory();
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
