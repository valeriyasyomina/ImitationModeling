#include "StatisticsBlock.h"

void StatisticsBlock::CollectStatistics(int currentRequestsNumberInMemory)
{
    emit CollectStatisticsSignal(currentRequestsNumberInMemory);
}
