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

const int N = 200100;
int p[N], rnk[N], size[N], tot[N];
int n, q, w[200100];

map<int,int> memo;

void create(int x){
	p[x] = x;
	rnk[x] = 0;
	tot[x] = w[x];
	memo[tot[x]]++;
	return;
}

int find(int x){
	if(x != p[x]) return p[x] = find(p[x]);
	return x;
}

void merge(int x, int y){
	int px = find(x), py = find(y);
	
	if(px == py) return;
	
	int v1 = tot[px], v2 = tot[py];
	
	memo[v1]--;
	memo[v2]--;
	memo[v1+v2]++;	
	
	if(memo[v1] == 0) memo.erase(v1);
	if(memo[v2] == 0) memo.erase(v2);
		
	if(rnk[px] > rnk[py]){
		p[py] = px;
		tot[px] += tot[py];
	}
	else{
		p[px] = py;
		tot[py] += tot[px];
	}
	if(rnk[px] == rnk[py]) rnk[py] = rnk[py] + 1;
	return;
}

int main(){
	sd2(n,q);
	for(int i = 1; i <= n; i++){
		sd(w[i]);
		create(i);
	}
	
	while(q--){
		int u, v; sd2(u,v);
		merge(u,v);
		printf("%d\n", memo.begin()->fi);
	}
	
	return 0;
}
