#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "vm.h"

#define QT_REG (R_END - R_PC)

typedef struct lasm_vm {
    char reg[R_END - R_PC];
    char *ram;
    char ram_size;
} lasmvm_t;

lasmvm_t *lasm_init(int ram_size) {
    lasmvm_t *ctx = malloc(sizeof(lasmvm_t));
    assert(ram_size < 256); // Avoid overflow
    ctx->ram_size = ram_size;
    ctx->ram = malloc(sizeof(char)*ram_size);
    int i;
    for (i = 0; i < ram_size; i++) {
        if (i < QT_REG)
            ctx->reg[i] = 0;
        ctx->ram[i] = 0;
    }
    return ctx;
}

void lasm_destroy(lasmvm_t *ctx) {
    free(ctx->ram);
    free(ctx);
}

void lasm_print_state(lasmvm_t *ctx) {
    printf("PC: 0x%x ", ctx->reg[R_PC]);
    printf("MAR: 0x%x ", ctx->reg[R_MAR]);
    printf("MDR: 0x%x ", ctx->reg[R_MDR]);
    printf("REGS: ");
    int i;
    for (i = R0; i < R_END; i++) {
        printf(" 0x%x ", ctx->reg[i]);
    }
    printf("\nRAM #%i: [ ", ctx->ram_size);
    for (i = 0; i < ctx->ram_size; i++) {
        printf(" 0x%x ", ctx->ram[i]);
    }
    printf("]\n");
}

void lasm_lw(lasmvm_t *ctx, char a, char b, char c) {
    printf("LW!\n");
    ctx->reg[R_MDR] = ctx->ram[ctx->reg[R_MAR]];
}

void lasm_sw(lasmvm_t *ctx, char a, char b, char c) {
    printf("SW!\n");
    ctx->ram[ctx->reg[R_MAR]] = ctx->reg[R_MDR];
}

void lasm_addr(lasmvm_t *ctx, char ra, char rb, char rres) {
    printf("ADD $%x $%x $%x\n", ra, rb, rres);
    ctx->reg[rres] = ctx->reg[ra] + ctx->reg[rb];
}

void lasm_addi(lasmvm_t *ctx, char ra, char nb, char rres) {
    printf("ADD $%x %x $%x\n", ra, nb, rres);
    ctx->reg[rres] = ctx->reg[ra] + nb;
}

void lasm_subr(lasmvm_t *ctx, char ra, char rb, char rres) {
    printf("SUB $%x $%x $%x\n", ra, rb, rres);
    ctx->reg[rres] = ctx->reg[ra] - ctx->reg[rb];
}

void lasm_subi(lasmvm_t *ctx, char ra, char nb, char rres) {
    printf("SUB $%x %x $%x\n", ra, nb, rres);
    ctx->reg[rres] = ctx->reg[ra] - nb;
}

void* ISA[] = {
    &lasm_lw,
    &lasm_sw,
    &lasm_addr,
    &lasm_addi,
    &lasm_subr,
    &lasm_subi,
};

