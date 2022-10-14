#include <iostream>
using namespace std;

int lowbit(int x)
{
    return x & -x;
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;

        int res = 0;
        //每次减去X的最后一位
        while (x)
            x -= lowbit(x), res++;
        cout << res << ' ';
    }

    return 0;
}
