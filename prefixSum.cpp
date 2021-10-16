

int sum(int l,int r){
    return s[r]-s[l-1];
}

int main(){
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
}