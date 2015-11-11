#ifndef STATISTICSBLOCK_H
#define STATISTICSBLOCK_H

#include <QObject>

class StatisticsBlock : public QObject
{
    Q_OBJECT
public:
    StatisticsBlock() {}
    ~StatisticsBlock() {}

    void CollectStatistics() {emit Collect();}
public slots:
    void MemoryStatistics() {}
    void InformationSourceStatistics() {}
    void ProcessingUnitStatistics() {}
signals:
    void Collect();
};

#endif // STATISTICSBLOCK_H
