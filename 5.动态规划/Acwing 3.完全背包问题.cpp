//  时间：2022.06.09  20点55分
#include<iostream>
#include<algorithm>
using namespace std;

const int N=1010;
int n,m;
int v[N],w[N];
int f[N][N];

//第一种：优化plus版（一维）,注意这种方法需要将f数组变成一维
// int main ()
// {
//     cin>>n>>m;
//     for(int i=1;i<=n;i++) cin>>v[i]>>w[i];
    
//     for(int i=1;i<=n;i++)
//         for(int j=v[i];j<=m;j++)
//             {
//              f[j]=max(f[j],f[j-v[i]]+w[i]);
//             }
//     cout<<f[m]<<endl;
//     return 0;
// }

// 第二种：优化版（二维） 将三重循环变为了双重循环
int main ()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>v[i]>>w[i];
    
    for(int i=1;i<=n;i++)
        for(int j=0;j<=m;j++)
            {
                f[i][j]=f[i-1][j];
                if(j>=v[i]) f[i][j]=max(f[i][j],f[i][j-v[i]]+w[i]);
            }
    cout<<f[n][m]<<endl;
    return 0;
}

// 第三种：朴素做法（二维），有三重循环，现在这个代码在Acwing已经不能ac了，会TLE
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