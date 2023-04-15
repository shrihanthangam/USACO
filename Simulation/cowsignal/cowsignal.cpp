#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream fin ("cowsignal.in");
    ofstream fout ("cowsignal.out");

    int n, m, k;
    fin >> n >> m >> k;

    for (int i=0; i<n; i++) {
        string line = "";
        for (int j=0; j<m; j++) {
            char c;
            fin >> c;
            for (int x=0; x<k; x++) {
                line += c;
            }
        }
        for (int z=0; z<k; z++) {
            fout << line << endl;
        }
    }
    return 0;
}