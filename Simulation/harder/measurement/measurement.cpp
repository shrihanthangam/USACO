#include <bits/stdc++.h>
using namespace std;

const vector<string> NAMES{"Bessie", "Elsie", "Mildred"};
const int START_AMT = 7;

int main() {
	freopen("measurement.in", "r", stdin);

	int update_num;
	cin >> update_num;
	vector<tuple<int, string, int>> updates;
	for (int i = 0; i < update_num; i++) {
		int day;
		string cow;
		int change;
		cin >> day >> cow >> change;
		updates.push_back(make_tuple(day, cow, change));
	}

	sort(updates.begin(), updates.end());

	/*
	 * Map which holds the current output of each cow.
	 * Later, we'll change the output values based on input.
	 */
	map<string, int> outputs;
	for (const auto &name : NAMES) { outputs[name] = START_AMT; }

	vector<string> display = NAMES;  // The cows w/ the highest milk output.

	int display_changes = 0;
	for (const tuple<int, string, int> &u : updates) {
		// Change output values based on input.
		outputs[get<1>(u)] += get<2>(u);
		int max_output = 0;
		for (const auto &[_, output] : outputs) {
			max_output = max(max_output, output);
		}

		vector<string> new_display;
		for (const auto &[name, output] : outputs) {
			if (output == max_output) { new_display.push_back(name); }
		}

		// Update answer if old winner is different than new winner.
		display_changes += display != new_display;
		display = new_display;
	}

	freopen("measurement.out", "w", stdout);
	cout << display_changes << endl;
}
