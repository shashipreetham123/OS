#include <stdio.h>
int main() {

    int p[20], at[20], bt[20], ct[20], tat[20], wt[20];

    int completed[20] = {0};
    int n;

    printf("Enter the Number of Processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter the Process ID, Arrival Time and Burst Time: ");
        scanf("%d%d%d", &p[i], &at[i], &bt[i]);
        
    }

    int completed_count = 0;
    int current_time = 0;

    printf("Gantt Chart: \n");

    while(completed_count < n) {
        int shortest = -1;

        for (int i = 0; i < n; i++) {
            if (at[i] <= current_time && completed[i] == 0) {
                    if (shortest == -1 || bt[i] < bt[shortest]) {
                        shortest = i;
                    }
            }
        }

        if (shortest == -1) {
            current_time++;
            continue;
        }
        
        current_time += bt[shortest];
        completed[shortest] = 1;
        ct[shortest] = current_time;
        tat[shortest] = ct[shortest] - at[shortest];
        wt[shortest] = tat[shortest] - bt[shortest];

        completed_count++;

        printf("|P%d", p[shortest]);
            
    }

    printf("|\n");

    float avg_tat = 0.0f;
    float avg_wt = 0.0f;

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    for (int i = 0; i < n; i++) {
        avg_tat += tat[i];
        avg_wt += wt[i];
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    
    avg_tat = avg_tat/n;
    avg_wt = avg_wt/n;

    printf("Average Turn Around Time: %f\n", avg_tat);
    printf("Average Waiting Time: %f\n", avg_wt);

    return 0;

    
}
