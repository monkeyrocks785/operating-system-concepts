// FCFS - First-Come, First-Served Scheduling Algorithm

#include <stdio.h>

struct Process
{
    int id;         // Process ID
    int arrival;    // Arrival time
    int burst;      // Burst time
    int completion; // Completion time
    int turnaround; // Turnaround time
    int waiting;    // Waiting time
};

void swap(struct Process *a, struct Process *b)
{
    struct Process temp = *a;
    *a = *b;
    *b = temp;
}

void sortProcesses(struct Process p[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j].arrival > p[j + 1].arrival)
            {
                swap(&p[j], &p[j + 1]);
            }
        }
    }
}

int main()
{
    int n;
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
    }

    sortProcesses(p, n);

    int currentTime = 0;
    for (int i = 0; i < n; i++)
    {
        if (currentTime < p[i].arrival)
        {
            currentTime = p[i].arrival;
        }
        p[i].completion = currentTime + p[i].burst;
        p[i].turnaround = p[i].completion - p[i].arrival;
        p[i].waiting = p[i].turnaround - p[i].burst;
        currentTime = p[i].completion;
    }

    printf("\nFCFS Scheduling Results:\n");
    printf("\nProcess ID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].id, p[i].arrival, p[i].burst, p[i].completion, p[i].turnaround, p[i].waiting);
    }

    return 0;
}