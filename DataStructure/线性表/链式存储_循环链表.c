//循环链表：头尾相接（最后一个结点的指针域不为空 指向头节点 整个链表形成一个环）
//循环链表中无NULL 若next等于头指针 则终止
//建议用尾指针进行操作 因为快 方便
//优点：从表中任意结点出发都能找到其他结点
#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define MAXSIZE 100 // 存储空间初始分配量

typedef int Status;
typedef char ElemType;

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

// 创建带尾指针的循环链表
LinkList CreateCircularList(char *arr, int len) {
    if (len == 0) return NULL;

    LNode *head = (LNode *)malloc(sizeof(LNode)); // 头节点
    head->next = head; // 先形成一个循环
    LNode *tail = head;

    for (int i = 0; i < len; i++) {
        LNode *node = (LNode *)malloc(sizeof(LNode));
        node->data = arr[i];
        node->next = head; // 新节点指向头节点形成循环
        tail->next = node; // 旧尾部指向新节点
        tail = node;       // 更新尾指针
    }
    return tail; // 返回尾指针
}

// 打印循环链表
void PrintCircularList(LinkList tail) {
    if (!tail) return;
    LNode *p = tail->next->next; // 跳过头节点
    do {
        printf("%c ", p->data);
        p = p->next;
    } while (p != tail->next->next);
    printf("\n");
}

// 合并两个循环链表
LinkList Connect(LinkList Ta, LinkList Tb) {
    if (!Ta || !Tb) return NULL; // 处理空链表的情况

    LNode *TaHead = Ta->next;  // Ta 的头结点
    LNode *TbHead = Tb->next;  // Tb 的头结点

    // 让 Ta 的尾巴指向 Tb 的第一个数据结点
    Ta->next = TbHead->next;
    // 让 Tb 的尾巴指向 Ta 的第一个数据结点
    Tb->next = TaHead->next;

    free(TbHead); // 释放 Tb 的头结点

    return Tb; // 返回合并后的尾指针
}

int main() {
    char dataA[] = {'A', 'B', 'C'};
    char dataB[] = {'X', 'Y', 'Z'};

    LinkList Ta = CreateCircularList(dataA, 3);
    LinkList Tb = CreateCircularList(dataB, 3);

    printf("链表A: ");
    PrintCircularList(Ta);
    printf("链表B: ");
    PrintCircularList(Tb);

    LinkList Tc = Connect(Ta, Tb);

    printf("连接两个链表: ");
    PrintCircularList(Tc);

    return 0;
}