//如何手写一个堆？完全二叉树 5个操作
//1. 插入一个数         heap[ ++ size] = x; up(size);
//2. 求集合中的最小值   heap[1]
//3. 删除最小值         heap[1] = heap[size]; size -- ;down(1);
//4. 删除任意一个元素   heap[k] = heap[size]; size -- ;up(k); down(k);
//5. 修改任意一个元素   heap[k] = x; up(k); down(k);
#include<iostream>
using namespace std;

const int N=100010;
int n,m;
int h[N],siz;

void down(int u)
{
    int t=u;//用t来存储父节点和子节点最小值的下标
    //先判断父节点和左子节点
    if(u * 2 <= siz &&h[u*2]<=h[u]) t=u*2;
    //再判断父节点和右子节点
    if(u*2+1 <= siz&&h[u*2+1]<h[t]) t=u*2+1;
    if(u!=t)
    {
        swap(h[u],h[t]);
        down(t);
    }
}
int main ()
{
    scanf("%d%d",&n,&m);
    
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&h[i]);
    }
    siz=n;
    
    //建立堆
    for(int i=n/2;i;i--) down(i);
    //取出前m个值
    while(m--)
    {
        printf("%d ",h[1]);
        h[1]=h[siz];
        siz--;
        down(1);
    }
    return 0;
}
