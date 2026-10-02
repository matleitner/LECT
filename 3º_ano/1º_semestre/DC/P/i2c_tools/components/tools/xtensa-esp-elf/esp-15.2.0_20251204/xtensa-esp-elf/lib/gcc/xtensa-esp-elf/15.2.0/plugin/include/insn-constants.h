/* Generated automatically by the program `genconstants'
   from the machine description file `md'.  */

#ifndef GCC_INSN_CONSTANTS_H
#define GCC_INSN_CONSTANTS_H

#define A8_REG 8
#define A0_REG 0
#define A9_REG 9
#define A1_REG 1
#define A7_REG 7

enum unspec {
  UNSPEC_NOP = 0,
  UNSPEC_PLT = 1,
  UNSPEC_RET_ADDR = 2,
  UNSPEC_TPOFF = 3,
  UNSPEC_DTPOFF = 4,
  UNSPEC_TLS_FUNC = 5,
  UNSPEC_TLS_ARG = 6,
  UNSPEC_TLS_CALL = 7,
  UNSPEC_TP = 8,
  UNSPEC_MEMW = 9,
  UNSPEC_LSETUP_START = 10,
  UNSPEC_LSETUP_END = 11,
  UNSPEC_FRAME_BLOCKAGE = 12
};
#define NUM_UNSPEC_VALUES 13
extern const char *const unspec_strings[];

enum unspecv {
  UNSPECV_SET_FP = 0,
  UNSPECV_ENTRY = 1,
  UNSPECV_S32RI = 2,
  UNSPECV_S32C1I = 3,
  UNSPECV_EH_RETURN = 4,
  UNSPECV_SET_TP = 5,
  UNSPECV_BLOCKAGE = 6
};
#define NUM_UNSPECV_VALUES 7
extern const char *const unspecv_strings[];

#endif /* GCC_INSN_CONSTANTS_H */
