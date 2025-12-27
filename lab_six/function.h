#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHUNK_SIZE 10

//структура книги
typedef struct BOOK{
    char author[100];
    char title[100];
    int year;
    double price;
    char category[75];
} BOOK;

//определение по какому полю сортировать
typedef enum{
    SORT_AUTHORS,
    SORT_TITLES,
    SORT_YEARS,
    SORT_PRICES,
    SORT_CATEGORIES
} SortingType;

int addTolib(BOOK **catalog, int *cnt, int *capacity, const BOOK *newbook);
void print_book(const BOOK *book);
void print_catalog(BOOK *catalog, int cnt);
int remove_Book(BOOK *catalog, int *cnt, int index);
int saveCatalog_to_file(const BOOK *catalog, int cnt, const char *filename);
int loadCatalog_from_file(BOOK **catalog, int *cnt, int *capacity, const char *filename);
int compare_books(const BOOK *a, const BOOK *b, SortingType type);
void sort_catalog(BOOK *catalog, int cnt, SortingType type);
void freeCatalog(BOOK *catalog);
