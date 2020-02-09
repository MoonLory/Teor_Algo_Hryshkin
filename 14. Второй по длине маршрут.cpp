#include <iostream>
#include <fstream>
#include <vector>

#define M 100000
#define N 10000

using namespace std;
bool used[N + 1];
bool is_Edge[M + 1];
long long ves[M + 1];
bool is_vershina[N + 1];
long long ans;
int ans_vrem, ans_dad, m, a, b;
int h[N];
int h_razmer;
int vershina_Pos[N + 1];
int dad[N + 1];
int dad_Edge[M + 1];
long long lvl[N + 1];
vector<vector<pair<int, int>>> g(N + 1);
vector <int> put;
int num = 0;
int n = 0;
int otv = 0;

int h_dad(int i) {
	return i >> 1;
}

int l(int i) {
	return 2*(i + 1)-1;
}

int r(int i) {
	return 2*(i + 1);
}

void hp(int i) {
	int t = h[i];
	while (i > 0 && (lvl[h[h_dad(i)]] > lvl[t])) {
		h[i] = h[h_dad(i)];
		vershina_Pos[h[i]] = i;
		i = h_dad(i);
	}
	while (((r(i) <= h_razmer) && (lvl[t] > lvl[h[r(i)]])) ||
		((l(i) <= h_razmer) && (lvl[t] > lvl[h[l(i)]]))) {
		int mensh_reb = l(i);
		if ((r(i) <= h_razmer) && (lvl[h[r(i)]] < lvl[h[l(i)]])) {
			mensh_reb++;
		}
		h[i] = h[mensh_reb];
		vershina_Pos[h[i]] = i;
		i = mensh_reb;
	}
	h[i] = t;
	vershina_Pos[t] = i;
}

void dijkstra() {
	for (int i = 1; i <= n; i++) {
		is_vershina[i] = false;
		vershina_Pos[i] = i - 1;
		h[i - 1] = i; 
		lvl[i] = 9223372036854775807;
	}
	

	lvl[a] = 0;
	h_razmer = n - 1;
	is_vershina[a] = is_vershina[b] = true;
	hp(vershina_Pos[a]);
	
	while (h_razmer >= 0) {
		int u = h[0];
		h[0] = h[h_razmer--];
		hp(0);
		for (int i = 0; i < g[u].size(); i++) {
			int k = g[u][i].first;
			int flag = g[u][i].second;
			long w = ves[flag];
			if (lvl[u] + w < lvl[k]) {
				lvl[k] = lvl[u] + w;
				dad[k] = u;
				dad_Edge[k] = flag;
				hp(vershina_Pos[k]);
			}
		}
	}

	vector<int> ans;
	int curv = b;
	ans.push_back(curv);
	
	while (dad[curv]) {
		is_Edge[dad_Edge[curv]] = true;
		curv = dad[curv];
		ans.push_back(curv);
		is_vershina[curv] = true;
	}
	
}

void dfs(int u) {
	used[u] = true;
	for (int i = 0; i < g[u].size(); i++) {
		int k, w, flag;
		flag = g[u][i].second;
		w = ves[flag];
		k = g[u][i].first;
		if (!used[k]) {
			dfs(k);
		}
		if (is_vershina[k] && (!is_Edge[flag]) &&
			(lvl[b] - lvl[k] + lvl[u] + w < ans)) {
			ans = lvl[b] - lvl[k] + lvl[u] + w;
			ans_dad = u;
			ans_vrem = k;
		}
	}
}

void f_sec() {
	dfs(a);
	otv==ans;
	int k = ans_dad;
	vector<int> save;
	save.push_back(ans_vrem);
	save.push_back(k);
	while (dad[k]) {
		k = dad[k];
		save.push_back(k);
	}
	for (int i = save.size() - 1; i >= 0; i--) {
		put.push_back(save[i]);
	}
	save.clear();
	k = b;
	while (k != ans_vrem && dad[k]) {
		save.push_back(k);
		k = dad[k];
	}
	for (int i = save.size() - 1; i >= 0; i--) {
		put.push_back(save[i]);
	}
}

int main() {

	ifstream fin("input.in");
	ofstream fout("output.out");
	
	fin>>n>>m;
	
	for (int i = 0; i < m; i++) {
		int u, k;
		fin >> u >> k >> ves[i];
		g[u].push_back(make_pair(k, i));
	}

	fin>>a>>b;
	
	dijkstra();
	ans = 9223372036854775807;

	f_sec();
	
	fout << ans<<endl;
	
	for (int i = 0; i < put.size(); i++)
		fout << put[i] << ' ';
	
	fin.close();
	fout.close();
	return 0;
}