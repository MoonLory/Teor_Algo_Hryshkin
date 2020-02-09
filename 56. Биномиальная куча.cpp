#include <iostream>
#include <fstream>
#include <deque>
#include <algorithm>
#include <math.h>
#pragma warning (disable:4996)
using namespace std;

int main()
{

	//setlocale(LC_ALL, "russian");
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	
	deque <int> mas;
	unsigned long long n;
	fin >> n;
	if (n < 1) {
		fout << -1;
		return 0;
	}
	while (n>0)
	{
		
		mas.push_back(n%2);
		n = n / 2;

	}
	//mas.push_front(n % 2);
	for (int i = 0; i < mas.size(); i++) {
		if (mas[i]==1)
		fout << i << endl;
	}
	fout.close();
	fin.close();
}