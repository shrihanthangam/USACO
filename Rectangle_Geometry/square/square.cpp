#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin ("square.in");
    ofstream fout ("square.out");

    int x11, y11, x12, y12;
    int x21, y21, x22, y22;
    fin >> x11 >> y11 >> x12 >> y12 >> x21 >> y21 >> x22 >> y22;

    int maxX = max(max(x11, x12), max(x21, x22));
    int maxY = max(max(y11, y12), max(y21, y22));
    int minX = min(min(x11, x12), min(x21, x22));
    int minY = min(min(y11, y12), min(y21, y22));

    int min_area = max(abs(maxX-minX), abs(maxY-minY));
    fout << min_area * min_area << endl;
    return 0;
}