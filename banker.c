#include<stdio.h>
#define true 1
#define false 0
#define processNum 5
#define resourceNum 3
#define MAXINT 9999
typedef int bool;

int available[resourceNum]={2,3,3};
// int available[resourceNum]={3,3,2};
// int maxRequest[processNum][resourceNum]={7,5,3,3,2,2,9,0,2,2,2,2,4,3,3};
int maxRequest[processNum][resourceNum]={{5,5,9},{5,3,6},{4,0,11},{4,2,5}
,{4,2,4}};
// int allocation[processNum][resourceNum]={0,1,0,2,0,0,3,0,2,2,1,1,0,0,2};

int allocation[processNum][resourceNum]={{2,1,2},{4,0,2}
,{4,0,5},{2,0,4},{3,1,4}};
int need[processNum][resourceNum]={7,4,3,1,2,2,6,0,0,0,1,1,4,3,1};
bool Finish[processNum];
int safeSeries[processNum]={MAXINT, MAXINT , MAXINT , MAXINT , MAXINT};
int request[resourceNum];

void Init()
{
    int i, j;
    printf("输入进程数量、资源数量\n");
    //scanf("%d %d",&processNum,&resourceNum);
    printf("输入当前资源可用数目\n");
    for(i = 0; i < resourceNum; i++){
        scanf("%d",&available[i]);
    }
    printf("输入最大需求矩阵\n");
    for(i = 0; i < processNum; i++){
        for(j = 0; j < resourceNum; j++){
            scanf("%d",&maxRequest[i][j]);
        }
    }
    printf("输入分配矩阵\n");
    for(i = 0; i < processNum; i++){
        for(j = 0; j < resourceNum; j++){
            scanf("%d",&allocation[i][j]);
        }
    }
    printf("输入当前需求矩阵\n");
    for(i = 0; i < processNum; i++){
        for(j = 0; j < resourceNum; j++){
            scanf("%d",&need[i][j]);
        }
    }
}

void showInfo()
{
    int i,j;
    printf("当前资源剩余：");
    for(j = 0; j < resourceNum; j++){
        printf("%d ",available[j]);
    }
    printf("\n");
    printf(" PID\t Max\t\tAllocation\tNeed\n");
    for(i = 0; i < processNum; i++){
        printf(" P%d\t",i);
        for(j = 0; j < resourceNum; j++){
            printf("%d ",maxRequest[i][j]);
        }
        printf("\t\t");
        for(j = 0; j < resourceNum; j++){
            printf("%d ",allocation[i][j]);
        }
        printf("\t\t");
        for(j = 0; j < resourceNum; j++){
            printf("%d ",need[i][j]);
        }
        printf("\n");
    }
}

void printNeed(int row){
      for(int j = 0; j < resourceNum; j++){
               
                    printf("%d ",need[row][j]);
              
            }
            printf("\n");
}
// https://blog.csdn.net/qq_36260974/article/details/84404369
bool isSafe()
{
    int i,j,k;
    int trueFinished = 0;
    int work[resourceNum];
    for(i = 0; i < resourceNum; i++){
        work[i]=available[i];
    }

    for(i = 0; i < processNum; i++){
        Finish[i]=false;
    }
    i = 0;
    int temp = 0;
    while(trueFinished != processNum){
        int j =0;
        if(Finish[i]!= true){
//             printf("进程 %d 没有结束\n",i);
//             printf("need\n");
// printNeed(i);
            for(j = 0; j < resourceNum; j++){
                if(need[i][j] > work[j]){break;}
            }
        }
        if(j == resourceNum){
            Finish[i]=true;
            SafeInfo(work,i);
            for(k = 0; k < resourceNum; k++){
                work[k]+=allocation[i][k];
            }
            int k2;
            safeSeries[trueFinished++] = i;
        }
        i++;
        if(i >= processNum)
        {
            i = i % processNum;
            if(temp == trueFinished)
                break;
        }
        temp = trueFinished;
    }

    if(trueFinished == processNum){
        printf("\n系统安全！\n\n安全序列为：");
        for(i = 0; i < processNum; i++){
            printf("%d ",safeSeries[i]);
        }
        return true;
    }
    printf("******系统不安全！******\n");
    return false;
}

void SafeInfo(int *work, int i)
{
    int j;
    printf(" P%d\t",i);
    for(j = 0; j < resourceNum; j++){
        printf("%d ",work[j]);
    }
    printf("\t\t");
    for(j = 0; j < resourceNum; j++){
        printf("%d ",need[i][j]);
    }
    printf("\t ");
    for(j = 0; j < resourceNum; j++){
        printf("%d ",allocation[i][j]);
    }
    printf("\t\t");
    for(j = 0; j < resourceNum; j++){
        printf("%d ",allocation[i][j]+work[j]);
    }
    printf("\n");
}

// banker
int main()
{
    int i,j,curProcess;
    // int wheInit = 0;
    // printf("是否使用内置数据？0是，1否：");
    // scanf("%d",&wheInit);
    // if(wheInit)
    //     Init();  //可以不使用，选用内置的数据进行测试
    printf("---------------------------------------------------------\n");
    showInfo();
    printf("\n系统安全情况分析\n");
    printf(" PID\t Work\t\tNeed\tAllocation\tWork+Allocation\n");
    isSafe();
    // printf("\n循环怎么没开始?\n");
    while(true){
        printf("\n---------------------------------------------------------\n");
        printf("\n输入要分配的进程：");
        scanf("%d",&curProcess);
        printf("\n输入要分配给进程P%d的资源：",curProcess);
        for(j = 0; j < resourceNum; j++){
            scanf("%d", &request[j]);
        }
        // 　　(1) 如果 Requesti[j] ≤ Need[i,j]便转向步骤(2)；
        // 否则认为出错，因为它所需要的资源数已超过它所宣布的最大值。
        for(j = 0; j < resourceNum; j++){
            if(request[j] <= need[curProcess][j])continue;
            else{printf("ERROR！\n");break;}
        }
        if(j == resourceNum){
            for(j = 0; j < resourceNum; j++){
                if(request[j] <= need[curProcess][j])continue;
                else{printf("资源不足，等待中！\n");break;}
            }
            // 　　(2) 如果 Requesti[j] ≤ Available[j]，便转向步骤(3)；
            // 否则，表示尚无足够资源，Pi须等待。

            if(j == resourceNum){
                for(j = 0; j < resourceNum; j++){
                    available[j] -= request[j];
                    allocation[curProcess][j] += request[j];
                    need[curProcess][j] -= request[j];
                }
                printf("\n系统安全情况分析\n");
                printf(" PID\t Work\t\tNeed\tAllocation\tWork+Allocation\n");
                if(isSafe()){
                    printf("分配成功！\n");
                    showInfo();
                }else{
                    for(j = 0; j < resourceNum; j++){
                        available[j] += request[j];
                        allocation[curProcess][j] -= request[j];
                        need[curProcess][j] += request[j];
                    }
                    printf("分配失败！\n");
                    showInfo();
                }
            }
        }
    }
}
