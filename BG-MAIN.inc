
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
		LDA		#$2F
		JSR		sub_9C7F
		LDA		#$00
		STA		_main_sub_idx
		STA		_main00_sub_idx
		STA		byte_567
		STA		_main02_sub_idx

; !FALLTHROUGH!

; =============== S U B	R O U T	I N E =======================================
_MAIN:
		JSR		_main_subA_dice_roll_editor
		JSR		_main_sub_exec
		JSR		_main_subC
		JSR		_main_subD
		JSR		_sync
		BEQ		_MAIN

; =============== S U B	R O U T	I N E =======================================
_main_subA_dice_roll_editor:
		LDA		_ingame_sub_idx
		BNE		locret_7066
		LDA		_cheat_flag1_w
		BEQ		locret_7066
		LDY		_cur_player_idx
		LDA		_pads_held,Y
		CMP		#$85
		BNE		locret_7066
		LDA		#$06
		STA		_1p_first_dice_roll_override
		STA		_2p_first_dice_roll_override
loc_701A:
		JSR		_main_subD
		JSR		sub_9202
		JSR		_sync
		LDY		_cur_player_idx
		LDA		_pads_press,Y
		TAX
		AND		#$C0
		BNE		sub_7057
		TXA
		LDX		#$00
		CMP		#$01
		BEQ		loc_7041
		INX
		CMP		#$04
		BEQ		loc_7041
		CMP		#$02
		BNE		loc_701A
		JSR		sub_7047
		DEX
loc_7041:
		JSR		sub_7047
		JMP		loc_701A

; =============== S U B	R O U T	I N E =======================================
sub_7047:
		INC		_1p_first_dice_roll_override,X
		LDA		_1p_first_dice_roll_override,X
		CMP		#$07
		BCC		locret_7056
		LDA		#$01
		STA		_1p_first_dice_roll_override,X
locret_7056:
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_7057:
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
		.WORD $0000; _j_demo
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
		LDA		#$2F
		JSR		sub_9C7F
		LDA		#$20
		LDX		#$2F
		LDY		#$00
		JSR		_ppu_fill_ex
		JSR		_spr_clear
		LDA		#$01
		STA		_nmi_disable_flush
		LDX		#<[_tlm_title]
		LDY		#>[_tlm_title]
		JSR		_ppu_tlm_unpack
loc_A294:
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
		STY		_tpp_idx
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
		LDA		byte_A343,Y
		STA		_ppu_pal_buf4+4
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
loc_A308:
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
byte_A343:
		.BYTE $3C,$3B,$3A,$39,$38,$37,$36,$35,$34,$33,$32,$31
_txt_push_start:
		.BYTE $0E
		.WORD $4B23
		.BYTE $0A
		.BYTE $20,$25,$23,$18,$2F,$23,$24,$11,$22,$24
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
		LDY		_tpp_idx
		CMP		(_tmp20w),Y
		BNE		loc_A376
		INC		_tpp_idx
		CPY		#$07
		BCS		loc_A377
loc_A374:
		CLC
		RTS
; ---------------------------------------------------------------------------
loc_A376:
		CLC
loc_A377:
		LDA		#$00
		STA		_tpp_idx
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
		LDA		#$2F
		JSR		sub_9C7F
		LDA		#$20
		LDX		#$2F
		LDY		#$00
		JSR		_ppu_fill_ex
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
		STA		_cheat_flag1_w
loc_A3DD:
		LDY		_menu_pos_idx_w
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
		STY		_menu_pos_idx_w
		STY		_game_mode_idx
		JSR		_apu_play_ctrlB_set02
		LDA		_cheat_flag1_w
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
		LDA		#$00
		STA		_load_file_list_idx
		JSR		_file_load
;		LDA		#$70
;		STA		_overlay_loaded_flag_w
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
		LDA		byte_A490,Y
		STA		_spr_buf
		LDA		#$FE
		STA		_spr_buf+1
		LDA		#$00
		STA		_spr_buf+2
		LDA		#$34
		STA		_spr_buf+3
		STY		_menu_pos_idx_w
		RTS
; ---------------------------------------------------------------------------
byte_A490:
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
; ---------------------------------------------------------------------------
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

; =============== S U B	R O U T	I N E =======================================
_main00_sub06_match_menu_input:
		LDY		_match_pts_w
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
		LDA		byte_A546,Y
		STA		byte_560
		LDA		byte_A549,Y
		STA		byte_561
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
		LDA		byte_A543,Y
		STA		_spr_buf+4
		LDA		#$FE
		STA		_spr_buf+5
		LDA		#$00
		STA		_spr_buf+6
		LDA		#$48
		STA		_spr_buf+7
		STY		_match_pts_w
		RTS
; ---------------------------------------------------------------------------
byte_A543:
		.BYTE $87,$97,$A7
byte_A546:
		.BYTE $05,$0B,$99
byte_A549:
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
; ---------------------------------------------------------------------------
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
_common_program_reload:
		LDA		#$01
		STA		_load_file_list_idx
		JSR		_file_load
		LDA		#$00
		STA		_main_sub_idx
		STA		_main00_sub_idx
		STA		byte_568
		RTS

; =============== S U B	R O U T	I N E =======================================
_set_field_pal:
		TYA
		ASL
		ASL
		TAY
		LDA		_field_pal_patch_lib,Y
		STA		_pal1_pw
		STA		_pal1_pw+4
		STA		_pal1_pw+8
		STA		_pal1_pw+$C
		STA		_pal1_pw+$10
		STA		_pal1_pw+$14
		STA		_pal1_pw+$18
		STA		_pal1_pw+$1C
		STA		_pal2_p0_w
		STA		_pal2_p1_w
		STA		_pal3_p0_w
		STA		_pal3_p1_w
		LDA		_field_pal_patch_lib+1,Y
		STA		_pal1_pw+5
		STA		_pal1_pw+$D
		STA		_pal1_pw+$1D
		STA		_pal2_p1_w+1
		STA		_pal3_p1_w+1
		LDA		_field_pal_patch_lib+2,Y
		STA		_pal1_pw+2
		STA		_pal1_pw+6
		LDA		_field_pal_patch_lib+3,Y
		STA		_pal1_pw+$A
		STA		_pal1_pw+$E
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
_main_subC:
		LDA		byte_32
		ORA		_ppu_queue_req
		ORA		_nmi_tlm_lib_idx
		ORA		byte_62
		ORA		byte_577
		BEQ		loc_A061
locret_A060:
		RTS
; ---------------------------------------------------------------------------
loc_A061:
		LDY		byte_55C
		BEQ		locret_A060
		DEY
		LDA		off_A079,Y
		STA		_tmp20w+1
		LDA		off_A07F,Y
		STA		_tmp20w
		LDA		#$00
		STA		byte_55C
		JMP		sub_A0E5
; ---------------------------------------------------------------------------
off_A079:
		.BYTE >[byte_A085]
		.BYTE >[byte_A095]
		.BYTE >[byte_A0A5]
		.BYTE >[byte_A0B5]
		.BYTE >[byte_A0C5]
		.BYTE >[byte_A0D5]
off_A07F:
		.BYTE <[byte_A085]
		.BYTE <[byte_A095]
		.BYTE <[byte_A0A5]
		.BYTE <[byte_A0B5]
		.BYTE <[byte_A0C5]
		.BYTE <[byte_A0D5]
byte_A085:
		.BYTE $22,$23,$23,$20,$23,$23,$23,$23,$02,$E2,$E2,$22,$E2,$E2,$E2,$E2
byte_A095:
		.BYTE $23,$23,$22,$22,$22,$22,$20,$20,$E2,$E2,$C2,$C2,$C2,$C2,$C2,$C2
byte_A0A5:
		.BYTE $22,$23,$23,$22,$23,$23,$23,$23,$22,$E2,$E2,$22,$E2,$E2,$E2,$E2
byte_A0B5:
		.BYTE $22,$22,$22,$22,$2E,$2E,$2F,$2F,$4A,$7A,$7A,$42,$7A,$7A,$7A,$7A
byte_A0C5:
		.BYTE $21,$2F,$2F,$21,$2F,$2F,$2F,$2F,$42,$7A,$7A,$0A,$7A,$7A,$7A,$7A
byte_A0D5:
		.BYTE $29,$2F,$2F,$28,$2F,$2F,$2F,$2F,$7A,$7A,$52,$52,$52,$52,$12,$12

; =============== S U B	R O U T	I N E =======================================
sub_A0E5:
		LDX		#$00
		STX		byte_57
loc_A0E9:
		LDY		byte_57
		CPY		#$04
		BEQ		locret_A112
		LDA		#$00
		STA		_tmp1Cw+1
		LDA		byte_A113,Y
		STA		_tmp1Cw
		LDA		byte_A117,Y
		TAY
		JSR		sub_A11B
		LDY		byte_57
		LDA		_tmp20w
		CLC
		ADC		byte_A117,Y
		BCC		loc_A10B
		INC		_tmp20w+1
loc_A10B:
		STA		_tmp20w
		INC		byte_57
		JMP		loc_A0E9
; ---------------------------------------------------------------------------
locret_A112:
		RTS
; ---------------------------------------------------------------------------
byte_A113:
		.BYTE $0A,$18,$2A,$38
byte_A117:
		.BYTE $06,$02,$06,$02

; =============== S U B	R O U T	I N E =======================================
sub_A11B:
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

; =============== S U B	R O U T	I N E =======================================
_main02_game:
		LDA		_main02_sub_idx
		JSR		_switch
; ---------------------------------------------------------------------------
		.WORD _main02_sub00_game_init
		.WORD _main02_sub01
		.WORD _main02_sub02
		.WORD _main02_sub03
		.WORD _main02_sub04_ingame
		.WORD _main02_sub05_player_gets_x_points_draw
		.WORD _main02_sub06
		.WORD _main02_sub07
		.WORD _main02_sub08_draw_winner
		.WORD _main02_sub09_win_animate
		.WORD _main02_sub0A_stage_complete
		.WORD _main02_sub0A_stage_complete
		.WORD _main02_sub0C_tournament_name
		.WORD _main02_sub0D_delay

; =============== S U B	R O U T	I N E =======================================
_main02_sub00_game_init:
		LDY		_game_mode_idx
		CPY		#$01
		BEQ		loc_63E9
		LDY		#$00
loc_63E9:
		STY		_training_mode_flag
		LDY		#$00
		STY		byte_FD
		STY		byte_3C
		STY		byte_3D
		STY		byte_3E
		STY		byte_3F
		STY		_match_idx
		STY		byte_555
		STY		byte_5B1
		STY		byte_5B2
		INC		_main02_sub_idx
		LDA		_game_mode_idx
		CMP		#$03
		BNE		locret_643F
		LDA		_cheat_flag1_w
		BEQ		loc_641B
		LDA		_pads_held+1
		AND		#$80
		BEQ		loc_641B
		JMP		_ending_screen
; ---------------------------------------------------------------------------
loc_641B:
		LDA		_pads_held+1
		AND		#$07
		BEQ		loc_643B
		LDY		#$01
		LDA		_pads_held+1
		AND		#$01
		BNE		loc_6438
		INY
		LDA		_pads_held+1
		AND		#$04
		BNE		loc_6438
		INY
		LDA		_pads_held+1
		AND		#$02
		BNE		loc_6438
		INY
loc_6438:
		STY		_match_idx
loc_643B:
		LDA		#$0C
		STA		_main02_sub_idx
locret_643F:
		RTS

; =============== S U B	R O U T	I N E =======================================
_main02_sub01:
		LDY		#$00
		LDA		_game_mode_idx
		BEQ		loc_647C
		INY
		CMP		#$01
		BEQ		loc_647C
		CMP		#$03
		BNE		loc_6466
		TAY
		LDA		byte_560
		CMP		#$05
		BEQ		loc_647C
		INY
		CMP		#$07
		BEQ		loc_647C
		INY
		CMP		#$0B
		BEQ		loc_647C
		INY
		JMP		loc_647C
; ---------------------------------------------------------------------------
loc_6466:
		LDY		#$09
		CMP		#$02
		BEQ		loc_646E
		LDY		#$0C
loc_646E:
		LDA		byte_554
		BNE		loc_647C
		DEY
		LDA		byte_560
		CMP		#$0B
		BEQ		loc_647C
		DEY
loc_647C:
		JSR		_set_field_pal
		JSR		_ppu_render_off
		LDA		#$27
		JSR		sub_9C7F
		LDA		#$04
		STA		byte_FC
		LDA		_ppu_ctrl_shadow
		AND		#$FC
		STA		_ppu_ctrl_shadow
		STA		_PPU_CTRL
		INC		_main02_sub_idx
		JMP		sub_9C6D

; =============== S U B	R O U T	I N E =======================================
_main02_sub02:
		JSR		_ppu_render_off
		LDA		#$01
		STA		_nmi_disable_flush
		JSR		_game_field_draw
		LDX		#<[_tlm_96A6]
		LDY		#>[_tlm_96A6]
		JSR		_ppu_tlm_unpack
		LDA		#$00
		STA		_nmi_disable_flush
		LDY		#$06
		STY		byte_557
		STY		byte_558
		LDA		_game_mode_idx
		CMP		#$01
		BEQ		loc_64C2
		LDA		byte_554
		BEQ		loc_64CD
loc_64C2:
		LDA		#$FF
		STA		byte_5B3
		STA		byte_5B4
		JMP		loc_6568
; ---------------------------------------------------------------------------
loc_64CD:
		LDA		byte_560
		SEC
		SBC		byte_3C
		STA		byte_57
		STA		byte_5B3
		LDA		byte_561
		SBC		byte_3D
		STA		byte_58
		JSR		sub_656F
		STY		byte_557
		LDA		byte_560
		SEC
		SBC		byte_3E
		STA		byte_57
		STA		byte_5B4
		LDA		byte_561
		SBC		byte_3F
		STA		byte_58
		JSR		sub_656F
		STY		byte_558
		LDA		byte_555
		BMI		loc_6568
		BNE		loc_6539
		LDA		byte_560
		SEC
		SBC		byte_3C
		STA		byte_57
		LDA		byte_561
		SBC		byte_3D
		BNE		loc_6517
		DEC		byte_57
		BEQ		loc_652A
loc_6517:
		LDA		byte_560
		SEC
		SBC		byte_3E
		STA		byte_57
		LDA		byte_561
		SBC		byte_3F
		BNE		loc_6539
		DEC		byte_57
		BNE		loc_6539
loc_652A:
		LDY		#$00
		STY		byte_557
		STY		byte_558
		INY
		STY		byte_555
		JMP		loc_6568
; ---------------------------------------------------------------------------
loc_6539:
		LDY		#$00
		STY		byte_5B1
		STY		byte_5B2
		LDA		byte_555
		BEQ		loc_6568
		INY
		LDA		byte_3E
		SEC
		SBC		byte_3C
		STA		byte_57
		LDA		byte_3F
		SBC		byte_3D
		BCS		loc_655A
		STY		byte_5B2
		JMP		loc_6563
; ---------------------------------------------------------------------------
loc_655A:
		BNE		loc_6560
		LDA		byte_57
		BEQ		loc_6563
loc_6560:
		STY		byte_5B1
loc_6563:
		LDA		#$FF
		STA		byte_555
loc_6568:
		INC		_main02_sub_idx
		LDA		#$14
		STA		_ingame_sub_idx
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_656F:
		LDY		#$06
		LDA		byte_58
		BNE		locret_6580
		LDA		byte_57
loc_6577:
		CMP		byte_6581,Y
		BCS		locret_6580
		DEY
		BPL		loc_6577
		INY
locret_6580:
		RTS
; ---------------------------------------------------------------------------
byte_6581:
		.BYTE $01,$02,$03,$05,$09,$11,$21

; =============== S U B	R O U T	I N E =======================================
_main02_sub03:
		LDA		_game_mode_idx
		CMP		#$01
		BEQ		loc_659D
		CMP		#$03
		BNE		loc_6599
		JSR		_apu_play_ctrlE_set01
		JMP		loc_65A6
; ---------------------------------------------------------------------------
loc_6599:
		CMP		#$04
		BNE		loc_65A3
loc_659D:
		JSR		_apu_play_ctrlD_set01
		JMP		loc_65A6
; ---------------------------------------------------------------------------
loc_65A3:
		JSR		_apu_play_ctrlD_set02
loc_65A6:
		LDY		#$FF
		STY		byte_302
		INY
		STY		_cur_player_idx
		STY		byte_309
		INY
		STY		byte_5D
		JSR		_pal_fade_outA
		LDA		#$03
		STA		byte_4D
		INC		_main02_sub_idx
loc_65BD:
		LDY		byte_4D
		LDA		byte_65D5,Y
		STA		_timer_minutes
		LDA		byte_65D1,Y
		STA		_tmp4Bb
		JSR		sub_65D9
		DEC		byte_4D
		BPL		loc_65BD
		RTS
; ---------------------------------------------------------------------------
byte_65D1:
		.BYTE $02,$05,$03,$05
byte_65D5:
		.BYTE $01,$13,$11,$0C

; =============== S U B	R O U T	I N E =======================================
sub_65D9:
		LDX		_timer_minutes
		INC		byte_3C0,X
		INC		byte_3E0,X
		JSR		sub_96C5
		LDA		_timer_minutes
		JSR		sub_77DA
		JSR		_sync
		LDA		#$19
		SEC
		SBC		_timer_minutes
		JSR		sub_77DA
		LDA		#$14
		LDY		byte_568
		BNE		loc_65FD
		LDA		#$05
loc_65FD:
		JSR		_wait_for_nmi
		DEC		_tmp4Bb
		BNE		sub_65D9
		RTS

; =============== S U B	R O U T	I N E =======================================
_main02_sub05_player_gets_x_points_draw:
		JSR		_apu_play_ctrlA_set04
		JSR		_wait_for_70_frames
		LDA		byte_31B
		LDY		byte_5D
		BEQ		loc_6619
		LDA		byte_31B
loc_6615:
		ASL
		DEY
		BNE		loc_6615
loc_6619:
		STA		byte_31C
;		LDY		#>[_tlm_patch_gets]
;		LDX		#<[_tlm_patch_gets]
;		CMP		#$01
;		BNE		loc_6628
;		LDY		#>[_tlm_patch_gets]
;		LDX		#<[_tlm_patch_gets]
;loc_6628:
;		STY		word_5A2
;		STX		word_5A2+1
		JSR		_spr_clear
		LDA		_cur_player_idx
		BNE		loc_664F
		LDA		_game_mode_idx
		CMP		#$02
		BCS		loc_6641
		JSR		_apu_play_ctrlD_set08
		BNE		loc_6667
loc_6641:
		CMP		#$03
		BNE		loc_664A
		JSR		_apu_play_ctrlE_set02
		BNE		loc_6667
loc_664A:
		JSR		_apu_play_ctrlD_set20
		BNE		loc_6667
loc_664F:
		LDA		_game_mode_idx
		CMP		#$02
		BCS		loc_665B
		JSR		_apu_play_ctrlD_set10
		BNE		loc_6667
loc_665B:
		CMP		#$03
		BNE		loc_6664
		JSR		_apu_play_ctrlE_set04
		BNE		loc_6667
loc_6664:
		JSR		_apu_play_ctrlD_set40
loc_6667:
		LDA		#$23
		STA		_nmi_tlmB1_ram
		LDA		#$C9
		STA		_nmi_tlmB1_ram+1
		LDA		#$05
		STA		_nmi_tlmB1_ram+2
		LDA		#$FF
		STA		_nmi_tlmB1_ram+8
		LDY		#$06
		LDX		#$04
loc_667F:
		LDA		byte_502,Y
		AND		#$0F
		ORA		#$A0
		STA		_nmi_tlmB1_ram-1,X
		DEY
		INX
		CPX		#$09
		BNE		loc_667F
		INC		byte_32
		JSR		_sync
		LDY		#>[_tlm_res_67D8]
		LDX		#<[_tlm_res_67D8]
		JSR		_tlm_B1_ram_queue
		JSR		_sync
		LDY		#>[_tlm_res_6012]
		LDX		#<[_tlm_res_6012]
		JSR		_tlm_B1_ram_queue
		LDA		byte_31B
		CMP		#$01
		BNE		loc_66B4
		LDY		#>[_tlm_patch_regular_win]
		LDA		#<[_tlm_patch_regular_win]
		LDX		#$14
		BNE		loc_66C6
loc_66B4:
		CMP		#$02
		BNE		loc_66C0
		LDY		#>[_tlm_patch_gammon]
		LDA		#<[_tlm_patch_gammon]
		LDX		#$12
		BNE		loc_66C6
loc_66C0:
		LDY		#>[_tlm_patch_backgammon]
		LDA		#<[_tlm_patch_backgammon]
		LDX		#$14
loc_66C6:
		JSR		_tlm_B1_ram_patch_queue
		JSR		_sync
		LDY		#>[_tlm_res_6044]
		LDX		#<[_tlm_res_6044]
		JSR		_tlm_B1_ram_queue
		LDA		_1p_cpu_ctrl_flag
		ASL
		ORA		_2p_cpu_ctrl_flag
		BNE		loc_6701
;		LDY		word_5A2
;		LDA		word_5A2+1
		LDY		#>[_tlm_patch_gets]
		LDX		#<[_tlm_patch_gets]
		LDX		#$21
		JSR		_tlm_B1_ram_patch_queue
		LDY		#>[_tlm_patch_player]
		LDA		#<[_tlm_patch_player]
		LDX		#$1A
		JSR		_tlm_B1_ram_patch_queue
		LDA		#$A5
		STA		_nmi_tlmB1_ram+$1B
		LDA		#$01
		LDY		_cur_player_idx
		BEQ		loc_66FB
		LDA		#$02
loc_66FB:
		STA		_nmi_tlmB1_ram+$1C
		JMP		loc_6740
; ---------------------------------------------------------------------------
loc_6701:
		CMP		#$01
		BNE		loc_672C
		LDA		_cur_player_idx
		BNE		loc_6716
		LDY		#>[_tlm_patch_player]
		LDA		#<[_tlm_patch_player]
		LDX		#$1A
		JSR		_tlm_B1_ram_patch_queue
		LDX		#$1F
		BNE		loc_6721
loc_6716:
		LDY		#>[_tlm_patch_computer]
		LDA		#<[_tlm_patch_computer]
		LDX		#$1C
		JSR		_tlm_B1_ram_patch_queue
		LDX		#$21
loc_6721:
;		LDY		word_5A2
;		LDA		word_5A2+1
		LDY		#>[_tlm_patch_gets]
		LDA		#<[_tlm_patch_gets]
		JSR		_tlm_B1_ram_patch_queue
		BEQ		loc_6740
loc_672C:
;		LDY		word_5A2
;		LDA		word_5A2+1
		LDY		#>[_tlm_patch_gets]
		LDA		#<[_tlm_patch_gets]
		LDX		#$21
		JSR		_tlm_B1_ram_patch_queue
		LDY		#>[_tlm_patch_computer]
		LDA		#<[_tlm_patch_computer]
		LDX		#$1C
		JSR		_tlm_B1_ram_patch_queue
loc_6740:
		JSR		_sync
		LDY		#>[_tlm_res_67F1]
		LDX		#<[_tlm_res_67F1]
		JSR		_tlm_B1_ram_queue
		JSR		_sync
		LDY		#>[_tlm_res_606E]
		LDX		#<[_tlm_res_606E]
		JSR		_tlm_B1_ram_queue
		LDA		#$00
		STA		byte_5B
		LDA		byte_31C
		STA		byte_5C
		LDA		#$00
		STA		byte_5A4
		LDA		#$64
		STA		byte_5A5
		JSR		_mul16
		LDA		byte_5C
		BNE		loc_6770
		LDA		#$2E
loc_6770:
		STA		_nmi_tlmB1_ram+$C
		LDA		#$0A
		STA		byte_5B
		JSR		_mul8
		LDA		byte_5A
		BNE		loc_6787
		LDY		_nmi_tlmB1_ram+$C
		CPY		#$2E
		BNE		loc_6787
		LDA		#$2E
loc_6787:
		STA		_nmi_tlmB1_ram+$D
		LDA		byte_59
		STA		_nmi_tlmB1_ram+$E
		LDA		byte_31C
		CMP		#$01
		BEQ		loc_679B
		LDA		#$23
		STA		_nmi_tlmB1_ram+$15
loc_679B:
		JSR		_sync
		LDY		#>[_tlm_res_6807]
		LDX		#<[_tlm_res_6807]
		JSR		_tlm_B1_ram_queue
		INC		_main02_sub_idx
		LDA		#$B4
		JMP		_wait_for_nmi

; =============== S U B	R O U T	I N E =======================================
_tlm_B1_ram_queue:
		STY		_tmp20w+1
		STX		_tmp20w
		LDY		#$00
		LDA		(_tmp20w),Y
		TAY
		LDA		#$FF
		STA		_tlm_ramB1_buf+1,Y
loc_67BA:
		LDA		(_tmp20w),Y
		STA		_tlm_ramB1_buf,Y
		DEY
		BNE		loc_67BA
		INC		byte_32
		RTS

; =============== S U B	R O U T	I N E =======================================
_tlm_B1_ram_patch_queue:
		STY		_tmp20w+1
		STA		_tmp20w
		LDY		#$00
		LDA		(_tmp20w),Y
		TAY
loc_67CE:
		LDA		(_tmp20w),Y
		STA		_nmi_tlmB1_ram,X
		DEX
		DEY
		BNE		loc_67CE
		RTS
; ---------------------------------------------------------------------------
_tlm_res_67D8:
		.BYTE $18
		.WORD $C420
		.BYTE $01
		.BYTE $0A
		.WORD $C520
		.BYTE $52
		.BYTE $0B
		.WORD $D720
		.BYTE $01
		.BYTE $0C
		.WORD $E420
		.BYTE $01
		.BYTE $10
		.WORD $E520
		.BYTE $52
		.BYTE $2E
		.WORD $F720
		.BYTE $01
		.BYTE $2D
_tlm_res_67F1:
		.BYTE $15
		.WORD $8421
		.BYTE $01
		.BYTE $10
		.WORD $8521
		.BYTE $52
		.BYTE $2E
		.WORD $9721
		.BYTE $01
		.BYTE $2D
		.WORD $D923
		.BYTE $06
		.BYTE $AA,$AA,$AA,$AA,$AA,$AA
_tlm_res_6807:
		.BYTE $18
		.WORD $C421
		.BYTE $01
		.BYTE $10
		.WORD $C521
		.BYTE $52
		.BYTE $2E
		.WORD $D721
		.BYTE $01
		.BYTE $2D
		.WORD $E421
		.BYTE $01
		.BYTE $0D
		.WORD $E521
		.BYTE $52
		.BYTE $0E
		.WORD $F721
		.BYTE $01
		.BYTE $0F
_tlm_patch_regular_win:
		.BYTE $0B
		.BYTE _R,_E,_G,_U,_L,_A,_R,__,_W,_I,_N
_tlm_patch_gammon:
		.BYTE $07
		.BYTE _G,_A,_M,_M,_O,_N,_ex
_tlm_patch_backgammon:
		.BYTE $0B
		.BYTE _B,_A,_C,_K,_G,_A,_M,_M,_O,_N,_ex
_tlm_patch_gets:
		.BYTE $04
		.BYTE _G,_E,_T,_S
_tlm_patch_player:
		.BYTE $06
		.BYTE _P,_L,_A,_Y,_E,_R
_tlm_patch_computer:
		.BYTE $08
		.BYTE _C,_O,_M,_P,_U,_T,_E,_R

; =============== S U B	R O U T	I N E =======================================
_main02_sub06:
		INC		_main02_sub_idx
		LDA		_game_mode_idx
		CMP		#$02
		BCS		loc_6870
		LDA		#$3C
		JSR		_wait_for_nmi
		LDY		#$01
		JSR		_pal_fade_outB
		INC		_main02_sub_idx
		RTS
; ---------------------------------------------------------------------------
loc_6870:
		LDA		_cur_player_idx
		ASL
		TAY
		LDA		byte_31C
		CLC
		ADC		byte_3C,Y
		STA		byte_3C,Y
		BCC		loc_6888
		LDA		#$00
		ADC		byte_3D,Y
		STA		byte_3D,Y
loc_6888:
		LDA		byte_3C,Y
		SEC
		SBC		#$E7
		LDA		byte_3D,Y
		SBC		#$03
		BCC		loc_689F
		LDA		#$E7
		STA		byte_3C,Y
		LDA		#$03
		STA		byte_3D,Y
loc_689F:
		LDY		#>[_tlm_res_frameA]
		LDX		#<[_tlm_res_frameA]
		JSR		_tlm_B1_ram_queue
		JSR		_sync
		LDY		#>[_tlm_res_6088]
		LDX		#<[_tlm_res_6088]
		JSR		_tlm_B1_ram_queue
		LDY		#>[_tlm_patch_matchB]
		LDA		#<[_tlm_patch_matchB]
		LDX		byte_554
		BEQ		loc_68CA
		LDX		#$12
		JSR		_tlm_B1_ram_patch_queue
		LDY		#>[_tlm_patch_endless]
		LDA		#<[_tlm_patch_endless]
		LDX		#$0C
		JSR		_tlm_B1_ram_patch_queue
		JMP		loc_68F4
; ---------------------------------------------------------------------------
loc_68CA:
		LDX		#$13
		JSR		_tlm_B1_ram_patch_queue
		LDY		#$2E
		LDX		#$05
		LDA		byte_560
		CMP		#$05
		BEQ		loc_68EE
		LDY		#$2E
		LDX		#$07
		CMP		#$07
		BEQ		loc_68EE
		LDY		#$01
		LDX		#$01
		CMP		#$0B
		BEQ		loc_68EE
		LDY		#$01
		LDX		#$05
loc_68EE:
		STY		_nmi_tlmB1_ram+5
		STX		_nmi_tlmB1_ram+6
loc_68F4:
		JSR		_sync
		LDY		#>[_tlm_res_60AC]
		LDX		#<[_tlm_res_60AC]
		JSR		_tlm_B1_ram_queue
		LDA		_1p_cpu_ctrl_flag
		ASL
		ORA		_2p_cpu_ctrl_flag
		BNE		loc_691A
		LDY		#>[_tlm_patch_player]
		LDA		#<[_tlm_patch_player]
		LDX		#$18
		JSR		_tlm_B1_ram_patch_queue
		LDA		#$A5
		STA		_nmi_tlmB1_ram+$19
		LDA		#$01
		STA		_nmi_tlmB1_ram+$1A
		BNE		loc_6932
loc_691A:
		CMP		#$01
		BNE		loc_6929
		LDY		#>[_tlm_patch_player]
		LDA		#<[_tlm_patch_player]
		LDX		#$19
		JSR		_tlm_B1_ram_patch_queue
		BEQ		loc_6932
loc_6929:
		LDY		#>[_tlm_patch_computer]
		LDA		#<[_tlm_patch_computer]
		LDX		#$18
		JSR		_tlm_B1_ram_patch_queue
loc_6932:
		LDA		byte_3C
		STA		byte_5C
		LDA		byte_3D
		STA		byte_5B
		JSR		sub_69D0
		JSR		_sync
		LDA		#$23
		STA		_nmi_tlmB1_ram
		LDA		#$E9
		STA		_nmi_tlmB1_ram+1
		LDA		#$06
		STA		_nmi_tlmB1_ram+2
		LDA		#$FF
		STA		_nmi_tlmB1_ram+9
		LDA		byte_50B
		AND		#$33
		ORA		#$88
		STA		_nmi_tlmB1_ram+3
		LDA		#$AA
		STA		_nmi_tlmB1_ram+4
		STA		_nmi_tlmB1_ram+5
		STA		_nmi_tlmB1_ram+6
		STA		_nmi_tlmB1_ram+7
		LDA		byte_510
		AND		#$CC
		ORA		#$22
loc_6973:
		STA		_nmi_tlmB1_ram+8
		INC		byte_32
		JSR		_sync
		LDY		#>[_tlm_res_60D0]
		LDX		#<[_tlm_res_60D0]
		JSR		_tlm_B1_ram_queue
		LDA		_1p_cpu_ctrl_flag
		ASL
		ORA		_2p_cpu_ctrl_flag
		BNE		loc_699E
		LDY		#>[_tlm_patch_player]
		LDA		#<[_tlm_patch_player]
		LDX		#$18
		JSR		_tlm_B1_ram_patch_queue
		LDA		#$A5
		STA		_nmi_tlmB1_ram+$19
		LDA		#$02
		STA		_nmi_tlmB1_ram+$1A
		BNE		loc_69B6
loc_699E:
		CMP		#$01
		BNE		loc_69AD
		LDY		#>[_tlm_patch_computer]
		LDA		#<[_tlm_patch_computer]
		LDX		#$1A
		JSR		_tlm_B1_ram_patch_queue
		BEQ		loc_69B6
loc_69AD:
		LDY		#>[_tlm_patch_computer]
		LDA		#<[_tlm_patch_computer]
		LDX		#$18
		JSR		_tlm_B1_ram_patch_queue
loc_69B6:
		LDA		byte_3E
		STA		byte_5C
		LDA		byte_3F
		STA		byte_5B
		JSR		sub_69D0
		JSR		_sync
		LDY		#>[_tlm_res_frameB]
		LDX		#<[_tlm_res_frameB]
		JSR		_tlm_B1_ram_queue
		LDA		#$B4
		JMP		_wait_for_nmi

; =============== S U B	R O U T	I N E =======================================
sub_69D0:
		LDA		#$00
		STA		byte_5A4
		LDA		#$64
		STA		byte_5A5
		JSR		_mul16
		LDA		byte_5C
		BNE		loc_69E3
		LDA		#$2E
loc_69E3:
		STA		_nmi_tlmB1_ram+$1C
		LDA		#$0A
		STA		byte_5B
		JSR		_mul8
		LDA		byte_5A
		BNE		loc_69FA
		LDY		_nmi_tlmB1_ram+$1C
		CPY		#$2E
		BNE		loc_69FA
		LDA		#$2E
loc_69FA:
		STA		_nmi_tlmB1_ram+$1D
		LDA		byte_59
		STA		_nmi_tlmB1_ram+$1E
		RTS
; ---------------------------------------------------------------------------
_tlm_patch_endless:
		.BYTE $07
		.BYTE _E,_N,_D,_L,_E,_S,_S
_tlm_patch_matchB:
		.BYTE $06
		.BYTE __,_M,_A,_T,_C,_H
_tlm_res_frameA:
		.BYTE $18
		.WORD $C621
		.BYTE $01
		.BYTE $0A
		.WORD $C721
		.BYTE $52
		.BYTE $0B
		.WORD $D921
		.BYTE $01
		.BYTE $0C
		.WORD $E621
		.BYTE $01
		.BYTE $10
		.WORD $E721
		.BYTE $52
		.BYTE $2E
		.WORD $F921
		.BYTE $01
		.BYTE $2D
_tlm_res_frameB:
		.BYTE $18
		.WORD $C622
		.BYTE $01
		.BYTE $10
		.WORD $C722
		.BYTE $52
		.BYTE $2E
		.WORD $D922
		.BYTE $01
		.BYTE $2D
		.WORD $E622
		.BYTE $01
		.BYTE $0D
		.WORD $E722
		.BYTE $52
		.BYTE $0E
		.WORD $F922
		.BYTE $01
		.BYTE $0F

; =============== S U B	R O U T	I N E =======================================
_main02_sub07:
		LDA		byte_560
		SEC
		SBC		byte_3C
		STA		byte_57
		LDA		byte_561
		SBC		byte_3D
		BCC		loc_6A6E
		BNE		loc_6A59
		LDA		byte_57
		BEQ		loc_6A6E
loc_6A59:
		LDA		byte_560
		SEC
		SBC		byte_3E
		STA		byte_57
		LDA		byte_561
		SBC		byte_3F
		BCC		loc_6A6E
		BNE		loc_6A7B
		LDA		byte_57
		BNE		loc_6A7B
loc_6A6E:
		LDA		byte_554
		BNE		loc_6A7B
		LDY		#$01
		JSR		_pal_fade_outB
		INC		_main02_sub_idx
		RTS
; ---------------------------------------------------------------------------
loc_6A7B:
		LDY		#$01
		JSR		_pal_fade_outB
		LDA		#$02
		STA		_main02_sub_idx
		RTS

; =============== S U B	R O U T	I N E =======================================
_main02_sub08_draw_winner:
		LDA		#$00
		STA		byte_539
		LDA		_game_mode_idx
		CMP		#$04
		BEQ		loc_6A9A
		LDA		_cur_player_idx
		BEQ		loc_6A9A
		JSR		_apu_play_ctrlD_set80
		BNE		loc_6A9D
loc_6A9A:
		JSR		_apu_play_ctrlE_set20
loc_6A9D:
		JSR		_ppu_render_off
		LDA		#$01
		STA		_nmi_disable_flush
		JSR		_game_field_draw
		LDA		#$00
		STA		_nmi_disable_flush
		LDY		#$0F
		LDA		#$2E
loc_6AAF:
		STA		_tlm_60F4_p0_w+1,Y
		STA		_tlm_60F4_p1_w+1,Y
		DEY
		BPL		loc_6AAF
		LDA		_1p_cpu_ctrl_flag
		ASL
		ORA		_2p_cpu_ctrl_flag
		BNE		loc_6AE4
		LDY		#>[_tlm_patch_player]
		LDA		#<[_tlm_patch_player]
		LDX		#$23
		JSR		_tlm_60F4_patch_write
		LDY		#>[_tlm_patch_is]
		LDA		#<[_tlm_patch_is]
		LDX		#$28
		JSR		_tlm_60F4_patch_write
		LDA		#$A5
		STA		_tlm_60F4_p0_w+9
		LDA		#$01
		LDY		_cur_player_idx
		BEQ		loc_6ADE
		LDA		#$02
loc_6ADE:
		STA		_tlm_60F4_p0_w+$A
		JMP		loc_6B1E
; ---------------------------------------------------------------------------
loc_6AE4:
		CMP		#$01
		BNE		loc_6B0C
		LDY		#>[_tlm_patch_player]
		LDA		#<[_tlm_patch_player]
		LDX		#$23
		JSR		_tlm_60F4_patch_write
		LDY		#>[_tlm_patch_is]
		LDA		#<[_tlm_patch_is]
		LDX		#$26
		JSR		_tlm_60F4_patch_write
		LDA		_cur_player_idx
		BEQ		loc_6B1E
		STA		byte_539
		LDY		#>[_tlm_patch_the_loser]
		LDA		#<[_tlm_patch_the_loser]
		LDX		#$4A
		JSR		_tlm_60F4_patch_write
		BEQ		loc_6B27
loc_6B0C:
		LDY		#>[_tlm_patch_computer]
		LDA		#<[_tlm_patch_computer]
		LDX		#$25
		JSR		_tlm_60F4_patch_write
		LDY		#>[_tlm_patch_is]
		LDA		#<[_tlm_patch_is]
		LDX		#$28
		JSR		_tlm_60F4_patch_write
loc_6B1E:
		LDY		#>[_tlm_patch_the_winner]
		LDA		#<[_tlm_patch_the_winner]
		LDX		#$4A
		JSR		_tlm_60F4_patch_write
loc_6B27:
		LDX		#<[_tlm_60F4_w]
		LDY		#>[_tlm_60F4_w]
		JSR		_ppu_tlm_unpack
		INC		_main02_sub_idx
		LDY		#$01
		JSR		_pal_fade_outA
		LDA		#$0C
		STA		_tmp4Bb
		LDA		#$06
		STA		byte_4D
		LDA		#$00
		STA		_tpp_idx
		RTS

; =============== S U B	R O U T	I N E =======================================
_game_field_draw:
		JSR		_ppu_nt_clear
		JSR		_spr_clear
		LDX		#<[_tlm_game_field]
		LDY		#>[_tlm_game_field]
		JSR		_ppu_tlm_unpack
		JSR		sub_6B92
		JSR		sub_96C5
		LDA		#$00
loc_6B57:
		PHA
		JSR		sub_77DA
		JSR		_nmi_ppu_dequeue
		PLA
		CLC
		ADC		#$01
		CMP		#$1A
		BNE		loc_6B57
		RTS

; =============== S U B	R O U T	I N E =======================================
_tlm_60F4_patch_write:
		STY		_tmp20w+1
		STA		_tmp20w
		LDY		#$00
		LDA		(_tmp20w),Y
		TAY
loc_6B70:
		LDA		(_tmp20w),Y
		STA		_tlm_60F4_w,X
		DEX
		DEY
		BNE		loc_6B70
		RTS
; ---------------------------------------------------------------------------
_tlm_patch_is:
		.BYTE $02
		.BYTE _I,_S
_tlm_patch_the_winner:
		.BYTE $0A
		.BYTE _T,_H,_E,__,_W,_I,_N,_N,_E,_R
_tlm_patch_the_loser:
		.BYTE $09
		.BYTE _T,_H,_E,__,_L,_O,_S,_E,_R

; =============== S U B	R O U T	I N E =======================================
sub_6B92:
		LDY		#$1F
		LDA		#$00
loc_6B96:
		STA		byte_3C0,Y
		STA		byte_3E0,Y
		DEY
		BPL		loc_6B96
		LDY		#$00
loc_6BA1:
		LDA		byte_6BAD,Y
		STA		byte_502,Y
		INY
		CPY		#$0F
		BNE		loc_6BA1
		RTS
; ---------------------------------------------------------------------------
byte_6BAD:
		.BYTE $00,$CC,$88,$88,$AA,$22,$22,$66,$AA,$88,$CC,$88,$33,$22,$22

; =============== S U B	R O U T	I N E =======================================
_main02_sub09_win_animate:
		LDA		_nmi_counter
		BNE		loc_6BC7
		DEC		_tmp4Bb
		BNE		loc_6BC7
		INC		_main02_sub_idx
		RTS
; ---------------------------------------------------------------------------
loc_6BC7:
		LDA		byte_539
		BNE		locret_6BE7
		DEC		byte_4D
		LDA		byte_4D
		BNE		locret_6BE7
		LDA		#$06
		STA		byte_4D
		LDA		_tpp_idx
		CMP		#$03
		BCC		loc_6BE0
		LDA		#$00
		STA		_tpp_idx
loc_6BE0:
		CLC
		ADC		#$04
		STA		byte_32
		INC		_tpp_idx
locret_6BE7:
		RTS
; ---------------------------------------------------------------------------
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
_nmi_tlmB7:
		.BYTE $FF

; =============== S U B	R O U T	I N E =======================================
_main02_sub0A_stage_complete:
		LDA		_game_mode_idx
		CMP		#$03
		BNE		loc_6C9A
		LDA		_cur_player_idx
		BEQ		loc_6C7C
		LDA		_cheat_flag1_w
		BEQ		loc_6C9A
		LDA		_pads_held+1
		BEQ		loc_6C9A
		JSR		_apu_play_ctrlC_set40
		BNE		loc_6C86
loc_6C7C:
		INC		_match_idx
		LDA		_match_idx
		CMP		#$04
		BEQ		_ending_screen
loc_6C86:
		LDA		#$0C
		STA		_main02_sub_idx
		LDY		#$00
		STY		byte_3C
		STY		byte_3D
		STY		byte_3E
		STY		byte_3F
		STY		byte_555
		JMP		loc_6CA1
; ---------------------------------------------------------------------------
loc_6C9A:
		LDY		#$00
		STY		_main_sub_idx
		STY		_main00_sub_idx
loc_6CA1:
		INY
		JMP		_pal_fade_outB

; =============== S U B	R O U T	I N E =======================================
_ending_screen:
		LDY		#$00
		STY		_main_sub_idx
		STY		_main00_sub_idx
		STY		_ending_sub_idx
		INY
		JSR		_pal_fade_outB
		LDA		#$02
		STA		_load_file_list_idx
		JSR		_file_load
;		LDA		#$70
;		STA		_overlay_loaded_flag_w
		JSR		_ending
;		LDY		#$00
;		STY		_overlay_loaded_flag_w
		INY
		STY		_load_file_list_idx
		JMP		_file_load

; =============== S U B	R O U T	I N E =======================================
_main02_sub0C_tournament_name:
		JSR		_ppu_render_off
		LDA		#$01
		STA		_nmi_disable_flush
		JSR		sub_7A91
		JSR		_ppu_nt_clear
		JSR		_spr_clear
		LDX		#<[_tlm_tournament_name_frame]
		LDY		#>[_tlm_tournament_name_frame]
		JSR		_ppu_tlm_unpack
		LDX		#<[_tlm_points_matchB]
		LDY		#>[_tlm_points_matchB]
		LDA		_match_idx
		CMP		#$03
		BNE		loc_6CF5
		LDX		#<[_tlm_points_matchA]
		LDY		#>[_tlm_points_matchA]
loc_6CF5:
		JSR		_ppu_tlm_unpack
		LDY		_match_idx
		LDA		_game_name_tlm_lib_lo,Y
		TAX
		LDA		_game_name_tlm_lib_hi,Y
		TAY
		JSR		_ppu_tlm_unpack
		LDA		#$00
		STA		byte_561
		LDY		_match_idx
		LDA		_trnm_match_points_list,Y
		STA		byte_560
		LDA		_tlm_pts_lib_lo,Y
		TAX
		LDA		_tlm_pts_lib_hi,Y
		TAY
		JSR		_ppu_tlm_unpack
		LDY		#$02
		JSR		_set_field_pal
		JSR		_apu_play_ctrlE_set08
		LDY		#$00
		STY		_nmi_disable_flush
		STY		byte_55B
		INC		_main02_sub_idx
		INY
		JMP		_pal_fade_outA
; ---------------------------------------------------------------------------
_tlm_tournament_name_frame:
		.WORD $2521
		.BYTE $01
		.BYTE $0A
		.WORD $2621
		.BYTE $54
		.BYTE $0B
		.WORD $3A21
		.BYTE $01
		.BYTE $0C
		.WORD $4521
		.BYTE $01
		.BYTE $10
		.WORD $4621
		.BYTE $54
		.BYTE $2E
		.WORD $5A21
		.BYTE $01
		.BYTE $2D
		.WORD $6521
		.BYTE $01
		.BYTE $10
		.WORD $6621
		.BYTE $54
		.BYTE $2E
		.WORD $7A21
		.BYTE $01
		.BYTE $2D
		.WORD $8521
		.BYTE $01
		.BYTE $10
		.WORD $8621
		.BYTE $54
		.BYTE $2E
		.WORD $9A21
		.BYTE $01
		.BYTE $2D
		.WORD $A521
		.BYTE $01
		.BYTE $10
		.WORD $A621
		.BYTE $54
		.BYTE $2E
		.WORD $BA21
		.BYTE $01
		.BYTE $2D
		.WORD $C521
		.BYTE $01
		.BYTE $10
		.WORD $C621
		.BYTE $54
		.BYTE $2E
		.WORD $DA21
		.BYTE $01
		.BYTE $2D
		.WORD $E521
		.BYTE $01
		.BYTE $10
		.WORD $E621
		.BYTE $54
		.BYTE $2E
		.WORD $FA21
		.BYTE $01
		.BYTE $2D
		.WORD $522
		.BYTE $01
		.BYTE $0D
		.WORD $622
		.BYTE $54
		.BYTE $0E
		.WORD $1A22
		.BYTE $01
		.BYTE $0F
		.BYTE $FF
_trnm_match_points_list:
		.BYTE $05,$07,$0B,$0F
_game_name_tlm_lib_lo:
		.BYTE <[_tlm_first_game]
		.BYTE <[_tlm_second_game]
		.BYTE <[_tlm_semifinal_game]
		.BYTE <[_tlm_final_game]
_game_name_tlm_lib_hi:
		.BYTE >[_tlm_first_game]
		.BYTE >[_tlm_second_game]
		.BYTE >[_tlm_semifinal_game]
		.BYTE >[_tlm_final_game]
_tlm_first_game:
		.WORD $6921
		.BYTE $0E
		.BYTE _T,_H,_E,__,_F,_I,_R,_S,_T,__,_G,_A,_M,_E
		.BYTE $FF
_tlm_second_game:
		.WORD $6821
		.BYTE $0F
		.BYTE _T,_H,_E,__,_S,_E,_C,_O,_N,_D,__,_G,_A,_M,_E
		.BYTE $FF
_tlm_semifinal_game:
		.WORD $6721
		.BYTE $12
		.BYTE _T,_H,_E,__,_S,_E,_M,_I,_F,_I,_N,_A,_L,__,_G,_A,_M,_E
		.BYTE $FF
_tlm_final_game:
		.WORD $6921
		.BYTE $0E
		.BYTE _T,_H,_E,__,_F,_I,_N,_A,_L,__,_G,_A,_M,_E
		.BYTE $FF
_tlm_pts_lib_lo:
		.BYTE <[_tlm_pts5]
		.BYTE <[_tlm_pts7]
		.BYTE <[_tlm_pts11]
		.BYTE <[_tlm_pts15]
_tlm_pts_lib_hi:
		.BYTE >[_tlm_pts5]
		.BYTE >[_tlm_pts7]
		.BYTE >[_tlm_pts11]
		.BYTE >[_tlm_pts15]
_tlm_pts5:
		.WORD $C821
		.BYTE $02
		.BYTE __,_5
		.BYTE $FF
_tlm_pts7:
		.WORD $C821
		.BYTE $02
		.BYTE __,_7
		.BYTE $FF
_tlm_points_matchA:
		.WORD $CC21
		.BYTE $0C
		.BYTE _P,_O,_I,_N,_T,_S,__,_M,_A,_T,_C,_H
		.BYTE $FF
_tlm_pts11:
		.WORD $C821
		.BYTE $02
		.BYTE _1,_1
		.BYTE $FF
_tlm_pts15:
		.WORD $C921
		.BYTE $02
		.BYTE _1,_5
		.BYTE $FF
_tlm_points_matchB:
		.WORD $CB21
		.BYTE $0C
		.BYTE _P,_O,_I,_N,_T,_S,__,_M,_A,_T,_C,_H
		.BYTE $FF

; =============== S U B	R O U T	I N E =======================================
_main02_sub0D_delay:
		DEC		byte_55B
		BNE		nullsub_3
		LDY		#$01
		STY		_main02_sub_idx
		JMP		_pal_fade_outB
nullsub_3:
		RTS

; =============== S U B	R O U T	I N E =======================================
_main_subD:
		LDA		_main02_sub_idx
		CMP		#$04
		BNE		nullsub_3
		LDA		_pads_press
		AND		#$20
		BEQ		nullsub_3
		LDA		_game_mode_idx
		CMP		#$02
		BCC		nullsub_3
		LDA		byte_32
		ORA		_ppu_queue_req
		ORA		_nmi_tlm_lib_idx
		ORA		byte_62
		ORA		byte_577
		BNE		nullsub_3
		JSR		_apu_play_ctrlC_set80
		JSR		_spr_clear
		LDY		#>[_tlm_res_6FE6]
		LDX		#<[_tlm_res_6FE6]
		JSR		_tlm_B1_ram_queue
		JSR		_sync
		LDY		#>[_tlm_res_615B]
		LDX		#<[_tlm_res_615B]
		JSR		_tlm_B1_ram_queue
		LDA		byte_554
		BEQ		loc_6E6F
		LDY		#>[_tlm_patch_endless]
		LDA		#<[_tlm_patch_endless]
		LDX		#$0C
		JSR		_tlm_B1_ram_patch_queue
		LDX		#$12
		BNE		loc_6E9F
loc_6E6F:
		LDY		#$2E
		LDX		#$05
		LDA		byte_560
		CMP		#$05
		BEQ		loc_6E8E
		LDY		#$2E
		LDX		#$07
		CMP		#$07
		BEQ		loc_6E8E
		LDY		#$01
		LDX		#$01
		CMP		#$0B
		BEQ		loc_6E8E
		LDY		#$01
		LDX		#$05
loc_6E8E:
		STY		_nmi_tlmB1_ram+5
		STX		_nmi_tlmB1_ram+6
		LDY		#>[_tlm_patch_points]
		LDA		#<[_tlm_patch_points]
		LDX		#$0D
		JSR		_tlm_B1_ram_patch_queue
		LDX		#$13
loc_6E9F:
		LDY		#>[_tlm_patch_matchA]
		LDA		#<[_tlm_patch_matchA]
		JSR		_tlm_B1_ram_patch_queue
		JSR		_sync
		LDA		byte_3C
		STA		byte_5C
		LDA		byte_3D
		STA		byte_5B
		JSR		sub_69D0
		LDA		_nmi_tlmB1_ram+$1C
		STA		byte_57
		LDA		_nmi_tlmB1_ram+$1D
		STA		byte_58
		LDA		_nmi_tlmB1_ram+$1E
		STA		byte_5A0
		LDY		#>[_tlm_res_6180]
		LDX		#<[_tlm_res_6180]
		JSR		_tlm_B1_ram_queue
		LDA		byte_57
		STA		_nmi_tlmB1_ram+$10
		LDA		byte_58
		STA		_nmi_tlmB1_ram+$11
		LDA		byte_5A0
		STA		_nmi_tlmB1_ram+$12
		LDA		_1p_cpu_ctrl_flag
		ASL
		ORA		_2p_cpu_ctrl_flag
		BNE		loc_6EF7
		LDY		#>[_tlm_patch_player]
		LDA		#<[_tlm_patch_player]
		LDX		#$0C
		JSR		_tlm_B1_ram_patch_queue
		LDA		#$A5
		STA		_nmi_tlmB1_ram+$D
		LDA		#$01
		STA		_nmi_tlmB1_ram+$E
		BNE		loc_6F0F
loc_6EF7:
		CMP		#$01
		BNE		loc_6F06
		LDY		#>[_tlm_patch_player]
		LDA		#<[_tlm_patch_player]
		LDX		#$0D
		JSR		_tlm_B1_ram_patch_queue
		BEQ		loc_6F0F
loc_6F06:
		LDY		#>[_tlm_patch_computer]
		LDA		#<[_tlm_patch_computer]
		LDX		#$0E
		JSR		_tlm_B1_ram_patch_queue
loc_6F0F:
		JSR		_sync
		LDA		byte_3E
		STA		byte_5C
		LDA		byte_3F
		STA		byte_5B
		JSR		sub_69D0
		LDA		_nmi_tlmB1_ram+$1C
		STA		byte_57
		LDA		_nmi_tlmB1_ram+$1D
		STA		byte_58
		LDA		_nmi_tlmB1_ram+$1E
		STA		byte_5A0
		LDY		#>[_tlm_res_61A5]
		LDX		#<[_tlm_res_61A5]
		JSR		_tlm_B1_ram_queue
		LDA		byte_57
		STA		_nmi_tlmB1_ram+$10
		LDA		byte_58
		STA		_nmi_tlmB1_ram+$11
		LDA		byte_5A0
		STA		_nmi_tlmB1_ram+$12
		LDA		_1p_cpu_ctrl_flag
		ASL
		ORA		_2p_cpu_ctrl_flag
		BNE		loc_6F60
		LDY		#>[_tlm_patch_player]
		LDA		#<[_tlm_patch_player]
		LDX		#$0C
		JSR		_tlm_B1_ram_patch_queue
		LDA		#$A5
		STA		_nmi_tlmB1_ram+$D
		LDA		#$02
		STA		_nmi_tlmB1_ram+$E
		BNE		loc_6F78
loc_6F60:
		CMP		#$01
		BNE		loc_6F6F
		LDY		#>[_tlm_patch_computer]
		LDA		#<[_tlm_patch_computer]
		LDX		#$0E
		JSR		_tlm_B1_ram_patch_queue
		BEQ		loc_6F78
loc_6F6F:
		LDY		#>[_tlm_patch_computer]
		LDA		#<[_tlm_patch_computer]
		LDX		#$0E
		JSR		_tlm_B1_ram_patch_queue
loc_6F78:
		JSR		_sync
		LDA		_pads_press
		AND		#$20
		BEQ		loc_6F78
		LDY		#$07
loc_6F83:
		STY		_tmp4Bb
		LDY		#>[_tlm_res_61CA]
		LDX		#<[_tlm_res_61CA]
		JSR		_tlm_B1_ram_queue
		LDY		_tmp4Bb
		LDA		byte_6FC9,Y
		STA		_nmi_tlmB1_ram
		LDA		byte_6FD1,Y
		STA		_nmi_tlmB1_ram+1
		JSR		_sync
		LDY		_tmp4Bb
		DEY
		BPL		loc_6F83
		LDA		byte_31D
		BPL		loc_6FB1
		LDY		#>[_tlm_res_96A5]
		LDX		#<[_tlm_res_96A5]
		JSR		_tlm_B1_ram_queue
		JSR		_sync
loc_6FB1:
		LDA		byte_578
		BEQ		loc_6FBB
		LDA		byte_579
		STA		byte_62
loc_6FBB:
		LDA		byte_305
		BEQ		loc_6FC5
		LDA		#$01
		STA		byte_305
loc_6FC5:
		JSR		_apu_play_ctrlC_set40
		RTS
; ---------------------------------------------------------------------------
byte_6FC9:
		.BYTE $22,$22,$22,$22,$21,$21,$21,$21
byte_6FD1:
		.BYTE $65,$45,$25,$05,$E5,$C5,$A5,$85
_tlm_patch_points:
		.BYTE $06
		.BYTE _P,_O,_I,_N,_T,_S
_tlm_patch_matchA:
		.BYTE $05
		.BYTE _M,_A,_T,_C,_H
_tlm_res_6FE6:
		.BYTE $19
		.BYTE $21,$85,$01,$0A
		.BYTE $21,$86,$52,$0B
		.BYTE $21,$98,$01,$0C
		.BYTE $21,$A5,$01,$10
		.BYTE $21,$A6,$52,$2E
		.BYTE $21,$B8,$01,$2D
		.BYTE $FF
_tlm_res_6012:
		.BYTE $31
		.WORD $0421
		.BYTE $01
		.BYTE $10
		.WORD $0521
		.BYTE $12
		.BYTE __,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__
		.WORD $1721
		.BYTE $01
		.BYTE $2D
		.WORD $2421
		.BYTE $01
		.BYTE $10
		.WORD $2521
		.BYTE $52
		.BYTE __
		.WORD $3721
		.BYTE $01
		.BYTE $2D
		.WORD $D123
		.BYTE $05
		.BYTE $AA,$AA,$AA,$AA,$AA
_tlm_res_6044:
		.BYTE $29
		.WORD $4421
		.BYTE $01
		.BYTE $10
		.WORD $4521
		.BYTE $52
		.BYTE __
		.WORD $5721
		.BYTE $01
		.BYTE $2D
		.WORD $6421
		.BYTE $01
		.BYTE $10
		.WORD $6521
		.BYTE $12
		.BYTE __,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__
		.WORD $7721
		.BYTE $01
		.BYTE $2D
_tlm_res_606E:
		.BYTE $19
		.WORD $A421
		.BYTE $01
		.BYTE $10
		.WORD $A521
		.BYTE $47
		.BYTE __
		.WORD $AA21
		.BYTE $0E
		.BYTE __,__,__,__,__,_P,_O,_I,_N,_T,__,__,__,$2D
_tlm_res_6088:
		.BYTE $23
		.WORD $0622
		.BYTE $14
		.BYTE $10,__,__,__,__,_P,_O,_I,_N,_T,_S,__,__,__,__,__,__,__,__,$2D
		.WORD $2622
		.BYTE $01
		.BYTE $10
		.WORD $2722
		.BYTE $52
		.BYTE __
		.WORD $3922
		.BYTE $01
		.BYTE $2D
_tlm_res_60AC:
		.BYTE $23
		.WORD $4622
		.BYTE $01
		.BYTE $10
		.WORD $4722
		.BYTE $52
		.BYTE __
		.WORD $5922
		.BYTE $01
		.BYTE $2D
		.WORD $6622
		.BYTE $14
		.BYTE $10,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,$2D
_tlm_res_60D0:
		.BYTE $23
		.WORD $8622
		.BYTE $01
		.BYTE $10
		.WORD $8722
		.BYTE $52
		.BYTE __
		.WORD $9922
		.BYTE $01
		.BYTE $2D
		.WORD $A622
		.BYTE $14
		.BYTE $10,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,$2D
_tlm_60F4_w:
		.WORD $8621
		.BYTE $01
		.BYTE $0A
		.WORD $8721
		.BYTE $50
		.BYTE $0B
		.WORD $9721
		.BYTE $01
		.BYTE $0C
		.WORD $A621
		.BYTE $01
		.BYTE $10
		.WORD $A721
		.BYTE $50
		.BYTE __
		.WORD $B721
		.BYTE $01
		.BYTE $2D
		.WORD $C621
		.BYTE $12
_tlm_60F4_p0_w:
		.BYTE $10,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,$2D
		.WORD $E621
		.BYTE $01
		.BYTE $10
		.WORD $E721
		.BYTE $50
		.BYTE __
		.WORD $F721
		.BYTE $01
		.BYTE $2D
		.WORD $0622
		.BYTE $12
_tlm_60F4_p1_w:
		.BYTE $10,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,$2D
		.WORD $2622
		.BYTE $01
		.BYTE $10
		.WORD $2722
		.BYTE $50
		.BYTE __
		.WORD $3722
		.BYTE $01
		.BYTE $2D
		.WORD $4622
		.BYTE $01
		.BYTE $0D
		.WORD $4722
		.BYTE $50
		.BYTE $0E
		.WORD $5722
		.BYTE $01
		.BYTE $0F
		.BYTE $FF
_tlm_res_615B:
		.BYTE $24
		.WORD $C521
		.BYTE $14
		.BYTE $10,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,$2D
		.WORD $E521
		.BYTE $01
		.BYTE $10
		.WORD $E621
		.BYTE $52
		.BYTE __
		.WORD $F821
		.BYTE $01
		.BYTE $2D
		.BYTE $FF
_tlm_res_6180:
		.BYTE $24
		.WORD $522
		.BYTE $14
		.BYTE $10,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,$2D
		.WORD $2522
		.BYTE $01
		.BYTE $10
		.WORD $2622
		.BYTE $52
		.BYTE __
		.WORD $3822
		.BYTE $01
		.BYTE $2D
		.BYTE $FF
_tlm_res_61A5:
		.BYTE $24
		.WORD $4522
		.BYTE $14
		.BYTE $10,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,$2D
		.WORD $6522
		.BYTE $01
		.BYTE $0D
		.WORD $6622
		.BYTE $52
		.BYTE $0E
		.WORD $7822
		.BYTE $01
		.BYTE $0F
		.BYTE $FF
_tlm_res_61CA:
		.BYTE $18
		.WORD $0000
		.BYTE $14
		.BYTE $2F,$2F,$2F,$2F,$2F,$2F,$2F,$2F,$2F,$63,$64,$2F,$2F,$2F,$2F,$2F
		.BYTE $2F,$2F,$2F,$2F
		.BYTE $FF
_pal1_w:
		.WORD $003F
		.BYTE $20
_pal1_pw:
		.BYTE $17,$30,$1A,$0F,$17,$16,$1A,$0F,$17,$30,$27,$0F,$17,$16,$27,$0F
		.BYTE $17,$37,$2C,$0F,$17,$12,$2C,$0F,$17,$30,$30,$0F,$17,$16,$0F,$0F
		.BYTE $FF
_pal2_w:
		.WORD $103F
		.BYTE $04
_pal2_p0_w:
		.BYTE $17,$36,$2C,$0F
		.WORD $1C3F
		.BYTE $04
_pal2_p1_w:
		.BYTE $17,$16,$10,$0F
		.BYTE $FF
_pal3_w:
		.WORD $103F
		.BYTE $04
_pal3_p0_w:
		.BYTE $17,$37,$2C,$0F
		.WORD $1C3F
		.BYTE $04
_pal3_p1_w:
		.BYTE $17,$16,$25,$0F
		.BYTE $FF

; =============== S U B	R O U T	I N E =======================================
_spr_lib_insert:
		PHA
		TYA
		PHA
		TXA
		PHA
		LDA		byte_300
		BPL		loc_707D
		INC		byte_300
		LDA		_spr_buf_pos
		PHA
		JSR		_spr_clear
		PLA
		STA		_spr_buf_pos
loc_707D:
		LDA		#$00
		STA		byte_6C
		LDY		_cur_player_idx
		BEQ		loc_70A8
		LDY		_spr_lib_idx
		CPY		#$08
		BCC		loc_70A8
		LDA		#$01
		STA		byte_6C
		CPY		#$12
		BCC		loc_70A8
		LDA		byte_32F
		STA		byte_6C
		CPY		#$1C
		BCC		loc_70A8
		LDA		#$C3
		STA		byte_6C
		CPY		#$20
		BCC		loc_70A8
		LDA		#$C0
		STA		byte_6C
loc_70A8:
		LDY		byte_60
		BEQ		loc_70BB
		LDY		_spr_lib_idx
		CPY		#$12
		BCC		loc_70BB
		CPY		#$18
		BCS		loc_70BB
		LDA		byte_32F
		STA		byte_6C
loc_70BB:
		LDA		_spr_lib_idx
		LDY		byte_60
		BEQ		loc_70CB
		CMP		#$1C
		BCC		loc_70CB
		CMP		#$1F
		BCS		loc_70CB
		ADC		#$08
loc_70CB:
		ASL
		TAY
		LDA		_spr_lib,Y
		STA		_tmp20w
		LDA		_spr_lib+1,Y
		STA		_tmp20w+1
		LDX		_spr_buf_pos
		LDY		#$00
		JMP		loc_7162
; ---------------------------------------------------------------------------
loc_70DE:
		LDA		byte_6C
		AND		#$80
		PHP
		LDA		(_tmp20w),Y
		PLP
		BEQ		loc_70ED
		LDA		#$F0
		SEC
		SBC		(_tmp20w),Y
loc_70ED:
		CMP		#$00
		BPL		loc_70F4
		DEC		byte_32B
loc_70F4:
		CLC
		ADC		byte_32A
		STA		byte_32A
		LDA		#$00
		ADC		byte_32B
		STA		byte_32D
		BEQ		loc_710B
		INY
		INY
		INY
		JMP		loc_7161
; ---------------------------------------------------------------------------
loc_710B:
		LDA		byte_32A
		STA		_spr_buf,X
		INY
		LDA		(_tmp20w),Y
		STA		_spr_buf+1,X
		INY
		LDA		(_tmp20w),Y
		AND		#$02
		BEQ		loc_7120
		ORA		byte_6B
loc_7120:
		ORA		(_tmp20w),Y
		STA		_spr_buf+2,X
		LDA		byte_6C
		AND		#$C0
		EOR		_spr_buf+2,X
		STA		_spr_buf+2,X
		INY
		LDA		byte_6C
		AND		#$40
		PHP
		LDA		(_tmp20w),Y
		PLP
		BEQ		loc_713F
		LDA		#$F8
		SEC
		SBC		(_tmp20w),Y
loc_713F:
		CMP		#$00
		BPL		loc_7146
		DEC		byte_329
loc_7146:
		CLC
		ADC		byte_328
		STA		byte_328
		LDA		#$00
		ADC		byte_329
		STA		byte_32C
		BNE		loc_7161
		LDA		byte_328
		STA		_spr_buf+3,X
		INX
		INX
		INX
		INX
loc_7161:
		INY
loc_7162:
		LDA		byte_6C
		LSR
		LSR
		BCS		loc_7175
		LDA		byte_68
		STA		byte_32A
		LDA		byte_69
		STA		byte_32B
		JMP		loc_7186
; ---------------------------------------------------------------------------
loc_7175:
		LDA		byte_68
		EOR		#$FF
		SEC
		ADC		#$F0
		STA		byte_32A
		LDA		byte_69
		SBC		#$00
		STA		byte_32B
loc_7186:
		LDA		byte_6C
		LSR
		BCS		loc_7198
		LDA		byte_66
		STA		byte_328
		LDA		byte_67
		STA		byte_329
		JMP		loc_71A9
; ---------------------------------------------------------------------------
loc_7198:
		LDA		byte_66
		EOR		#$FF
		SEC
		ADC		#$F2
		STA		byte_328
		LDA		byte_67
		SBC		#$00
		STA		byte_329
loc_71A9:
		LDA		(_tmp20w),Y
		CMP		#$80
		BEQ		loc_71B2
		JMP		loc_70DE
; ---------------------------------------------------------------------------
loc_71B2:
		LDA		byte_32C
		ORA		byte_32D
		BEQ		loc_71C8
		LDA		#$F4
		STA		_spr_buf,X
		STA		_spr_buf+1,X
		STA		_spr_buf+2,X
		STA		_spr_buf+3,X
loc_71C8:
		STX		_spr_buf_pos
		PLA
		TAX
		PLA
		TAY
		PLA
		RTS
; ---------------------------------------------------------------------------
_spr_lib:
		.WORD _spr00
		.WORD _spr01
		.WORD _spr02
		.WORD _spr03
		.WORD _spr04
		.WORD _spr05
		.WORD _spr06
		.WORD _spr07
		.WORD _spr08
		.WORD _spr09
		.WORD _spr0A
		.WORD _spr0B
		.WORD _spr0C
		.WORD _spr0D
		.WORD _spr0E
		.WORD _spr0F
		.WORD _spr10
		.WORD _spr11
		.WORD _spr12
		.WORD _spr13
		.WORD _spr14
		.WORD _spr15
		.WORD _spr16
		.WORD _spr17
		.WORD _spr18
		.WORD _spr19
		.WORD _spr1A
		.WORD _spr1B
		.WORD _spr1C
		.WORD _spr1D
		.WORD _spr1E
		.WORD _spr1F
		.WORD _spr20
		.WORD _spr21
		.WORD _spr22
		.WORD _spr23
		.WORD _spr24
		.WORD _spr25
		.WORD _spr26
		.WORD _spr27
		.WORD _spr28
_spr00:
		.BYTE $FB,$2E,$02,$F8
		.BYTE $FB,$2E,$42,$00
		.BYTE $80
_spr01:
		.BYTE $F9,$30,$02,$F8
		.BYTE $F9,$30,$42,$00
		.BYTE $80
_spr02:
		.BYTE $F7,$32,$02,$F8
		.BYTE $F7,$32,$42,$00
		.BYTE $80
_spr03:
		.BYTE $F7,$42,$02,$F9
		.BYTE $F7,$44,$02,$01
		.BYTE $80
_spr04:
		.BYTE $FE,$3E,$02,$F9
		.BYTE $FE,$40,$02,$01
		.BYTE $80
_spr05:
		.BYTE $FF,$46,$42,$F9
		.BYTE $FF,$46,$02,$00
		.BYTE $80
_spr06:
		.BYTE $F7,$FA,$03,$F8
		.BYTE $F7,$FC,$03,$00
		.BYTE $80
_spr07:
		.BYTE $F2,$00,$02,$F7
		.BYTE $F2,$02,$02,$FF
		.BYTE $80
_spr08:
		.BYTE $F9,$0A,$02,$F8
		.BYTE $F9,$0C,$02,$00
		.BYTE $80
_spr09:
		.BYTE $F8,$0E,$02,$F8
		.BYTE $F8,$10,$02,$00
		.BYTE $80
_spr0A:
		.BYTE $F9,$0E,$82,$F7
		.BYTE $F9,$10,$82,$FF
		.BYTE $80
_spr0B:
		.BYTE $F8,$0A,$82,$F8
		.BYTE $F8,$0C,$82,$00
		.BYTE $80
_spr0C:
		.BYTE $F8,$04,$02,$F8
		.BYTE $F8,$06,$02,$00
		.BYTE $08,$08,$02,$FC
		.BYTE $80
_spr0D:
		.BYTE $F8,$04,$82,$F8
		.BYTE $F8,$06,$82,$00
		.BYTE $E8,$08,$82,$FC
		.BYTE $80
_spr0E:
		.BYTE $F9,$0C,$42,$F8
		.BYTE $F9,$0A,$42,$00
		.BYTE $80
_spr0F:
		.BYTE $F8,$10,$42,$F7
		.BYTE $F8,$0E,$42,$FF
		.BYTE $80
_spr10:
		.BYTE $F9,$10,$C2,$F9
		.BYTE $F9,$0E,$C2,$01
		.BYTE $80
_spr11:
		.BYTE $F8,$0C,$C2,$F8
		.BYTE $F8,$0A,$C2,$00
		.BYTE $80
_spr12:
		.BYTE $F8,$26,$02,$F8
		.BYTE $F8,$28,$02,$00
		.BYTE $08,$2A,$02,$F8
		.BYTE $08,$2C,$02,$00
		.BYTE $80
_spr13:
		.BYTE $F8,$22,$02,$F8
		.BYTE $F8,$24,$02,$00
		.BYTE $08,$2A,$02,$F8
		.BYTE $08,$2C,$02,$00
		.BYTE $80
_spr14:
		.BYTE $F8,$1E,$02,$F8
		.BYTE $F8,$20,$02,$00
		.BYTE $08,$2A,$02,$F8
		.BYTE $08,$2C,$02,$00
		.BYTE $80
_spr15:
		.BYTE $F8,$1A,$02,$F8
		.BYTE $F8,$1C,$02,$00
		.BYTE $08,$2A,$02,$F8
		.BYTE $08,$2C,$02,$00
		.BYTE $80
_spr16:
		.BYTE $F8,$16,$02,$F8
		.BYTE $F8,$18,$02,$00
		.BYTE $08,$2A,$02,$F8
		.BYTE $08,$2C,$02,$00
		.BYTE $80
_spr17:
		.BYTE $F8,$12,$02,$F8
		.BYTE $F8,$14,$02,$00
		.BYTE $08,$2A,$02,$F8
		.BYTE $08,$2C,$02,$00
		.BYTE $80
_spr18:
		.BYTE $00,$34,$02,$00
		.BYTE $00,$36,$02,$08
		.BYTE $80
_spr19:
		.BYTE $00,$34,$02,$00
		.BYTE $00,$38,$02,$08
		.BYTE $80
_spr1A:
		.BYTE $00,$34,$02,$00
		.BYTE $00,$3A,$02,$08
		.BYTE $80
_spr1B:
		.BYTE $00,$34,$02,$00
		.BYTE $00,$3C,$02,$08,$80
_spr1C:
		.BYTE $D8,$7A,$00,$EE
		.BYTE $FD,$8E,$00,$F0
		.BYTE $EB,$CC,$02,$F0
		.BYTE $EB,$CE,$02,$F8
		.BYTE $E0,$72,$01,$E6
		.BYTE $E0,$74,$01,$EE
		.BYTE $E0,$76,$00,$F6
		.BYTE $E0,$78,$00,$FE
		.BYTE $F0,$7C,$00,$E8
		.BYTE $F0,$7E,$00,$F0
		.BYTE $F0,$82,$00,$F8
		.BYTE $F0,$84,$00,$00
		.BYTE $00,$86,$00,$ED
		.BYTE $00,$88,$00,$F5
		.BYTE $00,$8A,$00,$FD
		.BYTE $00,$8C,$00,$05
		.BYTE $10,$EA,$00,$FD
		.BYTE $10,$EC,$00,$05
		.BYTE $80
_spr1D:
		.BYTE $D8,$7A,$00,$EE
		.BYTE $FD,$8E,$00,$F0
		.BYTE $E0,$D0,$02,$ED
		.BYTE $F0,$D2,$02,$F3
		.BYTE $E0,$72,$01,$E6
		.BYTE $E0,$74,$01,$EE
		.BYTE $E0,$76,$00,$F6
		.BYTE $E0,$78,$00,$FE
		.BYTE $F0,$7C,$00,$E8
		.BYTE $F0,$7E,$01,$F0
		.BYTE $F0,$82,$00,$F8
		.BYTE $F0,$84,$00,$00
		.BYTE $00,$86,$00,$ED
		.BYTE $00,$88,$00,$F5
		.BYTE $00,$8A,$00,$FD
		.BYTE $00,$8C,$00,$05
		.BYTE $10,$EA,$00,$FD
		.BYTE $10,$EC,$00,$05
		.BYTE $80
_spr1E:
		.BYTE $E7,$D4,$02,$E6
		.BYTE $F7,$D6,$02,$EE
		.BYTE $E4,$90,$01,$DC
		.BYTE $E4,$92,$01,$E4
		.BYTE $E4,$94,$00,$EC
		.BYTE $E4,$96,$00,$F4
		.BYTE $E4,$98,$00,$FC
		.BYTE $F4,$9C,$01,$E0
		.BYTE $F4,$9E,$01,$E8
		.BYTE $F4,$A0,$00,$F0
		.BYTE $F4,$A2,$00,$F8
		.BYTE $F4,$A4,$00,$00
		.BYTE $04,$A6,$00,$EC
		.BYTE $04,$A8,$00,$F4
		.BYTE $04,$AA,$00,$FC
		.BYTE $04,$AC,$00,$04
		.BYTE $80
_spr1F:
		.BYTE $E7,$AE,$00,$E4
		.BYTE $DC,$B0,$00,$EC
		.BYTE $DF,$B2,$00,$F4
		.BYTE $E3,$B4,$00,$FC
		.BYTE $F0,$B6,$00,$DC
		.BYTE $F7,$B8,$00,$E4
		.BYTE $EC,$BA,$00,$EC
		.BYTE $EF,$BC,$00,$F4
		.BYTE $F3,$BE,$00,$FC
		.BYTE $F3,$C0,$00,$04
		.BYTE $FC,$C2,$00,$EC
		.BYTE $FF,$C4,$00,$F4
		.BYTE $03,$C6,$00,$FC
		.BYTE $03,$C8,$00,$04
		.BYTE $80
_spr20:
		.BYTE $F3,$48,$00,$00
		.BYTE $03,$4A,$00,$F6
		.BYTE $03,$4C,$00,$FE
		.BYTE $03,$4E,$00,$06
		.BYTE $13,$50,$00,$F0
		.BYTE $13,$52,$00,$F8
		.BYTE $13,$54,$00,$00
		.BYTE $13,$56,$00,$08
		.BYTE $23,$58,$00,$F8
		.BYTE $23,$5A,$00,$00
		.BYTE $23,$E6,$00,$08
		.BYTE $80
_spr21:
		.BYTE $FD,$D8,$02,$EE
		.BYTE $00,$5C,$00,$ED
		.BYTE $00,$5E,$00,$F5
		.BYTE $00,$60,$00,$FD
		.BYTE $00,$62,$00,$05
		.BYTE $10,$64,$00,$ED
		.BYTE $10,$66,$00,$F5
		.BYTE $10,$68,$00,$FD
		.BYTE $10,$6A,$00,$05
		.BYTE $20,$6C,$00,$F5
		.BYTE $20,$6E,$00,$FD
		.BYTE $20,$70,$00,$05
		.BYTE $80
_spr22:
		.BYTE $F3,$DA,$02,$F5
		.BYTE $F3,$DC,$02,$FD
		.BYTE $F0,$5C,$00,$F5
		.BYTE $F0,$5E,$00,$FD
		.BYTE $F0,$60,$00,$05
		.BYTE $F0,$62,$00,$0D
		.BYTE $00,$DE,$00,$F5
		.BYTE $00,$66,$00,$FD
		.BYTE $00,$68,$00,$05
		.BYTE $00,$6A,$00,$0D
		.BYTE $10,$6C,$00,$FD
		.BYTE $10,$6E,$00,$05
		.BYTE $10,$70,$00,$0D
		.BYTE $80
_spr23:
		.BYTE $F3,$9A,$02,$F5
		.BYTE $F3,$CA,$02,$FD
		.BYTE $F0,$5C,$00,$F5
		.BYTE $F0,$5E,$00,$FD
		.BYTE $F0,$60,$00,$05
		.BYTE $F0,$62,$00,$0D
		.BYTE $00,$DE,$00,$F5
		.BYTE $00,$66,$00,$FD
		.BYTE $00,$68,$00,$05
		.BYTE $00,$6A,$00,$0D
		.BYTE $10,$6C,$00,$FD
		.BYTE $10,$6E,$00,$05
		.BYTE $10,$70,$00,$0D
		.BYTE $80
_spr24:
		.BYTE $D8,$7A,$00,$EE
		.BYTE $FD,$8E,$00,$F0
		.BYTE $EB,$E0,$02,$F3
		.BYTE $E0,$72,$01,$E6
		.BYTE $E0,$74,$01,$EE
		.BYTE $E0,$76,$00,$F6
		.BYTE $E0,$78,$00,$FE
		.BYTE $F0,$7C,$00,$E8
		.BYTE $F0,$7E,$01,$F0
		.BYTE $F0,$82,$00,$F8
		.BYTE $F0,$84,$00,$00
		.BYTE $00,$86,$00,$ED
		.BYTE $00,$88,$00,$F5
		.BYTE $00,$8A,$00,$FD
		.BYTE $00,$8C,$00,$05
		.BYTE $10,$EA,$00,$FD
		.BYTE $10,$EC,$00,$05
		.BYTE $80
_spr25:
		.BYTE $D8,$7A,$00,$EE
		.BYTE $FD,$8E,$00,$F0
		.BYTE $F0,$D2,$02,$F3
		.BYTE $E0,$72,$01,$E6
		.BYTE $E0,$74,$01,$EE
		.BYTE $E0,$76,$00,$F6
		.BYTE $E0,$78,$00,$FE
		.BYTE $F0,$7C,$00,$E8
		.BYTE $F0,$7E,$01,$F0
		.BYTE $F0,$82,$00,$F8
		.BYTE $F0,$84,$00,$00
		.BYTE $00,$86,$00,$ED
		.BYTE $00,$88,$00,$F5
		.BYTE $00,$8A,$00,$FD
		.BYTE $00,$8C,$00,$05
		.BYTE $10,$EA,$00,$FD
		.BYTE $10,$EC,$00,$05
		.BYTE $80
_spr26:
		.BYTE $F7,$D6,$02,$EE
		.BYTE $E4,$90,$01,$DC
		.BYTE $E4,$92,$01,$E4
		.BYTE $E4,$94,$00,$EC
		.BYTE $E4,$96,$00,$F4
		.BYTE $E4,$98,$00,$FC
		.BYTE $F4,$9C,$01,$E0
		.BYTE $F4,$9E,$01,$E8
		.BYTE $F4,$A0,$00,$F0
		.BYTE $F4,$A2,$00,$F8
		.BYTE $F4,$A4,$00,$00
		.BYTE $04,$A6,$00,$EC
		.BYTE $04,$A8,$00,$F4
		.BYTE $04,$AA,$00,$FC
		.BYTE $04,$AC,$00,$04
		.BYTE $80
_spr27:
		.BYTE $00,$4C,$01,$06
		.BYTE $00,$4D,$01,$0E
		.BYTE $00,$4E,$01,$16
		.BYTE $00,$4F,$01,$1E
		.BYTE $08,$5B,$01,$00
		.BYTE $08,$5C,$01,$08
		.BYTE $08,$5D,$01,$10
		.BYTE $08,$5E,$01,$18
		.BYTE $08,$5F,$01,$20
		.BYTE $10,$6B,$01,$00
		.BYTE $10,$6C,$01,$08
		.BYTE $10,$6D,$01,$10
		.BYTE $10,$6E,$01,$18
		.BYTE $10,$6F,$01,$20
		.BYTE $18,$7B,$01,$00
		.BYTE $18,$7C,$01,$08
		.BYTE $18,$7D,$01,$10
		.BYTE $18,$7E,$01,$18
		.BYTE $18,$7F,$01,$20
		.BYTE $20,$8C,$01,$04
		.BYTE $20,$8D,$01,$0C
		.BYTE $20,$8E,$01,$14
		.BYTE $20,$8F,$01,$1C
		.BYTE $80
_spr28:
		.BYTE $18,$96,$C1,$14
		.BYTE $18,$97,$81,$0C
		.BYTE $18,$96,$81,$04
		.BYTE $10,$98,$C1,$18
		.BYTE $10,$99,$C1,$10
		.BYTE $10,$99,$81,$08
		.BYTE $10,$98,$81,$00
		.BYTE $08,$98,$41,$18
		.BYTE $08,$99,$41,$10
		.BYTE $08,$99,$01,$08
		.BYTE $08,$98,$01,$00
		.BYTE $00,$96,$41,$14
		.BYTE $00,$97,$01,$0C
		.BYTE $00,$96,$01,$04
		.BYTE $80

; =============== S U B	R O U T	I N E =======================================
_main02_sub04_ingame:
		LDA		_cheat_flag1_w
		BEQ		loc_7695
		LDA		_pads_held+1
		CMP		#$CA
		BNE		loc_7695
		JMP		RESET
; ---------------------------------------------------------------------------
loc_7695:
		LDA		#$FF
		STA		byte_300
		STA		byte_45
		JSR		_ingame_sub_exec
		LDA		byte_62
		CMP		#$02
		BCC		loc_76A9
		LDA		#$13
		STA		byte_45
loc_76A9:
		JSR		sub_8E47
		JSR		sub_7711
		JSR		sub_7797
		JSR		sub_77B6
		JSR		sub_9202
		LDA		byte_45
		CMP		#$FF
		BEQ		locret_76C7
		BPL		loc_76C5
		INC		_ingame_sub_idx
		JMP		locret_76C7
; ---------------------------------------------------------------------------
loc_76C5:
		STA		_ingame_sub_idx
locret_76C7:
		RTS

; =============== S U B	R O U T	I N E =======================================
_ingame_sub_exec:
		LDA		_ingame_sub_idx
		JSR		_switch
; ---------------------------------------------------------------------------
		.WORD _ingame_sub00
		.WORD _ingame_sub01
		.WORD _ingame_sub02
		.WORD _ingame_sub03
		.WORD _ingame_sub04
		.WORD _ingame_sub05
		.WORD _ingame_sub06
		.WORD _ingame_sub07
		.WORD _ingame_sub08
		.WORD _ingame_sub09
		.WORD _ingame_sub0A
		.WORD _ingame_sub0B
		.WORD _ingame_sub0C_next_turn_player_switch
		.WORD _ingame_sub0D
		.WORD _ingame_sub0E
		.WORD _ingame_sub0F
		.WORD _ingame_sub10
		.WORD _ingame_sub11
		.WORD _ingame_sub12
		.WORD _ingame_sub13
		.WORD _ingame_sub14
		.WORD _ingame_sub15
		.WORD _ingame_sub16
		.WORD _ingame_sub17
		.WORD _ingame_sub18
		.WORD _ingame_sub19
		.WORD _ingame_sub1A
		.WORD _ingame_sub1B
		.WORD _ingame_sub1C
		.WORD _ingame_sub1D
		.WORD _ingame_sub1E
		.WORD _ingame_sub1F
		.WORD _ingame_sub20
		.WORD _ingame_sub21

; =============== S U B	R O U T	I N E =======================================
sub_7711:
		LDA		byte_6B
		PHA
		LDA		byte_332
		BMI		loc_7735
		STA		byte_6B
		LDY		#$00
loc_771D:
		LDA		byte_76,Y
		STA		byte_66,Y
		INY
		CPY		#$05
		BNE		loc_771D
		LDA		byte_330
		STA		byte_32F
		LDA		#$E0
		STA		_spr_buf_pos
		JSR		_spr_lib_insert
loc_7735:
		LDA		byte_333
		BMI		loc_7793
		STA		byte_6B
		LDY		#$00
loc_773E:
		LDA		byte_7D,Y
		STA		byte_66,Y
		INY
		CPY		#$05
		BNE		loc_773E
		LDA		byte_331
		STA		byte_32F
		LDA		#$D0
		STA		_spr_buf_pos
		JSR		_spr_lib_insert
		LDA		byte_48
		BEQ		loc_7793
		LDA		byte_334
		BMI		loc_7793
		LDA		byte_60
		BNE		loc_7793
		LDA		byte_76
		LDY		byte_330
		BNE		loc_7772
		CLC
		ADC		#$08
		STA		byte_66
		JMP		loc_7777
; ---------------------------------------------------------------------------
loc_7772:
		SEC
		SBC		#$08
		STA		byte_66
loc_7777:
		LDA		#$6C
		STA		byte_68
		LDA		byte_4A
		CLC
		ADC		#$18
		STA		_spr_lib_idx
		LDA		#$00
		STA		byte_6B
		LDA		byte_330
		STA		byte_32F
		LDA		#$F8
		STA		_spr_buf_pos
		JSR		_spr_lib_insert
loc_7793:
		PLA
		STA		byte_6B
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_7797:
		LDA		byte_6B
		PHA
		LDA		byte_420
		PHA
		LDA		byte_319
		BEQ		loc_77A9
		LDA		byte_31A
		STA		byte_420
loc_77A9:
		LDA		#$00
		JSR		sub_77DA
		PLA
		STA		byte_420
		PLA
		STA		byte_6B
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_77B6:
		LDA		byte_6B
		PHA
		LDA		byte_32E
		BMI		loc_77D6
		LDA		byte_65
		STA		byte_6B
		LDA		#$00
		STA		_spr_buf_pos
		LDY		#$00
loc_77C8:
		LDA		byte_6F,Y
		STA		byte_66,Y
		INY
		CPY		#$05
		BNE		loc_77C8
		JSR		_spr_lib_insert
loc_77D6:
		PLA
		STA		byte_6B
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_77DA:
		STA		word_10+1
		TAY
		BNE		loc_77E2
		JMP		sub_7AD8
; ---------------------------------------------------------------------------
loc_77E2:
		CMP		#$19
		BCC		loc_77E9
		JMP		sub_7B64
; ---------------------------------------------------------------------------
loc_77E9:
		LDX		#$00
		LDY		_cur_player_idx
		BEQ		loc_77F5
		DEX
		EOR		#$FF
		SEC
		ADC		#$19
loc_77F5:
		STX		word_10
		STA		_tmp20w
		SEC
		SBC		#$01
		STA		_tmp20w+1
		ASL
		ADC		_tmp20w+1
		ASL
		CLC
		ADC		#<[byte_78F1]
		STA		_tmp1Cw
		LDA		#$00
		ADC		#>[byte_78F1]
		STA		_tmp1Cw+1
		LDY		#$04
		LDA		(_tmp1Cw),Y
		STA		byte_502
		LDX		word_10+1
		LDA		byte_400,X
		BNE		loc_7820
		LDA		byte_420,X
		INC		word_10
loc_7820:
		STA		byte_501
		INY
		LDA		(_tmp1Cw),Y
		TAY
		LDA		byte_502
		LDX		word_10
		BEQ		loc_7835
		EOR		#$FF
		ORA		byte_502,Y
		BNE		loc_7838
loc_7835:
		AND		byte_502,Y
loc_7838:
		STA		byte_502
		STA		byte_502,Y
		LDA		byte_501
		STA		byte_59
		LDY		_tmp20w
		CPY		#$0D
		BCS		loc_7862
		LDA		#$09
		STA		byte_57
		STA		byte_5A
		JSR		_div16
		LDA		byte_5C
		CLC
		ADC		#<[byte_7981]
		STA		byte_1E
		LDA		#>[byte_7981]
		ADC		byte_5B
		STA		byte_1F
		JMP		loc_7878
; ---------------------------------------------------------------------------
loc_7862:
		LDA		#$08
		STA		byte_57
		STA		byte_5A
		JSR		_div16
		LDA		byte_5C
		CLC
		ADC		#<[byte_7A11]
		STA		byte_1E
		LDA		#>[byte_7A11]
		ADC		byte_5B
		STA		byte_1F
loc_7878:
		LDA		#$00
		STA		byte_1A
		LDX		_ppu_queue_buf_pos
		JSR		sub_78A9
		INC		byte_1A
		JSR		sub_78A9
		LDA		#$F8
		STA		byte_1B
		JSR		sub_78CE
		JSR		sub_78CE
		LDA		byte_502
		ORA		#$AA
		STA		byte_502
		LDY		_tmp20w
		CPY		#$0D
		BCS		loc_78A3
		LDA		#$F0
		STA		byte_1B
loc_78A3:
		JSR		sub_78CE
		JMP		sub_9D1E

; =============== S U B	R O U T	I N E =======================================
sub_78A9:
		LDY		#$00
		LDA		(_tmp1Cw),Y
		JSR		sub_9D40
		INY
		LDA		(_tmp1Cw),Y
		CLC
		ADC		byte_1A
		JSR		sub_9D40
		LDA		byte_57
		JSR		sub_9D40
		LDY		#$00
loc_78C0:
		LDA		(byte_1E),Y
		CLC
		ADC		byte_1A
		JSR		sub_9D40
		INY
		CPY		byte_57
		BNE		loc_78C0
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_78CE:
		LDA		#$08
		CLC
		ADC		byte_1B
		STA		byte_1B
		LDY		#$02
		LDA		(_tmp1Cw),Y
		JSR		sub_9D40
		INY
		LDA		(_tmp1Cw),Y
		CLC
		ADC		byte_1B
		JSR		sub_9D40
		LDA		#$01
		JSR		sub_9D40
		LDA		byte_502
		JSR		sub_9D40
		RTS
; ---------------------------------------------------------------------------
byte_78F1:
		.BYTE $20,$7A,$23,$CE,$BB,$01
		.BYTE $20,$78,$23,$CE,$EE,$01
		.BYTE $20,$76,$23,$CD,$BB,$02
		.BYTE $20,$74,$23,$CD,$EE,$02
		.BYTE $20,$72,$23,$CC,$BB,$03
		.BYTE $20,$70,$23,$CC,$EE,$03
		.BYTE $20,$6C,$23,$CB,$EE,$04
		.BYTE $20,$6A,$23,$CA,$BB,$05
		.BYTE $20,$68,$23,$CA,$EE,$05
		.BYTE $20,$66,$23,$C9,$BB,$06
		.BYTE $20,$64,$23,$C9,$EE,$06
		.BYTE $20,$62,$23,$C8,$BB,$07
		.BYTE $22,$82,$23,$E8,$BB,$08
		.BYTE $22,$84,$23,$E9,$EE,$09
		.BYTE $22,$86,$23,$E9,$BB,$09
		.BYTE $22,$88,$23,$EA,$EE,$0A
		.BYTE $22,$8A,$23,$EA,$BB,$0A
		.BYTE $22,$8C,$23,$EB,$EE,$0B
		.BYTE $22,$90,$23,$EC,$EE,$0C
		.BYTE $22,$92,$23,$EC,$BB,$0C
		.BYTE $22,$94,$23,$ED,$EE,$0D
		.BYTE $22,$96,$23,$ED,$BB,$0D
		.BYTE $22,$98,$23,$EE,$EE,$0E
		.BYTE $22,$9A,$23,$EE,$BB,$0E
byte_7981:
		.BYTE $52,$30,$32,$34,$36,$38,$3A,$3C,$3E,$52,$4C,$5C,$34,$36,$38,$3A
		.BYTE $3C,$3E,$52,$4C,$6C,$7C,$36,$38,$3A,$3C,$3E,$52,$4C,$6C,$7C,$4E
		.BYTE $5E,$3A,$3C,$3E,$52,$4C,$6C,$7C,$4E,$6E,$7E,$3C,$3E,$52,$4C,$6C
		.BYTE $7C,$4E,$6E,$7E,$8E,$9E,$E6,$F6,$6C,$7C,$4E,$6E,$7E,$8E,$9E,$E6
		.BYTE $F6,$FC,$BA,$4E,$6E,$7E,$8E,$9E,$E6,$F6,$FC,$E8,$F8,$6E,$7E,$8E
		.BYTE $9E,$E6,$F6,$FC,$E8,$F8,$EA,$FA,$8E,$9E,$E6,$F6,$FC,$E8,$F8,$EA
		.BYTE $BE,$B8,$9E,$EC,$F4,$FC,$E8,$F8,$EA,$BE,$B8,$9E,$EC,$F4,$EE,$FE
		.BYTE $F8,$EA,$BE,$B8,$9E,$EC,$F4,$EE,$C0,$D0,$EA,$BE,$B8,$9E,$EC,$F4
		.BYTE $EE,$C0,$D0,$C2,$D2,$B8,$9E,$EC,$F4,$EE,$C0,$D0,$C2,$BC,$D0,$9E
byte_7A11:
		.BYTE $85,$3C,$3A,$38,$36,$34,$32,$30,$85,$3C,$3A,$38,$36,$34,$8C,$9C
		.BYTE $85,$3C,$3A,$38,$90,$8A,$9A,$9C,$85,$3C,$3A,$88,$98,$8A,$9A,$9C
		.BYTE $85,$92,$94,$96,$98,$8A,$9A,$9C,$70,$80,$94,$96,$98,$8A,$9A,$9C
		.BYTE $70,$80,$94,$96,$98,$8A,$C4,$D4,$70,$80,$94,$96,$C6,$D6,$C4,$D4
		.BYTE $70,$80,$94,$C8,$B0,$D6,$C4,$D4,$70,$CA,$DA,$C8,$B0,$D6,$C4,$D4
		.BYTE $CC,$DC,$DA,$C8,$B0,$D6,$C4,$D4,$CC,$DC,$DA,$C8,$B0,$B4,$CE,$DE
		.BYTE $CC,$DC,$DA,$C8,$AE,$B2,$CE,$DE,$CC,$DC,$E4,$E2,$D8,$B2,$CE,$DE
		.BYTE $CC,$E0,$F0,$E2,$D8,$B2,$CE,$DE,$94,$F2,$F0,$E2,$D8,$B2,$CE,$DE

; =============== S U B	R O U T	I N E =======================================
sub_7A91:
		LDY		#$00
loc_7A93:
		LDA		byte_7AAF,Y
		STA		byte_3C0,Y
		STA		byte_3E0,Y
		INY
		CPY		#$1A
		BNE		loc_7A93
		LDY		#$00
loc_7AA3:
		LDA		byte_7AC9,Y
		STA		byte_502,Y
		INY
		CPY		#$0F
		BNE		loc_7AA3
		RTS
; ---------------------------------------------------------------------------
byte_7AAF:
		.BYTE $00,$02,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$05,$00,$00,$00
		.BYTE $00,$03,$00,$05,$00,$00,$00,$00,$00,$00
byte_7AC9:
		.BYTE $00,$CC,$88,$88,$AA,$22,$22,$66,$AA,$88,$CC,$88,$33,$22,$22

; =============== S U B	R O U T	I N E =======================================
sub_7AD8:
		LDA		#$80
		STA		_spr_buf_pos
		LDA		#<[byte_86EF]
		STA		_tmp1Cw
		LDA		#>[byte_86EF]
		STA		_tmp1Cw+1
		LDA		#$01
		STA		byte_6B
		LDA		byte_420
		LDY		byte_327
		BEQ		loc_7AF3
		LDA		byte_400
loc_7AF3:
		JSR		sub_7B11
		LDA		#$A8
		STA		_spr_buf_pos
		LDA		#<[byte_86DF]
		STA		_tmp1Cw
		LDA		#>[byte_86DF]
		STA		_tmp1Cw+1
		LDA		#$00
		STA		byte_6B
		LDA		byte_400
		LDY		byte_327
		BEQ		sub_7B11
		LDA		byte_420

; =============== S U B	R O U T	I N E =======================================
sub_7B11:
		CMP		#$00
		BEQ		locret_7B63
		LDY		#$00
loc_7B17:
		CMP		#$05
		BCC		loc_7B22
		BEQ		loc_7B22
		INY
		SBC		#$05
		BCS		loc_7B17
loc_7B22:
		STY		word_10
		STA		word_10+1
		INC		word_10+1
		CPY		#$00
		BEQ		loc_7B2E
		LDA		#$05
loc_7B2E:
		TAY
		LDA		byte_6B
		BEQ		loc_7B39
		INY
		INY
		STY		byte_12
		LDY		#$01
loc_7B39:
		LDA		(_tmp1Cw),Y
		STA		byte_68
		LDA		#$00
		STA		byte_69
		LDA		#$78
		STA		byte_66
		LDA		#$00
		STA		byte_67
		LDA		word_10
		CPY		word_10+1
		BCC		loc_7B51
		SBC		#$01
loc_7B51:
		STA		_spr_lib_idx
		JSR		_spr_lib_insert
		LDA		byte_6B
		BEQ		loc_7B60
		INY
		INY
		CPY		byte_12
		BEQ		locret_7B63
loc_7B60:
		DEY
		BNE		loc_7B39
locret_7B63:
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_7B64:
		LDY		#$09
		LDA		_cur_player_idx
		BNE		loc_7B6C
		LDY		#$08
loc_7B6C:
		STY		byte_59
		STY		byte_5A5
		ASL
		ASL
		CLC
		ADC		#<[word_7BDB]
		STA		_tmp1Cw
		LDA		#>[word_7BDB]
		ADC		#$00
		STA		_tmp1Cw+1
		LDA		_cur_player_idx
		EOR		byte_327
		BNE		loc_7B8B
		LDA		byte_419
		JMP		loc_7B8E
; ---------------------------------------------------------------------------
loc_7B8B:
		LDA		byte_439
loc_7B8E:
		STA		byte_5A
		JSR		_div16
		LDY		#$02
		CLC
		LDA		byte_5C
		ADC		(_tmp1Cw),Y
		STA		byte_1E
		INY
		LDA		byte_5B
		ADC		(_tmp1Cw),Y
		STA		byte_1F
		LDA		#$00
		STA		byte_1A
		LDX		_ppu_queue_buf_pos
		JSR		sub_7BB5
		INC		byte_1A
		JSR		sub_7BB5
		JMP		sub_9D1E

; =============== S U B	R O U T	I N E =======================================
sub_7BB5:
		LDY		#$00
		LDA		(_tmp1Cw),Y
		JSR		sub_9D40
		INY
		LDA		(_tmp1Cw),Y
		CLC
		ADC		byte_1A
		JSR		sub_9D40
		LDA		byte_5A5
		JSR		sub_9D40
		DEY
loc_7BCC:
		LDA		(byte_1E),Y
		CLC
		ADC		byte_1A
		JSR		sub_9D40
		INY
		CPY		byte_5A5
		BNE		loc_7BCC
		RTS
; ---------------------------------------------------------------------------
word_7BDB:
		.WORD $9D22
		.WORD byte_7BE3
		.WORD $7D20
		.WORD byte_7C63
byte_7BE3:
		.BYTE $66,$66,$66,$66,$66,$66,$66,$66,$66,$66,$66,$66,$66,$66,$66,$7A
		.BYTE $66,$66,$66,$66,$66,$66,$4A,$5A,$66,$66,$66,$66,$66,$66,$78,$5A
		.BYTE $66,$66,$66,$66,$66,$4A,$58,$5A,$66,$66,$66,$66,$66,$78,$58,$5A
		.BYTE $66,$66,$66,$66,$4A,$58,$58,$5A,$66,$66,$66,$66,$78,$58,$58,$5A
		.BYTE $66,$66,$66,$4A,$58,$58,$58,$5A,$66,$66,$66,$78,$58,$58,$58,$5A
		.BYTE $66,$66,$4A,$58,$58,$58,$58,$5A,$66,$66,$78,$58,$58,$58,$58,$5A
		.BYTE $66,$4A,$58,$58,$58,$58,$58,$5A,$66,$78,$58,$58,$58,$58,$58,$5A
		.BYTE $4A,$58,$58,$58,$58,$58,$58,$5A,$78,$58,$58,$58,$58,$58,$58,$5A
byte_7C63:
		.BYTE $56,$66,$66,$66,$66,$66,$66,$66,$66,$AC,$6A,$66,$66,$66,$66,$66
		.BYTE $66,$66,$48,$68,$66,$66,$66,$66,$66,$66,$66,$48,$5A,$6A,$66,$66
		.BYTE $66,$66,$66,$66,$48,$58,$68,$66,$66,$66,$66,$66,$66,$48,$58,$5A
		.BYTE $6A,$66,$66,$66,$66,$66,$48,$58,$58,$68,$66,$66,$66,$66,$66,$48
		.BYTE $58,$58,$5A,$6A,$66,$66,$66,$66,$48,$58,$58,$58,$68,$66,$66,$66
		.BYTE $66,$48,$58,$58,$58,$5A,$6A,$66,$66,$66,$48,$58,$58,$58,$58,$68
		.BYTE $66,$66,$66,$48,$58,$58,$58,$58,$5A,$6A,$66,$66,$48,$58,$58,$58
		.BYTE $58,$58,$68,$66,$66,$48,$58,$58,$58,$58,$58,$5A,$6A,$66,$48,$58
		.BYTE $58,$58,$58,$58,$58,$68,$66,$48,$58,$58,$58,$58,$58,$58,$5A,$6A

; =============== S U B	R O U T	I N E =======================================
_ingame_sub00:
		JSR		sub_96C5
		LDA		_cur_player_idx
		STA		byte_327
		LDA		byte_304
		BNE		loc_7D0A
		LDA		_cur_player_idx
		CLC
		ADC		#$02
		STA		_nmi_tlm_lib_idx
		STA		byte_304
loc_7D0A:
		LDA		#$00
		STA		byte_30F
		STA		byte_62
		STA		byte_319
		STA		byte_30C
		LDA		#$80
		STA		byte_32E
		STA		byte_332
		STA		byte_333
		STA		byte_334
		LDA		byte_305
		BMI		loc_7D4D
		JSR		sub_97A2
		BEQ		loc_7D4D
		LDA		#$06
		STA		byte_62
		LDA		#$00
		STA		byte_323
		LDA		#$00
		STA		byte_324
		LDA		_cur_player_idx
		STA		byte_325
		LDA		#$01
		STA		byte_305
		LDA		#$00
		STA		byte_322
		RTS
; ---------------------------------------------------------------------------
loc_7D4D:
		LDY		#$06
loc_7D4F:
		LDA		byte_7DBD,Y
		STA		byte_6E,Y
		DEY
		BPL		loc_7D4F
		LDA		#$00
		STA		byte_5E
		STA		byte_6D
		LDA		byte_320
		BNE		loc_7D6F
		LDY		_cur_player_idx
		LDA		_1p_cpu_ctrl_flag,Y
		BNE		loc_7D74
		LDA		_pads_held,Y
		BPL		loc_7D94
loc_7D6F:
		LDA		#$80
		STA		byte_45
		RTS
; ---------------------------------------------------------------------------
loc_7D74:
		LDA		byte_568
		BEQ		loc_7D7F
		LDA		byte_569
		JMP		loc_7D82
; ---------------------------------------------------------------------------
loc_7D7F:
		JSR		_cp_sub01
loc_7D82:
		BEQ		loc_7D6F
		LDY		#$00
		STY		byte_569
		LDA		byte_60
		BNE		loc_7D6F
		LDA		#$01
		STA		byte_320
		LDA		#$40
loc_7D94:
		ASL
		BPL		locret_7DB2
		LDY		_cur_player_idx
		LDA		byte_5D
		CMP		byte_557,Y
		BCS		loc_7DB3
		LDA		byte_31D
		BMI		loc_7DA9
		EOR		_cur_player_idx
		BEQ		loc_7DB3
loc_7DA9:
		LDA		#$01
		STA		byte_320
		LDA		#$0D
		STA		byte_45
locret_7DB2:
		RTS
; ---------------------------------------------------------------------------
loc_7DB3:
		LDY		_cur_player_idx
		LDA		_1p_cpu_ctrl_flag,Y
		BNE		locret_7DB2
		JMP		_apu_play_ctrlB_set04
; ---------------------------------------------------------------------------
byte_7DBD:
		.BYTE $00,$10,$01,$C0,$00,$1E

; =============== S U B	R O U T	I N E =======================================
_ingame_sub01:
		LDA		byte_305
		BPL		loc_7DEB
		LDY		_cur_player_idx
		LDA		_1p_cpu_ctrl_flag,Y
		BNE		loc_7DE2
loc_7DCF:
		LDA		_cur_player_idx
		STA		byte_325
		LDA		#$01
		STA		byte_62
		LDA		#$00
		STA		byte_305
		LDA		#$0C
		STA		byte_45
		RTS
; ---------------------------------------------------------------------------
loc_7DE2:
		INC		byte_5E
		LDA		byte_5E
		CMP		#$70
		BEQ		loc_7DCF
		RTS
; ---------------------------------------------------------------------------
loc_7DEB:
		LDA		#$00
		STA		_spr_buf_pos
		LDA		_cur_player_idx
		STA		byte_6B
		LDA		#<[byte_7E3C]
		STA		_tmp1Cw
		LDA		#>[byte_7E3C]
		STA		_tmp1Cw+1
		LDA		#$00
		JSR		sub_80F0
		LDA		byte_6E
		BNE		loc_7E05
		RTS
; ---------------------------------------------------------------------------
loc_7E05:
		LDA		byte_30F
		BNE		loc_7E10
		JSR		_apu_play_ctrlC_set01
		INC		byte_30F
loc_7E10:
		LDA		byte_6E
		CMP		#$05
		BNE		loc_7E1A
		LDA		#$01
		STA		byte_6E
loc_7E1A:
		INC		byte_5E
		LDA		byte_5E
		CMP		#$10
		BCC		locret_7E32
		LDY		_cur_player_idx
		LDA		_1p_cpu_ctrl_flag,Y
		BNE		loc_7E33
		LDA		byte_60
		BNE		loc_7E33
		LDA		_pads_held,Y
		BPL		loc_7E33
locret_7E32:
		RTS
; ---------------------------------------------------------------------------
loc_7E33:
		LDA		#$00
		STA		byte_6E
		LDA		#$80
		STA		byte_45
		RTS
; ---------------------------------------------------------------------------
byte_7E3C:
		.BYTE $FC,$FE,$1C,$18,$00,$00,$1E,$07,$00,$00,$1D,$07,$00,$00,$1E,$07
		.BYTE $00,$00,$1C,$07

; =============== S U B	R O U T	I N E =======================================
_ingame_sub02:
		LDA		#$00
		STA		_spr_buf_pos
		LDA		_cur_player_idx
		STA		byte_6B
		LDA		#<[byte_7E71]
		STA		_tmp1Cw
		LDA		#>[byte_7E71]
		STA		_tmp1Cw+1
		LDA		#$00
		JSR		sub_80F0
		LDA		byte_6E
		CMP		#$04
		BEQ		loc_7E6C
		RTS
; ---------------------------------------------------------------------------
loc_7E6C:
		LDA		#$80
		STA		byte_45
		RTS
; ---------------------------------------------------------------------------
byte_7E71:
		.BYTE $00,$00,$1E,$07
		.BYTE $00,$00,$1F,$03
		.BYTE $04,$F8,$1F,$01
		.BYTE $00,$00,$1F,$04
		.BYTE $FC,$08,$1F,$01
		.BYTE $FF,$03,$1F,$01

; =============== S U B	R O U T	I N E =======================================
_ingame_sub03:
		LDA		#$00
		STA		_spr_buf_pos
		LDA		_cur_player_idx
		STA		byte_6B
		LDY		#$00
loc_7E93:
		LDA		byte_6F,Y
		STA		byte_66,Y
		INY
		CPY		#$05
		BNE		loc_7E93
		JSR		_spr_lib_insert
		LDY		#$00
loc_7EA3:
		LDA		byte_7EC8,Y
		STA		byte_74,Y
		INY
		CPY		#$0E
		BNE		loc_7EA3
		LDA		#$00
		STA		byte_5E
		STA		byte_6D
		STA		byte_338
		STA		byte_339
		JSR		_dice_roll_init
		JSR		_dice_roll_rand
		JSR		_apu_play_ctrlC_set02
		LDA		#$80
		STA		byte_45
		RTS
; ---------------------------------------------------------------------------
byte_7EC8:
		.BYTE $00,$00
		.BYTE $AE,$00
		.BYTE $70,$00
		.BYTE $10,$00
		.BYTE $00,$BA
		.BYTE $00,$7C
		.BYTE $00,$10

; =============== S U B	R O U T	I N E =======================================
_ingame_sub04:
		LDA		byte_5E
		INC		byte_5E
		CMP		#$30
		BCS		loc_7F02
		LDA		#$05
		STA		byte_6E
		LDA		byte_5E
		BNE		loc_7EEA
		LDA		#$04
		STA		byte_6E
loc_7EEA:
		LDA		#$00
		STA		_spr_buf_pos
		LDA		_cur_player_idx
		STA		byte_6B
		LDA		#<[byte_7E71]
		STA		_tmp1Cw
		LDA		#>[byte_7E71]
		STA		_tmp1Cw+1
		LDA		#$00
		STA		byte_335
		JSR		sub_80F0
loc_7F02:
		LDA		byte_338
		LSR
		BCS		loc_7F37
		LDA		_cur_player_idx
		STA		byte_6B
		LDA		#$E0
		STA		_spr_buf_pos
		LDA		byte_342
		STA		_tmp1Cw
		LDA		byte_343
		STA		_tmp1Cw+1
		LDA		byte_75
		ASL
		CLC
		ADC		byte_75
		TAY
loc_7F21:
		LDA		(_tmp1Cw),Y
		CMP		#$80
		BEQ		loc_7F32
		LDA		#$01
		STA		byte_335
		JSR		sub_80F0
		JMP		loc_7F51
; ---------------------------------------------------------------------------
loc_7F32:
		LDA		#$01
		STA		byte_338
loc_7F37:
		LDA		byte_46
		CLC
		ADC		#$11
		STA		_spr_lib_idx
		STA		byte_7A
		LDA		_cur_player_idx
		STA		byte_330
		STA		byte_332
		LDA		byte_60
		BEQ		loc_7F51
		LDA		#$00
		STA		byte_330
loc_7F51:
		LDA		byte_339
		LSR
		BCS		loc_7F85
		LDA		_cur_player_idx
		STA		byte_6B
		LDA		#$D0
		STA		_spr_buf_pos
		LDA		byte_344
		STA		_tmp1Cw
		LDA		byte_345
		STA		_tmp1Cw+1
		LDA		byte_7C
		ASL
		CLC
		ADC		byte_7C
		TAY
		LDA		(_tmp1Cw),Y
		CMP		#$80
		BEQ		loc_7F80
		LDA		#$01
		STA		byte_335
		LDA		#$02
		JMP		sub_80F0
; ---------------------------------------------------------------------------
loc_7F80:
		LDA		#$01
		STA		byte_339
loc_7F85:
		LDA		byte_47
		CLC
		ADC		#$11
		STA		_spr_lib_idx
		STA		byte_81
		LDA		_cur_player_idx
		STA		byte_331
		STA		byte_333
		LDA		byte_60
		BEQ		loc_7F9F
		LDA		#$01
		STA		byte_331
loc_7F9F:
		LDA		byte_5E
		CMP		#$30
		BCC		locret_7FB7
		LDA		byte_338
		AND		byte_339
		LSR
		BCC		locret_7FB7
		LDA		#$80
		STA		byte_45
		LDA		#$00
		STA		byte_335
locret_7FB7:
		RTS
; ---------------------------------------------------------------------------
off_7FB8:
		.WORD byte_7FC8
		.WORD byte_7FD5
		.WORD byte_7FF1
		.WORD byte_801C
off_7FC0:
		.WORD byte_8050
		.WORD byte_806C
		.WORD byte_8091
		.WORD byte_80BC
byte_7FC8:
		.BYTE $FF,$FE,$10
		.BYTE $00,$FE,$11
		.BYTE $01,$FE,$08
		.BYTE $FF,$FE,$09
		.BYTE $80
byte_7FD5:
		.BYTE $FE,$FE,$0A
		.BYTE $FF,$FE,$0B
		.BYTE $00,$FE,$0C
		.BYTE $01,$FE,$0D
		.BYTE $02,$FE,$0E
		.BYTE $FF,$FE,$0F
		.BYTE $00,$FE,$10
		.BYTE $01,$FE,$11
		.BYTE $00,$FE,$08
		.BYTE $80
byte_7FF1:
		.BYTE $FE,$FE,$09
		.BYTE $FF,$FE,$0A
		.BYTE $00,$FE,$0B
		.BYTE $01,$FE,$0C
		.BYTE $02,$FE,$0D
		.BYTE $FE,$FE,$0E
		.BYTE $FF,$FE,$0F
		.BYTE $00,$FE,$10
		.BYTE $01,$FE,$11
		.BYTE $02,$FE,$08
		.BYTE $FF,$02,$09
		.BYTE $00,$02,$0A
		.BYTE $01,$02,$0B
		.BYTE $FF,$02,$0C
		.BYTE $80
byte_801C:
		.BYTE $FE,$FE,$0D
		.BYTE $FF,$FE,$0E
		.BYTE $00,$FE,$0F
		.BYTE $01,$FE,$10
		.BYTE $02,$FE,$11
		.BYTE $FE,$FE,$08
		.BYTE $FF,$FE,$09
		.BYTE $00,$FE,$0A
		.BYTE $01,$FE,$0B
		.BYTE $02,$FE,$0C
		.BYTE $FF,$02,$0D
		.BYTE $00,$02,$0E
		.BYTE $01,$02,$0F
		.BYTE $FF,$02,$10
		.BYTE $00,$02,$11
		.BYTE $01,$02,$08
		.BYTE $00,$02,$09
		.BYTE $80
byte_8050:
		.BYTE $FF,$FE,$0A
		.BYTE $00,$FE,$0B
		.BYTE $01,$FE,$0C
		.BYTE $02,$FE,$0D
		.BYTE $03,$FE,$0E
		.BYTE $00,$FE,$0F
		.BYTE $01,$FE,$10
		.BYTE $02,$FE,$11
		.BYTE $FF,$FE,$08
		.BYTE $80
byte_806C:
		.BYTE $FF,$FE,$09
		.BYTE $00,$FE,$0A
		.BYTE $01,$FE,$0B
		.BYTE $02,$FE,$0C
		.BYTE $03,$FE,$0D
		.BYTE $00,$FE,$0E
		.BYTE $01,$FE,$0F
		.BYTE $02,$FE,$10
		.BYTE $FF,$FE,$11
		.BYTE $00,$FE,$08
		.BYTE $01,$FE,$09
		.BYTE $00,$FE,$0A
		.BYTE $80
byte_8091:
		.BYTE $FF,$FE,$0B
		.BYTE $00,$FE,$0C
		.BYTE $01,$FE,$0D
		.BYTE $02,$FE,$0E
		.BYTE $03,$FE,$0F
		.BYTE $FE,$FE,$10
		.BYTE $FF,$FE,$11
		.BYTE $00,$FE,$08
		.BYTE $01,$FE,$09
		.BYTE $02,$FE,$0A
		.BYTE $FF,$FE,$0B
		.BYTE $00,$FE,$0C
		.BYTE $01,$FE,$0D
		.BYTE $01,$02,$0E
		.BYTE $80
byte_80BC:
		.BYTE $FF,$FE,$0F
		.BYTE $00,$FE,$10
		.BYTE $01,$FE,$11
		.BYTE $02,$FE,$08
		.BYTE $03,$FE,$09
		.BYTE $FE,$FE,$0A
		.BYTE $FF,$FE,$0B
		.BYTE $00,$FE,$0C
		.BYTE $01,$FE,$0D
		.BYTE $02,$FE,$0E
		.BYTE $FF,$FE,$0F
		.BYTE $00,$FE,$10
		.BYTE $01,$FE,$11
		.BYTE $00,$02,$08
		.BYTE $01,$02,$09
		.BYTE $02,$02,$0A
		.BYTE $00,$02,$0B
		.BYTE $80

; =============== S U B	R O U T	I N E =======================================
sub_80F0:
		STA		word_10
		ASL
		ASL
		ASL
		SEC
		SBC		word_10
		TAX
		LDA		byte_6E,X
		ASL
		ASL
		LDY		byte_335
		BEQ		loc_8105
		SEC
		SBC		byte_6E,X
loc_8105:
		TAY
		LDA		(_tmp1Cw),Y
		BPL		loc_810C
		DEC		byte_72,X
loc_810C:
		CLC
		ADC		byte_71,X
		STA		byte_71,X
		LDA		byte_72,X
		ADC		#$00
		STA		byte_72,X
		INY
		LDA		(_tmp1Cw),Y
		BPL		loc_811E
		DEC		byte_70,X
loc_811E:
		CLC
		ADC		byte_6F,X
		STA		byte_6F,X
		LDA		byte_70,X
		ADC		#$00
		STA		byte_70,X
		INY
		LDA		(_tmp1Cw),Y
		STA		byte_73,X
		INY
		STX		word_10
		STY		word_10+1
		LDY		#$00
loc_8135:
		LDA		byte_6F,X
		STA		byte_66,Y
		INX
		INY
		CPY		#$05
		BNE		loc_8135
		JSR		_spr_lib_insert
		LDX		word_10
		LDY		word_10+1
		LDA		byte_6D,X
		BEQ		loc_8152
		DEC		byte_6D,X
		BNE		locret_8151
		INC		byte_6E,X
locret_8151:
		RTS
; ---------------------------------------------------------------------------
loc_8152:
		LDA		byte_335
		BNE		loc_8159
		LDA		(_tmp1Cw),Y
loc_8159:
		STA		byte_6D,X
		RTS

; =============== S U B	R O U T	I N E =======================================
_dice_roll_init:
		LDA		byte_30C
		BNE		locret_81CE
		JSR		sub_9C94
		LDY		#$00
loc_8166:
		CMP		#$24
		BCC		loc_816F
		SBC		#$24
		INY
		BCS		loc_8166
loc_816F:
		STA		word_10
		TYA
		STA		word_10+1
		ASL
		ASL
		ASL
		SEC
		SBC		word_10+1
		CLC
		ADC		word_10
		CMP		#$24
		BCC		loc_8183
		SBC		#$24
loc_8183:
		TAY
		LDA		byte_81CF,Y
		PHA
		LSR
		LSR
		LSR
		LSR
		STA		byte_46
		PLA
		AND		#$0F
		STA		byte_47
		LDA		byte_568
		BNE		loc_81A6
		LDA		_cheat_flag1_w
		BEQ		loc_81A6
		LDA		_pads_held
		CMP		#$0A
		BNE		loc_81A6
		JSR		_cp_sub03_field_and_dice_editor
loc_81A6:
		LDA		byte_568
		ORA		byte_57B
		BEQ		loc_81BD
		LDA		_1p_first_dice_roll_override
		STA		byte_46
		LDA		_2p_first_dice_roll_override
		STA		byte_47
		LDA		#$00
		STA		byte_57B
loc_81BD:
		LDA		byte_47
		LDY		#$00
		CMP		byte_46
		BNE		loc_81C6
		INY
loc_81C6:
		STY		byte_48
		LDA		#$00
		STA		byte_4A
		STA		byte_49
locret_81CE:
		RTS
; ---------------------------------------------------------------------------
byte_81CF:
		.BYTE $14,$66,$36,$65,$63,$11,$23,$33,$16,$31,$21,$53,$51,$61,$62,$35
		.BYTE $44,$22,$12,$32,$55,$34,$56,$25,$13,$43,$41,$42,$46,$15,$24,$52
		.BYTE $45,$26,$64,$54

; =============== S U B	R O U T	I N E =======================================
_dice_roll_rand:
		LDA		byte_48
		BNE		loc_81FD
		LDA		byte_60
		BNE		loc_8201
		BEQ		loc_820B
loc_81FD:
		LDA		#$03
		BNE		loc_8210
loc_8201:
		JSR		_increment_rand_seed
		AND		#$01
		CLC
		ADC		#$02
		BNE		loc_8210
loc_820B:
		JSR		_increment_rand_seed
		AND		#$03
loc_8210:
		ASL
		TAY
		LDA		off_7FB8,Y
		STA		byte_342
		LDA		off_7FB8+1,Y
		STA		byte_343
		LDA		byte_60
		BEQ		loc_822C
		JSR		_increment_rand_seed
		AND		#$01
		CLC
		ADC		#$02
		BNE		loc_8231
loc_822C:
		JSR		_increment_rand_seed
		AND		#$03
loc_8231:
		ASL
		TAY
		LDA		off_7FC0,Y
		STA		byte_344
		LDA		off_7FC0+1,Y
		STA		byte_345
		RTS

; =============== S U B	R O U T	I N E =======================================
_ingame_sub05:
		LDA		#$10
		STA		byte_340
		LDA		#$00
		STA		byte_49
		STA		byte_4A
		JSR		sub_9752
		BNE		loc_82AF
		LDY		_cur_player_idx
		LDA		_1p_cpu_ctrl_flag,Y
		BEQ		loc_826B
		LDA		#$00
		STA		byte_321
		LDA		byte_568
		BNE		loc_8264
		JSR		_cp_sub00
loc_8264:
		LDY		byte_321
		LDA		byte_A2,Y
		TAX
loc_826B:
		TXA
		TAY
		LDA		byte_400,Y
		STY		byte_61
		JSR		sub_8655
		STX		byte_6F
		STX		byte_84
		STY		byte_86
		LDA		#$F0
		LDY		_cur_player_idx
		BEQ		loc_8283
		LDA		#$00
loc_8283:
		STA		byte_71
		LDA		#$00
		STA		byte_70
		STA		byte_72
		STA		byte_85
		STA		byte_87
		STA		byte_5E
		STA		byte_6B
		STA		byte_65
		STA		byte_5F
		STA		byte_334
		STA		byte_303
		LDA		#$00
		STA		byte_64
		LDA		#$20
		STA		byte_73
		STA		byte_88
		JSR		sub_871F
		LDA		#$80
		STA		byte_45
		RTS
; ---------------------------------------------------------------------------
loc_82AF:
		LDA		_cur_player_idx
		EOR		#$01
		TAX
		BEQ		loc_82B8
		LDA		#$07
loc_82B8:
		TAY
		LDA		byte_76,Y
		LDY		byte_330,X
		BEQ		loc_82C6
		EOR		#$FF
		SEC
		ADC		#$F0
loc_82C6:
		STA		byte_6F
		LDA		#$F0
		LDY		_cur_player_idx
		BEQ		loc_82D0
		LDA		#$00
loc_82D0:
		STA		byte_71
		LDA		#$00
		STA		byte_70
		STA		byte_72
		STA		byte_336
		LDA		#$20
		STA		byte_73
		LDA		#$01
		STA		byte_306
		LDA		#$1E
		STA		byte_45
		RTS

; =============== S U B	R O U T	I N E =======================================
_ingame_sub06:
		LDA		byte_64
		STA		_spr_buf_pos
		LDA		byte_65
		STA		byte_6B
		LDA		byte_5E
		INC		byte_5E
		CMP		byte_337
		BNE		loc_82FD
		JMP		loc_836D
; ---------------------------------------------------------------------------
loc_82FD:
		JSR		sub_87C3
		LDA		#<[byte_346]
		STA		_tmp1Cw
		LDA		#>[byte_346]
		STA		_tmp1Cw+1
		LDA		byte_5F
		PHA
		ASL
		ASL
		ASL
		SEC
		SBC		byte_5F
		TAX
		LDA		#$00
		STA		byte_6E,X
		PLA
		JSR		sub_80F0
		LDA		byte_332
		BMI		loc_8343
		LDY		_cur_player_idx
		LDA		byte_60
		BEQ		loc_8327
		LDY		#$00
loc_8327:
		LDA		byte_30B
		BNE		loc_8340
		LDA		byte_48
		BNE		loc_8340
		LDA		byte_49
		BNE		loc_8340
		LDA		byte_5E
		AND		#$1F
		CMP		#$0A
		BCS		loc_8340
		TYA
		EOR		#$01
		TAY
loc_8340:
		STY		byte_332
loc_8343:
		LDA		byte_333
		BMI		locret_836C
		LDY		_cur_player_idx
		LDA		byte_60
		BEQ		loc_8350
		LDY		#$01
loc_8350:
		LDA		byte_30B
		BNE		loc_8369
		LDA		byte_48
		BNE		loc_8369
		LDA		byte_49
		BEQ		loc_8369
		LDA		byte_5E
		AND		#$1F
		CMP		#$0A
		BCS		loc_8369
		TYA
		EOR		#$01
		TAY
loc_8369:
		STY		byte_333
locret_836C:
		RTS
; ---------------------------------------------------------------------------
loc_836D:
		LDA		#<[byte_6F]
		STA		_tmp1Cw
		LDA		#>[byte_6F]
		STA		_tmp1Cw+1
		LDA		byte_5F
		ASL
		ASL
		ASL
		SEC
		SBC		byte_5F
		CLC
		ADC		_tmp1Cw
		STA		_tmp1Cw
		LDA		#$00
		ADC		_tmp1Cw+1
		STA		_tmp1Cw+1
		LDY		#$00
loc_838A:
		LDA		byte_84,Y
		STA		(_tmp1Cw),Y
		STA		byte_66,Y
		INY
		CPY		#$05
		BNE		loc_838A
		JSR		_spr_lib_insert
		LDA		#$00
		STA		byte_5E
		STA		byte_336
		LDA		#$07
		STA		byte_45
		RTS

; =============== S U B	R O U T	I N E =======================================
_ingame_sub07:
		LDA		#$00
		STA		byte_32E
		STA		byte_30B
		LDA		#$10
		STA		byte_340
		LDY		_cur_player_idx
		LDA		_1p_cpu_ctrl_flag,Y
		BNE		loc_83C5
		LDA		_pad_tmp2,Y
		AND		#$0F
		ORA		_pads_press,Y
		JMP		loc_840B
; ---------------------------------------------------------------------------
loc_83C5:
		LDA		#$30
		STA		byte_340
		LDY		byte_321
		LDA		byte_9E,Y
		LDY		byte_49
		CMP		byte_46,Y
		BEQ		loc_83DB
		LDA		#$40
		BNE		loc_840B
loc_83DB:
		LDY		byte_321
		LDA		byte_A2,Y
		CMP		byte_61
		BNE		loc_83F8
		LDA		#$00
		INC		byte_336
		LDX		byte_336
		CPX		#$14
		BNE		loc_840B
		STA		byte_336
		LDA		#$80
		BNE		loc_840B
loc_83F8:
		TAY
		LDA		#$00
		INC		byte_336
		LDX		byte_336
		CPX		#$0A
		BNE		loc_840B
		STA		byte_336
		JMP		loc_8623
; ---------------------------------------------------------------------------
loc_840B:
		LDY		_cur_player_idx
		STA		_pads_press,Y
		LDY		byte_400
		BEQ		loc_8425
		AND		#$F0
		LDY		_cur_player_idx
		STA		_pads_press,Y
		LDY		byte_61
		BEQ		loc_8425
		LDY		#$00
		JMP		loc_8623
; ---------------------------------------------------------------------------
loc_8425:
		LDY		byte_61
		CPY		#$19
		BNE		loc_8435
		AND		#$0D
		BEQ		loc_8435
		JSR		sub_9752
		JMP		loc_8621
; ---------------------------------------------------------------------------
loc_8435:
		LDY		_cur_player_idx
		LDA		_pads_press,Y
		LSR
		BCC		loc_8474
		LDA		byte_61
		TAY
		CMP		#$0D
		BCC		loc_845C
		CMP		#$18
		BNE		loc_844B
		JMP		loc_8529
; ---------------------------------------------------------------------------
loc_844B:
		LDA		byte_401,Y
		BEQ		loc_8454
		INY
		JMP		loc_8623
; ---------------------------------------------------------------------------
loc_8454:
		INY
		CPY		#$18
		BNE		loc_844B
		JMP		loc_8529
; ---------------------------------------------------------------------------
loc_845C:
		CMP		#$01
		BNE		loc_8463
		JMP		loc_8529
; ---------------------------------------------------------------------------
loc_8463:
		LDA		byte_3FF,Y
		BEQ		loc_846C
		DEY
		JMP		loc_8623
; ---------------------------------------------------------------------------
loc_846C:
		DEY
		CPY		#$01
		BNE		loc_8463
		JMP		loc_8529
; ---------------------------------------------------------------------------
loc_8474:
		LSR
		BCC		loc_84AD
		LDA		byte_61
		TAY
		CMP		#$0D
		BCC		loc_8496
		CMP		#$0D
		BNE		loc_8485
		JMP		loc_8529
; ---------------------------------------------------------------------------
loc_8485:
		LDA		byte_3FF,Y
		BEQ		loc_848E
		DEY
		JMP		loc_8623
; ---------------------------------------------------------------------------
loc_848E:
		DEY
		CPY		#$0D
		BNE		loc_8485
		JMP		loc_8529
; ---------------------------------------------------------------------------
loc_8496:
		CMP		#$0C
		BNE		loc_849D
		JMP		loc_8529
; ---------------------------------------------------------------------------
loc_849D:
		LDA		byte_401,Y
		BEQ		loc_84A6
		INY
		JMP		loc_8623
; ---------------------------------------------------------------------------
loc_84A6:
		INY
		CPY		#$0C
		BNE		loc_849D
		BEQ		loc_8529
loc_84AD:
		LSR
		BCC		loc_84EC
		LDY		_cur_player_idx
		LDA		_1p_cpu_ctrl_flag,Y
		EOR		#$FF
		AND		_cur_player_idx
		BNE		loc_84FA
loc_84BB:
		LDA		byte_61
		CMP		#$0D
		BCS		loc_8529
		EOR		#$FF
		SEC
		ADC		#$19
		TAY
		TAX
		DEX
loc_84C9:
		CPY		#$19
		BEQ		loc_84D6
loc_84CD:
		LDA		byte_400,Y
		BEQ		loc_84D5
		JMP		loc_8623
; ---------------------------------------------------------------------------
loc_84D5:
		INY
loc_84D6:
		CPX		#$0C
		BEQ		loc_84E6
		LDA		byte_400,X
		BEQ		loc_84E2
		JMP		loc_8621
; ---------------------------------------------------------------------------
loc_84E2:
		DEX
		JMP		loc_84C9
; ---------------------------------------------------------------------------
loc_84E6:
		CPY		#$19
		BNE		loc_84CD
		BEQ		loc_8529
loc_84EC:
		LSR
		BCC		loc_8529
		LDY		_cur_player_idx
		LDA		_1p_cpu_ctrl_flag,Y
		EOR		#$FF
		AND		_cur_player_idx
		BNE		loc_84BB
loc_84FA:
		LDA		byte_61
		CMP		#$0D
		BCC		loc_8529
		EOR		#$FF
		SEC
		ADC		#$19
		TAY
		TAX
		DEX
loc_8508:
		CPY		#$0D
		BEQ		loc_8515
loc_850C:
		LDA		byte_400,Y
		BEQ		loc_8514
		JMP		loc_8623
; ---------------------------------------------------------------------------
loc_8514:
		INY
loc_8515:
		CPX		#$00
		BEQ		loc_8525
		LDA		byte_400,X
		BEQ		loc_8521
		JMP		loc_8621
; ---------------------------------------------------------------------------
loc_8521:
		DEX
		JMP		loc_8508
; ---------------------------------------------------------------------------
loc_8525:
		CPY		#$0D
		BNE		loc_850C
loc_8529:
		INC		byte_5E
		LDY		_cur_player_idx
		LDA		_pads_press,Y
		BPL		loc_853A
		LDA		#$00
		STA		byte_303
		JMP		loc_861C
; ---------------------------------------------------------------------------
loc_853A:
		ASL
		BPL		loc_855F
		LDA		#$00
		STA		byte_303
		LDA		byte_4A
		BEQ		loc_854B
		DEC		byte_4A
		JMP		loc_8BBD
; ---------------------------------------------------------------------------
loc_854B:
		LDA		byte_48
		BNE		loc_855F
		LDY		_cur_player_idx
		LDA		_1p_cpu_ctrl_flag,Y
		BNE		loc_8559
		JSR		_apu_play_ctrlB_set20
loc_8559:
		LDA		byte_49
		EOR		#$01
		STA		byte_49
loc_855F:
		LDY		_cur_player_idx
		LDA		byte_60
		BEQ		loc_8567
		LDY		#$00
loc_8567:
		LDA		byte_48
		BNE		loc_857B
		LDA		byte_49
		BNE		loc_857B
		LDA		byte_5E
		AND		#$1F
		CMP		#$0A
		BCS		loc_857B
		TYA
		EOR		#$01
		TAY
loc_857B:
		STY		byte_332
		LDY		_cur_player_idx
		LDA		byte_60
		BEQ		loc_8586
		LDY		#$01
loc_8586:
		LDA		byte_48
		BNE		loc_859A
		LDA		byte_49
		BEQ		loc_859A
		LDA		byte_5E
		AND		#$1F
		CMP		#$0A
		BCS		loc_859A
		TYA
		EOR		#$01
		TAY
loc_859A:
		STY		byte_333
		LDA		#$00
		STA		byte_6B
		LDA		#$00
		STA		_spr_buf_pos
		LDA		byte_568
		BNE		locret_861B
		LDY		_cur_player_idx
		LDA		_1p_cpu_ctrl_flag,Y
		BNE		locret_861B
		LDA		byte_5E
		AND		#$0F
		CMP		#$06
		BCC		locret_861B
		LDA		byte_303
		BMI		locret_861B
		BNE		loc_85CF
		LDA		byte_61
		JSR		loc_97B5
		BEQ		loc_85CC
		DEC		byte_303
		BMI		locret_861B
loc_85CC:
		INC		byte_303
loc_85CF:
		LDY		byte_49
		LDA		byte_46,Y
		CLC
		ADC		byte_61
		TAY
		CPY		#$19
		BCC		loc_85E0
		LDY		#$19
		BNE		loc_85E5
loc_85E0:
		LDA		byte_420,Y
		BNE		loc_85E8
loc_85E5:
		LDA		byte_400,Y
loc_85E8:
		CLC
		ADC		#$01
		LDX		#$06
		STX		_spr_lib_idx
		CPY		#$19
		BNE		loc_8603
		LDX		#$03
		STX		_spr_lib_idx
		LDX		_cur_player_idx
		BNE		loc_8603
		CMP		#$01
		BEQ		loc_8601
		INC		_spr_lib_idx
loc_8601:
		INC		_spr_lib_idx
loc_8603:
		JSR		sub_8655
		STX		byte_66
		STY		byte_68
		LDA		#$00
		STA		byte_67
		STA		byte_69
		LDA		_cur_player_idx
		STA		byte_6B
		LDA		#$78
		STA		_spr_buf_pos
		JSR		_spr_lib_insert
locret_861B:
		RTS
; ---------------------------------------------------------------------------
loc_861C:
		LDA		#$08
		STA		byte_45
		RTS
; ---------------------------------------------------------------------------
loc_8621:
		TXA
		TAY
loc_8623:
		STY		byte_61
		LDA		byte_400,Y
		JSR		sub_8655
		STX		byte_84
		STY		byte_86
		LDA		#$00
		STA		byte_85
		STA		byte_87
		STA		byte_5E
		LDA		#$20
		STA		byte_73
		STA		byte_88
		JSR		sub_871F
		LDA		#$06
		STA		byte_45
		LDA		#$00
		STA		byte_65
		STA		byte_303
		LDA		#$00
		STA		byte_64
		JSR		_apu_play_ctrlB_set10
		JMP		_ingame_sub06

; =============== S U B	R O U T	I N E =======================================
sub_8655:
		CPY		#$00
		BEQ		loc_8689
		CPY		#$19
		BEQ		loc_869C
		PHA
		LDA		_cur_player_idx
		BEQ		loc_8669
		TYA
		EOR		#$FF
		SEC
		ADC		#$19
		TAY
loc_8669:
		PLA
		CPY		#$0D
		BCC		loc_8680
		PHA
		TYA
		EOR		#$FF
		SEC
		ADC		#$19
		TAY
		LDX		byte_86B1,Y
		PLA
		TAY
		LDA		byte_86BF,Y
		TAY
		RTS
; ---------------------------------------------------------------------------
loc_8680:
		LDX		byte_86B1,Y
		TAY
		LDA		byte_86CF,Y
		TAY
		RTS
; ---------------------------------------------------------------------------
loc_8689:
		LDX		byte_86B1,Y
		TAY
		LDA		_cur_player_idx
		BEQ		loc_8697
		LDA		byte_86EF,Y
		JMP		loc_869A
; ---------------------------------------------------------------------------
loc_8697:
		LDA		byte_86DF,Y
loc_869A:
		TAY
		RTS
; ---------------------------------------------------------------------------
loc_869C:
		LDY		#$0D
		LDX		byte_86B1,Y
		TAY
		LDA		_cur_player_idx
		BEQ		loc_86AC
		LDA		byte_870F,Y
		JMP		loc_86AF
; ---------------------------------------------------------------------------
loc_86AC:
		LDA		byte_86FF,Y
loc_86AF:
		TAY
		RTS
; ---------------------------------------------------------------------------
byte_86B1:
		.BYTE $78,$D8,$C8,$B8,$A8,$98,$88,$68,$58,$48,$38,$28,$18,$EE
byte_86BF:
		.BYTE $DF,$D3,$C7,$BB,$AF,$A3,$D1,$C5,$B9,$AD,$A1,$CF,$C3,$B7,$AB,$9F
byte_86CF:
		.BYTE $2C,$20,$2C,$38,$44,$50,$1E,$2A,$36,$42,$4E,$1C,$28,$34,$40,$4C
byte_86DF:
		.BYTE $E0,$98,$A4,$B0,$BC,$C8,$96,$A2,$AE,$BA,$C6,$84,$A0,$AC,$B8,$C4
byte_86EF:
		.BYTE $2C,$5C,$50,$44,$38,$2C,$5A,$4E,$42,$36,$2A,$58,$4C,$40,$34,$28
byte_86FF:
		.BYTE $E0,$D5,$D1,$CD,$C9,$C5,$C1,$BD,$B9,$B5,$B1,$AD,$A9,$A5,$A1,$9D
byte_870F:
		.BYTE $2C,$19,$1D,$21,$25,$29,$2D,$31,$35,$39,$3D,$41,$45,$49,$4D,$51

; =============== S U B	R O U T	I N E =======================================
sub_871F:
		JSR		sub_8861

; =============== S U B	R O U T	I N E =======================================
sub_8722:
		LDA		#$00
		STA		byte_33E
		STA		byte_33F
		LDA		byte_5F
		ASL
		ASL
		ASL
		SEC
		SBC		byte_5F
		PHA
		TAX
		LDA		byte_84
		SEC
		SBC		byte_6F,X
		STA		word_10
		LDA		byte_85
		SBC		byte_70
		STA		word_10+1
		BPL		loc_8755
		LDA		#$00
		SEC
		SBC		word_10
		STA		word_10
		LDA		#$00
		SBC		word_10+1
		STA		word_10+1
		LDA		#$80
		STA		byte_33E
loc_8755:
		JSR		sub_879C
		LDA		word_10
		STA		byte_33A
		LDA		word_10+1
		STA		byte_33B
		PLA
		TAX
		LDA		byte_86
		SEC
		SBC		byte_71,X
		STA		word_10
		LDA		byte_87
		SBC		byte_72
		STA		word_10+1
		BPL		loc_8785
		LDA		#$00
		SEC
		SBC		word_10
		STA		word_10
		LDA		#$00
		SBC		word_10+1
		STA		word_10+1
		LDA		#$80
		STA		byte_33F
loc_8785:
		JSR		sub_879C
		LDA		word_10
		STA		byte_33C
		LDA		word_10+1
		STA		byte_33D
		LDA		byte_341
		STA		byte_337
		DEC		byte_337
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_879C:
		LDA		byte_341
		STA		byte_14
		LDA		#$00
		STA		byte_13
		STA		byte_12
		LDX		#$20
		BNE		loc_87B9
loc_87AB:
		ROL		byte_12
		LDA		byte_12
		CMP		byte_14
		BCC		loc_87B9
		LDA		byte_12
		SBC		byte_14
		STA		byte_12
loc_87B9:
		ROL		byte_13
		ROL		word_10
		ROL		word_10+1
		DEX
		BPL		loc_87AB
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_87C3:
		LDA		byte_33C
		STA		word_10+1
		LDA		byte_33D
		STA		byte_12
		LDA		byte_5E
		STA		word_10
		JSR		sub_8847
		LDA		byte_14
		STA		byte_15
		LDA		byte_33C
		STA		word_10+1
		LDA		byte_33D
		STA		byte_12
		DEC		word_10
		JSR		sub_8847
		LDA		byte_33F
		BMI		loc_87F3
		LDA		byte_15
		SEC
		SBC		byte_14
		BCS		loc_87F8
loc_87F3:
		LDA		byte_14
		SEC
		SBC		byte_15
loc_87F8:
		STA		byte_346
		LDA		byte_33A
		STA		word_10+1
		LDA		byte_33B
		STA		byte_12
		LDA		byte_5E
		STA		word_10
		JSR		sub_8847
		LDA		byte_14
		STA		byte_15
		LDA		byte_33A
		STA		word_10+1
		LDA		byte_33B
		STA		byte_12
		DEC		word_10
		JSR		sub_8847
		LDA		byte_33E
		BMI		loc_882B
		LDA		byte_15
		SEC
		SBC		byte_14
		BCS		loc_8830
loc_882B:
		LDA		byte_14
		SEC
		SBC		byte_15
loc_8830:
		STA		byte_347
		LDA		byte_5F
		ASL
		ASL
		ASL
		SEC
		SBC		byte_5F
		TAX
		LDA		byte_73,X
		STA		byte_348
		LDA		#$00
		STA		byte_349
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_8847:
		LDA		#$00
		STA		byte_13
		STA		byte_14
		LDX		#$10
loc_884F:
		ROR		byte_12
		ROR		word_10+1
		BCC		loc_8858
		CLC
		ADC		word_10
loc_8858:
		ROR
		ROR		byte_14
		ROR		byte_13
		DEX
		BNE		loc_884F
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_8861:
		LDA		byte_5F
		ASL
		ASL
		ASL
		SEC
		SBC		byte_5F
		PHA
		TAX
		LDA		byte_84
		SEC
		SBC		byte_6F,X
		STA		word_10
		LDA		byte_85
		SBC		byte_70
		STA		word_10+1
		BPL		loc_8881
		LDA		#$00
		SEC
		SBC		word_10
		STA		word_10
loc_8881:
		LDY		#$00
		LDA		word_10
		CMP		#$28
		BCC		loc_8899
		INY
		CMP		#$58
		BCC		loc_8899
		INY
		CMP		#$98
		BCC		loc_8899
		INY
		CMP		#$C8
		BCC		loc_8899
		INY
loc_8899:
		STY		byte_12
		PLA
		TAX
		LDA		byte_86
		SEC
		SBC		byte_71,X
		STA		word_10
		LDA		byte_87
		SBC		byte_72
		STA		word_10+1
		BPL		loc_88B3
		LDA		#$00
		SEC
		SBC		word_10
		STA		word_10
loc_88B3:
		LDY		byte_12
		LDA		word_10
		CMP		#$20
		BCC		loc_88C1
		INC		byte_12
		INC		byte_12
		INC		byte_12
loc_88C1:
		LDA		byte_340
		LSR
		LSR
		LSR
		STA		byte_13
		LDY		byte_12
		BEQ		loc_88D3
loc_88CD:
		CLC
		ADC		byte_13
		DEY
		BNE		loc_88CD
loc_88D3:
		STA		byte_341
		RTS

; =============== S U B	R O U T	I N E =======================================
_ingame_sub08:
		LDA		byte_420
		STA		byte_31A
		LDA		byte_61
		JSR		sub_97C5
		BEQ		loc_88EC
		JSR		_apu_play_ctrlB_set04
		LDA		#$07
		STA		byte_45
		RTS
; ---------------------------------------------------------------------------
loc_88EC:
		LDA		byte_4A
		TAY
		LDA		byte_61
		STA		byte_310,Y
		LDA		#$00
		ROL
		STA		byte_30D
		STA		byte_319
		LDA		byte_61
		BEQ		loc_8904
		JSR		sub_77DA
loc_8904:
		LDY		byte_49
		LDA		byte_46,Y
		CLC
		ADC		byte_61
		TAY
		CPY		#$19
		BCC		loc_8913
		LDY		#$19
loc_8913:
		LDA		byte_400,Y
		STY		byte_61
		JSR		sub_8655
		STX		byte_84
		STY		byte_86
		LDA		#$00
		STA		byte_85
		STA		byte_87
		STA		byte_5E
		LDA		#$21
		STA		byte_73
		STA		byte_88
		LDX		#$10
		LDY		_cur_player_idx
		LDA		_1p_cpu_ctrl_flag,Y
		BEQ		loc_8938
		LDX		#$18
loc_8938:
		STX		byte_341
		JSR		sub_8722
		LDA		_cur_player_idx
		STA		byte_65
		LDA		#$00
		STA		byte_64
		LDA		byte_4A
		TAY
		CLC
		LDA		byte_30D
		ROR
		ROR
		ORA		byte_61
		STA		byte_314,Y
		JSR		_apu_play_ctrlB_set80
		LDA		#$09
		STA		byte_45
		RTS

; =============== S U B	R O U T	I N E =======================================
_ingame_sub09:
		JSR		_ingame_sub06
		LDA		byte_45
		CMP		#$07
		BEQ		loc_8966
		RTS
; ---------------------------------------------------------------------------
loc_8966:
		LDA		byte_30D
		BMI		loc_89C3
		LDA		byte_61
		JSR		sub_77DA
		LDA		#$20
		STA		byte_73
		LDA		byte_30D
		BEQ		loc_89CE
		LDA		#$04
		STA		byte_5F
		LDX		#$30
		STX		byte_340
		LDY		#$00
loc_8984:
		LDA		byte_6F,Y
		STA		byte_8B,Y
		INY
		CPY		#$04
		BNE		loc_8984
		LDA		_cur_player_idx
		PHA
		EOR		#$01
		STA		_cur_player_idx
		STA		byte_65
		LDY		#$00
		LDA		byte_420
		JSR		sub_8655
		PLA
		STA		_cur_player_idx
		STX		byte_84
		STY		byte_86
		LDA		#$00
		STA		byte_8F
		STA		byte_88
		STA		byte_5E
		JSR		sub_871F
		LDA		#$80
		STA		byte_30D
		LDA		#$70
		STA		byte_64
		JSR		_apu_play_ctrlB_set08
		LDA		#$09
		STA		byte_45
		RTS
; ---------------------------------------------------------------------------
loc_89C3:
		LDY		#$00
		STY		byte_319
		STY		byte_5F
		LDA		#$00
		STA		byte_64
loc_89CE:
		LDX		#$10
		LDY		_cur_player_idx
		LDA		_1p_cpu_ctrl_flag,Y
		BEQ		loc_89D9
		LDX		#$20
loc_89D9:
		STX		byte_340
		LDA		#$0A
		STA		byte_45
		LDA		byte_30D
		BMI		locret_89F1
		LDA		byte_61
		CMP		#$19
		BEQ		loc_89EE
		JMP		_apu_play_ctrlA_set80
; ---------------------------------------------------------------------------
loc_89EE:
		JMP		_apu_play_ctrlA_set40
; ---------------------------------------------------------------------------
locret_89F1:
		RTS

; =============== S U B	R O U T	I N E =======================================
_ingame_sub0A:
		LDA		#$01
		STA		byte_30B
		JSR		sub_97EB
		BEQ		loc_89FF
		JMP		loc_8A38
; ---------------------------------------------------------------------------
loc_89FF:
		LDY		byte_48
		LDA		byte_4A
		CMP		byte_8A43,Y
		BEQ		loc_8A29
		LDA		byte_49
		EOR		#$01
		STA		byte_49
		INC		byte_4A
		LDA		#$00
		STA		byte_306
		JSR		sub_9752
		BEQ		loc_8A21
		LDA		#$01
		STA		byte_306
		BNE		loc_8A29
loc_8A21:
		INC		byte_321
		LDA		#$07
		STA		byte_45
		RTS
; ---------------------------------------------------------------------------
loc_8A29:
		LDA		#$80
		STA		byte_334
		LDA		#$00
		STA		byte_336
		LDA		#$1E
		STA		byte_45
		RTS
; ---------------------------------------------------------------------------
loc_8A38:
		STA		byte_31B
		LDA		#$80
		STA		byte_307
		JMP		_ingame_sub1E
; ---------------------------------------------------------------------------
byte_8A43:
		.BYTE $01,$03

; =============== S U B	R O U T	I N E =======================================
_ingame_sub0B:
		LDA		#$80
		STA		byte_32E
		LDA		#$00
		STA		byte_64
		JSR		_ingame_sub06
		LDA		byte_45
		CMP		#$07
		BNE		locret_8A92
		LDA		#$00
		STA		byte_32E
		LDA		#$1F
		STA		byte_45
		LDA		byte_306
		BEQ		locret_8A92
		LDA		#$02
		STA		byte_62
		LDA		_cur_player_idx
		STA		byte_325
		LDA		#$1E
		STA		byte_322
		LDX		#$70
		LDY		_cur_player_idx
		LDA		_1p_cpu_ctrl_flag,Y
		BNE		loc_8A83
		LDA		#$1D
		STA		byte_322
		LDX		#$00
loc_8A83:
		STX		byte_324
		LDA		#$00
		STA		byte_306
		STA		byte_323
		LDA		_pads_press
		LDA		_pads_press+1
locret_8A92:
		RTS

; =============== S U B	R O U T	I N E =======================================
_ingame_sub0C_next_turn_player_switch:
		JSR		sub_9713
		LDA		_cur_player_idx
		EOR		#$01
		STA		_cur_player_idx
		LDA		_cheat_flag1_w
		BEQ		loc_8AB9
		LDA		_pads_held
		CMP		#$01
		BNE		loc_8AAD
		LDA		_1p_cpu_ctrl_flag
		EOR		#$01
		STA		_1p_cpu_ctrl_flag
loc_8AAD:
		LDA		_pads_held+1
		CMP		#$01
		BNE		loc_8AB9
		LDA		_2p_cpu_ctrl_flag
		EOR		#$01
		STA		_2p_cpu_ctrl_flag
loc_8AB9:
		LDA		#$00
		STA		byte_320
		STA		byte_305
		STA		byte_304
		STA		byte_60
		STA		byte_45
		LDA		byte_308
		CMP		#$FF
		BEQ		locret_8AD2
		INC		byte_308
locret_8AD2:
		RTS

; =============== S U B	R O U T	I N E =======================================
_ingame_sub12:
		LDA		#$05
		STA		_main02_sub_idx
		RTS

; =============== S U B	R O U T	I N E =======================================
_ingame_sub13:
		LDA		byte_62
		BNE		locret_8B2A
		LDA		byte_577
		BNE		locret_8B2A
		LDA		byte_305
		CMP		#$01
		BEQ		loc_8B2B
		LDY		byte_325
		LDA		_1p_cpu_ctrl_flag,Y
		BNE		loc_8B08
		LDA		_pads_press,Y
		STA		word_10
		LDA		#$C0
		LDY		byte_4A
		BNE		loc_8B04
		LDY		byte_322
		CPY		#$11
		BEQ		loc_8B04
		LDA		#$80
loc_8B04:
		AND		word_10
		BNE		loc_8B18
loc_8B08:
		LDA		byte_324
		BEQ		locret_8B2A
		LDA		byte_323
		INC		byte_323
		CMP		byte_324
		BNE		locret_8B2A
loc_8B18:
		LDY		byte_325
		LDA		_pads_press,Y
		STA		byte_326
		LDA		#$01
		STA		byte_62
		LDA		byte_322
		STA		byte_45
locret_8B2A:
		RTS
; ---------------------------------------------------------------------------
loc_8B2B:
		LDA		#$80
		STA		byte_305
		LDA		byte_322
		STA		byte_45
		RTS

; =============== S U B	R O U T	I N E =======================================
_ingame_sub1D:
		LDA		byte_326
		BMI		loc_8B45
		ASL
		BPL		loc_8B4F
		DEC		byte_4A
		LDA		#$1A
		STA		byte_45
		RTS
; ---------------------------------------------------------------------------
loc_8B45:
		LDA		#$80
		STA		byte_307
		LDA		#$1F
		STA		byte_45
		RTS
; ---------------------------------------------------------------------------
loc_8B4F:
		JSR		_apu_play_ctrlB_set04
		LDA		#$02
		STA		byte_62
		LDA		_cur_player_idx
		STA		byte_325
		LDA		#$00
		STA		byte_324
		STA		byte_323
		LDA		#$1D
		STA		byte_322
		RTS

; =============== S U B	R O U T	I N E =======================================
_ingame_sub1E:
		LDY		_cur_player_idx
		LDA		_1p_cpu_ctrl_flag,Y
		BEQ		loc_8B7A
		INC		byte_336
		LDX		byte_336
		CPX		#$0A
		BNE		locret_8BA3
loc_8B7A:
		LDA		#$10
		STA		byte_341
		JSR		sub_8C61
		LDA		_cur_player_idx
		STA		byte_65
		EOR		#$01
		EOR		byte_60
		JSR		sub_8C94
		LDA		#$20
		STA		byte_88
		JSR		sub_8722
		LDA		#$00
		STA		byte_5E
		STA		byte_30A
		LDA		#$FF
		STA		byte_61
		LDA		#$0B
		STA		byte_45
locret_8BA3:
		RTS

; =============== S U B	R O U T	I N E =======================================
_ingame_sub1F:
		LDA		byte_30A
		BNE		loc_8BFC
		LDY		_cur_player_idx
		LDA		_1p_cpu_ctrl_flag,Y
		BNE		loc_8BC7
		LDA		byte_307
		BMI		loc_8BC7
		LDA		_pads_press,Y
		BMI		loc_8BC7
		ASL
		BPL		locret_8BC6
loc_8BBD:
		LDA		#$10
		STA		byte_341
		LDA		#$1A
		STA		byte_45
locret_8BC6:
		RTS
; ---------------------------------------------------------------------------
loc_8BC7:
		LDA		_cur_player_idx
		STA		byte_302
		STA		byte_65
		LDA		byte_60
		BEQ		loc_8BE3
		LDA		#$01
		STA		byte_301
		LDA		#$20
		STA		byte_45
		LDA		#$04
		STA		byte_30A
		JMP		loc_9046
; ---------------------------------------------------------------------------
loc_8BE3:
		LDA		#$23
		STA		byte_73
		INC		byte_30A
		JMP		_apu_play_ctrlA_set02_0
; ---------------------------------------------------------------------------
loc_8BED:
		JSR		sub_8722
		LDA		#$00
		STA		byte_5E
		INC		byte_30A
		LDA		#$0B
		STA		byte_45
		RTS
; ---------------------------------------------------------------------------
loc_8BFC:
		CMP		#$04
		BNE		loc_8C24
		LDA		#$00
		STA		byte_307
		LDA		_cur_player_idx
		EOR		byte_60
		JSR		sub_8C94
		LDA		#$20
		STA		byte_73
		LDA		#$23
		STA		byte_88
		LDA		_cur_player_idx
		STA		byte_65
		LDA		_cur_player_idx
		EOR		#$01
		TAY
		LDA		#$80
		STA		byte_332,Y
		BMI		loc_8BED
loc_8C24:
		CMP		#$08
		BNE		loc_8C48
		JSR		_apu_play_ctrlA_set02_0
		LDA		byte_6F
		STA		byte_84
		LDA		#$F0
		LDY		_cur_player_idx
		BEQ		loc_8C37
		LDA		#$00
loc_8C37:
		STA		byte_86
		LDA		#$20
		STA		byte_73
		STA		byte_88
		LDY		_cur_player_idx
		LDA		#$80
		STA		byte_332,Y
		BMI		loc_8BED
loc_8C48:
		CMP		#$0C
		BNE		loc_8C5D
		LDA		#$80
		STA		byte_32E
		LDA		#$0C
		LDY		byte_31B
		BEQ		loc_8C5A
		LDA		#$12
loc_8C5A:
		STA		byte_45
		RTS
; ---------------------------------------------------------------------------
loc_8C5D:
		INC		byte_30A
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_8C61:
		LDA		byte_330
		BEQ		loc_8C7A
		LDA		byte_76
		EOR		#$FF
		SEC
		ADC		#$F2
		STA		byte_76
		LDA		byte_77
		SBC		#$00
		STA		byte_77
		LDA		#$00
		STA		byte_330
loc_8C7A:
		LDA		byte_331
		BEQ		locret_8C93
		LDA		byte_7D
		EOR		#$FF
		SEC
		ADC		#$F2
		STA		byte_7D
		LDA		byte_7E
		SBC		#$00
		STA		byte_7E
		LDA		#$00
		STA		byte_331
locret_8C93:
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_8C94:
		STA		word_10
		ASL
		ASL
		ASL
		SEC
		SBC		word_10
		TAX
		LDY		#$00
loc_8C9F:
		LDA		byte_76,X
		STA		byte_84,Y
		INX
		INY
		CPY		#$05
		BNE		loc_8C9F
		RTS

; =============== S U B	R O U T	I N E =======================================
_ingame_sub0D:
		LDA		#$78
		STA		byte_6F
		STA		byte_84
		LDY		byte_31D
		INY
		LDA		byte_8E77,Y
		STA		byte_86
		LDA		#$F0
		LDY		_cur_player_idx
		BEQ		loc_8CC2
		LDA		#$00
loc_8CC2:
		STA		byte_71
		LDA		#$20
		STA		byte_73
		STA		byte_88
		LDA		#$00
		STA		byte_70
		STA		byte_72
		STA		byte_85
		STA		byte_87
		STA		byte_5E
		STA		byte_65
		STA		byte_31F
		STA		byte_6B
		STA		byte_32E
		LDA		#$00
		STA		byte_64
		LDA		byte_86
		SEC
		SBC		byte_71
		BPL		loc_8CF0
		EOR		#$FF
		CLC
		ADC		#$01
loc_8CF0:
		LSR
		LSR
		STA		byte_341
		JSR		sub_8722
		LDA		#$0F
		STA		byte_45
		RTS

; =============== S U B	R O U T	I N E =======================================
_ingame_sub0E:
		LDA		byte_31E
		BMI		loc_8D48
		LDA		#$80
		STA		byte_31E
		LDA		byte_5D
		BNE		loc_8D0F
		LDA		#$03
		STA		byte_32
loc_8D0F:
		LDA		_cur_player_idx
		STA		byte_31D
		LDY		byte_31D
		INY
		LDA		byte_8E77,Y
		STA		byte_86
		LDA		#$22
		STA		byte_73
		STA		byte_88
		LDA		#$00
		STA		byte_5E
		STA		byte_65
		LDA		#$00
		STA		byte_64
		LDA		byte_86
		SEC
		SBC		byte_71
		BPL		loc_8D39
		EOR		#$FF
		CLC
		ADC		#$01
loc_8D39:
		LSR
		STA		byte_341
		JSR		_apu_play_ctrlB_set40
		JSR		sub_8722
		LDA		#$0F
		STA		byte_45
		RTS
; ---------------------------------------------------------------------------
loc_8D48:
		LDA		#$00
		STA		byte_31E
		INC		byte_5D
		LDA		byte_5D
		STA		byte_55C
		LDA		#$E0
		LDY		_cur_player_idx
		BEQ		loc_8D5C
		LDA		#$10
loc_8D5C:
		STA		byte_86
		LDA		#$20
		STA		byte_73
		STA		byte_88
		LDA		#$00
		STA		byte_5E
		STA		byte_65
		LDA		#$00
		STA		byte_64
		LDA		byte_86
		SEC
		SBC		byte_71
		BPL		loc_8D7A
		EOR		#$FF
		CLC
		ADC		#$01
loc_8D7A:
		LSR
		LSR
		STA		byte_341
		JSR		sub_8722
		LDA		#$01
		STA		byte_31F
		LDA		#$0F
		STA		byte_45
		RTS

; =============== S U B	R O U T	I N E =======================================
_ingame_sub0F:
		JSR		_ingame_sub06
		LDA		byte_45
		CMP		#$07
		BNE		locret_8DA3
		LDA		byte_31F
		BNE		loc_8D9F
		LDA		#$0E
		STA		byte_45
		RTS
; ---------------------------------------------------------------------------
loc_8D9F:
		LDA		#$10
		STA		byte_45
locret_8DA3:
		RTS

; =============== S U B	R O U T	I N E =======================================
_ingame_sub10:
		LDA		#$80
		STA		byte_32E
		LDA		_cur_player_idx
		EOR		#$01
		TAY
		STY		byte_325
		LDA		_1p_cpu_ctrl_flag,Y
		BEQ		loc_8DC2
		LDA		_cur_player_idx
		STA		byte_325
		JSR		_cp_sub02
		BNE		loc_8DE8
		BEQ		loc_8DD4
loc_8DC2:
		LDA		#$0A
		STA		byte_62
		LDA		#$00
		STA		byte_323
		STA		byte_324
		LDA		#$11
		STA		byte_322
		RTS
; ---------------------------------------------------------------------------
loc_8DD4:
		LDA		#$0B
		STA		byte_62
		LDA		#$00
		STA		byte_323
		LDA		#$70
		STA		byte_324
		LDA		#$00
		STA		byte_322
		RTS
; ---------------------------------------------------------------------------
loc_8DE8:
		LDA		#$0C
		STA		byte_62
		LDA		#$00
		STA		byte_323
		LDA		#$70
		STA		byte_324
		DEC		byte_5D
		LDA		#$01
		STA		byte_31B
		LDA		#$12
		STA		byte_322
		RTS

; =============== S U B	R O U T	I N E =======================================
_ingame_sub11:
		LDA		_cur_player_idx
		STA		byte_325
		LDA		byte_326
		BMI		loc_8E18
		ASL
		BMI		loc_8E2C
		JSR		_apu_play_ctrlB_set04
		LDA		#$10
		STA		byte_45
		RTS
; ---------------------------------------------------------------------------
loc_8E18:
		LDA		#$0B
		STA		byte_62
		LDA		#$00
		STA		byte_323
		LDA		#$70
		STA		byte_324
		LDA		#$00
		STA		byte_322
		RTS
; ---------------------------------------------------------------------------
loc_8E2C:
		LDA		#$0C
		STA		byte_62
		LDA		#$00
		STA		byte_323
		LDA		#$70
		STA		byte_324
		DEC		byte_5D
		LDA		#$01
		STA		byte_31B
		LDA		#$12
		STA		byte_322
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_8E47:
		LDA		byte_6B
		PHA
		LDA		byte_31E
		BMI		loc_8E73
		LDA		byte_5D
		BEQ		loc_8E73
		LDA		#$F0
		STA		_spr_buf_pos
		LDY		byte_31D
		INY
		LDA		byte_8E77,Y
		STA		byte_68
		LDA		#$78
		STA		byte_66
		LDA		#$00
		STA		byte_69
		STA		byte_67
		STA		byte_6B
		LDA		#$07
		STA		_spr_lib_idx
		JSR		_spr_lib_insert
loc_8E73:
		PLA
		STA		byte_6B
		RTS
; ---------------------------------------------------------------------------
byte_8E77:
		.BYTE $80,$20,$E0

; =============== S U B	R O U T	I N E =======================================
_ingame_sub14:
		LDA		byte_5D
		BEQ		loc_8E9A
		LDY		#$FF
		STY		byte_31D
		INY
		STY		byte_5D
		STY		byte_31E
		STY		byte_308
		STY		byte_31B
		STY		byte_301
		INY
		STY		byte_60
		LDA		#$06
		STA		byte_55C
loc_8E9A:
		LDY		#$00
		STY		byte_304
		JSR		loc_8EED
		LDA		byte_302
		BPL		loc_8EC1
		LDA		byte_309
		BPL		loc_8EB5
		LDA		#$00
		STA		_cur_player_idx
		STA		byte_302
		BEQ		loc_8ECE
loc_8EB5:
		ASL
		BPL		locret_8EE9
		LDA		#$01
		STA		_cur_player_idx
		STA		byte_302
		BNE		loc_8ECE
loc_8EC1:
		LDA		byte_309
		LDY		byte_302
		BNE		loc_8ECA
		ASL
loc_8ECA:
		AND		#$80
		BEQ		locret_8EE9
loc_8ECE:
		LDY		_cur_player_idx
		LDA		#$80
		STA		_pads_held,Y
		JSR		_ingame_sub00
		LDA		_cur_player_idx
		EOR		byte_302
		BEQ		locret_8EE9
		LDA		byte_302
		TAY
		STA		byte_332,Y
		STA		byte_330,Y
locret_8EE9:
		RTS

; =============== S U B	R O U T	I N E =======================================
_ingame_sub15:
		JSR		_ingame_sub01
loc_8EED:
		LDA		_1p_cpu_ctrl_flag
		AND		_2p_cpu_ctrl_flag
		BEQ		loc_8EF8
		LDA		#$C0
		STA		byte_309
loc_8EF8:
		LDA		_1p_cpu_ctrl_flag
		BNE		loc_8F03
		LDA		_pads_press
		AND		#$80
		JMP		loc_8F09
; ---------------------------------------------------------------------------
loc_8F03:
		LDA		byte_309
		AND		#$40
		ASL
loc_8F09:
		ORA		byte_309
		STA		byte_309
		LDA		_2p_cpu_ctrl_flag
		BNE		loc_8F1B
		LDA		_pads_press+1
		LSR
		AND		#$40
		JMP		loc_8F21
; ---------------------------------------------------------------------------
loc_8F1B:
		LDA		byte_309
		AND		#$80
		LSR
loc_8F21:
		ORA		byte_309
		STA		byte_309
		RTS

; =============== S U B	R O U T	I N E =======================================
_ingame_sub16:
		JSR		_ingame_sub02
		JMP		loc_8EED

; =============== S U B	R O U T	I N E =======================================
_ingame_sub17:
		LDA		#$00
		STA		_spr_buf_pos
		LDA		_cur_player_idx
		STA		byte_6B
		LDY		#$00
loc_8F38:
		LDA		byte_6F,Y
		STA		byte_66,Y
		INY
		CPY		#$05
		BNE		loc_8F38
		JSR		_spr_lib_insert
		LDA		_cur_player_idx
		ASL
		ASL
		ASL
		SEC
		SBC		_cur_player_idx
		PHA
		CLC
		ADC		#<[byte_7EC8]
		STA		_tmp1Cw
		LDA		#$00
		ADC		#>[byte_7EC8]
		STA		_tmp1Cw+1
		PLA
		CLC
		ADC		#<[byte_74]
		STA		byte_1E
		LDA		#$00
		ADC		#>[byte_74]
		STA		byte_1F
		LDY		#$00
loc_8F68:
		LDA		(_tmp1Cw),Y
		STA		(byte_1E),Y
		INY
		CPY		#$07
		BNE		loc_8F68
		LDA		#$00
		STA		byte_5E
		STA		byte_6D
		LDA		_cur_player_idx
		STA		byte_338
		EOR		#$01
		STA		byte_339
		LDA		_cur_player_idx
		EOR		byte_302
		BNE		loc_8F8E
		JSR		_dice_roll_init
		JSR		_dice_roll_rand
loc_8F8E:
		JSR		_apu_play_ctrlC_set02
		LDA		#$80
		STA		byte_45
		JMP		loc_8EED

; =============== S U B	R O U T	I N E =======================================
_ingame_sub18:
		JSR		_ingame_sub04
		LDA		_cur_player_idx
		EOR		byte_302
		BNE		loc_8FAE
		LDA		_cur_player_idx
		EOR		#$01
		TAY
		LDA		#$80
		STA		byte_332,Y
		BNE		loc_8FB8
loc_8FAE:
		LDA		byte_302
		TAY
		STA		byte_332,Y
		STA		byte_330,Y
loc_8FB8:
		JMP		loc_8EED

; =============== S U B	R O U T	I N E =======================================
_ingame_sub19:
		LDA		_cur_player_idx
		EOR		byte_302
		BNE		loc_8FCF
		LDA		_cur_player_idx
		EOR		#$01
		STA		_cur_player_idx
		LDA		#$14
		STA		byte_45
		JMP		loc_8EED
; ---------------------------------------------------------------------------
loc_8FCF:
		LDA		#$00
		STA		_cur_player_idx
		LDA		byte_47
		CMP		byte_46
		BEQ		loc_8FEF
		ROL		_cur_player_idx
		LDA		_cur_player_idx
		STA		byte_327
		JSR		sub_96C5
		LDA		_cur_player_idx
		CLC
		ADC		#$02
		STA		_nmi_tlm_lib_idx
		LDA		#$05
		STA		byte_45
		RTS
; ---------------------------------------------------------------------------
loc_8FEF:
		JSR		sub_8C61
		LDA		byte_302
		STA		_cur_player_idx
		STA		byte_65
		LDA		#$00
		STA		byte_30A
		LDA		#$20
		STA		byte_45
		RTS

; =============== S U B	R O U T	I N E =======================================
_ingame_sub20:
		LDA		byte_30A
		BNE		loc_9046
		LDA		_cur_player_idx
		CLC
		ADC		#$02
		STA		_nmi_tlm_lib_idx
		LDA		_cur_player_idx
		JSR		sub_8C94
		LDA		byte_84
		STA		byte_6F
		LDA		#$F0
		LDY		_cur_player_idx
		BEQ		loc_9020
		LDA		#$00
loc_9020:
		STA		byte_71
		LDA		#$00
		STA		byte_70
		STA		byte_85
		STA		byte_72
		STA		byte_87
loc_902C:
		LDA		#$20
		STA		byte_73
		STA		byte_88
		LDA		#$10
		STA		byte_341
		JSR		sub_8722
		LDA		#$00
		STA		byte_5E
		INC		byte_30A
		LDA		#$21
		STA		byte_45
		RTS
; ---------------------------------------------------------------------------
loc_9046:
		CMP		#$04
		BNE		loc_905B
		LDA		#$23
		STA		byte_73
		LDY		_cur_player_idx
		LDA		#$80
		STA		byte_332,Y
		INC		byte_30A
		JMP		_apu_play_ctrlA_set02_0
; ---------------------------------------------------------------------------
loc_905B:
		CMP		#$08
		BNE		loc_906C
		LDA		#$F0
		LDY		_cur_player_idx
		BEQ		loc_9067
		LDA		#$00
loc_9067:
		STA		byte_86
		JMP		loc_902C
; ---------------------------------------------------------------------------
loc_906C:
		CMP		#$0C
		BNE		loc_909C
		LDA		#$80
		STA		byte_32E
		LDA		_cur_player_idx
		EOR		byte_302
		BNE		loc_9088
		STA		byte_30A
		LDA		_cur_player_idx
		EOR		#$01
		STA		_cur_player_idx
		STA		byte_65
		RTS
; ---------------------------------------------------------------------------
loc_9088:
		LDA		byte_302
		STA		_cur_player_idx
		LDA		byte_301
		BNE		loc_9097
		LDA		#$14
		STA		byte_45
		RTS
; ---------------------------------------------------------------------------
loc_9097:
		LDA		#$0C
		JMP		loc_8C48
; ---------------------------------------------------------------------------
loc_909C:
		INC		byte_30A
		RTS

; =============== S U B	R O U T	I N E =======================================
_ingame_sub21:
		LDA		#$80
		STA		byte_32E
		LDA		#$00
		STA		byte_64
		JSR		_ingame_sub06
		LDA		byte_45
		CMP		#$07
		BNE		locret_90BB
		LDA		#$00
		STA		byte_32E
		LDA		#$20
		STA		byte_45
locret_90BB:
		RTS

; =============== S U B	R O U T	I N E =======================================
_ingame_sub1A:
		LDA		_cur_player_idx
		STA		byte_65
		LDA		#$00
		STA		byte_30D
		LDA		#$00
		STA		byte_64
		LDY		byte_4A
		LDA		byte_314,Y
		AND		#$7F
		CMP		byte_61
		BEQ		loc_90FD
		STA		byte_61
		TAY
		LDA		byte_400,Y
		JSR		sub_8655
		STX		byte_84
		STY		byte_86
		LDA		#$20
		STA		byte_88
		LDA		#$00
		STA		byte_85
		STA		byte_87
		STA		byte_5E
		LDA		#$10
		STA		byte_341
		JSR		sub_8722
		JSR		_apu_play_ctrlB_set80
		LDA		#$1C
		STA		byte_45
		RTS
; ---------------------------------------------------------------------------
loc_90FD:
		LDA		#$1B
		STA		byte_45
		RTS

; =============== S U B	R O U T	I N E =======================================
_ingame_sub1B:
		LDY		byte_4A
		LDA		byte_310,Y
		CMP		byte_61
		BNE		loc_910E
		JMP		loc_914D
; ---------------------------------------------------------------------------
loc_910E:
		STA		byte_61
		TAY
		LDA		byte_400,Y
		CLC
		ADC		#$01
		JSR		sub_8655
		STX		byte_84
		STY		byte_86
		LDA		#$21
		STA		byte_73
		LDA		#$20
		STA		byte_88
		LDA		#$00
		STA		byte_85
		STA		byte_87
		STA		byte_5E
		LDA		#$10
		STA		byte_341
		JSR		sub_8722
		JSR		_apu_play_ctrlB_set80
		LDY		byte_4A
		LDA		byte_314,Y
		AND		#$7F
		TAX
		DEC		byte_400,X
		TXA
		JSR		sub_77DA
		LDA		#$1C
		STA		byte_45
		RTS
; ---------------------------------------------------------------------------
loc_914D:
		LDA		byte_30D
		BMI		loc_91C4
		LDX		byte_310,Y
		INC		byte_400,X
		TXA
		JSR		sub_77DA
		LDY		byte_4A
		LDA		byte_314,Y
		BMI		loc_9166
		JMP		loc_91DD
; ---------------------------------------------------------------------------
loc_9166:
		AND		#$7F
		STA		byte_314,Y
		LDA		#$04
		STA		byte_5F
		LDY		byte_4A
		LDA		byte_314,Y
		TAY
		LDA		#$01
		JSR		sub_8655
		STX		byte_84
		STY		byte_86
		LDA		_cur_player_idx
		PHA
		EOR		#$01
		STA		_cur_player_idx
		STA		byte_65
		LDY		#$00
		LDA		byte_420
		JSR		sub_8655
		PLA
		STA		_cur_player_idx
		STX		byte_8B
		STY		byte_8D
		LDA		#$00
		STA		byte_8F
		STA		byte_88
		STA		byte_5E
		LDA		#$10
		STA		byte_341
		JSR		sub_8722
		LDA		#$80
		STA		byte_30D
		LDY		byte_4A
		LDX		byte_314,Y
		DEC		byte_420
		INC		byte_420,X
		LDA		#$70
		STA		byte_64
		LDA		#$80
		STA		byte_30D
		LDA		#$1C
		STA		byte_45
		RTS
; ---------------------------------------------------------------------------
loc_91C4:
		LDY		byte_4A
		LDA		byte_314,Y
		JSR		sub_77DA
		LDA		_cur_player_idx
		STA		byte_65
		STA		byte_6B
		LDA		#$00
		STA		byte_5F
		STA		byte_30D
		LDA		#$00
		STA		byte_64
loc_91DD:
		JSR		_apu_play_ctrlA_set80
		LDA		#$00
		STA		byte_334
		LDA		byte_4A
		BNE		loc_91EF
		LDA		byte_49
		EOR		#$01
		STA		byte_49
loc_91EF:
		LDA		#$07
		STA		byte_45
		RTS

; =============== S U B	R O U T	I N E =======================================
_ingame_sub1C:
		JSR		_ingame_sub06
		LDA		byte_45
		CMP		#$07
		BNE		locret_9201
		LDA		#$1B
		STA		byte_45
locret_9201:
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_9202:
		LDA		byte_62
		BEQ		loc_9228
		CMP		#$02
		BEQ		loc_9210
		CMP		#$06
		BEQ		loc_9210
		BNE		loc_921E
loc_9210:
		LDA		_1p_cpu_ctrl_flag
		ORA		_2p_cpu_ctrl_flag
		EOR		#$01
		ASL
		CLC
		ADC		byte_62
		ORA		_cur_player_idx
		STA		byte_62
loc_921E:
		LDA		byte_325
		CLC
		ROR
		ROR
		ORA		byte_62
		STA		byte_62
loc_9228:
		JSR		sub_922F
		JSR		sub_93A7
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_922F:
		LDA		byte_32
		ORA		_ppu_queue_req
		ORA		_nmi_tlm_lib_idx
		ORA		byte_577
		BNE		locret_9240
		LDA		byte_62
		BNE		loc_9241
		RTS
; ---------------------------------------------------------------------------
locret_9240:
		RTS
; ---------------------------------------------------------------------------
loc_9241:
		LDA		byte_62
		STA		byte_579
		AND		#$7F
		TAY
		DEY
		LDA		off_9280,Y
		STA		byte_108
		LDA		off_928C,Y
		STA		byte_109
		LDX		#$21
		LDY		#$82
		LDA		byte_62
		AND		#$80
		BEQ		loc_9264
		LDX		#$21
		LDY		#$90
loc_9264:
		STX		byte_107
		STY		byte_106
		LDA		#$3B
		STA		byte_104
		LDA		#$01
		STA		byte_105
		LDY		#$00
		STY		byte_62
		STY		byte_10A
		INY
		STY		byte_577
		RTS
; ---------------------------------------------------------------------------
off_9280:
		.BYTE <[byte_9298]
		.BYTE <[byte_9299]
		.BYTE <[byte_92B2]
		.BYTE <[byte_92CD]
		.BYTE <[byte_92E8]
		.BYTE <[byte_9303]
		.BYTE <[byte_9321]
		.BYTE <[byte_9341]
		.BYTE <[byte_9361]
		.BYTE <[byte_9381]
		.BYTE <[_tlm_accept]
		.BYTE <[_tlm_drop]
off_928C:
		.BYTE >[byte_9298]
		.BYTE >[byte_9299]
		.BYTE >[byte_92B2]
		.BYTE >[byte_92CD]
		.BYTE >[byte_92E8]
		.BYTE >[byte_9303]
		.BYTE >[byte_9321]
		.BYTE >[byte_9341]
		.BYTE >[byte_9361]
		.BYTE >[byte_9381]
		.BYTE >[_tlm_accept]
		.BYTE >[_tlm_drop]
byte_9298:
		.BYTE $FF
byte_9299:
		.BYTE $01,$0F,$06,$20,$1C,$11,$29,$15,$22,$26,$07,$13,$11,$1E,$2E,$1E
		.BYTE $1F,$24,$40,$04,$1D,$1F,$26,$15,$FF
byte_92B2:
		.BYTE $01,$0E,$08,$13,$1F,$1D,$20,$25,$24,$15,$22,$26,$07,$13,$11,$1E
		.BYTE $2E,$1E,$1F,$24,$40,$04,$1D,$1F,$26,$15,$FF
byte_92CD:
		.BYTE $01,$0E,$08,$20,$1C,$11,$29,$15,$22,$A5,$01,$26,$07,$13,$11,$1E
		.BYTE $2E,$1E,$1F,$24,$40,$04,$1D,$1F,$26,$15,$FF
byte_92E8:
		.BYTE $01,$0E,$08,$20,$1C,$11,$29,$15,$22,$A5,$02,$26,$07,$13,$11,$1E
		.BYTE $2E,$1E,$1F,$24,$40,$04,$1D,$1F,$26,$15,$FF
byte_9303:
		.BYTE $01,$0F,$06,$20,$1C,$11,$29,$15,$22,$26,$07,$13,$11,$1E,$2E,$1E
		.BYTE $1F,$24,$3E,$09,$22,$1F,$1C,$1C,$2E,$14,$19,$13,$15,$FF
byte_9321:
		.BYTE $01,$0E,$08,$13,$1F,$1D,$20,$25,$24,$15,$22,$26,$07,$13,$11,$1E
		.BYTE $2E,$1E,$1F,$24,$3E,$09,$22,$1F,$1C,$1C,$2E,$14,$19,$13,$15,$FF
byte_9341:
		.BYTE $01,$0E,$08,$20,$1C,$11,$29,$15,$22,$A5,$01,$26,$07,$13,$11,$1E
		.BYTE $2E,$1E,$1F,$24,$3E,$09,$22,$1F,$1C,$1C,$2E,$14,$19,$13,$15,$FF
byte_9361:
		.BYTE $01,$0E,$08,$20,$1C,$11,$29,$15,$22,$A5,$02,$26,$07,$13,$11,$1E
		.BYTE $2E,$1E,$1F,$24,$3E,$09,$22,$1F,$1C,$1C,$2E,$14,$19,$13,$15,$FF
byte_9381:
		.BYTE $01,$1A,$08,$A6,$2E,$11,$13,$13,$15,$20,$24,$32,$06,$A7,$2E,$14
		.BYTE $22,$1F,$20,$FF
_tlm_accept:
		.WORD $2702
		.BYTE $06
		.BYTE _A,_C,_C,_E,_P,_T
		.BYTE $FF
_tlm_drop:
		.WORD $2802
		.BYTE $04
		.BYTE _D,_R,_O,_P
		.BYTE $FF

; =============== S U B	R O U T	I N E =======================================
sub_93A7:
		LDA		byte_32
		ORA		_ppu_queue_req
		ORA		_nmi_tlm_lib_idx
		BNE		locret_93B5
		LDA		byte_577
		BNE		loc_93B6
locret_93B5:
		RTS
; ---------------------------------------------------------------------------
loc_93B6:
		CMP		#$01
		BNE		loc_93F2
		JSR		sub_94F9
		LDY		byte_108
		STY		_tmp1Cw
		LDY		byte_109
		STY		_tmp1Cw+1
		LDY		byte_10A
		INC		byte_10A
		LDA		(_tmp1Cw),Y
		BMI		loc_93DF
		JSR		sub_94C6
		JSR		sub_9414
		LDX		#$01
		STX		byte_578
		JMP		loc_93E4
; ---------------------------------------------------------------------------
loc_93DF:
		LDX		#$00
		STX		byte_578
loc_93E4:
		JSR		sub_945E
		JSR		sub_9473
		JSR		sub_9488
		LDX		#$03
		JMP		sub_9433
; ---------------------------------------------------------------------------
loc_93F2:
		CMP		#$02
		BNE		loc_9404
		JSR		sub_945E
		JSR		sub_9473
		JSR		sub_9488
		LDX		#$03
		JMP		sub_9433
; ---------------------------------------------------------------------------
loc_9404:
		JSR		sub_945E
		JSR		sub_9473
		LDY		#$FF
		STY		byte_577
		LDX		#$02
		JMP		sub_9433

; =============== S U B	R O U T	I N E =======================================
sub_9414:
		LDY		byte_10A
loc_9417:
		LDA		(_tmp1Cw),Y
		CMP		#$FF
		BEQ		locret_9432
		TAX
		INY
		LDA		(_tmp1Cw),Y
		STA		byte_57
		INY
loc_9424:
		LDA		(_tmp1Cw),Y
		STA		byte_13B,X
		INY
		INX
		DEC		byte_57
		BNE		loc_9424
		JMP		loc_9417
; ---------------------------------------------------------------------------
locret_9432:
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_9433:
		LDY		#$00
loc_9435:
		LDA		byte_106
		STA		byte_10C,Y
		LDA		byte_107
		STA		_nmi_tlmB2_ram,Y
		TYA
		CLC
		ADC		#$0F
		TAY
		LDA		byte_106
		ADC		#$20
		STA		byte_106
		BCC		loc_9453
		INC		byte_107
loc_9453:
		DEX
		BNE		loc_9435
		LDA		#$02
		STA		byte_32
		INC		byte_577
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_945E:
		LDA		#$0C
		STA		byte_10D
		LDA		#$FF
		STA		byte_11A
		LDA		#<[byte_10E]
		STA		_tmp1Cw
		LDA		#>[byte_10E]
		STA		_tmp1Cw+1
		JMP		loc_949D

; =============== S U B	R O U T	I N E =======================================
sub_9473:
		LDA		#$0C
		STA		byte_11C
		LDA		#$FF
		STA		byte_129
		LDA		#<[byte_11D]
		STA		_tmp1Cw
		LDA		#>[byte_11D]
		STA		_tmp1Cw+1
		JMP		loc_949D

; =============== S U B	R O U T	I N E =======================================
sub_9488:
		LDA		#$0C
		STA		byte_12B
		LDA		#$FF
		STA		byte_138
		LDA		#<[byte_12C]
		STA		_tmp1Cw
		LDA		#>[byte_12C]
		STA		_tmp1Cw+1
		JMP		loc_949D
loc_949D:
		LDA		byte_104
		STA		_tmp20w
		LDA		byte_105
		STA		_tmp20w+1
		LDY		#$0B
loc_94A9:
		LDA		(_tmp20w),Y
		STA		(_tmp1Cw),Y
		DEY
		BPL		loc_94A9
		LDA		_tmp20w
		CLC
		ADC		#$0C
		STA		_tmp20w
		BCC		loc_94BB
		INC		_tmp20w+1
loc_94BB:
		LDA		_tmp20w
		STA		byte_104
		LDA		_tmp20w+1
		STA		byte_105
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_94C6:
		TAY
		LDA		byte_9504,Y
		STA		byte_57
		LDA		byte_9507,Y
		STA		byte_58
loc_94D1:
		LDY		byte_57
		JSR		sub_94DF
		INC		byte_57
		LDA		byte_57
		CMP		byte_58
		BNE		loc_94D1
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_94DF:
		LDA		off_950A,Y
		STA		_tmp20w
		LDA		off_951E,Y
		STA		_tmp20w+1
		LDA		byte_9532,Y
		TAX
		LDY		#$0B
loc_94EF:
		LDA		(_tmp20w),Y
		STA		byte_13B,X
		DEX
		DEY
		BPL		loc_94EF
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_94F9:
		LDY		#$5F
		LDA		#$2F
loc_94FD:
		STA		byte_13B,Y
		DEY
		BPL		loc_94FD
		RTS
; ---------------------------------------------------------------------------
byte_9504:
		.BYTE $00,$08,$0F
byte_9507:
		.BYTE $08,$0F,$14
off_950A:
		.BYTE <[byte_9546]
		.BYTE <[byte_9552]
		.BYTE <[byte_9552]
		.BYTE <[byte_9552]
		.BYTE <[byte_9552]
		.BYTE <[byte_9552]
		.BYTE <[byte_9552]
		.BYTE <[byte_955E]
		.BYTE <[byte_9546]
		.BYTE <[byte_9552]
		.BYTE <[byte_9552]
		.BYTE <[byte_9552]
		.BYTE <[byte_9552]
		.BYTE <[byte_9552]
		.BYTE <[byte_955E]
		.BYTE <[byte_9546]
		.BYTE <[byte_9552]
		.BYTE <[byte_9552]
		.BYTE <[byte_9552]
		.BYTE <[byte_955E]
off_951E:
		.BYTE >[byte_9546]
		.BYTE >[byte_9552]
		.BYTE >[byte_9552]
		.BYTE >[byte_9552]
		.BYTE >[byte_9552]
		.BYTE >[byte_9552]
		.BYTE >[byte_9552]
		.BYTE >[byte_955E]
		.BYTE >[byte_9546]
		.BYTE >[byte_9552]
		.BYTE >[byte_9552]
		.BYTE >[byte_9552]
		.BYTE >[byte_9552]
		.BYTE >[byte_9552]
		.BYTE >[byte_955E]
		.BYTE >[byte_9546]
		.BYTE >[byte_9552]
		.BYTE >[byte_9552]
		.BYTE >[byte_9552]
		.BYTE >[byte_955E]
byte_9532:
		.BYTE $0B,$17,$23,$2F,$3B,$47,$53,$5F,$0B,$17,$23,$2F,$3B,$47,$53,$17
		.BYTE $23,$2F,$3B,$47
byte_9546:
		.BYTE $0A,$0B,$0B,$0B,$0B,$0B,$0B,$0B,$0B,$0B,$0B,$0C
byte_9552:
		.BYTE $10,$2E,$2E,$2E,$2E,$2E,$2E,$2E,$2E,$2E,$2E,$2D
byte_955E:
		.BYTE $0D,$0E,$0E,$0E,$0E,$0E,$0E,$0E,$0E,$0E,$0E,$0F
_ppu_pal8:
		.BYTE $3F,$00,$20,$0F,$30,$16,$0F,$0F,$39,$1A,$0F,$0F,$30,$38,$0F,$0F
		.BYTE $30,$35,$16,$0F,$30,$16,$0F,$0F,$39,$1A,$0F,$0F,$30,$38,$0F,$0F
		.BYTE $30,$35,$16,$FF
_ppu_pal5:
		.BYTE $3F,$00,$20,$0F,$30,$16,$0F,$0F,$30,$14,$0F,$0F,$0F,$28,$30,$0F
		.BYTE $30,$1A,$0F,$0F,$30,$16,$0F,$0F,$30,$14,$0F,$0F,$0F,$28,$30,$0F
		.BYTE $30,$1A,$0F,$FF
_ppu_pal6:
		.BYTE $3F,$00,$20,$0F,$30,$21,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F
		.BYTE $0F,$0F,$0F,$0F,$30,$26,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F
		.BYTE $0F,$0F,$0F,$FF
_ppu_pal7:
		.BYTE $3F,$00,$20,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F
		.BYTE $0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F
		.BYTE $0F,$0F,$0F,$FF
_tlm_game_field:
		.BYTE $20,$40,$4E,$46,$20,$4E,$02,$43,$44,$20,$50,$4E,$46,$20,$5E,$02
		.BYTE $45,$47,$20,$60,$02,$40,$41,$20,$62,$4C,$52,$20,$6E,$02,$42,$54
		.BYTE $20,$70,$4C,$52,$20,$7C,$04,$55,$56,$57,$83,$20,$80,$D8,$2F,$20
		.BYTE $81,$D8,$51,$20,$8E,$D8,$63,$20,$8F,$D8,$64,$20,$9C,$D8,$65,$20
		.BYTE $9D,$D8,$66,$20,$9E,$D8,$67,$20,$9F,$D8,$50,$21,$9E,$01,$A0,$21
		.BYTE $BE,$C6,$A1,$22,$7E,$01,$A2,$21,$80,$88,$82,$32,$32,$32,$32,$32
		.BYTE $32,$61,$21,$9D,$88,$82,$32,$32,$32,$32,$32,$32,$84,$23,$80,$02
		.BYTE $76,$60,$23,$82,$4C,$76,$23,$8E,$02,$73,$74,$23,$90,$4C,$76,$23
		.BYTE $9C,$04,$75,$76,$77,$62,$23,$A0,$5E,$72,$23,$BE,$01,$87,$23,$C0
		.BYTE $60,$AA,$23,$E0,$60,$AA,$23,$C7,$01,$FF,$23,$CF,$01,$FF,$23,$D7
		.BYTE $01,$FF,$23,$DF,$01,$FF,$23,$AE,$01,$87,$FF
_tlm_res_96A5:
		.BYTE $0B
_tlm_96A6:
		.WORD $EE21
		.BYTE $02
		.BYTE $A8,$A9
		.WORD $0E22
		.BYTE $02
		.BYTE $AA,$AB
		.BYTE $FF
_nmi_tlmB3:
		.WORD $EE21
		.BYTE $02
		.BYTE $63,$64
		.WORD $0E22
		.BYTE $02
		.BYTE $63,$64
		.BYTE $FF

; =============== S U B	R O U T	I N E =======================================
sub_96BC:
		PHA
		LDA		_PAD0_REG
		LDA		_PAD1_REG
		PLA
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_96C5:
		LDX		#>[byte_3C0]
		LDY		#<[byte_3C0]
		LDA		_cur_player_idx
		BEQ		loc_96CF
		LDY		#<[byte_3E0]
loc_96CF:
		STX		byte_91
		STY		byte_90
		LDY		#$00
loc_96D5:
		LDA		(byte_90),Y
		STA		byte_400,Y
		INY
		CPY		#$1A
		BNE		loc_96D5
		LDY		#<[byte_3E0]
		LDA		_cur_player_idx
		BEQ		loc_96E7
		LDY		#<[byte_3C0]
loc_96E7:
		STY		byte_90
		LDY		#$00
		LDA		(byte_90),Y
		STA		byte_420
		INY
		LDX		#$18
loc_96F3:
		LDA		(byte_90),Y
		STA		byte_420,X
		DEX
		INY
		CPY		#$19
		BNE		loc_96F3
		LDA		(byte_90),Y
		STA		byte_439
		LDX		#$1A
		LDA		#$00
loc_9707:
		STA		byte_400,X
		STA		byte_420,X
		INX
		CPX		#$20
		BNE		loc_9707
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_9713:
		LDX		#$03
		LDY		#$C0
		LDA		_cur_player_idx
		BEQ		loc_971D
		LDY		#$E0
loc_971D:
		STX		byte_91
		STY		byte_90
		LDY		#$00
loc_9723:
		LDA		byte_400,Y
		STA		(byte_90),Y
		INY
		CPY		#$1A
		BNE		loc_9723
		LDY		#$E0
		LDA		_cur_player_idx
		BEQ		loc_9735
		LDY		#$C0
loc_9735:
		STY		byte_90
		LDY		#$00
		LDA		byte_420
		STA		(byte_90),Y
		INY
		LDX		#$18
loc_9741:
		LDA		byte_420,X
		STA		(byte_90),Y
		DEX
		INY
		CPY		#$19
		BNE		loc_9741
		LDA		byte_439
		STA		(byte_90),Y
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_9752:
		JSR		sub_98C7
		LDA		#$01
		JSR		sub_99A3
		LDA		byte_9C
		STA		byte_96
		LDA		#$01
		LDX		#$00
		JSR		sub_98D9
		STA		byte_97
		STX		byte_98
		BEQ		loc_9773
		LDA		byte_48
		BNE		loc_979F
		LDA		byte_4A
		BNE		loc_979F
loc_9773:
		LDA		byte_9D
		STA		byte_96
		LDA		#$01
		LDX		#$00
		JSR		sub_98D9
		BEQ		loc_9786
		LDA		byte_97
		BNE		loc_979F
		BEQ		loc_979A
loc_9786:
		LDA		byte_4A
		BNE		loc_979A
		LDA		byte_97
		BNE		loc_9792
		CPX		byte_98
		BCS		loc_979A
loc_9792:
		STX		byte_98
		LDA		byte_49
		EOR		#$01
		STA		byte_49
loc_979A:
		LDX		byte_98
loc_979C:
		LDA		#$00
		RTS
; ---------------------------------------------------------------------------
loc_979F:
		LDA		#$01
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_97A2:
		LDA		byte_400
		BEQ		loc_979C
		LDX		#$06
loc_97A9:
		LDA		byte_420,X
		CMP		#$02
		BCC		loc_979C
		DEX
		BNE		loc_97A9
		BEQ		loc_979F
loc_97B5:
		LDY		#$01
		STY		_pause_mode_flag
		STA		byte_95
		JSR		sub_9812
		PHP
		JSR		sub_99C4
		PLP
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_97C5:
		LDY		#$01
		STY		_pause_mode_flag
		STA		byte_95
		STA		byte_95
		STA		byte_9B
		JSR		sub_9812
		BNE		loc_97E5
		LDA		byte_9B
		STA		byte_95
		LDY		byte_49
		LDA		byte_46,Y
		STA		byte_96
		LDA		#$00
		JSR		sub_98FE
loc_97E5:
		PHP
		JSR		sub_99C4
		PLP
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_97EB:
		LDA		byte_419
		CMP		#$0F
		BNE		loc_980F
		LDA		byte_439
		BNE		loc_980C
		LDA		byte_420
		BNE		loc_9809
		LDX		#$05
loc_97FE:
		LDA		byte_433,X
		BNE		loc_9809
		DEX
		BPL		loc_97FE
		LDA		#$02
		RTS
; ---------------------------------------------------------------------------
loc_9809:
		LDA		#$03
		RTS
; ---------------------------------------------------------------------------
loc_980C:
		LDA		#$01
		RTS
; ---------------------------------------------------------------------------
loc_980F:
		LDA		#$00
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_9812:
		LDA		byte_95
		STA		byte_9A
		JSR		sub_98C7
		LDA		#$01
		JSR		sub_99A3
		LDA		byte_9C
		STA		byte_96
		LDA		#$01
		JSR		sub_98FE
		BNE		loc_9886
		LDA		byte_48
		BNE		loc_9883
		LDA		byte_4A
		BNE		loc_9883
		LDA		byte_459
		CMP		#$0F
		BEQ		loc_9883
		LDA		#$12
		JSR		sub_99A3
		LDA		byte_9D
		STA		byte_96
		LDA		#$02
		LDX		#$00
		JSR		sub_98D9
		BEQ		loc_9883
		LDX		#$00
		STX		byte_99
loc_984E:
		LDA		#$01
		JSR		sub_99A3
		LDA		byte_9C
		STA		byte_96
		LDA		#$01
		LDX		byte_99
		JSR		sub_98D9
		BNE		loc_9880
		STX		byte_99
		CPX		byte_9A
		BEQ		loc_9878
		LDA		#$12
		JSR		sub_99A3
		LDA		byte_9D
		STA		byte_96
		LDA		#$02
		LDX		#$00
		JSR		sub_98D9
		BEQ		loc_9886
loc_9878:
		INC		byte_99
		LDA		byte_99
		CMP		#$19
		BNE		loc_984E
loc_9880:
		JMP		loc_9889
; ---------------------------------------------------------------------------
loc_9883:
		LDA		#$00
		RTS
; ---------------------------------------------------------------------------
loc_9886:
		LDA		#$01
		RTS
; ---------------------------------------------------------------------------
loc_9889:
		LDX		#$00
		STX		byte_99
loc_988D:
		LDA		#$01
		JSR		sub_99A3
		LDA		byte_9D
		STA		byte_96
		LDA		#$01
		LDX		byte_99
		JSR		sub_98D9
		BNE		loc_98BB
		STX		byte_99
		LDA		#$12
		JSR		sub_99A3
		LDA		byte_9C
		STA		byte_96
		LDA		#$02
		LDX		#$00
		JSR		sub_98D9
		BEQ		loc_9886
		INC		byte_99
		LDA		byte_99
		CMP		#$19
		BNE		loc_988D
loc_98BB:
		LDA		byte_99
		BEQ		loc_9883
		LDA		byte_9C
		CMP		byte_9D
		BCC		loc_9886
		BCS		loc_9883

; =============== S U B	R O U T	I N E =======================================
sub_98C7:
		LDY		byte_49
		LDA		byte_46,Y
		STA		byte_9C
		LDA		byte_49
		EOR		#$01
		TAY
		LDA		byte_46,Y
		STA		byte_9D
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_98D9:
		JSR		sub_96BC
		JSR		sub_998E
		STX		byte_95
loc_98E1:
		LDY		byte_95
		LDA		(byte_90),Y
		BEQ		loc_98EC
		JSR		sub_9901
		BEQ		loc_98F9
loc_98EC:
		INC		byte_95
		LDA		byte_95
		CMP		#$19
		BNE		loc_98E1
		LDX		byte_95
		LDA		#$01
		RTS
; ---------------------------------------------------------------------------
loc_98F9:
		LDX		byte_95
		LDA		#$00
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_98FE:
		JSR		sub_998E

; =============== S U B	R O U T	I N E =======================================
sub_9901:
		LDY		#$00
		LDA		(byte_90),Y
		BEQ		loc_9915
		LDA		byte_95
		BNE		loc_9944
		LDY		byte_96
		LDA		(byte_92),Y
		CMP		#$02
		BCC		loc_9947
		BCS		loc_9944
loc_9915:
		LDA		byte_96
		CLC
		ADC		byte_95
		CMP		#$19
		BCS		loc_9927
		TAY
		LDA		(byte_92),Y
		CMP		#$02
		BCC		loc_9947
		BCS		loc_9944
loc_9927:
		PHP
		LDY		#$00
loc_992A:
		LDA		(byte_90),Y
		BNE		loc_9943
		INY
		CPY		#$13
		BNE		loc_992A
		PLP
		BEQ		loc_9947
		LDY		byte_95
loc_9938:
		DEY
		LDA		(byte_90),Y
		BNE		loc_9944
		CPY		#$13
		BNE		loc_9938
		BEQ		loc_9947
loc_9943:
		PLP
loc_9944:
		LDA		#$01
		RTS
; ---------------------------------------------------------------------------
loc_9947:
		LDY		byte_95
		LDA		(byte_90),Y
		SEC
		SBC		#$01
		STA		(byte_90),Y
		TYA
		CLC
		ADC		byte_96
		CMP		#$19
		BCC		loc_995A
		LDA		#$19
loc_995A:
		TAY
		LDA		(byte_90),Y
		CLC
		ADC		#$01
		STA		(byte_90),Y
		CPY		#$19
		BEQ		loc_998A
		LDA		(byte_92),Y
		BEQ		loc_998A
		LDA		#$00
		STA		(byte_92),Y
		TYA
		PHA
		LDY		#$1A
loc_9972:
		LDA		(byte_92),Y
		BEQ		loc_997B
		INY
		CPY		#$1F
		BNE		loc_9972
loc_997B:
		PLA
		STA		(byte_92),Y
		LDY		#$00
		LDA		(byte_92),Y
		CLC
		ADC		#$01
		STA		(byte_92),Y
		SEC
		BCS		loc_998B
loc_998A:
		CLC
loc_998B:
		LDA		#$00
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_998E:
		TAY
		LDA		byte_99A0,Y
		STA		byte_90
		CLC
		ADC		#$20
		STA		byte_92
		LDA		#$04
		STA		byte_91
		STA		byte_93
		RTS
; ---------------------------------------------------------------------------
byte_99A0:
		.BYTE $00,$40,$80

; =============== S U B	R O U T	I N E =======================================
sub_99A3:
		PHA
		AND		#$30
		ASL
		ASL
		TAY
		PLA
		AND		#$03
		ASL
		ASL
		ASL
		ASL
		ASL
		ASL
		TAX
		LDA		#$40
		STA		byte_94
loc_99B7:
		LDA		byte_400,Y
		STA		byte_400,X
		INY
		INX
		DEC		byte_94
		BNE		loc_99B7
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_99C4:
		LDA		#$00
		STA		byte_533
loc_99C9:
		LDA		byte_533
		BEQ		loc_99C9
		LDA		#$00
		STA		_pause_mode_flag
		RTS

; =============== S U B	R O U T	I N E =======================================
_sync:
		LDA		byte_568
		BEQ		_wait_for_flush
		LDA		_pads_press
		AND		#$20
		BEQ		_wait_for_flush
		JSR		sub_99F6

; =============== S U B	R O U T	I N E =======================================
_wait_for_flush:
		LDA		#$01
		STA		_ppu_dequeue_req

; =============== S U B	R O U T	I N E =======================================
sub_99E6:
		JSR		_increment_rand_seed
		LDA		_nmi_flag
		BEQ		sub_99E6
		INC		_frames_counter
		LDA		#$00
		STA		_ppu_dequeue_req
		STA		_nmi_flag
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_99F6:
		JSR		_apu_play_ctrlC_set80
loc_99F9:
		JSR		_wait_for_flush
		LDA		_pads_press
		AND		#$20
		BEQ		loc_99F9
		JMP		_apu_play_ctrlC_set40

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
; ---------------------------------------------------------------------------
loc_9A7A:
		JSR		_delay
loc_9A7D:
		LDA		#$01
		STA		byte_533
		JSR		_apu_play
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
_delay:
		LDY		#$10
loc_9A96:
		LDA		$0100,Y
		LDA		$0200,Y
		LDA		$0300,Y
		LDA		$0500,Y
		LDA		$0600,Y
		DEY
		BNE		loc_9A96
		RTS

; =============== S U B	R O U T	I N E =======================================
_ppu_nt_clear:
		LDA		#$20
		LDX		#$2F
		LDY		#$00

; !FALLTHROUGH!

; =============== S U B	R O U T	I N E =======================================
_ppu_fill_ex:
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
		.BYTE >[_pal1_w]
		.BYTE >[_pal2_w]
		.BYTE >[_pal3_w]
		.BYTE >[_ppu_pal_buf4]
		.BYTE >[_ppu_pal5]
		.BYTE >[_ppu_pal6]
		.BYTE >[_ppu_pal7]
		.BYTE >[_ppu_pal8]
_nmi_tlm_lib_lo:
		.BYTE <[_pal1_w]
		.BYTE <[_pal2_w]
		.BYTE <[_pal3_w]
		.BYTE <[_ppu_pal_buf4]
		.BYTE <[_ppu_pal5]
		.BYTE <[_ppu_pal6]
		.BYTE <[_ppu_pal7]
		.BYTE <[_ppu_pal8]

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
		.BYTE <[_nmi_tlmB7]
off_9BBC:
		.BYTE >[_nmi_tlmB1_ram]
		.BYTE >[_nmi_tlmB2_ram]
		.BYTE >[_nmi_tlmB3]
		.BYTE >[_nmi_tlmB4]
		.BYTE >[_nmi_tlmB5]
		.BYTE >[_nmi_tlmB6]
		.BYTE >[_nmi_tlmB7]

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
sub_9C7F:
		STA		byte_FA
		STA		$4025
		STA		byte_FA
		RTS

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
_ppu_load_mem_swap:
		LDY		#$00
		STY		_tmp4Bb
		JMP		_ppu_load_ex

; =============== S U B	R O U T	I N E =======================================
_ppu_load_ppu_swap:
		LDA		#$01
		STA		_tmp4Bb

; =============== S U B	R O U T	I N E =======================================
_ppu_load_ex:
		LDA		_ppu_ctrl_shadow
		ORA		#$04
		STA		_ppu_ctrl_shadow
		STA		_PPU_CTRL
loc_9D68:
		LDA		_tmp20w+1
		STA		$2006
		LDA		_tmp20w
		STA		$2006
		LDA		$2007
		LDA		$2007
		PHA
		LDA		_tmp4Bb
		BNE		loc_9D92
		LDA		(_tmp1Cw),Y
		LDX		_tmp20w+1
		STX		$2006
		LDX		_tmp20w
		STX		$2006
		STA		$2007
		PLA
		STA		(_tmp1Cw),Y
		JMP		loc_9DBD
; ---------------------------------------------------------------------------
loc_9D92:
		LDX		_tmp1Cw+1
		STX		$2006
		LDX		_tmp1Cw
		STX		$2006
		LDX		$2007
		LDA		$2007
		LDX		_tmp20w+1
		STX		$2006
		LDX		_tmp20w
		STX		$2006
		STA		$2007
		LDX		_tmp1Cw+1
		STX		$2006
		LDX		_tmp1Cw
		STX		$2006
		PLA
		STA		$2007
loc_9DBD:
		INC		_tmp20w
		BNE		loc_9DC3
		INC		_tmp20w+1
loc_9DC3:
		INC		_tmp1Cw
		BNE		loc_9DC9
		INC		_tmp1Cw+1
loc_9DC9:
		LDA		byte_1E
		SEC
		SBC		#$01
		STA		byte_1E
		BNE		loc_9DD6
		LDA		byte_1F
		BEQ		loc_9DE0
loc_9DD6:
		BCC		loc_9DDB
		JMP		loc_9D68
; ---------------------------------------------------------------------------
loc_9DDB:
		DEC		byte_1F
		JMP		loc_9D68
; ---------------------------------------------------------------------------
loc_9DE0:
		JMP		sub_9C6D

; =============== S U B	R O U T	I N E =======================================
_file_load:
		JSR		_apu_play_ctrlA_set01
		JSR		_spr_clear
		LDA		#$06
		STA		_nmi_tlm_lib_idx
		JSR		_sync
		JSR		_ppu_render_off
		JSR		_nmi_off
		LDA		#$20
		LDX		#$2F
		LDY		#$00
		JSR		_ppu_fill_ex
		JSR		_nmi_on
		JSR		_ppu_render_on
		LDA		#$07
		STA		_nmi_tlm_lib_idx
		JMP		_nmi_on

; =============== S U B	R O U T	I N E =======================================
_fds_file_load:
		LDA		#$00
		STA		$4022
		STA		$4010
		LDA		#$C0
		STA		_PAD1_REG
		JSR		_nmi_off
		LDA		_ppu_ctrl_shadow
		AND		#$FB
		STA		_ppu_ctrl_shadow
		STA		_PPU_CTRL
		RTS

; =============== S U B	R O U T	I N E =======================================
_pal_fade_outA:
		STY		byte_553
		LDA		#$07
		STA		_nmi_tlm_lib_idx
		JSR		_ppu_render_on
		LDA		#$04
		STA		_tpp_idx
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
		DEC		_tpp_idx
		BNE		loc_A152
		JSR		_pal_buf4_load_lib
		JMP		_pal_buf_flush

; =============== S U B	R O U T	I N E =======================================
_pal_fade_outB:
		STY		byte_553
		JSR		_pal_buf4_load_lib
		LDA		#$04
		STA		_tpp_idx
loc_A176:
		LDA		#$10
		JSR		_pal_buf_dec
		JSR		_pal_buf_flush
		DEC		_tpp_idx
		BNE		loc_A176
		JMP		_ppu_render_off

; =============== S U B	R O U T	I N E =======================================
_pal_buf4_load_lib:
		LDA		#$3F
		STA		_ppu_pal_buf4
		LDA		#$00
		STA		_ppu_pal_buf4+1
		LDA		#$20
		STA		_ppu_pal_buf4+2
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
		STA		_ppu_pal_buf4,Y
		DEY
		CPY		#$02
		BNE		loc_A1A9
		RTS

; =============== S U B	R O U T	I N E =======================================
_pal_buf_dec:
		STA		byte_57
		LDY		#$1F
loc_A1B8:
		LDA		_ppu_pal_buf4+3,Y
		SEC
		SBC		byte_57
		BCS		loc_A1C2
		LDA		#$0F
loc_A1C2:
		STA		_ppu_pal_buf4+3,Y
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
; ---------------------------------------------------------------------------
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
; ---------------------------------------------------------------------------
locret_A23E:
		RTS
