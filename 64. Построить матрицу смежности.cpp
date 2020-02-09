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
	vector<vector<short int>> mas(n, vector<short int>(n, 0));
	for (int i = 0; i < m; i++ ) {
		fin >> v1 >> v2;
		mas[v1-1][v2-1] = 1;
		mas[v2-1][v1-1] = 1;
	}
	for (int i = 0; i < n; i++ ) {
		for (int  j= 0; j < n; j++ ) {
			fout << mas[i][j] << ' ';
		}
		fout << endl;
	}


	fin.close();
	fout.close();

}