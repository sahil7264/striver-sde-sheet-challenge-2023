vector<int> stringMatch(string text, string pattern) {
	    int m = pattern.size();
        int n = text.size();
        int i, j;
        int p = 0;
        int t = 0;
        int h = 1;
		int d = 10;
		int q = 13;
		vector<int>ans;
        for (i = 0; i < m - 1; i++)
          h = (h * d) % q;
    
        // Calculate hash value for pattern and text
        for (i = 0; i < m; i++) {
          p = (d * p + pattern[i]) % q;
          t = (d * t + text[i]) % q;
        }
    
        // Find the match
        for (i = 0; i <= n - m; i++) {
          if (p == t) {
            for (j = 0; j < m; j++) {
              if (text[i + j] != pattern[j])
                break;
            }
    
            if (j == m)
              ans.push_back(i+1);
          }
    
          if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
    
            if (t < 0)
              t = (t + q);
          }
        }
		return ans;
}
