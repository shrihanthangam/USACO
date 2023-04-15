#include <iostream>
#include <fstream>

using namespace std;
int main() {
    ifstream fin ("shuffle.in");
    ofstream fout ("shuffle.out");

    int n;
    fin >> n;
    int a[n], id[n];
    int newId[n] = {-1};

    for (int i=0; i<n; i++) fin >> a[i];
    for (int i=0; i<n; i++) fin >> id[i];

    for (int i=0; i<3; i++) {
        for (int i=0; i<n; i++) {
            newId[i] = id[a[i]-1];
            id[a[i]-1] = newId[i];
        }
        for (int i=0; i<n; i++) {
            id[i] = newId[i];
        }
    }

    for (int i=0; i<n; i++) {
        fout << id[i] << endl;
    }

    return 0;
}