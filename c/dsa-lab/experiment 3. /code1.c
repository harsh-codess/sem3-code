#include <stdio.h>

struct student {
    int roll;
    char name[50];
    float marks;
};

int main(void) {
    struct student students[3];

    // Input records
    for (int i = 0; i < 3; i++) {
        printf("Enter roll no: ");
        scanf("%d", &students[i].roll);

        printf("Enter name: ");
        scanf("%49s", students[i].name);

        printf("Enter marks: ");
        scanf("%f", &students[i].marks);
    }

    printf("\nStudent records:\n");
    for (int i = 0; i < 3; i++) {
        printf("%d %s %.2f\n",
               students[i].roll, students[i].name, students[i].marks);
    }

    // Linear search
    int key, found = 0;
    printf("\nEnter roll number for linear search: ");
    scanf("%d", &key);

    for (int i = 0; i < 3; i++) {
        if (students[i].roll == key) {
            printf("%d %s %.2f\n",
                   students[i].roll, students[i].name, students[i].marks);
            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("Student not found\n");
    }

    // Insertion sort
    for (int i = 1; i < 3; i++) {
        struct student temp = students[i];
        int j = i - 1;

        while (j >= 0 && students[j].roll > temp.roll) {
            students[j + 1] = students[j];
            j--;
        }
        students[j + 1] = temp;
    }

    printf("\nRecords after insertion sort:\n");
    for (int i = 0; i < 3; i++) {
        printf("%d %s %.2f\n",
               students[i].roll, students[i].name, students[i].marks);
    }

    // Binary search (records are now sorted)
    {
        int key;
        int low = 0, high = 2;
        int found = 0;

        printf("\nEnter roll number for binary search: ");
        scanf("%d", &key);

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (students[mid].roll == key) {
                printf("%d %s %.2f\n",
                       students[mid].roll, students[mid].name, students[mid].marks);
                found = 1;
                break;
            }
            else if (students[mid].roll < key) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        if (found == 0) {
            printf("Student not found\n");
        }
    }

    // Selection sort
    for (int i = 0; i < 2; i++) {
        int min = i;

        for (int j = i + 1; j < 3; j++) {
            if (students[j].roll < students[min].roll) {
                min = j;
            }
        }

        struct student temp = students[i];
        students[i] = students[min];
        students[min] = temp;
    }

    printf("\nRecords after selection sort:\n");
    for (int i = 0; i < 3; i++) {
        printf("%d %s %.2f\n",
               students[i].roll, students[i].name, students[i].marks);
    }

    return 0;



    // Shell sort
for (int gap = 3 / 2; gap > 0; gap = gap / 2) {
    for (int i = gap; i < 3; i++) {
        struct student temp = students[i];
        int j = i;

        while (j >= gap &&
               students[j - gap].roll > temp.roll) {
            students[j] = students[j - gap];
            j = j - gap;
        }

        students[j] = temp;
    }
}

printf("\nRecords after shell sort:\n");

for (int i = 0; i < 3; i++) {
    printf("%d %s %.2f\n",
           students[i].roll,
           students[i].name,
           students[i].marks);
}
}
