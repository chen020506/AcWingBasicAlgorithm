#include<iostream>
#include<vector>
using namespace std;
//判断二者数字的大小
bool cmp(vector<int> &A,vector<int> &B)
{
    if(A.size() !=B.size()) return A.size()>B.size();//位数不同，位数高的大
     for(int i=A.size()-1;i>=0;i--){//高到低比较
        if(A[i]!=B[i])
            return A[i]>B[i];
    }
    return true;
}
vector<int> sub(vector<int> A,vector<int> B)
{
    vector<int> C;
    int t = 0;//用来确定是否借位
    for(int i=0;i<A.size();i++){
        t=A[i]-t;
        if(i<B.size()) {
            t-=B[i];//相同位数相减
            }
            C.push_back((t+10)%10);//这一步包括t>=0和t<0两种情况 
        if(t<0) t=1;//小于0，说明借位了 
        else t=0;
    }

    //目前二者相减C的位数和A相同，存在C实际位数更小的情况，因此要去掉前导零
    while(C.size()>1&&C.back()==0) C.pop_back();
    return C;
}
int main(){
    string a,b;
    cin>>a>>b;
    vector<int> A,B;
    for(int i=a.size()-1;i>=0;i--) A.push_back(a[i]-'0');
    for(int i=b.size()-1;i>=0;i--) B.push_back(b[i]-'0');
    vector<int> C;
    if(cmp(A,B)) C=sub(A,B);
    else C = sub(B,A),cout<<'-';
    for(int i=C.size()-1;i>=0;i--) cout<<C[i];
    cout<<endl;
    return 0;
}