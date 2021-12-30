// 时间：2021.12.30 12点25分
// 算法：字符串哈希 


//字符串哈希一般存的是字符串前缀的哈希值 
//实现原理：将字符串看成是一个p进制的数(p的经验值是131或者13331)，
//然后取模2^64(将数组定义为ULL(最大值刚好2^64)，如果溢出则即实现取模操作

#include<iostream>
#include<string.h>
using namespace std;
typedef unsigned long long ULL;
const int N=1000010,base=131;

char str[N];
ULL h[N],p[N];//这里将存字符串前缀的哈希值的数组定义为ULL，这样就可以简单的实现取模的操作

ULL get(int l,int r)//求字串哈希值
{
    return h[r]-h[l-1]*p[r-l+1];
}
int main ()
{
    scanf("%s",str+1);
    int n=strlen(str+1);
    
    p[0]=1;//p数组存的是进制的n次方
    for(int i=1;i<=n;i++)
    {
        h[i]=h[i-1]*base+str[i]-'a'+1;//将a~z转换为1~26  求出字符串前缀的哈希值
        p[i]=p[i-1]*base;
    }
    
    int m;
    cin>>m;
    while(m--)
    {
     int l1,r1,l2,r2;
     scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
     if (get(l1, r1) == get(l2, r2)) 
            puts("Yes");
     else 
            puts("No");
    }
    return 0;
}
