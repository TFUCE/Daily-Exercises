/*����һ����n�����1~n��ȫ����,nҪ��2~9��ѡ��*/
/*int a[10], book[10], n;*/
/*���������Ѱ����������ʽ*/
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

/*���С��*/
/*�Թ���n��m�еĵ�Ԫ�����(n��m��С�ڵ���50)*/
/*ÿ����Ԫ��Ҫô�ǿյأ�Ҫô���ϰ���*/
/*����Թ������ͨ��С������λ�õ����·��*/
#include<iostream>
using namespace std;
int n, m, p, q, Min = 99999;
int a[51][51], book[51][51];
void dfs(int x, int y, int step) {
	int next[4][2]{
		{0,1},//������
		{1,0},//������
		{0,-1},//������
		{-1,0}//������
	};
	int tx, ty, k;
	//�ж��Ƿ񵽴�С����λ��
	if (x == p && y == q) {
		if (step < Min)
			Min = step;
		return;
	}
	//ö��4���߷�
	for (k = 0; k <= 3; k++) {
		//������һ���������
		tx = x + next[k][0];
		ty = y + next[k][1];
		//�ж��Ƿ�Խ��
		if (tx<1 || tx>n || ty<1 || ty>m)
			continue;
		//�жϸõ��Ƿ�Ϊ�ϰ�������Ѿ���·����
		if (a[tx][ty] == 0 && book[tx][ty] == 0) {
			book[tx][ty] = 1;
			dfs(tx, ty, step + 1);
			book[tx][ty] = 0;
		}
	}
}

int main() {
	int i, j, startx, starty;
	//n��m��
	cin >> n >> m;
	//�����Թ�
	for ( i = 1; i <= n; i++)
		for ( j = 1; j <= m; j++)
			cin >> a[i][j];
			//���������յ�����
	cin >> startx >> starty >> p >> q;
	//����㿪ʼ����
	book[startx][starty] = 1;
	dfs(startx, starty, 0);
	cout << Min;
}