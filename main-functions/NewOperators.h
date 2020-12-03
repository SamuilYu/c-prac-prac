#ifndef MAINFUNCTIONS_NEWOPERATORS_H
#define MAINFUNCTIONS_NEWOPERATORS_H

#include "stdexcept"
#include "MainFunctions/BaseFunction.h"
#include "ArithmeticFunctions/Sum.h"

template <class A, class B>
Sum operator+(const A& first, const B& second) {
    return Sum(first, second);
}

template <class A, class B>
BaseFunction& operator*(const A& first, const B& second) {
    return prod(first, second);
}

template <class A, class B>
BaseFunction& operator/(const A& first, const B& second) {
    return div(first, second);
}

template <class A, class B>
BaseFunction& operator-(const A& first, const B& second) {
    return diff(first, second);
}

#endif //MAINFUNCTIONS_NEWOPERATORS_H
