#include <cs50.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(void)
{
   //Get card number
    long number = get_long("Number: ");

    //check if card number is valid
    int count = 0;
    long currentNumber = number;
    int loopRun = 0;
    long divider;

    //Loop through card number and Multiply every other digit by 2,
    //starting with the number’s second-to-last digit, and then add those products’ digits together.
    do
    {
        if(loopRun == 1)
        {
            divider = 100;
        }else{
            divider = 10;
        }
        long numberLoop = currentNumber/divider;
        long timesNumber = numberLoop % 10;
        long plusNumber = timesNumber * 2;

            if(plusNumber > 9)
            {
                long getFirstNumber = plusNumber / 10;
                long firstNumber = getFirstNumber %10;
                count = firstNumber + count;
                long secondNumber = plusNumber % 10;
                count = secondNumber + count;
            }else
            {
                count = plusNumber + count;
            }

            currentNumber = numberLoop;
            loopRun = 1;
    }
    while(currentNumber > 0);

    //Reset current number
    currentNumber = number;

    //Loop through card number(currentNumber) to get every other number and,
    //Add the sum to the sum of the digits that weren’t multiplied by 2.
    do
    {
        long getNumber = currentNumber % 10;
        count = count + getNumber;
        long loopCardNumber = currentNumber / 100;
        currentNumber = loopCardNumber;
    }while(currentNumber > 0);

    //Reset current number
    currentNumber = number;

    string isCardVaild;

    //Now determine whether card is vaild or not
    if(count % 10 == 0)
    {
       isCardVaild = "VALID";
    }else
    {
       isCardVaild = "INVALID";
    }

    //check whether card is Visa , MasterCard , or American Express
    int cardNumberLenght = 0;
    int firstTwoDigits = 0;

    //Loop through card number and get card length and first digits
    do
    {
        long getlastNumberOnCard = currentNumber % 10;
        long loopThroughCardNumber = currentNumber / 10;
        currentNumber = loopThroughCardNumber;
        if(currentNumber < 100 && currentNumber > 10)
        {
            firstTwoDigits = currentNumber + firstTwoDigits;
        }
        cardNumberLenght++;
    }while(currentNumber > 0);

    //determine whether card is Visa , MasterCard, American Express
    if(strcmp(isCardVaild,"VALID") == 0)
    {
        if((cardNumberLenght == 15 && firstTwoDigits == 34) || (firstTwoDigits == 37) )
        {
            printf("AMEX\n");
        }else if((cardNumberLenght == 16) && (firstTwoDigits == 51 || firstTwoDigits == 52 || firstTwoDigits == 53 || firstTwoDigits == 54 || firstTwoDigits == 55)){
            printf("MASTERCARD\n");
        }else if((cardNumberLenght == 13 || cardNumberLenght == 16) && (firstTwoDigits / 10 == 4)){
            printf("VISA\n");
        }else{
        printf("INVALID\n");
        }
    }else{
        printf("%s\n",isCardVaild);
    }
}