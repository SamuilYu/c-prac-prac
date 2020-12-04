#ifndef MAINFUNCTIONS_ROOT_H
#define MAINFUNCTIONS_ROOT_H

#include "MainFunctions/BaseFunction.h"

float getRoot(const shared_ptr<BaseFunction>& func, float start, float step, size_t numberOfIteration) {
    float x2 = 0;
    float x1 = start;
    for (int i = 0; i < numberOfIteration; ++i) {
        float temp = x1;
        x1 = x1 - step * abs(x1 - x2)
                / abs(2 * (*func)(x1) * func->getDerivativeAtPoint(x1) - 2 * (*func)(x2) * func->getDerivativeAtPoint(x2))
                * 2 * (*func)(x1) * func->getDerivativeAtPoint(x1);
        x2 = temp;
    }
    return x1;
}

#endif //MAINFUNCTIONS_ROOT_H
