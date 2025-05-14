#include <iostream>
#include <windows.h>
#include "Dyhotomia_class.h"

int main() {
    setlocale(LC_ALL, "ukr");
    std::cout << "Рiвняння: f(x) = cos(2/x) - 2sin(1/x) + 1/x\n\n";

    Dyhotomia dyh(1.0, 2.0, 1e-6, 100);
    dyh.solve();
    dyh.printResult();

    std::cout << std::endl;

    Newton newt(1.5, 1e-6, 100);
    newt.solve();
    newt.printResult();

    return 0;
}
