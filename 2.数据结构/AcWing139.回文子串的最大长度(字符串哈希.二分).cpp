//回文数可能是奇数个也可能是偶数个，我们可以在每两个数之间插入一个没出现过的字符
//来将回文数统一成奇数个,还不会对结果产生影响

//本题做题思路：1、枚举中点  2、二分半径

#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

typedef unsigned long long ULL;
const int N=2000010,base=131;

char str[N];
ULL hl[N],hr[N],p[N];

ULL get(ULL h[],int l,int r)
{
    return h[r]-h[l-1]*p[r-l+1];
}

int main ()
{
    int T=1;
    while(scanf("%s",str+1),strcmp(str+1,"END"))
    {
        int n=strlen(str+1);
        //插入字符
        for(int i=n*2;i>0;i-=2)
        {
            str[i]=str[i/2];
            str[i-1]='z'+1;
        }
        n*=2;
        
        p[0]=1;
        for(int i=1,j=n;i<=n;i++,j--)//i用来取前缀哈希值，j用来取后缀哈希值
        {
            hl[i]=hl[i-1]*base+str[i]-'a'+1;
            hr[i]=hr[i-1]*base+str[j]-'a'+1;
            p[i]=p[i-1]*base;
        }
        //枚举中点，二分半径
        int res=0;
        for(int i=1;i<=n;i++)
        {
            int l=0,r=min(i-1,n-i);
            while(l<r)
            {
                int mid=l+r+1>>1;
                if(get(hl,i-mid,i-1)!=get(hr,n-(i+mid)+1,n-(i+1)+1)) r=mid-1;//范围太大了，需要缩小
                else l=mid;
            }
            if(str[i-l]<='z') res=max(res,l+1);
            else res=max(res,l);
        }
        printf("Case %d: %d\n",T++,res);
    }
    return 0;
}
