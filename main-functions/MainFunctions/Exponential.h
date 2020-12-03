#ifndef MAINFUNCTIONS_EXPONENTIAL_H
#define MAINFUNCTIONS_EXPONENTIAL_H


#include "BaseFunction.h"

class Exponential: public BaseFunction {
private:
    float coefficient;
public:
    explicit Exponential(float);

    string toString() const override;

    float getDerivativeAtPoint(float d) const override;

    float operator()(float d) const override;

    shared_ptr<BaseFunction> copy() const override;
};


#endif //MAINFUNCTIONS_EXPONENTIAL_H
