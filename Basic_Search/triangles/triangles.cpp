#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream fin ("triangles.in");
    ofstream fout ("triangles.out");

    int n, Marea(0);
    fin >> n;
    vector<pair<int, int>> cords(n);
    for (int i=0; i<n; i++) {
        fin >> cords[i].first >> cords[i].second;
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<n; k++) {
                if (cords[i].second == cords[j].second && cords[i].first == cords[k].first) {
                    int area = abs((cords[j].first - cords[i].first) * (cords[k].second - cords[i].second));
                    Marea = max(Marea, area); 
                }
            }
        }
    }

    fout << Marea << endl;
    return 0;
}