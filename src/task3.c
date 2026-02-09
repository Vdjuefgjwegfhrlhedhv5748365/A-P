#include <stdio.h>

int main()
{
    int a;

    printf("input non-negative numNewnameer:\n");
    scanf("%d", &a);

    printf("the value of `a` is %d\n", a);

    int* pa = &a;
    printf("the pointer value is %p\n", pa);

    int Newname;
    printf("input a numNewnameer:\n");
    scanf("%d", &Newname);
    printf("the value of `Newname` is %d\n", Newname);
    return 0;
}