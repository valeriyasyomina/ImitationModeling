#ifndef CONTROLPROGRAM_H
#define CONTROLPROGRAM_H

#include "../InformationSource/InformationSource.h"
#include "../ProcessingUnit/ProcessingUnit.h"
#include "../Memory/Memory.h"
#include "../StatisticsBlock/StatisticsBlock.h"
#include <math.h>

const int ARRAY_SIZE = 2;
const int INFORMATION_SOURSE_INDEX = 0;
const int PROCESSING_UNIT_INDEX = 1;
const int IDLE_TIME = -1;
const int REQUEST_NUMBER = 10;
const double EPSILON = 1e-3;

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
    int requestDropNumber;              // из 10 заявок
    int requestReturnNumber;            // из 10 заявок
    int requestCounter;
public:
    ControlProgram();
    ~ControlProgram();

    void ConfigureSystem(double endModelingTime, int maxMemorySize,
                         double a, double b, double matExp, double sigma, double maxBorderForNormalGenerator,
                         int requestDropPercent, int requestReturnPercent);
    void StartModeling();
private:
    double GetMinTime();
    void RealizeEvents();
    void CleanTimeArray();
public slots:
    void StatisticsCollected(int currentRequestsNumberInMemory, int dropRequestNumber,
                             int optimalQueueSize, double procUnitLoadKoff);
signals:
    void StatisticsCollectedSignal(int currentRequestsNumberInMemory, int dropRequestNumber,
                                   int optimalQueueSize, double procUnitLoadKoff);
    void ModelingFinishedSignal();
};

#endif // CONTROLPROGRAM_H
