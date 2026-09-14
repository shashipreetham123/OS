#include <stdio.h>

    int queue[50];
    int front = 0;
    int rear = 0;

    int p[20], at[20], bt[20], remaining[20], ct[20], tat[20], wt[20];

    int visited[20] = {0};
    int n;
    int time_quantum;

    printf("Enter the Number of Processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter the Process ID, Arrival Time and Burst Time: ");
        scanf("%d%d%d", &p[i], &at[i], &bt[i]);
        remaining[i] = bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &time_quantum);


    int completed = 0;

    int current_time = 0;

    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (at[i] <= current_time && visited[i] == 0) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
        if (front == rear) {
            current_time++;
            continue;
        }
        for (int i = front; i < rear; i++) {
            int process = queue[i];
            int start_time = current_time;
            if (remaining[process] > time_quantum) {
                remaining[process] -= time_quantum;
                current_time += time_quantum;

                for (int i = 0; i < n; i++) {
                    if (at[i] <= current_time && visited[i] == 0) {
                        queue[rear++] = i;
                        visited[i] = 1;
                    }
                }
                
                queue[rear++] = process;
            } else {
                current_time += remaining[process];
                remaining[process] = 0;
                ct[process] = current_time;
                tat[process] = ct[process] - at[process];
                wt[process] = tat[process] - bt[process];
                completed++;
            }
            front++;

            printf("|P%d (%d-%d) ", p[process], start_time, current_time);
        }
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
