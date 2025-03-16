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
#define TRUE 1
#define FALSE 0
#define OVERFLOW -1
#define MAXSIZE 100

typedef char SElemType;
typedef char Status;
typedef struct {
    SElemType *base; //栈底指针
    SElemType *top; //栈顶指针
    int stacksize; //栈的容量
}SqStack;

//1.顺序栈的初始化
Status InitStack(SqStack *S){//构造一个空栈
    S->base = (SElemType*)malloc(MAXSIZE*sizeof(SElemType));
    if(!S->base) return OVERFLOW;//存储分配失败
    S->top = S->base;//栈顶指针等于栈底指针 置空
    S->stacksize = MAXSIZE;
    return OK;
}

//2. 判断顺序栈是否为空 top=base
Status IsEmpty(SqStack *S){
    if(S->top == S->base)
        return TRUE;
    else
        return FALSE;
}

//3. 求长度
Status StackLength(SqStack *S){
    return S->top - S->base;
}

//4. 清空:top = base
Status ClearStack(SqStack *S){
    if(S->base)//若栈存在
         S->top = S->base;
    return OK;
}

//5. 销毁 释放这段空间
Status DestroyStack(SqStack *S){
    if(S->base){//若栈存在
        free(S->base);
        S->stacksize = 0;
        S->base = S->top = NULL;
    }
    return OK;
}

//6.!! 顺序栈的入栈 元素存到栈顶 top+1
Status Push(SqStack *S, SElemType e){
    if(S->top - S->base == S->stacksize)//栈满溢出
        return ERROR;
    *S->top = e; //*运算 直接操作它所指的空间 
    S->top++;
    return OK;
}

//7.！！出栈： 判断栈空  top下移到栈顶元素e  栈顶指针减一
Status Pop(SqStack *S, SElemType *e){
    if(S->top == S->base) return ERROR; //栈空 StackEmpty(S):栈空判断函数
    --S->top;//指针下移
    *e = *(S->top);//赋值给e 返回
    return OK;
}

// 8. 栈的打印函数（从栈顶到栈底）
void PrintStack(SqStack *S) {
    if (IsEmpty(S)) {
        printf("栈空打印失败\n");
        return;
    }
    printf("栈(top to bottom): ");
    SElemType *p = S->top;
    while (p != S->base) {
        p--; // 先下移
        printf("%c ", *p);
    }
    printf("\n");
}

int main(void){

    SElemType e;
    SqStack S;
    // 初始化栈
    InitStack(&S);

    // 测试栈是否为空
    printf("栈是否为空? %s\n", IsEmpty(&S) ? "是" : "否");

    // 入栈测试
    Push(&S, 'A');
    Push(&S, 'B');
    Push(&S, 'C');
    Push(&S, 'D');

    PrintStack(&S);

    // 输出栈长度
    printf("栈长度是: %d\n", StackLength(&S));

    // 出栈测试
    while (!IsEmpty(&S)) {
        Pop(&S, &e);
        printf("已出栈: %c\n", e);
    }

    PrintStack(&S);
    
    // 再次测试栈是否为空
    printf("出栈后是否为空? %s\n", IsEmpty(&S) ? "是" : "否");

    // 清空栈
    ClearStack(&S);
    printf("已清空\n");

    // 销毁栈
    DestroyStack(&S);
    printf("已销毁\n");

    return 0;
}