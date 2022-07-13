// 算法：动态规划之线性DP
// 时间：2022.07.13 15点45分
#include<iostream>
#include<algorithm>
using namespace std;

const int N=510;
int n,INF=1e9;
int a[N][N],f[N][N];
int main ()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            cin>>a[i][j];

    for(int i=0;i<=n;i++)
        for(int j=0;j<=i+1;j++)
//注意此时初始化需要多初始化一位，因为算边界时会算右上角的最大值，所以把最上角初始化为负无穷    
            f[i][j]=-INF;
    f[1][1]=a[1][1];
    for(int i=2;i<=n;i++)
        for(int j=1;j<=i;j++)
            f[i][j]=max(f[i-1][j-1]+a[i][j],f[i-1][j]+a[i][j]);
        
    //遍历最后一行的最大值
    int res=-INF;
    for(int i=1;i<=n;i++) res=max(res,f[n][i]);
    
    cout<<res<<endl;
    return 0;
}
