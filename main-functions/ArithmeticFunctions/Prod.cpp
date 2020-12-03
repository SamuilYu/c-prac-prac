#include <sstream>
#include "Prod.h"

Prod::Prod(const BaseFunction &first, const BaseFunction &second) {
    firstTerm = first.copy();
    secondTerm = second.copy();
}

string Prod::toString() const {
    ostringstream result;
    result << "(" << firstTerm -> toString() << ")*(" << secondTerm -> toString() << ")";
    return string(result.str());
}

float Prod::getDerivativeAtPoint(float point) const {
    return firstTerm -> getDerivativeAtPoint(point) * (*secondTerm)(point)
    + secondTerm -> getDerivativeAtPoint(point) * (*firstTerm)(point);
}

float Prod::operator()(float point) const {
    return (*firstTerm)(point)*(*secondTerm)(point);
}

shared_ptr<BaseFunction> Prod::copy() const {
    return make_shared<Prod>(*this);
}
