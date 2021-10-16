#include<cstdio> 
#include<algorithm>
using namespace std;
const int Max_N = 100000;
const int INF = 1000000;
// https://www.cnblogs.com/w-like-code/p/13472516.html
struct paper//图片结构体 
{
    int w;
    int h;
    paper(int w_,int h_){//构造函数 
        w = w_;    h = h_;
    }
    paper(){}
};

// 如果计算出从第 i 个图片开始排版到第N个图片的高度，
// 那么第k+1到N张图片排版改变后的高度为:将当前行填满  + 从第 i 张开始到第N张图片高度(假设用k+1-i-1将当前行填满)
// k 就是填满一行的 那个位置
paper P[Max_N+1];
//输入
int N,M;
int Rev[Max_N+2];//Rev[i]: 将 i----N 顺序加入最后的高度 
void add(paper &p,int k)
//在p的基础上加入第k个图片 p记录当前占用宽度和高度(这里p到代表某一行排列) 
// p 是循环时候中间的变量
// 这里是加了一个 ，外面有个循环，k在增加的
{ //加入时分两种情况考虑 
    if( p.w+P[k].w <= M )//加入图片宽度小于等于剩余宽度 (这时图片不需要收缩)
    {
        p.w += P[k].w;
        p.h = max( p.h, P[k].h );
    }
    else
    {//加入图片宽度>剩余宽度 
        int w = M - p.w;//剩余宽度 
        p.h = max( p.h, ((w*P[k].h-1)/P[k].w)+1 );
        	// 为什么是max, 因为被迫增加高度,因为你加了一个高的东西,被迫需要和他
            // 一样高的地方放了
        // wi/hi=w/h->h=w*hi/wi (-1,+1是处理向上取整)
        p.w = M;
        // 这个paper里 记的是合计的 不是单独的吗
        // 是的 他说是一行的
    }
} 

// 以一行为分界线
int getRev(paper p,int k)//在加入p的基础上加上k----N后排版的高度 
{
    // 这里不是引用啊
    // 小于宽度 小于数量
    while( p.w<M && k<=N )
    {
        add(p,k);
        // 这里是引用了 所以p会变
        // 但是出去以后 不会变
        // 但是那个也只是个暂时的 paper 00  
        // 所以变不变都没事吧
        k++;
    }
    return p.h + Rev[k];
    //  p.h 当前行 ，， Rev[k]; 后面的部分
}
void solve()
{
    // 为什么从N开始？ 难道是为了防止前面的多加了？
    for(int i=N; i>=1; i--)//初始化Rev[]
    {
        paper p(0,0);
        // 这个p 放进去之后 没有发生变化
        Rev[i] = getRev(p,i); //Rev[i] = h + Rev[k]
    }
    paper p(0,0);
    // 但是p 也是个tmp的 所以也没事吗
    // 但是前面的循环不会影响他吗
    int res = INF, h = 0;
    for(int i=1; i<=N; i++)
    {//每次去掉第i个图片 
    // 这是每一个测试 还是会更改的啊， 调用这个add 好像是引用,但是getRev 不是引用
        res = min( res, h + getRev(p,i+1) );
        // 但是这里有一个变了 好像有事的东西
        // 于是我应该尝试一下 不要引用
        
        //h:1---i-1的高度, getRev(p,i+1):i+1----N高度 
        // i 图片没有被加上 就是去掉了
    //    换入p
    //在加入p的基础上加上(i+1)---N后排版的高度 
    // 到了 p 这一行为止,加上(i+1)---N后排版的高度 
        add(p,i);   
        // p 是一行的 
        if( p.w==M )
        {
            h += p.h;//更新当前排版高度 
            p.w = p.h = 0;//下一行 
        }
    }
    printf("%d\n",res);
}
int main()
{
    scanf("%d%d",&M,&N);
    // 　第一行包含两个整数 M 和 N，分别表示纸张宽度和图片的数量。
    for(int i=1; i<=N; i++){
        scanf("%d%d",&P[i].w,&P[i].h);
    }
    
    solve();
    
    return 0;
}