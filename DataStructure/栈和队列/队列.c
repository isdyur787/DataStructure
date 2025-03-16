//队列（Queue）：队尾（an）插入  队头（a1）删除  头插尾删
//一种先进先出的线性表（FIFO）
//应用：排队场景
//空 front = rear
//循环队列 顺序存储

#include <stdio.h>
#include <stdlib.h>

#define MAXQSIZE 100
#define OK 1
#define ERROR 0

typedef char QElemType;
typedef char Status;

typedef struct {
    QElemType *base; // base数组 指针指向数组首元素
    int front;       // 头指针
    int rear;        // 尾指针
} SqQueue;

// 1.队列的初始化
Status InitQueue(SqQueue *Q) {
    Q->base = (QElemType *)malloc(MAXQSIZE * sizeof(QElemType)); // 分配数组空间
    if (!Q->base)
        return ERROR; // 存储分配失败
    Q->front = Q->rear = 0; // 头指针和尾指针置零 队列为空
    return OK;
}

// 2.求队列的长度
int QueueLength(SqQueue *Q) {
    return (Q->rear - Q->front + MAXQSIZE) % MAXQSIZE; // 防止rear的值小于front
}

// 3.入队
Status EnQueue(SqQueue *Q, QElemType e) {
    if ((Q->rear + 1) % MAXQSIZE == Q->front) // 队满
        return ERROR;
    Q->base[Q->rear] = e;                   // 在队尾插入元素
    Q->rear = (Q->rear + 1) % MAXQSIZE;      // 更新队尾指针，循环前进
    return OK;
}

// 4.出队 只能队头出
Status DeQueue(SqQueue *Q, QElemType *e) {
    if (Q->front == Q->rear)
        return ERROR; // 队空
    *e = Q->base[Q->front];                  // 保存要出队的头元素
    Q->front = (Q->front + 1) % MAXQSIZE;    // 队头指针加一，循环前进
    return OK;
}

// 5.取队头元素
QElemType GetHead(SqQueue *Q) {
    if (Q->front != Q->rear) // 队列不空
        return Q->base[Q->front]; // 返回队头元素
    return '\0'; // 返回空字符表示队列为空
}

// 主函数测试
int main(void) {
    SqQueue Q;
    if (InitQueue(&Q) == ERROR) {
        printf("队列初始化失败！\n");
        return 1;
    }

    // 入队测试
    printf("入队 A: %s\n", EnQueue(&Q, 'A') == OK ? "成功" : "失败");
    printf("入队 B: %s\n", EnQueue(&Q, 'B') == OK ? "成功" : "失败");
    printf("入队 C: %s\n", EnQueue(&Q, 'C') == OK ? "成功" : "失败");

    // 取队头元素测试
    printf("队头元素: %c\n", GetHead(&Q));

    // 出队测试
    QElemType e;
    if (DeQueue(&Q, &e) == OK)
        printf("出队元素: %c\n", e);
    if (DeQueue(&Q, &e) == OK)
        printf("出队元素: %c\n", e);

    // 取队列长度
    printf("队列长度: %d\n", QueueLength(&Q));

    // 再次入队测试
    printf("入队 D: %s\n", EnQueue(&Q, 'D') == OK ? "成功" : "失败");
    printf("入队 E: %s\n", EnQueue(&Q, 'E') == OK ? "成功" : "失败");

    // 取队头元素测试
    printf("队头元素: %c\n", GetHead(&Q));

    return 0;
}