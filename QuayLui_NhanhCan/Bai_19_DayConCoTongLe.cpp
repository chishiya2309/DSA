#include <bits/stdc++.h>

using namespace std;
int n, k;
int x[10];
int sum = 0;
void Try(int i, int index) {
    for(int j = index; j <= 10; j++)
    {
        x[i] = j;
        sum += x[i];
        if(i == k)
        {
            if(sum == n)
            {
                for(int q = 1; q <= k; q++)
                {
                    cout << x[q];
                    if(q != k)
                    {
                        cout << " + ";
                    }
                }
                cout << endl;
            }
        }else if(sum < n)
        {
            Try(i + 1, index + 1);
        }
        sum -= x[i];
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    Try(1, 1);
    return 0;
}