#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 10
#define OK 1
#define ERROR 0

typedef int Status;
typedef char ElemType;
typedef struct Lnode{
    ElemType data;
    struct Lnode *next;
}Lnode, *LinkList;


//初始化
Status InitList(LinkList *L) {
    *L = (LinkList)malloc(sizeof(Lnode)); // 分配内存空间
    if (!(*L)) return ERROR;
    (*L)->next = NULL; // 将头节点的指针域置空
    return OK;
}

//打印
void PrintList(LinkList L) {
    Lnode *p = L->next;
    while (p) {
        printf("%c -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

//例1:插入26字母
void build(LinkList *L){
    int i;
    Lnode *p;
    p = *L;
    for(i = 0; i < 26; i++){
        p -> data = i + 'a' - 1;
        p -> next = (LinkList)malloc(sizeof(Lnode));
        p = p -> next;
    }
    //此时i等于26 
    p -> data = i + 'a' - 1;//插入z
    p -> next = NULL;//尾结点指针域置空
}


int main(void){

    LinkList L;
    InitList(&L);

    build(&L);

    PrintList(L);

}
