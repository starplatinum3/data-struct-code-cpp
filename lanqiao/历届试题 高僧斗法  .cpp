//
// Created by Lenovo on 2021/2/22.
//

//https://www.cnblogs.com/yuyixingkong/p/4395055.html

#include<stdio.h>
#include "util/printUtilNotClass.h"

int main() {

//    int testNum=2;
//    printf("testNum^testNum : %d\n",testNum^testNum);

    int a[105] = {0};
    int b[105] = {0};
    int i = 0;
    char ch;
    while (1) {
        ch = getchar();
        if (ch == '\n')break;
        if (ch == ' ') i++;
        else
            a[i] = a[i] * 10 + (ch - '0');
    }
    int len = i + 1;
    if (len & 1) a[len++] = a[i] + 1;
    int aLen = len;
    i = 0;
    for (int j = 0; j < len; j += 2) {
//        8-5-1
//5-1 -1==3
//9  孤单一个 就当作0了
        b[i++] = a[j + 1] - a[j] - 1;
    }
    int bLen = i;
//len b 的长度
    printf("=============\n");
    printf("b\n");
    printArr(b, bLen);
    printf("=============\n");
    printf("a\n");
    printArr(a, aLen);

    printf("=============\n");

    int ans = 0;
    for (int j = 0; j < i; j++) {
        ans ^= b[j];
    }
    if (ans == 0) printf("-1\n");
    else {
        //      printf("%d\n",ans);
        int tp = 0;
//        尝试变成 平衡态
//        若有多个解，输出A值较小的解， （所以从小开始尝试
//        1 5 8 10 14 16 17
//        1 5 8 10 13 16 17
//        1 5 8 10 12 16 17
        for (int j = 0; j < len; j++) {
//            这里 j+1 没事吗
            printf("k=(%d,%d)\n", a[j], a[j + 1]);
//            k 尝试走几步？ 移动到B位置。    1    5    8   10 ,不能是原来有人站着的地方， 会占位置，堵住

            for (int k = a[j] + 1; k < a[j + 1]; k++) {
                printf("----------\n");
                printf("k: %d\n", k);
//                1    5    8   10
//j 奇数 是走到 5 10 这种， 假如走到5 吧， k 可以是2 3 4
                if (j % 2) {
//                    奇数 ，往左走，走不到 a[j-1] 位置的， 只能到a[j-1]+1 位置，所以还要-1  。(k - a[j - 1] - 1);
//其实也不是往左走 应该是左边的往右走 比如 1--->
                    printf("j 是奇数, j:%d\n", j);
                    printf("b[j/2]: %d, k-a[j-1]-1:%d\n", b[j / 2], k - a[j - 1] - 1);
                    printf("k: %d, a[j-1] :%d\n", k, a[j - 1]);
                    int moveStep = (k - a[j - 1] - 1);
//                  移动到k 需要走的步数
//因为 1--5 8--10 配对，那么a下标 是j 的时候，对应的b 的位置就是j/2 了
//                    a
//                    1    5    8   10
//                    1   3） 5    8   10
//为什么5 --8 之间没有用呢
//                    1   3） 5    8   10
//因为 a^a==0 ，ans 原来 ^ 了一个b[j / 2]，现在要把他去掉 只要重新 ^ b[j / 2]，然后再用(k - a[j - 1] - 1)这个
//新的 距离替换
                    if ((ans ^ b[j / 2] ^ (k - a[j - 1] - 1)) == 0) {
//                        还有需要注意输出第一步的时候，可以变化1-5的距离，即缩小间距，也可以变化5-8的距离，即扩大间距。
                        printf("%d %d\n", a[j], k);
                        tp = 1;
                        break;
                    }

                } else {
                    printf("j 是偶数, j:%d\n", j);
                    printf("a[j+1] :%d\n", a[j + 1]);
                    int moveStepRight = (a[j + 1] - k - 1);
                    printf("b[j/2]: %d, moveStepRight :%d\n", b[j / 2], moveStepRight);
                    if ((ans ^ b[j / 2] ^ (a[j + 1] - k - 1)) == 0) {
//                    要从 1 走到5  之类的
//如果他从3 开始     1  3 ） 5    8   10
//本来要 走3步 从 1--> 4 现在 抵消了 1-->3 的， 所以只要走3-->4 的1 步， 抵消就是用 ^ ，1^1==0
//1
//                    printf("j 是偶数, j:%d\n", j);
//                    printf("a[j+1] :%d\n",a[j+1]);
//                    int moveStepRight=(a[j + 1] - k - 1);
//                    printf("b[j/2]: %d, moveStepRight :%d\n", b[j / 2], moveStepRight);
//                    表示把A位置的小和尚移动到B位置。
                        printf("%d %d\n", a[j], k);
                        tp = 1;
                        break;
                    }

                }
            }
            if (tp) break;
        }
    }
    return 0;
}