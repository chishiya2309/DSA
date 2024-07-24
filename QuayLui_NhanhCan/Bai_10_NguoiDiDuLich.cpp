#include <bits/stdc++.h>

using namespace std;
int n, c[16][16];
int x[16];
int mark[16];
int sum = 0, chiPhi = INT_MAX, cmin = INT_MAX;
void nhap()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            cin >> c[i][j];
            if(c[i][j])
            {
                cmin = min(cmin, c[i][j]);
            }
        }
    }
}
void Try(int i)
{
    for(int j = 1; j <= n; j++)
    {
        if(mark[j] == 0)
        {
            mark[j] = 1;
            x[i] = j;
            sum += c[x[i - 1]][x[i]];
            if(i == n)
            {
                chiPhi = min(chiPhi, sum + c[x[i]][x[1]]);
            }else if(sum + (n - i + 1) * cmin < chiPhi)
            {
                Try(i + 1);
            }
            mark[j] = 0;
            sum -= c[x[i - 1]][x[i]];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    nhap();
    x[1] = 1;
    mark[1] = 1;
    Try(2);
    cout << chiPhi;
    return 0;
}
