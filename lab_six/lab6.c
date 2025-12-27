# include "function.h"

/*
    ╔═══════════════════════════════╗
    ║          THE BOSS LAB         ║
    ╚═══════════════════════════════╝
         .-=========-.
         ( o )   ( o )
          |/ \___/ \|
           \  | |  /
            \_____/
             |   |
        /----|   |----\
       /     |   |     \.          /|
      /      |___|      \.        / |
     /      /=====\      \.      /  |
    /      |#######|      \.    /___/
   /       |#######|       \.    ||
  /        |#######|        \.   ||
 /         |#######|         \   ||
/          |#######|          \  ||
*/

int main(){
    
    BOOK *catalog = (BOOK*)malloc(sizeof(BOOK) * CHUNK_SIZE);
    if (catalog == NULL){
        printf("Error\n");
        return -1;
    }

    int cnt = 0;
    int capacity = CHUNK_SIZE;
    int option;

//загрузка каталога при старте
    loadCatalog_from_file(&catalog, &cnt, &capacity, "catalog.txt");

    while (1){
        printf("\n");
        printf("Menu of the library:\n");
        printf("1. Print a library\n"); //вывод библиотеки
        printf("2. Add a new book\n"); //добавление новой книги
        printf("3. Remove a book\n"); //удаление книги
        printf("4. Get a library from the file\n"); //добавить в библиотеку содержимое из файла
        printf("5. Put a library to the file\n"); //загрузить содержимое библиотеки в файл
        printf("6. Sort library\n"); //сортировка библиотеки
        printf("7. Exit\n"); //выход 
        printf("Choose the option\n");
        scanf("%d", &option);

        // Очистка буфера ввода после scanf
        while (getchar() != '\n');
        switch (option){
            case 1:
                print_catalog(catalog, cnt);
                break;
            case 2:{
                BOOK newBook;
                printf("Author: \n");
                fgets(newBook.author, sizeof(newBook.author), stdin);
                newBook.author[strcspn(newBook.author, "\n")] = '\0';
                printf("Title: \n");
                fgets(newBook.title, sizeof(newBook.title), stdin);
                newBook.title[strcspn(newBook.title, "\n")] = '\0';
                printf("Year of publishing: \n");
                scanf("%d", &newBook.year);
                printf("Price: \n");
                scanf("%lf", &newBook.price);

                while (getchar() != '\n');

                printf("Category: \n");
                fgets(newBook.category, sizeof(newBook.category), stdin);
                newBook.category[strcspn(newBook.category, "\n")] = '\0';
                while (getchar() != '\n');
                if (addTolib(&catalog, &cnt, &capacity, &newBook) == 0){
                    printf("Book succesfully has added!\n");
                }
                else {
                    printf("Error, something went wrong\n");
                }
                break;
            }
            case 3:{
                if (cnt == 0){
                    printf("Can't delete book, library is empty\n");
                    break;
                }
                int index;
                printf("Put the index of the book, which you want remove: \n");
                scanf("%d", &index);
                if (remove_Book(catalog, &cnt, index) == 0){
                    printf("Book is removed\n");
                }
                else {
                    printf("Error, incorrect index\n");
                }
                break;
            }
            case 4:
                if (loadCatalog_from_file(&catalog, &cnt, &capacity, "catalog.txt") == 0){
                    printf("Library is loaded from file!\n");
                }
                else {
                    printf("Error, something went wrong\n");
                }
                break;
            case 5:
                if (saveCatalog_to_file(catalog, cnt, "catalog.txt") == 0) {
                    printf("Library is loaded to file!\n");
                }
                else{
                    printf("Error. Something went wrong\n");
                }
                break;
            case 6:
                if (cnt == 0){
                    printf("Can't sort! Library is empty\n");
                    break;
                }
                
                printf("Choose the part of sorting\n");
                printf("1. Author\n");
                printf("2. Title\n");
                printf("3. Year\n");
                printf("4. Price\n");
                printf("5. Category\n");

                int sortOpt;
                scanf("%d", &sortOpt);
                SortingType type;

                switch (sortOpt){
                    case 1: 
                        type = SORT_AUTHORS;
                        break;
                    case 2:
                        type = SORT_TITLES;
                        break;
                    case 3:
                        type = SORT_YEARS;
                        break;
                    case 4:
                        type = SORT_PRICES;
                        break;
                    case 5:
                        type = SORT_CATEGORIES;
                        break;
                    default: printf("Error. Incorrect number\n");
                        break;
                }
                sort_catalog(catalog, cnt, type);
                printf("Library succesfully sorted\n");
                break;
                
            case 7:
                printf("Exit\n");
                saveCatalog_to_file(catalog, cnt, "catalog.txt");
                freeCatalog(catalog);
                return 0;
            default:
                printf("Error. Incorrect number\n");
        }
    }
    freeCatalog(catalog);
}