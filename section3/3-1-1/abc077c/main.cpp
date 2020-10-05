#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  vector<int> c(n);
  for (int i = 0; i < n; i++) cin >> a.at(i);
  for (int i = 0; i < n; i++) cin >> b.at(i);
  for (int i = 0; i < n; i++) cin >> c.at(i);
  
  sort(a.begin(), a.end());
  sort(c.begin(), c.end());
  
  long result = 0;
  for (int i = 0; i < n; i++) {
    long a_count = lower_bound(a.begin(), a.end(), b.at(i)) - a.begin();
    long c_count = c.end() - upper_bound(c.begin(), c.end(), b.at(i));
    result += a_count * c_count;
  }
  
  cout << result << endl;
}
