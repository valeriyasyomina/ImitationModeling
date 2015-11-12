#ifndef STATISTICSBLOCK_H
#define STATISTICSBLOCK_H

#include <QObject>

class StatisticsBlock : public QObject
{
    Q_OBJECT
public:
    StatisticsBlock() {}
    ~StatisticsBlock() {}

    void CollectStatistics();
signals:
    void Collect();
};

#endif // STATISTICSBLOCK_H
