#include <math.h>

struct SecureGen {
    // TODO: Use the key to generate working
    double (*constant)(long long);
    double (*slope)(long long);
    double (*startValue)(long long);
};

double Gen_constant(long long KEY){
//    return fabs(KEY/1.45E16);
    return 250.0;
}

double Gen_slope(long long KEY){
//    return fabs(2.7E17/KEY);
    return 1.124;
}

double Gen_startValue(long long KEY) {
//    return fabs(sin(KEY));
    return 0.59;
}

const struct SecureGen Gen = {Gen_constant, Gen_slope, Gen_startValue};
