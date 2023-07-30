double multiply(double number, int n) {
    double ans = 1.0;
    for(int i = 1;i<=n;i++) {
        ans = ans * number;
    }
    return ans; 
}
 int getNthRoot(int n, int m) {
    double low = 1;
    double high = m;
    double eps = 1e-7; 
    
    while((high - low) > eps) {
        double mid = (low + high) / 2.0; 
        if(multiply(mid, n) < m) {
            low = mid; 
        }
        else {
            high = mid; 
        }
    }
    return ceil(low);
}
int NthRoot(int n, int m) {
  // Write your code here.
   if(pow(getNthRoot(n, m),n)==m) return getNthRoot(n, m);
   return -1;
}