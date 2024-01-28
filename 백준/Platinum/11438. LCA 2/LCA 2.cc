#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define ll long long
#define X first
#define Y second

using namespace std;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;

const char nl = '\n';

vector<int> adj[100005];
int p[100005][20];
vector<int> depth(100005, -1);
void dfs(int cur) {
  for(auto e : adj[cur]) {
    if(depth[e] != -1) continue;
    depth[e] = depth[cur] + 1;
    p[e][0] = cur;
    dfs(e);
  }
}

void solve() {
  int n;
  cin >> n;
  memset(p, -1, sizeof(p));
  for(int i = 0; i < n-1; i ++) {
    int a, b;
    cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  depth[1] = 0;
  dfs(1);
  for(int j = 0; j <= 17; j ++) {
    for(int i = 1; i <= n; i ++) {
      if(p[i][j] != -1)
        p[i][j+1] = p[p[i][j]][j];
    }
  }

  int m;
  cin >> m;
  while(m--) {
    int x, y;
    cin >> x >> y;
    if(depth[x] < depth[y]) swap(x, y);
    int diff = depth[x] - depth[y];
    for(int j = 0; diff; j ++) {
      if(diff & 1) {
        x = p[x][j];
      }
      diff = (diff >> 1);
    }
    if(x == y) {
      cout << x << nl;
      continue;
    }
    for(int i = 17; i >= 0; i --) {
      if(p[x][i] != -1 && p[x][i] != p[y][i]) {
        x = p[x][i];
        y = p[y][i];
      }
    }
    cout << p[x][0] << nl;
  }

}

// ************************************

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  // cin >> t;
  for (int i = 1; i <= t; i++) {
  //#ifdef DEBUG
  //cout << "Case " << i << ":\n";
  //#endif
  solve();
  //#ifdef DEBUG
  //cout << "============\n";
  //#endif
  }
}