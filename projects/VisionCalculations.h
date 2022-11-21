#include "math.h"

double calculateH(double x, double r, double theta) {
    return sqrt(pow(x, 2) + pow(r, 2) + 2 * x * r * cos(theta));
}

double calculateP(double r, double h, double theta) {
    return asin((r / h) * sin(theta));
}

double calculateCoordX(double x, double r, double theta) {
    return calculateH(x, r, theta) * cos(calculateH(x, r, theta));
}

double calculateCoordY(double x, double r, double theta) {
    return calculateH(x, r, theta) * sin(calculateP(x, calculateH(x, r, theta), theta));
}

double calculateEfficientCoordX(double x, double r, double theta) {
    double h = sqrt(x * x + r * r + x * r * cos(theta));
    return h * sin(asin(r / h) * sin(theta));
}

double calculateEfficientCoordY(double r, double theta) {
    return r * sin(theta);
}
