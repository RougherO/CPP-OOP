void strcpy(char const* const src, char* const dest)
{
    char* ptr2 = dest;
    for (int i = 0; src[i]; ++i, ++ptr2) {
        *ptr2 = src[i];
    }
    *ptr2 = 0;
}

int main()
{
    char const src[200] { "Source String!" };
    char dest[200];
    strcpy(src, dest);
}