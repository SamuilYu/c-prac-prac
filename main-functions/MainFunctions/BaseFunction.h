//
// Created by samuil on 11/30/20.
//

#ifndef MAINFUNCTIONS_BASEFUNCTION_H
#define MAINFUNCTIONS_BASEFUNCTION_H
#include <string>
#include <memory>
using namespace std;


class BaseFunction {
public:
    virtual string toString() const = 0;
    virtual float getDerivativeAtPoint(float) const = 0;
    virtual float operator()(float) const = 0;

    virtual shared_ptr<BaseFunction> copy() const = 0;
};


#endif //MAINFUNCTIONS_BASEFUNCTION_H
