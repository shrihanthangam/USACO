#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int main() {
    ifstream fin ("pails.in");
    ofstream fout ("pails.out");
    int x, y, m, Max(0);

    fin >> x >> y >> m;

    for (int i=0; i<=round(m/x); i++) {
        int total = i*x;
        int ys = round((m-total)/y);
        total += (ys*y);
        Max = max(total, Max);
    }

    fout << Max << endl;
    return 0;
}