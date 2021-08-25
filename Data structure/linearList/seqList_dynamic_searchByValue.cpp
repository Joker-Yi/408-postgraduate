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
    int *p = L.data; // 接收数组首元素地址
    L.data = (int *) malloc((L.maxSize + len) * sizeof (int)); // 重新开辟一片maxSize + len长度的新空间
    for (int i = 0; i < L.length; ++i) {
        L.data[i] = p[i]; // 将原数据复制到新区域
    }
    // realloc(参数1 包含地址的指针，参数2 要新分配的内存字节数)
//    L.data = (int *) realloc(p, (L.maxSize + len) * sizeof (int));  // 作用同上，建议使用malloc更能理解背后的原理
    L.maxSize += len; // 最大长度增加len
    free(p); // 释放原来的内存空间
}

// 顺序表的按位查找 i:查找的位序
// 时间复杂度：o（1）  （顺序表随机存取的特性)
int getElem (SeqList L, int i) {
//    if (i < 1 || i > L.length) { // 判断 i 范围的有效性
//        printf("查找失败，1<=i<=L.length\n");
//        return -1;
//    }
    return L.data[i-1]; // 与访问普通数组的方法一致 a[0] 存放的是首元素的地址

    // 下为另一种写法，是从地址的运算角度出发
    // L.data + i-1  假设首元素地址为1000，指针移一位为sizeof（int）个字节
    // 首地址 + （i-1） * 4B（int数据类型的大小，声明了指针为int，sizeof（int）= 4），刚好为第i个元素的地址 即地址1000后开始的（i-1）*4b
//    return *(L.data + i -1);
}


// 顺序表的按值查找 e：需要查找的值
// 时间复杂度 ：n = L.length
// 最好： 目标元素出现在表头 o（1）
// 最坏： 目标元素在表尾 o（n）
// 平均： 循环次数=n*（n+1）/2 * 1/n o（n）
int locateElem(SeqList L, int e) {
    for (int i = 0; i < L.length; ++i) {
        if (L.data[i] == e) { // int float double char 都可使用 == 比较；注：但struck 结构类型不可如此比较，需比较其各个分量都相等
            return i + 1; // 值相等时 返回它的位序
        }
    }
    return 0;
}

int main () {
    SeqList L; // 声明一个顺序表
    initList(L);

    L.data[0] = 1;
    L.data[1] = 2;
    L.data[2] = 23;
    L.length = 3; // 改变下数组长度 方便按值查找 （建议使用插入或添加操作）

    for (int i = 0; i < L.maxSize; ++i) {
        printf("data[%d] = %d\n", i, L.data[i]);
    };

    printf("查找第2个元素为%d\n", getElem(L, 2));
    printf("查找值为23的元素，它的位序为%d\n", locateElem(L, 23));
    return 0;
}

