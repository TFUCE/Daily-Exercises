//有一个序列，序列的第一个数是 n，后面的每个数是前一个数整除 2，请输出这个序列中值为正数的项。
#include<iostream>
using namespace std;
typedef long long ll;
void HalfNumber(ll n) {
	if (n != 0) {
		cout << n << " ";
		HalfNumber(n / 2);
	}
}
int main() {
	ll n;
	cin >> n;
	HalfNumber(n);
}