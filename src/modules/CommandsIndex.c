#include "CommandsIndex.h"


static CommandDescriptor commands[16];


void initCommandsDescriptors(){
    commands[mov]
            .numberOfOperands = 2;
    commands[mov]
            .allowedDestOperands[0] = REGISTER_OPERAND;
    commands[mov]
            .allowedDestOperands[1] = LABEL_OPERAND;
    commands[mov]
            .allowedDestOperands[2] = NO_OTHER_OPERAND;
    commands[mov]
            .allowedSrcOperands[0] = REGISTER_OPERAND;
    commands[mov]
            .allowedSrcOperands[1] = DIRECT_VALUE_OPERAND;
    commands[mov]
            .allowedSrcOperands[2] = LABEL_OPERAND;
    commands[cmp]
            .numberOfOperands = 2;
    commands[cmp]
            .allowedDestOperands[0] = REGISTER_OPERAND;
    commands[cmp]
            .allowedDestOperands[1] = LABEL_OPERAND;
    commands[cmp]
            .allowedDestOperands[2] = DIRECT_VALUE_OPERAND;
    commands[cmp]
            .allowedSrcOperands[0] = REGISTER_OPERAND;
    commands[cmp]
            .allowedSrcOperands[1] = DIRECT_VALUE_OPERAND;
    commands[cmp]
            .allowedSrcOperands[2] = LABEL_OPERAND;
    commands[add]
            .numberOfOperands = 2;
    commands[add]
            .allowedDestOperands[0] = REGISTER_OPERAND;
    commands[add]
            .allowedDestOperands[1] = LABEL_OPERAND;
    commands[add]
            .allowedDestOperands[2] = NO_OTHER_OPERAND;
    commands[add]
            .allowedSrcOperands[0] = REGISTER_OPERAND;
    commands[add]
            .allowedSrcOperands[1] = DIRECT_VALUE_OPERAND;
    commands[add]
            .allowedSrcOperands[2] = LABEL_OPERAND;
    commands[sub]
            .numberOfOperands = 2;
    commands[sub]
            .allowedDestOperands[0] = REGISTER_OPERAND;
    commands[sub]
            .allowedDestOperands[1] = LABEL_OPERAND;
    commands[sub]
            .allowedDestOperands[2] = NO_OTHER_OPERAND;
    commands[sub]
            .allowedSrcOperands[0] = REGISTER_OPERAND;
    commands[sub]
            .allowedSrcOperands[1] = DIRECT_VALUE_OPERAND;
    commands[sub]
            .allowedSrcOperands[2] = LABEL_OPERAND;
    commands[lea]
            .numberOfOperands = 2;
    commands[lea]
            .allowedDestOperands[0] = REGISTER_OPERAND;
    commands[lea]
            .allowedDestOperands[1] = LABEL_OPERAND;
    commands[lea]
            .allowedDestOperands[2] = NO_OTHER_OPERAND;
    commands[lea]
            .allowedSrcOperands[0] = NO_OTHER_OPERAND;
    commands[lea]
            .allowedSrcOperands[1] = NO_OTHER_OPERAND;
    commands[lea]
            .allowedSrcOperands[2] = LABEL_OPERAND;
    commands[notCMD]
            .numberOfOperands = 1;
    commands[notCMD]
            .allowedDestOperands[0] = REGISTER_OPERAND;
    commands[notCMD]
            .allowedDestOperands[1] = LABEL_OPERAND;
    commands[notCMD]
            .allowedDestOperands[2] = NO_OTHER_OPERAND;
    commands[clr]
            .numberOfOperands = 1;
    commands[clr]
            .allowedDestOperands[0] = REGISTER_OPERAND;
    commands[clr]
            .allowedDestOperands[1] = LABEL_OPERAND;
    commands[clr]
            .allowedDestOperands[2] = NO_OTHER_OPERAND;
    commands[inc]
            .numberOfOperands = 1;
    commands[inc]
            .allowedDestOperands[0] = REGISTER_OPERAND;
    commands[inc]
            .allowedDestOperands[1] = LABEL_OPERAND;
    commands[inc]
            .allowedDestOperands[2] = NO_OTHER_OPERAND;
    commands[dec]
            .numberOfOperands = 1;
    commands[dec]
            .allowedDestOperands[0] = REGISTER_OPERAND;
    commands[dec]
            .allowedDestOperands[1] = LABEL_OPERAND;
    commands[dec]
            .allowedDestOperands[2] = NO_OTHER_OPERAND;
    commands[jmp]
            .numberOfOperands = 1;
    commands[jmp]
            .allowedDestOperands[0] = REGISTER_OPERAND;
    commands[jmp]
            .allowedDestOperands[1] = LABEL_OPERAND;
    commands[jmp]
            .allowedDestOperands[2] = JUMP_OPERAND;
    commands[bne]
            .numberOfOperands = 1;
    commands[bne]
            .allowedDestOperands[0] = REGISTER_OPERAND;
    commands[bne]
            .allowedDestOperands[1] = LABEL_OPERAND;
    commands[bne]
            .allowedDestOperands[2] = JUMP_OPERAND;
    commands[red]
            .numberOfOperands = 1;
    commands[red]
            .allowedDestOperands[0] = REGISTER_OPERAND;
    commands[red]
            .allowedDestOperands[1] = LABEL_OPERAND;
    commands[red]
            .allowedDestOperands[2] = NO_OTHER_OPERAND;
    commands[prn]
            .numberOfOperands = 1;
    commands[prn]
            .allowedDestOperands[0] = REGISTER_OPERAND;
    commands[prn]
            .allowedDestOperands[1] = LABEL_OPERAND;
    commands[prn]
            .allowedDestOperands[2] = DIRECT_VALUE_OPERAND;
    commands[jsr]
            .numberOfOperands = 1;
    commands[jsr]
            .allowedDestOperands[0] = REGISTER_OPERAND;
    commands[jsr]
            .allowedDestOperands[1] = LABEL_OPERAND;
    commands[jsr]
            .allowedDestOperands[2] = JUMP_OPERAND;
    commands[rts]
            .numberOfOperands = 0;
    commands[stop]
            .numberOfOperands = 0;
}


COMMANDS commandStringToEnum(char *commandString){
    if(strcmp(commandString, "mov") == 0)
        return mov;
    if(strcmp(commandString, "cmp") == 0)
        return  cmp;
    if(strcmp(commandString, "add") == 0)
        return  add;
    if(strcmp(commandString, "sub") == 0)
        return  sub;
    if(strcmp(commandString, "not") == 0)
        return  notCMD;
    if(strcmp(commandString, "clr") == 0)
        return  clr;
    if(strcmp(commandString, "lea") == 0)
        return  lea;
    if(strcmp(commandString, "inc") == 0)
        return  inc;
    if(strcmp(commandString, "dec") == 0)
        return  dec;
    if(strcmp(commandString, "jmp") == 0)
        return  jmp;
    if(strcmp(commandString, "bne") == 0)
        return  bne;
    if(strcmp(commandString, "red") == 0)
        return  red;
    if(strcmp(commandString, "prn") == 0)
        return  prn;
    if(strcmp(commandString, "jsr") == 0)
        return  jsr;
    if(strcmp(commandString, "rts") == 0)
        return  rts;
    if(strcmp(commandString, "stop") == 0)
        return  stop;

    return  UNKNOWN_COMMAND;
}


CommandDescriptor* getCommandDescriptor(COMMANDS command){
    if(command == UNKNOWN_COMMAND){
        return  NULL;
    }
    return  &commands[command];
}
