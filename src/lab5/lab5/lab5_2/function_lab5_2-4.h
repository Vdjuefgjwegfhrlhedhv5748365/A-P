#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
//swap
void swapInt(void*a, void*b);
void swapDbl(void*a, void*b);
void swapStr(void*a, void*b);
//cmp
char cmpInt(const void* a, const void* b);
char cmpDbl(const void* a, const void* b);
char cmpStr(const void* a, const void* b);
//типы указателей на функции
typedef void(*swap_funct)(void*, void*);
typedef char (*compare_funct)(const void*, const void*);
//универсальная функция сортировки
void buble_sort(void* arr, size_t alen, size_t element_size, swap_funct swap_func, compare_funct compare_func);
//вывод массива
void printIntArr(int arr[] , size_t alen);
void printDblArr(double arr[], size_t alen);
void printStrArr(char* arr[], size_t alen);
//3
const char* getString();
const char* getAnotherString();
const char* getOneMoreString();
//4
struct Book{
    char author[200];
    char title[200];
    int year;
    int price;
    char category[200];
};
void printBook(const struct Book *book);