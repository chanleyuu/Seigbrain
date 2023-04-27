
#include "my_math.h"
#include <stdio.h>
//Math.c contains math and other helper functions
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


char * my_math_toArray(int number)
{
    int n = log10(number) + 1;
    int i;
    char *numberArray = (char*) calloc(n, sizeof(char));
    for (i = n-1; i >= 0; --i, number /= 10)
    {
        numberArray[i] = (number % 10) + '0';
    }
    return numberArray;
}

char * my_math_concat(char * str1, char * str2 ) {
    char *result = (char *) safe_malloc(strlen(str1) + strlen(str2) + 1); // +1 for the null-terminator
    strcpy(result, str1);
    strcat(result, str2);
    return result;
}

void *safe_malloc(size_t n)
{
    void *p = malloc(n);
    if (p == NULL) {
        fprintf(stderr, "Fatal: failed to allocate %zu bytes.\n", n);
        abort();
    }
    return p;
}

double my_math_relu(double act)
{
    if (act > 0) {
        return act;
    }

    return 0.01 * act;
}

double my_math_relu_deriv(double act)
{
    if (act > 0) {
        return 1.0;
    }

    return 0.01;
}


double my_math_error(double act, double right)
{
    double out = ((act * log(right)) + ((1 - act) * log(1.001 - right)));

    return out;
}

double my_math_error_deriv(double act, double right)
{
    double out = right - act / (right - 1) * right;
    return out;
}

