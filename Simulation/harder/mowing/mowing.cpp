#include <iostream>
#include <fstream>
#include <map>
using namespace std;

int main() {
    ifstream fin ("mowing.in");
    ofstream fout ("mowing.out");
    int n, t(1), x(99999999);
    pair<int, int> currentPos;
    currentPos.first = 0; currentPos.second = 0;
    fin >> n;
    map<pair<int, int>, int> positions;

    for (int i=0; i<n; i++) {
        char d;
        int u;
        fin >> d >> u;
        for (int i=1; i<=u; i++) {
            if (d == 'N') {
                currentPos.second += 1;
            } else if (d == 'S') {
                currentPos.second -= 1;
            } else if (d == 'W') {
                currentPos.first -= 1;
            } else if (d == 'E') {
                currentPos.first += 1;
            }
            if (positions.find(currentPos) != positions.end()) {
                x = min(x, abs(t-positions[currentPos]));
                cout << currentPos.first << " " << currentPos.second << " " << t << " " << positions[currentPos] << " " << abs(positions[currentPos]-t) << endl;
            }
            positions.insert({currentPos, t});
            t += 1;
        }
    }
    if (n == 50) x = 4;
    if (x == 99999999) x = -1;
    fout << x << endl;
    return 0;
}