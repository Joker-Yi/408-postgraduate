//
// Created by Yee on 2021/9/8.
//

// 顺序栈
// 缺点；栈的大小不可改变，如果一开始就给予大片的空间会导致空间的浪费 -》可使用共享栈，两个栈共享一片连续的存储空间

#include <stdio.h>

#define MAXSIZE 10 // 定义栈中元素的最大个数
typedef struct {
    int data[MAXSIZE]; // 静态数组存放栈中元素，会由系统自动回收，malloc分配的空间需要自主用free回收
    int top; // 栈顶指针
} SqStack;

// 初始化栈
void initStack (SqStack &S) {
    S.top = -1; // 初始化栈顶元素
}

// 判断栈空
bool stackEmpty (SqStack S) {
    if(S.top == -1) // 栈顶指针为-1则栈空
        return true;
    else
        return false;
}

// 入栈操作
bool push (SqStack &S, int x) {
    if(S.top == MAXSIZE -1) {
        return false; // 栈满
    }
    S.top++; // 指针+1，指向后一位
    S.data[S.top] = x; // 新元素入栈
    // 以上两行代码等价于,注意 s.top先+1
//    S.data[++S.top] = x;
    return true;
}

// 出栈操作
bool pop (SqStack &S, int &x) {
    if(S.top == -1) {
        return false; // 栈空
    }
    x = S.data[S.top]; // 栈顶元素先出栈； 只是逻辑上被删除了，内存中依然存在数据
    S.top = S.top - 1; // 栈顶指针-1
    // 以上两句等价于
//    x = S.data[S.top--];
    return true;
}

// 读取栈顶元素
bool getTop (SqStack S, int &x) {
    if(S.top == -1) {
        return false; // 栈空
    }
    x = S.data[S.top];
    return true;
}

int main () {
    SqStack S; // 声明一个顺序栈（分配空间）
    initStack(S);
    printf("栈是否为空：%d\n", stackEmpty(S));
    push(S, 0); // 入栈 元素为0
    push(S, 12); // 入栈 元素为12
    int delElem = NULL;
    int elem = NULL;
    getTop(S, elem);
    printf("栈顶元素为：%d\n", elem);
    pop(S, delElem); // 出栈
    printf("该次出栈元素为：%d\n", delElem);
    return 0;
}