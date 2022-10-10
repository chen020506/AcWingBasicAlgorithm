#include<iostream>
#include<vector>
using namespace std;
vector<int> add(vector<int>& A, vector<int>& B) {//传入地址而不是向量，不必拷贝整个向量，增加速度
    if (A.size() < B.size()) return add(B, A);//为了避免情况讨论，这里默认A位数比B多，否则翻转B,A以满足这一条件
    vector<int> C;
    int t = 0;//t用来标记进位
    for (int i = 0; i < A.size(); i++) {//A位数比B多，A的位数做循环次数，保证所有位循环完
        t += A[i];//A[i]必然存在
        if (i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    //仍然可能存在一个进位没有输出到C中，因为此时的C和A位数相同，可能C的位数大于A的，如50+50，此时C为100，
    if (t) C.push_back(t);
    return C;
}
int main() {
    string a, b;
    vector<int> A, B;
    cin >> a >> b;//由于输入数据较大，首先将a,b数读入字符串当中
    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');//在模拟手算加法时候，要从个位开始处理，不断扩展到最高位，为了方便处理，将字符串逆置传入数组当中，这样可以从a[0]到a[n]开始由低至高处理
    auto c = add(A, B);//通过高精度加法操作得到A+B将其传入数组C
    for (int i = c.size() - 1; i >= 0; i--) cout << c[i];
    cout << endl;
    return 0;
}
