//
// Created by Yee on 2021/8/22.
//

// 顺序表实现 静态分配
// 缺点：确定了数组的大小和空间 一旦占满就会导致溢出
// 优点：随机访问

#include <stdio.h>

// 定义最大容量
#define MAXSIZE 10
typedef struct {
    int data[MAXSIZE];
    int length; // 当前数组长度
} SeqList;

// 初始化顺序表
void initList (SeqList &L) {
    L.length = 0; //初始化当前数组长度
}

int main () {
    SeqList L;
    initList(L);
    for (int i = 0; i < MAXSIZE; ++i) { // 不推荐这么使用 应使用基本运算实现访问数组元素 即定义一个getElem函数来实现
        printf("data[%d] = %d\n", i, L.data[i]);
    };
    return 0;
}