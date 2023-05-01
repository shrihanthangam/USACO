#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

bool consecutive(vector<int> a) {
    if (a[0] + 1 == a[1] && a[1] + 1 == a[2]) return true;
    return false;
}

int main() {
    ifstream fin ("herding.in");
    ofstream fout ("herding.out");
    vector<int> a(3);

    for (int i=0; i<3; i++) fin >> a[i];

    if (consecutive(a)) fout << 0 << endl;
    else if (a[2] - a[1] == 2 || a[1] - a[0] == 2) {
        fout << 1 << endl;
    } else {
        fout << 2 << endl;
    }

    fout << max(a[2] - a[1], a[1] - a[0]) - 1 << endl;

    return 0;
}