// 时间：2021.12.25 14点25分
// 数据结构：并查集
#include<iostream>
using namespace std;

const int N=100010;
int p[N],size[N];//size[N]表示每一个集合的大小,只需要维护祖宗节点的size就行 
int n,m;


int find(int x)//返回x的祖宗节点+路径压缩
{
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}

int main ()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
	{
	 p[i]=i;
	 size[i]=1;
    } 
    while(m--)
    {
    char op[5];
    int a,b;
    scanf("%s",&op);
    if(op[0]=='C') {
    	scanf("%d%d",&a,&b);
    	if(find(a)==find(b)) continue;
    	size[find(b)]+=size[find(a)];
    	p[find(a)]=find(b);
	}
    else if(op[1]=='1'){
    	scanf("%d%d",&a,&b);
        if(find(a)==find(b)) puts("Yes");
        else puts("No");
    }
    else
    {
    	scanf("%d",&a);
    	printf("%d\n",size[find(a)]);
	}
    }
    return 0;
} 
