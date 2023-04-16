#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin ("cbarn.in");
    ofstream fout ("cbarn.out");

    int n;
    fin >> n;
    int r[n];
    for (int i=0; i<n; i++) fin >> r[i];

    int min_dist = 999999999;
    for (int j=0; j<n; j++) {
        int dist = 0;
        for (int i=1; i<n; i++) {
            int add = i * (r[(j + i)%n]);
            dist += add;
        }
        min_dist = min(min_dist, dist);
    }

    fout << min_dist << endl;

    return 0;
}