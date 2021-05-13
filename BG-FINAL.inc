
		ORG $A980

; =============== S U B	R O U T	I N E =======================================
_ending:
		JSR		_ending_sub_exec
		JSR		_sync
		JMP		_ending

; =============== S U B	R O U T	I N E =======================================
_ending_sub_exec:
		LDA		_ending_sub_idx
		JSR		_switch
; ---------------------------------------------------------------------------
		.WORD _ending00
		.WORD _ending01
		.WORD _ending02
		.WORD _ending03
		.WORD _ending02
		.WORD _ending05
		.WORD _ending06
		.WORD _ending07
		.WORD _ending06
		.WORD _ending09
		.WORD _ending06
		.WORD _ending09_final_screen
		.WORD _ending0A_secret_staff
		.WORD _ending02
		.WORD _ending0E

; =============== S U B	R O U T	I N E =======================================
_ending00:
		LDY		#$00
		STY		byte_FC
		STY		byte_FD
		JSR		_apu_play_ctrlA_set01
		LDA		#$98
		STA		_ppu_ctrl_shadow
		JSR		_ppu_render_off
		LDA		#_pad_tmp1+1
		JSR		sub_9C7F
		JSR		_spr_clear
		JSR		_nmi_off
		JSR		sub_AC9B
		LDX		#<[_tlm_AEDB]
		LDY		#>[_tlm_AEDB]
		JSR		_ppu_tlm_unpack
		JSR		_nmi_on
		INC		_ending_sub_idx
		LDY		#$08
		JSR		_pal_fade_outA
		JMP		_apu_play_ctrlE_set10

; =============== S U B	R O U T	I N E =======================================
_ending01:
		LDA		#$00
		STA		byte_572
		LDA		#$21
		STA		_tmp51w+1
		LDA		#$47
		STA		_tmp51w
		LDA		#>[byte_AE09]
		STA		_tmp53w+1
		LDA		#<[byte_AE09]
		STA		_tmp53w
		INC		_ending_sub_idx
		RTS

; =============== S U B	R O U T	I N E =======================================
_ending03:
		LDA		#$00
		STA		byte_572
		LDA		#$22
		STA		_tmp51w+1
		LDA		#$8E
		STA		_tmp51w
		LDA		#>[byte_AE4C]
		STA		_tmp53w+1
		LDA		#<[byte_AE4C]
		STA		_tmp53w
		INC		_ending_sub_idx
		RTS

; =============== S U B	R O U T	I N E =======================================
_ending02:
		LDA		_nmi_counter
		BNE		locret_AA1F
		LDA		byte_32
		ORA		_ppu_queue_req
		ORA		_nmi_tlm_lib_idx
		BEQ		loc_AA20
locret_AA1F:
		RTS
; ---------------------------------------------------------------------------
loc_AA20:
		LDA		_tmp51w+1
		STA		_nmi_tlmB2_ram
		LDA		_tmp51w
		STA		byte_10C
		LDA		#$01
		STA		byte_10D
		LDA		_tmp53w
		STA		_tmp20w
		LDA		_tmp53w+1
		STA		_tmp20w+1
		LDA		#$01
		STA		byte_111
		LDA		#$FF
		STA		byte_10F
		LDY		#$00
		LDA		(_tmp20w),Y
		STA		byte_57
		CMP		#$FF
		BNE		loc_AA4F
		INC		_ending_sub_idx
		RTS
; ---------------------------------------------------------------------------
loc_AA4F:
		LDY		#$CA
		CMP		#$0F
		BEQ		loc_AA5B
		LDY		#$C9
		CMP		#$0E
		BNE		loc_AA90
loc_AA5B:
		STY		byte_58
		LDA		_tmp53w
		CLC
		ADC		#$01
		STA		_tmp53w
		STA		_tmp20w
		BCC		loc_AA6A
		INC		_tmp53w+1
loc_AA6A:
		LDA		_tmp53w+1
		STA		_tmp20w+1
		LDY		#$00
		LDA		(_tmp20w),Y
		STA		byte_57
		LDA		#$FF
		STA		byte_113
		LDA		_tmp51w+1
		STA		byte_10F
		LDA		_tmp51w
		SEC
		SBC		#$20
		STA		byte_110
		BCS		loc_AA8B
		DEC		byte_10F
loc_AA8B:
		LDA		byte_58
		STA		byte_112
loc_AA90:
		LDA		byte_57
		STA		byte_10E
		LDA		#$02
		STA		byte_32
		LDA		_tmp53w
		CLC
		ADC		#$01
		STA		_tmp53w
		STA		_tmp20w
		BCC		loc_AAA6
		INC		_tmp53w+1
loc_AAA6:
		LDA		_tmp53w+1
		STA		_tmp20w+1
		LDA		_tmp51w
		CLC
		ADC		#$01
		STA		_tmp51w
		BCC		loc_AAB5
		INC		_tmp51w+1
loc_AAB5:
		INC		byte_572
		LDA		byte_572
		CMP		#$12
		BNE		loc_AACF
		LDA		#$00
		STA		byte_572
		LDA		_tmp51w
		CLC
		ADC		#$2E
		STA		_tmp51w
		BCC		loc_AACF
		INC		_tmp51w+1
loc_AACF:
		LDA		#$0C
		STA		_nmi_counter
		RTS

; =============== S U B	R O U T	I N E =======================================
_ending05:
		INC		_ending_sub_idx
		LDA		#$78
		JSR		_wait_for_nmi
		LDA		#>[byte_ACCF]
		STA		_tmp53w+1
		LDA		#<[byte_ACCF]
		STA		_tmp53w
		LDY		#$00
		STY		byte_54F
		STY		_title_push_start_toggle
		JMP		sub_AB98

; =============== S U B	R O U T	I N E =======================================
_ending07:
		LDA		#$10
		STA		_nmi_counter
loc_AAF3:
		JSR		sub_ABB3
		JSR		_sync
		LDA		_nmi_counter
		BNE		loc_AAF3
		INC		_ending_sub_idx
		LDA		#>[byte_AD4E]
		STA		_tmp53w+1
		LDA		#<[byte_AD4E]
		STA		_tmp53w
		LDY		#$00
		STY		byte_54F
		STY		_title_push_start_toggle
		JMP		sub_AB98

; =============== S U B	R O U T	I N E =======================================
_ending09:
		JSR		_apu_play_ctrlA_set10
		LDA		#$30
		STA		_nmi_counter
loc_AB1A:
		JSR		sub_ABB3
		JSR		_sync
		LDA		_nmi_counter
		BNE		loc_AB1A
		LDY		#$30
loc_AB26:
		LDA		byte_AFAD,Y
		STA		_nmi_tlmB1_ram,Y
		DEY
		BPL		loc_AB26
		LDA		#$01
		STA		byte_32
		LDA		#$3C
		STA		_nmi_counter
		INC		_ending_sub_idx
		LDA		#>[byte_AD79]
		STA		_tmp53w+1
		LDA		#<[byte_AD79]
		STA		_tmp53w
		LDY		#$00
		STY		byte_54F
		STY		_title_push_start_toggle
		STY		_tmp4Bb
		STY		_timer_minutes
		JMP		sub_AB98

; =============== S U B	R O U T	I N E =======================================
_ending06:
		JSR		sub_ABB3
		LDY		#$00
loc_AB56:
		LDA		byte_53C,Y
		CLC
		ADC		byte_53E,Y
		STA		byte_53C,Y
		LDX		#$00
		LDA		byte_53D,Y
		AND		#$80
		BEQ		loc_AB6B
		LDX		#$FF
loc_AB6B:
		STX		byte_57
		LDA		byte_53B,Y
		ADC		byte_53D,Y
		STA		byte_53B,Y
		LDA		byte_53A,Y
		ADC		byte_57
		STA		byte_53A,Y
		TYA
		CLC
		ADC		#$05
		TAY
		CMP		#$14
		BCC		loc_AB56
		DEC		byte_54E
		LDA		byte_54E
		BPL		locret_AB97
		JSR		sub_AB98
		BCC		locret_AB97
		INC		_ending_sub_idx
locret_AB97:
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_AB98:
		LDY		byte_54F
		LDX		#$00
		LDA		(_tmp53w),Y
		CMP		#$80
		BEQ		loc_ABAF
loc_ABA3:
		LDA		(_tmp53w),Y
		INY
		STA		byte_53A,X
		INX
		CPX		#$15
		BNE		loc_ABA3
		CLC
loc_ABAF:
		STY		byte_54F
nullsub_9:
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_ABB3:
		JSR		sub_AC08
		LDY		#$00
		STY		_cur_player_idx
		STY		byte_60
		STY		_spr_buf_pos
		STY		byte_6B
		LDA		#$27
		STA		_spr_lib_idx
		LDA		byte_540
		STA		byte_66
		LDA		byte_53F
		STA		byte_67
		LDA		byte_53B
		STA		byte_68
		LDA		byte_53A
		STA		byte_69
		JSR		_spr_lib_insert
		LDY		#$64
		STY		_spr_buf_pos
		LDY		#$01
		STY		byte_6B
		LDA		_title_push_start_toggle
		EOR		#$01
		STA		_title_push_start_toggle
		BEQ		nullsub_9
		LDY		#$28
		STY		_spr_lib_idx
		LDA		byte_54A
		STA		byte_66
		LDA		byte_549
		STA		byte_67
		LDA		byte_545
		STA		byte_68
		LDA		byte_544
		STA		byte_69
		JMP		_spr_lib_insert

; =============== S U B	R O U T	I N E =======================================
sub_AC08:
		LDY		#$AF
		LDA		#$F4
loc_AC0C:
		STA		_spr_buf,Y
		DEY
		CPY		#$FF
		BNE		loc_AC0C
		RTS

; =============== S U B	R O U T	I N E =======================================
_ending09_final_screen:
		LDA		_nmi_counter
		BNE		loc_AC27
		INC		_tmp4Bb
		LDA		_tmp4Bb
		CMP		#$3B
		BCC		loc_AC27
		LDA		#$00
		STA		_tmp4Bb
		INC		_timer_minutes
loc_AC27:
		LDA		_timer_minutes
		CMP		#$03
		BNE		_skip
		LDA		_tmp4Bb
		CMP		#$1E
		BCS		_skip
		LDA		_cheat_flag1_w
		BEQ		_skip
		LDA		_pads_held
		CMP		#$A6
		BNE		_skip
		LDA		_pads_held+1
		CMP		#$C1
		BNE		_skip
		INC		_ending_sub_idx
		LDY		#$08
		JMP		_pal_fade_outB
; ---------------------------------------------------------------------------
_skip:
		LDA		_pads_held
		BEQ		locret_AC5E
		JSR		_apu_play_ctrlA_set04
		PLA
		PLA
		LDY		#$08
		JSR		_pal_fade_outB
		LDA		#$F4
		STA		_ppu_ctrl_shadow
locret_AC5E:
		RTS

; =============== S U B	R O U T	I N E =======================================
_ending0A_secret_staff:
		JSR		_spr_clear
		JSR		_ppu_render_off
		JSR		_nmi_off
		JSR		sub_AC9B
		LDX		#<[_tlm_AFD6]
		LDY		#>[_tlm_AFD6]
		JSR		_ppu_tlm_unpack
		JSR		_nmi_on
		LDA		#$00
		STA		byte_572
		LDA		#$20
		STA		_tmp51w+1
		LDA		#$E7
		STA		_tmp51w
		LDA		#>[_tlm_staff]
		STA		_tmp53w+1
		LDA		#<[_tlm_staff]
		STA		_tmp53w
		INC		_ending_sub_idx
		JSR		_apu_play_ctrlD_set02
		LDY		#$08
		JMP		_pal_fade_outA

; =============== S U B	R O U T	I N E =======================================
_ending0E:
		LDA		#$0B
		STA		_ending_sub_idx
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_AC9B:
		LDA		#$20
		LDX		#$2F
		LDY		#$00
		JSR		_ppu_fill
		LDA		#$10
		STA		_tmp4Bb
		LDA		#$20
		STA		_timer_minutes
		LDA		#$C6
		STA		byte_4D
loc_ACB0:
		LDA		byte_4D
		STA		_tlm_AED6_w+1
		CLC
		ADC		#$20
		STA		byte_4D
		LDA		_timer_minutes
		STA		_tlm_AED6_w
		ADC		#$00
		STA		_timer_minutes
		LDX		#<[_tlm_AED6_w]
		LDY		#>[_tlm_AED6_w]
		JSR		_ppu_tlm_unpack
		DEC		_tmp4Bb
		BNE		loc_ACB0
		RTS
; ---------------------------------------------------------------------------
byte_ACCF:
		.BYTE $00,$2A,$00,$00,$AA,$01,$08,$00,$FC,$00,$00,$4A,$00,$00,$AA,$01
		.BYTE $18,$00,$FC,$00,$05,$00,$2E,$00,$01,$00,$00,$F0,$00,$FC,$00,$00
		.BYTE $4E,$00,$01,$00,$01,$00,$00,$FC,$00,$03,$00,$32,$00,$02,$00,$00
		.BYTE $E0,$00,$FC,$00,$00,$52,$00,$02,$00,$00,$F0,$00,$FC,$00,$03,$00
		.BYTE $3A,$00,$03,$00,$00,$D0,$00,$FC,$00,$00,$5A,$00,$03,$00,$00,$E0
		.BYTE $00,$FC,$00,$03,$00,$46,$00,$04,$00,$00,$C0,$00,$FC,$AB,$00,$66
		.BYTE $00,$04,$00,$00,$D0,$00,$FC,$AB,$05,$00,$5E,$00,$05,$00,$00,$AC
		.BYTE $00,$FD,$00,$00,$7E,$00,$05,$00,$00,$BC,$00,$FD,$00,$03,$80
byte_AD4E:
		.BYTE $00,$72,$00,$FE,$00,$00,$A0,$00,$00,$00,$00,$92,$00,$02,$00,$00
		.BYTE $B0,$00,$01,$99,$0A,$00,$5E,$00,$04,$00,$00,$A0,$00,$00,$00,$00
		.BYTE $A6,$00,$FB,$80,$00,$C0,$00,$FC,$80,$07,$80
byte_AD79:
		.BYTE $00,$7E,$00,$FC,$00,$00,$A0,$00,$02,$00,$00,$82,$00,$FE,$00,$00
		.BYTE $A4,$00,$03,$00,$03,$00,$6E,$00,$FC,$00,$00,$A8,$00,$02,$AA,$00
		.BYTE $7A,$00,$FD,$56,$00,$B0,$00,$04,$71,$08,$00,$4A,$00,$FC,$00,$00
		.BYTE $C0,$00,$04,$00,$00,$62,$00,$FD,$00,$00,$D8,$00,$06,$00,$03,$00
		.BYTE $3A,$00,$FE,$00,$00,$D0,$00,$04,$00,$00,$56,$00,$FF,$00,$00,$F0
		.BYTE $00,$04,$00,$03,$00,$32,$00,$FF,$00,$00,$E0,$00,$04,$00,$00,$52
		.BYTE $00,$FF,$00,$01,$00,$00,$04,$00,$03,$00,$2E,$00,$FF,$56,$00,$F0
		.BYTE $00,$04,$00,$00,$4E,$00,$FF,$56,$01,$10,$00,$04,$00,$05,$80
_unref_txt_tadashi_inu:
		.BYTE $24,$11,$14,$11,$23,$18,$19,$2E,$19,$1E,$25,$19,$2E,$0E,$E4,$E7
		.BYTE $FF
byte_AE09:
		.BYTE $D1,$E5,$E0,$EA,$2E,$0E,$B3,$B9,$BA,$0E,$E9,$C2,$F1,$CE,$B2,$D0
		.BYTE $CF,$9B,$CE,$B2,$E6,$D5,$D2,$E3,$2E,$E8,$D3,$DC,$C8,$D3,$E5,$2E
		.BYTE $DE,$D2,$DE,$D7,$FE,$2E,$D5,$DB,$F2,$2E,$E8,$D3,$DC,$C5,$D3,$2E
		.BYTE $DB,$FA,$EF,$DC,$E0,$DA,$E4,$FE,$DA,$DA,$E6,$2E,$DC,$C5,$D3,$DC
		.BYTE $EF,$DD,$FF
byte_AE4C:
		.BYTE $9C,$9D,$0E,$B3,$B9,$BA,$0E,$E9,$C2,$F1,$CE,$9E,$9F,$FF
_tlm_staff:
		.BYTE $2E,$2E,$2E,$2E,$A5,$2E,$23,$24,$11,$16,$16,$2E,$A5,$2E,$2E,$2E
		.BYTE $2E,$2E,$24,$1F,$23,$18,$19,$29,$25,$1B,$19,$2E,$1E,$11,$1B,$11
		.BYTE $1D,$25,$22,$11,$2E,$2E,$24,$11,$14,$11,$23,$18,$19,$2E,$19,$1E
		.BYTE $25,$19,$2E,$2E,$2E,$2E,$2E,$2E,$1E,$1F,$22,$19,$11,$1B,$19,$2E
		.BYTE $24,$15,$22,$11,$1D,$1F,$24,$1F,$2E,$2E,$2E,$1D,$11,$1B,$1F,$24
		.BYTE $1F,$2E,$1E,$11,$1B,$11,$29,$11,$1D,$11,$2E,$2E,$2E,$1D,$11,$29
		.BYTE $25,$1D,$19,$2E,$1D,$1F,$22,$19,$24,$11,$2E,$2E,$2E,$2E,$2E,$2E
		.BYTE $2E,$29,$25,$1B,$11,$2E,$12,$11,$1E,$12,$11,$FF
_tlm_AED6_w:
		.BYTE $00,$00,$54,$2E,$FF
_tlm_AEDB:
		.BYTE $20,$84,$18,$82,$83,$84,$85,$82,$83,$84,$85,$2E,$2E,$2E,$2E,$2E
		.BYTE $2E,$2E,$2E,$40,$41,$42,$43,$40,$41,$42,$43,$20,$A4,$18,$92,$93
		.BYTE $94,$95,$92,$93,$94,$95,$44,$45,$2E,$62,$63,$2E,$64,$65,$50,$51
		.BYTE $52,$53,$50,$51,$52,$53,$20,$CC,$08,$54,$55,$2E,$72,$73,$2E,$74
		.BYTE $75,$20,$C4,$90,$60,$70,$80,$90,$60,$70,$80,$90,$60,$70,$80,$90
		.BYTE $60,$70,$80,$90,$20,$C5,$90,$61,$71,$81,$91,$61,$71,$81,$91,$61
		.BYTE $71,$81,$91,$61,$71,$81,$91,$20,$DA,$90,$60,$70,$80,$90,$60,$70
		.BYTE $80,$90,$60,$70,$80,$90,$60,$70,$80,$90,$20,$DB,$90,$61,$71,$81
		.BYTE $91,$61,$71,$81,$91,$61,$71,$81,$91,$61,$71,$81,$91,$22,$C4,$18
		.BYTE $82,$83,$84,$85,$82,$83,$84,$85,$82,$83,$84,$85,$40,$41,$42,$43
		.BYTE $40,$41,$42,$43,$40,$41,$42,$43,$22,$E4,$18,$92,$93,$94,$95,$92
		.BYTE $93,$94,$95,$92,$93,$94,$95,$50,$51,$52,$53,$50,$51,$52,$53,$50
		.BYTE $51,$52,$53,$23,$C9,$66,$AA,$23,$E5,$02,$FF,$BB,$23,$ED,$02,$A0
		.BYTE $A8,$FF
byte_AFAD:
		.BYTE $22,$14,$05,$46,$47,$48,$49,$4A,$22,$34,$05,$56,$57,$58,$59,$5A
		.BYTE $22,$54,$05,$66,$67,$68,$69,$6A,$22,$74,$05,$76,$77,$78,$79,$7A
		.BYTE $22,$94,$05,$86,$87,$88,$89,$8A,$FF
_tlm_AFD6:
		.BYTE $20,$A5,$01,$0A,$20,$A6,$54,$0B,$20,$BA,$01,$0C,$20,$C5,$D0,$10
		.BYTE $20,$DA,$D0,$2D,$22,$C5,$01,$0D,$22,$C6,$54,$0E,$22,$DA,$01,$0F
		.BYTE $FF
_tlm_unref:
		.BYTE $20,$E6,$57,$4C,$D1,$AF,$60,$04,$10
