// ���ߣ�Eagerming
// ���ӣ�https://www.zhihu.com/question/39583780/answer/82140296
// ��Դ��֪��
// ����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#define max 127


// һ���ڵ����һ���Ӿ���
struct node
{
    int val; // ��λ����ֵ
    int count; // ��ǰ����1�ĸ���
    int* rows; // ����
    int rown; // �к�
    int* cols; // �к�
    int coln; // ����
    struct node* next;//��ϣ��ͬһ��hashֵ�е���һ��
};

struct hashTable
{
    struct node* list[max]; // Hash��
    struct node* topNode; // ��ǰ����1�ĸ������Ľڵ�
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

void  maxOne(){
    FILE* fp = fopen("d://data.txt","r");
    int n,m;
    fscanf(fp,"%d%d",&n,&m);
    int re[n];
    memset(re,0,sizeof(re));
//    ����ÿһ��
//������һ�е�����ȥ temp << (m-j-1);
//����ĳ�� hash �İ취��
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            int temp;
            fscanf(fp,"%d",&temp);
            re[i] += temp << (m-j-1);
            // ����ʲô
        }

    // for(int i=0; i<n; i++){
    //     printf("%d ",re[i]);
    // }
    // printf("\n");
    printArr(re,n);

    struct hashTable* table = (struct hashTable*) malloc(sizeof(struct hashTable));
    memset(table->list,0,sizeof(table->list));
    table->topNode = NULL;

//    ��ÿһ�к������а�λ�룬��λ���ֵ���ɽڵ���뵽Hash����
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
//            �������������
            if(i!=j)
                temp->rows[temp->rown++] = j;
            temp->next = NULL;
            colCal(temp,m);
//            m ��
            temp->count = temp->coln * temp->rown;
            hashInsert(table,temp);
        }
    maxHash(table);
}

// ��ÿһ�к������а�λ�룬��λ���ֵ���ɽڵ���뵽Hash���У�ͬʱ��Ҫ���������ڵ�Ŀ���1�ĸ�����
// �����λ���ֵ��ȫ�������Ѿ���Hash���нڵ��ֵ����ô�Ѿ���Hash���еĽڵ�countֵ�Զ����ϵ�rown��
// ͬʱע�ⲻ�����ظ����б����롣
int main()
{
    maxOne();

//    printf("1&1 %d\n",1&1);
//    printf("1&0 %d\n",1&0);
//    printf("5&6 %d\n",5&6);
//    printf("5&9 %d\n",5&9);

//    1&1 1
//    1&0 0
//    5&6 4
//    5&9 1
// & 1  �Ż��Ǳ����
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
//    �⼸���� �⼸���� ��ɵ� �����Ǹ�����
    return;
}


void colCal(struct node* iterator, int m)
{
    iterator->coln = 0;
    int val = iterator->val;
//    ȫ������ ÿ���� ȥ����
    for(int i=0; i<m && val>0; i++)
    {
//        ������
        if(val & 1){
            printf("val %d\n",val);
            printf("m-i-1; %d\n",m-i-1);
            iterator->cols[iterator->coln++] = m-i-1;
//            ����������� m-i-1;
//            1 1 1 0 0
//��һ�� �� 2 1 0 ���� 1
//����Ҳ���������˼
        }

        val >>= 1;
//        ����2
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
    for(int k=0; k<max; k++)	//�Ľ������forѭ������Ҫ��ԭ���������漸���Ǹ�ע�͵��жϲ���Ҫ��
    {
        temp = table->list[k];
        if(temp == NULL)
            continue;
        while(temp != NULL)
        {
//            1&1
            if((temp->val & iterator->val) == temp->val)
                //�ⲿ����ȫû�б�Ҫ��Ҳ��������forѭ���ǲ���Ҫ�ģ�
                // �ⲿ��ֻҪ(iterator->val == temp->val)�����ˣ�
                // ��ô����forѭ��������ֱ��ȡtable->list[temp->val % max]�����ˡ�
            {
                printf("(temp->val & iterator->val) == temp->val\n");
                printf("temp->val  %d\n",temp->val);

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