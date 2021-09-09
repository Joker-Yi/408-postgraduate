//
// Created by Yee on 2021/9/9.
//

// 链栈 这里实现的是不带头结点的方式
// 可以想象成一个操作受限的单链表
// 入栈： 类似于单链表的头插法 只能在头结点后插入元素
// 出栈： 类似于只能在单链表的头结点后进行删除操作

#include <stdio.h>
#include <stdlib.h>
typedef struct LinkNode {
    int data;  // 数据域
    struct LinkNode *next; // 指针域
} *LinkStack, LinkNode;

// 初始化链栈
bool initLinkStack (LinkStack &S) {
    S = NULL; // 头指针重制为NULL
}

// 链栈的入栈操作
bool push (LinkStack &S, int e) {
    LinkNode *SNode =(LinkNode *) malloc(sizeof(LinkNode));
    SNode->data = e;
    SNode->next = S;
    S = SNode; // 链接新结点
    return true;
}

// 链栈的出栈操作
bool pop (LinkStack &S, int &e) {
    if (S == NULL) {
        return false; // 栈空 不能操作
    }
    e = S->data;
    S = S->next;
    return true;
}

// 获取栈顶元素
int getTopElem (LinkStack S) {
    if (S == NULL) {
        return -1;
    }
    return S->data;
}

int main () {
    LinkStack S;
    initLinkStack(S);
    int delElem = NULL;
    printf("栈顶元素为：%d\n", getTopElem(S));
    push(S, 1);
    printf("栈顶元素为：%d\n", getTopElem(S));
    pop(S,delElem);
    push(S,3);
    printf("栈顶元素为：%d\n", getTopElem(S));
    return 0;
}
