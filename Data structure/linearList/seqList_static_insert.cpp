//
// Created by Yee on 2021/8/23.
//

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

// 顺序表的插入 i:插入的位置（位序） 1起始  e: 插入的元素
bool insertList (SeqList &L, int i, int e) {
    if (i < 1 || i > L.length + 1) { // 判断 i 范围的有效性
        printf("插入失败，1<=i<=L.length+1\n");
        return false;
    }
    if (L.length >= MAXSIZE) { // 判断是否空间已满
        printf("插入失败，当前存储空间已满\n");
        return false;
    }
    for (int j = L.length; j >= i; j--) { // 将第i个元素及其后元素后移一位
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e; // 元素e放入第i位
    L.length++; // 长度加1
    return true;
}
// 时间复杂度 问题规模：n=L.length
// 最好情况： 新元素插入到表尾 不需要移动元素；或者表的当前长度为0 T=o（1）
// 最坏情况： 新元素插入到表头 需移动原有n个元素 循环n次 T=o（n）
// 平均情况： 新元素插入到每个位置的概率相同 为p=1 / (n+1) i=1循环n次 i=2循环n-1次 .....
// 平均循环次数 = n(n+1)/2 * (1 / n+1) T=o (n)

int main () {
    SeqList L;
    initList(L);
    insertList(L, 1, 1);
    insertList(L, 1, 2);
    insertList(L, 1, 3);
    insertList(L, 7, 3); // 失败操作
    insertList(L, 1, 4); // 不断的插入元素 旧元素往后推
    for (int i = 0; i < L.length; ++i) {
        printf("data[%d] = %d\n", i, L.data[i]);
    };
    return 0;
}