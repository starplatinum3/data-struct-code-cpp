#include<stdio.h>

#include<stdlib.h>

#include<string.h>//��Ҫ�õ�strcmp����

#define N 1000//���ѧ������



int n=0,t=1;//n����ǰѧ������,t�����������������ִ�У��Լ�������˳�;



//��������

void menu();//���˵�����

//int add();//����ѧ����Ϣ
int add(int studentCnt);//����ѧ����Ϣ

void look(int studentCnt);//���

//void seek();//����ѧ����Ϣ

//void cancel();//ɾ��ѧ����Ϣ

//void modify();//�޸�ѧ����Ϣ

//void exit();//�˳�����



struct Student

{

    char id[100],academy[100],majoy[100],grade[100],name[100];

//ѧ��������Ϣ

    int time[N][100];

    char rname[N][100],rgrade[N][100],adviser[N][100],department[N][100];

//ѧ������Ϣ

}stu[N];



int main()

{

    char chioce;//chioce�ǲ˵�ѡ��
    int studentCnt=0;
//    ѧ��������i ��

    while(t)//t��ȫ�ֱ�������exit����������ѭ���Ƿ����

    {

        menu();//������˵�����

        printf("���ã�������˵���ţ�");

        scanf("%s",&chioce);

        switch(chioce)

        {

            case 'a': studentCnt=add(studentCnt); break;

            case 'b': look(studentCnt); break;

//	case 'c': seek(); break;

//	case 'd': cancel(); break;

//	case 'e': modify(); break;

//	case 'f': exit(); break;

            default:printf("�����������������룡\n");

        }

    }

    system("pause");

    return 0;

}
int part;
//���part �ŵ�ȫ����
//��Ȼ menu���������

void menu()
{
    printf("**��ѡ����Ҫ�޸ĵĲ���**\n");
    printf("********1.ѧԺ**********\n");
    printf("********2.רҵ**********\n");
    printf("********3.�꼶**********\n");
    printf("********4.ѧ��**********\n");
    printf("********5.����**********\n");
//    part ������add �������� ����Ϳ�������
//  �򵥵Ĵ���Ļ� �ͷ���ȫ����
    scanf("%d",&part);
}

void look(int studentCnt)
{
    int k;
    //    ѧ��������i �� �ڱ�ĺ������棬�����ǽӴ������ģ�
//    ����Ҫ�ò���������
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
//�����������վ������
//add Ҫ���� studentCnt
int add(int studentCnt)
{
//    ,part;
//���part �ŵ�ȫ����
//    int i=0,j;
    int i=studentCnt,j;
//    ÿ�ν��� add i����0 ��ʼ �����൱��û����
//���� ���i ҲҪ����ȫ�֣� ����ÿ�ζ�ͨ������ ���� ������

    //i��������ѧ����Ϣ����������ʱ�̵�ѧ������
    char cheak;
    printf("�������ѧ��:");
    scanf("%s",stu[i].id);
//�ж�ѧ���Ƿ��Ѿ�����

    for(j=1;j<100;j++)
    {
        if(strcmp(stu[i].id,stu[j].id)!=0)
        {
            printf("��ѧ����Ϣδ����!\n");
            printf("������ѧ����ѧԺ��רҵ���꼶��ѧ�ţ���������ʾ�������ÿһ���Զ��Ÿ�����\n");
            scanf("%s,%s,%s,%s,%s",stu[j].id,stu[j].academy,stu[j].majoy,stu[j].grade,stu[j].name);
            printf("�������ѧ���Ļ�ʱ�䣬�������ƣ��񽱵ȼ���ָ����ʦ���ڽ����ţ���ʾ�������ÿһ���Զ��Ÿ�����\n");
            scanf("%d,%s,%s,%s,%s",&stu[j].time,stu[j].rname[N],stu[j].rgrade[N],stu[j].adviser[N],stu[j].department[N]);
            break;
        }

        if(j>=1&&strcmp(stu[i].id,stu[j].id)==0)
        {
            printf("��ѧ���Ļ�����Ϣ�Ѿ��Ѿ����ڣ���˶�������Ϣ�Ƿ���ȷ����ȷ�����롮T��,���������롮F��!\n");
            printf("%s,%s,%s,%s,%s\n",stu[j].id,stu[j].academy,stu[j].majoy,stu[j].grade,stu[j].name);
            scanf("%s",&cheak);
            if(cheak=='T')
            {
                printf("�������ѧ���Ļ�ʱ�䣬�������ƣ��񽱵ȼ���ָ����ʦ���ڽ����ţ���ʾ�������ÿһ���Զ��Ÿ�����\n");
                scanf("%d,%s,%s,%s,%s",&stu[j].time,stu[j].rname,stu[j].rgrade,stu[j].adviser,stu[j].department);
            }
            if(cheak=='F')break;
        }
    }

    i++;//iΪ����ӹ���ͬѧ��������
    printf("����1������Ϣ��\n\n");
    system("pause");
    return (i);//����һ�������������
}
