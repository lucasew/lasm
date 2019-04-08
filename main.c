#include <stdio.h>
#include <stdlib.h>
#include "vm.h"
#include "asmvm.h"


int main() {
    lasmvm_t *ctx = lasm_init(10); // Inicializa uma VM com 10 bytes de capacidade na RAM
    lasm_runstr(ctx, "\x03\x03\x04\x07", 4); // Soma 4 com 0 e manda pro r4
    lasm_runstr(ctx, "\x02\x03\x07\x01", 4); // Soma o r0 com o r4 e manda para o MAR
    lasm_runstr(ctx, "\x02\x01\x07\x02", 4); // Soma o MAR com o r4 e manda para o MDR
    lasm_runstr(ctx, "\x01\x00\x00\x00", 4); // Grava o dado MDR no endereço MAR da RAM
    lasm_print_state(ctx);
    lasm_destroy(ctx);
}
