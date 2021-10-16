// 作者：Eagerming
// 链接：https://www.zhihu.com/question/39583780/answer/82140296
// 来源：知乎
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#define max 127


// 一个节点代表一个子矩阵
struct node
{
    int val; // 按位与后的值
    int count; // 当前块中1的个数
    int* rows; // 行数
    int rown; // 行号
    int* cols; // 列号
    int coln; // 列数
    struct node* next;//哈希表同一个hash值中的下一个
};

struct hashTable
{
    struct node* list[max]; // Hash表
    struct node* topNode; // 当前块中1的个数最多的节点
};

struct node* hashFind(const struct hashTable* table, const struct node* iterator);
void hashInsert(struct hashTable* table, struct node* iterator);
void colCal(struct node* iterator, int m);
void maxHash(const struct hashTable* table);

void printArr(int * arr,int len){
 for(int i=0; i<len; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

// 把每一行和其他行按位与，按位与的值构成节点插入到Hash表中，同时需要调整其他节点的块中1的个数。
// 如果按位与的值完全覆盖了已经在Hash表中节点的值，那么已经在Hash表中的节点count值自动加上的rown，
// 同时注意不能有重复的行被加入。
int main()
{
    FILE* fp = fopen("d://data.txt","r");
    int n,m;
    fscanf(fp,"%d%d",&n,&m);
    int re[n];
    memset(re,0,sizeof(re));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            int temp;
            fscanf(fp,"%d",&temp);
            re[i] += temp << (m-j-1);
            // 这是什么
        }

    // for(int i=0; i<n; i++){
    //     printf("%d ",re[i]);
    // }
    // printf("\n");
    printArr(re,n);

    struct hashTable* table = (struct hashTable*) malloc(sizeof(struct hashTable));
    memset(table->list,0,sizeof(table->list));
    table->topNode = NULL;

    for(int i=0; i<n; i++)
        for(int j=i; j<n; j++)
        {
            struct node* temp = (struct node*) malloc(sizeof(struct node));
            temp->val = re[i] & re[j];
            printf("temp->val :%d\n",temp->val);
            temp->rown = 0;
            temp->coln = 0;
            temp->cols = (int*) malloc(sizeof(int)*m);
            temp->rows = (int*) malloc(sizeof(int)*n);
            temp->rows[temp->rown++] = i;
            if(i!=j)
                temp->rows[temp->rown++] = j;
            temp->next = NULL;
            colCal(temp,m);
             temp->count = temp->coln * temp->rown;
            hashInsert(table,temp);
        }
    maxHash(table);
    return 0;

}

void maxHash(const struct hashTable* table)
{
    struct node* temp = table->topNode;
    int val = temp->val;
    printf("Size:%d\n",temp->rown*temp->coln);
    printf("Rows:");
    for(int i=0; i<temp->rown; i++)
        printf("%d ",temp->rows[i]+1);
    printf("\nCols:");
    for(int i=0; i<temp->coln; i++)
        printf("%d ",temp->cols[i]+1);
    return;
}


void colCal(struct node* iterator, int m)
{
    iterator->coln = 0;
    int val = iterator->val;
    for(int i=0; i<m && val>0; i++)
    {
        if(val & 1)
            iterator->cols[iterator->coln++] = m-i-1;
        val >>= 1;
    }
}

struct node* hashFind(const struct hashTable* table, const struct node* iterator)
{
    struct node* temp = table->list[iterator->val % max];
    while(temp != NULL && temp->val != iterator->val)
        temp = temp->next;
    return temp;
}

void hashInsert(struct hashTable* table, struct node* iterator)
{
    struct node* temp;
    for(int k=0; k<max; k++)	//改进：这个for循环不需要，原因在于下面几行那个注释的判断不需要。
    {
        temp = table->list[k];
        if(temp == NULL)
            continue;
        while(temp != NULL)
        {
            if((temp->val & iterator->val) == temp->val)	//这部分完全没有必要，也就是整个for循环是不需要的！这部分只要(iterator->val == temp->val)就行了，那么不用for循环遍历表，直接取table->list[temp->val % max]就行了。
            {

                for(int i=0; i<iterator->rown; i++)
                {
                    int flag = 1;
                    for(int j=0; j<temp->rown; j++)
                    {
                        if(temp->rows[j] == iterator->rows[i])
                        {
                            flag = 0;
                            break;
                        }
                    }
                    if(flag){
                        temp->rows[temp->rown++] = iterator->rows[i];
                        temp->count += temp->coln;
                    }
                }
                if(table->topNode == NULL || temp->count > table->topNode->count)
                    table->topNode = temp;
            }
            temp = temp->next;
        }
    }

    if(!hashFind(table,iterator))
    {
        temp = table->list[iterator->val % max];
        if(temp == NULL)
            table->list[iterator->val % max] = iterator;
        else{
            while(temp->next != NULL)
            temp = temp->next;
            temp->next = iterator;
         }
        if(table->topNode == NULL || iterator->count > table->topNode->count)
                table->topNode = iterator;
    }
    else
        free(iterator);
    return;
}

// https://www.zhihu.com/question/39583780