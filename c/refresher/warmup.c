
#include <stdio.h>

int main()
{
    int x = 10;
    int *px = &x;

    printf("value at x = %d \n", *(&x));
    printf("value at address %d", *px);

    // * = is for derefrencing a pointer = fetch the valude from an address block
    // & = is to product and give out an address as output

    // * = dereferencing operator = given a pointer, fetch the value stored at the address it holds.

    /*       & = address-of operator = given a variable, produces
            its memory address (which you can then store in a pointer, or pass to a function)
     */
}