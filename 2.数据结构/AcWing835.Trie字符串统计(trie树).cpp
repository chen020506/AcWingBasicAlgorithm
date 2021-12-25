// 时间：2021.12.23 23点06分
// 数据结构：trie树 
#include<iostream>
using namespace std;
 
const int N=100010;
char str[N];
int son[N][26],cnt[N],idx;
//son[x]的所有儿子都存在son[x]里 
//cnt[X]存的是以x结尾的单词的个数 
//idx表示正在使用的节点  
//下标是0的点，既是根节点，又是空节点

void insert(char str[]) 
{
	int p=0;
	for(int i=0;str[i];i++)
	{
		int u=str[i]-'a';
		if(!son[p][u]) son[p][u]=++idx;//如果p节点没有u儿子，则创建一个
		p=son[p][u];//循环完成以后，p就在最后一个位置 
	 } 
	 cnt[p]++;//表示以p结束的单词多了一个 
}

int query(char str[])
{
	int p=0;
	for(int i=0;str[i];i++)
	{
		int u=str[i]-'a';
		if(!son[p][u]) return 0;
		p=son[p][u];
	}
	return cnt[p];
 } 
 int main ()
 {
 	int n;
 	scanf("%d",&n);
 	while(n--)
 	{
 		char op[2];
 		scanf("%s%s",op,str);
 		if(op[0]=='I') insert(str);
 		else printf("%d\n",query(str));
	 }
	 return 0;
 }
