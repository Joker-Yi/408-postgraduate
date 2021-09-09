//
// Created by Yee on 2021/9/9.
//

// 队列 同样也是操作受限的线性表
// 先进先出 FIFO 队尾插入 队头删除

// 顺序存储结构 的 队列
// 1。顺序队列： 存在假溢出的问题，入队中途执行出队操作会有假溢出的问题，出队留下的空间不能利用
// 2。循环队列：解决了假溢出的问题,但是会浪费一个存储单元
//    队满：(Q.rear+1)%MAXSIZE = Q.front
//    对空：Q.front = Q.rear
//    当前队列元素个数：(rear + )

//    解决循环队列会浪费一个存储单元的问题
//    方法1： 在结构体定义的时候 int size，出栈size--，入栈size++， size == MAXSIZE 队满， size == 0队空
//    方法2： 在结构体定义的时候 int tag,设置一个标志符，出栈成功后tag = 0，入栈成功后tag == 1，
//           front = rear && tag = 1 队满， front = rear && tag == 0 队满

#include <stdio.h>
#define MAXSIZE 10
typedef struct {
    int data[MAXSIZE]; // 使用静态数组存放队列元素
    int front,rear; // 声明队头指针和队尾指针
} SqQueue;

// 初始化队列
bool initSqQueue (SqQueue &Q) {
    Q.front = 0;
    Q.rear = 0;
}

// 判断队列是否为空
bool EmptyQueue (SqQueue Q) {
    return Q.front == Q.rear;
}

// 入队
bool enterQueue (SqQueue &Q, int e) {
    if((Q.rear + 1) % MAXSIZE == Q.front) {
        return false; // 队满报错
    }
    Q.data[Q.rear] = e; // 新元素插入队尾
    Q.rear = (Q.rear + 1) % MAXSIZE; // 实现循环队列  0 到 MAXSIZE-1, 空余一个存储单元用于区别队满队空状态
    return true;
}

// 出队
bool deQueue (SqQueue &Q, int &x) {
    if(Q.rear == Q.front) {
        return false; // 空栈不能操作
    }
    x = Q.data[Q.front]; // 队头指针指向的元素进行出队
    Q.front = (Q.front + 1) % MAXSIZE; // 队头指针后移 同时实现循环队列
    return true;
}

// 获取队头元素
bool getHead (SqQueue Q, int &x) {
    if(Q.rear == Q.front) {
        return false; // 空栈不能操作
    }
    x = Q.data[Q.front];
    return true;
}

int main () {
    return 0;
}