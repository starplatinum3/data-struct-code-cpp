
# import readline


# from cgitb import small


def read_list():
    return list(map(int,input().split()))

def oneTest():
    n=int(input())
    print("n",n)
    bigger=0
    smaller=0
    # a=list(map(input().split()))
    # b=list(map(input()))
    a=read_list()
    b=read_list()
    print(a)
    print(b)
    maxn=0
    # for i in range(n):
    #     if b[i]>a[i]:
    #         bigger+=1
    #     elif a[i]>b[i]:
    #         smaller+=1
    now_trend="big"
    for i in range(n-1):
        if a[i]<a[i+1] and b[i]<b[i+1]  :
            
            smaller=0
            print("bigg")
            print("i",i)
            now_trend
            if now_trend=="big":
                bigger+=1
                maxn=max(maxn,bigger)

        elif a[i]>a[i+1] and b[i]>b[i+1]  :
            smaller+=1
            maxn=max(maxn,smaller)
            bigger=0


        # if b[i]>a[i]:
        #     bigger+=1
        # elif a[i]>b[i]:
            # smaller+=1
    # print("bigger")
    # print(bigger)
    # print("smaller")
    # print(smaller)
    # print(max(bigger,smaller))
    print("maxn")
    print(maxn)


T=int(input())
# https://www.nowcoder.com/test/question/a55198d2e65746009110226f2f6c8533?pid=30440638&tid=53127386
while T>0:
    T-=1
    oneTest()
    