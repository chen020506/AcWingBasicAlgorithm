//  时间:2022.09.08 19点45分
#include<bits/stdc++.h>
using namespace std;

const int N=110,INF=0x3f3f3f3f;
int n;
int a[N];
int s[N];//记录前缀和
int f[N][N];//f[l][r]表示把从l到r合并成一堆的得分的最小值
int g[N][N];//g[l][r]表示把从l到r合并成一堆的得分的最大值
int main ()
{
    memset(f,INF,sizeof f);
    memset(g,-INF,sizeof g);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i+n]=a[i];//复制一遍区间
    }
    for(int i=1;i<=2*n;i++){
        s[i]=s[i-1]+a[i];//前缀和
        g[i][i]=0,f[i][i]=0;
    }
    //DP
    for(int len=2;len<=n;len++)
        for(int l=1;l+len-1<=2*n;l++){
            int r=l+len-1;
            for(int k=l;k<r;k++){
                f[l][r]=min(f[l][r],f[l][k]+f[k+1][r]+s[r]-s[l-1]);
                g[l][r]=max(g[l][r],g[l][k]+g[k+1][r]+s[r]-s[l-1]);
            }
        }
    //输出
    int minv=INF,maxv=-INF;
    for(int i=1;i<=n;i++){
        minv=min(minv,f[i][i+n-1]);
        maxv=max(maxv,g[i][i+n-1]);
    }
    cout<<minv<<endl<<maxv<<endl;
    return 0;
}