#include "ProcessingUnit.h"

double ProcessingUnit::GetProcessTime()
{
    previousTime = LKG::GenerateValue(previousTime, a, b);
    return previousTime;
}
