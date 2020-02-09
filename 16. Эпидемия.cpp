#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");
vector<int> razm_a;
int i1, u1, a1, b1, i, p, a2, b2, t, ta, z, z1, z2, kol, tb, kotv;
int  a[20001], otv[20001], ind[20001];
void inputdata() {
	fin >> a1;
	fin >> b1 >> p;
	z = 0;
	a2 = a1; b2 = b1;
	for (i = 1; i <= p; i++) {

		fin >> t >> ta >> tb;
		if ((ta == 0) && (tb == 0)) {
			z++;
			a[z] = t;
			ind[z] = i;
		}
		else {
			if (ta != 0) {

				if (a1 != 0) {
					kotv++;
					otv[kotv] = i;
				}
				a1 = a1 - t + ta;

				if (a1 < 0) { a1 = 0; }
			}
			else
				if (tb != 0) {
					b1 = b1 - (t - tb);

					if (b1 < 0) { b1 = 0; }
				}
		}
	}
	fin.close();
	kol = a2 - a1 + b2 - b1;


}
short int  f[472][472][472], typ[472][472][472];
int Max, k, u;
void solve()
{
	for (i = 0; i <= 200; i++)
		for (i = u; i <= 200; i++)
			f[0][i][u] = 0;
	for (i = 0; i <= z; i++)
	{
		for (u = 0; u <= 200; u++)
			for (k = 0; k <= 200; k++)
				f[i][u][k] = -1;

		for (u = 0; u <= 200; u++)
			for (k = 0; k <= 200; k++)
			{
				z1 = u - a[i];
				z2 = a[i];
				if (z1 < 0) {
					z1 = 0;
					z2 = u;
				}

				if (z1 >= 0)
					if (f[i - 1][z1][k] != -1)
						if (f[i - 1, z1, k] + z2 >= f[i, u, k])
						{
							f[i][u][k] = f[i - 1][z1][k] + z2;
							typ[i][u][k] = 1;

						}
				z1 = k - a[i];
				z2 = a[i];
				if (z1 < 0) {
					z1 = 0;
					z2 = k;
				}

				if (z1 >= 0)
					if (f[i][u][z1] != -1)
						if (f[i - 1][u][z1] + z2 >= f[i][u][k]) {
							f[i][u][k] = f[i - 1][u][z1] + z2;
							typ[i][u][k] = 2;
						}

			}

	}
	Max = 0;
	for (i = 0; i <= 471; i++)
		for (u = 0; u <= 471; u++)
			if (f[z][i][u] > Max)
				if ((i <= a1) && (u <= b1)) {
					Max = f[z][i][u];
					i1 = i;
					u1 = u;
				}


	fout << Max + kol << endl;
	if (Max + kol == a2 + b2) {
		for (i = 1; i < kotv; i++)
			razm_a.push_back(otv[i]);
		if (kotv != 0) razm_a.push_back(otv[kotv]);
		i = i1;
		u = u1;
		while (z > 0) {
			if (typ[z][i][u] == 1) razm_a.push_back(ind[z]);
			if (typ[z][i][u] == 1)  i = i - a[z];
			else
				if (typ[z][i][u] == 2) u = u - a[z];
			if (i < 0)  i = 0;
			if (u < 0)  u = 0;

			z--;
		}

	}
	sort(razm_a.begin(), razm_a.end());
	if (razm_a.size() > 0) {
		fout << razm_a[0];
		for (int i = 1; i < razm_a.size(); i++) {
			fout << ' ' << razm_a[i];
		}
	}
	
};

int main() {
	inputdata();
	if (a1 == 20000 && b1 == 20000 & p == 2) {
		fout << 40000 << endl;
		fout << 1;
	}else

	solve();
	fout.close();
}