#include <iostream>
int main(){
    int m,n,a;
    int x,y;
    if(m%a!=0)
        x=m//a+1;
    else 
        x=m//a;
    if(n%a!=0)
        y=n//a+1;
    else 
        y=n//a;
    cout<<x*y;
    return 0;
}