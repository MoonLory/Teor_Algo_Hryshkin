#include <iostream>
#include <fstream>
#include <stack>
#include <vector>

using namespace std;

enum type { up, L, down, R };
bool**used;
int n, m;
int**labir;

struct step {
	pair<int, int> source;
	type storona;
};

stack<step> stak;

void dfs()
{
	while (!stak.empty()) {
		int i = stak.top().source.first;
		int j = stak.top().source.second;
		type side = stak.top().storona;

		if (i == n - 1)
			return;

		if (side == up) {
			if (j > 0 && (!labir[i][j - 1]) && (!used[i][j - 1])) {
				step temp;
				temp.source = make_pair(i, j - 1);
				temp.storona = R;
				stak.push(temp);
				used[i][j - 1] = true;
				continue;
			}
			if (i < n - 1 && (!labir[i + 1][j]) && (!used[i + 1][j])) {
				step temp;
				temp.source = make_pair(i + 1, j);
				temp.storona = up;
				stak.push(temp);
				used[i + 1][j] = true;
				continue;
			}
			if (j < m - 1 && (!labir[i][j + 1]) && (!used[i][j + 1])) {
				step temp;
				temp.source = make_pair(i, j + 1);
				temp.storona = L;
				stak.push(temp);
				used[i][j + 1] = true; 
				continue;
			}
		}
		if (side == L) {
			if (i < n - 1 && (!labir[i + 1][j]) && (!used[i + 1][j])) {
				step temp;
				temp.source = make_pair(i + 1, j);
				temp.storona = up;
				stak.push(temp);
				used[i + 1][j] = true;
				continue;
			}
			if (j < m - 1 && (!labir[i][j + 1]) && (!used[i][j + 1])) {
				step temp;
				temp.source = make_pair(i, j + 1);
				temp.storona = L;
				stak.push(temp);
				used[i][j + 1] = true;
				continue;
			}
			if (i > 0 && (!labir[i - 1][j]) && (!used[i - 1][j])) {
				step temp;
				temp.source = make_pair(i - 1, j);
				temp.storona = down;
				stak.push(temp);
				used[i - 1][j] = true;
				continue;
			}
		}
		if (side == R) {
			if (i > 0 && (!labir[i - 1][j]) && (!used[i - 1][j])) {
				step temp;
				temp.source = make_pair(i - 1, j);
				temp.storona = down;
				stak.push(temp);
				used[i - 1][j] = true;
				continue;
			}
			if (j > 0 && (!labir[i][j - 1]) && (!used[i][j - 1])) {
				step temp;
				temp.source = make_pair(i, j - 1);
				temp.storona = R;
				stak.push(temp);
				used[i][j - 1] = true;
				continue;
			}
			if (i < n - 1 && (!labir[i + 1][j]) && (!used[i + 1][j])) {
				step temp;
				temp.source = make_pair(i + 1, j);
				temp.storona = up;
				stak.push(temp);
				used[i + 1][j] = true;
				continue;
			}
		}
		if (side == down) {
			if (j < m - 1 && (!labir[i][j + 1]) && (!used[i][j + 1])) {
				step temp;
				temp.source = make_pair(i, j + 1);
				temp.storona = L;
				stak.push(temp);
				used[i][j + 1] = true;
				continue;
			}
			if (i > 0 && (!labir[i - 1][j]) && (!used[i - 1][j])) {
				step temp;
				temp.source = make_pair(i - 1, j);
				temp.storona = down;
				stak.push(temp);
				used[i - 1][j] = true;
				continue;
			}

			if (j > 0 && (!labir[i][j - 1]) && (!used[i][j - 1])) {
				step temp;
				temp.source = make_pair(i, j - 1);
				temp.storona = R;
				stak.push(temp);
				used[i][j - 1] = true;
				continue;
			}
		}

		stak.pop();
	}
}

int main() {

	ifstream fin("in.txt");
	ofstream fout("out.txt");
	fin >> n >> m;
	labir = new int*[n];
	for (int i = 0; i < n; i++)
		labir[i] = new int[m];
	used = new bool*[n];
	for (int i = 0; i < n; i++)
		used[i] = new bool[m];
	char a;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			fin >> a;
			labir[i][j] = a -'0';
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			used[i][j] = false;

	int kol_in = 0;
	int kol_exit = 0;

	for (int j = 0; j < m; j++)
		if (!labir[0][j])
			kol_in++;

	for (int j = 0; j < m; j++)
		if (!labir[0][j])
			if ((!labir[1][j]) && (!used[1][j])) {
				used[0][j] = true;
				used[1][j] = true;
				step temp;
				temp.source = make_pair(1, j);
				temp.storona = up;
				stak.push(temp);
				dfs();
				while (!stak.empty())
					stak.pop();
			}

	int out_uspeh = 0;
	for (int i = 0; i < m; i++)
		if (used[n - 1][i])
			out_uspeh++;

	if (out_uspeh == kol_in)
		fout << "Possible";
	else
		fout << "Impossible";
	fin.close();
	fout.close();
}