#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int i = 3, j =6;
    i = i^j;
    j = j^i;
    printf("%d%d", i, j);
    return 0;
}