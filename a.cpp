  #include<bits/stdc++.h>
  #include <ext/pb_ds/assoc_container.hpp>
  #include <ext/pb_ds/tree_policy.hpp>
  #define ll long long
  #define forn(i, n) for(ll i = 0; i < n; i++)
  #define forab(i, a, b) for(ll i=a; i<b; i++)
  #define MAXS 1000005
  #define MAX 2005
  #define MAXN 10000005
  #define level 18
  #define fastio ios_base::sync_with_stdio(false);cin.tie(NULL); 
  #define fi first
  #define se second
  #define be begin()
  #define en end()
  #define sz(x) ((ll) (x).size())
  #define all(x) x.begin(), x.end()
  #define pb push_back
  #define N 2750131
  #define debugar(a,n) forn(i,n)cout<<a[i]<<" ";cout<<endl;
  #define printar(a,n) forn(i,n)cout<<a[i]<<" ";cout<<"\n";
  using namespace std;
  using namespace __gnu_pbds;

  ll mod = 998244353;
  ll INF=1e18+1;  

  typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

  struct classcomp {
    bool operator() (const pair<ll,ll>& lhs, const pair<ll,ll>& rhs) const
    {return lhs>rhs;}
  };
  bool sortbysecdesc(const pair<int,int> &a,
                    const pair<int,int> &b)
  {
      return a.second>b.second;
  }



int main()
{
	fastio

	ll t;
	cin >> t;
	while(t--){ 
    } 
}