// Author : Roshan Mitra 😎
// Language: C++
// College: Symbiosis Institute Of Technology
// Practice is the only key to success
// Always push ur limits

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef pair<int, int> pii;
#define endl "\n"
#define set_bits(a) __builtin_popcountll(a)
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
const int inf = (int)(1e12 + 10);
#define rev(arr) reverse(arr.begin(), arr.end())
#define asc(v) v.begin(), v.end()
#define des(v) v.end(), v.begin()
#define all(v) v.begin(), v.end()
#define pb push_back
const int mx = 1e5 + 5;
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
#define lowb(a, x) (lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) (upper_bound((a).begin(), (a).end(), (x)) - (a).begin())
void file()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}

/*/-----------------------------INLINE FUNCTIONS----------------------------------/*/
inline int ceil(int num, int den) { return ((num + den - 1) / den); }
/*/-------------------------------------------------------------------------------/*/

//4 dir
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
//8 dir
int XX[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int YY[] = {-1, 0, 1, -1, 1, -1, 0, 1};

/*/-----------------------------CODE BEGINS----------------------------------/*/
vector<int> adj[100000 + 1];
vector<int> vis(1e5 + 1, 0);
vector<int> col(1e5 + 1, 0);
bool cycle = false, bip = false;
void checkbip(int node, int par, int color)
{
  vis[node] = 1;
  col[node] = color;
  for (auto it : adj[node])
  {
    if (!vis[it])
    {
      checkbip(it, node, !color);
    }
    else if (it != par)
    {
      //cout << "hello";
      cycle = true;
      if (col[it] == col[node])
        bip = false;
    }
  }
}
void solve()
{
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }

  checkbip(1, 0, 0);
  //cout << cycle;
  if (bip)
    cout << "no\n";
  else if (cycle and !bip)
    cout << "yes\n";
}
/*/-----------------------------CODE ENDS------------------------------------/*/
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