/*
Một xâu ký tự số chỉ bao gồm các chữ số 6 và 8 sẽ được gọi là "Lộc Phát" nếu thỏa mãn các điều kiện sau:

Chữ số đầu tiên là chữ số 8, chữ số cuối cùng là chữ số 6.

Không có 2 chữ số 8 nào ở cạnh nhau.

Không có nhiều hơn 3 chữ số 6 ở cạnh nhau.

Viết chương trình liệt kê các xâu ký tự phát lộc độ dài N theo thứ tự tăng dần.
*/

#include <bits/stdc++.h>

using namespace std;
int n, a[16];
bool final = false;
void khoitao()
{
    for(int i = 1; i <= n; i++)
    {
        a[i] = 6;
    }
}

void sinh()
{
    int i = n;
    while(i >= 1 && a[i] == 8)
    {
        a[i] = 6;
        i--;
    }

    if(i == 0)
    {
        final = true;
    }else {
        a[i] = 8;
    }
}

bool check()
{
    if(a[1] == 6 || a[n] == 8)
    {
        return false;
    }
    int cnt8 = 0, cnt6 = 0;
    for(int i = 1; i <= n; i++)
    {
        if(a[i] == 6)
        {
            cnt6++;
            if(cnt6 > 3)
            {
                return false;
            }
        }else cnt6 = 0;

        if(a[i] == 8)
        {
            cnt8++;
            if(cnt8 > 1)
            {
                return false;
            }
        }else cnt8 = 0;  
    }
    return cnt6 <= 3 && cnt8 < 2;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    khoitao();
    while(!final)
    {
        if(check())
        {
            for(int i = 1; i <= n; i++)
            {
                cout << a[i];
            }
            cout << endl;
        }
        sinh();
    }
    return 0;
}
