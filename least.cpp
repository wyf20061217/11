#include <bits/stdc++.h>
using namespace std;
int ct(int x,int y)
{
    int n=0;
    while(x%y==0)
    {
        n++;
        x/=y;
    }
    return n;
}
int main(){
    int n;
     cin>>n;
    vector<vector<int>> a(n+1,vector<int>(n+1));
    vector<vector<int>> ct2(n+1,vector<int>(n+1));
    vector<vector<int>> ct5(n+1,vector<int>(n+1));
    int x0=0,y0=0;
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            cin>>a[i][j];
            if(a[i][j]==0)
            {   
                x0=i;
                y0=j;
                ct2[i][j]=INT_MAX;
                ct5[i][j]=INT_MAX;
            }
            else
            {
                ct2[i][j]=ct(a[i][j],2);
                ct5[i][j]=ct(a[i][j],5);
            }
        }
            
    }
    vector<vector<int>> dp2(n+1,vector<int>(n+1,1e9));
    vector<vector<int>> dp5(n+1,vector<int>(n+1,1e9));
    vector<vector<char>> c2(n+1,vector<char>(n+1));
    vector<vector<char>> c5(n+1,vector<char>(n+1));
    dp2[1][1]=ct2[1][1];
    dp5[1][1]=ct5[1][1];
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            if(i==1&&j==1)continue;
            if(i>1&&dp2[i][j]>dp2[i-1][j]+ct2[i][j])
            {
                dp2[i][j]=dp2[i-1][j]+ct2[i][j];
                c2[i][j]='D';
            }
            if(j>1&&dp2[i][j]>dp2[i][j-1]+ct2[i][j])
            {
                dp2[i][j]=dp2[i][j-1]+ct2[i][j];
                c2[i][j]='R';
            }

            if(dp5[i][j]>dp5[i-1][j]+ct5[i][j])
            {
                dp5[i][j]=dp5[i-1][j]+ct5[i][j];
                c5[i][j]='D';
            }
            if(dp5[i][j]>dp5[i][j-1]+ct5[i][j])
            {
                dp5[i][j]=dp5[i][j-1]+ct5[i][j];
                c5[i][j]='R';
            }
        }
    }
    int rs2=dp2[n][n];
    int rs5=dp5[n][n];
    int rs=min(rs2,rs5);
    int x=n,y=n;
    string s="";
    if(rs2<rs5)
    {
        while(x>1||y>1)
        {
            s+=c2[x][y];
            if(c2[x][y]=='D')x--;
            else y--;
        }
    }
    else
    {
        while(x>1||y>1)
        {
            s+=c5[x][y];
            if(c5[x][y]=='D')x--;
            else y--;
        }
    }
    reverse(s.begin(),s.end());
    if(rs>1&&x0!=0)
    {
        for(int i=1;i<x0;i++) s+='D';
        for(int i=1;i<y0;i++) s+='R';
        for(int i=x0;i<n;i++) s+='D';
        for(int i=y0;i<n;i++) s+='R';
        cout<<s<<endl;
    }
    else
        cout<<rs<<endl<<s<<endl;
    return 0;
}