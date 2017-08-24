/* 
 * Edward Bersin
 * tuf18309@temple.edu
 * Last modified on September 29, 2015
 */

#include <stdio.h>
#include <stdint.h>

typedef uint64_t weatherlog_t;

unsigned int add(unsigned int, unsigned int);
unsigned int sub(unsigned int, unsigned int);
unsigned int mul(unsigned int, unsigned int);

void print_half_nybbles(unsigned int);
void reverse_half_nybbles(unsigned int);

int has_odd(unsigned int);
unsigned int make_odd(unsigned int);

int is_negative(int);

weatherlog_t pack_log_entry(unsigned int, unsigned int, unsigned int,
        unsigned int, int, int, unsigned int, unsigned int);

unsigned int get_year(weatherlog_t entry);
unsigned int get_month(weatherlog_t entry);
unsigned int get_day(weatherlog_t entry);
unsigned int get_zip(weatherlog_t entry);
unsigned int get_high(weatherlog_t entry);
unsigned int get_low(weatherlog_t entry);
unsigned int get_precip(weatherlog_t entry);
unsigned int get_wind(weatherlog_t entry);

int main(int argc, char **argv) {
    unsigned int i, j;
    int x, y;
    unsigned int year, month, day,
            zip, high_temp, low_temp, precip, avg_wind_speed;
    weatherlog_t log_entry;

    printf("Enter an integer: ");
    scanf("%u", &i);
    printf("Enter another integer: ");
    scanf("%u", &j);
    printf("One more integer, please: ");
    scanf("%d", &x);
    printf("Please enter a positive integer: ");
    scanf("%d", &y);

    printf("i + j = %u\n", add(i, j));
    printf("i - j = %u\n", sub(i, j));
    printf("i * j = %u\n", mul(i, j));

    if (is_negative(x))
        printf("%d is negative\n", x);
    else
        printf("%d is non-negative\n", x);

    if (has_odd(y)) {
        printf("0x%x has an odd number of bits in its binary representation\n", y);
    } else {
        printf("0x%x has an even number of bits in its binary representation\n", y);
        printf("but 0x%x has an odd number of bits in its binary representation\n", make_odd(y));
    }

    printf("The half-nybbles of %d (in hex, 0x%x) are: ", x, x);
    print_half_nybbles(x);

    printf(":: %d with reversed half-nybbles is: ", x);
    reverse_half_nybbles(x);

    printf("\nEnter a year: ");
    scanf("%u", &year);

    printf("Enter a month as an integer (1-12): ");
    scanf("%u", &month);

    printf("Enter a day as an integer (1-31): ");
    scanf("%u", &day);

    printf("Enter a zip code as an integer (0-99999): ");
    scanf("%u", &zip);

    printf("Enter the high temperature as an integer: ");
    scanf("%u", &high_temp);

    printf("Enter the low temperature as an integer: ");
    scanf("%u", &low_temp);


    printf("Enter the rainfall amount as an integer (mm): ");
    scanf("%u", &precip);

    printf("Enter the average wind speed as an integer (km/hr): ");
    scanf("%u", &avg_wind_speed);


    log_entry = pack_log_entry(year, month, day, zip, high_temp, low_temp,
            precip, avg_wind_speed);
    printf("You entered: %u/%u/%u for ZIP %5d: High %d F, Low %d F, precipitation %d mm, average wind speed %d km/hr\n",
            get_day(log_entry), get_month(log_entry), get_year(log_entry),
            get_zip(log_entry), get_high(log_entry), get_low(log_entry),
            get_precip(log_entry), get_wind(log_entry));
    return 0;
}

unsigned int add(unsigned int i, unsigned int j) {

    unsigned int carry;

    while (j != 0) {
        carry = i & j;
        i ^= j;
        j = carry << 1;
    }

    return i;
}

unsigned int sub(unsigned int i, unsigned int j) {

    j = add(~j, 1);

    return add(i, j);
}

unsigned int mul(unsigned int i, unsigned int j) {

    unsigned int count, k = 0;

    for (count = 0; count != j; count = add(count, 1)) {
        k = add(k, i);
    }

    return k;
}

void print_half_nybbles(unsigned int x) {

    unsigned int y;
    int i = 32, j;
    unsigned int nibbles[i];

    for (j = 0; j != i; j = add(j, 1)) {
        nibbles[j] = 0;
    }

    i = 31;
    while (x != 0) {
        y = x & 3;
        x >>= 2;

        switch (y) {
            case 0:
                nibbles[i] = 0;
                i = sub(i, 1);
                nibbles[i] = 0;
                i = sub(i, 1);
                break;
            case 1:
                nibbles[i] = 1;
                i = sub(i, 1);
                nibbles[i] = 0;
                i = sub(i, 1);
                break;
            case 2:
                nibbles[i] = 0;
                i = sub(i, 1);
                nibbles[i] = 1;
                i = sub(i, 1);
                break;
            case 3:
                nibbles[i] = 1;
                i = sub(i, 1);
                nibbles[i] = 1;
                i = sub(i, 1);
                break;
        }
    }
    i = 32;
    for (j = 0; j != i; j = add(j, 2)) {
        printf("%u%u ", nibbles[j], nibbles[add(j, 1)]);
    }
}

void reverse_half_nybbles(unsigned int i) {

    unsigned int y;
    int x = 32, j;
    unsigned int nibbles[x];

    for (j = 0; j != x; j = add(j, 1)) {
        nibbles[j] = 0;
    }

    x = 0;
    while (i != 0) {
        y = i & 3;
        i >>= 2;

        switch (y) {
            case 0:
                nibbles[x] = 0;
                x = add(x, 1);
                nibbles[x] = 0;
                x = add(x, 1);
                break;
            case 1:
                nibbles[x] = 1;
                x = add(x, 1);
                nibbles[x] = 0;
                x = add(x, 1);
                break;
            case 2:
                nibbles[x] = 0;
                x = add(x, 1);
                nibbles[x] = 1;
                x = add(x, 1);
                break;
            case 3:
                nibbles[x] = 1;
                x = add(x, 1);
                nibbles[x] = 1;
                x = add(x, 1);
                break;
        }
    }
    x = 32;
    for (j = 0; j != x; j = add(j, 2)) {
        printf("%u%u ", nibbles[j], nibbles[add(j, 1)]);
    }
}

int is_negative(int x) {

    int y;

    x >>= 30;
    y = x & 1;

    return y;
}

int has_odd(unsigned int x) {

    unsigned int y;
    int oddB = 1, evenB = 0, count = evenB;

    while (x != 0) {
        y = x & 1;
        x >>= 1;

        if ((y == 1) && (count == oddB)) {
            count = evenB;
        } else if ((y == 1) && (count == evenB)) {
            count = oddB;
        }
    }

    return count;
}

unsigned int make_odd(unsigned int x) {

    unsigned int y;

    if (has_odd(x) != 1) {
        y = x | 2147483648;
        return y;
    } else {
        return x;
    }
}

weatherlog_t pack_log_entry(unsigned int year, unsigned int month, unsigned int day,
        unsigned int zip, int high_temp, int low_temp, unsigned int precip,
        unsigned int avg_wind_speed) {

    weatherlog_t entry;

    entry = sub(year, 2000);
    entry <<= 4;
    entry |= month;
    entry <<= 5;
    entry |= day;
    entry <<= 16;
    entry |= zip;
    entry <<= 8;
    entry |= (unsigned int) high_temp;
    entry <<= 8;
    entry |= (unsigned int) low_temp;
    entry <<= 10;
    entry |= precip;
    entry <<= 7;
    entry |= avg_wind_speed;

    return entry;
}

unsigned int get_year(weatherlog_t entry) {
    entry >>= 58;
    return entry;
}

unsigned int get_month(weatherlog_t entry) {
    entry <<= 6;
    entry >>= 60;
    return entry;
}

unsigned int get_day(weatherlog_t entry) {
    entry <<= 10;
    entry >>= 59;
    return entry;
}

unsigned int get_zip(weatherlog_t entry) {
    entry <<= 15;
    entry >>= 48;
    return entry;
}

unsigned int get_high(weatherlog_t entry) {
    entry <<= 31;
    entry >>= 56;
    return (int) entry;
}

unsigned int get_low(weatherlog_t entry) {
    entry <<= 39;
    entry >>= 56;
    return (int) entry;
}

unsigned int get_precip(weatherlog_t entry) {
    entry <<= 47;
    entry >>= 54;
    return entry;
}

unsigned int get_wind(weatherlog_t entry) {
    entry <<= 57;
    entry >>= 57;
    return entry;
}