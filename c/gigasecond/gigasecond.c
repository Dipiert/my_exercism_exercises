#include "gigasecond.h"
#include <time.h>

time_t gigasecond_after(time_t date) {
	return date + 1e9;
}

