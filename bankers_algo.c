// Banker's Algo for deadlock avoidance

#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 5 // Maximum number of processes
#define MAX_RESOURCES 3 // Maximum number of resources

int main()
{
    int i, j, k;

    // example data

    int alloc[MAX_PROCESSES][MAX_RESOURCES] = {{0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2}}; // Allocation Matrix
    int max[MAX_PROCESSES][MAX_RESOURCES] = {{7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3}};   // MAX Matrix
    int avail[MAX_RESOURCES] = {3, 3, 2};                                                              // Available Resources

    int need[MAX_PROCESSES][MAX_RESOURCES]; // Need Matrix
    int finish[MAX_PROCESSES] = {0};
    int safeSeq[MAX_PROCESSES];

    // Calculate need matrix = max - alloc

    for (int i = 0; i < MAX_PROCESSES; i++)
    {
        for (int j = 0; j < MAX_RESOURCES; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    // Banker's Algorithm

    int count = 0;
    while (count < MAX_PROCESSES)
    {
        bool found = false;
        for (i = 0; i < MAX_PROCESSES; i++)
        {
            if (finish[i] == 0)
            {
                bool canAllocate = true;
                for (j = 0; j < MAX_RESOURCES; j++)
                {
                    if (need[i][j] > avail[j])
                    {
                        canAllocate = false;
                        break;
                    }
                }
                if (canAllocate)
                {
                    for (k = 0; k < MAX_RESOURCES; k++)
                    {
                        avail[k] += alloc[i][k];
                    }
                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = true;
                }
            }
        }
        if (!found)
        {
            printf("System is not in safe state\n");
            return 0;
        }
    }

    printf("System is in safe state.\nSafe sequence is: ");
    for (i = 0; i < MAX_PROCESSES; i++)
    {
        printf("P%d ", safeSeq[i]);
    }

    return 0;
}


