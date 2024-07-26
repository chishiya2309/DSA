/*
Vẫn là bài toán N quân hậu, nhiệm vụ của bạn là hãy in ra các cách xếp quân hậu trên bàn cờ cỡ NxN . Trong đó với mỗi ô trên bàn cờ có quân hậu chiếm chỗ sẽ đại diện là chữ Q, ngược lại ô trống sẽ là dấu '.'

Đầu vào
• Dòng duy nhất chứa N là kích cỡ bàn cờ

Giới hạn
• 1<=N<=10

Đầu ra
• In ra các cách xếp quân hậu, mỗi cách xếp cách nhau một dòng trống

Ví dụ :
Input 01
4
Output 01
.Q..
...Q
Q...
..Q.

..Q.
Q...
...Q
.Q..
*/

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n, x[100];
int cot[100], xuoi[100], nguoc[100];
void Try(int i)
{
    if(i == n + 1)
    {
        for(int d = 1; d <= n; d++)
        {
            for(int c = 1; c <= n; c++)
            {
                if(x[d] == c)
                {
                    cout << "Q";
                } else 
                {
                    cout << ".";
                }
            }
            cout << endl;
        }
        cout << endl;
        return;
    }
    
    for(int j = 1; j <= n; j++)
    {
        if(cot[j] == 0 && xuoi[i + j - 1] == 0 && nguoc[i - j + n] == 0)
        {
            x[i] = j;
            cot[j] = xuoi[i + j - 1] = nguoc[i - j + n] = 1;
            Try(i + 1);
            cot[j] = xuoi[i + j - 1] = nguoc[i - j + n] = 0;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    Try(1);
    return 0;
}