//
// Created by Lenovo on 2020/11/15.
//

#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
const int Max = 1111;

bool haveSameElement(vector<int> &vector1, vector<int> &vector2);
void unite(int element1_i, int  element2_i);
int findFatherOf(int element);
int father[Max] = {0};
int numberOfunit[Max] = {0};
int main() {
    int userNumber;
    cin >> userNumber;
    using namespace std;
    // 初始化储存每个人的兴趣爱好列表
    vector<vector<int>> persons(userNumber + 1);
    for(int i=1; i<=userNumber; i++) {
        numberOfunit[i] = 1;
        father[i] = i;
    }
    /*初始化父亲节点，正常思路有两种，第一种提前想好整个算法的数据结构，第二种想到后过来写，那种更好呢？我用的是后者*/

    for (int i = 1; i <= userNumber; i++) {
        int howMany;
        scanf("%d:", &howMany);
        for (int j = 0; j < howMany; j++) {
            int hobby;
            scanf("%d", &hobby);
            persons[i].push_back(hobby);
        }
    }
    // 遍历每一个人的habit，使用并查集把有关系的集合装起来
    for(int i = 1; i < userNumber; i++ ){
        for(int j = i; j <= userNumber; j++){
            if(i != j && haveSameElement(persons[i], persons[j])){
                unite(i,j);
            }
        }
    }
//每个组有多少人
    sort(numberOfunit+1, numberOfunit+userNumber, std::greater<>());
//    for(int i=1; i<userNumber; i++){
//        printf("%d ",numberOfunit[i]);
//    }
    int cnt = 0;
//    因为后面是0 直接退出也没事
    for(int i=1; i<=userNumber&&numberOfunit[i]>0; i++){
        cnt++;
    }
    printf("%d\n",cnt);
    for(int i=1; i<=userNumber&&numberOfunit[i]>0; i++) {
        if(i==1)printf("%d", numberOfunit[i]);
        else printf(" %d", numberOfunit[i]);
    }
}
// 没有带father数组传递，由于使用全局变量fathe//TODO 函数复用性问题：缺少数组传递。
int findFatherOf(int element){
    if(father[element] == element) return element;
    return father[element];
//                   =findFatherOf(father[element]);
}
void unite(int element1_i, int  element2_i) {//TODO 函数复用性问题：缺少数组传递。
    int f1 = findFatherOf(element1_i);
    int f2 = findFatherOf(element2_i);
    if(f1 == f2) return;
    else {
        //随意的安排父亲，还有别的方法
        numberOfunit[f1] += numberOfunit[f2];
        numberOfunit[f2]=0; //为了最后判断方便
        father[f2] = f1;    //代码思路：需提前初始化，回到主体函数进行初始化
    }
}

bool haveSameElement(vector<int> &vector1, vector<int> &vector2) {
    for(int habit:vector1){
        // TODO 学习：所需知识vector的使用
        if(find(vector2.begin(),vector2.end(),habit) != vector2.end()){
            return true;
        }
    }
    return false;
}