#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ELEMENTS 20 // size of elements is decided here

typedef struct node{ // creating a tree node
int data;
struct node* left_child;
struct node* right_child;
} node;

node* new_node(int new_data){ // a small function to make a new node on call
node* child = (node*)malloc(sizeof(node)); // allocating space
child->data = new_data; // initializing data
child->left_child = NULL;// initializing left pointer
child->right_child = NULL;// initializing right pointer
return child;
}

node* tree_builder(node* root , int new_data){
if(root == NULL){
    root = new_node(new_data); // if the root is not there then creating a new node
    return root;
}
if(root->data > new_data) // if the data is lower than that in it's root node it goes to left
   root->left_child = tree_builder(root->left_child,new_data);
   else// else it goes to right (includes larger values and equal values)
root->right_child = tree_builder(root->right_child,new_data);
return root;
}

void printer(node*root,FILE* output){ // inorder printer
    if(root == NULL) // NULL root means end of traversal of that branch
        return;
if(root->left_child != NULL) // before printing first checking left sub-tree
    printer(root->left_child,output);
printf("%d \t", root->data); // step 2 printing that root node
fprintf(output,"%d \t",root->data); // printing value in file not putc() utc value issue
if(root->right_child != NULL)// step 3 checking the right sub-tree
    printer(root->right_child,output);
}

void create_file(){ // creating the file for answers
FILE* input;
input = fopen("Tree_values","w"); // creating the file "Tree_values" to write in
fprintf(input,"%d \t",ELEMENTS); // first entering the size
srand(5);
for(int i = 0;i< ELEMENTS;i++)
    fprintf(input,"%d \t",rand());
  //  putc((unsigned int)rand(),input); // entering the values using random function
fclose(input); // closing file
}



int main(){
    create_file(); // first creating a file to read from
node* root = (node*)malloc(sizeof(node)); // creating the tree root node
root = NULL;
FILE* input; // opening the file to read from
input = fopen("Tree_values","r");
int size;
fscanf(input,"%d",&size); // getting the size of integers
for(int i = 0 ; i< size ; i++){
    int val;
fscanf(input,"%d",&val);
 root = tree_builder(root,val); // creating the tree using file input
}
fclose(input);
FILE* output; // creating the output file
output = fopen("TREE_INORDER","w");
fprintf(output,"In the Tree given in `Tree_values` with %d Elements the Inorder Values are : \n" , size); // opening sentence in file
printer(root,output); // putting the in order traversal in file
fclose(output);// end of files
return 0;
}
