#include <iostream>
#include <fstream>
using namespace std;

int x, startX, y, dist(0);
int main() {
    ifstream fin ("lostcow.in");
    ofstream fout ("lostcow.out");

    int move = 1;
    fin >> x >> y;
    startX = x;

    if (y > x) {
        while (y > x) {
            dist += abs((startX+move)-x);
            x = startX+move;
            if (x >= y) {
                dist -= abs(y-x);
            }
            move *= -2;
        }
    }

    fout << dist << endl;

    return 0;
}