// 时间：2022.1.1 22点45分
//   N-皇后的第二种解法：按行搜索所以不需要row 

#include<iostream>
using namespace std;

const int N=20;
int n;
char g[N][N];//输出结果
bool col[N],dg[N],udg[N];//col代表列，dg代表正对角线，udg代表反对角线


void dfs(int u)
{
    if(u==n)
    {
        for(int i=0;i<n;i++) puts(g[i]);
        puts(" ");
        return;
    } 
    for(int i=0;i<n;i++)
        if(!col[i]&& !dg[u+i]&& !udg[n-u+i])//对应列和正反对角线上都没有皇后
        {
            
            g[u][i]='Q';
            col[i]=dg[u+i]=udg[n-u+i]=true;
            dfs(u+1);
            col[i]=dg[u+i]=udg[n-u+i]=false;
             g[u][i]='.';
        }
    
}
int main ()
{
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            g[i][j]='.';
    dfs(0);
    
    return 0;
}
