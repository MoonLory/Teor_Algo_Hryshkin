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
	vector<int> mas(n,0);
	for (int i = 0; i < n-1; i++ ) {
		fin >> v1 >> v2;
		mas[v2-1]=v1;
	}
	for (int i = 0; i < n; i++ ) {
		fout << mas[i]<<' ';
	}


	fin.close();
	fout.close();

}