#include<iostream>
#include<fstream>
#include<algorithm>
#include<map>
#include<vector>
#include<set>



using namespace std;

int main() {

	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int n, m, a, b, i, k;
	long long len;
	map<long long, long long> schema;
	map<int, vector<pair<int, long long>>>mas;
	set<pair<int, long long>> find;

	fin >> n >> m;

	for (int i = 2; i < n + 1; i++) 
		schema[i] = 9223372036854775807;

	for (int i = 0; i < m; i++) {
		fin >> a>>b>>len;
		mas[a].push_back(make_pair(b, len));
		mas[b].push_back(make_pair(a, len));
	}
	
	find.insert(pair<int, long long>(0, 1));

	k = 1;

	while (!find.empty()) {
		k = find.begin()->second;
		find.erase(find.begin());
		
		for (auto i : mas[k]) {
			
			if (schema[k] + i.second < schema[i.first]) {
				find.erase(make_pair(schema[i.first], i.first));
				schema[i.first] = schema[k] + i.second;
				find.insert(make_pair(schema[i.first], i.first));
			}
		}
	}

	fout<<schema[n];

	fin.close();
	fout.close();
	return 0;
}