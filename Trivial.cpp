#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

int f[1010];
int num[1010][1010];

bool ok(int n, int k) {
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= k; j++) num[i][j] = num[i - 1][j];
		num[i][f[i]]++;
	}
	for(int i = k; i <= n; i++) {
		bool ok = 1;
		for(int j = 1; j <= k; j++) if(num[i][j] - num[i - k][j] == 0) {
			ok = false; break;
		}
		if(ok) return true;
	}
	return false;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("test\\in.txt", "r", stdin);
	freopen("test\\test.txt", "w", stdout);
#endif
	
	int n, k; scanf("%d %d", &n, &k);
	INT mul = 1;
	for(int i = n; i--; ) mul *= k;
	
	INT ans = 0;
	for(INT c = mul; c--; ) {
		INT s = c;
		for(int i = 1; i <= n; i++) f[i] = s % k + 1, s /= k;
		if(ok(n, k)) ans++;
	}
	cout<<ans<<endl;
	return 0;
}
