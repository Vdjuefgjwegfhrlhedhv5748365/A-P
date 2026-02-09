// Лабораторная 5.
// - указатели на функции
// - структуры
#include "function_lab5_2-4.h"

void swapInt(void* a, void*b){
    int temp = *(int*)a;
    *(int*)a = *(int*)b;
    *(int*)b = temp;
}
void swapDbl(void* a, void*b){
    double temp = *(double*)a;
    *(double*)a = *(double*)b;
    *(double*)b = temp;
}
void swapStr(void* a,void* b){
    char* temp = *(char**)a;
    *(char**)a = *(char**)b;
    *(char**)b = temp;
}

char cmpInt(const void* a, const void* b){
    int a1 = *(const int*)a;
    int b1 = *(const int*)b;
    if (a1 < b1)
        return -1;
    if (a1 > b1)
        return 1;
    return 0;
}
char cmpDbl(const void* a, const void* b){
    double a1 = *(const double*)a;
    double b1 = *(const double*)b;
    if (a1 < b1)
        return -1;
    if (a1 > b1)
        return 1;
    return 0;
}

char cmpStr(const void* a, const void* b){
    const char* a1 = *(const char**)a;
    const char* b1 = *(const char**)b;
    return strcmp(a1, b1);
}

//сортировка пузырьком
void buble_sort(void* arr, size_t alen, size_t element_size, swap_funct swap_func, compare_funct compare_func){
    if (alen <= 1)
        return;
    char* memory = (char*)arr;
    for (size_t i = 0; i < alen - 1; i++){
        for (size_t j = 0; j < alen - i -1; j++){
            void* current = memory + j * element_size;
            void* next = memory + (j+1) * element_size;
            if (compare_func(current, next)>0){
                swap_func(current, next);
            }
        }
    }

}
//функции вывода массивов

void printIntArr(int arr[] , size_t alen){
    for (int i = 0; i < alen; i++){
        printf(" %d", arr[i]);
    }
    printf("\n");
}

void printDblArr(double arr[], size_t alen){
    for (int i = 0; i < alen; i++){
        printf(" %.2f", arr[i]);
    }
    printf("\n");
}

void printStrArr(char* arr[], size_t alen){
    for (int i = 0; i < alen; i++){
        printf(" %s", arr[i]);
    }
}

// --- Задание 3. Массивы указателей на функцию ---
    // Напишите несколько функций вида
    // const char* getString();
    // const char* getAnotherString();
    // и так далее
    // каждая из функций возвращает указатель на некоторую строку
    // (подумайте, какой адрес Вы имеете право возвращать из функции) 
    // Объявите и проинициализируйте массив указателей на функции.
    // Вызовите различные функции из массива
// const char* getString();
const char* getString(){
    static const char* string = "Hello World!";
    return string;
}
const char* getAnotherString(){
    static const char* string = "Privet Mir!";
    return string;
}
const char* getOneMoreString(){
    static const char* string = "laboratornay 5";
    return string;
}

// --- Задание 4. Структуры ---
    // Задание 4a. Объявите структуру Book, описывающую книгу
    // (автор, заглавие, год издания, цена, категория…).
    // Подумайте, какого типа могут быть поля структуры.
    // Объявление структуры рекомендуется выносить в заголовочный файл.
    // Задание 4б. Создайте разными способами (статический, динамический)
    // экземпляры (объекты) типа Book
    // Задание 4в. Заполните поля созданных объектов.
    // Напоминание: в строках нужна "защита" от выхода за границы массива.
    // Задание 4г. Напишите функцию, выводящую на экран реквизиты книги.
    // Подумайте, как эффективнее передавать экземпляр Book в функцию.

void printBook(const struct Book *book){
    if (book == NULL){
        printf("error\n");
        return;
    }
    printf("Author: %s\n", book->author);
    printf("title: %s\n", book->title);
    printf("year of published: %d\n", book->year);
    printf("Price: %.d\n", book->price);
    printf("Category: %s\n", book->category);
    printf("\n");
}
    