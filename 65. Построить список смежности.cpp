#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int n, m, v1, v2;
	fin >> n >> m;
	vector<vector<int>> mas(n);
	for (int i = 0; i < m; i++ ) {
		fin >> v1 >> v2;
		mas[v1-1].push_back(v2);
		mas[v2-1].push_back(v1);
	}
	for (int i = 0; i < n; i++ ) {
		fout << mas[i].size()<<' ';
		for (int  j= 0; j < mas[i].size(); j++ ) {
			fout << mas[i][j] << ' ';
		}
		fout << endl;
	}


	fin.close();
	fout.close();

}