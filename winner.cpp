#include <bits/stdc++.h>
using namespace std;
struct ps{
    string name="";
    int sr=0;
};
int main(){
    int n;
    cin>>n;
    vector<ps> all={};
    int mx=-10001,co=0;
    for(int i=0;i<n;i++)
    {
        ps p0;
        cin>>p0.name>>p0.sr;
        bool jd=false;
        for (int j=0;j<all.size();j++)
        {  
            if(all[j].name==p0.name)jd=true;
            if(jd)
            {
                all[j].sr+=p0.sr;
                break;
            }
        }
        if(!jd)
            all.push_back(p0);
        for(int j=0;j<all.size();j++)
        {
            if(all[j].sr>mx)
            {
                mx=all[j].sr;
                co=j;
            }
        }
    }
    cout<<all[co].name<<endl;
    return 0;
}