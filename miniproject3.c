#include <stdio.h>
#include <string.h>

#define MAX 50

struct Bill {
    int billId;
    char name[50];
    float amount;
};

void input(struct Bill b[], int n);
void display(struct Bill b[], int n);
void mergeSort(struct Bill b[], int low, int high);
void merge(struct Bill b[], int low, int mid, int high);
int linearSearch(struct Bill b[], int n, int key);

int main() {
    struct Bill b[MAX];
    int n, choice, key, pos;

    printf("Enter number of bills: ");
    scanf("%d", &n);

    input(b, n);

    do {
        printf("\n--- MENU ---\n");
        printf("1. Display Bills\n");
        printf("2. Sort Bills (Merge Sort)\n");
        printf("3. Search Bill by ID\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                display(b, n);
                break;

            case 2:
                mergeSort(b, 0, n - 1);
                printf("\nBills sorted using Merge Sort.\n");
                display(b, n);
                break;

            case 3:
                printf("Enter Bill ID to search: ");
                scanf("%d", &key);

                pos = linearSearch(b, n, key);

                if(pos != -1) {
                    printf("\nBill Found:\n");
                    printf("ID: %d\nName: %s\nAmount: %.2f\n",
                           b[pos].billId, b[pos].name, b[pos].amount);
                } else {
                    printf("Bill not found.\n");
                }
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while(choice != 4);

    return 0;
}

void input(struct Bill b[], int n) {
    for(int i = 0; i < n; i++) {
        printf("\nBill %d\n", i + 1);

        printf("Enter Bill ID: ");
        scanf("%d", &b[i].billId);

        printf("Enter Customer Name: ");
        scanf(" %[^\n]", b[i].name);

        printf("Enter Amount: ");
        scanf("%f", &b[i].amount);
    }
}

void display(struct Bill b[], int n) {
    printf("\n---------------------------------\n");
    printf("ID\tName\t\tAmount\n");
    printf("---------------------------------\n");

    for(int i = 0; i < n; i++) {
        printf("%d\t%s\t\t%.2f\n",
               b[i].billId, b[i].name, b[i].amount);
    }
}

void mergeSort(struct Bill b[], int low, int high) {
    if(low < high) {
        int mid = (low + high) / 2;

        mergeSort(b, low, mid);
        mergeSort(b, mid + 1, high);
        merge(b, low, mid, high);
    }
}

void merge(struct Bill b[], int low, int mid, int high) {
    struct Bill temp[MAX];
    int i = low, j = mid + 1, k = low;

    while(i <= mid && j <= high) {
        if(b[i].amount <= b[j].amount) {
            temp[k] = b[i];
            i++;
        } else {
            temp[k] = b[j];
            j++;
        }
        k++;
    }

    while(i <= mid) {
        temp[k] = b[i];
        i++;
        k++;
    }

    while(j <= high) {
        temp[k] = b[j];
        j++;
        k++;
    }

    for(i = low; i <= high; i++) {
        b[i] = temp[i];
    }
}

int linearSearch(struct Bill b[], int n, int key) {
    for(int i = 0; i < n; i++) {
        if(b[i].billId == key)
            return i;
    }
    return -1;
}


