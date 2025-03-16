//链栈是受限的单链表 只能在链表头部进行操作
//注意：链栈指针方向相反 栈指针域指向前趋元素地址 
//头指针指向栈顶（an） 栈底是a1
//没有头节点 空栈：头指针指空
//插入和删除仅在栈顶处执行

#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef char SElemType;
typedef char Status;
typedef struct StackNode{
    SElemType data;
    struct StackNode *next;
}StackNode, *LinkStack;

LinkStack S;

//1. 链栈的初始化
Status InitStack(LinkStack *S){
    S = NULL;
    return OK;
}

//2. 判断空
Status IsEmpty(LinkStack *L){
    if(S == NULL) return TRUE;
    else return FALSE;
}

//3. 入栈:只能放栈顶（最后一个元素）
Status Push(LinkStack *S, SElemType e){
    StackNode *p; //生成新节点p
    p->data = e; //将新节点数据域设置为e
    p->next = S;//将新节点插入栈顶
    S = p; //头指针上移 指向栈顶
    return OK;
}

//4. 出栈:只能出栈顶（最后一个元素）
Status Pop(LinkStack *S, SElemType *e){
    if(S == NULL) return ERROR; //空栈
    LinkStack *p;
    e = S->data; //e存删除的值
    p = S; //p存删的结点
    S = S->next; //s头指针 指向新的栈顶
    free(p);//释放
    return OK;
} 

//5. 取栈顶元素
SElemType GetTop(LinkStack S){
    if(S != NULL)
        return S->data; //头指针的值
}

int main(void){

}