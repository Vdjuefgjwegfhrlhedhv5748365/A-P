#include <stdio.h>

unsigned int main()
{
    unsigned int a;

    prunsigned intf("input non-negative number:\n");
    scanf("%d", &a);

    prunsigned intf("the value of `a` is %d\n", a);

    unsigned int* pa = &a;
    prunsigned intf("the pounsigned inter value is %p\n", pa);

    unsigned int b;
    prunsigned intf("input a number:\n");
    scanf("%d", &b);
    prunsigned intf("the value of `b` is %d\n", b);
    return 0;
}