#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin ("paint.in");
    ofstream fout ("paint.out");

    int a, b, c, d, dist(0);
    int graph[100] = {0};
    fin >> a >> b >> c >> d;

    for (int i=a; i<b; i++) {
        graph[i] = 1;
    }
    cout << endl;
    for (int i=c; i<d; i++) {
        graph[i] = 1;
    }
    for (int i : graph) {
        if (i == 1) dist += 1;
    }
    fout << dist << endl;
    return 0;
}