#ifndef CONTROLPROGRAM_H
#define CONTROLPROGRAM_H

#include "../InformationSource/InformationSource.h"
#include "../ProcessingUnit/ProcessingUnit.h"
#include "../Memory/Memory.h"
#include "../StatisticsBlock/StatisticsBlock.h"

class ControlProgram
{
private:
    InformationSource* informationSourse;
    ProcessingUnit* processingUnit;
    StatisticsBlock* statisticsBlock;
    Memory* memory;
public:
    ControlProgram();
    ~ControlProgram();

};

#endif // CONTROLPROGRAM_H
