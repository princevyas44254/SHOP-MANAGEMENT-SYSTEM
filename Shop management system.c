#include <stdio.h>

#define NUM_PRODUCTS 5
#define NUM_BRANDS 3

const char* getGrade(float average) {
    if (average >= 100000) return "EXCELLENT SELL";
    else if (average >= 50000) return "GOOD SELL";
    else if (average >= 20000) return "AVERAGE SELL";
    else if (average >= 10000) return "FAIR SELL";
    else return "BAD SELL";
}

float getCostPrice(int productIndex) {
    float costPrices[NUM_PRODUCTS] = {150, 500, 400, 300, 400};
    return costPrices[productIndex];
}

int main() {
    float REVENUE[NUM_BRANDS][NUM_PRODUCTS];
    float UNIT_SOLD[NUM_BRANDS][NUM_PRODUCTS]; 
    float averages[NUM_BRANDS];

    const char* brandNames[] = {"Brand A", "Brand B", "Brand C"};

    
    printf("Welcome to Our Shop!\n");
    printf("Enter the required information to get the following information :-\n");
    printf("average revenue\n");
    printf("Profit per brand \n");
    printf("No of units sold \n");
    printf("Eligibility of your shop to be a Brand\n");

    for (int i = 0; i < NUM_BRANDS; i++) {
        printf("Enter REVENUE OF %s:\n", brandNames[i]);

        for (int j = 0; j < NUM_PRODUCTS; j++) {
            const char* productNames[] = {"TSHIRT REVENUE (INR)", "JACKET REVENUE (INR)", "SAREE REVENUE (INR)", "KURTI REVENUE (INR)", "SHIRT REVENUE (INR)"};
            printf("%s: ", productNames[j]);
            scanf("%f", &REVENUE[i][j]);

            printf("Units sold for %s: ", productNames[j]);
            scanf("%f", &UNIT_SOLD[i][j]); 
        }

        averages[i] = 0;
        for (int j = 0; j < NUM_PRODUCTS; j++) {
            averages[i] += REVENUE[i][j];
        }
        averages[i] /= NUM_PRODUCTS;
    }

    // Print average and grades
    printf("\nAverage and Grades:\n");
    for (int i = 0; i < NUM_BRANDS; i++) {
        const char* grade = getGrade(averages[i]);
        printf("%s: Average = %.2f, Grade = %s\n", brandNames[i], averages[i], grade);
    }

    // Calculate total average revenue
    float totalAverageRevenue = 0;
    for (int i = 0; i < NUM_BRANDS; i++) {
        totalAverageRevenue += averages[i];
    }

    // Print profit or loss
    printf("\nProfit or Loss:\n");
    for (int i = 0; i < NUM_BRANDS; i++) {
        float totalRevenue = 0;
        float totalCost = 0;

        for (int j = 0; j < NUM_PRODUCTS; j++) {
            totalRevenue += REVENUE[i][j];
            totalCost += getCostPrice(j) * UNIT_SOLD[i][j];
        }

        float profitOrLoss = totalRevenue - totalCost;

        if (profitOrLoss > 0) {
            printf("%s: Profit = %.2f (Upselling Brand)\n", brandNames[i], profitOrLoss);
        } else if (profitOrLoss < 0) {
            printf("%s: Loss = %.2f (Downselling Brand)\n", brandNames[i], -profitOrLoss);
        } else {
            printf("%s: No Profit No Loss\n", brandNames[i]);
        }
    }

    // Print units sold for each product
    printf("\nUnits Sold:\n");
    for (int i = 0; i < NUM_BRANDS; i++) {
        printf("%s:\n", brandNames[i]);
        const char* productNames[] = {"TSHIRT", "JACKET", "SAREE", "KURTI", "SHIRT"};
        for (int j = 0; j < NUM_PRODUCTS; j++) {
            printf("%s: %.2f units\n", productNames[j], UNIT_SOLD[i][j]);
        }
    }

    // Print total average revenue and eligibility check
    printf("\nTotal Average Revenue of all Brands = %.2f\n", totalAverageRevenue);
    if (totalAverageRevenue > 100000) {
        printf("Your shop is ready to compete in the market!\n");
    } else {
        printf("Your shop is not ready to compete in the market.\n");
    }

    return 0;
}