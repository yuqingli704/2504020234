
#include <stdio.h>
#include <stdlib.h>

// 定义二叉树结点结构体
typedef struct Node {
    int data;
    struct Node* lchild;
    struct Node* rchild;
} BiTNode, *BiTree;

int N;  // 表达式长度

// 创建二叉树（根据顺序存储数组）
BiTree CreateBiTree(int nodeList[], int position) {
    BiTree p;
    // 若结点为空或位置超出范围，返回NULL
    if (position > N || nodeList[position] == 0) {
        return NULL;
    } else {
        p = (BiTree)malloc(sizeof(BiTNode));
        p->data = nodeList[position];
        p->lchild = CreateBiTree(nodeList, 2 * position);
        p->rchild = CreateBiTree(nodeList, 2 * position + 1);
        return p;
    }
}

// 计算单个表达式的值
int Get_Value(int oper, int oper1, int oper2) {
    switch ((char)oper) {
        case '*': return oper1 * oper2;
        case '/': return oper1 / oper2;
        case '+': return oper1 + oper2;
        case '-': return oper1 - oper2;
        default: return 0;
    }
}

// 递归计算表达式的值
int Calculate(BiTree T) {
    int oper1, oper2;
    if (T->lchild == NULL && T->rchild == NULL) {
        return T->data - '0';  // 叶子结点：字符数字转整型数字
    }
    oper1 = Calculate(T->lchild);
    oper2 = Calculate(T->rchild);
    return Get_Value(T->data, oper1, oper2);
}

int main() {
    BiTree T = NULL;
    int cal_result;
    // 二叉树顺序存储数组（索引0不用，从1开始）
    int nodeList[8] = { ' ', '*', '+', '-', '1', '2', '6', '3' };
    N = 7;  // 表达式长度（数组有效元素个数）
    T = CreateBiTree(nodeList, 1);
    cal_result = Calculate(T);
    printf("Calculate result is [%d]\n", cal_result);
    return 0;
}