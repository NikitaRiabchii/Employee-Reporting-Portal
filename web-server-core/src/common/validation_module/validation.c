#include "validation.h"

unsigned long long check_pesel(const int *pesel) {
    // Check if pesel is NULL
    if (pesel == NULL) {
        return 0;
    }
    
    // Check each digit is in range 0-9 and calculate result
    unsigned long long result = 0;
    for (int i = 0; i < 11; i++) {
        if (pesel[i] < 0 || pesel[i] > 9) {
            return 0;
        }
        result = result * 10 + pesel[i];
    }
    
    // Validate using PESEL checksum algorithm
    // Weights: 1, 3, 7, 9, 1, 3, 7, 9, 1, 3
    const int weights[] = {1, 3, 7, 9, 1, 3, 7, 9, 1, 3};
    int sum = 0;
    
    for (int i = 0; i < 10; i++) {
        sum += pesel[i] * weights[i];
    }
    
    int checksum = (10 - (sum % 10)) % 10;
    
    // Compare with the 11th digit
    if (checksum != pesel[10]) {
        return 0;
    }
    
    // Extract date components
    int year = pesel[0] * 10 + pesel[1];
    int month = pesel[2] * 10 + pesel[3];
    int day = pesel[4] * 10 + pesel[5];
    
    // Adjust century based on month
    int century;
    if (month >= 1 && month <= 12) {
        century = 1900;
    } else if (month >= 21 && month <= 32) {
        century = 2000;
        month -= 20;
    } else if (month >= 41 && month <= 52) {
        century = 2100;
        month -= 40;
    } else if (month >= 61 && month <= 72) {
        century = 2200;
        month -= 60;
    } else if (month >= 81 && month <= 92) {
        century = 1800;
        month -= 80;
    } else {
        return 0; // Invalid month
    }
    
    int full_year = century + year;
    
    // Validate month
    if (month < 1 || month > 12) {
        return 0;
    }
    
    // Validate day
    if (day < 1) {
        return 0;
    }
    
    // Days in each month
    int max_days;
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            max_days = 31;
            break;
        case 4: case 6: case 9: case 11:
            max_days = 30;
            break;
        case 2:
            // Leap year check
            if ((full_year % 4 == 0 && full_year % 100 != 0) || (full_year % 400 == 0)) {
                max_days = 29;
            } else {
                max_days = 28;
            }
            break;
        default:
            return 0;
    }
    
    if (day > max_days) {
        return 0;
    }
    
    return result;
}

unsigned long long check_identification_number(const int *id_number) {
    //here will be implementation of check for identification number based on rules of this number, but now haven't develop it, I will return 0 for now.
    return 0;
}