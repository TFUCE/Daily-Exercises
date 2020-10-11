/*输入一个数n，输出1~n的全排列,n要在2~9内选择*/
#include<iostream>
using namespace std;
int a[10], book[10], n;
/*深度优先搜寻函数*/
void dfs(int step) {
	if (step == n + 1) {
		for (int i = 1; i <=n; i++)
			cout << a[i] << " ";
		cout << endl;
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (book[i] == 0) {
			a[step] = i;
			book[i] = 1;
			dfs(step + 1);
			book[i] = 0;
		}
	}
	return;
}
int main() {
	cin >> n;
	dfs(1);
	return 0;
	}