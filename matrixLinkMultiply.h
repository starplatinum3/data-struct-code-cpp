//
// Created by Lenovo on 2021/1/25.
//

#ifndef DATASTRUCT_MATRIXLINKMULTIPLY_H
#define DATASTRUCT_MATRIXLINKMULTIPLY_H

#include <stdio.h>

//https://pintia.cn/problem-sets/1314767576917401600/problems/1352144042022457353
const int N = 1e3 + 7;
int a[N] = {3, 5, 2, 1, 10};
//矩阵 是 3*5  5*2 2*1 。。的
//第一个矩阵 3*5  i==1 ， 是 a[0]*a[1] a[i-1]*a[i]
//所以要乘以的次数 a[i-1]*a[i]
int m[N][N];
int s[N][N];
const int INF = 0x3fffffff;

void findBestK(int i, int j) {
    int k;
    for (k = i; k <= j - 1; k++)//寻找最优的k值，使得分成两部分k在i与j-1之间
    {
        int temp = m[i][k] + m[k + 1][j] + a[i - 1] * a[k] * a[j];
//                {3, 5, 2, 1, 10};  2 （i, 1, 10（j  ，  2, 1, 10
//arr[i]==2 ,arr[j]==10
//k 最多也只能取到 1的那个位置，就是下标3， 不能取10的位置
//                                  a[i-1] *
        if (temp < m[i][j]) {
            m[i][j] = temp;   //记录下当前的最小代价
            s[i][j] = k;      //记录当前的括号位置，即矩阵的编号
        }
    }
}

void calTLenPay(int t, int matrixCnt) {
    int i, j;
//    matrix arr [i--j]
    for (i = 1; i <= matrixCnt - t + 1; i++)//从第一矩阵开始计算，计算长度为t的最小代价
    {
//            选择的 矩阵是 i--j 这个范围的，j可以根据t 这个选择的长度算出来
//            n==5
//            5 个数字的话 就有 4个矩阵
//            5-2 +1 ==4  [1-4]
//            {3, 5, 2, 1, 10};
//长度3 ，t==3， i==2 的时候 ，取得 是他们 2, 1, 10
//  所以 j 是从 取得i开始，(i就是取得这一段的开始下标，) +长度t -1， 现在算是4，
//2+3-1==4
        j = i + t - 1;//长度为t时候的最后一个元素
//            printf("(i,j): (%d,%d)\n",i,j);
//            m[i][j] = 100000011;//初始化为最大代价
        m[i][j] = INF;//初始化为最大代价
//            这段东西
//m是需要的乘法次数 从i 乘到 j
        findBestK(i, j);
//        在i j 之间找更好的k
    }
}

void matrixChainOrderRefactor(int a[], int len) {
    const int n = len - 1;
    int i, j, k, t;
//    自己到自己肯定是不用次数的
    for (i = 0; i <= n; i++)
        m[i][i] = 0;
    for (i = 0; i <= n; i++)
        s[i][i] = 0;
//链子最短也有两个
    //    len 长度的数组 代表的是n=len-1 个矩阵
    for (t = 2; t <= n; t++) //t is the chain length
    {
//        链子达到t长度 需要花费多少 就是要乘多少次
        calTLenPay(t, n);

    }
//    获得上述矩阵的乘积，所需的最少乘法次数。
    printf("%d\n", m[1][n]);
}

void Matrix_Chain_Order(int a[], int len) {
    const int n = len - 1;
    int i, j, k, t;
    for (i = 0; i <= n; i++)
        m[i][i] = 0;
    for (i = 0; i <= n; i++)
        s[i][i] = 0;
//    len 长度的数组 代表的是n=len-1 个矩阵
    for (t = 2; t <= n; t++) //t is the chain length
    {

//        3 5 / ...  3, 5, 2, 1, 10
//既然需要选择t长度的东西，那么i作为范围左边的数字，他的最大取值肯定是要减去一定长度的，就是减掉t的长度
        for (i = 1; i <= n - t + 1; i++)//从第一矩阵开始计算，计算长度为t的最小代价
        {
//            选择的 矩阵是 i--j 这个范围的，j可以根据t 这个选择的长度算出来
//            n==5
//            5 个数字的话 就有 4个矩阵
//            5-2 +1 ==4  [1-4]
//            {3, 5, 2, 1, 10};
//长度3 ，t==3， i==2 的时候 ，取得 是他们 2, 1, 10
//  所以 j 是从 取得i开始，(i就是取得这一段的开始下标，) +长度t -1， 现在算是4，
//2+3-1==4
            j = i + t - 1;//长度为t时候的最后一个元素
//            printf("(i,j): (%d,%d)\n",i,j);
//            m[i][j] = 100000011;//初始化为最大代价
            m[i][j] = INF;//初始化为最大代价
//            这段东西
//m是需要的乘法次数 从i 乘到 j
            for (k = i; k <= j - 1; k++)//寻找最优的k值，使得分成两部分k在i与j-1之间
            {
                int temp = m[i][k] + m[k + 1][j] + a[i - 1] * a[k] * a[j];
//                {3, 5, 2, 1, 10};  2 （i, 1, 10（j  ，  2, 1, 10
//arr[i]==2 ,arr[j]==10
//k 最多也只能取到 1的那个位置，就是下标3， 不能取10的位置
//                                  a[i-1] *
                if (temp < m[i][j]) {
                    m[i][j] = temp;   //记录下当前的最小代价
                    s[i][j] = k;      //记录当前的括号位置，即矩阵的编号
                }
            }
        }
    }
//    获得上述矩阵的乘积，所需的最少乘法次数。
    printf("%d\n", m[1][n]);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n + 1; i++) {
        scanf("%d", a + i);
    }
//    n 个矩阵，a会是n+1 的长度
//    Matrix_Chain_Order(a, n + 1);
    matrixChainOrderRefactor(a, n + 1);

//    printf("11875");
}

#endif //DATASTRUCT_MATRIXLINKMULTIPLY_H
