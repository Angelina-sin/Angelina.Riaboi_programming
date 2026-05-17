#include <stdio.h>

#define MAX 100

typedef struct {
    char name[50];
    double population;   
    double area;         
} Country;

void inputCountries(Country c[], int *n) {
    printf("Enter number of countries: ");
    scanf("%d", n);

    while (*n<1 || *n>MAX) {
        printf("Error! Enter number from 1 to %d: ", MAX);
        scanf("%d", n);
    }

    for (int i=0; i<*n; i++) {
        printf("Enter country name: ");
        scanf("%s", c[i].name);

        printf("Enter population (millions): ");
        scanf("%lf", &c[i].population);

        printf("Enter area (km^2): ");
        scanf("%lf", &c[i].area);
    }
}

int findMinDensity(Country c[], int n) {
    int minIndex = 0;
    double minDensity = c[0].population / c[0].area;

    for (int i=1; i<n; i++) {
        double density = c[i].population / c[i].area;

        if (density < minDensity) {
            minDensity = density;
            minIndex = i;
        }
    }

    return minIndex;
}

int main() {
    Country countries[MAX];
    int n;

    inputCountries(countries, &n);

    int index = findMinDensity(countries, n);

    printf("Country with minimum density: %s\n", countries[index].name);

    return 0;
}