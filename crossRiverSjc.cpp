//
// Created by Lenovo on 2021/1/3.
//

#include<stdio.h>
#include<iostream>
#include <string>
using namespace std;
const int MAX = 111;
const int inf=0x7fffff;
int dist[MAX]; 		//保存最小的
int collected[MAX];		//保存是否已经收录 0表示未收录，1表示一收录
int weight[MAX][MAX];
int vis[MAX];
int path[MAX];
int pathCnt;
void printRec(){//
    for(int i= 0; i<pathCnt; i++){
        printf("%d %d\n",path[i],15-path[i]);
    }
}
//独自过河时1***->0*** 即为start-带狼过河就是11**->00**,start-12
//start+cross[]/start+back[]表示下个节点
//带自己过河就是-8 ，带着狼过河就是-8-4==-12
int cross[4]={-8,-12,-10,-9};
int back[4] ={8,12,10,9};
int flag = 0;
//有人开始写了吗？我写了一段时间了，提供一下我的思路，但是感觉有一点问题，一共十个点，可以直接这样写就把联通情况给手写完，就不用程序来算了，
//int a[12]={0,15,5,13,1,11,2,10,0 };
//weight[13][4] = weight[4][13] = weight[4][14] = weight[14][4] = weight[14][2] = weight[2][14] = 1;
//for(int i=1;i<11;i++){
//weight[i][i+1]=weight[i+1][i]=1;
//}
//然后用dijkstra找最短路径，但是还有好多问题，比如说有多个解，也就是dijkstra里面找最小值的那个要按题目的方式改，
// 还有打印输出我现在写的是用father[]递归输出，但是还没写，有点效率低下了，干别的事去了
void DFS(int start,int end){
    //如果搜索的点找到了，应该返回，打印输出前面的路径，  和其他操作？
    if(start == end ) {
        //相应的操作；
        path[pathCnt] = end;
        if(flag != 0 ) printf("\n");
        flag = 1;
        printRec();
        return;
    }
    else{
        //如果是方向的话，会枚举方向
        for(int i=0; i<4; i++) {
            //枚举加方向的新坐标；
            //界限 ：例如：不能出到地图外，有障碍，已经访问过
            int nextState;
//            这个是判断一个值是不是大于8，然后做出相应的移动
//            就是如果大于8就可以-8也就是人移动，如果大于12 也就是可以人和狼移动
//因为cross 里面都是负数 所以要*-1
//            但是这个算是初步判断吧，后面还有一个判断是判断有没有连接的边
            if(start>=-1*cross[i]) nextState = start+cross[i];
            else if(start <=15-back[i])nextState =start+back[i];
//            15-8 ==7 0111 ，15-12==3 ，0011 ，这边人不在 需要人回来
            if(weight[start][nextState]==inf||weight[start][nextState]!=1||vis[nextState]) continue;
//            weight=1 之前设置的意思是说 这两种转化 是可能的吗 也就是说不是1 的 就是不可能的转化
                //设置已经访问新坐标；
            else{
                vis[nextState] = 1;
                path[pathCnt] = nextState;
                pathCnt++;
//                1 2 3  cnt
//                    printf("nextState=%d, end%d\n",nextState,end);
                printf("start = %d pathCnt =%d nextState=%d n-s= %d\n", start, pathCnt, nextState,nextState-start);
                DFS(nextState,end);
                vis[nextState] = 0;
                pathCnt--;
//                cnt --
//                1 2 3
//                    cnt
            }
        }
    }
}

void init(){

    int a[9]={0,15,5,13,1,11,2,10,0 };

    for(int i=0;i<=11;i++){
        for(int j=0; j<=11; j++){
            weight[i][j] = inf;
        }
    }
    for(int i=1;i<8;i++){
        weight[a[i]][a[i+1]]=weight[a[i+1]][a[i]]=1;
//        15 5 == 5 15 ==1，0xf 0b1111
//
// 5  0b101 狼 菜 ， 13  0xd  0b1101,人狼 菜  ==1
    }
    weight[13][4] = weight[4][13] = weight[4][14] = weight[14][4] = weight[14][2] = weight[2][14] = 1;
}
int main(void){
    init();
    char startL[13],endL[13];
    cin.getline(startL,13);
    cin.getline(endL,13);
//	cout << startL  << endl<< endL << endl;
    int start = 0,end = 0;
    for(int i=0; i<4;i++){
        if(startL[i]!='.') start=start*2+1;
        else start = start * 2;
        if(endL[i]!='.') end = end*2+1;
        else end = end * 2;
    }
    int startDirct, endDirct;
//	cout << start << endl<< end << endl;
    path[pathCnt] = start;
    pathCnt++;
    vis[start] = 1;
    DFS(start,end);
    if(flag ==0) printf("None");

}
