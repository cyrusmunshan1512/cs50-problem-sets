#include <stdio.h>
#include <cs50.h>

int main(void)
{
    float bill_amount = get_float("Bill amount: ");
    float tax_percent = get_float("Tax percent: ");
    int tip_percent = get_int("Tip percent: ");

    float total_bill = 1/2*(((100*(float)bill_amount*(int)tip_percent) + ((float)bill_amount*(int)tip_percent*(float)tax_percent) + (10000*(float)bill_amount) + (100*(float)bill_amount*(float)tax_percent))/5000);
    printf("You owe me $%f" , total_bill);
}