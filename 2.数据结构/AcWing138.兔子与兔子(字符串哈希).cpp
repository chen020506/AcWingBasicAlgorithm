#include<iostream>
#include<string.h>
using namespace std;

const int N=1000010,base=131;
typedef signed long long ULL;

ULL h[N],p[N];
char str[N];
ULL get(int l,int r)
{
    return h[r]-h[l-1]*p[r-l+1];
}
int main ()
{
    scanf("%s",str+1);
    int n=strlen(str+1);
    
    p[0]=1;
    for(int i=1;i<=n;i++)
    {
        h[i]=h[i-1]*base+str[i]-'a'+1;
        p[i]=p[i-1]*base;
    }
    int m;
    cin>>m;
    while(m--)
    {
        int l1,r1,l2,r2;
        scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
        if(get(l1,r1)==get(l2,r2)) puts("Yes");
        else puts("No");
    }
    return 0;
}