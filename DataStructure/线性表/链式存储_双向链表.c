//双向链表：在单链表的基础上加上指向前趋的指针域 更便于查找前面的元素
//空表：除了头结点没有其他结点（prior域和next域都为空）
//包含三个部分（prior➕data➕next）

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
#define OK 1
#define ERROR 0

typedef int Status;
typedef char ElemType;

typedef struct DuLNode {
    ElemType data;
    struct DuLNode *prior, *next;
} DuLNode, *DuLinkList;

// 初始化双向链表
DuLinkList InitList() {
    DuLNode *head = (DuLNode *)malloc(sizeof(DuLNode));
    head->prior = head->next = NULL;
    return head;
}

// 获取第 i 个元素，返回指向该节点的指针
DuLNode* GetElem(DuLinkList L, int i) {
    DuLNode *p = L->next; // 从头结点的 next 开始
    int j = 1;
    while (p && j < i) { //向后扫描
        p = p->next;
        ++j;
    }
    return p; // 若 i 超出范围，则返回 NULL
}

// 双向链表插入
Status ListInsert(DuLinkList L, int i, ElemType e) {
    DuLNode *p;
    if (i == 1) { 
        // 头部插入特殊处理
        p = L; 
    } else {
        p = GetElem(L, i - 1);//调用上面的查找算法 来判断位置i是否合理 若返回的p为空 报错
        if (!p) return ERROR;
    }

    DuLNode *s = (DuLNode *)malloc(sizeof(DuLNode));
    if (!s) return ERROR;

    s->data = e; //e赋值给s
    s->prior = p; //双链表要修改四个指针
    s->next = p->next;

    if (p->next) p->next->prior = s;
    p->next = s;

    return OK;
}

// 双向链表删除
Status ListDelete(DuLinkList L, int i, ElemType *e) {
    DuLNode *p = GetElem(L, i);
    if (!p) return ERROR;

    *e = p->data;

    if (p->prior) p->prior->next = p->next;
    if (p->next) p->next->prior = p->prior;

    free(p);
    return OK;
}

// 打印双向链表
void PrintList(DuLinkList L) {
    DuLNode *p = L->next;
    while (p) {
        printf("%c ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    DuLinkList L = InitList();

    ListInsert(L, 1, 'A');
    ListInsert(L, 2, 'B');
    ListInsert(L, 3, 'C');
    ListInsert(L, 4, 'D');

    printf("插入元素后: ");
    PrintList(L);

    ElemType deleted;
    ListDelete(L, 2, &deleted);
    printf("删除元素 %c 后: ", deleted);
    PrintList(L);

    return 0;
}