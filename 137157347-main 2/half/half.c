// Calculate your half of a restaurant bill
// Data types, operations, type casting, return value

#include <cs50.h>
#include <stdio.h>

float half(float bill, float tax, int tip);

int main(void)
{
    float bill_amount = get_float("Bill before tax and tip: ");
    float tax_percent = get_float("Sale Tax Percent: ");
    int tip_percent = get_int("Tip percent: ");

    float total_bill = (((float)1/4)*((((int)100*(float)bill_amount*(int)tip_percent) + ((float)bill_amount*(int)tip_percent*(float)tax_percent) + ((int)10000*(float)bill_amount) + ((int)100*(float)bill_amount*(float)tax_percent))/(int)5000));

    printf("You will owe $%.2f each!\n",total_bill);
}

// TODO: Complete the function

