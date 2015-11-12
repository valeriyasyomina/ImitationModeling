#include "LKG.h"

int LKG::GenerateValue(int previousValue, int lowBorder, int highBorder)
{
    int generatedNumber = Generator(previousValue);
    return TransformValueIntoBorders(generatedNumber, lowBorder, highBorder);
}

int LKG::GenerateValue(int previousValue)
{
    return Generator(previousValue);
}

int LKG::Generator(int previousValue)
{
    return (a * previousValue + b) % m;
}

int LKG::TransformValueIntoBorders(int value, int lowBorder, int highBorder)
{
    int resultValue = value % (highBorder - lowBorder) + lowBorder;
    return resultValue;
}

int LKG::a = 106;
int LKG::b = 1283;
int LKG::m = 6075;


