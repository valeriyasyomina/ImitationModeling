#ifndef STATISTICSBLOCK_H
#define STATISTICSBLOCK_H

#include <QObject>

class StatisticsBlock : public QObject
{
    Q_OBJECT
public:
    StatisticsBlock() {}
    ~StatisticsBlock() {}

    void CollectStatistics(int currentRequestsNumberInMemory);
signals:
    void CollectStatisticsSignal(int currentRequestsNumberInMemory);
};

#endif // STATISTICSBLOCK_H
