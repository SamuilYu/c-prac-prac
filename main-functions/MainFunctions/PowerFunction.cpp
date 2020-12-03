#include <sstream>
#include "PowerFunction.h"

PowerFunction::PowerFunction(int degree) {
    this->degree = degree;
}

string PowerFunction::toString() const {
    ostringstream result;
    if (degree == 0) {
        return "1";
    }
    if (degree > 0) {
        result << "x^" << degree;
    } else {
        result << "x^(" << degree << ")";
    }
    return string(result.str());
}

float PowerFunction::getDerivativeAtPoint(float point) const {
    if (degree == 0) {
        return 0;
    }

    int newDegree = degree - 1;
    float result = 1;
    if (newDegree > 0) {
        for (int i = 0; i < newDegree; ++i) {
            result *= point;
        }
    } else {
        for (int i = 0; i < -newDegree; ++i) {
            result /= point;
        }
    }
    return result * degree;
}

float PowerFunction::operator()(float point) const {
    if (degree == 0) {
        return 1;
    }

    float result = 1;
    if (degree > 0) {
        for (int i = 0; i < degree; ++i) {
            result *= point;
        }
    } else {
        for (int i = 0; i < -degree; ++i) {
            result /= point;
        }
    }
    return result;
}

shared_ptr<BaseFunction> PowerFunction::copy() const {
    return make_shared<PowerFunction>(*this);
}
