#ifndef PROCESSINGUNIT_H
#define PROCESSINGUNIT_H

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

    double GetA() const {return a;}
    double GetB() const {return b;}
    void SetA(double a) {this->a = a;}
    void SetB(double b) {this->b = b;}
};

#endif // PROCESSINGUNIT_H
