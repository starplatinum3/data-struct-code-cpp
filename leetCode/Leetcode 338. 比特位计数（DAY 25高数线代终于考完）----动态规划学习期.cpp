/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* countBits(int num, int* returnSize){
    (*returnSize) = num+1;
    int i,count,temp;
    int* ret = (int*)malloc(sizeof(int) * (num+1));
    for(i=0;i<=num;i++)
    {
        count = 0;
        // 是 0  他是第一个 
        if(!i)
            ret[i] = i;
        else
        {
            temp = i;
            while(temp)
            {
                temp &= (temp-1);
                count++;
            }
            ret[i] = count;
        }
    }
    return ret;
}
