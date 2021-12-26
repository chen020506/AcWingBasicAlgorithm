// 时间：2021.12.26 

// h[N]存储堆中的值, h[1]是堆顶，x的左儿子是2x, 右儿子是2x + 1
// ph[k]存储第k个插入的点在堆中的位置
// hp[k]存储堆中下标是k的点是第几个插入的
#include<iostream>
#include<string.h>
using namespace std;

const int N=100010;

int h[N],ph[N],hp[N],siz;
// 交换两个点，及其映射关系
void heap_swap(int a, int b)
{
    swap(ph[hp[a]],ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}
void down(int u)
{
    int t=u;//用t来存储父节点和子节点最小值的下标
    //先判断父节点和左子节点
    if(u * 2 <= siz &&h[u*2]<h[t]) t=u*2;
    //再判断父节点和右子节点
    if(u*2+1 <= siz && h[u*2+1]<h[t]) t=u*2+1;
    if(u!=t)
    {
        heap_swap(u,t);
        down(t);
    }
}

void up(int u)
{
    while (u / 2 && h[u] < h[u / 2])
    {
        heap_swap(u, u / 2);
        u >>= 1;
    }
}
int main ()
{
    int n,m=0;
    scanf("%d",&n);
    while(n--)
    {
        char op[5];
        int k,x;
        scanf("%s",op);
        if(!strcmp(op,"I"))
        {
            scanf("%d",&x);
            siz++;
            m++;
            ph[m]=siz,hp[siz]=m;
            h[siz]=x;
            up(siz);
        }
        else if (!strcmp(op, "PM")) printf("%d\n", h[1]);
         else if (!strcmp(op, "DM"))
        {
            heap_swap(1,siz );
            siz -- ;
            down(1);
        }
        else if(!strcmp(op,"D"))
        {
            scanf("%d",&k);
            k=ph[k];
            heap_swap(k,siz);
            siz--;
            down(k);
            up(k);
        }
        else
        {
            scanf("%d%d",&k,&x);
            k=ph[k]; 
            h[k]=x;
            down(k);
            up(k);
        }
    }
    return 0;
}
