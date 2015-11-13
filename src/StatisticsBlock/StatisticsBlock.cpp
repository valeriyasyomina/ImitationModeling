#include "StatisticsBlock.h"

void StatisticsBlock::CollectStatistics(int currentRequestsNumberInMemory, int dropRequestNumber, double currentModelingTime,
                                        double procUnitWorkingTime)
{
    if (optimalQueueSize < currentRequestsNumberInMemory)
        optimalQueueSize = currentRequestsNumberInMemory;
    optimalQueueSize += dropRequestNumber;

    double procUnitLoadKoff = !currentModelingTime ? 0.0 : (double) procUnitWorkingTime / currentModelingTime;
    emit CollectStatisticsSignal(currentRequestsNumberInMemory, dropRequestNumber, optimalQueueSize, procUnitLoadKoff);
}
