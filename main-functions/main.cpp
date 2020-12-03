#include <iostream>
#include <vector>
#include "MainFunctions/BaseFunction.h"
#include "MainFunctions/Polynomial.h"
#include "NewOperators.h"

using namespace std;

int main() {
    vector<float> v{1, 0, -1.5, 0, 2};
    vector<float> u{0, -1, -0.5, 0, 0, 0, 2 , 1, 2, 0};
    shared_ptr<BaseFunction> a = make_shared<Polynomial>(Polynomial(v));
    shared_ptr<BaseFunction> b = make_shared<Polynomial>(Polynomial(u));
    shared_ptr<Polynomial> c = make_shared<Polynomial>(u);

    cout << b -> toString() << "     " << b -> getDerivativeAtPoint(1) << endl
         << a -> toString() << "     " << a -> getDerivativeAtPoint(1) << endl << ((*a) + (*b)).getDerivativeAtPoint(1);
}
