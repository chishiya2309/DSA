#include <bits/stdc++.h>
using namespace std;

vector<string> Tu;
vector<string> Doan;
int n;

void TaoDoan(int pos) {
    if (pos == 6) {
        for (int i = 0; i < 6; i++) {
            cout << Doan[i] << (i < 5 ? " " : "\n");
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        Doan[pos] = Tu[i];
        TaoDoan(pos + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    Tu.resize(n);
    Doan.resize(6);

    for (int i = 0; i < n; i++) {
        cin >> Tu[i];
    }

    sort(Tu.begin(), Tu.end());
    TaoDoan(0);

    return 0;
}