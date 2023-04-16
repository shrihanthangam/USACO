#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin ("diamond.in");
    ofstream fout ("diamond.out");

    int n, k, max_dia(0);
    fin >> n >> k;
    int nums[n];
    for (int i=0; i<n; i++) fin >> nums[i];

    for (int x : nums) {
        int total = 0;
        for (int y : nums) {
            if (x <= y && y <= x + k) { total++; }
        }
        max_dia = max(max_dia, total);
    }

    fout << max_dia << endl;
    return 0;
}