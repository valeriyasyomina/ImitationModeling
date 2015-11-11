#include "NormalGenerator.h"
#include "LKG.h"

NormalGenerator::NormalGenerator()
{
    this->sigma = 0.0;
    this->matExp = 0.0;
    this->minBorder = 0;
    this->maxBorder = 0;
    this->iterationNumber = 0;
    this->currentNumber = 0;
}

NormalGenerator::NormalGenerator(double sigma, double matExp, int minBorder, int maxBorder, int iterationNumber)
{
    this->sigma = sigma;
    this->matExp = matExp;
    this->minBorder = minBorder;
    this->maxBorder = maxBorder;
    this->iterationNumber = iterationNumber;

    //cureentNumber
}

double NormalGenerator::GenerateValue(int lowBorder, int highBorder)
{
    double sum = 0.0;
    for (int i = 0; i < iterationNumber; i++)
    {
        currentNumber = LKG::GenerateValue(currentNumber, lowBorder, highBorder);
        sum += currentNumber;
    }
    double number = matExp + (sum - iterationNumber / 2) * sigma;
    return TransformValueIntoBorders(number, lowBorder, highBorder);
}

double NormalGenerator::TransformValueIntoBorders(double value, int lowBorder, int highBorder)
{
    double interval = highBorder - lowBorder;
    while (value > highBorder)
        value -= interval;
    while (value < lowBorder)
        value += lowBorder;
    return value;
}
