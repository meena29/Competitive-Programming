#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define func __FUNCTION__
#define line __LINE__

using namespace std;

template<typename S, typename T> 
ostream& operator<<(ostream& out, pair<S, T> const& p){out<<'('<<p.fi<<", "<<p.se<<')'; return out;}

template<typename T>
ostream& operator<<(ostream& out, vector<T> const & v){
int l = v.size(); for(int i = 0; i < l-1; i++) out<<v[i]<<' '; if(l>0) out<<v[l-1]; return out;}

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}

typedef long long ll;
typedef pair<int,int> pii;

const ll N = (1ll << 32);

ll f(ll x){
    assert(x >= 0);
    if(x <= 1) return x;
	   
	ll d = -1;
    for(int i = 32; i >= 0; i--){
    	if((x & (1ll << i)) > 0){
    		d = i;
    		break;
    	}
    }
    
    ll ret = d * (1ll << (d-1));
    return ret + (x - (1ll << d) + 1) + f(x - (1ll << d));
}

void solve(){
    ll a, b;
    cin >> a >> b;
    
    ll ans = 0;
    if(a >= 0){
        ans = f(b) - f(max(a - 1, 0ll));
    }
    else{
    	a = abs(a);
        if(b < 0){
        	b = abs(b);
            ans = f(N - b) - f(max(N - a - 1, 0ll));
        }
        else{
            ans = f(N - 1) - f(max(N - a - 1, 0ll)) + f(b);
        }
    }
    
    cout << ans << endl;
    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin >> t;
    while(t--) solve();
    
    return 0;
}

