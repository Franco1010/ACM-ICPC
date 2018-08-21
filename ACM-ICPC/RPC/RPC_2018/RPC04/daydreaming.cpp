#include <bits/stdc++.h>
//#include </Users/francoarielramirezvilla/stdc++.h>
#define PI 3.14159265358979323846
#define EPS 1e-6
#define INF 1000000000000000LL

#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define FOR(i, a, b) for(int i=int(a); i<int(b); i++)
#define RFOR(i, a, b) for(int i=int(a)-1; i>=int(b); i--)
#define FORC(it, cont) for(auto it = (cont).begin(); it != (cont).end(); it++)
#define RFORC(it, cont) for(auto it = (cont).rbegin(); it != (cont).rend(); it++)
#define pb push_back

#define sz(c) ((int)c.size())
#define print(v) cout << #v" = " << v << endl
#define printArr(arr, a, b) FOR(i, a, b) cout << #arr << "[" << i << "] = " << arr[i] << endl
#define zero(v) memset(v, 0, sizeof(v))
#define uno(v) memset(v, 1, sizeof(v))
#define unoneg(v) memset(v, -1, sizeof(v))
#define toIntA(c) (c - 'A')
#define toInta(c) (c - 'a')
#define toInt0(c) (c - '0')
#define toCharA(i) (char)(i + 'a')
#define toChara(i) (char)(i + 'A')
#define toChar0(i) (char)(i + '0')


using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define MAXN 400
#define MOD 1000000007

ll arr[MAXN], arr3[MAXN], arr2[MAXN];
int n;

int main() { _
    while (cin >> n) {
        arr3[0] = INF;
        arr3[n+1] = -INF;
        FOR(i, 0, n)    cin >> arr3[i+1];

        int k = 0;
        arr[k ++] = arr3[0];
        FOR(i, 1, n+2) {
            if (arr3[i] != arr[k-1]) {
                arr[k ++] = arr3[i];
            }
        }

        n = k;
        k = 0;
        FOR(i, 1, n+1) {
            if (arr[i-1] > arr[i] && arr[i] < arr[i+1]) { // minimo
                arr2[k ++] = arr[i];
            }
            else if (arr[i-1] < arr[i] && arr[i] > arr[i+1]) { // maximo
                arr2[k ++] = arr[i];
            }
            else if (i == n) {
                arr2[k ++] = arr[i];
            }
        }

        if (k % 2 == 1)     k --;
        k--;
        ll money = 100;
        ll stocks = 0;
        for(ll i=0; i<k-1; i+=2) {
            stocks = min(ll(100000), money/arr2[i]);
            money -= arr2[i] * stocks;
            money += arr2[i+1] * stocks;
            stocks = 0;
        }

        cout << money << endl;
    }

    return 0;
}
