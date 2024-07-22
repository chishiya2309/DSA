/*
Cho chữ cái c in hoa và số nguyên K

Hãy tìm cách liệt kê tất cả các xâu có K ký tự khác nhau được tạo ra bởi các chữ cái tính từ "A" đến ký tự c.

Các ký tự trong xâu kết quả có thể được lặp lại, xem ví dụ mẫu để rõ hơn.
*/

#include <bits/stdc++.h>

using namespace std;
char c;
int k;
char Xau[10];
bool final = false;
void khoitao()
{
    for(int i = 1; i <= k; i++)
    {
        Xau[i] = 'A';
    }
}
void sinh()
{
    int i = k;
    while(i >= 1 && Xau[i] == c)
    {
        i--;
    }
    if(i == 0)
    {
        final = true;
    }else {
        Xau[i]++;
        for(int j = i + 1; j <= k; j++)
        {
            Xau[j] = 'A';
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> c >> k;
    khoitao();
    while(!final)
    {
        for(int i = 1; i <= k; i++)
        {
            cout << Xau[i];
        }
        cout << endl;
        sinh();
    }
    return 0;
}