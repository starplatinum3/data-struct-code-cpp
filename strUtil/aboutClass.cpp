//
// Created by Lenovo on 2020/9/27.
//

#include <iostream>

class A {
private:
    A();

/* data */
    int v;

public:
    int publicNum;

    explicit A(int n);

    ~A();

    int getV() { return v; }

    int getPublicNum() {
        return publicNum;
    }
};

A::~A() = default;

A::A() {
    v = 1;
    publicNum = 1;
}

A::A(int n) {
    v = n;
    publicNum = n + 2;
}

int testClass() {
    //   A *p = new A();
    A *p = new A(1);

    printf("%d\n", p->getV());
    printf("%d\n", p->getPublicNum());
    printf("%d\n", p->publicNum);
//    printf("1");
    return 0;
}

class MyObject  {

};