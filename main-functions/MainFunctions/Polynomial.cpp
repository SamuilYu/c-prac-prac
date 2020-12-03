#include "Polynomial.h"
#include "sstream"

Polynomial::Polynomial(float f) {
    polynomialVector.push_back(f);
}

Polynomial::Polynomial() {
    polynomialVector.push_back(0);
}

Polynomial::Polynomial(const Polynomial& other) {
    polynomialVector = other.polynomialVector;
}

Polynomial::Polynomial(const vector<float>& v) {
    polynomialVector = v;
    removeTrailingZeroes();
}

string Polynomial::toString() const {
    bool isFirstTerm = true;
    ostringstream resultString;

    if (polynomialVector.size() == 1 && polynomialVector[0] == 0) {
        return "0";
    }

    for (int degree = 0; degree < polynomialVector.size(); ++degree) {
        float coefficient = polynomialVector[degree];
        bool positive = coefficient >= 0;

        if (coefficient != 0) {
            resultString << ((!isFirstTerm && positive)? "+" : "");

            if (degree == 0) {
                resultString << coefficient;
                isFirstTerm = false;
                continue;
            }

            if (coefficient == -1) {
                resultString << "-x";
            } else if (coefficient == 1) {
                resultString << "x";
            } else {
                resultString << coefficient << "x";
            }

            if (degree != 1) {
                resultString << "^" << degree;
            }

            isFirstTerm = false;
        }
    }
    return string(resultString.str());
}

float Polynomial::getDerivativeAtPoint(float point) const {
    float result = 0;
    int degree = 0;
    float accumulator = 1 / point;
    for (const auto &coefficient: polynomialVector) {
        result += coefficient * accumulator * float(degree);
        degree++;
        accumulator *= point;
    }
    return result;
}

float Polynomial::operator()(float point) const {
    float result = 0;
    float accumulator = 1;
    for (const auto &coefficient: polynomialVector) {
        result += coefficient * accumulator;
        accumulator *= point;
    }
    return result;
}

shared_ptr<BaseFunction> Polynomial::copy() const {
    return make_shared<Polynomial>(*this);
}

void Polynomial::removeTrailingZeroes() {
    vector<float> newPolynomialVector;
    size_t zeroesCount = 0;
    for (const auto &coefficient: polynomialVector) {
        if (coefficient == 0) {
            zeroesCount++;
        } else {
            for (int i = 0; i < zeroesCount; ++i) {
                newPolynomialVector.push_back(0);
            }
            newPolynomialVector.push_back(coefficient);
            zeroesCount = 0;
        }
    }
    if (newPolynomialVector.empty()) {
        polynomialVector = vector<float>{0};
    } else {
        polynomialVector = newPolynomialVector;
    }
}
