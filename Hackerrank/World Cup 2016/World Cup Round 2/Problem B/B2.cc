#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <cassert>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cerr.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define meta __FUNCTION__<<" "<<__LINE__<<" "
#define tr(x) cerr<<meta<<#x<<" "<<x<<endl;
#define tr2(x,y) cerr<<meta<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define tr3(x,y,z) cerr<<meta<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr4(w,x,y,z) cerr<<meta<<#w<<" "<<w<<" "<<#x<<" " <<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cerr<<meta<<#v<<" "<<v<<" "<<#w<<" "<<w<<" "<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cerr<<meta<<#u<<" "<<u<<" "<<#v<<" "<<v<<" "<<#w<<" "<<w<<" "<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;

using namespace std;

int n;
long long cnt;
set<vector<int> > memo;

void go(int val, vector<int> &v){
	if(memo.count(v)) return;
	
	if(v.size() == 1) return;
	memo.insert(v);
	
	if(!val) cnt++;
	
	int sz = v.size();
	for(int i = 1; i < sz; i++){
		vector<int> nxt;
		for(int j = 0; j < i-1; j++){
			nxt.pb(v[j]);
		}
		nxt.pb(v[i]+v[i-1]);
		for(int j = i+1; j < sz; j++){
			nxt.pb(v[j]);
		}
		
		int nval = val^v[i]^v[i-1]^(v[i]+v[i-1]);
		
		go(nval, nxt);
	}
}

int main(){
	sd(n);
	int val = 0;
	vector<int> a;
	for(int i = 0; i < n; i++){
		int x; sd(x);
		a.pb(x);
		val ^= x;
	}
	
	go(val, a);
	
	cout << cnt << endl;
	
	return 0;
}
