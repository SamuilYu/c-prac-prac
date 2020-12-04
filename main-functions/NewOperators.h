#ifndef MAINFUNCTIONS_NEWOPERATORS_H
#define MAINFUNCTIONS_NEWOPERATORS_H

#include <sstream>
#include "stdexcept"
#include "MainFunctions/BaseFunction.h"
#include "ArithmeticFunctions/Sum.h"
#include "ArithmeticFunctions/Diff.h"
#include "ArithmeticFunctions/Prod.h"
#include "ArithmeticFunctions/Div.h"

template<class A, class B,
        enable_if_t<is_base_of_v<shared_ptr<BaseFunction>, A>, bool> = true,
        enable_if_t<is_base_of_v<shared_ptr<BaseFunction>, B>, bool> = true>
shared_ptr<BaseArithmetic> operator+(const A& first, const B& second) {
    return make_shared<Sum>(Sum(*first, *second));
}

template<class A, class B,
        enable_if_t<!is_base_of_v<shared_ptr<BaseFunction>, A> ||
                !is_base_of_v<shared_ptr<BaseFunction>, B>, bool> = true>
shared_ptr<BaseArithmetic> operator+(const A& first, const B& second) {
    ostringstream stream;
    stream << "Invalid operands for operator+.";
    throw logic_error(string(stream.str()));
}

template<class A, class B,
        enable_if_t<is_base_of_v<shared_ptr<BaseFunction>, A>, bool> = true,
        enable_if_t<is_base_of_v<shared_ptr<BaseFunction>, B>, bool> = true>
shared_ptr<BaseArithmetic> operator*(const A& first, const B& second) {
    return make_shared<Prod>(Prod(*first, *second));
}

template<class A, class B,
        enable_if_t<!is_base_of_v<shared_ptr<BaseFunction>, A> ||
                    !is_base_of_v<shared_ptr<BaseFunction>, B>, bool> = true>
shared_ptr<BaseArithmetic> operator*(const A& first, const B& second) {
    ostringstream stream;
    stream << "Invalid operands for operator*.";
    throw logic_error(string(stream.str()));
}

template<class A, class B,
        enable_if_t<is_base_of_v<shared_ptr<BaseFunction>, A>, bool> = true,
        enable_if_t<is_base_of_v<shared_ptr<BaseFunction>, B>, bool> = true>
shared_ptr<BaseArithmetic> operator/(const A& first, const B& second) {
    return make_shared<Div>(Div(*first, *second));
}

template<class A, class B,
        enable_if_t<!is_base_of_v<shared_ptr<BaseFunction>, A> ||
                    !is_base_of_v<shared_ptr<BaseFunction>, B>, bool> = true>
shared_ptr<BaseArithmetic> operator/(const A& first, const B& second) {
    ostringstream stream;
    stream << "Invalid operands for operator/.";
    throw logic_error(string(stream.str()));
}

template<class A, class B,
        enable_if_t<is_base_of_v<shared_ptr<BaseFunction>, A>, bool> = true,
        enable_if_t<is_base_of_v<shared_ptr<BaseFunction>, B>, bool> = true>
shared_ptr<BaseArithmetic> operator-(const A& first, const B& second) {
    return make_shared<Diff>(Diff(*first, *second));
}

template<class A, class B,
        enable_if_t<!is_base_of_v<shared_ptr<BaseFunction>, A> ||
                    !is_base_of_v<shared_ptr<BaseFunction>, B>, bool> = true>
shared_ptr<BaseArithmetic> operator-(const A& first, const B& second) {
    ostringstream stream;
    stream << "Invalid operands for operator-.";
    throw logic_error(string(stream.str()));
}


#endif //MAINFUNCTIONS_NEWOPERATORS_H
