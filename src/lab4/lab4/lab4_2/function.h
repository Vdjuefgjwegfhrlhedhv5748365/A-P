#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <limits.h>
#include "minunit.h"

//1
void swap(int* a, int* b);
MU_TEST(test_1);
MU_TEST(test_2);
MU_TEST(test_3);
MU_TEST(test_4);
MU_TEST(test_5);
MU_TEST(test_6);
MU_TEST(test_7);
MU_TEST(test_8);
MU_TEST(test_9);
MU_TEST(test_10);
MU_TEST_SUITE(my_test_suite);
//2
void mini(int* arr, int line, int col);
int mini_d(int** arr, int line, int col);
int Mystrcp(const char* a, const char* b);
void print_array(int *array, int size);
int arr_add(int** array, int* size, int number);
int summa(int num);
int fibo(int n);
int *myMin(int *array, int size);