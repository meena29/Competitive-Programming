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

ll base = 1e9 + 7;

int n;
unordered_set<ll> vis;
int fin;
queue<pair<vector<int>, int> > q;

ll hashh(vector<int> &v){
	ll h = 0;
	for(int i = 0; i < 4; i++){
		h = h * base + v[i];
	}
	return h;
}

int main(){ _
	cin >> n;
	
	vector<int> cur(4, 0);
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		x--;
		cur[x] |= (1 << i);
	}

	for(int i = 0; i < n; i++){
		fin |= (1<<i);
	}

	
	int lows[4];
	
	q.push(mp(cur, 0));
	int dis;
	while(!q.empty()){
		cur = q.front().fi;
		dis = q.front().se;
		q.pop();
		
		if(cur[0] == fin){
			cout << dis << endl;
			return 0;
		}
		
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < n; j++){
				if((cur[i]&(1<<j))){
					lows[i] = j;
					break;
				}
			}
		}
		
		int x, y;
		for(int i = 0; i < 4; i++){
			if(!cur[i]) continue;
			x = lows[i];
			for(int j = 0; j < 4; j++){
				if(j == i) continue;
				
				if(!cur[j]){
					cur[i] ^= (1<<x);
					cur[j] ^= (1<<x);
					ll h = hashh(cur);
					if(vis.count(h)){
						cur[i] ^= (1<<x);
						cur[j] ^= (1<<x);
						continue;
					}
					
					vis.insert(h);
					q.push(mp(cur, dis+1));				
					cur[i] ^= (1<<x);
					cur[j] ^= (1<<x);
					continue;
				}
				
				y = lows[j];						
				if(y < x) continue;
				
				cur[i] ^= (1<<x);
				cur[j] ^= (1<<x);
				ll h = hashh(cur);
				if(vis.count(h)){
					cur[i] ^= (1<<x);
					cur[j] ^= (1<<x);								
					continue;
				}
				vis.insert(h);
				
				q.push(mp(cur, dis+1));				
				cur[i] ^= (1<<x);
				cur[j] ^= (1<<x);								
			}
		}
	}
		
	return 0;
}
