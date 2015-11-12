#ifndef CONTROLPROGRAM_H
#define CONTROLPROGRAM_H

#include "../InformationSource/InformationSource.h"
#include "../ProcessingUnit/ProcessingUnit.h"
#include "../Memory/Memory.h"
#include "../StatisticsBlock/StatisticsBlock.h"

const int ARRAY_SIZE = 2;
const int INFORMATION_SOURSE_INDEX = 0;
const int PROCESSING_UNIT_INDEX =1;

class ControlProgram : public QObject
{
    Q_OBJECT
private:
    InformationSource* informationSource;
    ProcessingUnit* processingUnit;
    StatisticsBlock* statisticsBlock;
    Memory* memory;
    double timeArray[ARRAY_SIZE];
    double currentModelingTime;
    double endModelingTime;
public:
    ControlProgram();
    ~ControlProgram();

    void ConfigureSystem(double endModelingTime, int maxMemorySize,
                         double a, double b, double matExp, double sigma, double maxBorderForNormalGenerator);
    void StartModeling();
private:
    double GetMinTime();
    void RealizeEvents();
    void CleanTimeArray();
public slots:
    void StatisticsCollected(int currentRequestsNumberInMemory);
signals:
    void StatisticsCollectedSignal(int currentRequestsNumberInMemory);
};

#endif // CONTROLPROGRAM_H
