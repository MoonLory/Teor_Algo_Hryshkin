#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <vector>

#pragma comment(linker, "/STACK:16777216")

using namespace std;

int n, flag, nSingletons;
unordered_map< int, unordered_set<int> > g;
unordered_map<int, char> cl;
unordered_map<int, int> p;

bool dfs1(int v)
{
	cl[v] = 1;
	bool res = false;
	for (auto &pos : g[v])
	{
		int to = pos;
		if (cl[to] == 0)
		{
			p[to] = v;
			res = res || dfs1(to);
		}
		else if (cl[to] == 1 && to != p[v])
		{
			cl[v] = 2;
			return true;
		}
	}
	cl[v] = 2;
	return res;
}

bool acycl()
{
	for (auto &pos : g)
	{
		cl[pos.first] = 0;
		p[pos.first] = -1;
	}

	flag = -1;
	for (auto &pos : g)
		if (cl[pos.first] == 0)
			if (dfs1(pos.first))
			{
				flag = 1;
				break;
			}

	return (flag == -1);
}

unordered_map<int, bool> used;
int compSize;

void dfs2(int v)
{
	used[v] = true;
	compSize++;
	for (auto &pos : g[v])
	{
		int to = pos;
		if (!used[to])
			dfs2(to);
	}
}

bool checkConnect()
{
	used.clear();
	for (auto &pos : g)
		used[pos.first] = false;
	compSize = 0;
	dfs2(g.begin()->first);
	return compSize == n;
}

int  main() {


	int w, a, b;

	while (true)
	{
		g.clear();
		cl.clear();

		cin >> n >> w;
		nSingletons = n;
		for (int i = 0; i < w; i++)
		{
			cin >> a >> b;
			if (g.find(b - 1) == g.end())
				--nSingletons;
			if (g.find(a - 1) == g.end())
				--nSingletons;
			g[b - 1].insert(a - 1);
			g[a - 1].insert(b - 1);
		}

		if (n == 0)
		{
			return 0;
		}

		flag = 0;
		for (auto &vert : g)
			if (vert.second.size() > 2)
			{
				cout << "NO\n";
				flag = 1;
				break;
			}
		if (flag)
			continue;

		n -= nSingletons;
		if (nSingletons == 0 && checkConnect())
		{
			cout << "YES\n";
			continue;
		}

		cout << (acycl() ? "YES" : "NO") << '\n';
	}
}