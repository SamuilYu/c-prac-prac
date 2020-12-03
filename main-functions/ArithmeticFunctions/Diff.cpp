//
// Created by samuil on 12/3/20.
//

#include <sstream>
#include "Diff.h"

Diff::Diff(const BaseFunction &first, const BaseFunction &second) {
    firstTerm = first.copy();
    secondTerm = second.copy();
}

string Diff::toString() const {
    ostringstream result;
    result << "(" << firstTerm -> toString() << ")-(" << secondTerm -> toString() << ")";
    return string(result.str());
}

float Diff::getDerivativeAtPoint(float point) const {
    return firstTerm -> getDerivativeAtPoint(point) - secondTerm -> getDerivativeAtPoint(point);
}

float Diff::operator()(float point) const {
    return (*firstTerm)(point) - (*secondTerm)(point);
}

shared_ptr<BaseFunction> Diff::copy() const {
    return make_shared<Diff>(*this);
}
