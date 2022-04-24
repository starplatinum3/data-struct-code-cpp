#include <stdio.h>
char curr;
char YF[300];
int N = -1;

void T();
void E();
void F();
void e();
void t();
void error();
void scaner();

int main()
{
    char ch;
    int i = 0;
    printf("请输入需要分析的curr语法：(以#结束)\n");
    do
    {
        scanf("%c", &ch);
        YF[i] = ch;
        i++;
    } while (ch != '#');
    scaner();
    E();
    if (curr == '#')
        printf("成功！\n");
    else
    {
        printf("文法有误！！\n");
        error();
    }
}

void scaner()
{

    N++;
    if (YF[N] == ' ')
    {
        N++;
    }
    else
    {
        curr = YF[N];
    }
}

void E()
{
    T();
    e();
}
void T()
{
    F();
    t();
}

void e()
{
    if (curr == '+')
    {
        scaner();
        T();
        e();
    }
    else if (curr == '-')
    {
        scaner();
        T();
        e();
    }
    else if (YF[N + 1] == '#' || YF[N + 1] == '+' || YF[N + 1] == '/' || YF[N + 1] == '*' || YF[N + 1] == '-')
    {
        if (YF[N] != '(' && YF[N] != ')')
            error();
    }
}

void t()
{
    if (curr == '*')
    {
        scaner();
        F();
        T();
    }
    else if (curr == '/')
    {
        scaner();
        F();
        T();
    }
    else if (YF[N + 1] == '#' || YF[N + 1] == '+' || YF[N + 1] == '/' || YF[N + 1] == '*' || YF[N + 1] == '-')
    {
        if (YF[N] != '(' && YF[N] != ')')
            error();
    }
}
//LIE ZHI HUA TI GONG TAI MA
// 劣质化提供泰马
// 劣质话题共泰马
// 雷志华 提供代码
void F()
{
    if (curr == '(')
    {
        scaner();
        E();
        if (curr == ')')
        {
            scaner();
            // printf("111111");
        }
        else
        {
            error();
        }
    }
    else
    {
        while (1)
        {
            if (curr >= 'a' && curr <= 'z' || curr >= 'A' && curr <= 'Z' || curr >= '0' && curr <= '9')
            {
                scaner();
            }
            else
            {
                break;
            }
        }
    }
}

void error()
{
    printf("%d %c之后的文法有错！\n", N, curr);
}