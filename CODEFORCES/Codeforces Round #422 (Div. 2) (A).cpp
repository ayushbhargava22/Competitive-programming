#pragma comment(linker, "/STACK:256000000")
#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <vector>
#include <ctime>
#include <cstring>
#include <sstream>
 
//#include <unordered_map>
//#include <unordered_set>
 
 
using namespace std;
 
//types
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pii> vpll;
 
 
 
//define trick
#define VA_NUM_ARGS(...) VA_NUM_ARGS_IMPL_((0,__VA_ARGS__, 8,7,6,5,4,3,2,1))
#define VA_NUM_ARGS_IMPL_(tuple) VA_NUM_ARGS_IMPL tuple
#define VA_NUM_ARGS_IMPL(_0,_1,_2,_3,_4,_5,_6,_7,_8,N,...) N
#define macro_dispatcher(macro, ...) macro_dispatcher_(macro, VA_NUM_ARGS(__VA_ARGS__))
#define macro_dispatcher_(macro, nargs) macro_dispatcher__(macro, nargs)
#define macro_dispatcher__(macro, nargs) macro_dispatcher___(macro, nargs)
#define macro_dispatcher___(macro, nargs) macro ## nargs
 
 
 
//consts
const int INF = 1000001000;
const ll INFLL = INF * 1LL * INF;
const int mod = 1000 * 1000 * 1000 + 7;
const int mod9 = 1000 * 1000 * 1000 + 9;
const int modr = 99990001;
const ld PI = 3.1415926535897932385;
 
//for 
#define F(i, st, fn) for(int i=st, i##end=(fn); i<=i##end; i++)
#define FL(i, st, fn) for(ll i=st, i##end=(fn); i<=i##end; i++)
#define FIN(x,a) for(auto x:a)
#define FI(n) F(i, 0, n-1)
#define FI1(n) F(i, 1, n)
#define FJ(n) F(j, 0, n-1)
#define FJ1(n) F(j, 1, n)
#define R(i, st, fn) for(int i=st, i##end=(fn); i>=i##end; i--)
#define RI(n) R(i, n-1, 0)
 
 
//DB
#define DBN1(a)         std::cerr<<#a<<"="<<(a)<<"\n"
#define DBN2(a,b)       std::cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<"\n"
#define DBN3(a,b,c)     std::cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<"\n"
#define DBN4(a,b,c,d)   std::cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<"\n"
#define DBN5(a,b,c,d,e) std::cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<"\n"
#define DBN6(a,b,c,d,e,f) std::cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<" "<<#f<<"="<<(f)<<"\n"
#define DBN7(a,b,c,d,e,f,g) std::cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<" "<<#f<<"="<<(f)<<" "<<#g<<"="<<(g)<<"\n"
#define DBN8(a,b,c,d,e,f,g,h) std::cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<" "<<#f<<"="<<(f)<<" "<<#g<<"="<<(g)<<" "<<#h<<"="<<(h)<<"\n"
#define DBN(...) macro_dispatcher(DBN, __VA_ARGS__)(__VA_ARGS__)
 
//calc
#define CpCm(c,mod) (c/(mod)+(c%(mod)!=0)) 
 
//pair
#define x first
#define y second
 
//reading
#define FR(x) freopen(x, "rt", stdin)
#define FW(x) freopen(x, "wt", stdout)
#define FRW(x, y) FR(x); FW(y)
#define UNSYNC() ios::sync_with_stdio(false)
 
#define D(type, x) type x; read(x)
#define DS(...) string __VA_ARGS__; read(__VA_ARGS__)
#define DI(...) int __VA_ARGS__; read(__VA_ARGS__)
#define DL(...) ll __VA_ARGS__; read(__VA_ARGS__)
#define DD(...) double __VA_ARGS__; read(__VA_ARGS__)
#define DX(...) ld __VA_ARGS__; read(__VA_ARGS__)
#define DP(...) pll __VA_ARGS__; read(__VA_ARGS__)
#define DC(...) char __VA_ARGS__; read(__VA_ARGS__)
#define DIS(x,...) DI(x);DS(__VA_ARGS__)
#define DIC(x,...) DI(x);DC(__VA_ARGS__)
#define DCL(x,...) DC(x);DL(__VA_ARGS__)
#define DLS(x,...) DL(x);DS(__VA_ARGS__)
#define DSL(x,...) DS(x);DL(__VA_ARGS__)
#define DIC(x,...) DI(x);DC(__VA_ARGS__)
#define DLX(x,...) DL(x);DX(__VA_ARGS__)
#define DCD(x,...) DC(x);DD(__VA_ARGS__)
#define DA(x,n) DI(n);readN(x,n)
#define DA1(x,n) DI(n);readN(x,n,1)
#define DAS(x,n,s) DI(n);readN(x,n,s)
#define RA(x,n) readN(x,n)
#define RA2(x,n,m) FI(n) readN(x[i],m)
#define RA1(x,n) readN(x,n,1)
 
#define TESTS DI(tests);F(test,1,tests)
#define TESTSI(i) DI(i##s);F(i,1,i##s)
 
#define ZI(...) int __VA_ARGS__; zero(0,__VA_ARGS__)
#define ZL(...) ll __VA_ARGS__; zero(0,__VA_ARGS__)
#define ZS(...) string __VA_ARGS__; zero(0,__VA_ARGS__)
#define ZP(...) pll __VA_ARGS__; zero(pll(0,0),__VA_ARGS__)
 
 
template<class T> void zero(T val, T& x) { x = val; }
template<class T, class... Targs> void zero(T val, T& x, Targs&... Fargs) { x = val; zero(val, Fargs...); }
 
 
template<class T, class T2> std::istream& operator>> (std::istream& is, pair<T, T2>& p) { return is >> p.x >> p.y; }
template<class T> std::istream& readN(T& x, int n, int st = 0) { F(i, st, st + n - 1) cin >> x[i]; return cin; }
template<class T> std::istream& readS(set<T>& x, int n) { T y = *x.rbegin(); FI(n) { cin >> y; x.insert(y); } return cin; }
template<class T> std::istream& read(T& x) { return cin >> x; }
template<class T, class... Targs> std::istream& read(T& x, Targs&... Fargs) { return read(x), read(Fargs...); }
 
 
#define prec(n) cout.precision(n);cout.setf(cout.fixed);
#define ln(...) out(__VA_ARGS__)<<"\n"
#define vln(v) ln(v.size());out(v)<<"\n"
#define vsizeline(v) cout<<v.size()<<" ";out(v)<<"\n"
#define puts3(a,b,f,s,t) {auto fvalc=(a),svalc=(b);puts(fvalc==svalc?s:fvalc>svalc?f:t);}
#define yn(c) puts(c?"YES":"NO");
#define ynm(c) puts(c?"Yes":"No");
#define dbputs3(a,b,f,s,t) {auto fvalc=(a),svalc=(b);puts(fvalc==svalc?s:fvalc>svalc?f:t);DBN(fvalc,svalc);}
template<class T, class T2> std::ostream& operator<< (std::ostream& os, pair<T, T2> p) { return os << p.x << " " << p.y; }
template<class T> std::ostream& operator<< (std::ostream& os, vector<T> v) { bool f = true; for (auto y : v) { if (!f) os << ' '; os << y;  f = false; } return os; }
template<class T> std::ostream& operator<< (std::ostream& os, set<T> v) { bool f = true; for (auto y : v) { if (!f) os << ' '; os << y;  f = false; } return os; }
template<class T> std::ostream& operator<< (std::ostream& os, multiset<T> v) { bool f = true; for (auto y : v) { if (!f) os << ' '; os << y;  f = false; } return os; }
template<class T, class T2> std::ostream& operator<< (std::ostream& os, map<T, T2> v) { bool f = true; for (pair<T, T2> y : v) { if (!f) os << ' '; os << y.x << "=>" << y.y;  f = false; } return os; }
template<class T> std::ostream& outV(T x, char del = ' ') { bool f = true; for (auto y : x) { if (!f) cout << del; cout << y;  f = false; } return cout; }
template<class T> std::ostream& outN(T x, int n = -1, int st = 0) { F(i, st, n == -1 ? (int)x.size() - 1 : st + n - 1) { cout << x[i]; if (i < iend) cout << ' '; } return cout; }
template<class T> std::ostream& outAN(T x, int n = -1, int st = 0) { F(i, st, n - 1) { cout << x[i]; if (i < iend) cout << ' '; } return cout; }
template<class T> std::ostream& outA2(T x, int n, int m) { FI(n) { FJ(m) cout << x[i][j] << (j == m - 1 ? '\n' : ' '); } return cout; }
template<class T> std::ostream& out(T x) { return cout << x; }
template<class T, class... Targs> std::ostream& out(T x, Targs... Fargs) { return out(x) << " ", out(Fargs...); }
 
template<typename T> void srt(T& a, int st, int fn, bool isArr) { sort(a + st, a + fn + 1); }
template<class T> void srt(T& a, int st = 0, int fn = 0) { sort(a.begin() + st, fn ? a.begin() + fn + 1 : a.end()); }
 
template<typename T> T rev_num(T a) { T r = 0; for (; a; a /= 10) r = r * 10 + a % 10; return r; }
template<typename T> void rev(T& a, int st, int fn, bool isArr) { reverse(a + st, a + fn + 1); }
template<class T> void rev(T& a, int st = 0, int fn = 0) { reverse(a.begin() + st, fn ? a.begin() + fn + 1 : a.end()); }
 
ll sqr(ll a) { return a*a; };
ll sqr(int a) { return a * 1LL * a; };
ld sqr(ld a) { return a*a; };
ld dist(pll x, pll y) { return sqrt(sqr(x.x - y.x) + sqr(x.y - y.y)); }
 
ll phi(int n) { int res = n; for (ll i = 2; i*i <= n; i++) if (n%i == 0) { while (n%i == 0) n /= i; res -= res / i; } if (n > 1) res -= res / n; return res; }
ll bpm(ll a, ll n = -2, ll m = mod) { n = n < 0 ? n + m : n; ll r = 1; while (n) { if (n & 1) r = (r*a) % m; a = (a*a) % m; n >>= 1; } return r; }
ull gcd(ull a, ull b) { while (b) { a %= b; swap(a, b); } return a; }
//
vi ero_p, ero_l; void ero(int n) { ero_l.resize(n + 1); ero_l[0] = -1; F(i, 2, n) if (!ero_l[i]) { ero_p.push_back(i); ero_l[i] = i; for (ll j = i * 1LL * i; j <= n; j += i) { ero_l[j] = i; } } }
//gcd with call_back
ll gcd_cb(ll a, ll b, ll&x, ll&y){ if (!b) { x = 1; y = 0; return a; }	ll x1, y1, g;	g = gcd_cb(b, a%b, x1, y1); x = y1;	y = x1 - a / b*y1; return g; }
//fact
vll fact; void fact_prec(int n = 20){ fact.resize(n + 1); fact[0] = 1; FI1(n) { fact[i] = fact[i - 1] * i; } }
vector<ld> factd; void fact_precd(int n = 146){ factd.resize(n + 1); factd[0] = 1; FI1(n) { factd[i] = factd[i - 1] * i; } }
string str(ll a) { string r = ""; for (; a; a /= 10) r += a % 10 + '0'; rev(r); return r; }
template <class T>int bitc(T x) { int r = 0;  for (T d = x; d >= 0; d >>= 1) r += d & 1; return r; }
 
const int N = 7000006;
 
int bal[50];
int main() {
	//FRW("input.txt", "output.txt");
	//UNSYNC();
 
	DI(a, b);
	fact_prec(12);
	ln(fact[min(a, b)]);
	return 0;
}