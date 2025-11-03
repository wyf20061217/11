#include <bits/stdc++.h>
using namespace std;
struct Circle {
    double x, y, r;
};
Circle ap(const Circle& A, const Circle& B) {
    double k = A.r / B.r;
    Circle C;
    C.x = (A.x - k * k * B.x) / (1 - k * k);
    C.y = (A.y - k * k * B.y) / (1 - k * k);
    double d = hypot(A.x - B.x, A.y - B.y);
    C.r = fabs(k * d / (1 - k * k));
    return C;
}

// 计算两圆交点，返回最多两个点
vector<pair<double, double>> intersect(const Circle& A, const Circle& B) {
    vector<pair<double, double>> res;
    double dx=B.x-A.x,dy=B.y-A.y;
    double d=hypot(dx,dy);
    double a=(A.r*A.r-B.r*B.r+d*d)/(2*d);
    double h=sqrt(A.r*A.r - a*a);
    double xm=A.x+a*dx/d;
    double ym=A.y+a*dy/d;
    double rx=-dy*(h/d);
    double ry= dx*(h/d);
    res.push_back({xm+rx,ym+ry});
    res.push_back({xm-rx,ym-ry});
    return res;
}

int main() {
    Circle O1, O2, O3;
    cin >> O1.x >> O1.y >> O1.r;
    cin >> O2.x >> O2.y >> O2.r;
    cin >> O3.x >> O3.y >> O3.r;
    Circle C12 = ap(O1, O2);
    Circle C13 = ap(O1, O3);
    auto pts = intersect(C12, C13);//jiao dian
    cout.setf(ios::fixed);
    cout << setprecision(6);
    for (auto [x, y] : pts) {
        cout << "P = (" << x << ", " << y << ")\n";
    }
    return 0;
}