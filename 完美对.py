# from idna import valid_contextj


# from operator import le

def read_line_ints():
    line=input()
    vals=line.split(" ")
    vals_int=map(int,vals)
    vals_int=list(vals_int)
    return vals_int


line=input()
vals=line.split(" ")
vals_int=map(int,vals)
vals_int=list(vals_int)
# https://blog.csdn.net/vocaloid01/article/details/77484548
# TypeError: 'map' object is not subscriptable
# print("vals_int")
# print(vals_int)
n=vals_int[0]
k=vals_int[1]
mat=[]
for i in range(n):
    mat.append([])
    for j in range(k):
        mat[i].append(0)

for i in range(n):
    # line=input()
    # vals=line.split(" ")
    # vals_int=map(int,vals)
    vals_int=read_line_ints()
    # print("vals_int")
    # print(vals_int)
    mat[i]=vals_int


def perfect_line(line1,line2):
    sum=line1[0]+line2[0]
    for i in range(len(line1)):
        temp_sum=line1[i]+line2[i]
        if temp_sum!=sum:
            return False
    
    return True
        
cnt=0
for i in range(n):
    for j in range(i+1,n):
        if i==j:
            continue
        if perfect_line(mat[i],mat[j]):
            cnt+=1

print(cnt)