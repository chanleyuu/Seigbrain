//Math.c contains math functions
double my_math_euler_num() 
{
    double out = 1;
    double lastnum = 1;
        for (int i = 1; i < 40; i++) {
            out += 1 / (lastnum * i);
            lastnum = lastnum * i;
        }

    return out;
}

double my_math_power(double base, double exp){
    double out = base;
    
    for (double i = 1; i < exp; i++) {
        out *= base;
    }
    return out;
}
