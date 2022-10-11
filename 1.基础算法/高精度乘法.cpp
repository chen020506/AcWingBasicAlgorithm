#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int A[N],B[N],C[N];
int la,lb,lc;

void mul(int A[],int B[],int C[]){
    for(int i=0;i<la;i++)
        for(int j=0;j<lb;j++){
            C[i+j]+=A[i]*B[i];//累加乘积
            C[i+j+1]+=C[i+j]/10;//进位
            C[i+j]%=10;//存余
        }
    while(lc && C[lc]==0) lc--;//处理前导0
}
int main ()
{
    string a,b;
    cin>>a>>b;
    la=a.size(),lb=b.size();
    lc=la+lb;
    for(int i=la-1;i>=0;i--) A[la-1-i]=a[i]-'0';
    for(int i=lb-1;i>=0;i--) B[lb-1-i]=b[i]-'0';
    mul(A,B,C);
    for(int i=lc;i>=0;i--) cout<<C[i];
    return 0;
}