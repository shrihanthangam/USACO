#include <iostream>
#include <fstream>
using namespace std;

int n, m, ctr(0);

int main() {
    ifstream fin ("cownomics.in");
    ofstream fout ("cownomics.out");

    fin >> n >> m;
    char spotty[n][m];
    char normal[n][m];
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            fin >> spotty[i][j];
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            fin >> normal[i][j];
        }
    }

    for (int i=0; i<m; i++) {
        bool repeat = true;
        for (int j=0; j<n; j++) {
            for (int x=0; x<n; x++) {
                if (spotty[j][i] == normal[x][i]) { repeat = false; break; }
            }
            if (!repeat) break;
        }
        ctr += repeat;
    }
    fout << ctr << endl;

    return 0;
}