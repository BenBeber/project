#ifndef ASSEMBLER_PHASE1_H
#define ASSEMBLER_PHASE1_H

#include "./utils/FileReader.h"
#include "./utils/TextUtils.h"
#include "./modules/Analyzer.h"
#include "./modules/DataSegment.h"
#include "./modules/CodeSegement.h"
void doPhase1(char* fileName);

/**
 * this method updates the symbols table addresses, after we know the exact length of the code segment, we can update each symbol its real address
*/
void updateSymbolTableAddresses();
#endif
