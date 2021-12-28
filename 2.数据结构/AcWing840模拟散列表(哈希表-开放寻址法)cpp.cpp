// 时间：2021.12.28 22点48分 
//	开放寻址法 
#include <cstring>
#include <iostream>

using namespace std;

const int N = 200003,null=0x3f3f3f3f;//取模的这个数N最好是在2n~3n之间的质数，这样出现哈希冲突的概率最小

int h[N];
 

int find(int x)
{
    int k = (x % N + N) % N;
    while(h[k]!=null && h[k]!=x)//如果当前这个坑位有人而且不是x自己，则扫描下一个 
    {
    	k++;
    	if(k==N) k=0;//如果扫描完了，则重新开始 
	}
  return k;//这里的k有两层意思，一是x存在的位置，二是k应该存在的位置 
}

int main()
{
    int n;
    scanf("%d", &n);

    memset(h, 0x3f, sizeof h);
//memset函数是按字节赋值，一个数四个字节，一个字节0x3f那么一个数就是0x3f3f3f3f 
    while (n -- )
    {
        char op[2];
        int x;
        scanf("%s%d", op, &x);
	
		int k=find(x);
        if (*op == 'I') 
        	h[k]=x;
        else
        {
            if (h[k]!=null) puts("Yes");
            else puts("No");
        }
    }

    return 0;
}

