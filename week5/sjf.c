#include<stdio.h>

int main() {
	int n;

	printf("Enter the Number of Processes: ");
	scanf("%d", &n);

	int p[n], at[n], bt[n], completed[n], ct[n], tat[n], wt[n];

	for (int i = 0; i < n; i++) {
		printf("Enter the ProcessID, Arrival Time, Burst Time: ");
		scanf("%d %d %d", &p[i], &at[i], &bt[i]);
		completed[i] = 0;
	}

	int temp;

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (at[j] > at[j + 1]) {
				temp = at[j];
				at[j] = at[j + 1];		
				at[j + 1] = temp;

				temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;

				temp = bt[j];
				bt[j] = bt[j + 1];
				bt[j + 1] = temp;
			}
		}
	}


	ct[0] = at[0] + bt[0];
	int time_passed = ct[0];
	completed[0] = 1;
	int total = 1;
	int shortestLTP, shortestGTP, shortestBT;
	while (total < n) {
		shortestLTP = -1;
		shortestGTP = -1;
		shortestBT = 1000;
		for (int i = 0; i < n; i++) {
			if (completed[i] == 0 && bt[i] < shortestBT) {
				if (at[i] < time_passed) {
					shortestLTP = i;
				}else{
					shortestGTP = i;
				}
				shortestBT = bt[i];

			}
		}

		if (shortestLTP != -1) {
			ct[shortestLTP] = time_passed + bt[shortestLTP];
			time_passed = time_passed + bt[shortestLTP];
			completed[shortestLTP] = 1; 
		}else{
			ct[shortestGTP] = at[shortestGTP] + bt[shortestGTP];
			time_passed = ct[shortestGTP];
			completed[shortestGTP] = 1;
		}

		total = total + 1;
	}

	float avg_tat = 0;
        float avg_wt = 0;

	for (int i = 0; i < n; i++) {
		tat[i] = ct[i] - at[i];
		wt[i] = tat[i] - bt[i];
		avg_tat += tat[i];
		avg_wt += wt[i];
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



				
