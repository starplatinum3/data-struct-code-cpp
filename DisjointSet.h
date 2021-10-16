//
// Created by Lenovo on 2020/11/13.
//

#ifndef DATASTRUCT_DISJOINTSET_H
#define DATASTRUCT_DISJOINTSET_H

#include <cstdio>
#include <vector>

class DisjointSet {
private:
//    https://www.pianshen.com/article/6430679051/
//    IDEA 如何批量修改变量名
// shift f6
    static const int MAXN = 1000010;
    const int MAX_STU_NUM = 30000;
    int maxPersonCnt = 0;
    int f[MAXN]{};
    int howManyPersons[MAXN + 1]{};
public:
    DisjointSet();

    explicit DisjointSet(bool havePersonCnt);

public:
    void init();

    void initWithPersonCnt(int howMany[]);

    void initWithPersonCnt();

    int find(int x, int fatherSet[]);

    int find(int x);

    void unite(int x, int y);

    void uniteWithPersonCnt(int x, int y, int howMany[]);

    void uniteWithPersonCnt(int x, int y);

//    直接复制一大段函数，会直接卡死，很可怕
    int getCountOfBiggestSet(int fromIndex, int toIndex, int fatherSet[]);

    void uniteVector(std::vector<int> v);

    bool haveSameHobby(const std::vector<int>& person1, std::vector<int> person2);

    int getCountOfSets(int n);

    void socialSet();
};


#endif //DATASTRUCT_DISJOINTSET_H
