

void longestNotDeqSeq(){
    for(int i=0;i<n;i++){
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(a[i]>=a[j]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        maxx=max(maxx,dp[i]);
    }
}