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
vi parent(100, 0);
vector<int> adj[100];
void findpar(int node, int par = 0)
{
  parent[node] = par;
  for (auto it : adj[node])
  {
    if (it != par)
      findpar(it, node);
  }
}
//intuition: store a parent array and find all the par of the nodes
//iterate until they become 0 while storing. Where the meet Just previous one is the lcs
void solve()
{
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n - 1; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  findpar(1);
  vi v1(n + 1), v2(n + 1);
  while (q--)
  {
    int a, b;
    cin >> a >> b;
    while (a != 0)
    {
      v1.pb(a);
      a = parent[a];
    }
    while (b != 0)
    {
      v2.pb(b);
      b = parent[b];
    }
    reverse(all(v1));
    reverse(all(v2));
    int fl = -1;
    for (int i = 0; i < min(v1.size(), v2.size()); i++)
    {
      if (v1[i] != v2[i])
      {
        fl = i - 1;
        break;
      }
    }
    if (fl == -1)
    {
      if (v1.size() < v2.size())
        cout << v1.back() << endl;
      else
        cout << v2.back() << endl;
    }
    else
      cout << v1[fl] << endl;
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