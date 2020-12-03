//
// Created by samuil on 12/3/20.
//

#ifndef MAINFUNCTIONS_SUM_H
#define MAINFUNCTIONS_SUM_H

#include "../MainFunctions/BaseFunction.h"
#include "BaseArithmetic.h"

class Sum: public BaseArithmetic {
public:
    Sum(const BaseFunction& first, const BaseFunction& second);

    string toString() const override;

    float getDerivativeAtPoint(float d) const override;

    float operator()(float d) const override;

    shared_ptr<BaseFunction> copy() const override;
};


#endif //MAINFUNCTIONS_SUM_H
