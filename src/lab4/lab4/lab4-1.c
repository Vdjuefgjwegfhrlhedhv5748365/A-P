#include "function.h"

#define FIRST 6
#define SECOND 36
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
MU_TEST(test_1){
    int a = 10, b = 100;
    swap(&a, &b);
    mu_assert_int_eq(100, a);
    mu_assert_int_eq(10, b);
}
MU_TEST(test_2){
    int a = -12, b = -13;
    swap(&a, &b);
    mu_assert_int_eq(-13, a);
    mu_assert_int_eq(-12, b);
}
MU_TEST(test_3){
    int a = 0, b = -8;
    swap(&a, &b);
    mu_assert_int_eq(-8, a);
    mu_assert_int_eq(0, b);
}
MU_TEST(test_4){
    int a = -1, b = 1;
    swap(&a, &b);
    mu_assert_int_eq(1, a);
    mu_assert_int_eq(-1, b);
}
MU_TEST(test_5){
    int a = 45, b = 45;
    swap(&a, &b);
    mu_assert_int_eq(45, a);
    mu_assert_int_eq(45, b);
}
MU_TEST(test_6){
    int arr[]={34, 56};
    swap(&arr[0], &arr[1]);
    mu_assert_int_eq(56, arr[0]);
    mu_assert_int_eq(34, arr[1]);
}
MU_TEST(test_7){
    int arr[2]={};
    swap(&arr[0], &arr[1]);
    mu_assert_int_eq(0, arr[0]);
    mu_assert_int_eq(0, arr[1]);
}
MU_TEST(test_8){
    int arr[3];
    arr[0]=23;
    swap(&arr[0], &arr[2]);
    mu_assert_int_eq(0, arr[0]);
    mu_assert_int_eq(23, arr[2]);
}
MU_TEST(test_9){
    int a = FIRST, b = SECOND;
    swap(&a, &b);
    mu_assert_int_eq(SECOND, a);
    mu_assert_int_eq(FIRST, b);
}
MU_TEST(test_10){
    int a = FIRST;
    swap(&a, &a);
    mu_assert_int_eq(FIRST, a);
}
MU_TEST_SUITE(my_test_suite){
    MU_RUN_TEST(test_1);
    MU_RUN_TEST(test_2);
    MU_RUN_TEST(test_3);
    MU_RUN_TEST(test_4);
    MU_RUN_TEST(test_5);
    MU_RUN_TEST(test_6);
    MU_RUN_TEST(test_7);
    MU_RUN_TEST(test_8);
    MU_RUN_TEST(test_9);
    MU_RUN_TEST(test_10);
}
int main(){
    MU_RUN_SUITE(my_test_suite);
    MU_REPORT();
    return 0;
}