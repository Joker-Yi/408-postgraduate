//
// Created by Yee on 2021/8/26.
//

#include <stdio.h>
#include <stdlib.h>

// 带头结点的单链表 尾插法创建单链表

typedef struct LNode {  // 定义单链表结点类型
    int data;           // 结点的数据域
    struct LNode *next; // 结点的指针域 指向下一个结点的指针
} LNode, *LinkList;   // 给struck LNode数据类型 设置别名LNode(结点), *LinkList（指向单链表的指针）

// 尾插法建立单链表 o（n）
// 都是对尾结点进行后插操作
LinkList initListByTailInsert (LinkList &L) {
    int x; // 接收用户输入的值
    L = (LinkList) malloc(sizeof(LNode)); // 建立头结点 初始化空表
    LNode *s, *tail = L; // tail表尾指针 始终指向最后一个结点
    printf("请输入插入元素，输入999退出插入操作\n");
    scanf("%d", &x);
    while (x != 999) { // 特定的一个数用于终止循环
        s = (LNode *) malloc(sizeof(LNode)); // 为新结点开辟空间
        s->data = x;
        tail->next = s; //链接新结点
        tail = s; // 表尾指针指向新结点
        printf("插入成功\n");
        printf("请输入插入元素，输入999退出插入操作\n");
        scanf("%d", &x);
    }
    tail->next = NULL; // 创建完成 尾结点指针指向null
    printf("已退出，单链表建立完成");
    return L;
}

int main () {
    LinkList L;
    initListByTailInsert(L);
    return 0;
}