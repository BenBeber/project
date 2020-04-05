#include "Binary.h"
#include "Error.h"


unsigned int* int_to_bin_digit(unsigned int in, int count)
{
    int i;
    unsigned int* out;
    unsigned int mask;
    out = (unsigned int*) malloc(sizeof(int) * count);
    errorIfMallocFailed(out, "couldn't allocate memory for a new binary number");

    mask = 1U << (count-1);
    for (i = 0; i < count; i++) {
        out[i] = (in & mask) ? 1 : 0;
        in <<= 1;
    }
    return  out;
}


char *decimal_to_binaryString(int n, int numOfDigits)
{
    int c, d, count;
    char *pointer;

    count = 0;
    pointer = (char*)malloc(numOfDigits+1);

    errorIfMallocFailed(pointer, "couldn't allocate memory for a new binary string");

    for (c = numOfDigits - 1 ; c >= 0 ; c--)
    {
        d = n >> c;

        if (d & 1)
            *(pointer+count) = 1 + '0';
        else
            *(pointer+count) = 0 + '0';

        count++;
    }
    *(pointer+count) = '\0';

    return  pointer;
}


void replaceToBinaryStringToWierdBinaryString(char *binaryString){
    int i;
    i =0;
    while (binaryString[i] !='\0'){
        if(binaryString[i] == '0')
            binaryString[i] = '.';
        else
            binaryString[i] = '/';

        i++;
    }
}
