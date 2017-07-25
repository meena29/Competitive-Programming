#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(__typeof((v).begin()) it=(v).begin(); it != (v).end(); ++it)
#define meta __FUNCTION__,__LINE__

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

using namespace std;

const long double PI = 3.1415926535897932384626433832795;

template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}

typedef long long ll;
typedef pair<int,int> pii;

const int N = 100100;
const ll INF = 1ll << 60;

vector<pii> g[N];
ll c[N];
int bad[N], vis[N];

ll dfs(int cur, int prev){
	ll ret = c[cur];
	vis[cur] = 1;
	foreach(it, g[cur]){
		if(it->fi == prev) continue;
		if(bad[it->se]) continue;
		ret += dfs(it->fi, cur);
	}
	return ret;
}

ll ans;

void solve(){
	int n; sd(n);
	ans = INF;
	
	for(int i = 1; i <= n; i++){
		g[i].clear();
		scanf("%lld", c+i);
	}
	
	for(int i = 1; i < n; i++){
		int x, y; sd2(x,y);
		g[x].pb(mp(y,i));
		g[y].pb(mp(x,i));
	}
	
	for(int i = 1; i < n; i++){
		for(int j = i+1; j < n; j++){
			bad[i] = 1;
			bad[j] = 1;

			for(int k =1; k <= n; k++) vis[k] = 0;
			
			vector<ll> s;
			for(int k = 1; k <= n; k++){
				if(!vis[k]){
					s.pb(dfs(k,-1));
				}
			}
			
			sort(s.begin(), s.end());
			if(s[1] == s[2]){
				ans = min(ans, s[1] - s[0]);
			}
			
			bad[i] = 0;
			bad[j] = 0;
		}
	}
	
	for(int i = 1; i < n; i++){
		bad[i] = 1;

		for(int k =1; k <= n; k++) vis[k] = 0;
		
		vector<ll> s;
		for(int k = 1; k <= n; k++){
			if(!vis[k]){
				s.pb(dfs(k,-1));
			}
		}
		
		sort(s.begin(), s.end());
		if(s[1] == s[0]){
			ans = min(ans, s[1]);
		}
		
		bad[i] = 0;
	}
	
	if(ans == INF) ans = -1;
	printf("%lld\n", ans);
}

int main(){
	int q; sd(q); while(q--){
		solve();
	}	
	return 0;
}
