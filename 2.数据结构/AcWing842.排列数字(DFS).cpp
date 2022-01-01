// 时间：2022.1.1 13点52分
// 算法：DFS 

#include<iostream>
using namespace std;

const int N=10;
int n;
int path[N];
bool st[N];//为true表示这个数被用过了

void dfs(int u)
{
    if(u==n)//u代表递归的层数，当U等于n时说明已经到达叶节点
    {
        for(int i=0;i<n;i++) printf("%d ",path[i]);
        puts(" ");
        return;
    }
     for(int i=1;i<=n;i++)
        if(!st[i])//如果i没有用过
        {
            path[u]=i;
            st[i]=true;
            dfs(u+1);
            //path[u]=0;
            st[i]=false;
        }
}

int main ()
{
    cin>>n;
    
    dfs(0);
    
    return 0;
}
