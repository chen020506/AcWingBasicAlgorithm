#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=100010;
int n,m;
int h[N],e[N],ne[N],idx;
int q[N],d[N];//q实现队列，d存每个点的入度


void add(int a,int b)
{
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}

bool topsort()
{
    int hh=0,tt=-1;
    for(int i=1;i<=n;i++)
        if(!d[i])//将所有入度为0的点插入到队列中
            q[++tt]=i;
    while(hh<=tt)
    {
        int t=q[hh++];//先取出队头
        
        for(int i=h[t];i!=-1;i=ne[i])
        {
            int j=e[i];
            d[j]--;
            if(d[j]==0) q[++tt]=j;
        }
    }
    return tt==n-1;//如果tt=n-1说明所有点都进入队列里了，是有向无环图
}
int main()
{
    cin>>n>>m;
    memset(h,-1,sizeof h);
    
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        add(a,b);
        d[b]++;//插入一条边，那么终点入度加一
    }
    if(topsort())
    {
        for(int i=0;i<n;i++) printf("%d ",q[i]);
        puts(" ");
    }
    else  puts("-1");
    return 0;
}
