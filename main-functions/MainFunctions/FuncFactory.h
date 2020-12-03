#ifndef MAINFUNCTIONS_FUNCFACTORY_H
#define MAINFUNCTIONS_FUNCFACTORY_H

#include <string>
#include <map>
#include <utility>
#include <vector>
#include "BaseFunction.h"
#include "Polynomial.h"
#include "PowerFunction.h"
#include "Exponential.h"

class FuncFactory {
private:
    class ICreator {
    public:
        virtual shared_ptr<BaseFunction> create(float coefficient) = 0;
        virtual shared_ptr<BaseFunction> create() = 0;
        virtual shared_ptr<BaseFunction> create(vector<float> coefficients) = 0;
    };

    template<class T>
    class Creator: public ICreator {
    public:
        shared_ptr<BaseFunction> create(float coefficient) override {
            return make_shared<T>(T(coefficient));
        }

        shared_ptr<BaseFunction> create() override {
            return make_shared<T>(T());
        }

        shared_ptr<BaseFunction> create(vector<float> coefficients) override {
            return make_shared<T>(T(coefficients));
        }
    };

    map<string, shared_ptr<ICreator>> registered;

    void registerAll() {
        registered["ident"] = make_shared<Creator<IdentityFunction>>();
        registered["const"] = make_shared<Creator<ConstantFunction>>();
        registered["poly"] = make_shared<Creator<Polynomial>>();
        registered["power"] = make_shared<Creator<PowerFunction>>();
        registered["exp"] = make_shared<Creator<Exponential>>();
    }

public:
    FuncFactory() {
        registerAll();
    }

    shared_ptr<BaseFunction> create(const string& type, float coefficient) {
        return registered[type]->create(coefficient);
    }

    shared_ptr<BaseFunction> create(const string& type) {
        return registered[type]->create();
    }

    shared_ptr<BaseFunction> create(const string& type, vector<float> coefficients) {
        return registered[type]->create(std::move(coefficients));
    }
};


#endif //MAINFUNCTIONS_FUNCFACTORY_H
