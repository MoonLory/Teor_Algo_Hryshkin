#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector <int> S(100001,-1);

int otn(int a) {
	if (S[a] < 0) return a;
	S[a] = otn(S[a]);
	return S[a];
}

int  main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	
	vector<int> C(100001);
	int ans, n, r, a, b;
	ans = 0;
	fin >> n >> r;
	for (int i = 0; i < r; i++) {
		fin >> a >> b;
		a = otn(a);
		b = otn(b);
		if (a == b) {
			ans++;
			continue;
		}
		if(C[a]<C[b]){
			S[a] = b;
		}
		else {
			S[b] = a;
			if (C[a] == C[b])
				C[a]++;
		}
	}
	fout << ans;
	fin.close();
	fout.close();
}