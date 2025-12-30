#include "function.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//фунция добавления книги в библиотеку
int addTolib(BOOK **catalog, int *cnt, int *capacity, const BOOK *newbook){
    if (catalog == NULL || newbook == NULL)
        return -1;
//проверяем: если массив заполнен, то увеличиваем его на CHUNK_SIZE элементов 
    if (*cnt >= *capacity){
        int new_capacity = *capacity + CHUNK_SIZE;
        BOOK *temp = (BOOK*)realloc(*catalog, new_capacity * sizeof(BOOK));
        if (temp == NULL){
            printf("Error, something went wrong");
            return 0;
        }
        *catalog = temp;
        *capacity = new_capacity;
    }
    //добавление книги
    (*catalog)[*cnt] = *newbook;
    (*cnt)++;
    return 0;
}
//функция вывода каталога (я объеденила функцию вывода книги и каталога)
void print_catalog(BOOK *catalog, int cnt) {
    if (cnt == 0 || catalog == NULL) {
        printf("Catalog is empty\n");
        return;
    }
    printf("Catalog:\n");
    for (int i = 0; i < cnt; i++) {
        printf("Book %d:\n", i + 1);
        
        // Проверка на NULL текущей книги в каталоге
        if (&catalog[i] == NULL) {
            printf("Book is not found\n");
            continue;
        }
        printf("Author: %s\n", catalog[i].author);
        printf("Title: %s\n", catalog[i].title);
        printf("Year of publication: %d\n", catalog[i].year);
        printf("Price: %.2lf\n", catalog[i].price);
        printf("Category: %s\n", catalog[i].category);
        printf("\n");
    }
}

//функция удаления книги
int remove_Book(BOOK *catalog, int *cnt, int index){
    if (catalog == NULL || *cnt == 0){
        printf("Library is empty\n");
        return -1;
    }
    if (index < 0 || index >= *cnt){
        printf("Invalid index\n");
        return -1;
    }
    for (int i = index; i < *cnt-1; i++){
        catalog[i]= catalog[i+1];
    }
    (*cnt)--;
    return 0;
}

//функция, позволяющая сохранить каталог в файл
int saveCatalog_to_file(const BOOK *catalog, int cnt, const char *filename){
    if (catalog == NULL || cnt == 0){
        printf("Library is emty. Nothing to save\n");
        return -1;
    }
    FILE *file = fopen(filename, "w");
    if (file == NULL){
        printf("File can't be open\n");
        return -1;
    }
    fprintf(file, "%d\n", cnt);

    for (int i = 0; i < cnt; i++){
        fprintf(file, "%s\n%s\n%d\n%lf\n%s\n", 
            catalog[i].author, 
            catalog[i].title,
            catalog[i].year, 
            catalog[i].price,
            catalog[i].category);
    }
    fclose(file);
    return 0;
}

//функция позволяющая добавить книги из файла в каталог
int loadCatalog_from_file(BOOK **catalog, int *cnt, int *capacity, const char *filename){
    FILE *file = fopen(filename, "r");
    if (file == NULL){
        printf("File is not finded\n");
        return -1;
    }
    fscanf(file, "%d\n", cnt);
    if (*cnt == 0){
        fclose(file);
        return -1;
    }
    if (*cnt > *capacity){
        *catalog = realloc(*catalog, *capacity * sizeof(BOOK));
        if (*catalog == NULL){
            printf("Error, something went wrong");
            fclose(file);
            return -1;
        }
    }
    for (int i = 0; i < *cnt; i++){
        fgets((*catalog)[i].author, sizeof((*catalog)[i].author), file);
        (*catalog)[i].author[strcspn((*catalog)[i].author, "\n")] = '\0';
        fgets((*catalog)[i].title, sizeof((*catalog)[i].title), file);
        (*catalog)[i].title[strcspn((*catalog)[i].title, "\n")] = '\0';
        fscanf(file, "%d\n", &(*catalog)[i].year);
        fscanf(file, "%lf\n", &(*catalog)[i].price);
        fgets((*catalog)[i].category, sizeof((*catalog)[i].category), file);
        (*catalog)[i].category[strcspn((*catalog)[i].category, "\n")] = '\0';
    }
    fclose(file);
    return 0;
}

//функция сравнения книг
int compare_books(const BOOK *a, const BOOK *b, SortingType type){
    switch (type) {
        case SORT_AUTHORS:
            return strcmp(a->author, b->author);
        case SORT_TITLES:
            return strcmp(a->title, b->title);
        case SORT_YEARS:
            return a->year -  b->year;
        case SORT_PRICES:
            if (a->price < b->price) return -1;
            if (a->price > b->price) return 1;
            return 0;
        case SORT_CATEGORIES:
            return strcmp(a->category, b->category);
        default:
            return 0;
    }
}




//освобождение памяти
void freeCatalog(BOOK *catalog){
    if (catalog != NULL)
        free(catalog);
}