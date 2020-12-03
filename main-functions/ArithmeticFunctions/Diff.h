//
// Created by samuil on 12/3/20.
//

#ifndef MAINFUNCTIONS_DIFF_H
#define MAINFUNCTIONS_DIFF_H


#include "BaseArithmetic.h"

class Diff: public BaseArithmetic {
public:
    Diff(const BaseFunction&, const BaseFunction&);

    string toString() const override;

    float getDerivativeAtPoint(float d) const override;

    float operator()(float d) const override;

    shared_ptr<BaseFunction> copy() const override;
};


#endif //MAINFUNCTIONS_DIFF_H
