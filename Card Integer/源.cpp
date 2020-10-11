/*问题：牌型种树
	小明被劫持到X赌城，被迫与其他3人玩牌
	一副扑克牌（去掉大小王牌，共52张），均匀发给4个人，每个人13张
	如果不考虑花色，只考虑点数，也不考虑自己得到的牌的先后顺序，自己手里拿到的初始牌型组合共有多少种？
*/

/*解题通常步骤：
	①设数组
	②数字能否重复使用？能，略过这条；不能，设计标记数组
	③定义dfs()方法
	④判断递归结束条件，通常是step越界，并进行等式判断
	⑤写递归进行时的做法
	⑥写main()
*/

#include<iostream>
using namespace std;
int a[13];
int cont = 0;
void dfs(int step) {
	/*判断递归结束条件*/
	if (step == 13) {
		int sum = 0;
		for (int i : a) {
			sum += i;
		}
		if (sum == 13) {
			cont++;
		}
		return;
	}
	/*递归进行时*/
	for (int i = 0; i <=4; i++) {
		a[step] = i;
		dfs(step + 1);
	}
}
int main() {
	dfs(0);
	cout << cont;
}