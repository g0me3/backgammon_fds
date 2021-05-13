
; =========================
; ==== SYSTEM ROUTINES ====
; =========================

; =============== S U B	R O U T	I N E =======================================
RESET:
		CLD
		LDX		#$00
		STX		_PPU_CTRL
		STX		_PPU_MASK
loc_623E:
		LDA		_PPU_STATUS
		BPL		loc_623E
		DEX
		TXS
		LDX		_frames_counter
		LDY		#>[byte_700]
		STY		word_10+1
		LDY		#$00
		STY		word_10
		LDA		#$00
loc_6254:
		STA		(word_10),Y
		DEY
		BNE		loc_6254
		DEC		word_10+1
		BPL		loc_6254
		TXA
		BNE		loc_6262
		LDX		#$5F
loc_6262:
		STX		_rand_seed
		LDA		#$C0
		STA		byte_100
		LDA		#$80
		STA		byte_101
		LDA		#$35
		STA		byte_102
		LDA		#$AC
		STA		byte_103
		LDA		#$0F
		STA		_APU_STATUS
		LDA		#$C0
		STA		_PAD1_REG
		LDA		#$B0
		STA		_PPU_CTRL
		STA		_ppu_ctrl_shadow
		LDA		#$06
		STA		_ppu_mask_shadow
		JSR		_ppu_nt_clear
		JSR		_spr_clear
		STY		$2005
		STY		$2005
;		LDA		#$2F
;		JSR		sub_9C7F
		JSR		_main_programm_load

; !FALLTHROUGH!

; =============== S U B	R O U T	I N E =======================================
_MAIN:
		JSR		_main_cheat_dice_roll_editor
		JSR		_main_sub_exec
		JSR		_main_chr_patch_handler
		JSR		_ingame_points_wnd_draw
		JSR		_sync
		BEQ		_MAIN

; =============== S U B	R O U T	I N E =======================================
_main_cheat_dice_roll_editor:
		LDA		_ingame_sub_idx
		BNE		locret_7066
		LDA		_cheat_flag1
		BEQ		locret_7066
		LDY		_cur_player_idx
		LDA		_pads_held,Y
		CMP		#$85
		BNE		locret_7066
		LDA		#$06
		STA		_1p_first_dice_roll_override
		STA		_2p_first_dice_roll_override
loc_701A:
		JSR		_ingame_points_wnd_draw
		JSR		_ingame_message_draw
		JSR		_sync
		LDY		_cur_player_idx
		LDA		_pads_press,Y
		TAX
		AND		#$C0
		BNE		_dice_editor_exit
		TXA
		LDX		#$00
		CMP		#$01
		BEQ		loc_7041
		INX
		CMP		#$04
		BEQ		loc_7041
		CMP		#$02
		BNE		loc_701A
		JSR		_dice_editor_val_fix
		DEX
loc_7041:
		JSR		_dice_editor_val_fix
		JMP		loc_701A

; =============== S U B	R O U T	I N E =======================================
_dice_editor_val_fix:
		INC		_1p_first_dice_roll_override,X
		LDA		_1p_first_dice_roll_override,X
		CMP		#$07
		BCC		locret_7056
		LDA		#$01
		STA		_1p_first_dice_roll_override,X
locret_7056:
		RTS

; =============== S U B	R O U T	I N E =======================================
_dice_editor_exit:
		LDY		#$05
		LDA		#$00
loc_705B:
		STA		_pads_held,Y
		DEY
		BPL		loc_705B
		LDA		#$01
		STA		byte_57B
locret_7066:
		RTS

; =============== S U B	R O U T	I N E =======================================
_main_sub_exec:
		LDA		_main_sub_idx
		JSR		_switch
; ---------------------------------------------------------------------------
		.WORD _main00_setup
		.WORD _main01_demo
		.WORD _main02_game

; =============== S U B	R O U T	I N E =======================================
_main00_setup:
		LDA		_main00_sub_idx
		JSR		_switch
; ---------------------------------------------------------------------------
		.WORD _main00_sub00_title_draw
		.WORD _main00_sub01_title_init
		.WORD _main00_sub02_title_input
		.WORD _main00_sub03_menu_draw
		.WORD _main00_sub04_menu_input
		.WORD _main00_sub05_match_menu_draw
		.WORD _main00_sub06_match_menu_input
		.WORD _main00_sub07_menu_restore

; =============== S U B	R O U T	I N E =======================================
_main00_sub00_title_draw:
		JSR		_randA
		LDY		#$00
		STY		byte_FC
		STY		byte_FD
		JSR		_apu_play_ctrlA_set01
		LDA		_ppu_ctrl_shadow
		AND		#$F4
		STA		_ppu_ctrl_shadow
		LDA		#$07
		STA		_nmi_tlm_lib_idx
		JSR		_sync
		JSR		_ppu_render_off
;		LDA		#$2F
;		JSR		sub_9C7F
		JSR		_ppu_nt_clear
		JSR		_spr_clear
		LDA		#$01
		STA		_nmi_disable_flush
		LDX		#<[_tlm_title]
		LDY		#>[_tlm_title]
		JSR		_ppu_tlm_unpack
		LDA		#$01
		JSR		_chr_load
		LDA		#$00
		STA		_nmi_disable_flush
		LDY		#$05
		JSR		_pal_fade_outA
		LDY		#$FF
		STY		byte_55F
		LDA		#$1C
		STA		byte_55B
		INC		_main00_sub_idx
		RTS

; =============== S U B	R O U T	I N E =======================================
_main00_sub01_title_init:
		JSR		_apu_play_ctrlD_set04
		INC		_main00_sub_idx
		LDA		#$0B
		STA		_tmp4Bb
		LDY		#$00
		STY		_tmp_idx
		STY		_cheat_flag0
		RTS

; =============== S U B	R O U T	I N E =======================================
_main00_sub02_title_input:
		JSR		sub_9C94
		LDA		#>[_cheat_seq0]
		STA		_tmp20w+1
		LDA		#<[_cheat_seq0]
		STA		_tmp20w
		JSR		_cheat_seq_test
		BCC		loc_A2D0
		LDA		#$01
		STA		_cheat_flag0
loc_A2D0:
		LDA		_nmi_counter
		AND		#$07
		CMP		#$07
		BNE		loc_A2EC
		LDY		_tmp4Bb
		DEC		_tmp4Bb
		BPL		loc_A2E2
		LDY		#$0B
		STY		_tmp4Bb
loc_A2E2:
		LDA		_title_pal_anim_list,Y
		STA		_pal_buf4+4
		LDA		#$04
		STA		_nmi_tlm_lib_idx
loc_A2EC:
		LDA		_pads_held
		AND		#$90
		BEQ		loc_A30D
		JSR		_apu_play_ctrlB_set02
		INC		_main00_sub_idx
		LDY		#$05
		JSR		_pal_fade_outB
		LDA		#$01
		STA		_nmi_disable_flush
		LDA		#$04
		JSR		_chr_load
		LDA		#$00
		STA		_nmi_disable_flush
locret_A30C:
		RTS
; ---------------------------------------------------------------------------
loc_A30D:
		LDA		_nmi_counter
		BNE		locret_A30C
		LDY		#<[_txt_push_start]
		STY		_tmp20w
		LDY		#>[_txt_push_start]
		STY		_tmp20w+1
		LDX		#$1E
		LDA		_title_push_start_toggle
		EOR		#$01
		STA		_title_push_start_toggle
		BNE		loc_A32F
		LDA		#<[_txt_blank]
		STA		_tmp20w
		LDA		#>[_txt_blank]
		STA		_tmp20w+1
		LDX		#$0F
loc_A32F:
		STX		_nmi_counter
		LDY		#$00
		LDA		(_tmp20w),Y
		TAY
loc_A336:
		LDA		(_tmp20w),Y
		STA		_tlm_ramB1_buf,Y
		DEY
		BNE		loc_A336
		LDA		#$01
		STA		byte_32
		RTS
; ---------------------------------------------------------------------------
_title_pal_anim_list:
		.BYTE $3C,$3B,$3A,$39,$38,$37,$36,$35,$34,$33,$32,$31
_txt_push_start:
		.BYTE $0E
		.WORD $4B23
		.BYTE $0A
		.BYTE _P,_U,_S,_H,$2F,_S,_T,_A,_R,_T
		.BYTE $FF
_txt_blank:
		.BYTE $05
		.WORD $4B23
		.BYTE $4A
		.BYTE $2F
		.BYTE $FF

; =============== S U B	R O U T	I N E =======================================
_cheat_seq_test:
		LDA		_pads_press+1
		BEQ		loc_A374
		LDY		_tmp_idx
		CMP		(_tmp20w),Y
		BNE		loc_A376
		INC		_tmp_idx
		CPY		#$07
		BCS		loc_A377
loc_A374:
		CLC
		RTS
loc_A376:
		CLC
loc_A377:
		LDA		#$00
		STA		_tmp_idx
		RTS
; ---------------------------------------------------------------------------
_cheat_seq0:
		.BYTE $80,$80,$80,$08,$01,$40,$04,$08
_cheat_seq1:
		.BYTE $04,$02,$01,$01,$40,$80,$80,$04

; =============== S U B	R O U T	I N E =======================================
_main00_sub03_menu_draw:
		LDY		#$00
		STY		byte_FC
		LDY		#$04
		STY		byte_FD
		JSR		_ppu_render_off
;		LDA		#$2F
;		JSR		sub_9C7F
		JSR		_ppu_nt_clear
		LDA		#$01
		STA		_nmi_disable_flush
		LDX		#<[_tlm_menu]
		LDY		#>[_tlm_menu]
		JSR		_ppu_tlm_unpack
		LDA		#$00
		STA		_nmi_disable_flush
		LDY		#$06
		JSR		_pal_fade_outA
		LDY		#$00
		STY		_1p_cpu_ctrl_flag
		STY		_2p_cpu_ctrl_flag
		STY		_main02_sub_idx
		STY		_timer_minutes
		INC		_main00_sub_idx
		RTS

; =============== S U B	R O U T	I N E =======================================
_main00_sub04_menu_input:
		LDA		#>[_cheat_seq1]
		STA		_tmp20w+1
		LDA		#<[_cheat_seq1]
		STA		_tmp20w
		JSR		_cheat_seq_test
		BCC		loc_A3DD
		LDA		_cheat_flag0
		BEQ		loc_A3DD
		LDA		#$01
		STA		_cheat_flag1
loc_A3DD:
		LDY		_menu_pos_idx
		LDA		_pads_press
		AND		#$08
		BEQ		loc_A3ED
		DEY
		BPL		loc_A3FC
		LDY		#$04
		BPL		loc_A3FC
loc_A3ED:
		LDA		_pads_press
		AND		#$24
		BEQ		loc_A3FF
		INY
		CPY		#$05
		BCC		loc_A3FC
		LDY		#$00
		BMI		loc_A3FF
loc_A3FC:
		JMP		loc_A474
; ---------------------------------------------------------------------------
loc_A3FF:
		LDA		_pads_press
		AND		#$90
		BEQ		loc_A477
		STY		_menu_pos_idx
		STY		_game_mode_idx
		JSR		_apu_play_ctrlB_set02
		LDA		_cheat_flag1
		BEQ		loc_A419
		LDA		_pads_held
		AND		#$01
		BNE		loc_A41C
loc_A419:
		LDA		_1p_cpu_ctrl_list,Y
loc_A41C:
		STA		_1p_cpu_ctrl_flag
		LDA		_2p_cpu_ctrl_list,Y
		STA		_2p_cpu_ctrl_flag
		CPY		#$02
		BEQ		_match_select_menu_start
		CPY		#$04
		BNE		_demo_play_start
_match_select_menu_start:
		INC		_main00_sub_idx
		RTS
; ---------------------------------------------------------------------------
_demo_play_start:
		CPY		#$00
		BNE		_other_game_start
		LDA		#$1E
		JSR		_wait_for_nmi
		JSR		_apu_play_ctrlA_set04
		LDY		#$06
		JSR		_pal_fade_outB
		JSR		_wait_for_70_frames
		LDA		#$01
		JSR		_unrom_prg_set
		LDA		#$03
		JSR		_chr_load
		JSR		_apu_play_ctrlA_set01
		LDY		#$00
		STY		_demo_sub_idx
		INC		_main_sub_idx
		RTS
; ---------------------------------------------------------------------------
_other_game_start:
		LDX		#$00
		STX		_main00_sub_idx
		INX
		INX
		STX		_main_sub_idx
		LDA		_ppu_ctrl_shadow
		AND		#$F7
		ORA		#$20
		STA		_ppu_ctrl_shadow
		JSR		_apu_play_ctrlA_set04
		LDY		#$06
		JSR		_pal_fade_outB
		JMP		_wait_for_70_frames
; ---------------------------------------------------------------------------
loc_A474:
		JSR		_apu_play_ctrlB_set01
loc_A477:
		LDA		_menu_pos_list,Y
		STA		_spr_buf
		LDA		#$FE
		STA		_spr_buf+1
		LDA		#$00
		STA		_spr_buf+2
		LDA		#$34
		STA		_spr_buf+3
		STY		_menu_pos_idx
		RTS
; ---------------------------------------------------------------------------
_menu_pos_list:
		.BYTE $47,$57,$67,$77,$87
_1p_cpu_ctrl_list:
		.BYTE $01,$00,$00,$00,$00
_2p_cpu_ctrl_list:
		.BYTE $01,$01,$01,$01,$00

; =============== S U B	R O U T	I N E =======================================
_main00_sub05_match_menu_draw:
		LDY		#$06
loc_A4A1:
		STY		_tmp4Bb
		LDX		_tlm_res_match_menu_lib_hi,Y
		LDA		_tlm_res_match_menu_lib_lo,Y
		TAY
		JSR		_tlm_B1_ram_queue
		JSR		_sync
		LDY		_tmp4Bb
		DEY
		BPL		loc_A4A1
		INC		_main00_sub_idx
		RTS

; =============== S U B	R O U T	I N E =======================================
_main00_sub06_match_menu_input:
		LDY		_match_menu_pos
		LDA		_pads_press
		AND		#$08
		BEQ		loc_A4D6
		DEY
		BPL		loc_A527
		LDY		#$02
		BPL		loc_A527
loc_A4D6:
		LDA		_pads_press
		AND		#$24
		BEQ		loc_A4E5
		INY
		CPY		#$03
		BCC		loc_A527
		LDY		#$00
		BPL		loc_A527
loc_A4E5:
		LDA		_pads_press
		AND		#$40
		BEQ		loc_A4F0
		LDA		#$07
		STA		_main00_sub_idx
		RTS
; ---------------------------------------------------------------------------
loc_A4F0:
		LDA		_pads_press
		AND		#$90
		BEQ		loc_A52A
		JSR		_apu_play_ctrlB_set02
		LDA		_match_menu_pts_list_lo,Y
		STA		_match_pts_val
		LDA		_match_menu_pts_list_hi,Y
		STA		_match_pts_val+1
		LDX		#$00
		CPY		#$02
		BNE		loc_A50C
		INX
loc_A50C:
		STX		byte_554
		LDX		#$02
		STX		_main_sub_idx
		LDA		_ppu_ctrl_shadow
		AND		#$F7
		ORA		#$20
		STA		_ppu_ctrl_shadow
		JSR		_apu_play_ctrlA_set04
		LDY		#$06
		JSR		_pal_fade_outB
		JMP		_wait_for_70_frames
; ---------------------------------------------------------------------------
loc_A527:
		JSR		_apu_play_ctrlB_set01
loc_A52A:
		LDA		_match_menu_pos_list,Y
		STA		_spr_buf+4
		LDA		#$FE
		STA		_spr_buf+5
		LDA		#$00
		STA		_spr_buf+6
		LDA		#$48
		STA		_spr_buf+7
		STY		_match_menu_pos
		RTS
; ---------------------------------------------------------------------------
_match_menu_pos_list:
		.BYTE $87,$97,$A7
_match_menu_pts_list_lo:
		.BYTE $05,$0B,$99
_match_menu_pts_list_hi:
		.BYTE $00,$00,$09

; =============== S U B	R O U T	I N E =======================================
_main00_sub07_menu_restore:
		LDA		#$F4
		STA		_spr_buf+4
		LDY		#$04
loc_A553:
		LDA		off_A572,Y
		STA		_tmp20w+1
		LDA		off_A577,Y
		STA		_tmp20w
		STY		_tmp4Bb
		JSR		_tlm_ram_queue22
		LDY		_tmp4Bb
		DEY
		BPL		loc_A553
		LDY		#$00
		STY		_1p_cpu_ctrl_flag
		STY		_2p_cpu_ctrl_flag
		LDA		#$04
		STA		_main00_sub_idx
		RTS

; =============== S U B	R O U T	I N E =======================================
_tlm_ram_queue22:
		LDY		#$22
loc_A57E:
		LDA		(_tmp20w),Y
		STA		_nmi_tlmB1_ram,Y
		DEY
		BPL		loc_A57E
		LDA		#$01
		STA		byte_32
		JMP		_sync

; =============== S U B	R O U T	I N E =======================================
_set_field_pal:
		TYA
		ASL
		ASL
		PHA
		LDX		#[_pal_end-_pal1-1]
.set_field_loop:
		LDA		_pal1,X
		STA		_pal_buf1,X
		DEX
		BNE		.set_field_loop
		PLA
		TAY
		LDA		_field_pal_patch_lib,Y
		STA		[_pal_buf1+[_pal1_p0_w-_pal1]]
		STA		[_pal_buf1+[_pal1_p0_w-_pal1]+4]
		STA		[_pal_buf1+[_pal1_p0_w-_pal1]+8]
		STA		[_pal_buf1+[_pal1_p0_w-_pal1]+$C]
		STA		[_pal_buf1+[_pal1_p0_w-_pal1]+$10]
		STA		[_pal_buf1+[_pal1_p0_w-_pal1]+$14]
		STA		[_pal_buf1+[_pal1_p0_w-_pal1]+$18]
		STA		[_pal_buf1+[_pal1_p0_w-_pal1]+$1C]
		STA		[_pal_buf2+[_pal2_p0_w-_pal2]]
		STA		[_pal_buf2+[_pal2_p1_w-_pal2]]
		STA		[_pal_buf3+[_pal3_p0_w-_pal3]]
		STA		[_pal_buf3+[_pal3_p1_w-_pal3]]
		LDA		_field_pal_patch_lib+1,Y
		STA		[_pal_buf1+[_pal1_p0_w-_pal1]+5]
		STA		[_pal_buf1+[_pal1_p0_w-_pal1]+$D]
		STA		[_pal_buf1+[_pal1_p0_w-_pal1]+$1D]
		STA		[_pal_buf2+[_pal2_p1_w-_pal2]+1]
		STA		[_pal_buf3+[_pal3_p1_w-_pal3]+1]
		LDA		_field_pal_patch_lib+2,Y
		STA		[_pal_buf1+[_pal1_p0_w-_pal1]+2]
		STA		[_pal_buf1+[_pal1_p0_w-_pal1]+6]
		LDA		_field_pal_patch_lib+3,Y
		STA		[_pal_buf1+[_pal1_p0_w-_pal1]+$A]
		STA		[_pal_buf1+[_pal1_p0_w-_pal1]+$E]
		RTS
; ---------------------------------------------------------------------------
_field_pal_patch_lib:
		.BYTE $17,$16,$1A,$27
		.BYTE $3B,$16,$38,$2B
		.BYTE $0F,$30,$21,$34
		.BYTE $28,$16,$1A,$17
		.BYTE $14,$15,$25,$34
		.BYTE $10,$15,$1C,$3C
		.BYTE $1A,$16,$18,$28
		.BYTE $1A,$16,$28,$29
		.BYTE $17,$15,$18,$28
		.BYTE $1C,$16,$24,$3C
		.BYTE $3B,$16,$24,$32
		.BYTE $3C,$16,$35,$3A
		.BYTE $38,$16,$24,$2B
_pal1:
		.WORD $003F
		.BYTE $20
_pal1_p0_w:
		.BYTE $17,$30,$1A,$0F
		.BYTE $17,$16,$1A,$0F
		.BYTE $17,$30,$27,$0F
		.BYTE $17,$16,$27,$0F
		.BYTE $17,$37,$2C,$0F
		.BYTE $17,$12,$2C,$0F
		.BYTE $17,$30,$30,$0F
		.BYTE $17,$16,$0F,$0F
		.BYTE $FF
_pal2:
		.WORD $103F
		.BYTE $04
_pal2_p0_w:
		.BYTE $17,$36,$2C,$0F
		.WORD $1C3F
		.BYTE $04
_pal2_p1_w:
		.BYTE $17,$16,$10,$0F
		.BYTE $FF
_pal3:
		.WORD $103F
		.BYTE $04
_pal3_p0_w:
		.BYTE $17,$37,$2C,$0F
		.WORD $1C3F
		.BYTE $04
_pal3_p1_w:
		.BYTE $17,$16,$25,$0F
		.BYTE $FF
_pal_end:

_tlm_title:
		.BYTE $20,$82,$5D,$76,$20,$C2,$1D,$90,$91,$92,$2F,$94,$2F,$D0,$D1,$D2
		.BYTE $96,$97,$98,$99,$9A,$2F,$94,$2F,$9B,$9C,$9D,$9B,$9C,$9D,$C8,$C9
		.BYTE $CA,$9E,$9F,$E6,$20,$E2,$1D,$A0,$A1,$93,$2F,$A4,$2F,$E0,$2F,$E2
		.BYTE $A1,$A7,$A8,$E9,$AA,$2F,$A4,$2F,$AB,$AC,$AD,$AB,$AC,$AD,$E0,$A0
		.BYTE $A9,$AE,$2F,$E9,$21,$02,$1D,$A0,$A1,$A2,$B3,$B4,$B5,$F0,$2F,$A0
		.BYTE $B6,$B7,$B8,$E9,$2F,$B3,$B4,$B5,$BB,$BC,$AD,$BB,$BC,$AD,$F0,$A0
		.BYTE $B9,$BE,$BF,$E9,$21,$22,$1D,$A0,$B1,$B2,$C3,$C4,$C5,$F0,$2F,$A0
		.BYTE $C6,$C7,$B8,$E9,$2F,$C3,$C4,$C5,$CB,$CC,$AD,$CB,$CC,$AD,$F0,$A0
		.BYTE $B9,$CE,$CF,$E9,$21,$42,$1D,$A0,$A1,$B0,$D3,$D4,$D5,$F0,$2F,$A0
		.BYTE $D6,$D7,$B8,$D9,$DA,$D3,$D4,$D5,$DB,$DC,$AD,$DB,$DC,$AD,$F0,$A0
		.BYTE $B9,$DE,$DF,$E9,$21,$62,$1D,$A0,$A1,$93,$E3,$E4,$E5,$E1,$2F,$A3
		.BYTE $A1,$E7,$E8,$E9,$EA,$E3,$E4,$E5,$EB,$EC,$AD,$EB,$EC,$AD,$E1,$A0
		.BYTE $BD,$EE,$EF,$E9,$21,$82,$1D,$C0,$C1,$C2,$F3,$F4,$F5,$F1,$F2,$95
		.BYTE $F6,$F7,$F8,$F9,$FA,$F3,$F4,$F5,$FB,$FC,$FD,$FB,$FC,$FD,$DD,$ED
		.BYTE $CD,$FE,$FF,$E9,$21,$C2,$5D,$76,$22,$48,$10,$70,$71,$72,$73,$74
		.BYTE $75,$A5,$77,$78,$79,$7A,$7B,$2F,$7C,$7D,$7E,$22,$68,$10,$80,$81
		.BYTE $82,$83,$84,$85,$86,$87,$88,$89,$8A,$8B,$2F,$8C,$8D,$8E,$22,$EA
		.BYTE $0C,$2C,$01,$09,$09,$00,$2F,$A6,$AF,$BA,$D8,$7F,$8F,$23,$E2,$04
		.BYTE $50,$50,$50,$50,$23,$EA,$0C,$80,$A0,$A0,$20,$00,$00,$00,$00,$80
		.BYTE $A0,$A0,$20,$FF
_tlm_menu:
		.BYTE $20,$E5,$01,$0A
		.BYTE $20,$E6,$52,$0B
		.BYTE $20,$F8,$01,$0C
		.BYTE $21,$05,$01,$10
		.BYTE $21,$06,$52,__
		.BYTE $21,$18,$01,$2D
		.BYTE $21,$25,$14,$10,__,__,__,_D,_E,_M,_O,_N,_S,_T,_R,_A,_T,_I,_O,_N,__,__,$2D
		.BYTE $21,$45,$01,$10
		.BYTE $21,$46,$52,__
		.BYTE $21,$58,$01,$2D
		.BYTE $21,$65,$14,$10,__,__,__,_T,_R,_A,_I,_N,_I,_N,_G,__,_P,_L,_A,_Y,__,__,$2D
		.BYTE $21,$85,$01,$10
		.BYTE $21,$86,$52,__
		.BYTE $21,$98,$01,$2D
		.BYTE $21,$A5,$14,$10,__,__,__,_M,_A,_T,_C,_H,__,_P,_L,_A,_Y,__,__,__,__,__,$2D
		.BYTE $21,$C5,$01,$10
		.BYTE $21,$C6,$52,__
		.BYTE $21,$D8,$01,$2D
		.BYTE $21,$E5,$14,$10,__,__,__,_T,_O,_U,_R,_N,_A,_M,_E,_N,_T,__,__,__,__,__,$2D
		.BYTE $22,$05,$01,$10
		.BYTE $22,$06,$52,__
		.BYTE $22,$18,$01,$2D
		.BYTE $22,$25,$14,$10,__,__,__,_2,__,_P,_L,_A,_Y,_E,_R,_S,__,_G,_A,_M,_E,__,$2D
		.BYTE $22,$45,$01,$10
		.BYTE $22,$46,$52,__
		.BYTE $22,$58,$01,$2D
		.BYTE $22,$65,$01,$0D
		.BYTE $22,$66,$52,$0E
		.BYTE $22,$78,$01,$0F
		.BYTE $FF
_tlm_res_match_menu_lib_lo:
		.BYTE >[_tlm_res_match_menu0]
		.BYTE >[_tlm_res_match_menu1]
		.BYTE >[_tlm_res_match_menu2]
		.BYTE >[_tlm_res_match_menu3]
		.BYTE >[_tlm_res_match_menu4]
		.BYTE >[_tlm_res_match_menu5]
		.BYTE >[_tlm_res_match_menu6]
_tlm_res_match_menu_lib_hi:
		.BYTE <[_tlm_res_match_menu0]
		.BYTE <[_tlm_res_match_menu1]
		.BYTE <[_tlm_res_match_menu2]
		.BYTE <[_tlm_res_match_menu3]
		.BYTE <[_tlm_res_match_menu4]
		.BYTE <[_tlm_res_match_menu5]
		.BYTE <[_tlm_res_match_menu6]
_tlm_res_match_menu6:
		.BYTE $18
		.BYTE $21,$E8,$01,$0A
		.BYTE $21,$E9,$52,$0B
		.BYTE $21,$FB,$01,$0C
		.BYTE $22,$08,$01,$10
		.BYTE $22,$09,$52,$2E
		.BYTE $22,$1B,$01,$2D
_tlm_res_match_menu5:
		.BYTE $17
		.BYTE $22,$28,$14,$10,__,__,__,_5,__,_P,_O,_I,_N,_T,_S,__,_M,_A,_T,_C,_H,__,$2D
_tlm_res_match_menu4:
		.BYTE $0C
		.BYTE $22,$48,$01,$10
		.BYTE $22,$49,$52,$2E
		.BYTE $22,$5B,$01,$2D
_tlm_res_match_menu3:
		.BYTE $17
		.BYTE $22,$68,$14,$10,__,__,_1,_1,__,_P,_O,_I,_N,_T,_S,__,_M,_A,_T,_C,_H,__,$2D
_tlm_res_match_menu2:
		.BYTE $0C
		.BYTE $22,$88,$01,$10
		.BYTE $22,$89,$52,__
		.BYTE $22,$9B,$01,$2D
_tlm_res_match_menu1:
		.BYTE $17
		.BYTE $22,$A8,$14,$10,__,__,__,_E,_N,_D,_L,_E,_S,_S,__,__,_M,_A,_T,_C,_H,__,$2D
_tlm_res_match_menu0:
		.BYTE $18
		.BYTE $22,$C8,$01,$10
		.BYTE $22,$C9,$52,__
		.BYTE $22,$DB,$01,$2D
		.BYTE $22,$E8,$01,$0D
		.BYTE $22,$E9,$52,$0E
		.BYTE $22,$FB,$01,$0F
off_A572:
		.BYTE >[_tlm_res_main_menu_restore0]
		.BYTE >[_tlm_res_main_menu_restore1]
		.BYTE >[_tlm_res_main_menu_restore2]
		.BYTE >[_tlm_res_main_menu_restore3]
		.BYTE >[_tlm_res_main_menu_restore4]
off_A577:
		.BYTE <[_tlm_res_main_menu_restore0]
		.BYTE <[_tlm_res_main_menu_restore1]
		.BYTE <[_tlm_res_main_menu_restore2]
		.BYTE <[_tlm_res_main_menu_restore3]
		.BYTE <[_tlm_res_main_menu_restore4]
_tlm_res_main_menu_restore0:
		.WORD $E821
		.BYTE $14
		.BYTE __,_T,_O,_U,_R,_N,_A,_M,_E,_N,_T,__,__,__,__,__,$2D,$2F,$2F,$2F
		.WORD $0822
		.BYTE $50
		.BYTE __
		.WORD $1822
		.BYTE $04
		.BYTE $2D,$2F,$2F,$2F
		.BYTE $FF
_tlm_res_main_menu_restore1:
		.WORD $2822
		.BYTE $14
		.BYTE __,_2,__,_P,_L,_A,_Y,_E,_R,_S,__,_G,_A,_M,_E,__,$2D,$2F,$2F,$2F
		.WORD $4822
		.BYTE $50
		.BYTE __
		.WORD $5822
		.BYTE $04
		.BYTE $2D,$2F,$2F,$2F
		.BYTE $FF
_tlm_res_main_menu_restore2:
		.WORD $6822
		.BYTE $50
		.BYTE $0E
		.WORD $7822
		.BYTE $04
		.BYTE $0F,$2F,$2F,$2F
		.WORD $8822
		.BYTE $54
		.BYTE $2F
		.BYTE $FF
_tlm_res_main_menu_restore3:
		.WORD $A822
		.BYTE $54
		.BYTE $2F
		.WORD $C822
		.BYTE $54
		.BYTE $2F
		.BYTE $FF
_tlm_res_main_menu_restore4:
		.WORD $E822
		.BYTE $54
		.BYTE $2F
		.BYTE $FF

; =============== S U B	R O U T	I N E =======================================
_main_chr_patch_handler:
		LDA		byte_32
		ORA		_ppu_queue_req
		ORA		_nmi_tlm_lib_idx
		ORA		byte_62
		ORA		byte_577
		BEQ		loc_A061
locret_A060:
		RTS
loc_A061:
		LDY		byte_55C
		BEQ		locret_A060
		DEY
		LDA		_chr_patch_lib_lo,Y
		STA		_tmp20w+1
		LDA		_chr_patch_lib_hi,Y
		STA		_tmp20w
		LDA		#$00
		STA		byte_55C
		LDX		#$00
		STX		byte_57
loc_A0E9:
		LDY		byte_57
		CPY		#$04
		BEQ		locret_A112
		LDA		#$00
		STA		_tmp1Cw+1
		LDA		_chr_patch_ofs_list,Y
		STA		_tmp1Cw
		LDA		_chr_patch_len_list,Y
		TAY
		JSR		_chr_patch_load_lib
		LDY		byte_57
		LDA		_tmp20w
		CLC
		ADC		_chr_patch_len_list,Y
		BCC		loc_A10B
		INC		_tmp20w+1
loc_A10B:
		STA		_tmp20w
		INC		byte_57
		JMP		loc_A0E9
locret_A112:
		RTS

; =============== S U B	R O U T	I N E =======================================
_chr_patch_load_lib:
		LDA		_tmp1Cw+1
		STA		_nmi_tlmB1_ram,X
		INX
		LDA		_tmp1Cw
		STA		_nmi_tlmB1_ram,X
		INX
		TYA
		STA		_nmi_tlmB1_ram,X
		INX
		DEY
loc_A12D:
		LDA		(_tmp20w),Y
		STA		_nmi_tlmB1_ram,X
		INX
		DEY
		BPL		loc_A12D
		LDA		#$FF
		STA		_nmi_tlmB1_ram,X
		LDA		#$01
		STA		byte_32
		RTS
; ---------------------------------------------------------------------------
_chr_patch_ofs_list:
		.BYTE $0A,$18,$2A,$38
_chr_patch_len_list:
		.BYTE $06,$02,$06,$02
_chr_patch_lib_lo:
		.BYTE >[_chr_patch00]
		.BYTE >[_chr_patch01]
		.BYTE >[_chr_patch02]
		.BYTE >[_chr_patch03]
		.BYTE >[_chr_patch04]
		.BYTE >[_chr_patch05]
_chr_patch_lib_hi:
		.BYTE <[_chr_patch00]
		.BYTE <[_chr_patch01]
		.BYTE <[_chr_patch02]
		.BYTE <[_chr_patch03]
		.BYTE <[_chr_patch04]
		.BYTE <[_chr_patch05]
_chr_patch00:
		.BYTE $22,$23,$23,$20,$23,$23,$23,$23,$02,$E2,$E2,$22,$E2,$E2,$E2,$E2
_chr_patch01:
		.BYTE $23,$23,$22,$22,$22,$22,$20,$20,$E2,$E2,$C2,$C2,$C2,$C2,$C2,$C2
_chr_patch02:
		.BYTE $22,$23,$23,$22,$23,$23,$23,$23,$22,$E2,$E2,$22,$E2,$E2,$E2,$E2
_chr_patch03:
		.BYTE $22,$22,$22,$22,$2E,$2E,$2F,$2F,$4A,$7A,$7A,$42,$7A,$7A,$7A,$7A
_chr_patch04:
		.BYTE $21,$2F,$2F,$21,$2F,$2F,$2F,$2F,$42,$7A,$7A,$0A,$7A,$7A,$7A,$7A
_chr_patch05:
		.BYTE $29,$2F,$2F,$28,$2F,$2F,$2F,$2F,$7A,$7A,$52,$52,$52,$52,$12,$12

; =============== S U B	R O U T	I N E =======================================
_sync:
		LDA		byte_568
		BEQ		_wait_for_flush
		LDA		_pads_press
		AND		#$20
		BEQ		_wait_for_flush
		JSR		_apu_play_ctrlC_set80
loc_99F9:
		JSR		_wait_for_flush
		LDA		_pads_press
		AND		#$20
		BEQ		loc_99F9
		JSR		_apu_play_ctrlC_set40
_wait_for_flush:
		LDA		#$01
		STA		_ppu_dequeue_req
_wait_for_flush_ex:
		JSR		_increment_rand_seed
		LDA		_nmi_flag
		BEQ		_wait_for_flush_ex
		INC		_frames_counter
		LDA		#$00
		STA		_ppu_dequeue_req
		STA		_nmi_flag
		RTS

; =============== S U B	R O U T	I N E =======================================
_ppu_render_off:
		JSR		_sync
		LDA		_ppu_mask_shadow
		AND		#$E7

; =============== S U B	R O U T	I N E =======================================
_ppu_status_set:
		STA		_PPU_MASK
		STA		_ppu_mask_shadow
		RTS

; =============== S U B	R O U T	I N E =======================================
_ppu_render_on:
		JSR		_sync
		JSR		sub_9C6D
		LDA		_ppu_mask_shadow
		ORA		#$18
		BNE		_ppu_status_set

; =============== S U B	R O U T	I N E =======================================
_nmi_on:
		LDA		_PPU_STATUS
		AND		#$80
		BNE		_nmi_on
		LDA		_ppu_ctrl_shadow
		ORA		#$80
		BNE		_ppu_ctrl_set

; =============== S U B	R O U T	I N E =======================================
_nmi_off:
		LDA		_ppu_ctrl_shadow
		AND		#$7F

; =============== S U B	R O U T	I N E =======================================
_ppu_ctrl_set:
		STA		_PPU_CTRL
		STA		_ppu_ctrl_shadow
		RTS

; =============== S U B	R O U T	I N E =======================================
NMI:
		CLI
		PHA
		TXA
		PHA
		TYA
		PHA
		LDA		_nmi_disable_flush
		BNE		loc_9A7A
		LDA		#$00
		STA		$2003
		LDA		#$02
		STA		_PPU_OAM_DMA
		LDA		_pause_mode_flag
		BNE		loc_9A5B
		LDA		_ppu_dequeue_req
		BEQ		loc_9A7A
		JSR		_nmi_tlm_libA_send
		JSR		_nmi_tlm_libB_send
		JSR		_nmi_ppu_dequeue
loc_9A5B:
		JSR		sub_9C6D
		LDA		_ppu_ctrl_shadow
		STA		_PPU_CTRL
		LDA		_ppu_mask_shadow
		STA		_PPU_MASK
		JSR		_read_pads
		LDA		_pause_mode_flag
		BNE		loc_9A7A
		JSR		_calc_pads
		LDY		#$01
		STY		_nmi_flag
		JMP		loc_9A7D
loc_9A7A:
		LDY		#$10
loc_9A96:
		LDA		$0100,Y
		LDA		$0200,Y
		LDA		$0300,Y
		LDA		$0500,Y
		LDA		$0600,Y
		DEY
		BNE		loc_9A96
loc_9A7D:
		LDA		#$01
		STA		byte_533
		LDA		_cur_prg_bank
		PHA
		LDA		#$01
		JSR		_unrom_prg_set
		JSR		_apu_play
		PLA
		JSR		_unrom_prg_set
		LDY		_nmi_counter
		BNE		loc_9A8B
		LDY		#$3C
loc_9A8B:
		DEY
		STY		_nmi_counter
		PLA
		TAY
		PLA
		TAX
		PLA
IRQ:
		RTI

; =============== S U B	R O U T	I N E =======================================
_ppu_nt_clear:
		LDA		#$20
		LDX		#$2F
		LDY		#$00
		STX		byte_12
		STY		byte_13
		STA		word_10+1
		LDA		_PPU_STATUS
		LDA		_ppu_ctrl_shadow
		AND		#$FB
		STA		_PPU_CTRL
		STA		_ppu_ctrl_shadow
		LDA		word_10+1
		STA		$2006
		LDA		#$00
		STA		$2006
		TAY
		LDX		#$04
		LDA		byte_12
loc_9AD0:
		STA		$2007
		DEY
		BNE		loc_9AD0
		DEX
		BNE		loc_9AD0
		LDA		word_10+1
		CLC
		ADC		#$03
		STA		$2006
		LDA		#$C0
		STA		$2006
		LDY		#$40
		LDA		byte_13
loc_9AEA:
		STA		$2007
		DEY
		BNE		loc_9AEA
		RTS

; =============== S U B	R O U T	I N E =======================================
_spr_clear:
		LDY		#$00
		LDA		#$F4
loc_9AF5:
		STA		_spr_buf,Y
		INY
		BNE		loc_9AF5
		STY		_spr_buf_pos
locret_9AFD:
		RTS

; =============== S U B	R O U T	I N E =======================================
_nmi_tlm_libA_send:
		LDY		_nmi_tlm_lib_idx
		BEQ		locret_9AFD
		DEY
		LDA		_nmi_tlm_lib_hi,Y
		LDX		_nmi_tlm_lib_lo,Y
		TAY
		LDA		#$00
		STA		_nmi_tlm_lib_idx
		JSR		_ppu_tlm_unpack
		LDA		#$3F
		STA		$2006
		LDA		#$00
		STA		$2006
		STA		$2006
		STA		$2006
		RTS
; ---------------------------------------------------------------------------
_nmi_tlm_lib_hi:
		.BYTE >[_pal_buf1]
		.BYTE >[_pal_buf2]
		.BYTE >[_pal_buf3]
		.BYTE >[_pal_buf4]
		.BYTE >[_pal5]
		.BYTE >[_pal6]
		.BYTE >[_pal7]
		.BYTE >[_pal8]
_nmi_tlm_lib_lo:
		.BYTE <[_pal_buf1]
		.BYTE <[_pal_buf2]
		.BYTE <[_pal_buf3]
		.BYTE <[_pal_buf4]
		.BYTE <[_pal5]
		.BYTE <[_pal6]
		.BYTE <[_pal7]
		.BYTE <[_pal8]
_pal5:
		.BYTE $3F,$00,$20,$0F,$30,$16,$0F,$0F,$30,$14,$0F,$0F,$0F,$28,$30,$0F
		.BYTE $30,$1A,$0F,$0F,$30,$16,$0F,$0F,$30,$14,$0F,$0F,$0F,$28,$30,$0F
		.BYTE $30,$1A,$0F,$FF
_pal6:
		.BYTE $3F,$00,$20,$0F,$30,$21,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F
		.BYTE $0F,$0F,$0F,$0F,$30,$26,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F
		.BYTE $0F,$0F,$0F,$FF
_pal7:
		.BYTE $3F,$00,$20,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F
		.BYTE $0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F
		.BYTE $0F,$0F,$0F,$FF
_pal8:
		.BYTE $3F,$00,$20,$0F,$30,$16,$0F,$0F,$39,$1A,$0F,$0F,$30,$38,$0F,$0F
		.BYTE $30,$35,$16,$0F,$30,$16,$0F,$0F,$39,$1A,$0F,$0F,$30,$38,$0F,$0F
		.BYTE $30,$35,$16,$FF

; =============== S U B	R O U T	I N E =======================================
_read_pads:
		LDX		#$01
		STX		_PAD0_REG
		DEX
		TXA
		STA		_PAD0_REG
		JSR		_read_pad
		INX

; =============== S U B	R O U T	I N E =======================================
_read_pad:
		LDY		#$08
loc_9B42:
		PHA
		LDA		_PAD0_REG,X
		STA		word_10
		LSR
		ORA		word_10
		LSR
		PLA
		ROL
		DEY
		BNE		loc_9B42
		STA		_pads_raw,X
		RTS

; =============== S U B	R O U T	I N E =======================================
_calc_pads:
		LDX		#$00
		JSR		_calc_pad
		INX

; =============== S U B	R O U T	I N E =======================================
_calc_pad:
		LDA		_pads_raw,X
		LDY		_pads_held,X
		STY		word_10
		CMP		_pad_tmp0,X
		BNE		loc_9B73
		INC		_pad_tmp1,X
		LDY		_pad_tmp1,X
		CPY		#$03
		BCC		loc_9B79
		STA		_pads_tmp4,X
		JMP		loc_9B75
; ---------------------------------------------------------------------------
loc_9B73:
		STA		_pad_tmp0,X
loc_9B75:
		LDA		#$00
		STA		_pad_tmp1,X
loc_9B79:
		LDA		_pads_tmp4,X
		STA		_pads_held,X
		EOR		word_10
		AND		_pads_held,X
		STA		_pads_press,X
		STA		_pad_tmp2,X
		LDY		#$18
		LDA		_pads_held,X
		CMP		word_10
		BNE		loc_9B95
		DEC		_pad_tmp3,X
		BNE		locret_9B97
		STA		_pad_tmp2,X
		LDY		#$08
loc_9B95:
		STY		_pad_tmp3,X
locret_9B97:
		RTS

; =============== S U B	R O U T	I N E =======================================
_nmi_tlm_libB_send:
		LDY		byte_32
		BEQ		locret_9BB4
		DEY
		LDA		off_9BB5,Y
		STA		word_10
		LDA		off_9BBC,Y
		STA		word_10+1
		JSR		_ppu_tlm_unpack_ex
		LDA		#$00
		STA		_tlm_ramB1_buf
		STA		_nmi_tlmB1_ram
		STA		byte_32
locret_9BB4:
		RTS
; ---------------------------------------------------------------------------
off_9BB5:
		.BYTE <[_nmi_tlmB1_ram]
		.BYTE <[_nmi_tlmB2_ram]
		.BYTE <[_nmi_tlmB3]
		.BYTE <[_nmi_tlmB4]
		.BYTE <[_nmi_tlmB5]
		.BYTE <[_nmi_tlmB6]
off_9BBC:
		.BYTE >[_nmi_tlmB1_ram]
		.BYTE >[_nmi_tlmB2_ram]
		.BYTE >[_nmi_tlmB3]
		.BYTE >[_nmi_tlmB4]
		.BYTE >[_nmi_tlmB5]
		.BYTE >[_nmi_tlmB6]
_nmi_tlmB3:
		.WORD $EE21
		.BYTE $02
		.BYTE $63,$64
		.WORD $0E22
		.BYTE $02
		.BYTE $63,$64
		.BYTE $FF
_nmi_tlmB4:
		.WORD $C823
		.BYTE $07
		.BYTE $AA,$22,$AA,$88,$88,$22,$AA
		.WORD $D023
		.BYTE $07
		.BYTE $AA,$22,$AA,$88,$88,$22,$AA
		.WORD $E823
		.BYTE $07
		.BYTE $AA,$22,$AA,$88,$88,$22,$AA
		.WORD $F023
		.BYTE $07
		.BYTE $AA,$22,$AA,$88,$88,$22,$AA
		.BYTE $FF
_nmi_tlmB5:
		.WORD $C823
		.BYTE $07
		.BYTE $AA,$88,$22,$AA,$22,$AA,$88
		.WORD $D023
		.BYTE $07
		.BYTE $AA,$88,$22,$AA,$22,$AA,$88
		.WORD $E823
		.BYTE $07
		.BYTE $AA,$88,$22,$AA,$22,$AA,$88
		.WORD $F023
		.BYTE $07
		.BYTE $AA,$88,$22,$AA,$22,$AA,$88
		.BYTE $FF
_nmi_tlmB6:
		.WORD $C823
		.BYTE $07
		.BYTE $22,$AA,$88,$AA,$AA,$88,$22
		.WORD $D023
		.BYTE $07
		.BYTE $22,$AA,$88,$AA,$AA,$88,$22
		.WORD $E823
		.BYTE $07
		.BYTE $22,$AA,$88,$AA,$AA,$88,$22
		.WORD $F023
		.BYTE $07
		.BYTE $22,$AA,$88,$AA,$AA,$88,$22
		.BYTE $FF

; =============== S U B	R O U T	I N E =======================================
_nmi_ppu_dequeue:
		LDA		_ppu_queue_req
		BEQ		locret_9C08
		LDA		#<[_ppu_queue_buf]
		STA		word_10
		LDA		#>[_ppu_queue_buf]
		STA		word_10+1
		LDA		_ppu_ctrl_shadow
		ORA		#$04
		STA		_PPU_CTRL
		STA		_ppu_ctrl_shadow
		LDX		_PPU_STATUS
		LDY		#$00
		BEQ		loc_9BF9
loc_9BE0:
		STA		$2006
		INY
		LDA		(word_10),Y
		STA		$2006
		INY
		LDA		(word_10),Y
		AND		#$3F
		TAX
loc_9BEF:
		INY
		LDA		(word_10),Y
		STA		$2007
		DEX
		BNE		loc_9BEF
		INY
loc_9BF9:
		LDA		(word_10),Y
		BNE		loc_9BE0
		LDA		#$00
		STA		_ppu_queue_buf_pos
		STA		_ppu_queue_buf
		STA		_ppu_queue_req
locret_9C08:
		RTS

; =============== S U B	R O U T	I N E =======================================
_switch:
		ASL
		TAY
		INY
		PLA
		STA		_tmp20w
		PLA
		STA		_tmp20w+1
		LDA		(_tmp20w),Y
		TAX
		INY
		LDA		(_tmp20w),Y
		STA		_tmp20w+1
		STX		_tmp20w
		JMP		(_tmp20w)

; =============== S U B	R O U T	I N E =======================================
_ppu_tlm_unpack:
		STX		word_10
		STY		word_10+1
		JMP		_ppu_tlm_unpack_ex

; =============== S U B	R O U T	I N E =======================================
_ppu_tlm_unpack_loop:
		STA		$2006
		INY
		LDA		(word_10),Y
		STA		$2006
		INY
		LDA		(word_10),Y
		ASL
		PHA
		LDA		_ppu_ctrl_shadow
		ORA		#$04
		BCS		loc_9C3C
		AND		#$FB
loc_9C3C:
		STA		_PPU_CTRL
		STA		_ppu_ctrl_shadow
		PLA
		ASL
		BCC		loc_9C48
		ORA		#$02
		INY
loc_9C48:
		LSR
		LSR
		TAX
loc_9C4B:
		BCS		loc_9C4E
		INY
loc_9C4E:
		LDA		(word_10),Y
		STA		$2007
		DEX
		BNE		loc_9C4B
		SEC
		TYA
		ADC		word_10
		STA		word_10
		LDA		#$00
		ADC		word_10+1
		STA		word_10+1

; =============== S U B	R O U T	I N E =======================================
_ppu_tlm_unpack_ex:
		LDX		_PPU_STATUS
		LDY		#$00
		LDA		(word_10),Y
		CMP		#$FF
		BNE		_ppu_tlm_unpack_loop

; =============== S U B	R O U T	I N E =======================================
sub_9C6D:
		PHA
		LDA		byte_FA
		STA		$4025
		LDA		byte_FD
		STA		$2005
		LDA		byte_FC
		STA		$2005
		PLA
		RTS

; =============== S U B	R O U T	I N E =======================================
;sub_9C7F:
;		STA		byte_FA
;		STA		$4025
;		STA		byte_FA
;		RTS

; =============== S U B	R O U T	I N E =======================================
_increment_rand_seed:
		LDA		_rand_seed
		CLC
		ADC		#$0F
		STA		_rand_seed
		LDA		_rand_seed
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_9C94:
		INC		byte_600
		LDA		byte_600
		CMP		#$37
		BCC		loc_9CA6
		JSR		_randB
		LDA		#$00
		STA		byte_600
loc_9CA6:
		TAY
		LDA		byte_600+1,Y
		RTS

; =============== S U B	R O U T	I N E =======================================
_randA:
		LDA		_rand_seed
		AND		#$1F
		STA		word_10
		STA		byte_600+$37
		LDA		#$01
		STA		word_10+1
		LDY		#$14
		LDX		#$36
loc_9CBD:
		LDA		word_10+1
		STA		byte_600+1,Y
		LDA		word_10
		SEC
		SBC		word_10+1
		BPL		loc_9CCC
		CLC
		ADC		#$B4
loc_9CCC:
		STA		word_10+1
		LDA		byte_600+1,Y
		STA		word_10
		TYA
		CLC
		ADC		#$15
		CMP		#$37
		BCC		loc_9CDD
		SBC		#$37
loc_9CDD:
		TAY
		DEX
		BNE		loc_9CBD
		JSR		_randB
		JSR		_randB

; =============== S U B	R O U T	I N E =======================================
_randB:
		LDY		#$00
loc_9CE9:
		TYA
		STA		word_10
		CMP		#$18
		BCS		loc_9CF4
		ADC		#$1F
		BCC		loc_9CF6
loc_9CF4:
		SBC		#$18
loc_9CF6:
		TAY
		LDA		byte_600+1,Y
		STA		word_10+1
		LDY		word_10
		LDA		byte_600+1,Y
		SEC
		SBC		word_10+1
		BCS		loc_9D08
		ADC		#$B4
loc_9D08:
		STA		byte_600+1,Y
		INY
		CPY		#$37
		BNE		loc_9CE9
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_9D1E:
		STX		_ppu_queue_buf_pos
		LDA		#$00
		STA		_ppu_queue_buf,X
		LDA		#$01
		STA		_ppu_queue_req
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_9D40:
		STA		_ppu_queue_buf,X
		INX
		TXA
		CMP		#$55
		BCC		locret_9D53
		LDX		_ppu_queue_buf_pos
		LDA		#$00
		STA		_ppu_queue_buf,X
		PLA
		PLA
locret_9D53:
		RTS

; =============== S U B	R O U T	I N E =======================================
_main_programm_load:
		LDA		#$00
		JSR		_chr_load
		LDA		#$00
		JSR		_unrom_prg_set
		LDA		#$00
		STA		_main_sub_idx
		STA		_main00_sub_idx
		STA		byte_567
		STA		byte_568
		STA		_main02_sub_idx
		RTS

; =============== S U B	R O U T	I N E =======================================
_ending_screen:
		LDY		#$00
		STY		_main_sub_idx
		STY		_main00_sub_idx
		STY		_ending_sub_idx
		INY
		JSR		_pal_fade_outB
		LDA		#$02
		JSR		_chr_load
		JSR		_ending
		LDA		#$00

; =============== S U B	R O U T	I N E =======================================
_chr_load:
		STA		_chr_data_idx
		LDA		_cur_prg_bank
		PHA
		LDA		#$02
		JSR		_unrom_prg_set
		LDX		_chr_data_idx
		LDA		_chr_data_list_lo,X
		STA		_tmp20w
		LDA		_chr_data_list_hi,X
		STA		_tmp20w+1
		LDA		_chr_ofs_list,X
		TAY
		LDA		_chr_size_list,X
		TAX
		JSR		_chr_copy
		PLA
		JMP		_unrom_prg_set

_chr_data_list_lo:
		.BYTE <[_chr00]
		.BYTE <[_chr10]
		.BYTE <[_chr30]
		.BYTE <[_chr20]
		.BYTE <[_chr00+$1700]
_chr_data_list_hi:
		.BYTE >[_chr00]
		.BYTE >[_chr10]
		.BYTE >[_chr30]
		.BYTE >[_chr20]
		.BYTE >[_chr00+$1700]
_chr_ofs_list:
		.BYTE $00
		.BYTE $17
		.BYTE $14
		.BYTE $1B
		.BYTE $17
_chr_size_list:
		.BYTE $17
		.BYTE $09
		.BYTE $06
		.BYTE $05
		.BYTE $09

; =============== S U B	R O U T	I N E =======================================
_chr_copy:
		STY		$2006
		LDA		#$00
		STA		$2006
		LDY		#$00
.1:
		LDA		(_tmp20w),Y
		STA		$2007
		INY
		BNE		.1
		INC		_tmp20w+1
		DEX
		BNE		.1
		RTS

; =============== S U B	R O U T	I N E =======================================
_pal_fade_outA:
		STY		byte_553
		LDA		#$07
		STA		_nmi_tlm_lib_idx
		JSR		_ppu_render_on
		LDA		#$04
		STA		_tmp_idx
		LDA		#$40
		STA		byte_4D
loc_A152:
		JSR		_pal_buf4_load_lib
		LDA		byte_4D
		SEC
		SBC		#$10
		STA		byte_4D
		JSR		_pal_buf_dec
		JSR		_pal_buf_flush
		DEC		_tmp_idx
		BNE		loc_A152
		JSR		_pal_buf4_load_lib
		JMP		_pal_buf_flush

; =============== S U B	R O U T	I N E =======================================
_pal_fade_outB:
		STY		byte_553
		JSR		_pal_buf4_load_lib
		LDA		#$04
		STA		_tmp_idx
loc_A176:
		LDA		#$10
		JSR		_pal_buf_dec
		JSR		_pal_buf_flush
		DEC		_tmp_idx
		BNE		loc_A176
		JMP		_ppu_render_off

; =============== S U B	R O U T	I N E =======================================
_pal_buf4_load_lib:
		LDA		#$3F
		STA		_pal_buf4
		LDA		#$00
		STA		_pal_buf4+1
		LDA		#$20
		STA		_pal_buf4+2
		LDA		#$FF
		STA		byte_59F
		LDY		byte_553
		DEY
		LDA		_nmi_tlm_lib_hi,Y
		STA		_tmp20w+1
		LDA		_nmi_tlm_lib_lo,Y
		STA		_tmp20w
		LDY		#$22
loc_A1A9:
		LDA		(_tmp20w),Y
		STA		_pal_buf4,Y
		DEY
		CPY		#$02
		BNE		loc_A1A9
		RTS

; =============== S U B	R O U T	I N E =======================================
_pal_buf_dec:
		STA		byte_57
		LDY		#$1F
loc_A1B8:
		LDA		_pal_buf4+3,Y
		SEC
		SBC		byte_57
		BCS		loc_A1C2
		LDA		#$0F
loc_A1C2:
		STA		_pal_buf4+3,Y
		DEY
		BPL		loc_A1B8
		RTS

; =============== S U B	R O U T	I N E =======================================
_pal_buf_flush:
		LDY		#$04
		STY		_nmi_tlm_lib_idx
		LDA		#$05
		JSR		_wait_for_nmi
		RTS

; =============== S U B	R O U T	I N E =======================================
_wait_for_70_frames:
		LDA		#$46

; =============== S U B	R O U T	I N E =======================================
_wait_for_nmi:
		STA		_nmi_counter
loc_A1D7:
		JSR		_sync
		LDA		_nmi_counter
		BNE		loc_A1D7
		RTS

; =============== S U B	R O U T	I N E =======================================
_div16:
		LDA		#$00
		STA		byte_5B
		STA		byte_5C
		LDX		#$08
loc_A1E7:
		LSR		byte_59
		BCC		loc_A1F2
		LDA		byte_5A
		CLC
		ADC		byte_5B
		STA		byte_5B
loc_A1F2:
		ROR		byte_5B
		ROR		byte_5C
		DEX
		BNE		loc_A1E7
		RTS

; =============== S U B	R O U T	I N E =======================================
_mul8:
		LDA		#$00
		STA		byte_59
		LDX		#$09
		CLC
loc_A201:
		ROL		byte_5A
		DEX
		BEQ		locret_A214
		ROL		byte_59
		LDA		byte_59
		SEC
		SBC		byte_5B
		BCC		loc_A201
		STA		byte_59
		JMP		loc_A201
locret_A214:
		RTS

; =============== S U B	R O U T	I N E =======================================
_mul16:
		LDA		#$00
		STA		byte_59
		STA		byte_5A
		LDX		#$11
		CLC
loc_A21E:
		ROL		byte_5C
		ROL		byte_5B
		DEX
		BEQ		locret_A23E
		ROL		byte_5A
		ROL		byte_59
		LDA		byte_5A
		SEC
		SBC		byte_5A5
		TAY
		LDA		byte_59
		SBC		byte_5A4
		BCC		loc_A21E
		STA		byte_59
		STY		byte_5A
		JMP		loc_A21E
locret_A23E:
		RTS

; =============== S U B	R O U T	I N E =======================================
_unrom_prg_set:
		TAX
		STA		_cur_prg_bank
		STA		_unrom_prg_cmd,X
		RTS
_unrom_prg_cmd:
		.BYTE $00,$01,$02,$03

; =============== S U B	R O U T	I N E =======================================
_apu_play_ctrlA_set01:
		LDA		#$01
		BNE		_apu_play_ctrlA_set_ex

; =============== S U B	R O U T	I N E =======================================
_apu_play_ctrlA_set02:
		LDA		#$02
		BNE		_apu_play_ctrlA_set_ex

; =============== S U B	R O U T	I N E =======================================
_apu_play_ctrlA_set04:
		LDA		#$04
		BNE		_apu_play_ctrlA_set_ex

; =============== S U B	R O U T	I N E =======================================
_apu_play_ctrlA_set10:
		LDA		#$10
		BNE		_apu_play_ctrlA_set_ex

; =============== S U B	R O U T	I N E =======================================
_apu_play_ctrlA_set02_0:
		LDA		#$20
		BNE		_apu_play_ctrlA_set_ex

; =============== S U B	R O U T	I N E =======================================
_apu_play_ctrlA_set40:
		LDA		#$40
		BNE		_apu_play_ctrlA_set_ex

; =============== S U B	R O U T	I N E =======================================
_apu_play_ctrlA_set80:
		LDA		#$80

; =============== S U B	R O U T	I N E =======================================
_apu_play_ctrlA_set_ex:
		STA		_apu_play_ctrlA
		RTS

; =============== S U B	R O U T	I N E =======================================
_apu_play_ctrlB_set01:
		LDA		#$01
		BNE		_apu_play_ctrlB_set_ex

; =============== S U B	R O U T	I N E =======================================
_apu_play_ctrlB_set02:
		LDA		#$02
		BNE		_apu_play_ctrlB_set_ex

; =============== S U B	R O U T	I N E =======================================
_apu_play_ctrlB_set04:
		LDA		#$04
		BNE		_apu_play_ctrlB_set_ex

; =============== S U B	R O U T	I N E =======================================
_apu_play_ctrlB_set08:
		LDA		#$08
		BNE		_apu_play_ctrlB_set_ex

; =============== S U B	R O U T	I N E =======================================
_apu_play_ctrlB_set10:
		LDA		#$10
		BNE		_apu_play_ctrlB_set_ex

; =============== S U B	R O U T	I N E =======================================
_apu_play_ctrlB_set20:
		LDA		#$20
		BNE		_apu_play_ctrlB_set_ex

; =============== S U B	R O U T	I N E =======================================
_apu_play_ctrlB_set40:
		LDA		#$40
		BNE		_apu_play_ctrlB_set_ex

; =============== S U B	R O U T	I N E =======================================
_apu_play_ctrlB_set80:
		LDA		#$80

; =============== S U B	R O U T	I N E =======================================
_apu_play_ctrlB_set_ex:
		STA		_apu_play_ctrlB
		RTS

; =============== S U B	R O U T	I N E =======================================
_apu_play_ctrlC_set01:
		LDA		#$01
		BNE		_apu_play_ctrlC_set_ex

; =============== S U B	R O U T	I N E =======================================
_apu_play_ctrlC_set02:
		LDA		#$02
		BNE		_apu_play_ctrlC_set_ex

; =============== S U B	R O U T	I N E =======================================
_apu_play_ctrlC_set40:
		LDA		#$40
		BNE		_apu_play_ctrlC_set_ex

; =============== S U B	R O U T	I N E =======================================
_apu_play_ctrlC_set80:
		LDA		#$80

; =============== S U B	R O U T	I N E =======================================
_apu_play_ctrlC_set_ex:
		STA		_apu_play_ctrlC
		RTS

; =============== S U B	R O U T	I N E =======================================
_apu_play_ctrlD_set01:
		LDA		#$01
		BNE		_apu_play_ctrlD_set_ex

; =============== S U B	R O U T	I N E =======================================
_apu_play_ctrlD_set02:
		LDA		#$02
		BNE		_apu_play_ctrlD_set_ex

; =============== S U B	R O U T	I N E =======================================
_apu_play_ctrlD_set04:
		LDA		#$04
		BNE		_apu_play_ctrlD_set_ex

; =============== S U B	R O U T	I N E =======================================
_apu_play_ctrlD_set08:
		LDA		#$08
		BNE		_apu_play_ctrlD_set_ex

; =============== S U B	R O U T	I N E =======================================
_apu_play_ctrlD_set10:
		LDA		#$10
		BNE		_apu_play_ctrlD_set_ex

; =============== S U B	R O U T	I N E =======================================
_apu_play_ctrlD_set20:
		LDA		#$20
		BNE		_apu_play_ctrlD_set_ex

; =============== S U B	R O U T	I N E =======================================
_apu_play_ctrlD_set40:
		LDA		#$40
		BNE		_apu_play_ctrlD_set_ex

; =============== S U B	R O U T	I N E =======================================
_apu_play_ctrlD_set80:
		LDA		#$80

; =============== S U B	R O U T	I N E =======================================
_apu_play_ctrlD_set_ex:
		STA		_apu_play_ctrlD
		RTS

; =============== S U B	R O U T	I N E =======================================
_apu_play_ctrlE_set01:
		LDA		#$01
		BNE		_apu_play_ctrlE_set_ex

; =============== S U B	R O U T	I N E =======================================
_apu_play_ctrlE_set02:
		LDA		#$02
		BNE		_apu_play_ctrlE_set_ex

; =============== S U B	R O U T	I N E =======================================
_apu_play_ctrlE_set04:
		LDA		#$04
		BNE		_apu_play_ctrlE_set_ex

; =============== S U B	R O U T	I N E =======================================
_apu_play_ctrlE_set08:
		LDA		#$08
		BNE		_apu_play_ctrlE_set_ex

; =============== S U B	R O U T	I N E =======================================
_apu_play_ctrlE_set10:
		LDA		#$10
		BNE		_apu_play_ctrlE_set_ex

; =============== S U B	R O U T	I N E =======================================
_apu_play_ctrlE_set20:
		LDA		#$20

; =============== S U B	R O U T	I N E =======================================
_apu_play_ctrlE_set_ex:
		STA		_apu_play_ctrlE
		RTS
