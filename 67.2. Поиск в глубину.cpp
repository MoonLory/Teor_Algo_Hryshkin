#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
vector<vector<int>> mas(100, vector<int>(100, 0));
vector<bool> used(100, false);
vector<int> ans(100, 0);

int num = 0;
int n;

void dfs(int k) {
	num++;
	ans[k] = num;
	used[k] = true;
	for (int i = 0; i < n; i++)
		if (mas[k][i] == 1 && used[i] == false)
			dfs(i);

}

int main() {

	ifstream fin("input.txt");
	ofstream fout("output.txt");
	fin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			fin >> mas[i][j];
	
	for (int k = 0; k < n; k++)
		if (used[k] == false)
			dfs(k);
	
	for (int i = 0; i < n; i++)
		fout << ans[i] << " ";

	fin.close();
	fout.close();
}