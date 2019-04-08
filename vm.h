#ifndef LASM_VM
#define LASM_VM

typedef struct lasm_vm lasmvm_t;

typedef enum reg_names {
    R_PC = 0,
    R_MAR = 1,
    R_MDR = 2,
    R0 = 3,
    R1 = 4,
    R2 = 5,
    R3 = 6,
    R4 = 7,
    R_END = 8
} reg_names;

struct lasm_vm *lasm_init(int ram_size);

void lasm_destroy(lasmvm_t *ctx);

void lasm_lw(lasmvm_t *ctx, char a, char b, char c);

void lasm_sw(lasmvm_t *ctx, char a, char b, char c);

void lasm_addr(lasmvm_t *ctx, char ra, char rb, char rres);

void lasm_addi(lasmvm_t *ctx, char ra, char nb, char rres);

void lasm_subr(lasmvm_t *ctx, char ra, char rb, char rres);

void lasm_subi(lasmvm_t *ctx, char ra, char nb, char rres);

void lasm_print_state(lasmvm_t *ctx);

extern void* ISA[];

#endif
