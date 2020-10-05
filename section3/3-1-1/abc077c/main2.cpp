#include <bits/stdc++.h>
using namespace std;

// https://qiita.com/ganariya/items/33f1326154b85db465c3
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  vector<int> c(n);
  vector<long> bmemo(n);
  for (int i = 0; i < n; i++) cin >> a.at(i);
  for (int i = 0; i < n; i++) cin >> b.at(i);
  for (int i = 0; i < n; i++) cin >> c.at(i);
  
  sort(b.begin(), b.end());
  reverse(b.begin(), b.end());
  sort(c.begin(), c.end());

  // calculate bmemo
  bmemo.at(0) = n + c.begin() - lower_bound(c.begin(), c.end(), b.at(0) + 1);
  for (int i = 1; i < n; i++) {
    long count = n + c.begin() - lower_bound(c.begin(), c.end(), b.at(i) + 1);
    bmemo.at(i) = bmemo.at(i-1) + count;
  }
  
  reverse(b.begin(), b.end());
  reverse(bmemo.begin(), bmemo.end());
  
  long result = 0;
  for (int i = 0; i < n; i++) {
    
    int idx_b = lower_bound(b.begin(), b.end(), a.at(i) + 1) - b.begin();
    
    if (idx_b >= n) {
      continue;
    }
    
    result += bmemo.at(idx_b);
  }
  
  cout << result << endl;
}
