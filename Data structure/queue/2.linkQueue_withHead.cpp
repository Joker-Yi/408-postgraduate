//
// Created by Yee on 2021/9/12.
//

// 链队列 （带头结点）

#include <stdlib.h>

// 声明一个结构体 代表链队列里的结点
typedef struct LinkNode {
    int data;
    struct LinkNode *next;
} LinkNode;

// 声明一个结构体 代表该链队列(头结点)
typedef struct {
    LinkNode *front, *rear;
} LinkQueue;

// 初始化链队列
void initQueue (LinkQueue &Q) {
    Q.front = Q.rear = (LinkNode *) malloc(sizeof(LinkNode));
    Q.front->next = NULL;
}

// 判断是否为空
bool isEmpty (LinkQueue Q) {
    return Q.front == Q.rear;
    // 也可
//    return Q.front->next == NULL;
}

// 入队操作
void enQueue (LinkQueue &Q, int x) {
    LinkNode *newNode = (LinkNode *) malloc(sizeof (LinkNode));
    newNode->data = x;
    newNode->next = NULL;
    Q.rear->next = newNode;
    Q.rear = newNode;
}

// 出队操作
bool deQueue (LinkQueue &Q, int &x) {
    if (Q.front == Q.rear) {
        return false; // 空队不允许出队
    }
    LinkNode *p = Q.front->next;
    x = p->data;
    Q.front->next = p->next; // 修改头结点的next指针指向
    if (Q.rear == p) { // 队中最后一元素出栈
        Q.rear = Q.front; // 重制为空队
    }
    free(p);
    return true;
}

int main () {
    LinkQueue Q;
    initQueue(Q);
    return 0;
}