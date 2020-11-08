#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define limit  1000000
#define CARD_SIZE 7

typedef struct card{
int suit;
int value;
}cards;
int random_vals[CARD_SIZE];
float  one_pair = 0 , two_pair = 0 , three_kind = 0 , four_kind = 0, full_house = 0;

void pass(){
    int issue = 0;
for(int i = 0 ; i < CARD_SIZE ; i++){
    for(int j = 0 ;j < i ;j++){
        if(random_vals[i] == random_vals[j]){
            random_vals[i] = rand()%51;
            issue += 1;
        }
    }
}
if(issue != 0)
    pass();
return ;
}

void random_val(){ // triggered by card_values
for(int i = 0 ;i<CARD_SIZE;i++)
    random_vals[i] = rand()%51;
  for(int i = 0 ;i < CARD_SIZE;i++)
  //  printf("%d\t",random_vals[i]);
  //  printf("\n");

pass();
}

int card_type[4], card_value[13];
cards sets[CARD_SIZE];

void re_set(){ // just a re set as using global variable to make sure there is pre-set val  // triggered by card_values
for(int i = 0 ;i < 4;i++){
    card_type[i] = 0; card_value[i] =0;
    sets[i].suit = 0 ; sets[i].value = 0;
}
for(int i =4 ;i <CARD_SIZE;i++){                             // just tried something to reduce iterations
    card_value[i] = 0;
    sets[i].suit = 0 ; sets[i].value = 0;
}
for(int i = CARD_SIZE ; i < 13 ; i++)
        card_value[i] = 0;

}

void print_it(int card_suit , int card_pip){ // triggered in card_values
switch(card_suit){
case(0): printf("%d Club ",card_pip); break;// club = 0 / heart = 1 / diamond = 2 / spade = 3
case(1): printf("%d Heart ",card_pip); break;
case(2):printf("%d Diamond ",card_pip); break;
case(3):printf("%d Spade ",card_pip); break;
}
}

void card_values(){
random_val();
re_set();
for(int i = 0 ;i< CARD_SIZE ;i++){
    sets[i].suit = random_vals[i]%4;
    card_type[sets[i].suit] += 1;
    sets[i].value = random_vals[i]%13;
    card_value[sets[i].value] += 1;
   // print_it(sets[i].suit,sets[i].value);
}
//printf("\n");
}
void last_call(){
card_values();

int temp_2_cards = 0 , temp_3_cards = 0 , temp_3_kind = 0 , temp_4_kinds = 0;
for(int i = 0 ; i< 13 ; i++){
     //    printf("%d card_value ", card_value[i]);
    if(card_value[i] > 2){
        temp_3_cards++;temp_2_cards+= card_value[i]/2;
    }else if(card_value[i] > 1){
    temp_2_cards++;
    }
}
for(int i = 0 ;i < 4;i++){
       //         printf("%d card_type ", card_type[i]);
    if(card_type[i] > 3){
        temp_4_kinds = 1; temp_3_kind = 1;
    }else if(card_type[i]>2){
    temp_3_kind= 1;
    }
}
if(temp_4_kinds != 0){
    four_kind++;
  //  printf("\nfour_kind \n");
}else if(temp_2_cards!= 0 && temp_3_cards != 0){
full_house++;
   // printf("\n full_house \n");
}else if(temp_3_kind != 0){
three_kind++;
  //  printf("\n three_kind \n");
} if(temp_2_cards > 1 ){
two_pair++;
//    printf("\n two_pair \n");
} if(temp_2_cards == 1){
one_pair++;
 //   printf("\n one_pair \n");
}else{
   // printf("\n no_pair \n");
}
}



void probability_show(){
    srand(time(0));
for(int i = 0 ; i < limit;i++){
    last_call();
   // printf("\n-----------------------------------------------------------\n");
}
printf("The probabilities are : \n");

printf("no pair -> %0.8f \n", (float)1-(one_pair+two_pair)/limit);
printf("one pair -> %0.8f \n", (one_pair)/limit);
printf("two pair -> %0.8f \n", two_pair/limit);
printf("three of a kind -> %0.8f \n", (three_kind+four_kind)/limit);
printf("full house -> %0.8f \n", full_house/limit);
printf("4 of a kind -> %0.8f \n", four_kind/limit);
// no pair, one pair, two pair, three of a kind, full house and 4 of a kind

}

int main(){

probability_show();

    return 0;
}
/*
if(temp_4_kinds != 0){
    four_kind++;
  //  printf("\nfour_kind \n");
}else if(temp_2_cards!= 0 && temp_3_cards != 0){
full_house++;
   // printf("\n full_house \n");
}else if(temp_3_kind != 0){
three_kind++;
  //  printf("\n three_kind \n");
}else if(temp_2_cards > 1 ){
two_pair++;
//    printf("\n two_pair \n");
}else if(temp_2_cards == 1){
one_pair++;
 //   printf("\n one_pair \n");
}else{
   // printf("\n no_pair \n");
}
*/
/*
int arr[7];

int random(int val , int index){
for(int i = 0 ; i < index ;i++){
    if(val == arr[i]){
        srand(time(0));
        val = random(rand()%51,index);
        break;
    }
}
arr[index] = val;
return val;
}

void checker(){
for(int i = 0; i < 7;i++){
    srand(time(0));
    random(rand()%51,i);
   // printf("%d  ", arr[i] );
}

}
*/

    /*
//checker();
         srand(time(0));
for(int j = 0 ; j< 5 ; j++){
       // srand(time(0));
for(int i = 0 ; i< 7 ;i++){
    //srand(time(0));
    printf("%d " , rand()%51);
}
printf("\n");
}
printf("\n");
*/
/*
if(temp_four_kind != 0) // putting the tally for final one, 1 tally only
    four_kind += 1;
else if(temp_three_val != 0 && temp_one_pair != 0)
    full_house += 1;
else if(temp_three_kind != 0)
    three_kind += 1;
else if(temp_one_pair > 1)
    two_pair += 1;
else if(temp_one_pair != 0)
    one_pair += 1;
else
    no_pair += 1;
*/
/*
void final_setter(){ // triggered by  probability_show
card_values();
// keeping tally for this iteration
int max_suit = card_type[0];
for(int i = 1 ;i< 4 ;i++)
    if(max_suit < card_type[i])
        max_suit = card_type[i];

int max_val = card_value[0];
int  temp_pair = 0 , temp_three_val = 0;

for(int i = 1 ;i< 13 ;i++){
    if(card_value[i] > max_val)
        max_val = card_value[i];
    if(card_value[i] >= 3){
            if(temp_three_val == 0)
        temp_three_val =1;
    else
    temp_pair += 1;
}
}
// no pair, one pair, two pair, three of a kind, full house(3-2 + 2-4) and 4 of a kind
if(max_val > 3)
    two_pair++;
else if(max_val > 1)
    one_pair++;
    else
    no_pair++;
if(max_suit > 3)
    four_kind++;
else if(max_suit == 3)
    three_kind++;

if(temp_three_val > 0 && temp_pair >0)
    full_house++;

}
*/
// float no_pair = 0 , one_pair = 0 , two_pair = 0 , three_kind = 0 , four_kind = 0, full_house = 0;
