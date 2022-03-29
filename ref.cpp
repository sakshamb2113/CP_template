#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define forn(i, n) for(i = 0; i < n; i++)
#define forab(i, a, b) for(i=a; i<b; i++)
#define MAXS 1000005
#define MAX 1005
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL); 
#define fi first
#define se second
#define pb push_back
#define N 2750131
#define debugar(a,n) forn(i,n)cout<<a[i]<<" ";cout<<endl;
using namespace std;
using namespace __gnu_pbds;

ll mod = 1e9+7;
ll mincnst=1e18+1;  

typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

bool issquare(long double x)
{
    // Find floating point value of
    // square root of x.
    if (x >= 0) {
 
        long long sr = sqrt(x);
         
        // if product of square root
        //is equal, then
        // return T/F
        return (sr * sr == x);
    }
    // else return false if n<0
    return false;
}
ll modexp(ll x, ll y, ll mod){
  ll res = 1;
  x = x%mod;
  if(x==0) return 0; 
  while(y>0){
    
    if(y%2) res = (res*x) % mod;
    y = y >> 1;
    x = (x*x) % mod;
  }

  return res;

}

vector<ll> printDivisors(ll n) 
{
    vector<ll> v;
    for (ll i=2; i<=sqrt(n); i++) 
    { 
        if (n%i == 0) 
        { 
            if (n/i != i){
                v.pb(n/i);
            } 
            v.pb(i);
        } 
    } 
    return v;
} 
vector<ll> primeFactors(ll n)  
{  
    vector<ll> v;
    while (n % 2 == 0)  
    {  
        v.pb(2);  
        n = n/2;  
    }  
  
    for (ll i = 3; i <= sqrt(n); i = i + 2)  
    {  
        while (n % i == 0)  
        {  
            v.pb(i);
            n = n/i;  
        }  
    }  

    if (n > 2)  
        v.pb(n);

    return v;
}


// supply comparator greater<int>

priority_queue<ll,vector<ll>,greater<ll> > g;
vector<ll> NGE(ll arr[], ll n)
{
    stack<ll> s;
    vector<ll> v(n);

    s.push(0);

    for (ll i = 1; i < n; i++)
    {
 
        if (s.empty()) {
            s.push(i);
            continue;
        }
 

        while (s.empty() == false
               && arr[s.top()] <= arr[i])
        {
            // cout << s.top()
                //  << " --> " << arr[i] << endl;
                v[s.top()]=i;
            s.pop();
        }

        s.push(i);
    }

    while (s.empty() == false) {
        // cout << s.top() << " --> " << -1 << endl;
        v[s.top()]=-1;
        s.pop();
    }
    return v;
}


vector<ll> PGE(ll arr[], ll n)
{
    stack<ll> s;
    vector<ll> v(n);

    s.push(n-1);

    for (ll i = n-2; i > -1; i--)
    {
 
        if (s.empty()) {
            s.push(i);
            continue;
        }
 

        while (s.empty() == false
               && arr[s.top()] <= arr[i])
        {
            // cout << s.top()
                //  << " --> " << arr[i] << endl;
                v[s.top()]=i;
            s.pop();
        }

        s.push(i);
    }

    while (s.empty() == false) {
        // cout << s.top() << " --> " << -1 << endl;
        v[s.top()]=-1;
        s.pop();
    }
    return v;
}

string decToBinary(ll n)
{
    // Size of an integer is assumed to be 32 bits
    string res="";
    for (int i = 31; i >= 0; i--) {
        ll k = n >> i;
        if (k & 1)
            res+="1";
        else
            res+="0";
    }

    return res;
}


bool ispallin(string s){
    forn(i,s.length()/2){
        if(s[i]!=s[s.length()-1-i]){
            return false;
        }
    }
    return true;
}

unsigned long long fac[1000000];  
unsigned long long power(unsigned long long x,
                                  ll y, ll p)
{
    unsigned long long res = 1; // Initialize result
 
    x = x % p; // Update x if it is more than or
    // equal to p
 
    while (y > 0)
    {
     
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;
 
        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}
 
unsigned long long fac[1000000];
// Returns n^(-1) mod p
unsigned long long modInverse(unsigned long long n, 
                                            ll p)
{
    return power(n, p - 2, p);
}
 
ll cfact(ll n, ll p){
    fac[0] = 1;
    for (ll i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;
}
// Returns nCr % p using Fermat's little
// theorem.
unsigned long long nCrModPFermat(unsigned long long n,
                                 ll r, ll p)
{
    // If n<r, then nCr should return 0
    if (n < r)
        return 0;
    // Base case
    if (r == 0)
        return 1;
 
    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r

 
    return (fac[n] * modInverse(fac[r], p) % p
            * modInverse(fac[n - r], p) % p)
           % p;
}


		if(x-1>=1 && !visited[x-1][y]){
			
			assigndp(x-1,y,x,y);
			q.push({x-1,y});
		}
		if(x+1<n+1 && !visited[x+1][y]){
			assigndp(x+1,y,x,y);
			q.push({x+1,y});
		}
		if(y-1>=1 && !visited[x][y-1]){
			assigndp(x,y-1,x,y);
			q.push({x,y-1});
		}
		if(y+1<m+1 && !visited[x][y+1]){
			assigndp(x,y+1,x,y);
			q.push({x,y+1});
		}


//* MOD INV
ll gcd(ll a, ll b);
 
// To compute x raised to power y under modulo m
ll power(ll x, ll y, ll m);
 
// Function to find modular inverse of a under modulo m
// Assumption: m is prime
ll modInverse(ll a, ll m)
{
    ll g = gcd(a, m);
    if (g != 1)
        cout << "Inverse doesn't exist";
    else
    {
        // If a and m are relatively prime, then modulo
        // inverse is a^(m-2) mode m
        return power(a, m - 2, m);
    }
}
 
// To compute x^y under modulo m
ll power(ll x, ll y, ll m)
{
    if (y == 0)
        return 1;
    ll p = power(x, y / 2, m) % m;
    p = (p * p) % m;
 
    return (y % 2 == 0) ? p : (x * p) % m;
}
 
// Function to return gcd of a and b
ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
/* MOD INV

ll i, n, t, bit[N], save[N];

void update(ll idx, ll val) {
	while (idx < N) {
		bit[idx] += val;
		idx += idx & -idx;
	}
}
 
ll query(ll idx) {
	ll ans = 0;
	while (idx) {
		ans += bit[idx];
		idx -= idx & -idx;
	}
	return ans;
}
 
ll rsum(ll l, ll r) {
	return query(r) - query(l - 1);
}
 
void range_update(ll l, ll r, ll val) {
	update(l, val);
	update(r + 1, -val);
}*/

ll n, t[4*MAXS];

void build(ll a[], ll v, ll tl, ll tr){
	if(tl==tr){
		t[v] = a[tl];
	}
	else{
		ll tm = (tl+tr)/2;
		build(a,v*2,tl,tm);
		build(a,v*2+1,tm+1,tr);
		t[v] = t[v*2]+t[v*2+1];
	}
}

ll sum(ll v, ll tl, ll tr, ll l, ll r){
	if(l>r) 
		return 0;

	if(l==tl && r==tr){
		return t[v];
	}
	ll tm = (tl+tr)/2;
	return sum(v*2,tl,tm,l,min(r,tm)) + sum(v*2+1,tm+1,tr,max(l,tm+1),r);
}

void update(ll v, ll tl, ll tr, ll pos, ll new_val){
	if(tl==tr){
		t[v]=new_val;
	}
	else{
		ll tm=(tl+tr)/2;
		if(pos<=tm)
		update(v*2,tl,tm,pos,new_val);
		else
		update(v*2+1,tm+1, tr, pos, new_val);
		t[v]=t[v*2]+t[v*2+1];
	}
}


// Trie 26 alphabets
struct Trie
{
    Trie *c[26];
};
 
Trie *getnode()
{
    Trie *root = new Trie;
    for (int i = 0; i < 26; i++)
    {
        root->c[i] = NULL;
    }
    return root;
}
 
void insert(string &s, Trie *root)
{
    Trie *node = root;
    ll i;
    FOR(i, s.length())
    {
        if (!node->c[s[i] - 'a'])
        {
            node->c[s[i] - 'a'] = getnode();
        }
        node = node->c[s[i] - 'a'];
    }
}

// Trie another implementation with search function
// change 'a' to '0' and 26 to 2 for Bit Trie
const ll N = 1e5 + 11;
ll ptr = 1ll, nxt[N][26], endWord[N];
void insert(string &s) {
    int c = 0;
    for (int i = 0; i < (int)s.size(); c = nxt[c][s[i] - 'a'], ++i)
        if (!nxt[c][s[i] - 'a']) nxt[c][s[i] - 'a'] = ptr++;
    endWord[c]++;
}
 
bool search(string &s) {
    int c = 0;
    for (int i = 0; i < (int)s.size(); c = nxt[c][s[i] - 'a'], ++i)
        if (!nxt[c][s[i] - 'a']) return false;
    return (endWord[c] > 0);
}


vector<int> pr,rk;
int getp(int a){
	return a == pr[a] ? a : pr[a] = getp(pr[a]);
}
 
int unite(int a, int b){
	a = getp(a), b = getp(b);
	if(a == b) return false;
	if(rk[a]<rk[b]) swap(a,b);
	rk[a] += rk[b];
	pr[b] = a;
	return true;
}