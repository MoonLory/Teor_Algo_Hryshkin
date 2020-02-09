#include <iostream>
#include <fstream>
#include <vector>
#include <exception>
#include <algorithm>

#pragma warning (disable:4996)
using namespace std;

int main()
{
	//setlocale(LC_ALL, "russian");
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int n;
	fin >> n;
	vector <int> mas1(n);
	for (int i = 0; i < n; i++) {
		fin >> mas1[i];
	};
	vector <int> mas2(n,-1);

	mas2[0] = mas1[0];

	for (int i = 1; i < n; i++) {
		if (i >= 2) mas2[i] = max(mas2[i], mas2[i - 2]);

		if (i >= 3) mas2[i] = max(mas2[i], mas2[i - 3]);

		if ( mas2[i]!=-1) mas2[i]+=mas1[i];
	};

	fout << mas2[n - 1];

	fout.close();
	fin.close();
	//cout<<sum;
	//cin >> sum;
}