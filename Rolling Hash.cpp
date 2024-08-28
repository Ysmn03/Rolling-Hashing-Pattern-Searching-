#include <iostream>
#include<map>
#include<string>
#include <vector>
#include<cstring>
#include<cstdio>
using namespace std;

#define ll long long
#define YES printf("YES\n")
#define NO printf("NO\n")

const int N = 100001, PRIME = 1e9 + 9;
char s1[N], s2[N];
ll cumSum[N];
vector<ll>chr(26);

ll fastPower(ll base, ll exp) {
	ll result = 1;
	while (exp > 0) {
		if (exp % 2 == 1) {
			result = (result * base) % PRIME;
		}
		base = (base * base) % PRIME;
		exp /= 2;
	}
	return (result % PRIME);
}

void Hashing()
{
	chr[0] = 1;
	for (int i = 1; i < 26; ++i)
		chr[i] = (i * fastPower(31, i) + chr[i - 1]) % PRIME;
}

void CummulativeSumOfHashes(int n)
{
	cumSum[0] = chr[s1[0] - 'a'];
	for (int i = 1; i < n; ++i)
		cumSum[i] = (cumSum[i - 1] + chr[s1[i] - 'a']);
}

int main()
{
	int t;
	scanf("%d", &t);
	Hashing();

	while (t--)
	{
		int len1, q;
		scanf("%d%d", &len1, &q);
		scanf("%s", s1);

		CummulativeSumOfHashes(len1);

		map<char, vector<int>>mp; //Store all the appearances of each character

		mp[s1[0] - 'a'].push_back(0);
		for (int i = 1; i < len1; ++i)
			mp[s1[i] - 'a'].push_back(i);

		while (q--)
		{
			scanf("%s", s2);

			int len2 = strlen(s2);
			ll s2SUM = 0;

			for (int i = 0; i < len2; ++i)
				s2SUM += chr[s2[i] - 'a'];

			bool flag = false;
			vector<bool>seen(26);

			for (int i = 0; i < len2; ++i)
			{
				if (!seen[s2[i] - 'a']) //Avoid checking already checked character
				{
					for (int j = 0; j < mp[s2[i] - 'a'].size(); ++j)
					{
						int pos = mp[s2[i] - 'a'][j];
						if (pos - len2 >= 0 && cumSum[pos] - cumSum[pos - len2] == s2SUM || cumSum[pos] == s2SUM)
						{
							flag = true;
							break;
						}
					}
				}
				seen[s2[i] - 'a'] = true;
				if (flag)
					break;
			}

			if (flag)
				YES;
			else
				NO;

		}
		memset(cumSum, 0, sizeof(cumSum));
	}
}
