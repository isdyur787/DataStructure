//树型结构：非线性结构 结点之间有分支 具有层次关系
//用例：家谱 组织机构 语法结构 组织信息 算法分析......
//树（Tree）是n个结点的有限集 若n=0空树， 若n>0:有且仅有一个根（Root）结点 + 其余结点（子树SubTree）
//根结点：只有一个 无前驱结点
//结点的度：结点拥有的子树数量 = 分支的数量 = 后继结点的数量
//树的度：树内所有结点中的最大值
//度为0的结点：叫做叶子 或 终端结点
//不为0的结点：分支结点 内部结点

typedef int TElemType;
//存储方式1:双亲表示法 特点：找双亲方便 找孩子难
typedef struct PTNode {
    TElemType data;
    int parent;//双亲位置域
}PTNode;
//树结构
#define MAXTREESIZE 100
typedef struct {
    PTNode nodes[MAXTREESIZE];
    int r, n; //根结点的位置和个数
}PTree;

//2.孩子链表 找孩子容易
//孩子结点结构：
typedef struct CTNode {
    int child;
    struct CTNode *next;
}*ChildPtr;
//双亲结点结构：
typedef struct {
    TElemType data;
    ChildPtr firstchild; //孩子链表的头指针
}CTBox;

//!! 3.孩子兄弟表示法（二叉树表示法）用二叉链表存储 两个指针：一个指孩子 一个指兄弟
typedef struct CSNode {
    TElemType data;
    struct CSNode *firstchild, *nextsibling;
}CSNode, *CSTree;

//树转化为二叉树 （因为二叉树简单）都可以用二叉链表来存储
//步骤：1. 兄弟之间加一条线 2. 对每个结点 除了其左子树外，去除其与其余孩子之间的关系 3.以树根为轴心 顺时针旋转45度
//口诀：兄弟相连留长子

//二叉树转化为树

//森林转化为二叉树

//二叉树转化为森林

//树的遍历：
//1.先根遍历：先访问根结点 然后依次先根访问各个子树

//2.后根遍历：先后根访问各个子树 再根结点

//3.层次遍历：从上到下 从左到右

//森林的遍历：
//1.先序遍历：
//2.中序遍历