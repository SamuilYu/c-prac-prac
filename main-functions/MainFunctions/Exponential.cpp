#include <sstream>
#include <math.h>
#include "Exponential.h"

Exponential::Exponential(float k) {
    coefficient = k;
}

Exponential::Exponential() {
    coefficient = 0;
}

Exponential::Exponential(vector<float> k) {
    if (!k.empty()) {
        coefficient = k[0];
    } else {
        coefficient = 0;
    }
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
