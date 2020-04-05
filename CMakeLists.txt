cmake_minimum_required(VERSION 3.15)
project(14Maman C)

set(CMAKE_C_STANDARD 90)

add_executable(14Maman src/main.c src/constants.h src/phase1.c src/phase1.h src/phase2.c src/phase2.h src/modules/Analyzer.c src/modules/Analyzer.h src/modules/CodeSegement.c src/modules/CodeSegement.h src/modules/CommandBuilder.c src/modules/CommandBuilder.h src/modules/CommandsIndex.c src/modules/CommandsIndex.h src/modules/DataSegment.c src/modules/DataSegment.h src/modules/Opearnds.c src/modules/Opearnds.h src/modules/statments_types.h src/modules/SymbolsTable.c src/modules/SymbolsTable.h src/utils/Binary.c src/utils/Binary.h src/utils/Error.c src/utils/Error.h src/utils/FileReader.c src/utils/FileReader.h src/utils/FileWriter.c src/utils/FileWriter.h src/utils/List.c src/utils/List.h src/utils/TextUtils.c src/utils/TextUtils.h)