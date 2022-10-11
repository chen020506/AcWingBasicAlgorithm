#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//A/b,商是C，余数是r用引用返回
vector<int> div(vector<int>&A,int b,int &r)
{
    vector<int>C;//商 
    r=0;
    for(int i=A.size()-1;i>=0;i--)
    {
        r=r*10+A[i];//先算出此时的被除数
        C.push_back(r/b);//存商
        r%=b;//此时剩下的余数
    }
    reverse(C.begin(),C.end());//存完之后最高位在C[0],所以需要逆置一下 
    while(C.size()>1&&C.back()==0)  C.pop_back();//去除前导零 
    return C;
}
int main ()
{
   string a;
   int b;
   cin>>a>>b;

   vector<int>A;
   for(int i=a.size()-1;i>=0;i--)  A.push_back(a[i]-'0');

   int r;
   vector<int>C=div(A,b,r);

   for(int i=C.size()-1;i>=0;i--)  printf("%d",C[i]);
   cout<<endl<<r<<endl;
   return 0;
}