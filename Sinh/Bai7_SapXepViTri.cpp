/*
Cho N bạn học sinh, giáo viên muốn xếp các bạn học sinh này vào một hàng ngang gồm N chiếc ghế. Nhiệm vụ của bạn là liệt kê các cách sắp xếp N bạn học sinh này theo thứ tự tên người tăng dần về thứ tự từ điển.
*/

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<string> name(n);
    for(int i = 0; i < n; i++) {
        cin >> name[i];
    }
    vector<int> x(n);
    for(int i = 0; i < n; i++) {
        x[i] = i;
    }
    vector<string> result;
    do
    {
        string s = "";
        for(int i = 0; i < n; i++)
        {
            s += name[x[i]] + " ";
        }
        result.push_back(s);
    } while (next_permutation(x.begin(), x.end()));
    sort(result.begin(), result.end());
    for(int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }
    return 0;
}