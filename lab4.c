#include "function.h"

int main()
{
    // Задание 2. Указатели на массивы в качестве аргументов.
    // Напишите два вариант функции поиска минимального элемента
    // 2a. во встроенном двухмерном массиве
    // 2b. в динамическом двухмерном массиве (обе размерности вычисляются)
    printf(" задание 2\n");
    int lines = 3;
    int colums = 2;
    //создание встроенного двумерного массива
    int two_arr[3][2] = { {2, 67}, {45, 109}, {-7, 345} };
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 2; j++){
            printf("%d ", two_arr[i][j]);
        }
    }
    printf("\nmin element of massive: ");
    mini((int*)two_arr, 3, 2); //поиск минимального элемента
    printf("\n");

    //создание динамического двумерного массива
    int** dyn_arr = (int**)malloc(lines * sizeof(int*));
    for (int i = 0; i < lines; i++){
        dyn_arr[i] = (int*)malloc(colums * sizeof(int));
    }

    for (int i = 0; i < lines; i++){
        for (int j = 0; j < colums; j++){
            dyn_arr[i][j] = (rand()%100);
            printf("%d ", dyn_arr[i][j]);
        }
    }
    printf("\n");
    int res1 = mini_d(dyn_arr, lines, colums);
    printf("\nmin element of dinamyc massive: %d\n", res1); //поиск минимального элемента
    // Например:
    // int ar[N][M] = {список значений};
    // int res = myMin(ar, ... наверняка понадобится передать ещё какие-нибудь данные);
    
    // Задание 3. Напишите функцию сравнения двух строк - myStrCmp():
    printf("\nзадание 3\n");
    printf("abc - def: %d\n", Mystrcp("abc", "def"));
    printf("aaa - aaa: %d\n", Mystrcp("aaa", "aaa"));
    
    // Задание 4. Создайте одномерный динамический массив, заполните его значениями.
    // Для проверки напишите функцию, которая выводит значения всех элементов на экран
    printf("\nзадание 4\n");
    int n = 6;
    int* arr_4 = (int*)malloc(n *sizeof(int));
    for (int i = 0; i < n; i++){
        arr_4[i] = i;
    }
    print_array(arr_4, n);
    arr_add(&arr_4, &n, 100); //почему-то не добавляется
    print_array(arr_4, n);
    arr_add(&arr_4, &n, 100); //повтор => не добавится
    print_array(arr_4, n);
    free(arr_4);
    // Задание 5. Рекурсивные функции.
    // 5a. Напишите рекурсивную функцию вычисления суммы первых N натуральных чисел
    // 5б. Напишите рекурсивную функцию для вычисления N-го числа Фибоначчи
    printf("\nЗадание 5\n");
    printf("\nsum of first 6 numbers: %d\n", summa(6));
    printf("\nfibonachi 8: %d", fibo(8));

    // Задание 7. Возвращение адреса.
    printf("\nзадание 7\n");
    int arr_7[]={12, 34, 56, 78, 90};
    printf("massive before:");
    for (int i = 0; i < 5; i++){
        printf("%d ", arr_7[i]);
    }
    *myMin(arr_7, 5) = 0;
    printf("\nmassive after:");
    for (int i = 0; i < 5; i++){
        printf(" %d", arr_7[i]);
    }
    printf("\n");
    
    return 0;
}


