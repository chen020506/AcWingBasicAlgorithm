//  时间：2022.06.08 21点57分
#include<iostream>
#include<algorithm>
using namespace std;

const int N=1010;
int n,m;
int v[N],w[N];
int f[N][N];
// 第二种：朴素做法，现在这个代码在Acwing已经不能ac了，会TLE
// int main ()
// {
//     cin>>n>>m;
//     for(int i=1;i<=n;i++) cin>>v[i]>>w[i];
    
//     for(int i=1;i<=n;i++)
//         for(int j=0;j<=m;j++)
//             for(int k=0;k*v[i]<=j;k++)
//                 f[i][j]=max(f[i][j],f[i-1][j-v[i]*k]+w[i]*k);
//     cout<<f[n][m]<<endl;
//     return 0;
// }