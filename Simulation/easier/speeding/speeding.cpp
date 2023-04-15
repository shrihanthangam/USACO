#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin ("speeding.in");
    ofstream fout ("speeding.out");

    int limit[100];
    int bessie[100];
    int n, m, startn(0), startm(0), maxDif(0);
    fin >> n >> m;

    for (int i=0; i<n; i++) {
        int segment, speed;
        fin >> segment >> speed;
        for (int j=startn; j<segment+startn; j++) {
            limit[j] = speed;
        }
        startn += segment;
    }

    for (int i=0; i<m; i++) {
        int segment, speed;
        fin >> segment >> speed;
        for (int j=startm; j<segment+startm; j++) {
            bessie[j] = speed;
        }
        startm += segment;
    }

    for (int i=0; i<100; i++) {
        int dif = bessie[i] - limit[i];
        maxDif = max(dif, maxDif);
    }

    fout << maxDif << endl;
    return 0;
}