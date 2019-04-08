#ifndef LASM_RUN
#define LASM_RUN

void lasm_runstr(lasmvm_t *ctx, char *code, int size);

void lasm_runinstruction(lasmvm_t *ctx, char *inst);

#endif
