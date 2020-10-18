#include <bits/stdc++.h>
using namespace std;
#define ALL(a)  (a).begin(),(a).end()
typedef int long long ll;

int N, M;
set<int> S;
vector<int> f;
vector<int> counts;
int MOD = 1000000007;

int main() {
  cin >> N >> M;
  f.resize(N);
  counts.resize(N+1);
  for (int i = 0; i < N; i++) cin >> f[i];
  
  if (N == 1) {
    cout << 1 << endl;
    return 0;
  }
  
  int left = 0;
  int sum = 1;
  counts[0] = 1;
  for (int right = 0; right < N; right++) {
    while(S.find(f[right]) != S.end()) {
      S.erase(f[left]);
      sum = (sum - counts[left] + MOD) % MOD;
      left++;
    }
    S.insert(f[right]);
    counts[right+1] = sum;
    sum = (sum + counts[right+1]) % MOD;
  }
  cout << counts[N] << endl;
}
