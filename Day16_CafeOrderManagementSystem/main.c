#include <stdio.h>
int main()
{
    int prices[5]={50, 30, 80, 120, 60};
    char items[5][20]={"Coffee", "Tea", "Sandwitch", "Burger", "Pastry"};
    int sold[5]={0, 0, 0, 0, 0};
    int customers, i, j, totalItemsSold = 0;
    float totalRevenue = 0;
    //input
    printf("\nMenu:\n");
    printf("Item No.   Item Name     Price \n");
    for (i = 0; i < 5; i++)
    {
        printf("%d%-12s %d\n", i + 1, items[i], prices[i]);
    }
    printf("\nEnter total number of customers (max 10) = ");
    scanf("%d", &customers);
    if (customers <= 0 || customers > 10)
    {
        printf("Invalid number of customers! Please enter between 1 and 10. = ");
        return 0;
    }
    for (i = 1; i <= customers; i++)
    {
        int orderCount, itemNo, qty;
        float bill = 0;
        printf("\n--- Customer %d ---\n", i);
        printf("Enter number of items to orde =  ");
        scanf("%d", &orderCount);
        printf("Enter item number and quantity = \n");
        for (j = 0; j < orderCount; j++)
        {
            scanf("%d %d", &itemNo, &qty);
            if (itemNo < 1 || itemNo > 5 || qty <= 0)
            {
                printf("Invalid input! Try again.\n");
                j--;
                continue;
            }
            bill += prices[itemNo - 1] * qty;
            sold[itemNo - 1] += qty;
            totalItemsSold += qty;
        }

        printf("Total Bill for Customer %d = %.2f\n", i, bill);
        totalRevenue += bill;
    }
    int mostIndex = 0, leastIndex = 0;
    for (i = 1; i < 5; i++)
    {
        if (sold[i] > sold[mostIndex])
            mostIndex = i;
        if (sold[i] < sold[leastIndex])
            leastIndex = i;
    }
    //output
    printf("Total Revenue = %.2f\n", totalRevenue);
    printf("Total Items Sold = %d\n", totalItemsSold);
    printf("Most Ordered Item = %s\n", items[mostIndex]);
    printf("Least Ordered Item = %s\n", items[leastIndex]);
    return 0;
}
