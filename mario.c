#include <stdio.h>
#include <cs50.h>

void drawrow(int, int);

int main(void)
{
int total;

while (true){
    printf("Height: ");
   total = get_int(); 
   
   if (total<24 && total >= 0){
       break;
   }
}


for (int rownumber=1; rownumber<(total+1); rownumber++){
    drawrow(total, rownumber);
}
}
void drawrow(int total, int rownumber)
{
    int spaces = total-rownumber;
    for (int i=0; i<spaces; i++){
    printf(" ");
    }
    for (int i=0; i<rownumber; i++){
    printf("#");
    }
    printf("  ");
    for (int i=0; i<rownumber; i++){
    printf("#");
    }
    printf("\n");
}