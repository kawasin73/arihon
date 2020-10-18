#include <bits/stdc++.h>
using namespace std;
#define ALL(a)  (a).begin(),(a).end()
typedef int long long ll;

int N;
ll K;
vector<int> s;

int main() {
  cin >> N >> K;
  s.resize(N);
  for (int i = 0; i < N; i++) cin >> s[i];
  for (int i = 0; i < N; i++) {
    if (s[i] == 0) {
      cout << N << endl;
      return 0;
    }
  }

  ll accum = 1;
  int result = 0;
  int right = 0;
  for (int left = 0; left < N; left++) {
    while (right < N && accum * s[right] <= K) {
      accum *= s[right];
      right++;
    }
    if (right - left > result) {
      result = right - left;
    }

    if (left == right) {
      accum *= s[right];
      right++;
    }
    accum /= s[left];
  }
  cout << result << endl;
}
