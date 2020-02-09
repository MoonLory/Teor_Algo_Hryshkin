#include <iostream>
#include <fstream>
#include <vector>
#include <exception>
#include <algorithm>

#pragma warning (disable:4996)
using namespace std;

int multiplyOrder(vector <int> &p) {
	int n = p.size() - 1;
	vector<vector<int>> dp(n+1,vector<int>(n+1));
	 
	for (int i = 1; i <= n; i++) {
		dp[i][i] = 0;
	}

	for (int l = 2; l <= n; l++) {
		for (int i = 1; i <= n - l + 1; i++) {
			int j = i + l - 1;
			dp[i][j] = INT32_MAX;
			for (int k = i; k <= j - 1; k++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j]);
			}
		}
	}
	return dp[1][n];
}

int main()
{
	//setlocale(LC_ALL, "russian");
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int n;
	fin >> n;
	vector <int> p(n+1);
	for (int i = 0; i < n; i++) {
		fin >> p[i];
		fin >> p[i+1];

	}
	fout << multiplyOrder(p);
	fout.close();
	fin.close();
	//cout<<sum;
	//cin >> sum;
}