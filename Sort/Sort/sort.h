#pragma once

#define MAX_SIZE 101
#define SWAP(x, y, t)  ((t) = (x), (x) = (y), (y) = (t))

// selection sort
void selection_sort(int[], int);      