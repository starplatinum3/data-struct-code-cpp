
int n;
const int N=1e4;
int s[N],a[N];

void rulerGet(){
    int sho=111;
  for(int i=0;i<n;i++){
      int st=0;
      s[i]=s[i-1]+a[i];
      while(s[i]-s[st]>sho){
  st++;
      }
  }
}