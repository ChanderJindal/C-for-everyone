#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FILE_SIZE 10

int max_val(int a , int b){
return a > b ? a:b ;
}

void get_avg(FILE *input ){
int  size ,val ;
rewind(input);
size = getc(input);
double avg = 0;
int max_ = -1;
while((val = getc(input)) != -1){
    avg += val;
    max_ = max_val(max_,val);
}
avg /= size;
fclose(input);
FILE* output;
output = fopen("answer-hw3","w");
fprintf(output, "The Average Value is 10%f and maximum Value is %d" , avg , max_);
fclose(output);
printf( "\n The Average Value is 10%f and maximum Value is %d \n" , avg , max_);
}

void my_file_val(FILE* input){
    rewind(input);
    int size = getc(input);
printf("My file contains %d elements : \n\n" , size);
while((size = getc(input)) != -1){
    printf("%d \t" , size);
}
printf("\n\nThat's all Folks! \n");
}

void file_creater(){
FILE* input ;
input = fopen("Myfile" , "w+");
putc(FILE_SIZE,input);
for(int i = 0;i < FILE_SIZE ; i++){
    fputc(rand(),input);
}
my_file_val(input);
fclose(input);
}

int main(int argc ,  char *argv[])
{
    file_creater();
    FILE* input ;
    input = fopen("Myfile","r+");
    get_avg(input);

    return 0;
}
