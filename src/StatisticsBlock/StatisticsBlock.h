#ifndef STATISTICSBLOCK_H
#define STATISTICSBLOCK_H

#include <QObject>

class StatisticsBlock : public QObject
{
    Q_OBJECT
private:
    int optimalQueueSize;
public:
    StatisticsBlock() : optimalQueueSize(0) {}
    ~StatisticsBlock() {}

    void CollectStatistics(int currentRequestsNumberInMemory, int dropRequestNumber, double currentModelingTime,
                           double procUnitWorkingTime);
signals:
    void CollectStatisticsSignal(int currentRequestsNumberInMemory, int dropRequestNumber,
                                 int optimalQueueSize, double procUnitLoadKoff);
};

#endif // STATISTICSBLOCK_H
