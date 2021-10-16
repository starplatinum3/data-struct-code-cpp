//
// Created by Lenovo on 2020/10/10.
//
#include <cstring>
#include<cstdio>

//const int MAXLEN = 1E6 + 10;
//char ptr[MAXLEN], str[MAXLEN];
//int next[MAXLEN];
//int *next;

void cal_next(const char *str, int *next, int len) {
    next[0] = -1;//next[0]初始化为-1，-1表示不存在相同的最大前缀和最大后缀
    int k = -1;//k初始化为-1
    for (int q = 1; q <= len - 1; q++) {
        while (k > -1 && str[k + 1] != str[q])
            //如果下一个不同，那么k就变成next[k]，注意next[k]是小于k的，无论k取任何值。
        {
            k = next[k];//往前回溯
        }
        //如果相同，k++
        if (str[k + 1] == str[q]) {
            k = k + 1;
        }
        next[q] = k;//这个是把算的k的值（就是相同的最大前缀和最大后缀长）赋给next[q]

    }
}
/**
 *
 * @param str 被查找的字符串
 * @param originStringLen  被查找的字符串的长度
 * @param pattenString  要找的字符串
 * @param patternStringLen 要找的字符串的长度
 * @return  返回相应的位置
 */
int KMP(const char *str, int originStringLen, char *pattenString, int patternStringLen) {
    int *next = new int[patternStringLen];
    cal_next(pattenString, next, patternStringLen);//计算next数组
    int k = -1;
    for (int i = 0; i < originStringLen; i++) {
        while (k > -1 && pattenString[k + 1] != str[i]) {
            k = next[k];//往前回溯
        }
        if (pattenString[k + 1] == str[i]) {
            k = k + 1;
        }
        if (k == patternStringLen - 1)//说明k移动到ptr的最末端
        {
            return i - patternStringLen + 1;//返回相应的位置
        }
    }
    return -1;
}


int KMP(char *str, char *pattenString ) {
   int originStringLen=strlen(str);
    int patternStringLen=strlen(pattenString);
    return   KMP(str, originStringLen, pattenString, patternStringLen);
}

void testKmp() {

    const int MAX_LEN = 1E6 + 10;
    char pattenString[MAX_LEN], str[MAX_LEN];

    printf("输入字符串");
    scanf("%s", str);
    int howManyTimes;
    printf("how many");
    scanf("%d", &howManyTimes);
    while (howManyTimes--) {
        int len, originStringLen, patternStringLen;
        printf("to find");
        scanf("%s", pattenString);
        patternStringLen = strlen(pattenString);
        originStringLen = strlen(str);
//        cal_next(pattenString, next, patternStringLen);
        int index = KMP(str, originStringLen, pattenString, patternStringLen);
        if (index == -1) {
            printf("Not Found\n");
        } else
            printf("%s\n", str + index);
    }
}
