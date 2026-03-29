#include "function_lab5_2-4.h"

int main(){
    // --- Задание 2. Указатель на функцию в качестве аргумента ---
    // 2а. Реализуйте функцию сортировки любых объектов sort, которая принимает следующие параметры:
    // 1) указатель на первый сортируемый элемент (void*)
    // 2) количество сортируемых элементов
    // 3) размер элемента в байтах
    // 4) указатель на функцию перестановки элементов, которая принимает на вход два значения типа void*
    // 5) указатель на функцию сравнения элементов, которая принимает также два указателя и возвращает short

    // В качестве примера напишите функцию swapInt перестановки двух целых чисел
    // (принимает два указателя на void и меняет значения местами)
    // и функцию cmpInt, которая принимает два void указателя и
    // возвращает тип short - результат сравнения:
    // <0 - первый элемент меньше, чем второй
    // =0 - равны
    // >0 - первый элемент больше, чем второй

    int a[] = {5, 7, 3, -1, 2, 3};
    int alen = 6;
    printf("\nbefore:\n");
    printIntArr(a, alen);
    buble_sort((void*)a, alen, sizeof(int), swapInt, cmpInt);
    printf("\nafter:\n");
    printIntArr(a, alen);
    //double
    // Задание 2б. По аналогии с 8а создайте вспомогательные
    // функции swapDouble и cmpDouble. Примените функцию sort
    // для сортировки массива вещественных значений.
    double b[] = {34.6, 67.4, 45.6, 100.0, -45.76};
    int blen = 5;
    printf("\nbefore:\n");
    printDblArr(b, blen);
    buble_sort((void*)b, blen, sizeof(double), swapDbl, cmpDbl);
    printf("\nafter:\n");
    printDblArr(b, blen);
    //str
    // Задание 2в. По аналогии с 8а создайте вспомогательные
    // функции - swapStr и cmpStr; вызовите функцию Sort
    // для сортировки массива указателей на строки.
    //  char* arStr[] = {"QQQ", "SDF", "ABC"...};
    char* arStr[] = {"QQQ", "SDF", "ABC", "GRT"};
    int stlen = 4;
    printf("\nbefore:\n");
    printStrArr(arStr, stlen);
    buble_sort((void*)arStr, stlen, sizeof(char*), swapStr, cmpStr);
    printf("\nafter:\n");
    printStrArr(arStr, stlen);
    
    //3
    const char* (*func[3])() = {getString, getAnotherString, getOneMoreString};
    //вызов функций через массив указателей
    for (int i = 0; i < 3; i++){
        const char* res = func[i]();
        printf("\nFunction %d: %s\n", i+1, res);
    }
    //вызов функций через индексы
    printf("\nFirst function: %s\n", func[0]());
    printf("\nSecond function: %s\n", func[1]());
    printf("\nThird function: %s\n", func[2]());
    
    //4 
    printf("\n");
    struct Book st_book;
    struct Book* din_book = (struct Book*)malloc(sizeof(struct Book));
    if (din_book == NULL){
        printf("error\n");
        return 1;
    }
    //заполнение структуры
    //cтатическая книга
    strncpy(st_book.author, "A.S.Pushkin", sizeof(st_book.author)-1);
    st_book.author[sizeof(st_book.author)-1]= '\0';
    strncpy(st_book.title, "Eugene Onegin", sizeof(st_book.title)-1);
    st_book.title[sizeof(st_book.title)-1] = '\0';
    st_book.year = 1833;
    st_book.price = 1000;
    strncpy(st_book.category, "Classic literature", sizeof(st_book.category)-1);
    st_book.category[sizeof(st_book.category)-1]='\0';
    //динамическая книга
    strncpy(din_book->author, "M.A.Sholokhov", sizeof(din_book->author)-1);
    din_book->author[sizeof(din_book->author)-1] = '\0';
    strncpy(din_book->title, "Quiet Flows the Don", sizeof(din_book->title)-1);
    din_book->title[sizeof(din_book->title)-1] = '\0';
    din_book->year = 1928;
    din_book->price = 750;
    strncpy(din_book->category,"Historic novel", sizeof(din_book->category)-1);
    din_book->category[sizeof(din_book->category)-1] = '\0';
    //4г
    printf("\nFirst book:\n");
    printBook(&st_book);
    printf("\nSecond book:\n");
    printBook(din_book);


    free(din_book);
    return 0;
}
