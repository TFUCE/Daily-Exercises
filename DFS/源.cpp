/*输入一个数n，输出1~n的全排列,n要在2~9内选择*/
/*int a[10], book[10], n;*/
/*深度优先搜寻函数基本格式*/
/*
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
*/

/*解救小哈*/
/*迷宫由n行m列的单元格组成(n和m都小于等于50)*/
/*每个单元格要么是空地，要么是障碍物*/
/*求从迷宫的起点通往小哈所在位置的最短路径*/
#include<iostream>
using namespace std;
int n, m, p, q, Min = 99999;
int a[51][51], book[51][51];
void dfs(int x, int y, int step) {
	int next[4][2]{
		{0,1},//向下走
		{1,0},//向右走
		{0,-1},//向上走
		{-1,0}//向左走
	};
	int tx, ty, k;
	//判断是否到达小哈的位置
	if (x == p && y == q) {
		if (step < Min)
			Min = step;
		return;
	}
	//枚举4种走法
	for (k = 0; k <= 3; k++) {
		//计算下一个点的坐标
		tx = x + next[k][0];
		ty = y + next[k][1];
		//判断是否越界
		if (tx<1 || tx>n || ty<1 || ty>m)
			continue;
		//判断该点是否为障碍物或者已经在路径中
		if (a[tx][ty] == 0 && book[tx][ty] == 0) {
			book[tx][ty] = 1;
			dfs(tx, ty, step + 1);
			book[tx][ty] = 0;
		}
	}
}

int main() {
	int i, j, startx, starty;
	//n行m列
	cin >> n >> m;
	//进入迷宫
	for ( i = 1; i <= n; i++)
		for ( j = 1; j <= m; j++)
			cin >> a[i][j];
			//输入起点和终点坐标
	cin >> startx >> starty >> p >> q;
	//从起点开始搜索
	book[startx][starty] = 1;
	dfs(startx, starty, 0);
	cout << Min;
}