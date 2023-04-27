//MY Math.h
/*
* network.cpp
*
* Version information
* Author: Conall Hanley
* Date:3/24/2023
* Description: This is the header file for a collection of helper functions that multiple classes may rely on
* This class defines a specific model.
* TODO Allow it to generate various models.
*
* Copyright notice -
*/
#pragma once

#include <math.h>
#include <stdlib.h>
#include <string.h>

double my_math_euler_num();

double my_math_power(double base, double exp);

char* my_math_toArray(int number);

char* my_math_concat(char * str1, char * str2 );

void *safe_malloc(size_t n);

double my_math_relu(double act);

double my_math_relu_deriv(double act);

double my_math_error(double act, double right);

double my_math_error_deriv(double act, double right);
