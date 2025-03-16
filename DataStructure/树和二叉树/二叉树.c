//二叉树(Binary Tree)：一个根结点+左子树+右子树 （每个结点最多两个孩子）
//二叉树：只有两个叉的树 结构最简单 规律性最强 
//所有的树都能转为唯一对应的二叉树
//二叉树的五种形态：空 根 根+左子树 根+右子树 根+左右子树

#include<stdio.h>
#include<stdlib.h>
#define MAXTSIZE 100
#define OK 1
#define ERROR 0

typedef char Status;
typedef int TElemType;
//二叉树的顺序存储表示：
typedef TElemType SqBiTree[MAXTSIZE];
SqBiTree bt;

//二叉树的链式存储表示：
typedef struct BiNode{
    TElemType data; //数据域
    struct BiNode *lchild, *rchild; //左右子树 指针
}BiNode, *BiTree;

//二叉树的遍历顺序：
//1.先序遍历（根 左 右）
Status PreOrderTraverse(BiTree T){
    if(T == NULL) return OK;
    else{
        visit(T);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}
//2.1 中序遍历（左 根 右）
Status InOrderTraverse(BiTree T){
    if(T == NULL) return OK;
    else{
        InOrderTraverse(T->lchild);
        visit(T);
        InOrderTraverse(T->rchild);
    }
}

//2.2 中序遍历 非递归方法 用栈实现
//建立一个栈 根结点入栈，遍历左子树 根结点出栈，输出根结点，遍历右子树
Status InOrderTraverse_Stack(BiTree T){
    BiTree p;
    initStack(S);
    p = T;
    while (p || !StackEmpty(S))
    {
        if(p){
            push(S, p);
            p = p->lchild;
        }
        else{
            Pop(S, p);
            printf("%c", q->data);
            p = q->rchild;
        }
        return OK;
    }
    
} 


//3.后序遍历（左 右 根）
Status PostOrderTraverse(BiTree T){
    if(T == NULL) return OK;
    else{
        InOrderTraverse(T->lchild);
        InOrderTraverse(T->rchild);
        visit(T);     
    }
}

//4.二叉树的层次遍历:从上到下 从左到右 使用队列实现

typedef struct { //队列定义
    BTNode data[MaxSize]; //存放队中元素
    int front, rear; //队头和队尾指针
}SqQueue;

void LevelOrder(BTNode *b){
    BTNode *p;
    SqQueue *qu;
    InitQueue(qu);
    enQueue(qu, b);
    while (!QueueEmpty(qu))
    {
        deQueue(qu, p);
        printf("%c", p->data);
        if(p->lchild != NULL)
            enQueue(qu, p->lchild);
        if(p->rchild != NULL)
            enQueue(qu, p->rchild);
    }
}

//5.二叉树的建立 建立顺序：先序（根 左 右）  用#表示空                               
Status CreateBiTree(BiTree *T){
    scanf("&ch");
    if(ch == "#") T = NULL;// #表示空
    else{
        if(!(T = (BiTNode *)malloc(sizeof(BiTree))))
            return ERROR;//溢出
        T->data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
    return OK;
}

//6.复制二叉树
int Copy(BiTree T, BiTree *NewT){
    if(T == NULL){
        NewT = NULL;
        return ERROR;
    }
    else {
        NewT->data = T->data;
        Copy(T->lchild, NewT->lchild);
        Copy(T->rchild, NewT->rchild);
    }
}

//7.计算二叉树深度 左子树深度m 右子树深度n 二叉树深度为m与n中较大者加一
int Depth(BiTree T) {
    if(T == NULL)
     return 0;
    else{
        m = Depth(T->lchild);
        n = Depth(T->rchild);
        if(m > n) return m + 1;
        else return n + 1;
    }
}

//8.求结点总个数 总个数为左子树结点+右子树结点+1
int NodeCount(BiTree T) {
    if(T == NULL) return 0;
    else 
        return NodeCount(T->lchild) + NodeCount(T->rchild) + 1
}

//9.计算叶子节点数 左叶子+右叶子   叶子节点：左右都空
int LeafCount(BiTree T) {
    if(T == NULL) return 0;
    if(T->lchild == NULL && T->rchild = NULL) return 1;
    else return LeafCount(T->lchild) + LeafCount(T->rchild);
}

//10.线索二叉树（Threaded Binary Tree）：利用二叉树链式存储中的空指针域 
//若左子树为空 则把此左子树指针域改为指向其前趋 若右子树为空 就把它的指针域指向其后继



int main(void){

}