#include <iostream>
#include <vector>
#include "MainFunctions/FuncFactory.h"
#include "NewOperators.h"
#include "Root.h"

using namespace std;

int main() {
    vector<float> v{1, 0, -1.5, 0, 2};
    vector<float> u{-1, 0, 1};
    auto factory = FuncFactory();
    auto a = factory.create("exp", -1.23);
    auto b = factory.create("power", -2);
    auto c = factory.create("poly", u);

    cout << c -> toString() << "     " << (*b).getDerivativeAtPoint(2) << endl
         << a -> toString() << "     " << (*a).getDerivativeAtPoint(1) << endl << (a + b)->toString() << endl;
    cout << getRoot(c, 10, 0.1, 100);
}
