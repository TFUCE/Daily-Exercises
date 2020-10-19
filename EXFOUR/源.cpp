#include<iostream>
using namespace std;
void Decode(string str) {
	int x = str.length(),flag=0,i=0;
	while(str[flag]) {
		if (str[flag] >= '0' && str[flag] <= '9') {
			int x = str[flag] - '0';
			while (x--) {
				cout << str[i];
			}
			i = ++flag;
		}
		else if (str[i] != str[flag] && (str[flag] >= 'A' && str[flag] <= 'Z' || str[flag] >= 'a' && str[flag] <= 'z')) {
			cout << str[i];
			i = flag++;
		}
		else
			flag++;
	}
}
int main() {
	string str;
	cin >> str;
	Decode(str);
}