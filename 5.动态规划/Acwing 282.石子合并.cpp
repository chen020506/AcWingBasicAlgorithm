// 算法：区间DP
// 时间：2022.07.13 20点06分
#include<iostream>
#include<algorithm>
using namespace std;

const int N=310;
int n;
int s[N];
int f[N][N];
int main ()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>s[i];
    //求前缀和
    for(int i=1;i<=n;i++) s[i]+=s[i-1];
    
    for(int len=2;len<=n;len++)
        for(int i=1;i+len-1<=n;i++)
            {
                int l=i,r=i+len-1;
                f[l][r]=1e9;
                for(int k=l;k<r;k++)//枚举最后一次合并的分界点
                    f[l][r]=min(f[l][r],f[l][k]+f[k+1][r]+s[r]-s[l-1]);
            }
    cout<<f[1][n]<<endl;
    return 0;

}