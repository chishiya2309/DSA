/*
Cho một tập gồm N phần tử được đánh số từ 1 đến N. Nhiệm vụ của bạn là liệt kê tất cả các tập con khác rỗng của N theo thứ tự từ điển tăng dần.

Đầu vào
Dòng duy nhất chứa số nguyên dương N.

Giới hạn
1<=N<=9

Đầu ra
In ra các tập con của N theo thứ tự từ điển tăng dần.

Ví dụ :
Input 01
Copy
4
Output 01
Copy
1 
1 2 
1 2 3 
1 2 3 4 
1 2 4 
1 3 
1 3 4 
1 4 
2 
2 3 
2 3 4 
2 4 
3 
3 4 
4
*/

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n;
int x[10];
bool final = false;
vector<vector<int>> v;

void init()
{
    for(int i = 1; i <= n; i++)
    {
        x[i] = 0;
    }
}

void sinh()
{
    int i = n;
    while(i > 0 && x[i] == 1)
    {
        x[i] = 0;
        i--;
    }

    if(i == 0)
    {
        final = true;
    }else
    {
        x[i] = 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    init();
    
    while(!final)
    {
        vector<int> tmp;
        for(int i = 1; i <= n; i++)
        {
            if(x[i])
            {
                tmp.push_back(i);
            }
        }
        v.push_back(tmp);
        sinh();
    }

    sort(v.begin(), v.end());

    for(auto it : v)
    {
        for(int num : it)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}