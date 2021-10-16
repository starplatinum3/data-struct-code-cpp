

void adjustDown(int low,int high){
  int i=low;
  int j=i*2;
  while (j<=high)
  {
      if(j+1<=n&&a[j]<a[j+1])j++;
      /* code */
      if(a[i]<a[j]){
          swap(a[i],a[j]);
          i=j;
          j=i*2;
      }else break;
  }
  
}

int main(){
    int i;
    for( i=n;i>=0&&a[i]>=a[1];i--);
    swap(a[i],a[1]);
    adjustDown(1,i-1);
}