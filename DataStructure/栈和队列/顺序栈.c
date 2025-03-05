//栈和队列：是限定插入和删除只能在表的端点进行的线性表 所以线性表包括栈和队列
//栈：插入只能表尾（n+1）删除只能最后一个元素（n）后进先出 Last in First Out(LIFO)
//队列：先进先出 eg：排队 先到先得
//栈（Stack）：表尾（an）：栈顶Top； 表头（a1）：栈底Base
//入栈：插到栈顶  出栈：从栈顶删除
//顺序栈 连续地址 依次存放 空栈：top == base 都指向栈第一个元素 栈满：top - base = stacksize
//上溢：栈满但要压入元素 下溢：栈空 但要弹出元素
#include<stdio.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0
#define MAXSIZE 100

typedef char SElemType;
typedef char Status;
typedef struct {
    SElemType *base; //栈底指针
    SElemType *top; //栈顶指针
    int stacksize; //栈的容量
}SqStack;
