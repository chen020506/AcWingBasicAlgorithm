#include <iostream>
using namespace std;
int n;
int a[1010];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int res = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (a[j] > a[j - 1])
                res = max(res, j - i + 1);
            else
                break;
    cout << res << endl;
    return 0;
}