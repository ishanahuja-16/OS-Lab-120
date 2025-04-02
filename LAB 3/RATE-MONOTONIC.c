#include <stdio.h>
#include <math.h>

#define MAX_TASKS 10

typedef struct {
    int id;
    int execution;
    int period;
} Task;

void sort_by_priority(Task tasks[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (tasks[i].period > tasks[j].period) {
                Task temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }
}

int check_utilization(Task tasks[], int n) {
    double utilization = 0;
    for (int i = 0; i < n; i++) {
        utilization += (double)tasks[i].execution / tasks[i].period;
    }
    double bound = n * (pow(2.0, 1.0 / n) - 1);

    printf("Total Utilization: %.2f, Utilization Bound: %.2f\n", utilization, bound);

    return utilization <= bound;
}

void rate_monotonic(Task tasks[], int n) {
    int time = 0;
    int completed[MAX_TASKS] = {0};

    printf("\nScheduling Execution:\n");

    while (1) {
        int task_executed = -1;


        for (int i = 0; i < n; i++) {
            if (time % tasks[i].period == 0) {
                task_executed = i;
                break;
            }
        }

        if (task_executed != -1) {
            printf("At time %d: Task %d is executed\n", time, tasks[task_executed].id);
            time += tasks[task_executed].execution;
            completed[task_executed]++;
        } else {
            time++;
        }


        int all_completed = 1;
        for (int i = 0; i < n; i++) {
            if (completed[i] == 0) {
                all_completed = 0;
                break;
            }
        }

        if (all_completed) {
            break;
        }
    }
}

int main() {
    int n;
    printf("Enter the number of tasks: ");
    scanf("%d", &n);

    if (n > MAX_TASKS) {
        printf("Error: Maximum task limit exceeded.\n");
        return 1;
    }

    Task tasks[n];

    for (int i = 0; i < n; i++) {
        tasks[i].id = i + 1;
        printf("\nEnter details for Task %d\n", i + 1);
        printf("Execution time (C): ");
        scanf("%d", &tasks[i].execution);
        printf("Period (T): ");
        scanf("%d", &tasks[i].period);
    }

    sort_by_priority(tasks, n);

    if (check_utilization(tasks, n)) {
        rate_monotonic(tasks, n);
    } else {
        printf("Warning: Task set may not be schedulable under Rate Monotonic Scheduling.\n");
    }

    return 0;
}
