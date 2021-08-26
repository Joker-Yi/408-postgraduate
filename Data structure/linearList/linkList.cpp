//
// Created by Yee on 2021/8/26.
//

#include <stdio.h>
#include <stdlib.h>

// 带头结点的单链表

typedef struct LNode {  // 定义单链表结点类型
    int data;           // 结点的数据域
    struct LNode *next; // 结点的指针域 指向下一个结点的指针
} LNode, *LinkList;   // 给struck LNode数据类型 设置别名LNode(结点), *LinkList（指向单链表的指针）

// 初始化单链表 （带头结点）
bool initList (LinkList &L) {
    L = (LNode *) malloc(sizeof(LNode)); // 给头结点分配内存 头指针L指向该地址
    if (L == NULL) {
        return false;   // 分配失败 可能内存不足
    }
    L->next = NULL; // 头结点指针置为NULL 暂无后续结点
    // 头结点不储存数据 data
    return true;
}

// 判断单链表是否为空
bool empty (LinkList L) {
    return (L->next == NULL); // 头结点指针域 为NULL则为空表
}

void test () {
    LinkList L; //声明一个指向单链表的指针
    initList(L); // 初始化一个空表
    printf("单链表是否为空：%d\n", empty(L));
}

int main () {
    test();
    return 0;
}