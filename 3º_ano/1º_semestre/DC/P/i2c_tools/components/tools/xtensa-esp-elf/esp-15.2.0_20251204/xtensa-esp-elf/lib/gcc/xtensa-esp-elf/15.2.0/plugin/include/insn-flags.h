/* Generated automatically by the program `genflags'
   from the machine description file `md'.  */

#ifndef GCC_INSN_FLAGS_H
#define GCC_INSN_FLAGS_H

#define HAVE_addsi3 1
#define HAVE_addsf3 (TARGET_HARD_FLOAT)
#define HAVE_subsi3 1
#define HAVE_subsf3 (TARGET_HARD_FLOAT)
#define HAVE_mulsi3_highpart (TARGET_MUL32_HIGH)
#define HAVE_umulsi3_highpart (TARGET_MUL32_HIGH)
#define HAVE_mulsi3 (TARGET_MUL32)
#define HAVE_mulhisi3 (TARGET_MUL16 || TARGET_MAC16)
#define HAVE_umulhisi3 (TARGET_MUL16 || TARGET_MAC16)
#define HAVE_muladdhisi (TARGET_MAC16)
#define HAVE_mulsubhisi (TARGET_MAC16)
#define HAVE_mulsf3 (TARGET_HARD_FLOAT)
#define HAVE_fmasf4 (TARGET_HARD_FLOAT)
#define HAVE_fnmasf4 (TARGET_HARD_FLOAT)
#define HAVE_divsi3 (TARGET_DIV32)
#define HAVE_udivsi3 (TARGET_DIV32)
#define HAVE_modsi3 (TARGET_DIV32)
#define HAVE_umodsi3 (TARGET_DIV32)
#define HAVE_abssi2 (TARGET_ABS)
#define HAVE_abssf2 (TARGET_HARD_FLOAT)
#define HAVE_sminsi3 (TARGET_MINMAX)
#define HAVE_uminsi3 (TARGET_MINMAX)
#define HAVE_smaxsi3 (TARGET_MINMAX)
#define HAVE_umaxsi3 (TARGET_MINMAX)
#define HAVE_clrsbsi2 (TARGET_NSA)
#define HAVE_clzsi2 (TARGET_NSA)
#define HAVE_bswaphi2 1
#define HAVE_bswapsi2_internal (!optimize_debug && optimize > 1 && !optimize_size)
#define HAVE_negsi2 1
#define HAVE_one_cmplsi2 1
#define HAVE_negsf2 (TARGET_HARD_FLOAT)
#define HAVE_andsi3 1
#define HAVE_iorsi3 1
#define HAVE_xorsi3_internal 1
#define HAVE_zero_extendhisi2 1
#define HAVE_zero_extendqisi2 1
#define HAVE_extendhisi2_internal 1
#define HAVE_extendqisi2_internal (TARGET_SEXT)
#define HAVE_extvsi_internal (TARGET_SEXT)
#define HAVE_extzvsi_internal 1
#define HAVE_fix_truncsfsi2 (TARGET_HARD_FLOAT)
#define HAVE_fixuns_truncsfsi2 (TARGET_HARD_FLOAT)
#define HAVE_floatsisf2 (TARGET_HARD_FLOAT)
#define HAVE_floatunssisf2 (TARGET_HARD_FLOAT)
#define HAVE_movdi_internal (register_operand (operands[0], DImode) \
   || register_operand (operands[1], DImode))
#define HAVE_movsi_internal (xtensa_valid_move (SImode, operands))
#define HAVE_movhi_internal (xtensa_valid_move (HImode, operands))
#define HAVE_movqi_internal (xtensa_valid_move (QImode, operands))
#define HAVE_movsf_internal (((register_operand (operands[0], SFmode) \
     || register_operand (operands[1], SFmode)) \
    && !(FP_REG_P (xt_true_regnum (operands[0])) \
	 && (constantpool_mem_p (operands[1]) || CONSTANT_P (operands[1])))))
#define HAVE_movdf_internal (register_operand (operands[0], DFmode) \
   || register_operand (operands[1], DFmode))
#define HAVE_ashlsi3_internal 1
#define HAVE_ashrsi3 1
#define HAVE_lshrsi3 1
#define HAVE_rotlsi3 1
#define HAVE_rotrsi3 1
#define HAVE_zero_cost_loop_start (TARGET_LOOPS && optimize)
#define HAVE_zero_cost_loop_end (TARGET_LOOPS && optimize)
#define HAVE_loop_end (TARGET_LOOPS && optimize)
#define HAVE_salt (TARGET_SALT)
#define HAVE_saltu (TARGET_SALT)
#define HAVE_movsicc_internal0 1
#define HAVE_movsicc_internal1 (TARGET_BOOLEANS)
#define HAVE_movsfcc_internal0 1
#define HAVE_movsfcc_internal1 (TARGET_BOOLEANS)
#define HAVE_seq_sf (TARGET_HARD_FLOAT)
#define HAVE_slt_sf (TARGET_HARD_FLOAT)
#define HAVE_sle_sf (TARGET_HARD_FLOAT)
#define HAVE_suneq_sf (TARGET_HARD_FLOAT)
#define HAVE_sunlt_sf (TARGET_HARD_FLOAT)
#define HAVE_sunle_sf (TARGET_HARD_FLOAT)
#define HAVE_sunordered_sf (TARGET_HARD_FLOAT)
#define HAVE_jump 1
#define HAVE_indirect_jump_internal 1
#define HAVE_tablejump_internal 1
#define HAVE_call_internal (!SIBLING_CALL_P (insn))
#define HAVE_call_value_internal (!SIBLING_CALL_P (insn))
#define HAVE_sibcall_internal (!TARGET_WINDOWED_ABI && SIBLING_CALL_P (insn))
#define HAVE_sibcall_value_internal (!TARGET_WINDOWED_ABI && SIBLING_CALL_P (insn))
#define HAVE_entry 1
#define HAVE_return (reload_completed \
   && (TARGET_WINDOWED_ABI \
       || compute_frame_size (get_frame_size ()) == 0 \
       || epilogue_completed))
#define HAVE_nop 1
#define HAVE_eh_set_a0_windowed 1
#define HAVE_eh_set_a0_call0 1
#define HAVE_blockage 1
#define HAVE_trap 1
#define HAVE_set_frame_ptr 1
#define HAVE_get_thread_pointersi (TARGET_THREADPTR)
#define HAVE_set_thread_pointersi (TARGET_THREADPTR)
#define HAVE_tls_func (TARGET_THREADPTR && HAVE_AS_TLS)
#define HAVE_tls_arg (TARGET_THREADPTR && HAVE_AS_TLS)
#define HAVE_tls_call (TARGET_THREADPTR && HAVE_AS_TLS)
#define HAVE_sync_lock_releasesi (TARGET_RELEASE_SYNC)
#define HAVE_sync_compare_and_swapsi (TARGET_S32C1I && !TARGET_DISABLE_HARDWARE_ATOMICS)
#define HAVE_eq_zero_NSA (TARGET_NSA)
#define HAVE_eqne_zero 1
#define HAVE_adddi3 1
#define HAVE_subdi3 1
#define HAVE_mulsidi3 (TARGET_MUL32_HIGH)
#define HAVE_umulsidi3 1
#define HAVE_ctzsi2 (TARGET_NSA)
#define HAVE_ffssi2 (TARGET_NSA)
#define HAVE_bswapsi2 (!optimize_debug && optimize > 1)
#define HAVE_bswapdi2 (!optimize_debug && optimize > 1 && optimize_size)
#define HAVE_xorsi3 1
#define HAVE_extendhisi2 1
#define HAVE_extendqisi2 1
#define HAVE_extvsi (TARGET_SEXT)
#define HAVE_extzvsi 1
#define HAVE_movdi 1
#define HAVE_movsi 1
#define HAVE_movhi 1
#define HAVE_movqi 1
#define HAVE_reloadhi_literal 1
#define HAVE_reloadqi_literal 1
#define HAVE_movsf 1
#define HAVE_movdf 1
#define HAVE_cpymemsi 1
#define HAVE_setmemsi (!optimize_debug && optimize)
#define HAVE_ashlsi3 1
#define HAVE_cbranchsi4 1
#define HAVE_cbranchsf4 (TARGET_HARD_FLOAT)
#define HAVE_doloop_end (TARGET_LOOPS && optimize)
#define HAVE_cstoresi4 1
#define HAVE_cstoresf4 (TARGET_HARD_FLOAT)
#define HAVE_movsicc 1
#define HAVE_movsfcc 1
#define HAVE_indirect_jump 1
#define HAVE_tablejump 1
#define HAVE_sym_PLT 1
#define HAVE_call 1
#define HAVE_call_value 1
#define HAVE_sibcall (!TARGET_WINDOWED_ABI)
#define HAVE_sibcall_value (!TARGET_WINDOWED_ABI)
#define HAVE_untyped_call 1
#define HAVE_allocate_stack (TARGET_WINDOWED_ABI)
#define HAVE_prologue 1
#define HAVE_epilogue 1
#define HAVE_sibcall_epilogue (!TARGET_WINDOWED_ABI)
#define HAVE_nonlocal_goto (TARGET_WINDOWED_ABI)
#define HAVE_eh_return 1
#define HAVE_frame_blockage 1
#define HAVE_sym_TPOFF 1
#define HAVE_sym_DTPOFF 1
#define HAVE_memory_barrier 1
#define HAVE_sync_compare_and_swaphi (TARGET_S32C1I && !TARGET_DISABLE_HARDWARE_ATOMICS)
#define HAVE_sync_compare_and_swapqi (TARGET_S32C1I && !TARGET_DISABLE_HARDWARE_ATOMICS)
#define HAVE_sync_lock_test_and_sethi (TARGET_S32C1I && !TARGET_DISABLE_HARDWARE_ATOMICS)
#define HAVE_sync_lock_test_and_setqi (TARGET_S32C1I && !TARGET_DISABLE_HARDWARE_ATOMICS)
#define HAVE_sync_andhi (TARGET_S32C1I && !TARGET_DISABLE_HARDWARE_ATOMICS)
#define HAVE_sync_iorhi (TARGET_S32C1I && !TARGET_DISABLE_HARDWARE_ATOMICS)
#define HAVE_sync_xorhi (TARGET_S32C1I && !TARGET_DISABLE_HARDWARE_ATOMICS)
#define HAVE_sync_addhi (TARGET_S32C1I && !TARGET_DISABLE_HARDWARE_ATOMICS)
#define HAVE_sync_subhi (TARGET_S32C1I && !TARGET_DISABLE_HARDWARE_ATOMICS)
#define HAVE_sync_nandhi (TARGET_S32C1I && !TARGET_DISABLE_HARDWARE_ATOMICS)
#define HAVE_sync_andqi (TARGET_S32C1I && !TARGET_DISABLE_HARDWARE_ATOMICS)
#define HAVE_sync_iorqi (TARGET_S32C1I && !TARGET_DISABLE_HARDWARE_ATOMICS)
#define HAVE_sync_xorqi (TARGET_S32C1I && !TARGET_DISABLE_HARDWARE_ATOMICS)
#define HAVE_sync_addqi (TARGET_S32C1I && !TARGET_DISABLE_HARDWARE_ATOMICS)
#define HAVE_sync_subqi (TARGET_S32C1I && !TARGET_DISABLE_HARDWARE_ATOMICS)
#define HAVE_sync_nandqi (TARGET_S32C1I && !TARGET_DISABLE_HARDWARE_ATOMICS)
#define HAVE_sync_old_andhi (TARGET_S32C1I && !TARGET_DISABLE_HARDWARE_ATOMICS)
#define HAVE_sync_old_iorhi (TARGET_S32C1I && !TARGET_DISABLE_HARDWARE_ATOMICS)
#define HAVE_sync_old_xorhi (TARGET_S32C1I && !TARGET_DISABLE_HARDWARE_ATOMICS)
#define HAVE_sync_old_addhi (TARGET_S32C1I && !TARGET_DISABLE_HARDWARE_ATOMICS)
#define HAVE_sync_old_subhi (TARGET_S32C1I && !TARGET_DISABLE_HARDWARE_ATOMICS)
#define HAVE_sync_old_nandhi (TARGET_S32C1I && !TARGET_DISABLE_HARDWARE_ATOMICS)
#define HAVE_sync_old_andqi (TARGET_S32C1I && !TARGET_DISABLE_HARDWARE_ATOMICS)
#define HAVE_sync_old_iorqi (TARGET_S32C1I && !TARGET_DISABLE_HARDWARE_ATOMICS)
#define HAVE_sync_old_xorqi (TARGET_S32C1I && !TARGET_DISABLE_HARDWARE_ATOMICS)
#define HAVE_sync_old_addqi (TARGET_S32C1I && !TARGET_DISABLE_HARDWARE_ATOMICS)
#define HAVE_sync_old_subqi (TARGET_S32C1I && !TARGET_DISABLE_HARDWARE_ATOMICS)
#define HAVE_sync_old_nandqi (TARGET_S32C1I && !TARGET_DISABLE_HARDWARE_ATOMICS)
#define HAVE_sync_new_andhi (TARGET_S32C1I && !TARGET_DISABLE_HARDWARE_ATOMICS)
#define HAVE_sync_new_iorhi (TARGET_S32C1I && !TARGET_DISABLE_HARDWARE_ATOMICS)
#define HAVE_sync_new_xorhi (TARGET_S32C1I && !TARGET_DISABLE_HARDWARE_ATOMICS)
#define HAVE_sync_new_addhi (TARGET_S32C1I && !TARGET_DISABLE_HARDWARE_ATOMICS)
#define HAVE_sync_new_subhi (TARGET_S32C1I && !TARGET_DISABLE_HARDWARE_ATOMICS)
#define HAVE_sync_new_nandhi (TARGET_S32C1I && !TARGET_DISABLE_HARDWARE_ATOMICS)
#define HAVE_sync_new_andqi (TARGET_S32C1I && !TARGET_DISABLE_HARDWARE_ATOMICS)
#define HAVE_sync_new_iorqi (TARGET_S32C1I && !TARGET_DISABLE_HARDWARE_ATOMICS)
#define HAVE_sync_new_xorqi (TARGET_S32C1I && !TARGET_DISABLE_HARDWARE_ATOMICS)
#define HAVE_sync_new_addqi (TARGET_S32C1I && !TARGET_DISABLE_HARDWARE_ATOMICS)
#define HAVE_sync_new_subqi (TARGET_S32C1I && !TARGET_DISABLE_HARDWARE_ATOMICS)
#define HAVE_sync_new_nandqi (TARGET_S32C1I && !TARGET_DISABLE_HARDWARE_ATOMICS)
extern rtx        gen_addsi3                   (rtx, rtx, rtx);
extern rtx        gen_addsf3                   (rtx, rtx, rtx);
extern rtx        gen_subsi3                   (rtx, rtx, rtx);
extern rtx        gen_subsf3                   (rtx, rtx, rtx);
extern rtx        gen_mulsi3_highpart          (rtx, rtx, rtx);
extern rtx        gen_umulsi3_highpart         (rtx, rtx, rtx);
extern rtx        gen_mulsi3                   (rtx, rtx, rtx);
extern rtx        gen_mulhisi3                 (rtx, rtx, rtx);
extern rtx        gen_umulhisi3                (rtx, rtx, rtx);
extern rtx        gen_muladdhisi               (rtx, rtx, rtx, rtx);
extern rtx        gen_mulsubhisi               (rtx, rtx, rtx, rtx);
extern rtx        gen_mulsf3                   (rtx, rtx, rtx);
extern rtx        gen_fmasf4                   (rtx, rtx, rtx, rtx);
extern rtx        gen_fnmasf4                  (rtx, rtx, rtx, rtx);
extern rtx        gen_divsi3                   (rtx, rtx, rtx);
extern rtx        gen_udivsi3                  (rtx, rtx, rtx);
extern rtx        gen_modsi3                   (rtx, rtx, rtx);
extern rtx        gen_umodsi3                  (rtx, rtx, rtx);
extern rtx        gen_abssi2                   (rtx, rtx);
extern rtx        gen_abssf2                   (rtx, rtx);
extern rtx        gen_sminsi3                  (rtx, rtx, rtx);
extern rtx        gen_uminsi3                  (rtx, rtx, rtx);
extern rtx        gen_smaxsi3                  (rtx, rtx, rtx);
extern rtx        gen_umaxsi3                  (rtx, rtx, rtx);
extern rtx        gen_clrsbsi2                 (rtx, rtx);
extern rtx        gen_clzsi2                   (rtx, rtx);
extern rtx        gen_bswaphi2                 (rtx, rtx);
extern rtx        gen_bswapsi2_internal        (rtx, rtx);
extern rtx        gen_negsi2                   (rtx, rtx);
extern rtx        gen_one_cmplsi2              (rtx, rtx);
extern rtx        gen_negsf2                   (rtx, rtx);
extern rtx        gen_andsi3                   (rtx, rtx, rtx);
extern rtx        gen_iorsi3                   (rtx, rtx, rtx);
extern rtx        gen_xorsi3_internal          (rtx, rtx, rtx);
extern rtx        gen_zero_extendhisi2         (rtx, rtx);
extern rtx        gen_zero_extendqisi2         (rtx, rtx);
extern rtx        gen_extendhisi2_internal     (rtx, rtx);
extern rtx        gen_extendqisi2_internal     (rtx, rtx);
extern rtx        gen_extvsi_internal          (rtx, rtx, rtx, rtx);
extern rtx        gen_extzvsi_internal         (rtx, rtx, rtx, rtx);
extern rtx        gen_fix_truncsfsi2           (rtx, rtx);
extern rtx        gen_fixuns_truncsfsi2        (rtx, rtx);
extern rtx        gen_floatsisf2               (rtx, rtx);
extern rtx        gen_floatunssisf2            (rtx, rtx);
extern rtx        gen_movdi_internal           (rtx, rtx);
extern rtx        gen_movsi_internal           (rtx, rtx);
extern rtx        gen_movhi_internal           (rtx, rtx);
extern rtx        gen_movqi_internal           (rtx, rtx);
extern rtx        gen_movsf_internal           (rtx, rtx);
extern rtx        gen_movdf_internal           (rtx, rtx);
extern rtx        gen_ashlsi3_internal         (rtx, rtx, rtx);
extern rtx        gen_ashrsi3                  (rtx, rtx, rtx);
extern rtx        gen_lshrsi3                  (rtx, rtx, rtx);
extern rtx        gen_rotlsi3                  (rtx, rtx, rtx);
extern rtx        gen_rotrsi3                  (rtx, rtx, rtx);
extern rtx        gen_zero_cost_loop_start     (rtx, rtx, rtx);
extern rtx        gen_zero_cost_loop_end       (rtx, rtx, rtx);
extern rtx        gen_loop_end                 (rtx, rtx, rtx);
extern rtx        gen_salt                     (rtx, rtx, rtx);
extern rtx        gen_saltu                    (rtx, rtx, rtx);
extern rtx        gen_movsicc_internal0        (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_movsicc_internal1        (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_movsfcc_internal0        (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_movsfcc_internal1        (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_seq_sf                   (rtx, rtx, rtx);
extern rtx        gen_slt_sf                   (rtx, rtx, rtx);
extern rtx        gen_sle_sf                   (rtx, rtx, rtx);
extern rtx        gen_suneq_sf                 (rtx, rtx, rtx);
extern rtx        gen_sunlt_sf                 (rtx, rtx, rtx);
extern rtx        gen_sunle_sf                 (rtx, rtx, rtx);
extern rtx        gen_sunordered_sf            (rtx, rtx, rtx);
extern rtx        gen_jump                     (rtx);
extern rtx        gen_indirect_jump_internal   (rtx);
extern rtx        gen_tablejump_internal       (rtx, rtx);
extern rtx        gen_call_internal            (rtx, rtx);
extern rtx        gen_call_value_internal      (rtx, rtx, rtx);
extern rtx        gen_sibcall_internal         (rtx, rtx);
extern rtx        gen_sibcall_value_internal   (rtx, rtx, rtx);
extern rtx        gen_entry                    (rtx);
extern rtx        gen_return                   (void);
extern rtx        gen_nop                      (void);
extern rtx        gen_eh_set_a0_windowed       (rtx);
extern rtx        gen_eh_set_a0_call0          (rtx);
extern rtx        gen_blockage                 (void);
extern rtx        gen_trap                     (void);
extern rtx        gen_set_frame_ptr            (void);
extern rtx        gen_get_thread_pointersi     (rtx);
extern rtx        gen_set_thread_pointersi     (rtx);
extern rtx        gen_tls_func                 (rtx, rtx);
extern rtx        gen_tls_arg                  (rtx, rtx);
extern rtx        gen_tls_call                 (rtx, rtx, rtx, rtx);
extern rtx        gen_sync_lock_releasesi      (rtx, rtx);
extern rtx        gen_sync_compare_and_swapsi  (rtx, rtx, rtx, rtx);
extern rtx        gen_eq_zero_NSA              (rtx, rtx);
extern rtx        gen_eqne_zero                (rtx, rtx, rtx);
extern rtx        gen_adddi3                   (rtx, rtx, rtx);
extern rtx        gen_subdi3                   (rtx, rtx, rtx);
extern rtx        gen_mulsidi3                 (rtx, rtx, rtx);
extern rtx        gen_umulsidi3                (rtx, rtx, rtx);
extern rtx        gen_ctzsi2                   (rtx, rtx);
extern rtx        gen_ffssi2                   (rtx, rtx);
extern rtx        gen_bswapsi2                 (rtx, rtx);
extern rtx        gen_bswapdi2                 (rtx, rtx);
extern rtx        gen_xorsi3                   (rtx, rtx, rtx);
extern rtx        gen_extendhisi2              (rtx, rtx);
extern rtx        gen_extendqisi2              (rtx, rtx);
extern rtx        gen_extvsi                   (rtx, rtx, rtx, rtx);
extern rtx        gen_extzvsi                  (rtx, rtx, rtx, rtx);
extern rtx        gen_movdi                    (rtx, rtx);
extern rtx        gen_movsi                    (rtx, rtx);
extern rtx        gen_movhi                    (rtx, rtx);
extern rtx        gen_movqi                    (rtx, rtx);
extern rtx        gen_reloadhi_literal         (rtx, rtx, rtx);
extern rtx        gen_reloadqi_literal         (rtx, rtx, rtx);
extern rtx        gen_movsf                    (rtx, rtx);
extern rtx        gen_movdf                    (rtx, rtx);
extern rtx        gen_cpymemsi                 (rtx, rtx, rtx, rtx);
extern rtx        gen_setmemsi                 (rtx, rtx, rtx, rtx);
extern rtx        gen_ashlsi3                  (rtx, rtx, rtx);
extern rtx        gen_cbranchsi4               (rtx, rtx, rtx, rtx);
extern rtx        gen_cbranchsf4               (rtx, rtx, rtx, rtx);
extern rtx        gen_doloop_end               (rtx, rtx);
extern rtx        gen_cstoresi4                (rtx, rtx, rtx, rtx);
extern rtx        gen_cstoresf4                (rtx, rtx, rtx, rtx);
extern rtx        gen_movsicc                  (rtx, rtx, rtx, rtx);
extern rtx        gen_movsfcc                  (rtx, rtx, rtx, rtx);
extern rtx        gen_indirect_jump            (rtx);
extern rtx        gen_tablejump                (rtx, rtx);
extern rtx        gen_sym_PLT                  (rtx);
extern rtx        gen_call                     (rtx, rtx);
extern rtx        gen_call_value               (rtx, rtx, rtx);
extern rtx        gen_sibcall                  (rtx, rtx);
extern rtx        gen_sibcall_value            (rtx, rtx, rtx);
extern rtx        gen_untyped_call             (rtx, rtx, rtx);
extern rtx        gen_allocate_stack           (rtx, rtx);
extern rtx        gen_prologue                 (void);
extern rtx        gen_epilogue                 (void);
extern rtx        gen_sibcall_epilogue         (void);
extern rtx        gen_nonlocal_goto            (rtx, rtx, rtx, rtx);
extern rtx        gen_eh_return                (rtx);
extern rtx        gen_frame_blockage           (void);
extern rtx        gen_sym_TPOFF                (rtx);
extern rtx        gen_sym_DTPOFF               (rtx);
extern rtx        gen_memory_barrier           (void);
extern rtx        gen_sync_compare_and_swaphi  (rtx, rtx, rtx, rtx);
extern rtx        gen_sync_compare_and_swapqi  (rtx, rtx, rtx, rtx);
extern rtx        gen_sync_lock_test_and_sethi (rtx, rtx, rtx);
extern rtx        gen_sync_lock_test_and_setqi (rtx, rtx, rtx);
extern rtx        gen_sync_andhi               (rtx, rtx);
extern rtx        gen_sync_iorhi               (rtx, rtx);
extern rtx        gen_sync_xorhi               (rtx, rtx);
extern rtx        gen_sync_addhi               (rtx, rtx);
extern rtx        gen_sync_subhi               (rtx, rtx);
extern rtx        gen_sync_nandhi              (rtx, rtx);
extern rtx        gen_sync_andqi               (rtx, rtx);
extern rtx        gen_sync_iorqi               (rtx, rtx);
extern rtx        gen_sync_xorqi               (rtx, rtx);
extern rtx        gen_sync_addqi               (rtx, rtx);
extern rtx        gen_sync_subqi               (rtx, rtx);
extern rtx        gen_sync_nandqi              (rtx, rtx);
extern rtx        gen_sync_old_andhi           (rtx, rtx, rtx);
extern rtx        gen_sync_old_iorhi           (rtx, rtx, rtx);
extern rtx        gen_sync_old_xorhi           (rtx, rtx, rtx);
extern rtx        gen_sync_old_addhi           (rtx, rtx, rtx);
extern rtx        gen_sync_old_subhi           (rtx, rtx, rtx);
extern rtx        gen_sync_old_nandhi          (rtx, rtx, rtx);
extern rtx        gen_sync_old_andqi           (rtx, rtx, rtx);
extern rtx        gen_sync_old_iorqi           (rtx, rtx, rtx);
extern rtx        gen_sync_old_xorqi           (rtx, rtx, rtx);
extern rtx        gen_sync_old_addqi           (rtx, rtx, rtx);
extern rtx        gen_sync_old_subqi           (rtx, rtx, rtx);
extern rtx        gen_sync_old_nandqi          (rtx, rtx, rtx);
extern rtx        gen_sync_new_andhi           (rtx, rtx, rtx);
extern rtx        gen_sync_new_iorhi           (rtx, rtx, rtx);
extern rtx        gen_sync_new_xorhi           (rtx, rtx, rtx);
extern rtx        gen_sync_new_addhi           (rtx, rtx, rtx);
extern rtx        gen_sync_new_subhi           (rtx, rtx, rtx);
extern rtx        gen_sync_new_nandhi          (rtx, rtx, rtx);
extern rtx        gen_sync_new_andqi           (rtx, rtx, rtx);
extern rtx        gen_sync_new_iorqi           (rtx, rtx, rtx);
extern rtx        gen_sync_new_xorqi           (rtx, rtx, rtx);
extern rtx        gen_sync_new_addqi           (rtx, rtx, rtx);
extern rtx        gen_sync_new_subqi           (rtx, rtx, rtx);
extern rtx        gen_sync_new_nandqi          (rtx, rtx, rtx);

#endif /* GCC_INSN_FLAGS_H */
