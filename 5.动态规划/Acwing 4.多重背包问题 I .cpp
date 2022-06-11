//  时间：2022.06.11 23点15分
#include<iostream>
#include<algorithm>
using namespace std;
const int N=110;
int n,m;
int v[N],w[N],s[N];
int f[N][N];

//多重背包问题的朴素写法
int main ()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>v[i]>>w[i]>>s[i];
    
    for(int i=1;i<=n;i++)
        for(int j=0;j<=m;j++)
            for(int k=0;k<=s[i]&&k*v[i]<=j;k++)//k表示第i个物品选多少个
                f[i][j]=max(f[i][j],f[i-1][j-v[i]*k]+w[i]*k);
    cout<<f[n][m]<<endl;
    return 0;
}