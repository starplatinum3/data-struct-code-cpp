//
// Created by Lenovo on 2021/1/2.
//

#include <stdio.h>
#include <vector>
void CartesianProduct() ;
//int main() {
//    CartesianProduct();
//}

//笛卡尔积

std::vector<int> input(int num) {
    printf("input the ");
    printf(num == 1 ? "first" : "second");
    printf(" union.\n");
    printf("how much\n");
    int number;
    scanf("%d", &number);
    std::vector<int> v;
    printf("input %d numbers to the first union\n", number);
    for (int i = 0; i < number; i++) {
        int x;
        scanf("%d", &x);
        v.emplace_back(x);
    }
    return v;
}

void CartesianProduct() {

    std::vector<int> first;
    std::vector<int> second;
    first = input(1);
    second = input(2);
    printf("Cartesian Product of first and second\n");
    for(auto i:first){
        for(auto j:second){
            printf("<%d,%d>\n",i,j);
        }
    }



}
//笛卡尔和 自己造的一个概念
void CartesianSum(  const std::vector<int>& first, const std::vector<int>& second){
    printf("Cartesian Sum of first and second\n");
    for(auto i:first){
        for(auto j:second){
            printf("%d + %d == %d\n",i,j,i+j);
        }
    }
}

//笛卡尔减 自己造的一个概念
void CartesianMinus(  const std::vector<int>& first, const std::vector<int>& second){
    printf("Cartesian Sum of first and second\n");
    for(auto i:first){
        for(auto j:second){
            printf("%d - %d == %d\n",i,j,i-j);
        }
    }
}