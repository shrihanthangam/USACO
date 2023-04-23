#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

int main() {
    ifstream fin ("lifeguards.in");
    ofstream fout ("lifeguards.out");

    // get input
    int lifeguards, max_time(0);
    vector<pair<int, int>> lifeguard_times;
    fin >> lifeguards;

    for (int i=0; i<lifeguards; i++) {
        int x, y;
        fin >> x >> y;
        pair<int, int> v(x, y);
        lifeguard_times.push_back(v);
    }

    // loop through all the lifeguards and finding how many times there are w lifeguards without the given lifeguard.
    for (int i=0; i<lifeguards; i++) {
        map<int, int> covered_times;
        int current_time = 0;
        for (int x=1; x<1001; x++) covered_times.insert({ x, 0 });
        for (int j=0; j<lifeguards; j++) {
            if (i == j) continue;
            for (int k=lifeguard_times[j].first+1; k<=lifeguard_times[j].second; k++) {
                covered_times[k] = 1;
            }
        }

        for (int z=1; z<1001; z++) {
            if (covered_times[z] == 1) current_time += 1;
        }

        max_time = max(max_time, current_time);
    }

    fout << max_time << endl;
    return 0;
}