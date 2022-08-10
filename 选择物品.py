
def read_line_ints():
    line=input()
    return list(map(int,line.split()))

path=[]
res=[]
def dfs(n,m,idx):
    if(len(path))==m:
        # 需要这么多数字
        res.append(path.copy())
        # print("path")
        # print(path)
        return
    for i in range(idx,n+1):
        path.append(i)
        dfs(n,m,i+1)
        path.pop()

n,m=read_line_ints()
# print("n : ",n)
# print("m : ",m)
dfs(n,m,1)

# print(res)

for line in res:
    for i in range(m):
        # print(line[i]+f"{line[i]} ")
        print(f"{line[i]} ",end="")
    print()
    # print(line[0],line[1])

# https://www.nowcoder.com/question/next?pid=30440590&qid=1664934&tid=53272716
# ac 