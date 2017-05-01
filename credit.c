#include <stdio.h>
#include <cs50.h>

int comp(long long);
bool validation(long long);
int length(long long);
int array(long long, int);
int sum1(long long);
int sum2(long long);

int main(void)
{
long long number;

    printf("Number: ");
   number = get_long_long(); 

   if (validation(number)==true && comp(number)==1){
       printf("AMEX\n");
   }
    else if (validation(number)==true && comp(number)==2){
       printf("MASTERCARD\n");
   }
   else if (validation(number)==true && comp(number)==3){
       printf("VISA\n");
   }
     
   else {
       printf("INVALID\n");
   }
   
  return 0;
}

int comp(long long number){
    if (length(number)==15 && 
    ((array(number,1)==3 && array(number,2)==4)
    ||
    (array(number,1)==3 && array(number,2)==7)))
    {
        return 1;
    }
     else if (length(number)==16 && 
    (
        (array(number,1)==5 && array(number,2)==1)
    ||
        (array(number,1)==5 && array(number,2)==2)
     ||
        (array(number,1)==5 && array(number,2)==3)
     ||
        (array(number,1)==5 && array(number,2)==4)
     ||
        (array(number,1)==5 && array(number,2)==5)))
        {
        return 2;
    }
    else if (length(number)>12 && length(number)<17
    &&
    (array(number,1)==4)){
        return 3;
    }
    else {
        return 4;
    }
}

int length(long long number){
    int i=0;
    while (number>=10){
        number=number/10;
        i++;
    }
    return i+1;
}

int array(long long number, int cell){
        char str[20];
        int i = length(number);
        long long a = number;
        while(i>=0)
    {
        str[i]=a%10;
        a=a/10;
        i--;
    }
    return str[cell];
}

bool validation(long long number){
   if((sum1(number)+sum2(number))%10 == 0){
    return true;
}
    else {
        return false;
    }
}

int sum1 (long long number){
    int sum1=0;
    for(int i=length(number)-1; i>0; i=i-2)
    {
        if (length(array(number,i)*2)<2)
        {
        sum1=2*(array(number,i))+sum1;
        }
        else
        {
        sum1=sum1+array(2*(array(number,i)),1)+array(2*(array(number,i)),2);
        }
    }
    return sum1;
}

int sum2(long long number){
    int sum2=0;
    for(int i=length(number); i>0; i=i-2)
    {
        sum2=(array(number,i))+sum2;
        }
return sum2;
    
}