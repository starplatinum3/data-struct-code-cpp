//
// Created by Lenovo on 2021/1/13.
//

#ifndef DATASTRUCT_KNAPSACK_H
#define DATASTRUCT_KNAPSACK_H

#include <stdio.h>

using namespace std;
const int N = 1e3 + 7;
int a[N];
//int m[n+1][n+1] = new int[n+1][n+1];
//int s[n+1][n+1] = new int[n+1][n+1];
int m[N][N];
int s[N][N];

void Display(int s[][N], int i, int j) {
    if (i == j) {
        printf("A");
        printf("%d", i);
//        System.out.print('A');
//        System.out.print(i);
    } else {
//        System.out.print('(');
        printf("(");
        Display(s, i, s[i][j]);
        Display(s, s[i][j] + 1, j);
//        System.out.print(')');
        printf(")");
    }

}

void Matrix_Chain_Order(int a[], int len) {
    const int n = len - 1;
    int i, j, k, t;
    for (i = 0; i <= n; i++)
        m[i][i] = 0;
    for (i = 0; i <= n; i++)
        s[i][i] = 0;
    for (t = 2; t <= n; t++) //t is the chain length
    {
        for (i = 1; i <= n - t + 1; i++)//从第一矩阵开始计算，计算长度为t的最小代价
        {
            j = i + t - 1;//长度为t时候的最后一个元素
            m[i][j] = 1000000;//初始化为最大代价
            for (k = i; k <= j - 1; k++)//寻找最优的k值，使得分成两部分k在i与j-1之间
            {
                int temp = m[i][k] + m[k + 1][j] + a[i - 1] * a[k] * a[j];
                if (temp < m[i][j]) {
                    m[i][j] = temp;   //记录下当前的最小代价
                    s[i][j] = k;      //记录当前的括号位置，即矩阵的编号
                }
            }
        }
    }

//    System.out.println("一个最优解为：");
    printf("一个最优解为：");
    Display(s,1,n);
    printf("\n计算的次数为：");
//    System.out.println("\n计算的次数为：");
    printf("%d\n",m[1][n]);
//    System.out.println(m[1][n]);
}


#endif //DATASTRUCT_KNAPSACK_H
