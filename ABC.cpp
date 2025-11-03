#include <bits/stdc++.h>
using namespace std;
const double p=acos(-1.0);
pair <double,double> cc(double x1,double y1,double x2,double y2,double x3,double y3)//center of circle
{
    double a1 = 2 * (x2 - x1);
    double b1 = 2 * (y2 - y1);
    double c1 = x2*x2 + y2*y2 - x1*x1 - y1*y1;
    double a2 = 2 * (x3 - x1);
    double b2 = 2 * (y3 - y1);
    double c2 = x3*x3 + y3*y3 - x1*x1 - y1*y1;
    double d = a1*b2 - a2*b1;
    double x = (c1*b2 - c2*b1) / d;
    double y = (a1*c2 - a2*c1) / d;
    return {x, y};
}
int main(){
    double x1,y1,x2,y2,x3,y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    auto [m,n]=cc(x1,y1,x2,y2,x3,y3);
    //cout<<m<<endl<<n<<endl;
    double R=hypot(x1-m,y1-n);
    vector<double> ang= {
        atan2(y1 - n, x1 - m),
        atan2(y2 - n, x2 - m),
        atan2(y3 - n, x3 - m)
    };//ji jiao
    for(auto &a :ang)
        if(a<0) a+=2*p;
    sort(ang.begin(), ang.end());
    vector<double> an = {
        ang[1] - ang[0],
        ang[2] - ang[1],
        2*p-(ang[2]-ang[0])
    };
    cout<<an[0]<<endl<<an[1]<<endl<<an[2]<<endl;
    for(int i=3;i<=100;i++)
    {
        double a=2*p/i;
        double r1=an[0]/a,r2=an[1]/a,r3=an[2]/a;
        if(fabs(r1-round(r1))<=1e-5&&fabs(r2-round(r2))<=1e-5&&fabs(r3-round(r3))<=1e-5)
        {
            cout<<i<<endl;
            double area = 0.5*i*R*R*sin(2*p/i);
            cout << fixed << setprecision(6) << area << endl;
            return 0;
        }
    }
    return 0;
}