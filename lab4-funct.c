#include "function.h"

//функция к заданию 2
//Напишите два варианта функции поиска минимального элемента
//для встроенного двумерного массива
void mini(int* arr, int line, int col){
    int minN = 1000;
    for (int i = 0; i < line; i++){
        for (int j = 0; j < col; j++){
            if (arr[i * col + j] < minN){
                minN = arr[i * col + j];
            }
    
        }
    }
    printf("%d", minN);
}
//для динамического двумерного массива
int mini_d(int** arr, int line, int col){
    int m = arr[0][0];
    for (int i = 0; i< line; i++){
        for (int j = 0; j < col; j++){
            if (arr[i][j] < m)
                m = arr[i][j];
        }
    }
    return m;
}
//функция для задания 3
// Функция должна принимать два указателя на сравниваемые
// строки (возможно, понадобится сказать компилятору, что функция
// не имеет права модифицировать содержимое строк)
// Функция должна возвращать отрицательное значение, если
// первая строка лексиграфически меньше второй, 0 - если они равны
// и положительное значение, если первая строка больше второй.
// Вспомните, что признаком конца строки является нулевой байт.
int Mystrcp(const char* a, const char* b){
    while (*a == *b && *a != 0){
        a++;
        b++;
    }
    return *a - *b;
}

//функции для задания 4
//функция вывода массива 
void print_array(int *array, int size){
    for (int i = 0; i < size; i++){
        printf(" %d", array[i]);
    }
    printf("\n");
}
// Напишите функцию, которая добавляет в массив новое значение только при условии,
// что такого значения в массиве еще нет. Подсказка: при этом размер
// массива должен увеличиться!
int arr_add(int** array, int* size, int number){
    for (int i = 0; i < *size; i++){
        if ((*array)[i]==number)
            return 0;
    }
    *array = realloc(*array, (*size+1)*sizeof(int));
    if (*array == NULL)
        return -1;
    (*array)[*size] = number;
    (*size)++;
    return 1;
}

//функция для задания 5
//5а функция вычисления суммы первых N натуральных чисел
int summa(int num){
    if (num == 0)
        return 0;
    return num + summa(num-1);
}
//5b функция для вычисления N-го числа Фибоначчи
int fibo(int n){
    if (n == 0) return 0;
    if (n== 1) return 1;
    return fibo(n-2) + fibo(n-1);
}

//функция для задания 7
// Напишите функцию, которая находит минимальное значение в массиве,
// таким образом, чтобы ее вызов можно было использовать слева от знака
// равенства: *myMin(параметры) = 0;
int *myMin(int *array, int size){
    int *mini = array;
    for (int i = 1; i < size; i++){
        if (array[i] < *mini) mini = &array[i];
    }
    return mini;
}
