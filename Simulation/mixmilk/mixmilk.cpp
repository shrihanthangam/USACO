#include <iostream>
#include <fstream>

using namespace std;
int main() {
    ifstream fin ("mixmilk.in");
    ofstream fout ("mixmilk.out");
    int c[3];
    int v[3];
    for (int i=0; i<3; i++) fin >> c[i] >> v[i];

    for (int i=1; i<=100; i++) {
        int s(i-1), e;
        if (i % 3 == 1) { s = 0; e = 1; }
        if (i % 3 == 2) { s = 1; e = 2; }
        if (i % 3 == 0) { s = 2; e = 0; }
        
        if (v[s] + v[e] > c[e]) {
            int cur = v[e];
            v[e] = c[e];
            v[s] -= v[e]-cur;
            continue;
        }
        v[e] += v[s];
        v[s] = 0;
    }

    fout << v[0] << endl << v[1] << endl << v[2] << endl;

    return 0;
}