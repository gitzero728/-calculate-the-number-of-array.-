#define rnd (((((INT)rand() << 15) | rand()) << 15) | rand())
#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

int main() {
	freopen("test\\in.txt", "w", stdout);
	
	srand(time(0));
	int n = rnd % 9 + 1;
	int k = rnd % n + 1;
	cout<<n<<' '<<k<<endl;
	return 0;
}
