#include "vm.h"

void lasm_runinstruction(lasmvm_t *ctx, char *inst) { // exatamente 4 chars, ou 4 bytes
    char opcode = inst[0];
    char param1 = inst[1];
    char param2 = inst[2];
    char param3 = inst[3];
    void (*fn) (lasmvm_t*, char, char, char) = ISA[opcode];
    fn(ctx, param1, param2, param3);
}

void lasm_runstr(lasmvm_t *ctx, char *code, int size) {
    for (; size >= 4; size -= 4) {
        lasm_runinstruction(ctx, code);
        code += 4;
    }
}


