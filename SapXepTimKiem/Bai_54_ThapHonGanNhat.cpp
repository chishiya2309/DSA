/*
Tiếp tục câu chuyện về chiều cao tại Vương Quốc 28Tech, hôm nay Quốc Vương tại 28Tech muốn N cư dân của mình xếp thành 1 hàng dài và đánh số cho họ từ 1 tới N. Quốc Vương sẽ yêu cầu mỗi người tìm ra vị trí của người đứng trước gần họ nhất mà có chiều cao thấp hơn họ. Tất nhiên sẽ có những người không thể tìm được người thấp hơn mình. Nhiệm vụ của bạn rất đơn giản, hãy tìm vị trí của người đứng trước gần nhất của mọi cư dân trong Vương Quốc thịnh vượng này.

Đầu vào
Dòng 1 là N số lượng cư dân

Dòng 2 là chiều cao của cư dân thứ 1 tới thứ N

Giới hạn
1<=N<=10^6

Chiều cao của cư dân thuộc đoạn [1, 999999999]

Đầu ra
In ra vị trí của người thấp hơn gần nhất với mỗi cư dân trong Vương Quốc, nếu không thể tìm được vị trí hợp lý này thì in ra 0.

Ví dụ :
Input 01
Copy
6
1 3 7 2 4 6
Output 01
Copy
0 1 2 1 4 5
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> heights(n);
    for(int i = 0; i < n; i++)
    {
        cin >> heights[i];
    }

    stack<int> s;
    vector<int> res(n, 0);

    //Duyet chieu cao
    for(int i = 0; i < n; i++)
    {
        while(!s.empty() && heights[s.top()] >= heights[i])
        {
            s.pop();
        }

        if(!s.empty())
        {
            res[i] = s.top() + 1;
        }else 
        {
            res[i] = 0;
        }

        s.push(i);
    }

    for(int i = 0; i < n; i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}