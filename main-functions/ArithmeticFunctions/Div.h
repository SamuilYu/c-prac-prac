//
// Created by samuil on 12/3/20.
//

#ifndef MAINFUNCTIONS_DIV_H
#define MAINFUNCTIONS_DIV_H


#include "BaseArithmetic.h"

class Div: public BaseArithmetic {
public:
    Div(const BaseFunction&, const BaseFunction&);

    string toString() const override;

    float getDerivativeAtPoint(float d) const override;

    float operator()(float d) const override;

    shared_ptr<BaseFunction> copy() const override;
};


#endif //MAINFUNCTIONS_DIV_H
