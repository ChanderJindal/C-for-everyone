#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{ // here the node is created
int data; // data / info field
struct node* next; // next node pointer for triversal
} node;

//node*
void adder(node** head , int new_data){ // here with new_data a new node is created and added in the linked list
node* temp = malloc(sizeof(node)); // initializing the size first
temp->data = new_data;
temp->next =  NULL;
if((*head) != NULL)
    temp->next = (*head);
    (*head) = temp; // initializing the head
   // return (*head);
}

void printer(node* head){ // a simple print function for the list
    int counter =  0 ; // as have to print a total of 5 number in a line
while(head != NULL){
    printf("%d ", head->data); counter++;
    head = head->next;
if(counter%5 == 0) // ensuring 5 number limit
    printf("\n");
}
//printf(" NULL "); // NULL marks the end of list
}

void sorter(node* head ){ // the main sorting function

  node*  temp1 = malloc(sizeof(node)); // first comes initializing
  node*  temp2 = malloc(sizeof(node));
  temp1 = head; // temp1 stores the starting point
while(temp1->next != NULL){ // till the end
  temp2 = temp1->next; // temp2 is for compare
  while(temp2 != NULL){ // from next of temp1 till end
    if(temp2->data < temp1->data){ // if temp2's data is lower than temp1's data (for all data)
            // a bit fancy way to swap value of two number , say temp1  data = x , temp2 data = y
        temp2->data += temp1->data; //  temp2 data = x + y
        temp1->data = temp2->data-temp1->data; // temp1 data = x+y - x = y
        temp2->data = temp2->data-temp1->data; // temp2 data = x+y - y = x
    }
    temp2 = temp2->next; // then onto next temp2
  }
  temp1 = temp1->next; // onto next temp1
}
}

int main(){
    node* head = NULL; // creating head node
    for(int i = 0 ; i< 100 ; i++)
    adder(&head,rand()%1001); // generating the linked list using Random function

    printer(head); // printing initial list
        printf("\n Line Change \n"); // marker that initial list is over
    sorter(head); // sorting the list
    printf("After Sorting \n"); // marker that sorting is over
    printer(head); // printing new list
    return 0;
}
