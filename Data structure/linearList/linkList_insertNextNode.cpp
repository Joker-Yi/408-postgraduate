//
// Created by Yee on 2021/8/26.
//

#include <stdio.h>
#include <stdlib.h>

// 带头结点的单链表 按位序插入 指定结点的后插操作

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

// 在第i个位置插入元素e （带头结点）
// L头指针 i第i个位置（1起始） e插入元素
// 最好情况： 插入到头结点后 o（1）
// 最坏情况： 插入到表尾 o（n）
// 平均情况： o（n）
bool insertList (LinkList &L, int i, int e) {
    if (i < 1) {
        return false;
    }
    LNode *p; // 定义一个指针p 用于存储当前结点地址
    p = L;  //  头指针赋给p
    int index = 0; // 当前为第几个结点 0位置代表头结点
    while (p != NULL && index < i - 1) {  // 循环找到第 i-1 个结点 即要插入位置的前一个结点 用p记录下其指针域的指针->
        p = p->next;
        index++;
    }
    // 调用后插操作代码 跟之前的插入相同
    return insertNextNode(p, e);
}

// 后插操作  在p结点之后插入e元素
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

int main () {
    LinkList L;
    initList(L);
    printf("插入成功? %d\n", insertList(L, 1, 321)); // 成功
    printf("插入成功? %d\n", insertList(L, 5, 321)); // 失败 找不到前一个结点 i输入非法
    return 0;
}