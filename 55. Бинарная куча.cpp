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
	int n;
	fin >> n;
	
	int *arr=new int[n+1];
	for (int i = 1; i <= n; i++) {
		fin >> arr[i];
	}
	for (int i = 1; i*2 <= n; i++) {
		if (arr[2 * i] < arr[i] ||(2 * i + 1<=n && arr[2 * i + 1] < arr[i])) {
			fout << "No";
			fout.close();
			fin.close();
			return 0;
		}
	}
	fout << "Yes";
	fout.close();
	fin.close();
}