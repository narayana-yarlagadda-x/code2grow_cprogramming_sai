#include <stdio.h>

int main()
{
    int prices[5] = {50, 30, 80, 120, 60};
//Prices for Coffee, Tea, Sandwich, Burger, Pastry;
    char items[5][20] = {"Coffee", "Tea", "Sandwich", "Burger", "Pastry"};
    int totalQuantity[5] = {0};
   // Track total quantity of each item sold
    int numCustomers, numItems, itemNo, qty;
    int totalRevenue = 0;

    printf(" Café Order Management System \n\n");

    // Ask number of customers
    printf("Enter total number of customers (max 10): ");
    scanf("%d", &numCustomers);

    if (numCustomers > 10)
     {
        printf("Maximum 10 customers allowed!\n");
        return 0;
    }

    // Process each customer
    for (int c = 1; c <= numCustomers; c++)
     {
        int customerTotal = 0;
        printf("\n Customer %d \n", c);
        printf("Enter number of items: ");
        scanf("%d", &numItems);

        printf("Enter item number and quantity:\n");
        for (int i = 0; i < numItems; i++)
         {
            scanf("%d %d", &itemNo, &qty);
            if (itemNo >= 1 && itemNo <= 5) {
                customerTotal += prices[itemNo - 1] * qty;
                totalQuantity[itemNo - 1] += qty;
            } else
             {
                printf("Invalid item number! Skipping...\n");
            }
        }

        printf("Total Bill for Customer %d: ₹%d\n", c, customerTotal);
        totalRevenue += customerTotal;
    }

    // Calculate total items sold, most and least ordered item
    int totalItemsSold = 0, mostIdx = 0, leastIdx = 0;

    for (int i = 0; i < 5; i++)
    {
        totalItemsSold += totalQuantity[i];
        if (totalQuantity[i] > totalQuantity[mostIdx]) mostIdx = i;
        if (totalQuantity[i] < totalQuantity[leastIdx]) leastIdx = i;
    }

   //Display summary
    printf("\nCafé Summary \n");
    printf("Total Revenue: ₹%d\n", totalRevenue);
    printf("Total Items Sold: %d\n", totalItemsSold);
    printf("Most Ordered Item: %s\n", items[mostIdx]);
    printf("Least Ordered Item: %s\n", items[leastIdx]);
    printf("\n");

    return 0;
}

