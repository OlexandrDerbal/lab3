#pragma once

class Dyhotomia {
private:
    double a, b, epsilon;
    int maxIterations;
    double root;

public:
    Dyhotomia(double a_, double b_, double eps_, int maxIt_);
    double f(double x);
    void solve(); // пошук кореня
    void printResult();
};

class Newton {
private:
    double x0, epsilon;
    int maxIterations;
    double root;

public:
    Newton(double x0_, double eps_, int maxIt_);
    double f(double x);
    double df(double x);
    void solve();
    void printResult();
};
