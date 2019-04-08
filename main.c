#include <stdio.h>
#include <stdlib.h>
#include "vm.h"
#include "asmvm.h"


int main() {
    lasmvm_t *ctx = lasm_init(10);
    lasm_runstr(ctx, "\x03\x03\x04\x07", 4);
    lasm_print_state(ctx);
    lasm_destroy(ctx);
}
