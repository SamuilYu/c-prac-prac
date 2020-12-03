//
// Created by samuil on 12/4/20.
//

#ifndef MAINFUNCTIONS_FUNCFACTORY_H
#define MAINFUNCTIONS_FUNCFACTORY_H

#include <string>
#include <vector>
#include "BaseFunction.h"

class FuncFactory {
public:
    static shared_ptr<BaseFunction> create(const string& type, float coefficient);
    static shared_ptr<BaseFunction> create(const string& type);
    static shared_ptr<BaseFunction> create(const string& type, vector<float> coefficients);
};


#endif //MAINFUNCTIONS_FUNCFACTORY_H
