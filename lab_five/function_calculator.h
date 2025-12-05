#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>

//тут будет реализация функций
typedef double (*operation)(double, double);
double sum(double a, double b);
double sub(double a, double b);
double mul(double a, double b);
double divv(double a, double b);
double power(double a, double b);
double calculator(double a, double b, operation oper);
void operation_tests();
void menu();
double get_number(const char* num);
char get_oper();

operation sum_ptr;
operation sub_ptr;
operation mul_ptr;
operation divv_ptr;
operation power_ptr;
