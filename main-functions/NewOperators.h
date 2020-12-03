#ifndef MAINFUNCTIONS_NEWOPERATORS_H
#define MAINFUNCTIONS_NEWOPERATORS_H

#include "stdexcept"
#include "MainFunctions/BaseFunction.h"
#include "ArithmeticFunctions/Sum.h"
#include "ArithmeticFunctions/Diff.h"
#include "ArithmeticFunctions/Prod.h"
#include "ArithmeticFunctions/Div.h"

template <class A, class B>
shared_ptr<BaseArithmetic> operator+(const A& first, const B& second) {
    return make_shared<Sum>(Sum(*first, *second));
}

template <class A, class B>
shared_ptr<BaseArithmetic> operator*(const A& first, const B& second) {
    return make_shared<Prod>(Prod(*first, *second));
}

template <class A, class B>
shared_ptr<BaseArithmetic> operator/(const A& first, const B& second) {
    return make_shared<Div>(Div(*first, *second));
}

template <class A, class B>
shared_ptr<BaseArithmetic> operator-(const A& first, const B& second) {
    return make_shared<Diff>(Diff(*first, *second));
}

#endif //MAINFUNCTIONS_NEWOPERATORS_H
