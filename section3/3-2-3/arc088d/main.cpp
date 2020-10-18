#include <bits/stdc++.h>
using namespace std;
#define ALL(a)  (a).begin(),(a).end()
typedef int long long ll;

int main() {
  string s;
  cin >> s;
  
  int size = (int) s.length();
  int result = size;
  for (int i = 0; i < size - 1; i++) {
    if (s[i] != s[i+1]) {
      int n = max(i+1, size - (i+1));
      if (n < result) {
        result = n;
      }
    }
  }

  cout << result << endl;
}
