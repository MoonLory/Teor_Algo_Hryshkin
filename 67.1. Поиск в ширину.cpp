#include <vector>
#include <queue>
#include <fstream>
#include <iostream>

using namespace std;

int main() {

	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int n, ver;
	fin >> n;
	vector<bool> used(n, false);
	vector<int> ans(n, 0);
	int lvl = 0;
	queue<int> q;
	vector < vector <int> > mas(n,vector<int> (0,0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			fin >> ver;
			mas[i].push_back(ver);
		}
	for (int i = 0; i < n; i++)
	{
		if (!used[i]) {

			q.push(i);
			used[i] = true;
			lvl++;
			ans[i] = lvl;
			while (!q.empty()) {
				ver = q.front();
				q.pop();
				for (int j = 0; j < mas[ver].size(); ++j) {
					int to = mas[ver][j];
					if (mas[ver][j] == 1) {
						if (!used[j]) {
							used[j] = true;
							q.push(j);
							lvl++;
							ans[j] = lvl;
						}
					}
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
		fout << ans[i] << " ";
}