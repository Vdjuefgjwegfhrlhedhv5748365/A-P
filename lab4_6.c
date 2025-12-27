#include <stdio.h>
#include <stdarg.h>
//функция для задания 6
// Напишите функцию varArgs, не использующую макросы,
// которая принимает переменное число аргументов (см. подсказку внизу кода задания)
// типа int и выводит на печать число принятых параметров и их значения.
// Признаком конца списка параметров является нулевое значение.
void varArgs(int arg1, ...) {
    int nArgs = 0;
    int *ptr = &arg1;
    while (*ptr != 0) {
        printf("%d ", *ptr);
        ptr++;
        nArgs++;
    }
    printf("Количество принятых аргументов: %d\n", nArgs);
}

//функция к заданию 6б
//модифицированная функция varArgs c макросами
void VarArgs_macros(int first, ...) {
    va_list args;
    va_start(args, first);
    int cnt = 0;
    int number = first;
    while (number != 0) {
        printf("%d ", number);
        number = va_arg(args, int);
        cnt++;
    }
    printf("Количество принятых аргументов: %d\n", cnt);
    va_end(args);
}


int main(){
       // Задание 6а. Функции с переменным числом параметров.
    
    printf("\nЗадание 6\n");
    int args[] = {5, 11, 4, 7, -1};
    
    varArgs(args[0], 0);
    varArgs(args[0], args[1], 0);
    varArgs(args[0], args[1], args[2], args[3], -1, 0);

    // Задание 6б. Модифицируйте функцию 6а с помощью макросов
    //  va_start, va_arg, va_end
    printf("\nзадание 6b\n");
    VarArgs_macros(args[0], 0);
    VarArgs_macros(args[0], args[1], 0);
    VarArgs_macros(args[0], args[1], args[2], args[3], -1, 0);
    return 0;
}