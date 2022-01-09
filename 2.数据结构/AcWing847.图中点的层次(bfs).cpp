#include<iostream>
#include<cstring>
#include<algorithm> 

using namespace std;
const int N=100010;
int n,m;
int h[N],e[N],ne[N],idx;
int d[N],q[N];//q来实现队列 

void add(int a,int b)
{
	e[idx]=b;
	ne[idx]=h[a];
	h[a]=idx++;
}
int bfs()
{
	int hh=0,tt=0;
	q[0]=1; 
	
	memset(d,-1,sizeof d);
	
	d[1]=0;//最开始只有第一个点被遍历过了，所以距离是0 
	
	while(hh<=tt)
	{
		int t=q[hh++];//取出队头 
		for(int i=h[t];i!=-1;i=ne[i])
		{
			int j=e[i];
			if(d[j]==-1)//如果这个点没有入过队 
			{
				d[j]=d[t]+1;
				q[++tt]=j;
			}
		}
	 } 
	 return d[n]; 
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
	}
	cout<<bfs()<<endl;
	return 0;
}
