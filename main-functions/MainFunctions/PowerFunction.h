#ifndef MAINFUNCTIONS_POWERFUNCTION_H
#define MAINFUNCTIONS_POWERFUNCTION_H

#include <vector>
#include "BaseFunction.h"

class PowerFunction: public BaseFunction {
private:
    int degree;
public:
    explicit PowerFunction(int degree);
    explicit PowerFunction(float degree);
    PowerFunction();
    explicit PowerFunction(vector<float> v);

    string toString() const override;

    float getDerivativeAtPoint(float d) const override;

    float operator()(float d) const override;

    shared_ptr<BaseFunction> copy() const override;
};


#endif //MAINFUNCTIONS_POWERFUNCTION_H
