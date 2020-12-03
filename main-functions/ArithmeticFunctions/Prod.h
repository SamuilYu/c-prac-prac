//
// Created by samuil on 12/3/20.
//

#ifndef MAINFUNCTIONS_PROD_H
#define MAINFUNCTIONS_PROD_H


#include "BaseArithmetic.h"

class Prod: public BaseArithmetic {
public:
    Prod(const BaseFunction&, const BaseFunction&);

    string toString() const override;

    float getDerivativeAtPoint(float d) const override;

    float operator()(float d) const override;

    shared_ptr<BaseFunction> copy() const override;
};


#endif //MAINFUNCTIONS_PROD_H
