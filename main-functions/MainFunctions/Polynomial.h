#ifndef MAINFUNCTIONS_POLYNOMIAL_H
#define MAINFUNCTIONS_POLYNOMIAL_H

#include "BaseFunction.h"
#include <vector>
#include <iostream>

class Polynomial: public BaseFunction {
private:
    void removeTrailingZeroes ();
protected:
    vector<float> polynomialVector;
public:
    Polynomial();
    Polynomial(const Polynomial&);
    Polynomial(const vector<float>&);

    string toString() const override;
    float operator()(float d) const override;
    float getDerivativeAtPoint(float d) const override;

    shared_ptr<BaseFunction> copy() const override;
};

class IdentityFunction: public Polynomial {
public:
    IdentityFunction() {
        polynomialVector.clear();
        polynomialVector.push_back(0);
        polynomialVector.push_back(1);
    }
};

class ConstantFunction: public Polynomial {
public:
    ConstantFunction(float c) {
        polynomialVector.clear();
        polynomialVector.push_back(c);
    }
};


#endif //MAINFUNCTIONS_POLYNOMIAL_H
