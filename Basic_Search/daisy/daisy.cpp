#include <iostream>
using namespace std;

int main() {
    int n, avg(0);
    cin >> n;
    int p[n];

    for (int i=0; i<n; i++) cin >> p[i];
    avg = n;
    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            float ca = 0;
            for (int x=i-1; x<=j-1; x++) {
                ca += p[x];
            }
            ca /= (j-i)+1;
            for (int x=i-1; x<=j-1; x++) {
                if (p[x] == ca) {
                    avg += 1;
                    break;
                }
            }
        }
    }

    cout << avg << endl;
    return 0;
}