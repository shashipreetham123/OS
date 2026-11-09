
#include <stdio.h>

int main() {
    int queue[1000];
    int p[10], at[10], bt[10], ct[10], tat[10], wt[10];
    int visited[10], remaining[10];

    int n, i;
    int front = 0, rear = 0, count = 0;

    int time_quantum = 3;

    printf("Enter Number of Processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter Process ID, Arrival Time, Burst Time: ");
        scanf("%d%d%d", &p[i], &at[i], &bt[i]);

        visited[i] = 0;
        remaining[i] = bt[i];
    }

    int current_time = 0;
    int completed_count = 0;

    while (completed_count < n) {

        // Add arrived processes
        for (i = 0; i < n; i++) {
            if (at[i] <= current_time && visited[i] == 0) {
                queue[rear] = i;
                rear = (rear + 1) % 1000;
                count++;
                visited[i] = 1;
            }
        }

        // CPU is idle
        if (count == 0) {
            current_time++;
            continue;
        }

        // Select process
        int process = queue[front];
        front = (front + 1) % 1000;
        count--;

        // Execute process
        if (remaining[process] > time_quantum) {
            current_time += time_quantum;
            remaining[process] -= time_quantum;
        } else {
            current_time += remaining[process];
            remaining[process] = 0;

            ct[process] = current_time;
            completed_count++;
        }

        // Add newly arrived processes
        for (i = 0; i < n; i++) {
            if (at[i] <= current_time && visited[i] == 0) {
                queue[rear] = i;
                rear = (rear + 1) % 1000;
                count++;
                visited[i] = 1;
            }
        }

        // Reinsert unfinished process
        if (remaining[process] > 0) {
            queue[rear] = process;
            rear = (rear + 1) % 1000;
            count++;
        }
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    for (i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
            p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    return 0;
}
