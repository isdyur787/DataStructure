//链队：队列的链式存储
//空：头指针 尾指针都指向同一个结点
//从尾入 从头出

#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

typedef char Status;
typedef int QElemType;

// 队列结点结构
typedef struct Qnode {
    QElemType data;
    struct Qnode *next;
} Qnode, *QueuePtr;

// 链队列结构
typedef struct {
    QueuePtr front; // 头指针，指向头结点
    QueuePtr rear;  // 尾指针，指向尾结点
} LinkQueue;

// 1. 链队列初始化：首尾指针都指向头结点
Status InitQueue(LinkQueue *Q) {
    Q->front = Q->rear = (QueuePtr)malloc(sizeof(Qnode)); // 申请头结点空间
    if (!Q->front)
        return ERROR;
    Q->front->next = NULL; // 头结点指针域为空
    return OK;
}

// 2. 销毁队列
Status DestroyQueue(LinkQueue *Q) {
    QueuePtr p;
    while (Q->front) {
        p = Q->front->next; // p临时存要删除的结点信息
        free(Q->front);      // 释放当前头结点
        Q->front = p;        // 头指针后移
    }
    return OK;
}

// 3. 入队（插入到队尾）
Status EnQueue(LinkQueue *Q, QElemType e) {
    QueuePtr p = (QueuePtr)malloc(sizeof(Qnode)); // 创建新结点
    if (!p)
        return ERROR;
    p->data = e;
    p->next = NULL;
    Q->rear->next = p; // 让尾结点指针指向新结点
    Q->rear = p;       // 更新尾指针
    return OK;
}

// 4. 出队（从队头删除）
Status DeQueue(LinkQueue *Q, QElemType *e) {
    if (Q->front == Q->rear)
        return ERROR; // 队空
    QueuePtr p = Q->front->next; // 取头结点的下一个结点（首元素结点）
    *e = p->data;                // 保存出队元素
    Q->front->next = p->next;     // 让头结点指向下一个结点
    if (Q->rear == p)             // 若删除的是尾结点
        Q->rear = Q->front;       // 尾指针回归到头指针
    free(p);                      // 释放出队结点
    return OK;
}

// 5. 取队头元素（但不出队）
Status GetHead(LinkQueue *Q, QElemType *e) {
    if (Q->front == Q->rear)
        return ERROR; // 队列为空
    *e = Q->front->next->data; // 取队头元素
    return OK;
}

// 主函数测试
int main(void) {
    LinkQueue Q;
    if (InitQueue(&Q) == ERROR) {
        printf("队列初始化失败！\n");
        return 1;
    }

    // 入队测试
    printf("入队 10: %s\n", EnQueue(&Q, 10) == OK ? "成功" : "失败");
    printf("入队 20: %s\n", EnQueue(&Q, 20) == OK ? "成功" : "失败");
    printf("入队 30: %s\n", EnQueue(&Q, 30) == OK ? "成功" : "失败");

    // 取队头元素测试
    QElemType e;
    if (GetHead(&Q, &e) == OK)
        printf("队头元素: %d\n", e);

    // 出队测试
    if (DeQueue(&Q, &e) == OK)
        printf("出队元素: %d\n", e);
    if (DeQueue(&Q, &e) == OK)
        printf("出队元素: %d\n", e);

    // 取队头元素测试
    if (GetHead(&Q, &e) == OK)
        printf("队头元素: %d\n", e);

    // 释放队列
    DestroyQueue(&Q);
    printf("队列销毁完成\n");

    return 0;
}