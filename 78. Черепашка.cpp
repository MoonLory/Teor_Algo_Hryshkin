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
	string s;
	long n, m;
	fin >> n;
	fin >> m;
	//cout << n <<' '<< m;
	long long *mas1 = new long long[m];
	long long *mas2 = new long long[m];
	for (int x = 0; x < m; x++)
	{
		mas2[x] = 1;
		mas1[x] = 0;
	}

	int k = n;
	mas1[0] = 1;

	while (k > 0) {
		if (k % 2 == 0) {
			for (int x = 1; x < m; x++)
			{
				mas1[x] = (mas1[x - 1] + mas2[x]) % 1000000007;
			}
		}
		else {
			for (int x = 1; x < m; x++)
			{
				mas2[x] = (mas2[x - 1] + mas1[x]) % 1000000007;
			}
		}
		k--;
	}

	if (n % 2 == 1) {
		fout << mas2[m - 1] << endl;
	}
	else {
		fout << mas1[m - 1] << endl;
	}

	
	//fin >> s;
	//s = palindrome(s);
	//fout << s.length()<<'\n';
	//fout << s;
	//fout << sum;
	fout.close();
	fin.close();
	//cout<<sum;
	//cin >> sum;
}