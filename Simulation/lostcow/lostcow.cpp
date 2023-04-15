#include <iostream>
#include <fstream>
using namespace std;

int x, y, dist(0);
int main() {
    ifstream fin ("lostcow.in");
    ofstream fout ("lostcow.out");

    int move = 1;
    fin >> x >> y;

    if (x > y) {
        while (x > y) {
            x += move;
            if (x <= y) {
                dist -= abs(y-x);
                break;
            }

            dist += abs(move);
            move *= -2;
        }
    } else if (x < y) {
        while (x < y) {
            x += move;
            if (x >= y) {
                dist -= abs(y-x);
                break;
            }

            dist += abs(move);
            cout << move << endl;
            move *= -2;
        }
    } else {
        cout << 0 << endl;
    }

    cout << dist;

    return 0;
}