#ifndef MAINFUNCTIONS_BASEARITHMETIC_H
#define MAINFUNCTIONS_BASEARITHMETIC_H

#include "../MainFunctions/BaseFunction.h"

class BaseArithmetic: public BaseFunction {
protected:
    shared_ptr<BaseFunction> firstTerm;
    shared_ptr<BaseFunction> secondTerm;
};

#endif //MAINFUNCTIONS_BASEARITHMETIC_H
