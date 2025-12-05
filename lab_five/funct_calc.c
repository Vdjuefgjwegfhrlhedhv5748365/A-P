#include "function_calculator.h"
typedef double (*operation)(double, double);
//1) sum - принимает два значения типа double и возвращает сумму
double sum(double a, double b){
    return a + b;
}
//2) sub - разность
double sub(double a, double b){
    return a - b;
}
// 3) mul - произведение
double mul(double a, double b){
    return a * b;
}
// 4) div - результат деления
double divv(double a, double b){
    if (b == 0){
        printf("error");
        return 0;
    }
    return a / b;
}
// 5) возведение в степень
double power(double a, double b){
    return pow(a, b);
}

double calculator(double a, double b, operation oper){
    return oper(a, b);
}

operation sum_ptr = &sum;
operation sub_ptr = &sub;
operation mul_ptr = &mul;
operation divv_ptr = &divv;
operation power_ptr = &power;


void operation_tests(){
    assert(sum_ptr(23.5, 40.5) == 64.0);
    assert(sum_ptr(0, 0)==0.0);
    assert(sum_ptr(-3.0, -4.0)== -7.0);

    assert(sub_ptr(10.0, 2.0) == 8.0);
    assert(sub_ptr(0, 0)==0.0);
    assert(sub_ptr(-8.0, -4.0)== -4.0);

    assert(mul_ptr(10.0, 1.0) == 10.0);
    assert(mul_ptr(0, 0)==0.0);
    assert(mul_ptr(-2.0, -3.0)== 6.0);
    
    assert(divv_ptr(15.0, 3.0) == 5.0);
    assert(divv_ptr(5.0, 2.0)==2.5);
    assert(divv_ptr(-6.0, -3.0)== 2.0);

    assert(power_ptr(2.0, 2.0) == 4.0);
    assert(power_ptr(1.0, 23.0)==1.0);
    assert(power_ptr(-8.0, 3.0)== -512.0);

    assert(calculator(1.0, 2.0, sum_ptr) == 3.0);
    assert(calculator(5.0, 4.0, sub_ptr) == 1.0);
    assert(calculator(6.0, 7.5, mul_ptr) == 45.0);
    assert(calculator(9.0, 3.0, divv_ptr) == 3.0);
    assert(calculator(10.0, 2.0, power_ptr) == 100.0);
    
    printf("tests passed succesfully");
}
void menu(){
    printf("choose operation:\n");
    printf(" + - summa\n");
    printf(" - - substraction\n");
    printf(" * - multiplication\n");
    printf(" / - division\n");
    printf(" ^ - raising to a power\n");
    printf("! - exit\n");
}
double get_number(const char* num){ //why we need num ?
    double value;
    int res;
    while (1){
        printf("%s", num);
        res = scanf("%lf", &value);
        if (res == 1){
            return value;
        }
        else{
            printf("error - incorret number\n");
            while (getchar() != '\n');
        }
    }
}
char get_oper(){
    char sign_oper;
    int res;
    while (1){
        printf("Выберите операцию (+, -, *, /, ^, ! - exit): ");
        res = scanf(" %c", &sign_oper);
        if (res == 1){
            if (sign_oper == '+' || sign_oper == '-' || sign_oper == '*' || sign_oper == '/' || sign_oper == '^' || sign_oper == '+' ){
                return sign_oper;
            }
            else{
                printf("incorrect input - unknown operation\n");
                while (getchar() != '\n');
            }
        }
        else{
            printf("incorrect symbol\n");
            while (getchar() != '\n');
        }
    }
}