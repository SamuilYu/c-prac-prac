//
// Created by samuil on 12/4/20.
//

#include "FuncFactory.h"
#include "Polynomial.h"
#include "Exponential.h"
#include "PowerFunction.h"

shared_ptr<BaseFunction> FuncFactory::create(const string& type, float coefficient) {
    if (type == "ident") {
        return make_shared<IdentityFunction>(IdentityFunction());
    } else if (type == "const") {
        return  make_shared<ConstantFunction>(ConstantFunction(coefficient));
    } else if (type == "exp") {
        return  make_shared<Exponential>(Exponential(coefficient));
    } else if (type == "power") {
        return make_shared<PowerFunction>(PowerFunction(int(coefficient)));
    } else if (type == "poly") {
        vector<float> temp{coefficient};
        return make_shared<Polynomial>(Polynomial(temp));
    } else {
        throw logic_error("Unknown type provided to factory: " + type);
    }
}

shared_ptr<BaseFunction> FuncFactory::create(const string& type) {
    if (type == "ident") {
        return make_shared<IdentityFunction>(IdentityFunction());
    } else if (type == "const") {
        return  make_shared<ConstantFunction>(ConstantFunction(0));
    } else if (type == "exp") {
        return  make_shared<Exponential>(Exponential(0));
    } else if (type == "power") {
        return make_shared<PowerFunction>(PowerFunction(0));
    } else if (type == "poly") {
        vector<float> temp{0};
        return make_shared<Polynomial>(Polynomial(temp));
    } else {
        throw logic_error("Unknown type provided to factory: " + type);
    }
}

shared_ptr<BaseFunction> FuncFactory::create(const string& type, vector<float> coefficients) {
    if (type == "ident") {
        return make_shared<IdentityFunction>(IdentityFunction());
    } else if (type == "const") {
        return  make_shared<ConstantFunction>(ConstantFunction(coefficients[0]));
    } else if (type == "exp") {
        return  make_shared<Exponential>(Exponential(coefficients[0]));
    } else if (type == "power") {
        return make_shared<PowerFunction>(PowerFunction(int(coefficients[0])));
    } else if (type == "poly") {
        return make_shared<Polynomial>(Polynomial(coefficients));
    } else {
        throw logic_error("Unknown type provided to factory: " + type);
    }
}
