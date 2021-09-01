//
// Created by Yee on 2021/8/31.
//

#include <stdio.h>
#include <stdlib.h>

// 带头结点的单链表

// 1。按位序插入 指定结点的前插操作

// 单链表查找某结点的前一个结点比较麻烦 需要遍历
// 思路：单链表的结点只知道它的后一个结点，可以让数据域移位实现
// 即申请一个新的结点，把指定结点的数据放在新结点，再把要加入的新元素（数据）放在原来的指定结点，两结点相连即可实现

// 2。按位序删除

// 3。按指定结点删除

// 4。按位查找

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

// 4。按位查找 o(n)
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

// 后插操作  在p结点之后插入元素e
bool insertNextNode (LNode *p, int e) {
    if (p == NULL) { // i值不合法 未找到i-1个结点
        return false;
    }
    LNode *insertNode = (LNode *) malloc(sizeof(LNode)); // 为插入结点开辟内存空间  *insertNode为指向新结点的指针
    insertNode->data = e; // 新插入结点数据域中 存储 要添加的数据
    insertNode->next = p->next; // i-1结点处 指向下一个结点的指针 赋给 插入结点的指针域中
    p->next = insertNode; // i-1结点指针域指针 指向 新插入结点地址 即 p 链接上 insertNode
    return true; // 插入完成
}

// 在第i个位置插入元素e （带头结点）
// L头指针 i第i个位置（1起始） e插入元素
// 最好情况： 插入到头结点后 o（1）
// 最坏情况： 插入到表尾 o（n）
// 平均情况： o（n）
bool insertList (LinkList &L, int i, int e) {
    if (i < 1) {
        return false;
    }
    LNode *p = getElem(L, i-1); // 使用封装的按位查找函数

//    p = L;  //  头指针赋给p
//    int index = 0; // 当前为第几个结点 0位置代表头结点
//    while (p != NULL && index < i - 1) {  // 循环找到第 i-1 个结点 即要插入位置的前一个结点 用p记录下其指针域的指针->
//        p = p->next;
//        index++;
//    }
    // 调用后插操作代码 跟之前的插入相同
    return insertNextNode(p, e);
}

// 前插操作 在p结点之前插入结点s  时间复杂度o（1）
bool insertBeforeNode (LNode *p, LNode *s) {
    if (p == NULL || s == NULL)
        return false;
    s->next = p->next;
    p->next = s; // p的next指针指向新插入结点s
    // 交换这两结点的数据
    int temp = p->data;
    p->data = s->data;
    s->data = temp;
    return true;
}

// 2。按位序删除结点
bool deleteList (LinkList &L, int i, int &e) {
    if (i < 1) {
        return false;
    }
    LNode *p = getElem(L, i-1); // 使用封装的按位查找函数

//    p = L;  //  头指针赋给p
//    int index = 0; // 当前为第几个结点 0位置代表头结点
//    while (p != NULL && index < i - 1) {  // 循环找到第 i-1 个结点 即要插入位置的前一个结点 用p记录下其指针域的指针->
//        p = p->next;
//        index++;
//    }
    if (p == NULL)
        return false;
    if (p->next == NULL) // i-1 处结点无后续结点
        return false;
    LNode *q = p->next;
    e = q->data;
    p->next = q->next;
    free(q); // 释放结点的存储空间
    return true;
}

// 3。删除指定结点 o(1)
// 思路： 删除实际上我们要删除的是数据 存放数据的容器（地址）改变是允许的
// bug：删除最后一个结点时 p->next 为 NULL 该处为空指针，只能采用遍历查找p的前驱进行删除 o（n）
bool deleteNode (LNode *p) {
    if (p == NULL) {
        return false;
    }
    LNode *q = p->next;
    p->data = p->next->data; // bug： 删除最后一个结点时 p->next 为 NULL 该处为空指针
    p->next = q->next; // 未赋值前 q->next 是等于  p->next->next
    free(q);
    return true;
}

// 单链表的局限性： 无法逆向检索 不方便去找前驱结点 -> 用双链表可以解决这个局限性

int main () {
    LinkList L;
    initList(L);
    int deleteElem = NULL;
    printf("插入成功? %d\n", insertList(L, 1, 321)); // 成功
    printf("查找第1个结点 %d\n", getElem(L, 1)->data);
    deleteList(L, 1, deleteElem);
    printf("删除第1个结点 %d\n", deleteElem);
    return 0;
}