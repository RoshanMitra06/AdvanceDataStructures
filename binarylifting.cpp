#include <bits/stdc++.h>
using namespace std;

// Author : Roshan Mitra 😎
// Language: C++
// College: Symbiosis Institute Of Technology
// Practice is the only key to success
// Always push ur limits
typedef pair<int, int> pii;
#define endl "\n"
#define set_bits(a) __builtin_popcountll(a)
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define sd(val) scanf("%d", &val)
#define sl(val) scanf("%lld", &val)
#define debug(val) printf("check%d\n", val)
#define asc(v) v.begin(), v.end()
#define des(v) v.end(), v.begin()
#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define int long long
#define maxheap priority_queue<int>
#define minheap priority_queue<int, vector<int>, greater<int>>
typedef vector<int> vi;
#define MOD 1000000007
#define clr(val) memset(val, 0, sizeof(val))
#define what_is(x) cerr << #x << " is " << x << endl;
#define rr return
#define FIO                         \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL);
void file()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}

//4 dir
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
//8 dir
int XX[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int YY[] = {-1, 0, 1, -1, 1, -1, 0, 1};

vector<int> adj[100001];
vector<vector<int>> parent(100001, vector<int>(22, 0));
vector<int> level(100001, 0);
int n, q;
//binary lifting (storing 2^i th parent)
void dfs(int node, int par = 0)
{
  parent[node][0] = par;
  cout << node;
  for (int i = 1; 1 << i <= n; i++)
    for (int j = 0; j <= n; j++)
      parent[node][i] = parent[parent[node][i - 1]][i - 1];
  // for (int i = 2; i <= 20; i++)
  // {
  //   //cout << 1;
  //   int x = parent[node][i - 1];
  //   parent[node][i] = parent[x][i - 1];
  // }
  for (auto it : adj[node])
  {
    if (it != par)
      dfs(it, node);
  }
}

//finding kth parent of a node
int findKthPar(int node, int k)
{
  int cnt = -1;
  while (k)
  {
    cnt++;
    if (k & 1)
      node = parent[node][cnt];
    k >>= 1;
  }
}

//normal lca might take O(n). Better go for lca using binary lifting 😉 O(logn)

void dfs1_bf(int node, int par = 0, int lev = 0)
{
  level[node] = lev;
  parent[node][0] = par;
  for (int i = 1; i <= 20; i++)
  {
    parent[node][i - 1] = parent[parent[node][i - 1]][i - 1];
  }
  for (auto it : adj[node])
  {
    if (it != par)
      dfs1_bf(it, node, lev + 1);
  }
}
int find_lca_bf(int x, int y)
{
  //considering only 1 case of x lower than y
  if (level[y] > level[x])
    swap(x, y);

  int diff = level[x] - level[y];
  int cnt = -1;
  while (diff)
  {
    cnt++;
    if (diff & 1)
      x = parent[x][cnt];
    diff >>= 1;
  }
  if (x == y)
    return x;
  for (int i = 20; i >= 0; i--)
  {
    if (parent[x][i] != parent[y][i])
    {
      x = parent[x][i];
      y = parent[y][i];
    }
  }
  return parent[x][0];
  // or return parent[y][0];
}
void solve()
{
  // int n, q;
  cin >> n >> q;
  for (int i = 2; i <= n; i++)
  {
    int u;
    cin >> u;
    adj[i].pb(u);
    adj[u].pb(i);
  }
  dfs(1, -1);
  while (q--)
  {
    int node, k;
    cin >> node >> k;
    int x = findKthPar(node, k);

    cout << node << endl;
  }
}
signed main()
{
  file();
  FIO;
  int t = 1;
  //cin>>t;
  while (t--)
  {
    solve();
  }
  return 0;
}