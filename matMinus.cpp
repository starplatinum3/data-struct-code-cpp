//
// Created by Lenovo on 2021/4/22.
//

//矩阵相加 矩阵相减
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
class trMinus
{
private:
    int m, n, k;
    double **a, **b, **c; //a[m][n]+b[m][n]=c[m][n]
public:
    trMinus(int mm, int nn) //有参数的构造函数
    {
        int i;
        m = mm;
        n = nn;
//动态分配内存空间
        a = new double*[m]; //a[m][n]
        for (i = 0; i < m; i++)
        {
            a[i] = new double[n]; //a[m][n]
        }
        b = new double*[m]; //b[m][n]
        for (i = 0; i < m; i++)
        {
            b[i] = new double[n];//b[m][n]
        }
        c = new double*[m];//c[m][n]
        for (i = 0; i < m; i++)
        {
            c[i] = new double[n];//c[m][n]
        }
    }
    void input(); //从文件读入:a[m][n]与b[m][n]
    void add(); //执行:a[m][n]*b[m][n]=c[m][n]
    void output(); //输出c[m][n]到文件
    ~trMinus() //析构函数 delete空间
    {
        int i;
        for (i = 0; i<m; i++)
        {
            delete[] a[i];
        }
        delete[] a;
        for (i = 0; i<n; i++)
        {
            delete[] b[i];
        }
        delete[] b;
        for (i = 0; i<m; i++)
        {
            delete[] c[i];
        }
        delete[] c;
    }
};
void trMinus::input() //从文件读入矩阵A与B
{
    int i, j;
    char str1[20];
    ifstream fin;
    fin.open("trMinus.dat", ios::in);
//ifstream fin("trMinus.dat");
    strcpy(str1, "trMinus.dat");
    if (!fin)
    {
        cout << "\n不能打开这个文件 " << str1 << endl;
        exit(1);
    }
    for (i = 0; i < m; i++) //读入矩阵A
    {
        for (j = 0; j < n; j++)
        {
            fin >> a[i][j];
        }
    }
    for (i = 0; i < m; i++) //读入矩阵B
    {
        for (j = 0; j < n; j++)
        {
            fin >> b[i][j];
        }
    }
    fin.close();
}
void trMinus::add() //执行a[m][n]+b[m][n]=c[m][n]
{
    int i, j, t;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            c[i][j] = a[i][j] - b[i][j];
        }
    }
}
void trMinus::output() //矩阵C写到文件
{
    int i, j;
    char str2[20];
    ofstream fout;
    fout.open("out.txt", ios::out);
    strcpy(str2, "out.txt");
    if (!fout)
    {
        cout << "\n不能打开这个文件 " << str2 << endl;
        exit(1);
    }
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
//fout << " " << c[i][j];
//cout << " " << c[i][j];
            fout << setw(10) << setprecision(5) << c[i][j];
            cout << setw(10) << setprecision(4) << c[i][j];
        }
        fout << endl; cout << endl;
    }
    fout.close();
}
int main() //主函数
{
    trMinus c(4, 5);
    c.input(); //从文件读入矩阵A和B
    c.add(); //执行C=AB
    c.output(); //输出矩阵C到文件
    return 0;
}

//https://blog.csdn.net/sinat_32602421/article/details/105848664