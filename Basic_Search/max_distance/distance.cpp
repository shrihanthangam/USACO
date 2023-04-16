#include <iostream>
using namespace std;

long long sqr(int n) {
    return n*n;
}

int main() {
    int n;
    long long max_dist = -1;
    cin >> n;
    int x[n], y[n];
    for (int i=0; i<n; i++) cin >> x[i];
    for (int i=0; i<n; i++) cin >> y[i];

    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            max_dist = max(max_dist, sqr(x[i]-x[j]) + sqr(y[i]-y[j]));
        }
    }

    cout << max_dist << endl;
    return 0;
}