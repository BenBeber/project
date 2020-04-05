
#include "Error.h"

void errorIfMallocFailed(void* pointer, char *cause){
    if(pointer == NULL){
        ERROR_PROGRAM(("failed to allocate memory %s", cause));
        exit(1);
    }
}
