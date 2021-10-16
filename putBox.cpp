//
// Created by Lenovo on 2020/12/24.
//
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

class Thing {
    int size;
    int box;
public:
    Thing(int size) : size(size) {}

    int getSize() const {
        return size;
    }

    int getBox() const {
        return box;
    }

    void setSize(int size) {
        Thing::size = size;
    }

    void setBox(int box) {
        Thing::box = box;
    }
};

const int MAX_N = 107;
int s[MAX_N];
int space[MAX_N];
int n;
vector<Thing> things;

int findBoxEnough(int thingIndex) {
    for (int i = 0; i < n; i++) {
        if (space[i] >= things[thingIndex].getSize()) {
            things[thingIndex].setBox(i);
            space[i] -= things[thingIndex].getSize();
        }
    }
}

void putBox() {

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int size;
        scanf("%x", &size);
//        scanf("%d", s + i);
        things.emplace_back(size);
        space[i] = 100;
    }
//    for (int i = 0; i < n; i++) {
//        if (space[i] >= s[])
//    }
    for (int i = 0; i < things.size(); i++) {
        findBoxEnough(i);
    }

    for(auto t:things){
        printf("%d %d\n",t.getSize(),t.getBox());
    }

}

