#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FILE_SIZE 10 // declaring the file size, can be changed as will

int max_val(int a , int b){ // finding the max value of two
return a > b ? a:b ;
}

void get_avg(FILE *input ){
int  size ,val ;
rewind(input);
size = getc(input); // getting the max_size
double avg = 0;
int max_ = -1;
while((val = getc(input)) != -1){
    avg += val; // taking total val
    max_ = max_val(max_,val);// taking max_val
}
avg /= size; // cal. average
fclose(input); // no more use of file, so closed it
FILE* output; // new file
output = fopen("answer-hw3","w"); // output file
fprintf(output, "The Average Value is 10%f and maximum Value is %d" , avg , max_); // printing the answer in output file
fclose(output);
printf( "\n The Average Value is 10%f and maximum Value is %d \n" , avg , max_); // a print out to main screen
}

void my_file_val(FILE* input){ // triggered by file_creater
    rewind(input);
    int size = getc(input);
printf("My file contains %d elements : \n\n" , size); // printing the elements in file
while((size = getc(input)) != -1)
    printf("%d \t" , size);
printf("\n\nThat's all Folks! \n");
}

void file_creater(){
FILE* input ;
input = fopen("Myfile" , "w+"); // to create the file under name "Myfile"
putc(FILE_SIZE,input);
for(int i = 0;i < FILE_SIZE ; i++){
    fputc(rand(),input); // adding numbers using random numbers
}
my_file_val(input); // printing the values
fclose(input);
}

int main(int argc ,  char *argv[])
{
    file_creater();// first creating file
    FILE* input ;
    input = fopen("Myfile","r+"); // opening file
    get_avg(input); // getting and printing file

    return 0;
}
