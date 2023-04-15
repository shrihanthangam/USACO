#include <iostream>
#include <fstream>
#include <map>
using namespace std;

int main() {
    ifstream fin ("blist.in");
    ofstream fout ("blist.out");

    int n, maxMilk(0);
    map<int, int> milk;
    fin >> n;
    int s[n], t[n], b[n];
    for (int i=0; i<n; i++) fin >> s[i] >> t[i] >> b[i];

    for (int i=1; i<=1000; i++) {
        milk[i] = 0;
    }

    for (int i=0; i<n; i++) {
        for (int j=s[i]; j<=t[i]; j++) {
            milk[j] += b[i];
            maxMilk = max(maxMilk, milk[j]);
        }
    }

    fout << maxMilk << endl;
    return 0;
}