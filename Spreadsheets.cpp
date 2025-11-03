#include <bits/stdc++.h>
#include <string>
using namespace std;
bool jd(const string &s)
{
    if(s[0]!='R')
        return false;
    int a=s.find('C');
    if(a==string::npos)
        return false;
    else
    {
        //cout<<"dddd"<<endl;
        for(int i=1;i<a;i++)
        {
            if(!isdigit(s[i]))
                return false;
        }
        //cout<<"yyyy"<<endl;
        for(int i=a+1;i<s.size();i++)
        {
            if(!isdigit(s[i]))
                return false;
        }
    }
    //cout<<"whoo"<<endl;
    return true;
}
string ex(const string &s)
{
    int a=s.find('C');
    int m,n;
    m=stoi(s.substr(1,a-1));
    n=stoi(s.substr(a+1));
    //cout<<m<<endl<<n<<endl;
    string r="";
    //cout<<char(n/26+'A'-1)<<endl<<char(n%26-1+'A')<<endl;
    if(n>26)
    {
        r+=char(n/26+'A'-1);
        r+=char(n%26-1+'A');
    }    
    else
        r=to_string(n);
    //cout<<r<<endl;
    if(m>26)
    {
        r+=char(m/26+'A');
        r+=char(m%26-1+'A');
    }
    else
        r+=to_string(m);
    return r;
}
string rx(const string &s)
{
    string m;
    int n;
    string r="";
    for( int i=0;i<s.size();i++)
    {
        if(isdigit(s[i+1])){
            string m=s.substr(0,i);
            n=stoi(s.substr(i+1));
            break;
        }
    }
    if(m.size()==1)
        r="R"+to_string(n)+"C"+to_string(m[0]-'A'+1);
    else
    {
        int t;
        t=int(s[0]-'A'+1)*26+int(s[1]-'A'+1);
        r="R"+to_string(n)+"C"+to_string(t);
    }
    return r;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        jd(s);
        if(s=="RC"||jd(s))
            cout<<ex(s)<<endl;//is rx
        else
            cout<<rx(s)<<endl;
    }
}