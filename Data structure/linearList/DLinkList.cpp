//
// Created by Yee on 2021/9/2.
//

#include <stdlib.h>

// 双链表 及其基本操作
// 不可随机存取， 按位查找 按值查找操作都只能遍历 o（n）
// 跟单链表只能后向遍历相比 双链表可进行前向遍历和后向遍历

typedef struct DNode {
    int data;
    struct DNode *prior, *next; // 定义一个前驱指针 和 后继指针
} DNode, *DLinkList;

// 初始化双链表
bool initDLinkList (DLinkList &L) {
    L = (DNode *) malloc(sizeof(DNode));
    if (L == NULL) {
        return false; // 内存不足 分配失败
    }
    L->prior = NULL;
    L->next = NULL;
    return true;
}

// 在结点后插入新结点 (后插操作)
// 前插操作：可利用双链表的结构轻松找到前驱结点，对前驱结点进行后插操作即可
bool insertNextDNode (DNode *p, DNode *s) {
    if (p == NULL || s == NULL) {
        return false;
    }
    s->next = p->next;
    if (p->next != NULL) {
        p->next->prior = s;
    }
    s->prior = p;
    p->next = s;
}

// 删除p结点的后继结点
bool deleteNextDNode (DNode *p) {
    if (p == NULL) {
        return false;
    }
    DNode *q = p->next;
    if (q == NULL)
        return false;
    p->next = q->next;
    if (q->next != NULL) { // 保证q结点不是最后一个结点
        q->next->prior = p; // 把q结点的后一个结点的前驱指针指向p
    }
    free(q);
    return true;
}

// 销毁单链表
// 思路：利用删除操作，对头结点后的结点进行循环删除，然后在把头结点释放
void destroyList (DLinkList &L) {
    while (L->next != NULL) {
        deleteNextDNode(L); // 删除头结点后一个元素
    }
    free(L); // 释放头结点的空间
    L = NULL; // 头指针重制为NULL
}

int main () {
    DLinkList L;
    initDLinkList(L);

    // 后向遍历
//    while (p != NULL) {
//        // 对结点p进行操作
//        p = p->next;
//    }
    // 前向遍历
//    while (p->prior != NULL) {
//        // 对结点p进行操作
//        p = p->prior;
//    }
}