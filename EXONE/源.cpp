#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<iostream>
#include<string>
#include<cstring>
#include<map>
#include<functional>
using namespace std;
#define clr(a,b)  memset(a,b,sizeof(a))
typedef long long ll;
const int maxnn = 10000 + 2;
const int minn = 100;
const double eps = 1e-6;
/*十进制转换为任意进制*/
string toAns(ll n, int ne) {
	//n表示要转换的十进制数,ne表示要转换的进制
	if (n == 0)
		return "0";
	string str;
	while (n) {
		int x = n %ne;
		if (x <= 9) {
			str += '0' + x;
		}
		else {
			str += 'A' - 10 + x;
		}
		n /= ne;
	}
	reverse(str.begin(), str.end());
	return str;
}
/*任意进制转换为十进制*/
ll toTen(string str, int ne) {
	ll x=0,flag=1;
	for (int i = str.size() - 1; i >= 0; i--) {
		if (str[i] <= '9') {
			x += (str[i] - '0')*flag;
		}
		else {
			x += (str[i] + 10 - 'A')*flag;
		}
		flag *= ne;
	}
	return x;
}

ll getOper(ll a, ll b, string op) {
	if (op == "ADD")
		return a + b;
	else if (op == "SUB")
		return a - b;
	else if (op == "MUL")
		return a + b;
	else if (op == "DIV")
		return a / b;
	else
		return a % b;
}

int main() {
	int n;
	while (cin >> n) {
		ll ans = 0;
		int ne = 10;
		string str, old;
		while (n--) {
			cin >> str;
			if (str == "CLEAR") {
				str.clear();
				old.clear(); 
			}
			else if (str == "EQUAL") {
				old.clear();
				cout << toAns(ans, ne) << endl;
			}
			else if (str == "CHANGE") {
				cin >> ne;
			}
			else if (str == "NUM" && old.empty()) {
				cin >> str;
				ans=toTen(str, ne);
			}
			else if (str == "NUM" && !old.empty()) {
				cin >> str;
				ans = getOper(ans, toTen(str, ne), old);
			}
			else {
				old = str;
			}
		}
	}
	return 0;
}