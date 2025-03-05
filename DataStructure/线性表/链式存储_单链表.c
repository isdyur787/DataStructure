// Created by 邵昱铭 on 2025/2/25.
//链式存储结构
//用任意的存储单元来存放数据元素 可能连续或不连续 存元素的同时还存了下一个元素的地址（结点=数据域➕指针域）
//单链表可以用头指针的名字来命名 单链表：结点只有一个指针域的链表 双链表：两个指针域（前地址➕后地址）
//循环链表：首尾相连
//空表：有头结点时：头指针为空表示空表；有头结点时：当头结点的指针域为空才表示空表

#include <stdio.h>
#include <stdlib.h>

// 预定义函数结果状态代码
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

// 预定义 Status 是函数的类型，其值是函数结果状态代码
typedef int Status;
typedef char ElemType;

typedef struct Lnode { // 声明结点的类型和指向结点的指针类型
    ElemType data;  // 结点的数据域
    struct Lnode *next; // 指针域
} Lnode, *LinkList; // LinkList 为指向结构体 Lnode 的指针类型

// 1. 单链表的初始化
Status InitList(LinkList *L) {
    *L = (LinkList)malloc(sizeof(Lnode)); // 分配内存空间
    if (!(*L)) return ERROR;
    (*L)->next = NULL; // 将头节点的指针域置空
    return OK;
}

// 2. 判断是否为空
Status IsEmpty(LinkList L) {
    return (L->next == NULL) ? TRUE : FALSE;
}

// 3. 单链表的销毁
Status DestroyList(LinkList *L) {
    Lnode *p;
    while (*L) {
        p = *L;
        *L = (*L)->next;
        free(p);
    }
    return OK;
}

// 4. 清空单链表
Status ClearList(LinkList L) {
    Lnode *p, *q;
    p = L->next;
    while (p) {
        q = p->next;
        free(p);
        p = q;
    }
    L->next = NULL;
    return OK;
}

// 5. 求链表的表长
int ListLength(LinkList L) {
    Lnode *p = L->next;
    int i = 0;
    while (p) {
        i++;
        p = p->next;
    }
    return i;
}

// 6. 取单链表中第 i 个元素
Status GetElem(LinkList L, int i, ElemType *e) {
    Lnode *p = L->next;
    int j = 1;
    while (p && j < i) {
        p = p->next;
        ++j;
    }
    if (!p || j > i) return ERROR;
    *e = p->data;
    return OK;
}

// 7. 按值查找
int FindElem(LinkList L, ElemType e) {
    Lnode *p = L->next;
    int j = 1;
    while (p && p->data != e) {
        p = p->next;
        j++;
    }
    return p ? j : ERROR;
}

// 8. 插入 在第i个结点前插入值为e的新节点
Status InsertElem(LinkList L, int i, ElemType e) {
    Lnode *p = L;
    int j = 0;
    while (p && j < i - 1) {
        p = p->next;
        ++j;
    }
    if (!p || j > i - 1) return ERROR;
    Lnode *s = (Lnode *)malloc(sizeof(Lnode));
    if (!s) return ERROR;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

// 9. 删除第 i 个结点
Status DeleteElem(LinkList L, int i, ElemType *e) {
    Lnode *p = L, *q;
    int j = 0;
    while (p->next && j < i - 1) {
        p = p->next;
        ++j;
    }
    if (!(p->next) || j > i - 1) return ERROR;
    q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);
    return OK;
}

// 10. 单链表的建立（头插法）
void CreateListFront(LinkList *L, int n) {
    *L = (LinkList)malloc(sizeof(Lnode));
    (*L)->next = NULL;
    Lnode *p;
    for (int i = 0; i < n; i++) {
        p = (Lnode *)malloc(sizeof(Lnode));
        scanf(" %c", &p->data);
        p->next = (*L)->next;
        (*L)->next = p;
    }
}

// 11. 单链表的建立（尾插法）
void CreateListBack(LinkList *L, int n) {
    *L = (LinkList)malloc(sizeof(Lnode));
    (*L)->next = NULL;
    Lnode *r = *L, *p;
    for (int i = 0; i < n; i++) {
        p = (Lnode *)malloc(sizeof(Lnode));
        scanf(" %c", &p->data);
        p->next = NULL;
        r->next = p;
        r = p;
    }
}

// 遍历链表
void PrintList(LinkList L) {
    Lnode *p = L->next;
    while (p) {
        printf("%c -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

// 主函数测试
int main() {
    LinkList L;
    InitList(&L);
    InsertElem(L, 1, 'A');
    InsertElem(L, 2, 'B');
    InsertElem(L, 3, 'C');
    printf("单链表: ");
    PrintList(L);
    return 0;
}