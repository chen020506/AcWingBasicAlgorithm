//  时间：2022.09.07 19点56分
//  算法：线性DP
#include<bits/stdc++.h>
using namespace std;
const int N=510;
int f[N][N];
int w[N];
int main ()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>w[i];
        
        f[1][0]=0,f[1][1]= -w[1];
        //dp
        for(int i=2;i<=n;i++){
            f[i][0]=max(f[i-1][0],f[i-1][1]+w[i]);
            f[i][1]=max(f[i-1][1],f[i-1][0]-w[i]);
        }

        cout<<f[n][0]<<endl;
    return 0;
}