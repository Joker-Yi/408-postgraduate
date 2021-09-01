//
// Created by Yee on 2021/8/26.
//

#include <stdio.h>
#include <stdlib.h>

// 带头结点的单链表 利用头插法 逆序输出一个链表

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
    printf("已退出，单链表建立完成\n");
    return L;
}

// 按位查找 o(n)
// 可适用于按位删除/插入操作
LNode * getElem(LinkList L, int i) {
    if (i < 0)
        return NULL;
    LNode *p = L; // 从头结点开始查询
    int index = 0; // 当前位序
    while (p != NULL && index < i) {
        p = p->next;
        index++;
    }
    return p; // 返回查找的结点
}

// 获取单链表长度
int getLength (LinkList L) {
    int len = 0;
    LNode *p = L;
    while (p->next != NULL) {
        p = p->next;
        len++;
    }
    return len;
}

// 利用头插法 转置 单链表
LinkList reverseList (LinkList &L) {
    LNode *p = L->next; // L 链表的遍历指针 从位序为1的结点开始
    LNode *newNode;
    LinkList newList = (LinkList) malloc(sizeof(LNode));
    newList->next = NULL;
    while (p != NULL) {
        newNode = (LNode *) malloc(sizeof(LNode));
        newNode->data = p->data; // 把 L链表的数据传给新结点
        newNode->next = newList->next;
        newList->next = newNode; // 头结点与新结点链接
        p = p->next;
    }
    return newList;
}

int main () {
    LinkList L;
    initListByHeadInsert(L);
    LinkList reverseL = reverseList(L); // 转置
    for (int i = 1; i < getLength(reverseL) + 1; ++i) { // 打印出每个结点的数据 此处时间复杂度仍为o（n）
        printf("第%d个结点的元素为%d\n", i, getElem(reverseL, i)->data);
    }
    return 0;
}