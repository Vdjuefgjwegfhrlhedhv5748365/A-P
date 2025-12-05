// Лабораторная 5.
// - указатели на функции
// - структуры
#include "function_calculator.h"

int main()
{
    // --- Задание 1. Указатель на функцию. "Калькулятор" ---
    // Напишите функции:
    // 1) sum - принимает два значения типа double и возвращает сумму
    // 2) sub - разность
    // 3) mul - произведение
    // 4) div - результат деления
    // 5) возведение в степень - можно воспользоваться pow() из <math.h>
    
    // не забудьте unit-тесты
    
    // Сделайте интерфейс калькулятора.
    // Пока пользователь хочет пользоваться калькулятором,
    // он может вводить два значения и знак операции;
    // результат выводится на экран.
    // Если ввод некорректный, нужно сообщить об этом пользователю и продолжить работу

    operation_tests();
    double a = 15.0, b = 5.0;
    operation *operArr = malloc(5 * sizeof(operation));
    operArr[0] = &sum;
    operArr[1] = &sub;
    operArr[2] = &mul;
    operArr[3] = &divv;
    operArr[4] = &power;
    printf("\n");
    
    char* names_operation[] = {"summa", "substraction", "multiplication", "division", "raising to a power"};
    for (int i = 0; i < 5; i++){
        double result = calculator(a, b, operArr[i]);
        printf("%.1f and %.1f - %s: %.1f\n", a, b, names_operation[i], result);
    }
    free(operArr);

    printf("calculater");
    bool cont_process = true;
    while (cont_process){
        menu();
        char symbol = get_oper();
        if (symbol == '!'){
            printf("stop calculating");
            break;
        }
        double x, y;
        x = get_number("first number:\n");
        y = get_number("second number:\n");

        operation selected_operation = NULL;
        char* name_operation = "";
        char symbol_operation = symbol;
        switch(symbol){
            case '+': 
                selected_operation = &sum; 
                name_operation = "summa";
                break;
            case '-': 
                selected_operation = &sub;
                name_operation = "substraction";
                break;
            case '*': 
                selected_operation = &mul; 
                name_operation = "multiplication";
                break;
            case '/': 
                selected_operation = &divv; 
                name_operation = "division";
                break;
            case '^': 
                selected_operation = &power; 
                name_operation = "raising to a power";
                break;
            default:
                printf("error, incorrect input");
                return 1;
        }
        if (selected_operation != NULL){
            double result = calculator(x, y, selected_operation);
            printf("\n result: %.1f %c %.1f = %.1f\n", x, symbol, y, result);
        }
        char continue_calculating;
        printf("\n continue calculating? (y/n):\n");
        scanf(" %c", &continue_calculating);
        if (continue_calculating == 'n' || continue_calculating == 'N'){
            cont_process = false;
            printf("exit, best wishes!");
        }
    }
    
    return 0;
}