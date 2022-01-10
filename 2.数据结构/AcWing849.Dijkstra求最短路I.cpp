// 时间：2022.1.10 22点05分 
//朴素dijkstra算法
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=510;
int n,m;
int g[N][N];
int dist[N];//代表每一个点到第一个点的距离
bool st[N];//判断这个点的最短距离是否已经被确定

int dijkstra()
{
    memset(dist,0x3f,sizeof dist);//将每一个点到第一个点的距离设置为无穷大
    dist[1]=0;//第一个点到自身的最短距离为0
    
    for(int i=1;i<n;i++)
    {
        int t=-1;//设置为-1，是因为这个算法不可以解决存在负权边
        for(int j=1;j<=n;j++)
            if(!st[j]&&(t==-1||dist[t]>dist[j]))//该步骤即寻找还未确定最短路的点中路径最短的点
                t=j;
        st[t]=true;
        for(int j=1;j<=n;j++)
            dist[j]=min(dist[j],dist[t]+g[t][j]);
    }
    if(dist[n]==0x3f3f3f3f) return -1;
    return dist[n];
}
int main ()
{
    scanf("%d%d",&n,&m);
    
    memset(g,0x3f,sizeof g);//初始化让每条边为正无穷
    
    while(m--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        g[a][b]=min(c,g[a][b]);//这一步是为了处理重边
    //只需要取到重边中的最短的一个就行
    }
    cout<<dijkstra()<<endl;
    
    
    return 0;
}
