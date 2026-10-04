#include <stdio.h> 
#include <stdlib.h>


struct student { 
    int regNo; 
    char name[50];
    struct student *next;
};



int main() { 
    struct student *head = NULL; 
    struct student *newnode = malloc(sizeof(struct student));


if (newnode == NULL ) { 
    printf("memory allocation failed\n");
    return 1; 

}

printf("enter registeration number :"); 
scanf("%d", &newnode->regNo);


printf("enter name : "); 
scanf("%s", &newnode->name);

newnode->next = NULL;


head = newnode;

printf("%d %s\n", head->regNo, head->name);



// current to display 
struct student *current = head; 
while (current != NULL) { 
    printf("%d %s\n" , current->regNo, current->name); 
    current = current->next;
}

// adding a student 

if (head == NULL) { 
    head = newnode; 


} else { 
    struct student *current = head; 
    while (current->next != NULL) { 
        current = current->next; 
    }
    current->next = newnode;
}



// delete 

int key; 
printf("Enter registration number to delete: ");
scanf("%d", &key);

struct student *current = head; 
struct student *previous = NULL; 

while (current != NULL && current->regNO != key) { 
    previous = current; 
    current = current->next;
}

if (current == NULL) { 
    printf("student not found\n");

}
else if (previous == NULL) { 
    head = current->next; 
    free (current);
} else {
    previous->next = current->next;
    free(current);
}






} 