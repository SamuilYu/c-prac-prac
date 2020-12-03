#include "sstream"
#include "Sum.h"

Sum::Sum(const BaseFunction& first, const BaseFunction& second) {
    firstTerm = first.copy();
    secondTerm = second.copy();
}

string Sum::toString() const {
    ostringstream resultStream;
    resultStream << "(" << firstTerm -> toString() << ")+(" << secondTerm -> toString() + ")";
    return string(resultStream.str());
}

float Sum::getDerivativeAtPoint(float point) const {
    return firstTerm -> getDerivativeAtPoint(point) + secondTerm->getDerivativeAtPoint(point);
}

float Sum::operator()(float point) const {
    return (*firstTerm)(point) + (*secondTerm)(point);
}

shared_ptr<BaseFunction> Sum::copy() const {
    return shared_ptr<BaseFunction>();
}
