int maximum(int x, int y, int z)
{
    return x > y ? (x > z ? x : z) : (y > z ? y : z);
}

int maximum(int* arr, unsigned size)
{
    int max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}