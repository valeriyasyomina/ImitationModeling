#ifndef LKG_H
#define LKG_H

class LKG
{
protected:
    static int a;
    static int b;
    static int m;
public:
    static int GenerateValue(int previousValue, int lowBorder, int highBorder);
protected:
    static int Generator(int previousValue);
    static int TransformValueIntoBorders(int value, int lowBorder, int highBorder);
};

#endif // LKG_H
