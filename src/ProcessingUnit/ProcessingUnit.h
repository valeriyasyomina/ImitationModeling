#ifndef PROCESSINGUNIT_H
#define PROCESSINGUNIT_H

#include "../Generator/LKG.h"

class ProcessingUnit
{
private:
    double a;
    double b;
public:
    ProcessingUnit() {}
    ProcessingUnit(double a, double b)
    {
        this->a = a;
        this->b = b;
    }
    ~ProcessingUnit() {}


};

#endif // PROCESSINGUNIT_H
