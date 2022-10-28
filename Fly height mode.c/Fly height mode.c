#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>

#include<ext/pb_ds/tree_policy.hpp>

using namespace std;

using namespace __gnu_pbds;



/****** Debugging Class *****/

vector<string> vec_splitter(string s) {

    s += ',';

    vector<string> res;

    while(!s.empty()) {

        res.push_back(s.substr(0, s.find(',')));

        s = s.substr(s.find(',') + 1);

    }

    return res;

}

void debug_out(

        vector<string> __attribute__ ((unused)) args,

        __attribute__ ((unused)) int idx, 

        __attribute__ ((unused)) int LINE_NUM) { cout << endl; } 

template <typename Head, typename... Tail>

void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {

    if(idx > 0) cout << ", "; else cout << "Line(" << LINE_NUM << ") ";

    stringstream ss; ss << H;

    cout << args[idx] << " = " << ss.str();

    debug_out(args, idx + 1, LINE_NUM, T...);

}

template<class K, class V>ostream& operator<<(ostream&s,const pair<K,V>&p){s<<'<'<<p.first<<", "<<p.second<<'>';return s;}

template<class T, class=typename T::value_type, class=typename enable_if<!is_same<T,string>::value>::type>

ostream& operator<<(ostream&s,const T&v){s<<'[';for(auto&x:v){s<<x<<", ";}if(!v.empty()){s<<"\b\b";}s<<']';return s;}

void __prnt(){cout<<endl;} template<class T, class...Ts>void __prnt(T&&a,Ts&&...etc){cout<<a<<' ';__prnt(etc...);}

#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)

#define debug2(...) __prnt(__VA_ARGS__)

/**********************************************/



void localMachine(){ 

#ifdef LOCAL

    freopen("/home/pseudonymous/workspace/cp/input.txt","r",stdin);

    freopen("/home/pseudonymous/workspace/cp/output.txt","w",stdout);

#endif

}



#define endl '\n'

#define x first

#define y second

#define mp make_pair

#define pb push_back

#define sz(x) ((int)(x).size()) 

#define rep(i,n) for(int i=0;i<n;i++)

#define rep2(i,start,n) for(int i=start;i<n;i++)

#define rep3(i,start,n) for(int i=start;i<=n;i++)

#define tr(it,x) for(auto it=x.begin();it!=x.end();it++)

#define print(a) tr(i,a) cout<<i<<" ";cout<<endl;

#define clr(x) memset(x,0,sizeof(x))

#define all(x) x.begin(), x.end()

#define rall(x) x.rbegin(), x.rend()

#define sortall(x) sort(all(x))

#define flush fflush(stdout)

#define precision(x) cout << fixed << setprecision(x)

#define IOS_BASE ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)



typedef long long ll;

typedef long double ld;

typedef pair<int,int> pi;

typedef pair<ll,ll> pl;

typedef vector<int> vi;

typedef vector<char> vc;

typedef vector<ll> vl;

typedef vector<ld> vd;

typedef vector<vi> vvi;

typedef vector<vc> vvc;

typedef vector<vl> vvl;

typedef vector<vd> vvd;

typedef vector<pi> vpi;

typedef vector<vpi> vvpi;

typedef vector<pl> vpl;

typedef vector<vpl> vvpl;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> oredered_set;



/****** some basic operations *****/

ll gcd(ll a, ll b){return(b?gcd(b,a%b):a);} 

ll lcm(ll a, ll b){return(a*(b/gcd(a,b)));}

vl gcdExt(ll a, ll b){if(a==0)return{b,0,1};vl temp=gcdExt(b%a,a);return{temp[0],temp[2]-b/a*temp[1],temp[1]};}

ll powerMod(ll a,ll b,ll m=1e9+7){return(!b?1:(b&1?a*powerMod(a*a%m,b/2,m)%m:powerMod(a*a%m,b/2,m)%m));}

ll modInv(ll x,ll m=1e9+7){return powerMod(x,m-2,m);} 

ll nCr(ll n,ll r,ll mod=1e9+7){if(n<r)return 0;ll ans=1;for(int i=1;i<=r;i++){ans=(ans*(n-i+1))%mod;ans=(ans*modInv(i,mod))%mod;}return ans;}

/**********************************************/



const int inf=1<<30;

const long long INF=1ll<<60;

const int mod=1000000007;

const long double eps=1e-9;



const int N=2e5+5;



void solve()

{

    int n;

    cin>>n;

    vi h(n);

    for(int i=0;i<n;i++)

        cin>>h[i];

    if(n==1)

    {

        cout<<1<<endl;

        return;

    }

    map<int,int>events;

    for(int i=0;i<n-1;i++)

    {

        int l=min(h[i],h[i+1]);

        int r=max(h[i],h[i+1]);

        events[l]++;

        events[r]--;

    }

    int maxCnt=0;

    int curSum=0;

    for(auto &[e,cnt]:events)

    {

        cnt+=curSum;

        curSum=cnt;

        maxCnt=max(maxCnt,curSum);

    }

    cout<<maxCnt<<endl;

}

int main()

{

    IOS_BASE;

    localMachine();

    int t=1;

    //cin>>t;

    for(int i=1;i<=t;i++)

        solve();

    return 0;

}

