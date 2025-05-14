#include <iostream>
#include <cmath>
#include "Dyhotomia_class.h"

using namespace std;

// Dyhotomia
Dyhotomia::Dyhotomia(double a_, double b_, double eps_, int maxIt_) {
    a = a_;
    b = b_;
    epsilon = eps_;
    maxIterations = maxIt_;
    root = 0.0; // Ініціалізація
}

double Dyhotomia::f(double x) {
    return cos(2 / x) - 2 * sin(1 / x) + 1 / x;
}

void Dyhotomia::solve() {
    int iterations = 0;
    double c;

    if (f(a) * f(b) >= 0) {
        cout << "Помилка: немає гарантiї наявностi кореня на вiдрiзку.\n";
        return;
    }

    while ((b - a) / 2.0 > epsilon && iterations < maxIterations) {
        c = (a + b) / 2.0;
        if (f(c) == 0.0)
            break;
        else if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;
        iterations++;
    }

    root = (a + b) / 2.0;
}

void Dyhotomia::printResult() {
    cout << "Метод дихотомiї: корiнь ~ " << root << endl;
}

// Newton
Newton::Newton(double x0_, double eps_, int maxIt_) {
    x0 = x0_;
    epsilon = eps_;
    maxIterations = maxIt_;
    root = 0.0; // Ініціалізація
}

double Newton::f(double x) {
    return cos(2 / x) - 2 * sin(1 / x) + 1 / x;
}

double Newton::df(double x) {
    double h = 1e-6;
    return (f(x + h) - f(x)) / h;
}

void Newton::solve() {
    int iterations = 0;
    double x = x0, x1;

    while (iterations < maxIterations) {
        double dfx = df(x);
        if (fabs(dfx) < 1e-10) {
            cout << "Похiдна надто мала, метод не працює.\n";
            return;
        }

        x1 = x - f(x) / dfx;
        if (fabs(x1 - x) < epsilon)
            break;

        x = x1;
        iterations++;
    }

    root = x;
}

void Newton::printResult() {
    cout << "Метод Ньютона: корiнь ~ " << root << endl;
}
