#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

const int N = 1e5+4;

int c[N];

void update(int x,int val){
   for(int i=x;i<N;i+= (i &-i))
       c[i]+=val;
}
int sum(int x){
   int res= 0;
   for(int i=x;i;i-=(i&-i))res+=c[i];
   return res;
}
int get(int x){
   int l =0;  int r= N;
   int ans;
   while(l<=r){
       int mid =(l+r)>>1;
       if(sum(mid) >=x){
           ans = mid;
           r = mid-1;
       }
       else l=mid+1;
   }
   return ans;
}


int main(){

   int n;
   cin>>n;
   char op[222];

   stack<int>S;

   while(n--){
       scanf("%s",op);
       //pop
       if(op[1]=='o'){
           if(S.size()){
               printf("%d\n",S.top());
               update(S.top(),-1);
               S.pop();
           }
           else {
               printf("Invalid\n");
           }
       }
       else if(op[1]=='e'){
           if(S.size()){
               int len  =S.size();
               printf("%d\n",get( (len+1)/2 )  );
           }
           else   printf("Invalid\n");
       }
       //push
       else if(op[1]=='u'){
           int x;
           scanf("%d",&x);
           update(x,1);
           S.push(x);
       }

   }

   return 0;
}

