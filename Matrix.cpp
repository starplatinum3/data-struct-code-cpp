//
// Created by Lenovo on 2021/2/21.
//

#include<cstdio>
#include<cstring>
#include<cmath>
#include "Matrix.h"
//#define MOD 1000000007
//#define LL long long
//static long long  ** Matrix:: newMat(int _rowCnt, int _colCnt) {
//        LL **ret;
//        ret = new LL *[_rowCnt];
//        for (int i = 0; i < _rowCnt; ++i) {
//            ret[i] = new LL[_colCnt];
//        }
//        return ret;
//    }
//matrix
//struct Matrix {
////    using namespace std;
//    typedef  long long LL ;
//    LL **v;
//    int rowCnt, colCnt;
//    static const int MOD=1000000007;
//
//    static LL **newMat(int _rowCnt, int _colCnt) {
//        LL **ret;
//        ret = new LL *[_rowCnt];
//        for (int i = 0; i < _rowCnt; ++i) {
//            ret[i] = new LL[_colCnt];
//        }
//        return ret;
//    }
//
//    LL **newMat(){
//        return newMat(rowCnt,colCnt);
//    }
//
//    static int  **newIntMatrix(int _rowCnt, int _colCnt) {
//        int  **ret;
//        ret = new int  *[_rowCnt];
//        for (int i = 0; i < _rowCnt; ++i) {
//            ret[i] = new int[_colCnt];
//        }
//        return ret;
//    }
//
//    static int ** sub(const Matrix& a,const Matrix& b){
//        int i,j;
//        int ** mat=newIntMatrix(a.rowCnt,a.colCnt);
//        for (i = 0; i < a.rowCnt; i++)
//        {
//            for (j = 0; j < a.colCnt; j++)
//            {
//                mat[i][j]=  a.v[i][j]-  b.v[i][j];
////                c[i][j] = a[i][j] - b[i][j];
//            }
//        }
//        return mat;
//    }
//
//    static long long  ** subLL(const Matrix& a,const Matrix& b){
//        int  i,j;
//        long long ** mat=newMat(a.rowCnt,a.colCnt);
//        for (i = 0; i < a.rowCnt; i++)
//        {
//            for (j = 0; j < a.colCnt; j++)
//            {
//                mat[i][j]=  a.v[i][j]-  b.v[i][j];
////                c[i][j] = a[i][j] - b[i][j];
//            }
//        }
//        return mat;
//    }
//
//
//
//    void memsetMat() {
////        for (int i = 0; i <rowCnt ; ++i) {
////            memset(v, 0, sizeof(v[i]));
////        }
//    }
//
//    Matrix() {
//        rowCnt = 6;
//        colCnt = 6;
////        v= (new LL[rowCnt][colCnt]);
//        v = newMat();
////        implicit use of 'this' pointer is only allowed within the evaluation of a call to a 'constexpr' member function
////        Array size is not a constant expression
//
//        memset(v, 0, sizeof(v[0]));
//        this->print();
//
//    }
//
//    Matrix(Matrix const &matrix) {
//        rowCnt = 6;
//        colCnt = 6;
//        for (int i = 0; i < rowCnt; i++) {
//            for (int j = 0; j < colCnt; j++) {
//                v[i][j] = matrix.v[i][j];
//            }
//        }
//    }
//
//    void print() {
//        for (int i = 0; i < rowCnt; i++) {
//            for (int j = 0; j < colCnt; j++) {
//
//                printf("%4lld", v[i][j]);
//            }
//            putchar('\n');
//        }
//        putchar('\n');
//    }
//
//    static Matrix mul(const Matrix &x, const Matrix &y) {
//        Matrix ans;
//        for (int i = 0; i < 6; i++) {
//            for (int j = 0; j < 6; j++) {
//                for (int k = 0; k < 6; k++) {
//                    ans.v[i][j] = (ans.v[i][j] + x.v[i][k] * y.v[k][j]) % MOD;
//                }
//            }
//        }
//        return ans;
//    }
//
//    Matrix mul(const Matrix &x) {
//        return mul(*this, x);
//    }
//
//    Matrix mulSelf() {
//        return mul(*this, *this);
//    }
//
//};

//Matrix mul(const Matrix& x, const Matrix& y) {
//    Matrix ans;
//    for (int i = 0; i < 6; i++) {
//        for (int j = 0; j < 6; j++) {
//            for (int k = 0; k < 6; k++) {
//                ans.v[i][j] = (ans.v[i][j] + x.v[i][k] * y.v[k][j]) % MOD;
//            }
//        }
//    }
//    return ans;
//}

//x 自己乘以 k 次
//x^k
//Matrix q_pow(Matrix x, int k) {
//    Matrix ans;
//    for (int i = 0; i < 6; i++) ans.v[i][i] = 1;
//    while (k) {
//        if (k & 1) ans = mul(ans, x);
//        x = mul(x, x);
//        k >>= 1;
//    }
//    return ans;
//}

//int n, m, a, b;;
//
//int mainMatrix() {
//    //初始化
//    Matrix T, ans;
//    for (int i = 0; i < 6; i++) {
//        for (int j = 0; j < 6; j++) {
//            T.v[i][j] = 1;
//        }
//    }
//    //数据输入
//    scanf("%d%d", &n, &m);
//    for (int i = 0; i < m; i++) {
//        scanf("%d%d", &a, &b);
//        T.v[a - 1][b - 1] = 0;
//        T.v[b - 1][a - 1] = 0;
//    }
//    Matrix tmp = Matrix(T);
//    tmp.print();
////    T2.print();
//    tmp = tmp.mul(T);
//    tmp.print();
//
//    tmp = tmp.mul(T);
//    tmp.print();
//
////    Matrix tPow2 = q_pow(T, 2);
////    printf("tPow2\n");
////    tPow2.print();
////
////    //数据处理
////    ans = q_pow(T, n - 1);
////
////    int sum = 0;
////    for (int i = 0; i < 6; i++) {
////        for (int j = 0; j < 6; j++) {
////            sum = (sum + ans.v[i][j]) % MOD;
////        }
////    }
////    //结果输出
////    printf("%d\n", (sum * ((int) pow(4, n)) % MOD) % MOD);
//
//    return 0;
//}