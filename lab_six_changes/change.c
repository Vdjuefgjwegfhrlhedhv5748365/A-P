
//функция вывода каталога
void print_catalog(BOOK *catalog, int cnt){
    if (cnt == 0 || catalog == NULL){
        printf("Catalog is empty\n");
        return;
    }
    printf("Catalog:\n");
    for (int i = 0; i < cnt; i++){
        printf("Book %d:\n", i+1);
        print_book(&catalog[i]);
    }
}
//функция вывода книги
void print_book(const BOOK *book){
    if (book == NULL){
        printf("Book is not finded\n");
        return;
    }
    printf("Author: %s\n", book->author);
    printf("Title: %s\n", book->title);
    printf("Year of publication: %d\n", book->year);
    printf("Price: %.2lf\n", book->price);
    printf("Category: %s\n", book->category);
    printf("\n");
}

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