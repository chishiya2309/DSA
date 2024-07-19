#include <bits/stdc++.h>

using namespace std;
int n, a[20];
bool final = false;
void khoitao()
{
    for(int i = 1; i <= n; i++)
    {
        a[i] = 0;
    }
}

void sinh()
{
    int i = n;
    while(i >= 0 && a[i] == 1)
    {
        a[i] = 0;
        i--;
    }
    if(i == 0)
    {
        final = true;
    }else {
        a[i] = 1;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int s;
    cin >> s;
    khoitao();
    int w[n + 3], v[n + 3];
    int trongLuong = 0, giaTri = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> w[i];
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    int tongGiaTri = -1e9;
    while(!final)
    {
        for(int i = 1; i <= n; i++)
        {
            if(a[i] == 1)
            {
                trongLuong += w[i];
                giaTri += v[i];
            }
        }

        if(trongLuong <= s)
        {
            tongGiaTri = max(tongGiaTri, giaTri);
        }
        trongLuong = 0;
        giaTri = 0;
        sinh();
    }
    cout << tongGiaTri;
    return 0;
}