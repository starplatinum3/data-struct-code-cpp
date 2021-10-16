#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
//正确的
//  https://blog.csdn.net/qq_42794545/article/details/90138412
using namespace std;

const int MAXN = 10000;
const double PI = atan(1.0) * 4;
const double EPS = 1e-10;

bool debug = false;

class Point {
public:
    double x, y;

    Point() {}

    Point(double x, double y) : x(x), y(y) {}

    // (1,3) -(2,4) -1,-1
    Point operator-(const Point &r) const { return Point(x - r.x, y - r.y); }

    Point operator+(const Point &r) const { return Point(x + r.x, y + r.y); }

    Point &operator+=(const Point &r) {
        x += r.x;
        y += r.y;
        return *this;
    }

    Point &operator*=(double m) {
        x *= m;
        y *= m;
        return *this;
    }

//做的就是逆时针旋转一个点
    Point pOfRotate(double angle) const {
//        https://www.runoob.com/cprogramming/c-function-cos.html
//        angle 是类似 1/2) pi
        double cosA = cos(angle);
        double sinA = sin(angle);
        return Point(cosA * x - sinA * y, sinA * x + cosA * y);
    }

    //  (1,3)  -3,1)
    // 逆时针转90 绕着o 点
    Point pOfRotate90() const { return Point(-y, x); }

//    到原点距离
    double length() const { return sqrt(x * x + y * y); }

//    (1,3)
    Point pOfNormal() const {
        double len = length();
        // 到原点距离  sqrt(10)
        return Point(x / len, y / len);
        // point (1/sqrt(10),3/sqrt(10))
        // 长度为一的时候 取到的点
        // 也就是模长那种？
    }

    double angle() const { return atan2(y, x); }
};

//Point
ostream &operator<<(ostream &os, const Point &v) {
    os << "(" << v.x << "," << v.y << ")";
    return os;
}

class Segment;

class Circle;

class Seg {
public:
    virtual double getLeft() const = 0;

    virtual double getRight() const = 0;

    virtual double getY(double x) const = 0;

    virtual double getLength(double x1, double x2) const = 0;

    virtual void intersect(Seg *r) const = 0;

    virtual void intersect(const Segment &v) const = 0;

    virtual void intersect(const Circle &v) const = 0;

    bool contains(double x) const { return x >= getLeft() && x <= getRight(); }

    virtual void acceptPrint(ostream &os) const = 0;
};

ostream &operator<<(ostream &os, const Seg &v) {
    v.acceptPrint(os);
    return os;
}

//既然有四个点 我认为是矩形的意思
//但是是 直接连起来吗，这样的话 也不是矩形啊
Point intersectRet[4];
int tIntersectRet;

class Segment : public Seg {
public:
    Point a, b;

    Segment &moveLeft(double dis) {
        // dis 是不是 (2,6) -(1,3)的距离啊?
        // (2,4) -(1,3)==1,1)
        // (2,6) -(1,3)==1,3)
        // pOfNormal 取得单位长度时候的那个点
        Point tmp = ((b - a).pOfRotate90().pOfNormal() *= dis);
        a += tmp;
        b += tmp;
        // this 会变 还会return
        return *this;
    }

    // https://zhidao.baidu.com/question/2012065953274688188.html
    virtual double getLeft() const { return a.x; }
//    左边端点

    virtual double getRight() const { return b.x; }

//    2,4） (1,3)
    virtual double getY(double x) const {
        if (debug) {
            printf("(%lf-%lf)*(%lf-%lf)/(%lf-%lf)+%lf\n", x, a.x, b.y, a.y, b.x, a.x, a.y);

        }
        return (x - a.x) * (b.y - a.y) / (b.x - a.x) + a.y;
    }

    virtual double getLength(double x1, double x2) const {
        double lenBA= (b - a).length();
//        printf("(%.2f -%.2f ) * %.2f / (%.2f - %.2f );\n",
//                x2,x1,lenBA,b.x,a.x);
        double res=(x2 - x1) * lenBA/ (b.x - a.x);
//        printf("res=%.2f\n",res);
        return res;
    }

    virtual void intersect(Seg *r) const {
        r->intersect(*this);
    }

    virtual void intersect(const Segment &v) const {
        tIntersectRet = 0;
        double ang = (b - a).angle();
        Point c = (v.a - a).pOfRotate(-ang);
        Point d = (v.b - a).pOfRotate(-ang);
        // Bug
        //double di = b.length();
        double di = (b - a).length();
        if (!((c.y > 0 && d.y < 0) || (c.y < 0 && d.y > 0)))
            return;
        double x = (d.x - c.x) * (-c.y) / (d.y - c.y) + c.x;
        if (x < 0 || x > di)
            return;
        Point ret = Point(x, 0).pOfRotate(ang) + a;
//        一次相交 只是加了一个点
        if (debug) {
            printf("新的交点\n");
            cout << ret << "\n";
        }

        intersectRet[tIntersectRet++] = ret;
//        ret 是rectangle吗  矩形
    }

    virtual void intersect(const Circle &v) const;

    virtual void acceptPrint(ostream &os) const {
        os << a << "-" << b;
    }
};

class Circle : public Seg {
public:
    Point c;
    double r;

//圆形减掉 半径 最左边的x
    virtual double getLeft() const { return c.x - r; }

    virtual double getRight() const { return c.x + r; }

    virtual double getY(double x) const {
        double y2 = r * r - (c.x - x) * (c.x - x);
        if (y2 < 0) y2 = 0;
        return c.y + sqrt(y2);
    }

    virtual double getLength(double x1, double x2) const {
        x1 -= c.x;
        x2 -= c.x;
        double a1 = Point(x1, sqrt(abs(r * r - x1 * x1))).angle(),
                a2 = Point(x2, sqrt(abs(r * r - x2 * x2))).angle();
        return (a1 - a2) * r;
    }

    virtual void intersect(Seg *r) const {
        r->intersect(*this);
    }

//    段
    virtual void intersect(const Segment &v) const {
        tIntersectRet = 0;
        Point a = v.a - c;
        Point b = v.b - c;
        if (debug) {
            cout << "这个点: " << c << "" << "\n";
//         0， 1) -( 3,0) == (-3,1)
//        (3,0),1
//                      (0,1)-(3,1)
//如果和 线段去相交 才会是 这个函数
//a 线段起点
            cout << "a(线段的左端点-地上点,也就是端点到圆形底盘点的向量）: "
                 << a << " , b（线段的右端点-地上点）:" << b << "\n";
            cout << "举例子 ： a就是 cc->D , b就是 cc->E\n";
            cout << "cc->D  -  cc->E 其实 还是 ED 的向量\n";
            cout << "其实是 ED 关于 x正半轴的角度吧\n";
        }
        double ang = (b - a).angle();
//        c --cc' 大概是 -1/4pi =-1/4*3.14== -0.785, 然而不是 总之大概是: -0.982794
//是从 x 轴 正半轴 往顺时针旋转 所以是负数
//ab 的角度
        if (debug) {
            cout << "nA 就是转正之后的 cc->D cc->E\n";
            printf("angle（左右端点之间的角度 相对地上点）例子就是D cc E : %lf\n", ang);
            cout << "所以nA.y 确实就是1 啊\n";
        }
//<doubt>

//        cout << "实际上 na 也不是个点了吧 实际上是原点到那边的线段了吧，"
//                "也可以说是这条线段的长度，因为平移的话 其实都是一样的\n";
//cout<<"nA 是地上点到 平移悬空点的向量吗\n";
//cout<<"比如 cc->gg  cc->E 向量?\n";
//cout<<"如果确实是这个数值的话 nA: (2.22045e-16,1), nB:(5.09902,1)\n";
//        </doubt>

//        nA: (2.22045e-16,1), nB:(5.09902,1)
        Point nA = a.pOfRotate(-ang);
//        顺时针 ang角度
//        逆时针 绕着原点 旋转 -ang 角度
        Point nB = b.pOfRotate(-ang);
//        图片 1 ）摆正姿态 所以大概是做了这样的事情
        if (debug) {
            printf("两个距离向量 逆时针绕着原点旋转%lf角度之后\n", ang);
            cout << "如果ang 是负数 那么相当于顺时针转了这个的abs\n";
            cout << "其实是把它转正了\n";
            cout << "nA: " << nA << ", nB:" << nB << "\n";
        }
        double y = nA.y;
        if (debug) {

            printf("nA.y :%lf\n", y);
        }

        //        (5,-3),1
//                       (0,1)-(3,1)
// 这里有 nA.y :4.000000 但是没有符合(y > r || y < -r) 所以没有入选
//AB cc 确实好像是离得太远了
//所以到 AB  只能是aa bb 这种 距离小于1（半径） 的
//bb ED 估计也会因为距离问题而 不要了吧
//也就是说 只有相对于轮子最近的两个点 会去算吗
//比如 ED 就是 算cc 和dd
        if (y > r || y < -r)
            return;
        double x = sqrt(r * r - y * y);

        if (debug) {
            printf("勾股定理\n");
            printf("x==sqrt(r * r - y * y);: %lf\n", x);
//        这样他不会一直 x 都是0 吗
            cout << "这个点以勾股定理得到的x 和nA.y;作为组成\n";
            cout << "有时候这个x可以不是0， 因为圆形的点和 线段可以在一条直线上\n";
            cout << "其实 这个线段才是圆心的连线啊\n";
            cout << "x==sqrt(r * r - y * y);: 1.000000 说明他是正方向的\n";
            cout << "但是 bb E D 这种有可能出现吗,这种bb地上的点 不是和两个圆圈临近的\n";
            cout << "还是说 x 只可能出现 1 或者 0 的情况吗\n";
            cout << "但是bb GH 都出现了 bb E D  怎么不能出现呢\n";
        }
        Point pointToRotate;
        if (debug) {
            cout << "需要(x >= nA.x && x <= nB.x) \n";
        }

        if (x >= nA.x && x <= nB.x) {
            pointToRotate = Point(x, y);
//            intersectRet[tIntersectRet++] = Point(x, y).pOfRotate(ang) + c;
            intersectRet[tIntersectRet++] = pointToRotate.pOfRotate(ang) + c;

        }
        if (-x >= nA.x && -x <= nB.x) {
            pointToRotate = Point(-x, y);
//            intersectRet[tIntersectRet++] = Point(-x, y).pOfRotate(ang) + c;
            intersectRet[tIntersectRet++] = pointToRotate.pOfRotate(ang) + c;
        }
        if (debug) {
            printf("增加了一个,是这个点(左端点） ");
            cout << pointToRotate;
            printf(" 逆时针绕着原点旋转 %lf角度+c(右端点) 获得的\n", ang);
//    printf("c : %d\n",c);
//<error>
//        cout << "c （这个圆形自己）: " << c << "\n";
//</error>
            cout << "c （这个点自己）: " << c << "\n";
//        正是 c 这个点了
            cout << intersectRet[tIntersectRet - 1] << "\n";

            putchar('\n');
        }
    }

    virtual void intersect(const Circle &v) const {
        tIntersectRet = 0;
        Point p = v.c - c;
        double d = p.length();
        if (d > r + v.r || d == 0)
            return;
        double x = (r * r - v.r * v.r + d * d) / (2 * d);
        if (x <= r) {
            double y = sqrt(abs(r * r - x * x));
            double ang = p.angle();
            intersectRet[tIntersectRet++] = Point(x, y).pOfRotate(ang) + c;
            intersectRet[tIntersectRet++] = Point(x, -y).pOfRotate(ang) + c;
        }
    }

    virtual void acceptPrint(ostream &os) const {
        os << c << "," << r;
    }
};

void Segment::intersect(const Circle &v) const {
    v.intersect(*this);
}

int n;
Point inps[MAXN];
vector<Seg *> segs;
vector<double> spes;
double radius = 1;

void printSegs() {
    for (auto val :segs) {
//        (typeof(val))
//        cout << val << " ";
        val->acceptPrint(cout);
        putchar(' ');
    }
    putchar('\n');
}

void input() {
    scanf("%d%lf", &n, &radius);
    for (int i = 0; i < n; ++i) {
        double x, y;
        scanf("%lf%lf", &x, &y);
        inps[i] = Point(x, y);
//        地上的点
    }
}

#include "util/printUtilNotClass.h"

//vector<Seg*>mySegs;
void process() {
    segs.clear();
    spes.clear();
    for (int i = 1; i + 1 < n; ++i) {
        Circle *tmp = new Circle;
        //c circle
        tmp->c = inps[i];
        tmp->r = radius;
        segs.push_back(tmp);

//        圆形
    }

//    cout << "放入地上的线段 和 那些圆圈 : \n";
    for (int i = 0; i + 1 < n; ++i) {
        Segment *tmp = new Segment;
        tmp->a = inps[i];
        tmp->b = inps[i + 1];
//        cout << "转变的两个点\n";
//        cout << "a: " << tmp->a << " , b:" << tmp->b << "\n";\
//        cout << "移动 这个 距离 是圆形的半径: " << radius << "\n";
        tmp->moveLeft(radius);
//        相当于把地上的线 移动到圆心位置
        // 半径
//        相当于把地上的线 移动到圆心位置，


// <error>
//        cout<<"线段往右侧移动了 不管是哪种 都是往右移动的\n";
//        cout<<"就是往右拔高了 r的高度，对于每个点  ";
//</error>


//        cout << "线段 整体往上偏移 做出了ED 这条线: ";
//        tmp->acceptPrint(cout);
//        cout << "\n==================\n";
//        整体往上偏移 做出了ED 这条线
        segs.push_back(tmp);
//        segs 里面圆形和线段都是有的
    }

//圆形和线段都有
//    spes 每个点 （除了0 0） 的 左右端点
//C cc' 这样的线段 ，平移上去的线段的 左右端点，包括 AB
    for (int i = 0; i < (int) segs.size(); ++i) {
        spes.push_back(segs[i]->getLeft());
        spes.push_back(segs[i]->getRight());
    }

    if (debug) {
        printf("show spes\n");

        printVector(spes);
        printSegs();
//        2.00 4.00 4.00 6.00 5.00 7.00 6.00 8.00 0.00 3.00 3.83 5.83 4.02 5.02 6.95 7.95 7.00 10.00

    }
    for (int i = 0; i < (int) segs.size(); ++i) {
        for (int j = i + 1; j < (int) segs.size(); ++j) {
//           相交
//边和边
//这是所有边之间都要相交的意思啊
            if (debug) {

                printf("两个东西相交,去产生交点\n");
                segs[i]->acceptPrint(cout);
                putchar('\n');
                segs[j]->acceptPrint(cout);
                putchar('\n');


            }
//相交的是直线  弧线不去相交
            segs[i]->intersect(segs[j]);
//            相交 有新的也要加入
            if (tIntersectRet > 0) {
                for (int id = 0; id < tIntersectRet; ++id) {
//                    cout << *segs[i] << " " << *segs[j] << " : " << intersectRet[id] << endl;
                    spes.push_back(intersectRet[id].x);
                }
            }
        }
    }
    sort(spes.begin(), spes.end());
    double pre = spes[0];
    const double NONE = 1e30;
    double preEnd = NONE;
    double totalLen = 0;
    for (int i = 1; i < (int) spes.size(); ++i) {
//        相当于==0
        if (spes[i] - pre < EPS)
            continue;
        double cur = (pre + spes[i]) / 2;
        //cout << "Processing " << cur << "  from " << pre << " to " << spes[i] << endl;
//        地上的点
        if (cur >= inps[0].x && cur <= inps[n - 1].x) {
            double MY = -NONE;
//            一开始 == -1e30
            int who;
            for (int j = 0; j < (int) segs.size(); ++j) {
                if (!segs[j]->contains(cur))
                    continue;
                double y = segs[j]->getY(cur);
                if (y > MY) {
                    MY = y;
                    who = j;
                }
            }
            if (preEnd != NONE) {
                double LY = segs[who]->getY(pre);
                cout << "Drop info " << *segs[who] << " " <<
                     "[" << pre << "]" << endl;
                totalLen += abs(preEnd - LY);
                cout << "Pre drop = " << abs(preEnd-LY) << "  from " << preEnd << " to " << LY << endl;
            }
//            pre 前面那个点的x spes 里面的
            double len = segs[who]->getLength(pre, spes[i]);
            if (len < 0)
                printf("Error!\n");
            cout << "Curlen = " << len << " from " << pre << " to " << spes[i] << endl;
            totalLen += len;
            preEnd = segs[who]->getY(spes[i]);
        }
        pre = spes[i];
    }
    printf("%0.2lf\n", totalLen);
    for (int i = 0; i < (int) segs.size(); ++i)
        delete segs[i];
    segs.clear();
}

//做的就是逆时针旋转一个点
void testPOfRotate() {
//    Point pOfRotate(double angle);
    Point point(sqrt(3), 1);
    Point rotatePoint = point.pOfRotate(60 * 1.0 / 180 * PI);
    cout << point << "\n";
    cout << "rotate 60/180)pi : " << rotatePoint << "\n";

}

void testMoveLeft() {
    Segment *tmp = new Segment;
    tmp->a = Point(1, 3);
    tmp->b = Point(2, 6);
    tmp->acceptPrint(cout);
//    (1,3)-(2,6) 移动之前
//    (-2,4)-(-1,7) 之后
// 好像不是水平移动  而是垂直于 (1,3)-> (2,6)  这个向量移动
    tmp->moveLeft(sqrt(10));
//    移动的长度
//    这是往左平移吗
    // radius 半径
//    cout<<tmp<<"\n";
    tmp->acceptPrint(cout);
//    a-b
}

int main() {

//    testPOfRotate();
    input();
    process();
    return 0;
}