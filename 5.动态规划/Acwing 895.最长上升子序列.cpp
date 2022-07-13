// 算法：线性DP
// 时间：2022.07.13 16点44分
#include<iostream>
#include<algorithm>
using namespace std;

const int N=1010;
int a[N],f[N];
int n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    
    for(int i=1;i<=n;i++)
    {
        f[i]=1;//以i结尾的上升序列只有它本身
        for(int j=1;j<i;j++)
    //枚举i前一个数的位置，从0到i-1
            if(a[j]<a[i])
                f[i]=max(f[i],f[j]+1);
    }
    int res=-1;
    for(int i=1;i<=n;i++) res=max(res,f[i]);
    
    cout<<res<<endl;
    return 0;
}