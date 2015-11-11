#ifndef INFORMATIONSOURCE_H
#define INFORMATIONSOURCE_H

class InformationSource
{
private:
    double matExp;
    double sigma;
public:
    InformationSource(): sigma(0.0), matExp(0.0) {}
    InformationSource(double sigma, double matExp)
    {
        this->sigma = sigma;
        this->matExp = matExp;
    }
    ~InformationSource() {}

    double GetSigma() const {return sigma;}
    double GetMatExp() const {return matExp;}
};

#endif // INFORMATIONSOURCE_H
