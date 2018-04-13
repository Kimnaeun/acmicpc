#include <stdio.h>

int choice[11];
int n;
int max = -1000000000, min = 1000000000;
int input[12];
void dfs(int cnt, int plus, int minus, int multi, int div, int sum);

int main() {
	int i, j, cnt = 0, index = 0;
	int oper[4];

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &input[i]);

	for (i = 0; i < 4; i++)
		scanf("%d", &oper[i]);

	dfs(1, oper[0], oper[1], oper[2], oper[3], input[0]);
}

void dfs(int cnt, int plus, int minus, int multi, int div, int sum) {

	if (cnt == n)
	{
		if (max < sum)
			max = sum;
		if (min > sum)
			min = sum;
		return;
	}

	if (plus != 0)
		dfs(cnt + 1, plus - 1, minus, multi, div, sum + input[cnt]);
	if (minus != 0)
		dfs(cnt+1, plus, minus-1, multi, div, sum - input[cnt]);
	if (multi != 0)
		dfs(cnt+1, plus, minus, multi-1, div, sum * input[cnt]);
	if (div != 0)
		dfs(cnt+1, plus, minus, multi, div-1, sum / input[cnt]);

}

