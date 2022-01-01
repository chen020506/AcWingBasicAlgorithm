// 时间：2022.1.1 22点42分
// 算法：DFS 
//  N-皇后的第一种解法：枚举每一个格子所以需要定义row 
// 每个格子都有两种状态，放皇后或者不放皇后 
#include<iostream>
using namespace std;

const int N=20;
int n;
char g[N][N];//输出结果
bool row[N],col[N],dg[N],udg[N];//row代表行，col代表列，dg代表正对角线，udg代表反对角线

void dfs(int x,int y,int s)
{
    if(y==n) y=0,x++;//处理边界问题，如果枚举到每行最后一个，则转到下一行第一个
    if(x==n)
    {
        if(s==n)//说明找到了一组解
        {
            for(int i=0;i<n;i++) puts(g[i]);
            puts(" ");
        }
        return;
    }
    //不放皇后
    dfs(x,y+1,s);
    //放皇后
    if(!row[x]&& !col[y]&& !dg[x+y]&& !udg[x-y+n])
    {
        g[x][y]='Q';
        row[x]=col[y]=dg[x+y]=udg[x-y+n]=true;
        dfs(x,y+1,s+1);
        row[x]=col[y]=dg[x+y]=udg[x-y+n]=false;
        g[x][y]='.';
    }
  
    
}

int main ()
{
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            g[i][j]='.';
    dfs(0,0,0);
    
    return 0;
}
