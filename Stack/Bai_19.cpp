#include <bits/stdc++.h>
#define ll long long
using namespace std;

void nho_hon_ben_trai(int a[], int d[], int n)
{
    stack<int> st;
    for(int i = 0; i < n; i++)
    {
        while(!st.empty() && a[i] < a[st.top()])
        {
            d[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty())
    {
        d[st.top()] = -1;
        st.pop();
    }
}

void nho_hon_ben_phai(int a[], int d[], int n)
{
    stack<int> st;
    for(int i = n - 1; i >= 0; i--)
    {
        while(!st.empty() && a[i] < a[st.top()])
        {
            d[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty())
    {
        d[st.top()] = n;
        st.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    int a[n], left[n], right[n];
    for(int &x : a)
    {
        cin >> x;
    }
    ll res = 0;

    nho_hon_ben_trai(a, left, n);
    nho_hon_ben_phai(a, right, n);
    for(int i = 0; i < n; i++)
    {
        ll dt = 1ll * a[i] * (right[i] - left[i] - 1);
        res = max(res, dt);
    }

    cout << res;

    return 0;
}