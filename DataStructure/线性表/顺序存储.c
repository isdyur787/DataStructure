//线性表（List）顺序存储：
//连续的存储空间
//插入 删除 查找算法的平均时间复杂度是O（n） 空间复杂度S（n）= O（1）
//优点：存储密度大 可以随机存取表中任一元素
//缺点：插入删除时需要移动大量元素 浪费存储空间 属于静态存储类型 数据元素的个数不能自由扩充
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;
typedef char ElemType;
#define LIST_INT_SIZE 1000

typedef struct {
    char no[20];
    char name[50];
    float price;
} Book;

typedef struct {
    Book *elem;
    int length;
} SqList;

//1 线性表L的初始化
Status InitList_Sq(SqList *L) {
    L->elem = (Book *)malloc(LIST_INT_SIZE * sizeof(Book));
    if (!L->elem) return OVERFLOW;
    L->length = 0;
    return OK;
}

//2 销毁线性表
Status DestroyList_Sq(SqList *L) {
    if (L->elem) {
        free(L->elem);
        L->elem = NULL;
        L->length = 0;
    }
    return OK;
}

//3 清空线性表
void ClearList_Sq(SqList *L) {
    L->length = 0;
}

//4 求长度
int GetLength_Sq(SqList *L) {
    return L->length;
}

//5 判断为空
int isEmpty(SqList *L) {
    return L->length == 0;
}

//6 顺序表的取值（根据位置i获取相应位置数据元素的内容）
Status GetElem(SqList *L, int i, Book *e) {
    if (i < 1 || i > L->length) return ERROR;
    *e = L->elem[i - 1];
    return OK;
}

//7 ！！顺序表的查找 在线性表L中查找与指定值e相同的元素位置 从表的一端开始找 找到返回i 否则返回0
int LocateElem(SqList *L, char *name) {
    for (int i = 0; i < L->length; i++) {
        if (strcmp(L->elem[i].name, name) == 0)
            return i + 1;
    }
    return 0;
}

//8 ！！插入算法
Status ListInsert_Sq(SqList *L, int i, Book e) {
    if (i < 1 || i > L->length + 1) return ERROR;
    if (L->length == LIST_INT_SIZE) return ERROR;
    for (int j = L->length; j >= i; j--)
        L->elem[j] = L->elem[j - 1];
    L->elem[i - 1] = e;
    L->length++;
    return OK;
}

//9 ！！删除算法
Status ListDelete_Sq(SqList *L, int i, Book *e) {
    if (i < 1 || i > L->length) return ERROR;
    *e = L->elem[i - 1];
    for (int j = i - 1; j < L->length - 1; j++)
        L->elem[j] = L->elem[j + 1];//被删除元素之后的元素前移
    L->length--;//表长减一
    return OK;
}

void PrintList(SqList *L) {
    for (int i = 0; i < L->length; i++) {
        printf("No: %s, 书名: %s, 价格: %.2f\n", L->elem[i].no, L->elem[i].name, L->elem[i].price);
    }
}

int main() {
    SqList bookList;
    InitList_Sq(&bookList);
    
    Book b1 = {"001", "C语言", 45.5};
    Book b2 = {"002", "数据结构", 55.0};
    Book b3 = {"003", "Java", 65.0};
    
    ListInsert_Sq(&bookList, 1, b1);
    ListInsert_Sq(&bookList, 2, b2);
    ListInsert_Sq(&bookList, 3, b3);
    
    printf("插入图书后:\n");
    PrintList(&bookList);
    
    Book deletedBook;
    ListDelete_Sq(&bookList, 2, &deletedBook);
    printf("\n删除第二本书后:\n");
    PrintList(&bookList);
    
    printf("\n查找Java 结果：%d\n", LocateElem(&bookList, "Java"));
    
    DestroyList_Sq(&bookList);
    return 0;
}
