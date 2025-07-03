// Shopping cart program  
// Features:
// - Enter the name of an item
// - Enter a price for an item
// - Enter a quantity of an item
// - Resulting total is displayed

#include <stdio.h>
#include <string.h>

int main() {

    // Declare variables 
    char item_name[50] = "";
    float price = 0.0f;
    int quantity = 0;
    char currency = '$';
    float total = 0.0f;

    // Get user input
    printf("What item would you like to purchase? ");
    fgets(item_name, sizeof(item_name), stdin);
    item_name[strlen(item_name) - 1] = '\0';
    printf("What is the price for each? ");
    scanf("%f", &price);
    printf("How many would you like to buy? ");
    scanf("%d", &quantity);

    total = price * quantity;

    printf("\nYou have purchased %d %s(s)\n", quantity, item_name);
    // floating point format specifiers %.nf
    // to display the floating point number to the nearest n decimal places 
    printf("%c%.2f", currency, total); 

    return 0;
}