#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <vector>
#include <assert.h>
#include <algorithm>

using namespace std;
const int INF = 1e9;
struct edge
{
	int x, y, cost;
	bool prox;
};

int main()
{
	int n;
	cin >> n;
	vector<int> sf(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &sf[i]);
	}
	sort(sf.begin(), sf.end());
	vector<long long> ans;
	if (n >= 6)
	{
		ans.push_back(sf[0]);
		ans.push_back(sf[1]);
		ans.push_back(sf[2]);
		ans.push_back(sf[n - 1]);
		ans.push_back(sf[n - 2]);
		ans.push_back(sf[n - 3]);
	}
	else if (n == 5)
	{
		ans.push_back(sf[0]);
		ans.push_back(sf[1]);
		ans.push_back(sf[2]);
		ans.push_back(sf[n - 1]);
		ans.push_back(sf[n - 2]);
	}
	else if (n == 4)
	{
		ans.push_back(sf[0]);
		ans.push_back(sf[1]);
		ans.push_back(sf[2]);
		ans.push_back(sf[n - 1]);
	}
	else if (n == 3)
	{
		ans.push_back(sf[0]);
		ans.push_back(sf[1]);
		ans.push_back(sf[2]);
	}
	int j = ans.size();
	long long h = ((-30000) * (-30000)) * 1LL * (-30000);
	for (int i = 0; i < j; i++)
	{
		for (int y = 0; y < j; y++)
		{
			if (i != y)
				for (int z = 0; z < j; z++)
				{
					if (i != z && y != z && i != y)
					{
						long long r = (ans[i] * ans[y]) * 1LL * ans[z];
						h = max(h, r * 1LL);
					}
				}
		}
	}
	cout << h << endl;
}