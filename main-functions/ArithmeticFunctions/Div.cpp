//
// Created by samuil on 12/3/20.
//

#include <sstream>
#include "Div.h"

Div::Div(const BaseFunction &first, const BaseFunction &second) {
    firstTerm = first.copy();
    secondTerm = second.copy();
}

string Div::toString() const {
    ostringstream result;
    result << "(" << firstTerm->toString() << ")/(" << secondTerm->toString() << ")";
    return string(result.str());
}

float Div::getDerivativeAtPoint(float point) const {
    float u = (*firstTerm)(point);
    float v = (*secondTerm)(point);
    float ul = firstTerm->getDerivativeAtPoint(point);
    float vl = secondTerm->getDerivativeAtPoint(point);
    return (u*vl - v*ul) / (v*v);
}

float Div::operator()(float point) const {
    return (*firstTerm)(point) / (*secondTerm)(point);
}

shared_ptr<BaseFunction> Div::copy() const {
    return make_shared<Div>(*this);
}
