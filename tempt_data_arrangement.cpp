#include <iostream>
#include <limits.h>  // For INT_MIN and INT_MAX
using namespace std;

const int MONTHS = 12;  // Number of months in a year

// Function to read and store the temperatures
void getData(int highTemps[MONTHS], int lowTemps[MONTHS]) {
    cout << "Enter the highest temperatures for all 12 months: ";
    for (int i = 0; i < MONTHS; i++) {
        cin >> highTemps[i];  // Store high temperature for each month
    }

    cout << "Enter the lowest temperatures for all 12 months: ";
    for (int i = 0; i < MONTHS; i++) {
        cin >> lowTemps[i];  // Store low temperature for each month
    }
}

// Function to calculate and return the average high temperature for the year
double averageHigh(int highTemps[MONTHS]) {
    double totalHigh = 0;
    for (int i = 0; i < MONTHS; i++) {
        totalHigh += highTemps[i];  // Sum up the high temperatures
    }
    return totalHigh / MONTHS;  // Return the average high temperature
}

// Function to calculate and return the average low temperature for the year
double averageLow(int lowTemps[MONTHS]) {
    double totalLow = 0;
    for (int i = 0; i < MONTHS; i++) {
        totalLow += lowTemps[i];  // Sum up the low temperatures
    }
    return totalLow / MONTHS;  // Return the average low temperature
}

// Function to find the highest high temperature for the year
int highestHighTemp(int highTemps[MONTHS]) {
    int highestHigh = highTemps[0];  // Start with the first month's high temperature
    for (int i = 1; i < MONTHS; i++) {
        if (highTemps[i] > highestHigh) {
            highestHigh = highTemps[i];  // Update if a higher high is found
        }
    }
    return highestHigh;  // Return the highest high temperature
}

// Function to find the lowest low temperature for the year
int lowestLowTemp(int lowTemps[MONTHS]) {
    int lowestLow = lowTemps[0];  // Start with the first month's low temperature
    for (int i = 1; i < MONTHS; i++) {
        if (lowTemps[i] < lowestLow) {
            lowestLow = lowTemps[i];  // Update if a lower low is found
        }
    }
    return lowestLow;  // Return the lowest low temperature
}

// Main function
int main() {
    int highTemps[MONTHS];  // Array to store the high temperatures for each month
    int lowTemps[MONTHS];   // Array to store the low temperatures for each month

    // Get the temperature data from the user
    getData(highTemps, lowTemps);

    // Calculate the averages
    double avgHigh = averageHigh(highTemps);
    double avgLow = averageLow(lowTemps);

    // Find the highest high and lowest low temperatures
    int highestHigh = highestHighTemp(highTemps);
    int lowestLow = lowestLowTemp(lowTemps);

    // Output the results
    cout << "\nAverage High Temperature: " << avgHigh << endl;
    cout << "Average Low Temperature: " << avgLow << endl;
    cout << "Highest temperature: " << highestHigh << endl;
    cout << "Lowest temperature: " << lowestLow << endl;

    return 0;
}
