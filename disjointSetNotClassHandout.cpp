//
// Created by Lenovo on 2020/10/29.
//


#include <stdio.h>


const int maxn = 1000010;
const int MAX_STU_NUM = 30000;
int maxPersonCnt = 0;
int f[maxn];
int howManyPersons[maxn + 1];

void initWithPersonCnt() {
    int i;
    for (i = 0; i <= maxn; i++) {
        f[i] = i;
        howManyPersons[i] = 1;
    }
}

int find(int x, int fatherSet[]) {
    if (x != fatherSet[x])
        return fatherSet[x] = find(fatherSet[x], fatherSet);
    else
        return x;
}


int find(int x) {
    return find(x, f);
}

void uniteWithPersonCnt(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx != fy) {
        howManyPersons[fy] += howManyPersons[fx];
        howManyPersons[fx] = 0;
        if (howManyPersons[fy] > maxPersonCnt)
            maxPersonCnt = howManyPersons[fy];
        f[fx] = fy;
    }
}

#include <stdlib.h>
#include <cstring>
#include <vector>


//获得最大集团里面有多少人的个数
/**
 * 获得最大集团里面有多少人的个数
 * @param fromIndex 从哪个人开始找，这个是他的编号
 * @param toIndex 找到哪个人为止，这个是他的编号
 * @param fatherSet 并查集的集合，如果提供一个null的话，用的是全局变量的f，不然就是传进来的这个
 * 主要是find(i, fatherSet) 函数的区别
 * @return 获得最大集团里面有多少人的个数
 */
int getCountOfBiggestSet(int fromIndex, int toIndex, int fatherSet[]) {
//        输出给出一个整数，表示在最大朋友圈中有多少人。
    int kingHaveHowManyServants[MAX_STU_NUM];
    memset(kingHaveHowManyServants, 0, sizeof(int) * MAX_STU_NUM);
    for (int i = fromIndex; i <= toIndex; i++) {
//        f[i] is  i's father ,不一定的，有些好像还没有设置为他的最大的老大哥, how many the father king of all them
        int fatherNum;
        if (fatherSet) {
            fatherNum = find(i, fatherSet);
        } else {
            fatherNum = find(i);
        }

        kingHaveHowManyServants[fatherNum]++;

    }
    int maxCount = kingHaveHowManyServants[0];
    for (int i = 1; i < MAX_STU_NUM; i++) {
        if (maxCount < kingHaveHowManyServants[i])maxCount = kingHaveHowManyServants[i];
    }
    return maxCount;
}


#include <algorithm>
#include <functional>

bool haveSameHobby(const std::vector<int>& person1, std::vector<int> person2) {
    for (int hobby:person1) {
        if (std::find(person2.begin(), person2.end(), hobby) != person2.end()) {
            return true;
        }
    }
    return false;
}

int getCountOfSets(int n) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
//        找到它的大王就是他自己，那就是一个集合了
        if (find(i) == i) {
            cnt++;
        }
    }
    return cnt;
}

//7-1 社交集群 (30分)
void socialSet() {
    int n;
//      分别代表学校的学生总数和俱乐部的个数
    scanf("%d", &n);

    initWithPersonCnt();
//    ，n 为社交网络平台注册的所有用户的人数

    using namespace std;
    vector<vector<int>> persons(n + 1);
    for (int i = 1; i <= n; i++) {
        int howMany;
        scanf("%d:", &howMany);
        for (int j = 0; j < howMany; j++) {
            int hobby;
            scanf("%d", &hobby);
            persons[i].push_back(hobby);

        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (i != j && haveSameHobby(persons[i], persons[j]))
                uniteWithPersonCnt(i, j);
        }

    }
//    首先在一行中输出不同的社交集群的个数。随后第二行按非增序输出每个集群中的人数。
//    数字间以一个空格分隔，行末不得有多余空格。

    int cnt = getCountOfSets(n);

    vector<int> setCounts;
    printf("%d\n", cnt);
    for (int i = 1; i <= n; i++) {

        if (howManyPersons[i] > 0) {
            setCounts.emplace_back(howManyPersons[i]);

        }
    }
//    https://blog.csdn.net/lytwy123/article/details/84503492
    sort(setCounts.begin(), setCounts.end(), std::greater<>());
    int first=1;
    for (int setCount:setCounts) {
        if(first){
            printf("%d", setCount);
            first=0;
        }else{
            printf(" %d", setCount);
        }


    }

}

int main(){
     socialSet() ;
}