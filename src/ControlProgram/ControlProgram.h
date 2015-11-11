#ifndef CONTROLPROGRAM_H
#define CONTROLPROGRAM_H

#include "../InformationSource/InformationSource.h"
#include "../ProcessingUnit/ProcessingUnit.h"
#include "../Memory/Memory.h"
#include "../StatisticsBlock/StatisticsBlock.h"

#define ARRAY_SIZE 3

class ControlProgram
{
private:
    InformationSource* informationSourse;
    ProcessingUnit* processingUnit;
    StatisticsBlock* statisticsBlock;
    Memory* memory;
    double timeArray[ARRAY_SIZE];
    double currentModelingTime;
    double timeStep;
    double endModelingTime;
public:
    ControlProgram();
    ~ControlProgram();

    void ConfigureSystem(double timeStep, double endModelingTime, int maxMemorySize,
                         double a, double b, double matExp, double sigma);
    void StartModeling();
};

#endif // CONTROLPROGRAM_H
