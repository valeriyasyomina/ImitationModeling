#ifndef NORMALGENERATOR_H
#define NORMALGENERATOR_H

class NormalGenerator
{
protected:
    double sigma;
    double matExp;
    double minBorder;
    double maxBorder;
    int iterationNumber;
    int currentNumber;
public:
    NormalGenerator();
    NormalGenerator(double sigma, double matExp, int minBorder, int maxBorder, int iterationNumber);
    ~NormalGenerator() {}

    double GenerateValue(int lowBorder, int highBorder);
protected:
    double TransformValueIntoBorders(double value, int lowBorder, int highBorder);

};

#endif // NORMALGENERATOR_H
