#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int n, m, v1, v2;
	fin >> n;
	vector <int> ans(n, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			fin >> v1;
			if (v1) {
				ans[j] = i+1;
			}
		}
	}


	for (int i = 0; i < n; i++ ) {
		fout << ans[i]<<' ';
	}


	fin.close();
	fout.close();

}