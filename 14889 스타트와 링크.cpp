#include <stdio.h>

int min = 1000000;
int input[20][20];
int n;
int select[21] = {-1,};

void dfs(int index, int count, int target);
void getmin();

int main() {
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &input[i][j]);
		}
	}
	dfs(0, n/2, 0);
	printf("%d",min);

}

void dfs(int index, int count, int target) {
	if (count == 0)	getmin();
	else if (target==n) 	return;
	else {
		select[index] = target;
		dfs(index+1, count-1, target+1 );
		dfs(index, count, target+1);
	}

}

void getmin() {
	int i, j, count=0, index=0;
	int start=0, link=0;
	int noselect[21] = {-1,};
	int sum = 0;
	for (i = 0; i < n; i++) {
		if (select[count] != i) {
			noselect[index++] = i;
			
		}
		else
			count++;
	}

	for (i = 0; i < n/2; i++) {
		for (j = 0; j < n/2; j++) {
			start += input[select[i]][select[j]];
			link += input[noselect[i]][noselect[j]];
		}
	}

	if (start > link)
		sum = start - link;
	else
		sum = link - start;

	if (sum < min)
		min = sum;
}