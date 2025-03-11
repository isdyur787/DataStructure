//数据结构课堂展示 Demo1 2025/3/10 by邵昱铭
#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

typedef int Status;
typedef char ElemType;

//定义链表节点结构体
typedef struct Lnode{
    ElemType data;  //数据域
    struct Lnode *next; //指针域
} Lnode, *LinkList;  //定义LinkList是指向Lnode结构体的指针类型

//菜单
void menu() {
    printf("\n\t====== 单链表操作菜单 ======");
    printf("\n\t1. 建立单链表（头插法）");
    printf("\n\t2. 建立单链表（尾插法）");
    printf("\n\t3. 插入新元素");
    printf("\n\t4. 删除指定位置的元素");
    printf("\n\t5. 遍历输出链表");
    printf("\n\t6. 删除指定范围的元素");
    printf("\n\t7. 退出");
}

//1 头插法创建链表（新节点插入到链表头部）
void CreateListFront(LinkList *L, int n) {
    *L = (LinkList)malloc(sizeof(Lnode)); //创建头结点
    (*L)->next = NULL;  //初始化一个空表
    Lnode *p;
    for (int i = 0; i < n; i++) {
        p = (Lnode *)malloc(sizeof(Lnode));  //为新节点开辟内存空间
        scanf(" %c", &p->data);  //输入节点数据
        p->next = (*L)->next;  //新节点的next指向原来的第一个节点
        (*L)->next = p;  //头节点的next指向新节点
    }
}

//2尾插法创建链表（新节点插入到链表尾部）
void CreateListBack(LinkList *L, int n) {
    *L = (LinkList)malloc(sizeof(Lnode));  //创建头节点
    (*L)->next = NULL;
    Lnode *r = *L, *p;  //r指向当前尾节点
    for (int i = 0; i < n; i++) {
        p = (Lnode *)malloc(sizeof(Lnode)); //创建新节点
        scanf(" %c", &p->data);  //输入节点数据
        p->next = NULL;
        r->next = p; //让当前尾节点的next指向新节点
        r = p;  //更新尾节点
    }
}

//3 在i插入新节点 值为e
Status InsertElem(LinkList L, int i, ElemType e) {
    Lnode *p = L;  //p指向头节点用于遍历
    int j = 0; //记录当前节点的位置索引
    while (p && j < i - 1) {  //查找第i-1个节点
        p = p->next;
        ++j;
    }
    if (!p || j > i - 1) return ERROR;  //判断i是否超出范围
    Lnode *s = (Lnode *)malloc(sizeof(Lnode));  //创建新节点
    if (!s) return ERROR;
    s->data = e;
    s->next = p->next;  // 新节点指向p的下一个节点
    p->next = s;  //p指向新节点
    return OK;
}

//4 删除第i个结点，并返回其值
Status DeleteElem(LinkList L, int i, ElemType *e) {
    Lnode *p = L, *q;//p:遍历链表 q：存删除结点
    int j = 0; //记录当前位置
    while (p->next && j < i - 1) {  //查找第i-1个节点
        p = p->next;
        ++j;
    }
    if (!(p->next) || j > i - 1) return ERROR;  //如果i超出范围，返回错误
    q = p->next;  //q指向要删除的节点
    p->next = q->next;  // 让p直接指向q的下一个节点
    *e = q->data;  //记录删除的节点数据
    free(q);
    return OK;
}

//5 遍历链表并打印
void PrintList(LinkList L) {
    Lnode *p = L->next;
    while (p) {
        printf("%c -> ", p->data);  // 输出节点数据
        p = p->next;
    }
    printf("NULL\n");  // 结束标志
}

//6 删除所有值在 (mink, maxk) 之间的节点
void DeleteInRange(LinkList L, ElemType mink, ElemType maxk) {
    Lnode *p = L, *q; //p：遍历 q：指要删除的节点
    while (p->next) {
        if (p->next->data > mink && p->next->data < maxk) {  //判断是否需要删除
            q = p->next;  //q指向要删除的节点
            p->next = q->next;  //让p跳过q
            free(q);
        } else {
            p = p->next;  //继续遍历
        }
    }
}

// 主函数
int main() {
    LinkList L = NULL;
    int choice, n, pos;
    ElemType e, mink, maxk;

    while (1) {
        menu();
        printf("\n请输入功能选项：");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("请输入链表元素个数：");
                scanf("%d", &n);
                CreateListFront(&L, n);
                printf("单链表（头插法）创建成功！\n");
                break;

            case 2:
                printf("请输入链表元素个数：");
                scanf("%d", &n);
                CreateListBack(&L, n);
                printf("单链表（尾插法）创建成功！\n");
                break;

            case 3:
                printf("请输入插入位置和元素值：");
                scanf("%d %c", &pos, &e);
                if (InsertElem(L, pos, e) == OK) {
                    printf("插入成功！\n");
                } else {
                    printf("插入失败！\n");
                }
                break;

            case 4:
                printf("请输入要删除的结点位置：");
                scanf("%d", &pos);
                if (DeleteElem(L, pos, &e) == OK) {
                    printf("删除成功！删除元素：%c\n", e);
                } else {
                    printf("删除失败！\n");
                }
                break;

            case 5:
                printf("当前链表内容：\n");
                PrintList(L);
                break;

            case 6:
                printf("请输入 mink 和 maxk（删除范围）：");
                scanf(" %c %c", &mink, &maxk);
                DeleteInRange(L, mink, maxk);
                printf("已删除所有值大于 %c 且小于 %c 的元素！\n", mink, maxk);
                break;

            case 7:
                printf("程序退出！\n");
                return 0;

            default:
                printf("无效选项，请重新输入！\n");
                break;
        }
    }
    return 0;
}
