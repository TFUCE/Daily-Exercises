//��һ�����У����еĵ�һ������ n�������ÿ������ǰһ�������� 2����������������ֵΪ�������
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