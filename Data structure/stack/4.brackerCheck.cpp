//
// Created by Yee on 2021/9/13.
//

// 栈的应用之 括号匹配   {[]}()[
// 遵循栈先后进先出的规则，先入栈的括号先出栈进行匹配，遇到左括号 入栈，遇到右括号 出栈与右括号比对， 空栈和不匹配则 匹配失败

#include <stdio.h>
// 这里采用顺序栈的方式 写法上更加简便 也可使用链栈，使得空间更大
#define MAXSIZE 10  // 也可使用链栈 使得空间更大
typedef struct {
    char data[MAXSIZE]; // 静态数组存放字符括号元素
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
bool push (SqStack &S, char x) {
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
bool pop (SqStack &S, char &x) {
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
bool getTop (SqStack S, char &x) {
    if(S.top == -1) {
        return false; // 栈空
    }
    x = S.data[S.top];
    return true;
}

// 括号匹配
bool bracketCheck (char str[], int length) {
    SqStack S;
    initStack(S);
    for (int i = 0; i < length; ++i) { // 扫描整个字符数组
        if (str[i] == '{' || str[i] == '[' || str[i] == '(' ) { // 左括号入栈
            push(S, str[i]);
        } else { // 扫描到右括号
            if (stackEmpty(S)) {
                return false;
            }
            char topElem;
            pop(S, topElem);
            // 进行左右括号匹配
            if (str[i] == ')' && topElem != '(')
                return false;
            if (str[i] == ']' && topElem != '[')
                return false;
            if (str[i] == '}' && topElem != '{')
                return false;
        }
    }
    return stackEmpty(S); // 全部出栈完毕，全部括号匹配成功
}

int main () {
    char a[] = "[]{}{}]";
    char b[] = "[[]{}{}()]";
    printf("匹配是否成功：%d\n",bracketCheck(a, 7));
    printf("匹配是否成功：%d\n",bracketCheck(b, 10));
}