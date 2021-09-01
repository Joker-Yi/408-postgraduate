//
// Created by Yee on 2021/8/26.
//

#include <stdio.h>
#include <stdlib.h>

// 带头结点的单链表 头插法创建单链表

typedef struct LNode {  // 定义单链表结点类型
    int data;           // 结点的数据域
    struct LNode *next; // 结点的指针域 指向下一个结点的指针
} LNode, *LinkList;   // 给struck LNode数据类型 设置别名LNode(结点), *LinkList（指向单链表的指针）

// 尾插法建立单链表 o（n）
// 都是对尾结点进行后插操作  根据输入的顺序插入
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

// 头插法建立单链表 o(n)
// 对头结点进行后插操作 根据输入顺序建立的逆序单链表
// 可用于逆置单链表！！！
LinkList initListByHeadInsert (LinkList &L) {
    int x;
    LNode *s;
    L = (LinkList) malloc(sizeof(LNode));
    L->next = NULL; // 初始为空链表 因为不知该指针指向的地址会不会存在脏数据
    printf("请输入插入元素，输入999退出插入操作\n");
    scanf("%d", &x);
    while (x != 999) { // 特定的一个数用于终止循环
        s = (LNode *) malloc(sizeof(LNode)); // 为新结点开辟空间
        s->data = x;
        s->next = L->next; //链接新结点
        L->next = s; // 表尾指针指向新结点
        printf("插入成功\n");
        printf("请输入插入元素，输入999退出插入操作\n");
        scanf("%d", &x);
    }
    printf("已退出，单链表建立完成");
    return L;
}

int main () {
    LinkList L;
    initListByHeadInsert(L);
    return 0;
}