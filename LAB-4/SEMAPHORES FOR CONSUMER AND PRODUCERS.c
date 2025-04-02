#include <stdio.h>
#include <stdlib.h>

int mutex = 1;
int full = 0;
int empty = 5;
int x = 0;

void wait(int *S) {
    (*S)--;
}

void signal(int *S) {
    (*S)++;
}

void producer() {
    if (mutex == 1 && empty > 0) {
        wait(&mutex);
        signal(&full);
        wait(&empty);
        x++;

        printf("Producer has produced: Item %d\n", x);
        signal(&mutex); // Unlock critical section
    } else {
        printf("Buffer is full!\n");
    }
}

void consumer() {
    if (mutex == 1 && full > 0) {
        wait(&mutex);
        wait(&full);
        signal(&empty);

        printf("Consumer has consumed: Item %d\n", x);
        x--;

        signal(&mutex);
    } else {
        printf("Buffer is empty!\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nEnter 1.Producer  2.Consumer  3.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: producer();
                    break;
            case 2: consumer();
                    break;
            case 3: exit(0);
            default: printf("Invalid choice! Please enter 1, 2, or 3.\n");
        }
    }

    return 0;
}
