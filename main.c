#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{ // here the node is created
int data; // data / info field
struct node* next; // next node pointer for traversal
struct node* prev;
} node;

//node*
void adder(node** head , int new_data){ // here with new_data a new node is created and added in the linked list
node* temp = malloc(sizeof(node)); // initializing the size first
temp->data = new_data; // other common initializations for a new node
temp->next =  NULL;
temp->prev = NULL;
if((*head) != NULL){
    temp->next = (*head); // if not a new node connect it to head
    (*head)->prev = temp;
}
    (*head) = temp; // initializing the head
   // return (*head);
}

void printer(node* head){ // a simple print function for the list
while(head != NULL){
    printf("%d -> ", head->data);
    head = head->next;
}
printf(" NULL "); // NULL marks the end of list
}

void duplicates(node* head){
node* temp1 = malloc(sizeof(node)); // starting point
temp1 = head; // initializing to starting point
  node*  temp2 = malloc(sizeof(node)); // to compare
while(temp1->next != NULL){ // to check from start to end
  temp2 = temp1->next;
  while(temp2->next != NULL){ // this is misses the last element every time, but it wouldn't work other-wise
    if(temp2->data == temp1->data){
            temp2->prev->next = temp2->next; // re-connecting the nodes
            temp2->next->prev = temp2->prev;
    }
    temp2 = temp2->next;
  }
  temp1 = temp1->next;
}
// to check the last node/element , note that temp1 is currently at last node of list
temp2 = head;  // initializing to starting point
while(temp2->next != NULL){
    if(temp1->data == temp2->data){
        temp1->prev->next = NULL; // if there is a match then last node is to be removed and loop can be broken
        free(temp1);
        break;
    }
}
return ;
}

int main(){
    node* head = NULL; // creating head node
    for(int i = 0 ; i< 100 ; i++)
    adder(&head,rand()%50); // generating the linked list using Random function

    printer(head); // printing initial list
        printf("\n Processing \n\n"); // marker that initial list is over
    duplicates(head);  // removes duplicates
        printer(head); // prints answer

    return 0;
}
