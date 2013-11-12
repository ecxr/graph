#include <cstdlib>
#include "util.h"

// Returns a random integer between 0 and 1.
double prob()
{
    return (static_cast<double>(rand()) / RAND_MAX);
}
