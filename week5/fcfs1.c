#include<stdio.h>

int main() {
	int n, temp;
	printf("Enter the Number of Processes: ");
	scanf("%d", &n);

	int p[n], at[n], bt[n], tat[n], wt[n], ct[n];

	for(int i = 0; i < n; i++) {
		printf("Enter the Process ID, Arrival Time, Burst Time: ");
		scanf("%d %d %d", &p[i], &at[i], &bt[i]);
	}

	for(int i = 0; i < n - 1; i++) {
		for(int j = 1; j < n - i - 1; j++) {
			if (at[j] > at[j + 1]) {
				temp = at[j];
				at[j] = at[j + 1];
				at[j + 1] = temp;

				temp = bt[j];
				bt[j] = bt[j + 1];
				bt[j + 1] = temp;

				temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
	}

	ct[0] = at[0] + bt[0];

	for (int i = 1; i < n; i++) {
		if (ct[i - 1] < at[i]) {
			ct[i] = at[i] + bt[i];
		}else{
			ct[i] = ct[i - 1] + bt[i];
		}
	}

	float avg_tat = 0;
	float avg_wt = 0;

	for (int i = 0; i < n; i++) {
		tat[i] = ct[i] - at[i];
		wt[i] = tat[i] - bt[i];
		avg_tat = avg_tat + tat[i];
		avg_wt = avg_wt + wt[i];
	}

	avg_tat = avg_tat/n;
	avg_wt = avg_wt/n;


	printf("PID\tAT\tBT\tCT\tTAT\tWT\n");

	for (int i = 0; i < n; i++) {
		printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
	}

	printf("Average TAT = %f\n", avg_tat);
	printf("Average WT = %f\n", avg_wt);


	return 0;
}
