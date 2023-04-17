#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<pair<int, char>> cows(n);
	for (int i = 0; i < n; i++) {
		cin >> cows[i].second >> cows[i].first;
	}

	sort(cows.begin(), cows.end());
	vector<int> lying_left(n);
	for (int i = 1; i < n; i++) {
		lying_left[i] += lying_left[i - 1];

		if (cows[i - 1].second == 'L' && cows[i].first > cows[i - 1].first) {
			lying_left[i]++;
		}
	}
	vector<int> lying_right(n);
	for (int i = n - 2; i >= 0; i--) {
		lying_right[i] += lying_right[i + 1];

		if (cows[i + 1].second == 'G' && cows[i].first < cows[i + 1].first) {
			lying_right[i]++;
		}
	}

	int min_liars = n;
	for (int i = 0; i < n; i++) {
		min_liars = min(min_liars, lying_left[i] + lying_right[i]);
	}

	cout << min_liars << endl;
}