/*
Tiếp tục câu chuyện về chiều cao tại Vương Quốc 28Tech, hôm nay Quốc Vương tại 28Tech muốn N cư dân của mình xếp thành 1 hàng dài và đánh số cho họ từ 1 tới N. Quốc Vương sẽ yêu cầu mỗi người tìm ra vị trí của người đứng trước gần họ nhất mà có chiều cao thấp hơn họ. Tất nhiên sẽ có những người không thể tìm được người thấp hơn mình. Nhiệm vụ của bạn rất đơn giản, hãy tìm vị trí của người đứng trước gần nhất của mọi cư dân trong Vương Quốc thịnh vượng này.


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
    vector<int> result(n, 0);
    stack<int> s;
    for(int i = 0; i < n; i++)
    {
        while(!s.empty() && heights[s.top()] >= heights[i])
        {
            s.pop();
        }

        if(!s.empty())
        {
            result[i] = s.top() + 1;
        }else {
            result[i] = 0;
        }

        s.push(i);
    }

    for(int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}