#include <stdbool.h>

bool is_leap_year(unsigned short year) {
    if (!(year % 4) && ((year % 100) || !(year % 400)))
        return true;
    return false;
}

