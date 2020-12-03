#ifndef MAINFUNCTIONS_POLYNOMIAL_H
#define MAINFUNCTIONS_POLYNOMIAL_H

#include "BaseFunction.h"
#include <vector>

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


#endif //MAINFUNCTIONS_POLYNOMIAL_H
