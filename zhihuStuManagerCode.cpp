#include<stdio.h>

#include<stdlib.h>

#include<string.h>//需要用到strcmp函数

#define N 1000//最大学生人数



int n=0,t=1;//n代表当前学生人数,t用来控制整个程序的执行，以及程序的退出;



//函数声明

void menu();//主菜单函数

//int add();//增加学生信息
int add(int studentCnt);//增加学生信息

void look(int studentCnt);//浏览

//void seek();//查找学生信息

//void cancel();//删除学生信息

//void modify();//修改学生信息

//void exit();//退出函数



struct Student

{

    char id[100],academy[100],majoy[100],grade[100],name[100];

//学生基本信息

    int time[N][100];

    char rname[N][100],rgrade[N][100],adviser[N][100],department[N][100];

//学生获奖信息

}stu[N];



int main()

{

    char chioce;//chioce是菜单选项
    int studentCnt=0;
//    学生数量的i ，

    while(t)//t是全局变量，用exit函数来控制循环是否继续

    {

        menu();//输出主菜单界面

        printf("您好，请输入菜单编号：");

        scanf("%s",&chioce);

        switch(chioce)

        {

            case 'a': studentCnt=add(studentCnt); break;

            case 'b': look(studentCnt); break;

//	case 'c': seek(); break;

//	case 'd': cancel(); break;

//	case 'e': modify(); break;

//	case 'f': exit(); break;

            default:printf("输入有误，请重新输入！\n");

        }

    }

    system("pause");

    return 0;

}
int part;
//这个part 放到全局了
//不然 menu里面读不到

void menu()
{
    printf("**请选择需要修改的部分**\n");
    printf("********1.学院**********\n");
    printf("********2.专业**********\n");
    printf("********3.年级**********\n");
    printf("********4.学号**********\n");
    printf("********5.姓名**********\n");
//    part 定义在add 函数里面 这里就看不到了
//  简单的处理的话 就放在全局了
    scanf("%d",&part);
}

void look(int studentCnt)
{
    int k;
    //    学生数量的i ， 在别的函数里面，这里是接触不到的，
//    所以要用参数传进来
//    for(k=0;k<i;k++)
    for(k=0;k<studentCnt;k++)
    {
        printf("%s,%s,%s,%s,%s,%d,%s,%s,%s,%s\n",stu[k].id,stu[k].academy,stu[k].majoy,stu[k].grade,stu[k].name,stu[k].time,stu[k].rname,stu[k].rgrade,stu[k].adviser,stu[k].department);
    }
}


/*void modify(int add)
{
int k,z,j=0;
for(k=0;k<z;k++)
{
scanf("%s,%s,%s,%s,%s",&stu[j].id,&stu[j].academy,&stu[j].majoy,&stu[j].grade,&stu[j].name);
scanf("%d,%s,%s,%s,%s",&stu[j].time,&stu[j].rname,&stu[j].rgrade,&stu[j].adviser,&stu[j].department);
printf("\n");
j++;
}
}*/

//https://paste.ubuntu.com/
//建议在这个网站贴代码
//add 要传入 studentCnt
int add(int studentCnt)
{
//    ,part;
//这个part 放到全局了
//    int i=0,j;
    int i=studentCnt,j;
//    每次进入 add i都从0 开始 所以相当于没增加
//所以 这个i 也要放在全局， 或者每次都通过函数 参数 传进来

    //i代表增加学生信息过程中任意时刻的学生人数
    char cheak;
    printf("请输入的学号:");
    scanf("%s",stu[i].id);
//判断学号是否已经存在

    for(j=1;j<100;j++)
    {
        if(strcmp(stu[i].id,stu[j].id)!=0)
        {
            printf("该学生信息未存入!\n");
            printf("请输入学生的学院，专业，年级，学号，姓名（提示：输入的每一项以逗号隔开）\n");
            scanf("%s,%s,%s,%s,%s",stu[j].id,stu[j].academy,stu[j].majoy,stu[j].grade,stu[j].name);
            printf("请输入该学生的获奖时间，竞赛名称，获奖等级，指导老师，授奖部门（提示：输入的每一项以逗号隔开）\n");
            scanf("%d,%s,%s,%s,%s",&stu[j].time,stu[j].rname[N],stu[j].rgrade[N],stu[j].adviser[N],stu[j].department[N]);
            break;
        }

        if(j>=1&&strcmp(stu[i].id,stu[j].id)==0)
        {
            printf("该学生的基本信息已经已经存在，请核对如下信息是否正确，正确请输入‘T’,错误请输入‘F’!\n");
            printf("%s,%s,%s,%s,%s\n",stu[j].id,stu[j].academy,stu[j].majoy,stu[j].grade,stu[j].name);
            scanf("%s",&cheak);
            if(cheak=='T')
            {
                printf("请输入该学生的获奖时间，竞赛名称，获奖等级，指导老师，授奖部门（提示：输入的每一项以逗号隔开）\n");
                scanf("%d,%s,%s,%s,%s",&stu[j].time,stu[j].rname,stu[j].rgrade,stu[j].adviser,stu[j].department);
            }
            if(cheak=='F')break;
        }
    }

    i++;//i为所添加过的同学的总人数
    printf("输入1条获奖信息！\n\n");
    system("pause");
    return (i);//返回一共输入的总人数
}
