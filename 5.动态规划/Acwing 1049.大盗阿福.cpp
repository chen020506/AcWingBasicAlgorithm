//  时间：2022.09.07 18点09分
//  算法：线性DP
//  法一
#include<bits/stdc++.h>
using namespace std;
const int N=510;
int f[N][N];
int w[N];
int main ()
{
    int n,m;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>m;
        for(int i=1;i<=m;i++)
            cin>>w[i];
        //dp
        f[1][0]=0,f[1][1]=w[1];
        for(int i=2;i<=m;i++){
            f[i][0]=max(f[i-1][0],f[i-1][1]);
            f[i][1]=f[i-1][0]+w[i];
        }
        cout<<max(f[m][0],f[m][1])<<endl;
    }
    return 0;
}
// 法二
#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int f[N];
int w[N];
int main ()
{
    int n,m;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>m;
        for(int i=1;i<=m;i++)
        cin>>w[i];
        //dp
        f[1]=w[1];//边界条件
        for(int i=2;i<=m;i++)
            f[i]=max(f[i-1],f[i-2]+w[i]);

        cout<<f[m]<<endl;
    }
    return 0;
}