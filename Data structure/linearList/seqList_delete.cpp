//
// Created by Yee on 2021/8/24.
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
// 时间复杂度 问题规模：n=L.length
// 最好情况： 新元素插入到表尾 不需要移动元素；或者表的当前长度为0 T=o（1）
// 最坏情况： 新元素插入到表头 需移动原有n个元素 循环n次 T=o（n）
// 平均情况： 新元素插入到每个位置的概率相同 为p=1 / (n+1) i=1循环n次 i=2循环n-1次 .....
// 平均循环次数 = n(n+1)/2 * (1 / n+1) T=o (n)
bool insertList (SeqList &L, int i, int e) {
    if (i < 1 || i > L.length + 1) { // 判断 i 范围的有效性
        printf("插入失败，1<=i<=L.length+1\n");
        return false;
    }
    if (L.length >= MAXSIZE) { // 判断是否空间已满
        printf("插入失败，当前存储空间已满\n");
        return false;
    }
    for (int j = L.length; j >= i; j--) { // 将第i个元素及其后元素后移一位（注：从表尾元素开始移动！！！）
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e; // 元素e放入第i位
    L.length++; // 长度加1
    return true;
}

// 顺序表的删除操作 i:删除元素的位序  e：被删除的元素 带回被调用的地方 可以让使用者知道被删除的元素内容
// 时间复杂度 问题规模：n=L.length
// 最好情况： 删除表尾元素 不需要移动其他元素 T=o（1）
// 最坏情况： 删除表头元素 需移动原有n-1个元素 循环n-1次 T=o（n）
// 平均情况： 删除任何元素的概率相同 为p=1/n i=1循环n-1次 i=2循环n-2次 ..... i = n循环0次
// 平均循环次数 = n(n-1)/2 * (1 / n) T=o (n)
bool deleteList (SeqList &L, int i, int &e) {
    if (i < 1 || i > L.length + 1) { // 判断 i 范围的有效性
        printf("删除失败，1<=i<=L.length+1\n");
        return false;
    }
    if (L.length == 0) {
        printf("删除失败，表为空，无元素可以删除\n");
        return false;
    }
    e = L.data[i-1]; // 存下被删除的元素
    for (int j = i; j < L.length; ++j) { // 把i位之后的元素往前移一位
        L.data[j-1] = L.data[j];
    }
    L.length--;
    return true;
}

int main () {
    SeqList L;
    initList(L);
    int e = NULL; // 接收被删除的元素
    deleteList(L, 1, e);
    insertList(L, 1, 1);
    insertList(L, 1, 2);
    insertList(L, 1, 3);

    if (deleteList(L, 1, e)) {
        printf("删除成功，删除元素值为%d\n", e);
    }

    for (int i = 0; i < L.length; ++i) {
        printf("data[%d] = %d\n", i, L.data[i]);
    };
    return 0;
}
