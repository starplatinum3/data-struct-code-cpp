function bubbleSort(array){
    for (let i = 0; i < array.length-1; i++) {
        // const element = array[i];
        for (let j = i+1; j < array.length-1; j++) {
            // const element = array[j];
            if(array[i]>array[j]){
                let temp=  array[i]

              array[i]=array[j]
              array[j]=temp
            //   https://zhuanlan.zhihu.com/p/101522204
            }
        }
        
    }
}