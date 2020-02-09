#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#pragma warning (disable:4996)
using namespace std;




int main()
{

	//setlocale(LC_ALL, "russian");
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int n, b;
	string s;
	fin >> s;
	n = s.length();
	int **a = new int*[n + 1];
	for (int i = 0; i <= n; i++)
	{
		a[i] = new int[n + 1];
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			a[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++)
	{

		a[i][i] = 1;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; i + j < n; j++) {

			if (s[j] == s[j + i]) {
				a[j][j + i] = a[j + 1][j + i - 1] + 2;

			}
			else {
				a[j][j + i] = max(a[j][j + i - 1], a[j + 1][i + j]);
			}
		}

	}

	string ans;
	char *ans1 = new char[a[0][n - 1]];
	int st = 0;
	int end = a[0][n - 1] - 1;
	int i = 0;
	int j = n - 1;
	while (a[i][j] > 0) {
		if (s[i] == s[j]) {
			ans1[st] = ans1[end] = s[i];
			st++;
			end--;
			i++;
			j--;
		}
		else {
			if (a[i][j - 1] > a[i + 1][j]) {
				j--;
			}
			else {
				i++;
			}
		}
	}
	if (ans.length() % 2 != 0) {
		ans1[st + 1] = s[i];
	}
	fout << a[0][n - 1] << endl;

	for (int i = 0; i < a[0][n - 1]; i++) {
		fout << ans1[i];
	}
	fout.close();
	fin.close();
}