//
// Created by Lenovo on 2020/10/29.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int weight;
    int parent;
    int lchild;
    int rchild;
} HTNode, *HuffmanTree;
typedef char **HuffmanCode;

void SelectTwoMin(int upbound, HuffmanTree HT, int &s1, int &s2);

void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, int *w, int n);

int mainHuffmanTree() {
    HuffmanTree ht;
    HuffmanCode hc;

    int n;
    scanf("%d", &n);
//    多少个

    int *w = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i)
        scanf("%d", &w[i]);
//    每个的权值

    HuffmanCoding(ht, hc, w, n);

    printf(" ht[i].weight, ht[i].parent, ht[i].lchild, ht[i].rchild);\n");
    for (int i = 1; i <= 2 * n - 1; ++i) {
        printf("%d %d %d %d\n",
               ht[i].weight, ht[i].parent, ht[i].lchild, ht[i].rchild);
    }
    printf("每一个节点的哈夫曼编码\n");
    for (int i = 1; i <= n; ++i)
        printf("%s\n", hc[i]);

    free(w);
    free(ht);
    for (int i = 1; i <= n; ++i)
        free(hc[i]);

    return 0;
}
/* 你的代码将被嵌在这里 */

//函数SelectTwoMin(int upbound, HuffmanTree HT, int &s1, int &s2)是从1到upbound中找出father为0的节点赋给s1,s2,
// （为了保证答案唯一，请让s1的节点编号小于s2），
//https://pintia.cn/problem-sets/1321327444616241152/problems/1321327558336405516
//wrong thing
namespace mine {

    void SelectTwoMin(int upbound, HuffmanTree HT, int &s1, int &s2) {
        int have = 0;
        for (int i = 1; i <= upbound; i++) {
            if (HT->parent == 0) {
                if (have == 0) {
                    s1 = HT->weight;
                    have = 1;
                } else {
                    s2 = HT->weight;
                    break;
                }

            }
        }
    }

//函数HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, int *w, int n)
// 是构造哈夫曼树以及计算哈夫曼编码。保证输入的权重值小于1000。
//其中 upbound 编号，HT是哈夫曼树，HC是哈夫曼编码，w是权值，n是叶子节点个数。
//typedef char **HuffmanCode;
    void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, int *w, int n) {

    }

}

//翻转一个字符串
void reverse(char *CH) {
    int n = strlen(CH);
    int i;
    for (i = 0; i < n / 2; i++) {
        char temp;
        temp = CH[i];
        CH[i] = CH[n - i - 1];
        CH[n - i - 1] = temp;
    }
}

//https://blog.csdn.net/weixin_43843978/article/details/89451845
//其中 upbound 编号，HT是哈夫曼树，HC是哈夫曼编码，w是权值，n是叶子节点个数
void SelectTwoMin(int upbound, HuffmanTree HT, int &s1, int &s2) {
    int x1 = 0, x2 = 0;
//    have relation with index
    int m1 = 1000;
    int m2 = 1000;
    for (int i = 1; i <= upbound; i++) {
        if (HT[i].parent == 0 && HT[i].weight < m1) {
//            root node
            m2 = m1;
//            第二小的比第一小的小
//这里感觉搞错了，我理解错了，应该是m2 是最小的吧
            x2 = x1;
//            最小的下标，最小的值至少是m1这么小，
            m1 = HT[i].weight;
//            第二小的
//            smaller weight
            x1 = i;
//            第二小的东西的下标
        } else if (HT[i].parent == 0 && HT[i].weight < m2) {
//            找到一个更加小的，并且他是根，也就是那些离散的东西
            m2 = HT[i].weight;
            x2 = i;
        }
    }
    s1 = x1;
//    下标
    s2 = x2;
}

//其中 upbound 编号，HT是哈夫曼树，HC是哈夫曼编码，w是权值（一个数组，每个点的权值），n是叶子节点个数
void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, int *w, int n) {
    int s1 = 0;
    int s2 = 0;
    HT = (HuffmanTree) malloc(sizeof(HTNode) * (2 * n));
    HC = (char **) malloc(sizeof(char *) * (n + 1));
//    这好像是一个二维数组一样的东西
    for (int i = 1; i <= n; i++) {
//        HC是哈夫曼编码
        HC[i] = (char *) malloc(sizeof(char) * (n + 1));
        memset(HC[i], 0, sizeof(char) * (n + 1));
    }
//    1 开始
    for (int i = 0; i < n; ++i) {
        HT[i + 1].weight = w[i];
    }//给结构体赋值
//    n是叶子节点，那么一共 的节点就是2n-1
//    一棵有n个叶子节点的赫夫曼树共有2n-1个节点。
    for (int i = 1; i <= 2 * n - 1; i++) {
        HT[i].parent = 0;
        HT[i].lchild = 0;
        HT[i].rchild = 0;
    }
    for (int i = 0; i < n - 1; ++i) {
//        HT是哈夫曼树
        SelectTwoMin(n + i, HT, s1, s2);
        HT[i + n + 1].lchild = s1;
//        因为下标是从1开始的，所以要加1
        HT[i + n + 1].rchild = s2;
        HT[i + n + 1].weight = HT[s1].weight + HT[s2].weight;
//        这个节点到时候算权重的时候不管的
        HT[s1].parent = i + n + 1;
        HT[s2].parent = i + n + 1;
    }
    //
    for (int i = 1; i <= n; ++i) {
        int c = i;
        int parent = HT[c].parent;
        while (parent != 0) {
//            左边孩子是0
            if (HT[parent].lchild == c) {
//                strncat()主要功能是在字符串的结尾追加n个字符。
//                https://baike.baidu.com/item/strncat/5522575?fr=aladdin
                strncat(HC[i], "0", 1);
//                第i个HC编码有个编码
            } else
                strncat(HC[i], "1", 1);
            c = parent;
//            c是他自己
            parent = HT[parent].parent;
//            他爹
        }
        reverse(HC[i]);
    }
}