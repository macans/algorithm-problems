
#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <Vector>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <set>
#define LL long long
#define INF 0x3f3f3f3f
#define eps 1e-10
#define OPEN_FILE
using namespace std;
int n;
int const maxn = 1000;

int dcmp(double x){
    if (fabs(x) < eps) return 0;
    return x < 0 ? -1 : 1;
}
struct Point{
    double x, y;
    Point(double p = 0, double q = 0){
        x = p;
        y = q;
    }
};
struct Node{
    int p;
    Point A, B;
    Node(Point a1, Point a2, int t){
        A = a1;
        B = a2;
        p = t;
    }
};
typedef Point Vector;

Vector operator + (Vector A, Vector B){
    return Vector(A.x + B.x, A.y + B.y);
}
Vector operator - (Vector A, Vector B){
    return Vector(A.x - B.x, A.y - B.y);
}
Vector operator * (Vector A, double p){
    return Vector(A.x * p, A.y * p);
}
Vector operator / (Vector A, double p){
    return Vector(A.x / p, A.y / p);
}
bool operator == (Vector A, Vector B){
    return dcmp(A.x - B.x) == 0 && dcmp(A.y - B.y) == 0;
}
bool operator > (Vector A, Vector B){
    return A.x > B.x && A.y > B.y;
}
bool operator <(Vector A, Vector B){
    return A.x < B.x && A.y < B.y;
}
//点积
double  Dot(Vector A, Vector B){
    return A.x * B.x + A.y * B.y;
}
//模
double Length(Vector A){
    return sqrt(Dot(A, A));
}
//夹角
double Angle(Vector A, Vector B){
    return acos(Dot(A, B) / Length(A) / Length(B));
}
//叉积
double Cross(Vector A, Vector B){
    return A.x * B.y - A.y*B.x;
}
//三角形面积
double Area2(Point A, Point B, Point C){
    return Cross(B - A, C - A);
}
struct Line
{
    Point p;
    Vector v;
    double angle;
    Line(){}
    Line(Point p, Vector v) :p(p), v(v){
        angle = atan2(v.y, v.x);
    }
    bool operator < (const Line & L) const{
        return angle<L.angle;
    }
};
//点p在直线L的左边
bool OnLeft(Line L, Point p) { return Cross(L.v, p - L.p)>=0; }

//直线A，B的交点
Point GetIntersection(Line A, Line B)
{
    Vector u = A.p - B.p;
    double t = Cross(B.v, u) / Cross(A.v, B.v);
    return A.p + A.v*t;
}
double cross(Point p0, Point p1, Point p2) {
    return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}

void andrew() {
    Point list[maxn], stk[maxn];
    int p = 1;
    stk[0] = list[0], stk[1] = list[1];
    for (int i = 2; i < n; ++i) {  //求下凸包
        while (p > 0 && cross(stk[p - 1], stk[p], list[i]) <= 0) --p;
        stk[++p] = list[i];
    }
    stk[++p] = list[n - 2];
    for (int i = n - 3; i >= 0; --i) {  //求上凸包
        while (p > 0 && cross(stk[p - 1], stk[p], list[i]) <= 0) --p;
        stk[++p] = list[i];
    }  //要注意栈尾和栈顶都是list[0]
}

//graham扫描法求凸包，凸包顶点存在stack栈中
//从栈底到栈顶一次是逆时针方向排列的
//如果要求凸包的一条边有2个以上的点
//那么要将while中的<=改成<
//但这不能将最后一条边上的多个点保留
//因为排序时将距离近的点排在前面
//那么最后一条边上的点仅有距离最远的会被保留，其余的会被出栈
//所以最后一条边需要特判
//如果要求逆凸包的话需要改cmp，graham中的符号即可
void Graham(int n) {
    int i;
    if (n == 1) top = 0, stack[0] = 0;
    if (n == 2) top = 1, stack[0] = 0, stack[1] = 1;
    if (n > 2) {
        for (i = 0; i <= 1; i++) stack[i] = i;
        top = 1;

        for (i = 2; i < n; i++) {
            while (top > 0 &&
                   cross(list[stack[top - 1]], list[stack[top]], list[i]) <= 0)
                top--;
            top++;
            stack[top] = i;
        }
    }
}