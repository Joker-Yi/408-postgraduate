//
// Created by Yee on 2021/8/22.
//

// 顺序表实现 动态分配
// 动态分配存储空间 当超出初始容量 会重新开辟一片连续空间
// 将原数据 复制到开辟后的新空间 时间开销大

#include <stdio.h>
#include <cstdlib>
//#include <stdlib.h>

// 定义默认初始容量
#define INITSIZE 10
typedef struct {
    int *data; // 指示动态分配数组的指针
    int length; // 当前长度
    int maxSize; // 最大容量
} SeqList;

// 初始化顺序表
void initList (SeqList &L) {
    // 用malloc函数申请一片连续的储存空间
    L.data = (int *) malloc(INITSIZE * sizeof (int));
    L.length = 0;
    L.maxSize = INITSIZE;
}

// 增加动态数组长度 len：增加的长度
void increaseSize (SeqList &L, int len) {
    int *p = L.data;
    L.data = (int *) malloc((L.maxSize + len) * sizeof (int)); // 重新开辟一片maxSize + len长度的新空间
    for (int i = 0; i < L.length; ++i) {
        L.data[i] = p[i]; // 将原数据复制到新区域
    }
    // realloc(参数1 包含地址的指针，参数2 要新分配的内存字节数)
//    L.data = (int *) realloc(p, (L.maxSize + len) * sizeof (int));  // 作用同上，建议使用malloc更能理解背后的原理
    L.maxSize += len; // 最大长度增加len
    free(p); // 释放原来的内存空间
}

int main () {
    SeqList L; // 声明一个顺序表
    initList(L);
    // 往顺序表中插入元素。。。
    increaseSize(L, 10);
    for (int i = 0; i < L.maxSize; ++i) {
        printf("data[%d] = %d\n", i, L.data[i]);
    };
    printf("dataSize = %d\n", sizeof (L.data)); // 指针（即地址）所占大小（地址长度） 8字节（跟系统寻址能力有关 64位：8字节 32位：4字节）
    return 0;
}

