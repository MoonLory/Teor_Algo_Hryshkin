#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <math.h>
#pragma warning (disable:4996)
using namespace std;


int main()
{

	//setlocale(LC_ALL, "russian");
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int m;
	fin >> m;
	int n, k;
	unsigned long long mas[100001];
	unsigned long long sum=0;
	for (int j = 0; j < m; j++) {
		fin >> n >> k;
		mas[0] = 1;
		sum = 1;
		for (int i = 1; i < n;i++) {
			mas[i] = sum;
			if (i < k) {
				sum = (sum + mas[i]) % 1000000007;
			}
			else {
				sum = (sum - mas[i - k] + mas[i] + 1000000007) % 1000000007;
			}
		}
		fout << mas[n - 1] << endl;
	}
	fout.close();
	fin.close();
}