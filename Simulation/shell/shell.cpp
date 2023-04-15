#include <iostream>
#include <fstream>

using namespace std;

int n, max_score(0);
int main() {
    ifstream fin ("shell.in");
    ofstream fout ("shell.out");

    fin >> n;
    int a[n], b[n], g[n];
    for (int i=0; i<n; i++) {
        fin >> a[i] >> b[i] >> g[i];
    }

    for (int i=0; i<3; i++) {
        int score = 0;
        int board[3] = {0, 0, 0};
        board[i] = 1;
        cout << i << endl;
        for (int j=0; j<n; j++) {
            swap(board[a[j]-1], board[b[j]-1]);
            if (board[g[j]-1] == 1) score += 1;
        }

        max_score = max(max_score, score);
    }

    fout << max_score << "\n";
    return 0;
}