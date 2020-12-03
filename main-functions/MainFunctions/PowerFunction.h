#ifndef MAINFUNCTIONS_POWERFUNCTION_H
#define MAINFUNCTIONS_POWERFUNCTION_H

#include "BaseFunction.h"

class PowerFunction: public BaseFunction {
private:
    int degree;
public:
    PowerFunction(int degree);

    string toString() const override;

    float getDerivativeAtPoint(float d) const override;

    float operator()(float d) const override;

    shared_ptr<BaseFunction> copy() const override;
};


#endif //MAINFUNCTIONS_POWERFUNCTION_H
