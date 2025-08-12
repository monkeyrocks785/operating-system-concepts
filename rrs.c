// RRS - Round Robin Scheduler

#include <stdio.h>

struct Process
{
    int id;         // Process ID
    int arrival;    // Arrival time
    int burst;      // Burst time
    int remaining;  // Remaining time for the process
    int completion; // Completion time
    int turnaround; // Turnaround time
    int waiting;    // Waiting time
};

int main()
{
    int n, tq;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for (int i = 0; i < n; i++)
    {
        p[i].id = i + 1;
        printf("Enter arrival time for process %d: ", p[i].id);
        scanf("%d", &p[i].arrival);
        printf("Enter burst time for process %d: ", p[i].id);
        scanf("%d", &p[i].burst);
        p[i].remaining = p[i].burst;
    }

    printf("Enter time quantum: ");
    scanf("%d", &tq);

    int currentTime = 0;
    int completed = 0;
    int flag;
    while (completed < n)
    {
        flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (p[i].arrival <= currentTime && p[i].remaining > 0)
            {
                flag = 1; // There is a process ready to execute
                if (p[i].remaining > tq)
                {
                    currentTime += tq;
                    p[i].remaining -= tq;
                }
                else
                {
                    currentTime += p[i].remaining;
                    p[i].completion = currentTime;
                    p[i].turnaround = p[i].completion - p[i].arrival;
                    p[i].waiting = p[i].turnaround - p[i].burst;
                    p[i].remaining = 0;
                    completed++;
                }
            }
        }
        if (flag == 0)
        {
            currentTime++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        p[i].turnaround = p[i].completion - p[i].arrival;
        p[i].waiting = p[i].turnaround - p[i].burst;
    }

    printf("Round Robin Scheduling:\n");
    printf("\nProcess ID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].id, p[i].arrival, p[i].burst, p[i].completion, p[i].turnaround, p[i].waiting);
    }

    return 0;
}