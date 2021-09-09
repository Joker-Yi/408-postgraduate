//
// Created by Yee on 2021/9/9.
//

// 共享栈 栈满条件 top0 + 1 = top1

#include <stdio.h>

#define MAXSIZE 10
typedef struct {
    int data[MAXSIZE];
    int top0;
    int top1;
} ShaStack;

// 初始化共享栈
ShaStack initStack (ShaStack &S) {
    S.top0 = -1;
    S.top1 = MAXSIZE;
}

// 判断栈满
bool isFullStack (ShaStack S) {
    if (S.top0 + 1 == S.top1)
        return true;
    else
        return false;
}

int main () {
    ShaStack S;
    initStack(S);
    printf("共享栈是否满：%d\n", isFullStack(S));
    return 0;
}
