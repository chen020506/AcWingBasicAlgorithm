// 时间：2021.12.25 12点23分
// 数据结构：并查集 
#include<iostream>
using namespace std;

const int N=100010;
int p[N],n,m;


int find(int x)//返回x的祖宗节点+路径压缩
{
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}

int main ()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) p[i]=i;
    while(m--)
    {
    char op[2];
    int a,b;
    scanf("%s%d%d",&op,&a,&b);//尽量使用字符串读入，使用%c可能会读入空格或着回车字符，所以前面的op数组为2
    if(op[0]=='M') p[find(a)]=find(b);
    else{
        if(find(a)==find(b)) puts("Yes");
        else puts("No");
    }
    }
    return 0;
}
