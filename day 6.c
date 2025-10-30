#include <stdio.h>

int main() {
    float data, baseCost, extraData = 0, extraCost = 0, total, finalBill;
    int student, corporate;
    float discount = 0;

    printf("Enter total data used (GB): ");
    scanf("%f", &data);

    printf("Are you a student? (1-Yes / 0-No): ");
    scanf("%d", &student);

    printf("Corporate user? (1-Yes / 0-No): ");
    scanf("%d", &corporate);

    if (data > 100) {
        printf("Excessive Usage - Plan Not Allowed\n");
    }
    else if (data < 30) {
        // Silver Plan
        baseCost = 299;
        extraData = 0;
        total = baseCost;
        printf("\nSelected Plan: Silver\n");
    }
    else if (data >= 30 && data <= 60) {
        // Gold Plan
        baseCost = 499;
        if (data > 60)
            extraData = data - 60;
        total = baseCost + (extraData * 40);
        printf("\nSelected Plan: Gold\n");
    }
    else { // data > 60 and <= 100
        // Platinum Plan
        baseCost = 799;
        if (data > 60)
            extraData = data - 60;
        total = baseCost + (extraData * 30);
        printf("\nSelected Plan: Platinum\n");
    }

    // Choose higher discount
    if (student == 1 && corporate == 1)
        discount = 15;
    else if (student == 1)
        discount = 15;
    else if (corporate == 1)
        discount = 10;
    else
        discount = 0;

    finalBill = total - (total * discount / 100);

    // Bill Summary
    printf("\nUser Plan Summary:\n");
    printf("Data Used: %.2f GB\n", data);
    printf("Base Cost: ₹%.2f\n", baseCost);
    printf("Extra Data: %.2f GB\n", extraData);
    printf("Total (before discount): ₹%.2f\n", total);
    printf("Discount Applied: %.0f%%\n", discount);
    printf("Final Bill: ₹%.2f\n", finalBill);

    return 0;
}
