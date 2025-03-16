//LeetCode
#include <stdio.h>
#include <stdlib.h>

typedef struct BiTree{
    int val;
    struct BiTree *lchild, *rchild;

}BiTree;

//1.前序遍历
void PreOrderTrans(struct BiTree *root, int *res, int *returnSize) {
    if(!root) return;

    res[(*returnSize)++] = root->val;
    PreOrderTrans(root->lchild, res, returnSize);
    PreOrderTrans(root->rchild, res, returnSize);
}

int PreOrderT(){
    int *returnSize = 0;
    int *res = malloc(sizeof(int) * 100);
    struct BiTree *root = {1, 2, 3, NULL, 4, 5, NULL, 6};
    PreOrderTrans(root, res, returnSize);
    return res;
}