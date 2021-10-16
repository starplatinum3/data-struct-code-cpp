

int eularRoad(){
   int  odd=0;
    for(int i=0;i<n;i++){
        if(g[i].size()&1){
odd++;
        }
    }
    if(odd==0){
        printf("eular ");
    }else if(odd==2){
        printf("sem -eular");
    }
}