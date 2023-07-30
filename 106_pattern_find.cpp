#include <bits/stdc++.h> 
void LPSArray(string pattern, int M, int lps[]);

bool KMPSearch(string pattern, string txt)
{
	int M = pattern.size();
	int N = txt.size();

	int lps[M];

	LPSArray(pattern, M, lps);

	int i = 0; 
	int j = 0; 
	while ((N - i) >= (M - j)) {
		if (pattern[j] == txt[i]) {
			j++;
			i++;
		}

		if (j == M) {
			return true;
			j = lps[j - 1];
		}

		else if (i < N && pattern[j] != txt[i]) {
			if (j != 0)
				j = lps[j - 1];
			else
				i = i + 1;
		}
	}
    return false;
}

void LPSArray(string pattern, int M, int lps[])
{

	int len = 0;

	lps[0] = 0; 
	int i = 1;
	while (i < M) {
		if (pattern[i] == pattern[len]) {
			len++;
			lps[i] = len;
			i++;
		}
		else 
		{
			
			if (len != 0) {
				len = lps[len - 1];

			}
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}
bool findPattern(string p, string s)
{
    return KMPSearch(p, s);
}