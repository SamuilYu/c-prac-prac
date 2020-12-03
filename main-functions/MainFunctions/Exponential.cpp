#include <sstream>
#include <math.h>
#include "Exponential.h"

Exponential::Exponential(float k) {
    coefficient = k;
}

string Exponential::toString() const {
    if (coefficient == 0) {
        return "1";
    }

    ostringstream result;
    if (coefficient == 1) {
        result << "exp(x)";
    } else if (coefficient == -1) {
        result << "exp(-x)";
    } else {
        result << "exp(" << coefficient << "x)";
    }

    return string(result.str());
}

float Exponential::getDerivativeAtPoint(float point) const {
    return coefficient * exp(coefficient * point);
}

float Exponential::operator()(float point) const {
    return exp(coefficient * point);
}

shared_ptr<BaseFunction> Exponential::copy() const {
    return make_shared<Exponential>(*this);
}
