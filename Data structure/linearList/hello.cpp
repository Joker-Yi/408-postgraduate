//
// Created by Yee on 2021/8/23.
//

#include <stdio.h>

int main () {
    int a = 10;
    int *p = &a;
    *p = 100;
    a++;
    int b = *p;
    printf("%d - %d - %d",a,b,*p);
}