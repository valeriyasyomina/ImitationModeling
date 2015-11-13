#ifndef PROCESSINGUNIT_H
#define PROCESSINGUNIT_H

#include "../Generator/LKG.h"

class ProcessingUnit
{
private:
    double a;
    double b;
    double previousTime;
    double workingTime;
public:
    ProcessingUnit(): a(0.0), b(0.0), previousTime(0.0), workingTime(0.0) {}
    ProcessingUnit(double a, double b)
    {
        this->a = a;
        this->b = b;
        previousTime = 0.0;
    }
    ~ProcessingUnit() {}

    double GetProcessTime();
    double GetWorkingTime() const {return workingTime;}
};

#endif // PROCESSINGUNIT_H
