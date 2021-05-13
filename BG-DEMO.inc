
		ORG $A980

; =============== S U B	R O U T	I N E =======================================
j__dummy:
		JMP	_dummy

; =============== S U B	R O U T	I N E =======================================
j__dummy_0:
		JMP	_dummy

; =============== S U B	R O U T	I N E =======================================
j__dummy_1:
		JMP	_dummy

; =============== S U B	R O U T	I N E =======================================
_j_demo:
		JMP		_demo

; =============== S U B	R O U T	I N E =======================================
_demo:
		LDA		_demo_sub_idx
		JSR		_switch
; ---------------------------------------------------------------------------
		.WORD _demo00
		.WORD _demo01
		.WORD _demo02
		.WORD _demo03
		.WORD _demo04
		.WORD _demo05
		.WORD _demo06
		.WORD _demo07
		.WORD _demo08

; =============== S U B	R O U T	I N E =======================================
_demo00:
		LDA		#$27
		STA		byte_FA
		JSR		_main02_sub00_game_init
		JSR		_main02_sub01
		JSR		_nmi_off
		JSR		sub_6B42
		JSR		_nmi_on
		LDY		#$01
		JSR		_pal_fade_outA
		LDY		#$00
		STY		byte_300
		INY
		STY		byte_557
		STY		byte_558
		STY		_nmi_tlm_lib_idx
		STY		byte_568
		STY		_demo_sub_idx
		STY		byte_5D
		RTS

; =============== S U B	R O U T	I N E =======================================
_demo03:
		JSR		_spr_clear
		JSR		sub_26EC6
		LDA		#$00
		STA		_tmp4Bb
loc_269DD:
		LDY		_tmp4Bb
		LDA		off_26A64,Y
		STA		_tmp20w
		LDA		off_26A6D,Y
		STA		_tmp20w+1
		JSR		sub_26A53
		INC		_tmp4Bb
		LDY		_tmp4Bb
		CPY		#$09
		BEQ		loc_26A0B
		LDA		off_26A64,Y
		STA		_tmp20w
		LDA		off_26A6D,Y
		STA		_tmp20w+1
		JSR		sub_26A53
		INC		_tmp4Bb
		LDA		#$5A
		JSR		_wait_for_nmi
		JMP		loc_269DD
; ---------------------------------------------------------------------------
loc_26A0B:
		LDA		#$FF
		JSR		_wait_for_nmi
		LDA		#$03
		STA		_tmp4Bb
loc_26A14:
		LDY		_tmp4Bb
		LDA		byte_26BF7,Y
		STA		_tmp20w
		LDA		byte_26BFB,Y
		STA		_tmp20w+1
		LDA		byte_26BFF,Y
		STA		byte_58
		LDA		byte_26C03,Y
		STA		byte_57
		JSR		sub_26BA8
		LDY		_tmp4Bb
		LDA		off_26C0B,Y
		STA		_tmp20w+1
		LDA		off_26C07,Y
		STA		_tmp20w
		JSR		sub_26BE6
		DEC		_tmp4Bb
		BPL		loc_26A14
		LDY		#$1C
loc_26A42:
		LDA		byte_26C4C,Y
		STA		_nmi_tlmB1_ram,Y
		DEY
		BPL		loc_26A42
		LDA		#$01
		STA		byte_32
		INC		_demo_sub_idx
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_26A53:
		LDY		#$29
loc_26A55:
		LDA		(_tmp20w),Y
		STA		_nmi_tlmB1_ram,Y
		DEY
		BPL		loc_26A55
		LDA		#$01
		STA		byte_32
		JMP		_sync
; ---------------------------------------------------------------------------
off_26A64:
		.BYTE <[byte_26A76]
		.BYTE <[byte_26A92]
		.BYTE <[byte_26ABA]
		.BYTE <[byte_26AD6]
		.BYTE <[byte_26B01]
		.BYTE <[byte_26B1D]
		.BYTE <[byte_26B45]
		.BYTE <[byte_26B61]
		.BYTE <[byte_26B8B]
off_26A6D:
		.BYTE >[byte_26A76]
		.BYTE >[byte_26A92]
		.BYTE >[byte_26ABA]
		.BYTE >[byte_26AD6]
		.BYTE >[byte_26B01]
		.BYTE >[byte_26B1D]
		.BYTE >[byte_26B45]
		.BYTE >[byte_26B61]
		.BYTE >[byte_26B8B]
byte_26A76:
		.BYTE $20,$D0,	1, $A,$20,$D1,$4A, $B,$20,$DB,	1, $C,$20,$F0, $C,$10
		.BYTE $2E,$2E,$2E,$2E,$2E,$2E,$2E,$C9,$2E,$C9,$2D,$FF
byte_26A92:
		.BYTE $21,$10,$0C,$10,$D1,$D6,$E7,$CC,$CE,$CF,$D0,$B1,$D0,$B2,$2D,$21
		.BYTE $30,$01,$0D,$21,$31,$4A,$0E,$21,$3B,$01,$0F,$23,$CC,$03,$A8,$A8
		.BYTE $A8,$23,$D4,$03,$8A,$8A,$8A,$FF
byte_26ABA:
		.BYTE $20,$C2,$01,$0A,$20,$C3,$4A,$0B,$20,$CD,$01,$0C,$20,$E2,$0C,$10
		.BYTE $2E,$2E,$2E,$2E,$2E,$2E,$2E,$C9,$2E,$C9,$2D,$FF
byte_26AD6:
		.BYTE $21,$02,$0C,$10,$D1,$D6,$E7,$CB,$CD,$B0,$D0,$B1,$D0,$B2,$2D,$21
		.BYTE $22,$01,$0D,$21,$23,$4A,$0E,$21,$2D,$01,$0F,$23,$C8,$04,$A2,$A2
		.BYTE $A2,$AA,$23,$D0,$04,$2A,$2A,$2A,$AA,$FF,$FF
byte_26B01:
		.BYTE $22,$D0,$01,$0A,$22,$D1,$4A,$0B,$22,$DB,$01,$0C,$22,$F0,$0C,$10
		.BYTE $2E,$2E,$2E,$2E,$2E,$2E,$2E,$C9,$2E,$C9,$2D,$FF
byte_26B1D:
		.BYTE $23,$10,$0C,$10,$DC,$FB,$E7,$CC,$CE,$CF,$D0,$B1,$D0,$B2,$2D,$23
		.BYTE $30,$01,$0D,$23,$31,$4A,$0E,$23,$3B,$01,$0F,$23,$EC,$03,$A2,$A2
		.BYTE $A2,$23,$F4,$03,$2A,$2A,$2A,$FF
byte_26B45:
		.BYTE $22,$C2,$01,$0A,$22,$C3,$4A,$0B,$22,$CD,$01,$0C,$22,$E2,$0C,$10
		.BYTE $2E,$2E,$2E,$2E,$2E,$2E,$2E,$C9,$2E,$C9,$2D,$FF
byte_26B61:
		.BYTE $23,$02,$0C,$10,$DC,$FB,$E7,$CB,$CD,$B0,$D0,$B1,$D0,$B2,$2D,$23
		.BYTE $22,$01,$0D,$23,$23,$4A,$0E,$23,$2D,$01,$0F,$23,$E8,$04,$AA,$A8
		.BYTE $A8,$A8,$23,$F0,$04,$AA,$8A,$8A,$8A,$FF
byte_26B8B:
		.BYTE $21,$CD,$04,$0A,$0B,$0B,$0C,$21,$ED,$04,$10,$C9,$2E,$2D,$22,$0D
		.BYTE $04,$10,$B3,$D0,$2D,$22,$2D,$04,$0D,$0E,$0E,$0F,$FF

; =============== S U B	R O U T	I N E =======================================
sub_26BA8:
		LDA		#>[byte_26C0F]
		STA		_tmp1Cw+1
		LDA		#<[byte_26C0F]
		STA		_tmp1Cw
		LDX		#$04
loc_26BB2:
		LDY		#$01
		LDA		_tmp20w
		STA		(_tmp1Cw),Y
		DEY
		CLC
		ADC		byte_58
		STA		_tmp20w
		LDA		_tmp20w+1
		STA		(_tmp1Cw),Y
		ADC		byte_57
		STA		_tmp20w+1
		LDA		_tmp1Cw
		CLC
		ADC		#$0F
		STA		_tmp1Cw
		BCC		loc_26BD1
		INC		_tmp1Cw+1
loc_26BD1:
		DEX
		BNE		loc_26BB2
		LDY		#$3C
loc_26BD6:
		LDA		byte_26C0F,Y
		STA		_nmi_tlmB1_ram,Y
		DEY
		BPL		loc_26BD6
		LDA		#$01
		STA		byte_32
		JMP		_sync

; =============== S U B	R O U T	I N E =======================================
sub_26BE6:
		LDY		#$0E
loc_26BE8:
		LDA		(_tmp20w),Y
		STA		_nmi_tlmB1_ram,Y
		DEY
		BPL		loc_26BE8
		LDA		#$01
		STA		byte_32
		JMP		_sync
; ---------------------------------------------------------------------------
byte_26BF7:
		.BYTE $22,$30,$C2,$D0
byte_26BFB:
		.BYTE $23,$23,$20,$20
byte_26BFF:
		.BYTE $E0,$E0,$20,$20
byte_26C03:
		.BYTE $FF,$FF,$00,$00
off_26C07:
		.BYTE <[byte_26C92]
		.BYTE <[byte_26C85]
		.BYTE <[byte_26C76]
		.BYTE <[byte_26C69]
off_26C0B:
		.BYTE >[byte_26C92]
		.BYTE >[byte_26C85]
		.BYTE >[byte_26C76]
		.BYTE >[byte_26C69]
byte_26C0F:
		.BYTE $00,$00,$0C,$34,$35,$34,$35,$34,$35,$34,$35,$34,$35,$34,$35,$00
		.BYTE $00,$0C,$36,$37,$36,$37,$36,$37,$36,$37,$36,$37,$36,$37,$00,$00
		.BYTE $0C,$38,$39,$38,$39,$38,$39,$38,$39,$38,$39,$38,$39,$00,$00,$0C
		.BYTE $3A,$3B,$3A,$3B,$3A,$3B,$3A,$3B,$3A,$3B,$3A,$3B,$FF
byte_26C4C:
		.BYTE $21,$CD,$04,$2F,$63,$64,$2F,$21,$ED,$04,$2F,$63,$64,$2F,$22,$0D
		.BYTE $04,$2F,$63,$64,$2F,$22,$2D,$04,$2F,$63,$64,$2F,$FF
byte_26C69:
		.BYTE $23,$CC,$03,$88,$88,$88,$23,$D4,$03,$88,$88,$88,$FF
byte_26C76:
		.BYTE $23,$C8,$04,$22,$22,$22,$AA,$23,$D0,$04,$22,$22,$22,$AA,$FF
byte_26C85:
		.BYTE $23,$EC,$03,$22,$22,$22,$23,$F4,$03,$22,$22,$22,$FF
byte_26C92:
		.BYTE $23,$E8,$04,$AA,$88,$88,$88,$23,$F0,$04,$AA,$88,$88,$88,$FF

; =============== S U B	R O U T	I N E =======================================
_demo01:
		JSR		_apu_play_ctrlD_set02
		LDY		#$00
		STY		byte_570
		STY		byte_55
		JSR		sub_277ED
		LDA		#$78
		JSR		_wait_for_nmi
		LDY		#$01
		STY		byte_55
		JSR		sub_277ED
		LDA		#$B4
		JSR		_wait_for_nmi
		LDY		#$02
		STY		byte_55
		INC		_demo_sub_idx
		JMP		sub_277ED

; =============== S U B	R O U T	I N E =======================================
_demo02:
		LDA		#$01
		STA		byte_55D
		LDA		#$D0
		STA		byte_55F
loc_26CD3:
		JSR		sub_26ED7
		LDY		#$1E
		STY		_nmi_counter
loc_26CDA:
		LDA		byte_55F
		STA		_spr_buf+3
		STA		_spr_buf+$B
		CLC
		ADC		#$08
		STA		_spr_buf+7
		STA		_spr_buf+$F
		LDA		#$1A
		STA		_spr_buf
		STA		_spr_buf+4
		LDA		#$CD
		STA		_spr_buf+8
		STA		_spr_buf+$C
		LDA		#$F0
		STA		_spr_buf+1
		STA		_spr_buf+9
		LDA		#$F2
		STA		_spr_buf+5
		STA		_spr_buf+$D
		LDA		#$00
		STA		_spr_buf+2
		STA		_spr_buf+6
		STA		_spr_buf+$A
		STA		_spr_buf+$E
		LDA		_nmi_counter
		BNE		loc_26D45
		LDA		byte_55F
		SEC
		SBC		#$10
		STA		byte_55F
		INC		byte_55D
		LDA		byte_55D
		CMP		#$0D
		BEQ		loc_26D41
		CMP		#$07
		BNE		loc_26D3E
		LDA		byte_55F
		SEC
		SBC		#$10
		STA		byte_55F
loc_26D3E:
		JMP		loc_26CD3
; ---------------------------------------------------------------------------
loc_26D41:
		INC		_demo_sub_idx
		RTS
; ---------------------------------------------------------------------------
loc_26D45:
		JSR		_sync
		JMP		loc_26CDA

; =============== S U B	R O U T	I N E =======================================
_demo04:
		LDY		#$3F
		LDA		#$00
loc_26D4F:
		STA		byte_3C0,Y
		DEY
		BPL		loc_26D4F
		LDY		#$01
		STY		byte_570
		LDY		#$03
		STY		byte_55
		JSR		sub_277ED
		LDA		#$3C
		JSR		_wait_for_nmi
		LDA		#$03
		STA		byte_4D
loc_26D6A:
		LDY		byte_4D
		LDA		byte_65D5,Y
		STA		_timer_minutes
		LDA		byte_65D1,Y
		STA		_tmp4Bb
		JSR		sub_65D9
		DEC		byte_4D
		BPL		loc_26D6A
		LDY		#$04
		STY		byte_55
		JSR		sub_277ED
		INC		_demo_sub_idx
		LDA		#$3C
		JMP		_wait_for_nmi

; =============== S U B	R O U T	I N E =======================================
_demo05:
		LDY		#$05
		STY		byte_55
		JSR		sub_277ED
		LDA		#$3C
		JSR		_wait_for_nmi
		LDA		#$00
		JSR		sub_26E01
		LDA		#$01
		JSR		sub_26E01
		LDA		#$02
		JSR		sub_26E01
		JSR		_spr_clear
		LDY		#$06
		STY		byte_55
		JSR		sub_277ED
		LDA		#$3C
		JSR		_wait_for_nmi
		LDA		#$03
		JSR		sub_26E01
		LDA		#$04
		JSR		sub_26E01
		LDA		#$05
		JSR		sub_26E01
		JSR		_spr_clear
		LDY		#$07
		STY		byte_55
		JSR		sub_277ED
		LDA		#$3C
		JSR		_wait_for_nmi
		JSR		sub_26EC6
		INC		_demo_sub_idx
		LDY		#$0A
loc_26DDC:
		LDA		_tlm_96A6,Y
		STA		_nmi_tlmB1_ram,Y
		DEY
		BPL		loc_26DDC
		LDA		#$01
		STA		byte_32
		JSR		_sync
		LDA		#$00
		STA		byte_567
		LDA		#$14
		STA		_ingame_sub_idx
		LDA		#$04
		STA		_main02_sub_idx
		LDA		#$06
		STA		byte_55C
		JMP		_main_subC

; =============== S U B	R O U T	I N E =======================================
sub_26E01:
		ASL
		STA		byte_57
		ASL
		CLC
		ADC		byte_57
		TAY
		LDA		byte_26E2A,Y
		STA		byte_534
		LDA		byte_26E2A+1,Y
		STA		byte_535
		LDA		byte_26E2A+2,Y
		STA		byte_537
		LDA		byte_26E2A+3,Y
		STA		byte_536
		LDA		byte_26E2A+4,Y
		LDX		byte_26E2A+5,Y
		JMP		loc_26E4E
; ---------------------------------------------------------------------------
byte_26E2A:
		.BYTE $38,$D0,$FE,$00,$00,$60
		.BYTE $38,$10,$00,$02,$03,$40
		.BYTE $B8,$10,$02,$00,$01,$60
		.BYTE $B8,$D0,$FE,$00,$00,$60
		.BYTE $B8,$10,$00,$FE,$02,$40
		.BYTE $38,$10,$02,$00,$01,$60
; ---------------------------------------------------------------------------
loc_26E4E:
		STA		_tmp4Bb
		STX		_timer_minutes
loc_26E52:
		LDA		_tmp4Bb
		JSR		sub_26E73
		JSR		_sync
		LDA		byte_534
		CLC
		ADC		byte_536
		STA		byte_534
		LDA		byte_535
		CLC
		ADC		byte_537
		STA		byte_535
		DEC		_timer_minutes
		BNE		loc_26E52
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_26E73:
		ASL
		ASL
		ASL
		TAY
		LDX		#$00
loc_26E79:
		LDA		byte_26EA6,Y
		CLC
		ADC		byte_534
		STA		_spr_buf,X
		INY
		INX
		LDA		byte_26EA6,Y
		STA		_spr_buf,X
		INY
		INX
		LDA		byte_26EA6,Y
		STA		_spr_buf,X
		INY
		INX
		LDA		byte_26EA6,Y
		CLC
		ADC		byte_535
		STA		_spr_buf,X
		INY
		INX
		CPX		#$08
		BNE		loc_26E79
		RTS
; ---------------------------------------------------------------------------
byte_26EA6:
		.BYTE $00,$F6,$40,$00
		.BYTE $00,$F4,$40,$08
		.BYTE $00,$F4,$00,$00
		.BYTE $00,$F6,$00,$08
		.BYTE $00,$F8,$00,$00
		.BYTE $00,$F8,$40,$08
		.BYTE $00,$F8,$80,$00
		.BYTE $00,$F8,$C0,$08

; =============== S U B	R O U T	I N E =======================================
sub_26EC6:
		LDY		#$00
		STY		byte_575
		JSR		sub_2776F
		JSR		_sync
		JSR		sub_2776F
		JMP		_sync

; =============== S U B	R O U T	I N E =======================================
sub_26ED7:
		LDA		byte_32
		ORA		_ppu_queue_req
		ORA		_nmi_tlm_lib_idx
		ORA		byte_62
		ORA		byte_577
		BEQ		loc_26EE6
locret_26EE5:
		RTS
; ---------------------------------------------------------------------------
loc_26EE6:
		LDA		byte_55D
		BEQ		locret_26EE5
		AND		#$7F
		TAY
		DEY
		LDA		off_26F0D,Y
		STA		_tmp20w+1
		LDA		off_26F19,Y
		STA		_tmp20w
		LDX		#$0F
		LDY		#$00
		LDA		byte_55D
		BPL		loc_26F06
		LDX		#$0E
		LDY		#$20
loc_26F06:
		STX		word_10
		STY		word_10+1
		JMP		loc_26FCD
; ---------------------------------------------------------------------------
off_26F0D:
		.BYTE >[byte_26F25]
		.BYTE >[byte_26F33]
		.BYTE >[byte_26F41]
		.BYTE >[byte_26F4F]
		.BYTE >[byte_26F5D]
		.BYTE >[byte_26F6B]
		.BYTE >[byte_26F79]
		.BYTE >[byte_26F87]
		.BYTE >[byte_26F95]
		.BYTE >[byte_26FA3]
		.BYTE >[byte_26FB1]
		.BYTE >[byte_26FBF]
off_26F19:
		.BYTE <[byte_26F25]
		.BYTE <[byte_26F33]
		.BYTE <[byte_26F41]
		.BYTE <[byte_26F4F]
		.BYTE <[byte_26F5D]
		.BYTE <[byte_26F6B]
		.BYTE <[byte_26F79]
		.BYTE <[byte_26F87]
		.BYTE <[byte_26F95]
		.BYTE <[byte_26FA3]
		.BYTE <[byte_26FB1]
		.BYTE <[byte_26FBF]
byte_26F25:
		.BYTE $83,$83,$87,$83,$87,$83,$83,$02,$02,$02,$02,$82,$02,$02
byte_26F33:
		.BYTE $83,$80,$8C,$87,$8F,$8C,$86,$82,$C2,$C2,$82,$C2,$02,$02
byte_26F41:
		.BYTE $87,$80,$8C,$87,$87,$8C,$80,$82,$C2,$C2,$82,$82,$C2,$C2
byte_26F4F:
		.BYTE $89,$85,$83,$81,$83,$81,$8F,$82,$82,$82,$82,$C2,$82,$C2
byte_26F5D:
		.BYTE $8F,$8C,$8C,$8F,$87,$8C,$80,$82,$02,$02,$C2,$82,$C2,$C2
byte_26F6B:
		.BYTE $8F,$8C,$8C,$87,$87,$8C,$8C,$82,$02,$C2,$82,$82,$C2,$C2
byte_26F79:
		.BYTE $81,$80,$8C,$8F,$87,$83,$83,$C2,$C2,$C2,$C2,$82,$02,$02
byte_26F87:
		.BYTE $87,$8C,$8C,$87,$87,$8C,$8C,$82,$C2,$C2,$82,$82,$C2,$C2
byte_26F95:
		.BYTE $87,$8C,$8C,$87,$87,$8C,$80,$C2,$C2,$C2,$82,$82,$C2,$C2
byte_26FA3:
		.BYTE $8D,$8D,$9D,$8C,$9E,$8D,$8D,$B2,$B2,$B2,$E2,$E2,$B2,$B2
byte_26FB1:
		.BYTE $8C,$8C,$9C,$8C,$9E,$8C,$8C,$62,$62,$E2,$62,$F2,$62,$62
byte_26FBF:
		.BYTE $8C,$8C,$9D,$8C,$9F,$8D,$8C,$62,$32,$B2,$E2,$F2,$82,$C2
; ---------------------------------------------------------------------------
loc_26FCD:
		LDX		#$00
		STX		byte_57
loc_26FD1:
		LDY		byte_57
		CPY		#$04
		BEQ		locret_26FFD
		LDA		word_10
		STA		_tmp1Cw+1
		LDA		word_10+1
		CLC
		ADC		byte_26FFE,Y
		STA		_tmp1Cw
		LDA		byte_27002,Y
		TAY
		JSR		sub_A11B
		LDY		byte_57
		LDA		_tmp20w
		CLC
		ADC		byte_27002,Y
		BCC		loc_26FF6
		INC		_tmp20w+1
loc_26FF6:
		STA		_tmp20w
		INC		byte_57
		JMP		loc_26FD1
; ---------------------------------------------------------------------------
locret_26FFD:
		RTS
; ---------------------------------------------------------------------------
byte_26FFE:
		.BYTE $04,$10,$24,$30
byte_27002:
		.BYTE $04,$03,$04,$03

; =============== S U B	R O U T	I N E =======================================
_demo07:
		LDY		#$01
		JSR		_pal_fade_outB
		LDA		#$01
		STA		_nmi_disable_flush
		JSR		sub_270D8
		JSR		sub_270B6
		LDY		#$00
		STY		_nmi_disable_flush
		STY		byte_31E
		INY
		STY		byte_31D
		INY
		STY		byte_55C
		STY		byte_5D
		JSR		_main_subC
		JSR		_sync
		JSR		sub_8E47
		LDY		#$01
		JSR		_pal_fade_outA
		LDY		#$00
		STY		byte_570
		LDY		#$16
		STY		byte_56A
		LDY		#$28
		STY		byte_55
		JSR		sub_277FB
		LDY		#$29
		STY		byte_55
		JSR		sub_277ED
		LDA		#$78
		JSR		_wait_for_nmi
		INC		_demo_sub_idx
		LDY		#$01
		JMP		_pal_fade_outB

; =============== S U B	R O U T	I N E =======================================
_demo08:
		LDY		#$01
		STY		_nmi_disable_flush
		STY		_byte_270E4_w+$25
		DEY
		STY		_byte_270E4_w+$2C
		JSR		sub_270D8
		JSR		sub_270B6
		LDY		#$00
		STY		_nmi_disable_flush
		STY		byte_31E
		STY		byte_31D
		LDA		#$03
		STA		byte_55C
		STA		byte_5D
		JSR		_main_subC
		JSR		_sync
		JSR		sub_8E47
		LDY		#$01
		JSR		_pal_fade_outA
		LDY		#$00
		STY		byte_570
		LDY		#$17
		STY		byte_56A
		LDY		#$2A
		STY		byte_55
		JSR		sub_277FB
		LDY		#$2B
		STY		byte_55
		JSR		sub_277ED
		LDA		#$64
		JSR		_wait_for_nmi
		JSR		_apu_play_ctrlA_set04
		LDA		#$78
		JSR		_wait_for_nmi
		LDY		#$01
		JSR		_pal_fade_outB
		JMP		sub_A5D6

; =============== S U B	R O U T	I N E =======================================
sub_270B6:
		JSR		_spr_clear
		JSR		sub_9AA9
		LDX		#<[_tlm_95FA]
		LDY		#>[_tlm_95FA]
		JSR		_ppu_tlm_unpack
		JSR		sub_96C5
		LDA		#$00
loc_270C8:
		PHA
		JSR		sub_77DA
		JSR		_nmi_ppu_dequeue
		PLA
		CLC
		ADC		#$01
		CMP		#$1A
		BNE		loc_270C8
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_270D8:
		LDY		#$39
loc_270DA:
		LDA		_byte_270E4_w,Y
		STA		byte_3C0,Y
		DEY
		BPL		loc_270DA
		RTS
; ---------------------------------------------------------------------------
_byte_270E4_w:
		.BYTE $00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
		.BYTE $00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
		.BYTE $00,$0F,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
		.BYTE $00,$00,$00,$00,$00,$00,$00,$00,$01,$00,$00,$01
		.BYTE $00,$00,$02,$03,$02,$02,$02,$02,$00,$00

; =============== S U B	R O U T	I N E =======================================
_demo06:
		LDA		_main02_sub_idx
		CMP		#$04
		BNE		loc_27127
		JSR		sub_27144
loc_27127:
		LDA		byte_566
		BNE		loc_27136
		LDA		_main02_sub_idx
		CMP		#$05
		BCS		loc_2713C
		JSR		_main02_game
		RTS
; ---------------------------------------------------------------------------
loc_27136:
		JSR		sub_27282
		JMP		_demo
; ---------------------------------------------------------------------------
loc_2713C:
		INC		_demo_sub_idx
		LDA		#$78
		JMP		_wait_for_nmi

; =============== S U B	R O U T	I N E =======================================
sub_27144:
		LDA		byte_567
		JSR		_switch
; ---------------------------------------------------------------------------
		.WORD sub_2714E
		.WORD sub_27178

; =============== S U B	R O U T	I N E =======================================
sub_2714E:
		LDY		#$FF
		STY		byte_56D
		INY
		STY		byte_563
		STY		byte_566
		INY
		STY		_1p_cpu_ctrl_flag
		STY		_2p_cpu_ctrl_flag
		INY
		STY		_2p_first_dice_roll_override
		LDA		#$04
		STA		_1p_first_dice_roll_override
		LDA		#<[byte_272A7]
		STA		byte_4F
		LDA		#>[byte_272A7]
		STA		byte_50
		LDA		#$07
		STA		byte_55
		INC		byte_567
locret_27177:
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_27178:
		LDA		byte_56D
		CMP		#$FF
		BEQ		loc_27183
		CMP		_ingame_sub_idx
		BNE		locret_27177
loc_27183:
		LDY		#$00
		LDA		(byte_4F),Y
		STA		byte_57
		AND		#$C0
		LSR
		LSR
		LSR
		LSR
		LSR
		LSR
		JSR		_switch
; ---------------------------------------------------------------------------
		.WORD sub_2719A
		.WORD sub_271FB
		.WORD sub_27222

; =============== S U B	R O U T	I N E =======================================
sub_2719A:
		LDY		#$01
		LDA		byte_57
		AND		#$08
		BNE		sub_271F5
		LDA		_ingame_sub_idx
		CMP		#$05
		BEQ		loc_271AD
		LDY		#$00
		JMP		sub_27211
; ---------------------------------------------------------------------------
loc_271AD:
		JSR		sub_271E9
		LDA		byte_57
		AND		#$04
		BNE		loc_271D4
		LDA		byte_57
		AND		#$03
		STA		byte_5A1
		INC		byte_5A1
		LDX		#$00
loc_271C2:
		JSR		sub_271D7
		LDA		byte_58
		STA		byte_9E,X
		LDA		byte_5A0
		STA		byte_A2,X
		INX
		CPX		byte_5A1
		BNE		loc_271C2
loc_271D4:
		JMP		sub_27211

; =============== S U B	R O U T	I N E =======================================
sub_271D7:
		LDA		(byte_4F),Y
		INY
		PHA
		LSR
		LSR
		LSR
		LSR
		LSR
		STA		byte_58
		PLA
		AND		#$1F
		STA		byte_5A0
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_271E9:
		LDX		#$03
		LDA		#$FF
loc_271ED:
		STA		byte_9E,X
		STA		byte_A2,X
		DEX
		BPL		loc_271ED
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_271F5:
		STY		byte_569
		JMP		sub_27211

; =============== S U B	R O U T	I N E =======================================
sub_271FB:
		LDY		#$01
		LDA		byte_57
		AND		#$07
		STA		_1p_first_dice_roll_override
		LDA		byte_57
		AND		#$38
		LSR
		LSR
		LSR
		STA		_2p_first_dice_roll_override
		JMP		sub_27211

; =============== S U B	R O U T	I N E =======================================
sub_27211:
		LDA		(byte_4F),Y
		STA		byte_56D
		INY
		TYA
		CLC
		ADC		byte_4F
		STA		byte_4F
		BCC		locret_27221
		INC		byte_50
locret_27221:
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_27222:
		LDY		#$01
		LDA		(byte_4F),Y
		CMP		#$FF
		BNE		loc_27230
		LDA		#$01
		STA		byte_563
		RTS
; ---------------------------------------------------------------------------
loc_27230:
		CMP		#$FE
		BNE		loc_27238
		INY
		JMP		sub_27211
; ---------------------------------------------------------------------------
loc_27238:
		TAX
		LDA		off_27246,X
		STA		word_10
		LDA		off_27248,X
		STA		word_10+1
		JMP		(word_10)
; ---------------------------------------------------------------------------
off_27246:
		.BYTE <[sub_2724A]
		.BYTE <[sub_2725F]
off_27248:
		.BYTE >[sub_2724A]
		.BYTE >[sub_2725F]

; =============== S U B	R O U T	I N E =======================================
sub_2724A:
		LDX		#$00
		STX		byte_565
		INX
		STX		byte_566
		INC		byte_55
		INY
		LDA		(byte_4F),Y
		STA		byte_570
		INY
		JMP		sub_27211

; =============== S U B	R O U T	I N E =======================================
sub_2725F:
		LDX		#$00
		STX		byte_551
		STX		byte_565
		STX		byte_556
		INX
		STX		_tmp4Bb
		STX		byte_566
		INC		byte_55
		INY
		LDA		(byte_4F),Y
		STA		byte_570
		INY
		LDA		(byte_4F),Y
		STA		byte_56A
		INY
		JMP		sub_27211

; =============== S U B	R O U T	I N E =======================================
sub_27282:
		JSR		sub_27485
		JSR		sub_2808B
		JSR		_sync
		LDA		byte_566
		BNE		sub_27282
		LDY		#$00
		STY		byte_56A
		JMP		sub_27298

; =============== S U B	R O U T	I N E =======================================
sub_27298:
		LDY		#$1F
		LDA		#$F4
loc_2729C:
		STA		_spr_buf+$50,Y
		DEY
		BPL		loc_2729C
		INY
		RTS

; =============== S U B	R O U T	I N E =======================================
_dummy:
		LDA		#$00
		RTS
; ---------------------------------------------------------------------------
byte_272A7:
		.BYTE $80,$00,$00,$05,$80,$00,$00,$05,$01,$91,$53,$06,$80,$01,$00,$0C
		.BYTE $0A,$80,$FE,$06,$80,$01,$00,$0D,$0C,$80,$01,$00,$01,$00,$6A,$01
		.BYTE $80,$00,$01,$05,$01,$AC,$4C,$06,$80,$01,$01,$0E,$0A,$80,$FE,$06
		.BYTE $80,$01,$01,$0E,$00,$66,$05,$01,$C1,$87,$06,$80,$01,$00,$02,$0C
		.BYTE $80,$01,$00,$0B,$00,$61,$05,$01,$20,$8C,$06,$80,$01,$01,$0B,$06
		.BYTE $80,$01,$01,$10,$06,$80,$01,$01,$03,$06,$80,$01,$01,$04,$00,$49
		.BYTE $05,$03,$33,$33,$31,$31,$06,$80,$00,$00,$00,$59,$05,$01,$71,$33
		.BYTE $0C,$08,$0D,$80,$01,$00,$0A,$10,$80,$00,$00,$00,$73,$01,$80,$00
		.BYTE $00,$05,$01,$61,$CB,$00,$52,$05,$03,$53,$53,$41,$41,$00,$74,$05
		.BYTE $80,$01,$00,$05,$05,$04,$00,$6A,$05,$01,$41,$A3,$0A,$69,$05,$00
		.BYTE $20,$0A,$80,$01,$00,$13,$00,$49,$05,$03,$31,$31,$30,$28,$00,$71
		.BYTE $05,$01,$20,$CC,$00,$76,$05,$03,$D1,$D1,$C3,$C3,$00,$75,$05,$01
		.BYTE $AC,$CC,$00,$6E,$05,$01,$C9,$AF,$00,$65,$05,$01,$92,$B1,$00,$75
		.BYTE $05,$01,$A9,$C9,$00,$4B,$05,$01,$32,$73,$00,$4E,$05,$01,$CE,$34
		.BYTE $00,$49,$05,$03,$32,$32,$33,$36,$00,$6D,$05,$03,$AC,$AC,$B1,$B1
		.BYTE $00,$80,$01,$01,$06,$00,$6C,$05,$01,$93,$AC,$00,$6A,$05,$01,$4F
		.BYTE $B1,$00,$63,$05,$01,$71,$94,$00,$5B,$05,$03,$72,$72,$76,$74,$0A
		.BYTE $80,$FE,$0A,$80,$FE,$07,$80,$01,$01,$11,$07,$80,$01,$01,$12,$08
		.BYTE $80,$FE,$07,$80,$00,$01,$00,$5A,$05,$01,$4C,$74,$0A,$6E,$05,$01
		.BYTE $D3,$B4,$08,$80,$FE,$07,$80,$01,$01,$15,$07,$80,$01,$01,$14,$00
		.BYTE $5D,$05,$01,$A1,$6E,$0A,$80,$00,$00,$00,$5E,$05,$04,$00,$76,$05
		.BYTE $03,$C1,$C6,$CC,$D2,$0B,$80,$01,$00,$08,$00,$80,$00,$00,$00,$75
		.BYTE $05,$01,$A7,$D1,$00,$5C,$05,$01,$8C,$70,$00,$4E,$05,$01,$D3,$37
		.BYTE $00,$5E,$05,$01,$D3,$73,$00,$6A,$05,$04,$00,$64,$05,$03,$94,$94
		.BYTE $95,$95,$00,$66,$05,$01,$C0,$86,$00,$72,$05,$01,$57,$D6,$0A,$80
		.BYTE $01,$00,$09,$00,$4E,$05,$01,$CA,$30,$00,$61,$05,$01,$38,$96,$00
		.BYTE $6E,$05,$01,$D1,$B4,$00,$51,$05,$01,$38,$57,$00,$64,$05,$03,$95
		.BYTE $95,$95,$95,$00,$61,$05,$01,$38,$96,$00,$73,$05,$01,$76,$D5,$00
		.BYTE $5D,$05,$01,$B7,$78,$00,$52,$05,$03,$57,$57,$57,$57,$00,$6A,$05
		.BYTE $00,$58,$12,$80,$00,$00,$12,$80,$01,$00,$0F,$12,$80,$FF

; =============== S U B	R O U T	I N E =======================================
sub_27485:
		LDA		byte_565
		JSR		_switch
; ---------------------------------------------------------------------------
		.WORD sub_27495
		.WORD sub_27574
		.WORD sub_2767A
		.WORD sub_27762
		.WORD sub_2776F

; =============== S U B	R O U T	I N E =======================================
sub_27495:
		LDA		byte_32
		ORA		_ppu_queue_req
		ORA		_nmi_tlm_lib_idx
		BEQ		loc_2749F
		RTS
; ---------------------------------------------------------------------------
loc_2749F:
		LDY		#$21
		LDX		#$82
		LDA		byte_570
		BEQ		loc_274AC
		LDY		#$21
		LDX		#$90
loc_274AC:
		STY		byte_107
		STY		_tmp51w+1
		STX		byte_106
		TXA
		CLC
		ADC		#$41
		STA		_tmp51w
		LDA		byte_55
		TAY
		LDA		_msg_lib_lo,Y
		STA		_tmp53w
		LDA		_msg_lib_hi,Y
		STA		_tmp53w+1
		LDA		#$00
		JSR		sub_94C6
		LDA		#$01
		STA		byte_105
		LDA		#$3B
		STA		byte_104
		JSR		sub_945E
		JSR		sub_9473
		JSR		sub_9488
		LDX		#$03
		JSR		sub_9433
		JSR		_sync
		JSR		sub_945E
		JSR		sub_9473
		JSR		sub_9488
		LDX		#$03
		JSR		sub_9433
		JSR		_sync
		JSR		sub_945E
		JSR		sub_9473
		LDY		#$FF
		STY		byte_577
		LDX		#$02
		JSR		sub_9433
		JSR		_sync
		LDY		#$00
		STY		byte_572
		INY
		STY		_nmi_counter
		LDA		#$19
		STA		byte_571
		INC		byte_565
		RTS
; ---------------------------------------------------------------------------
_msg_lib_lo:
		.BYTE <[_msg00]
		.BYTE <[_msg01]
		.BYTE <[_msg02]
		.BYTE <[_msg03]
		.BYTE <[_msg04]
		.BYTE <[_msg05]
		.BYTE <[_msg06]
		.BYTE <[_msg07]
		.BYTE <[_msg08]
		.BYTE <[_msg09]
		.BYTE <[_msg0A]
		.BYTE <[_msg0B]
		.BYTE <[_msg0C]
		.BYTE <[_msg0D]
		.BYTE <[_msg0E]
		.BYTE <[_msg0F]
		.BYTE <[_msg10]
		.BYTE <[_msg11]
		.BYTE <[_msg12]
		.BYTE <[_msg13]
		.BYTE <[_msg14]
		.BYTE <[_msg15]
		.BYTE <[_msg16]
		.BYTE <[_msg17]
		.BYTE <[_msg18]
		.BYTE <[_msg19]
		.BYTE <[_msg1A]
		.BYTE <[_msg1B]
		.BYTE <[_msg1C]
		.BYTE <[_msg1D]
		.BYTE <[_msg1E]
		.BYTE <[_msg1F]
		.BYTE <[_msg20]
		.BYTE <[_msg21]
		.BYTE <[_msg22]
		.BYTE <[_msg23]
		.BYTE <[_msg24]
		.BYTE <[_msg25]
		.BYTE <[_msg26]
		.BYTE <[_msg27]
		.BYTE <[_msg28]
		.BYTE <[_msg29]
		.BYTE <[_msg2A]
		.BYTE <[_msg2B]
_msg_lib_hi:
		.BYTE >[_msg00]
		.BYTE >[_msg01]
		.BYTE >[_msg02]
		.BYTE >[_msg03]
		.BYTE >[_msg04]
		.BYTE >[_msg05]
		.BYTE >[_msg06]
		.BYTE >[_msg07]
		.BYTE >[_msg08]
		.BYTE >[_msg09]
		.BYTE >[_msg0A]
		.BYTE >[_msg0B]
		.BYTE >[_msg0C]
		.BYTE >[_msg0D]
		.BYTE >[_msg0E]
		.BYTE >[_msg0F]
		.BYTE >[_msg10]
		.BYTE >[_msg11]
		.BYTE >[_msg12]
		.BYTE >[_msg13]
		.BYTE >[_msg14]
		.BYTE >[_msg15]
		.BYTE >[_msg16]
		.BYTE >[_msg17]
		.BYTE >[_msg18]
		.BYTE >[_msg19]
		.BYTE >[_msg1A]
		.BYTE >[_msg1B]
		.BYTE >[_msg1C]
		.BYTE >[_msg1D]
		.BYTE >[_msg1E]
		.BYTE >[_msg1F]
		.BYTE >[_msg20]
		.BYTE >[_msg21]
		.BYTE >[_msg22]
		.BYTE >[_msg23]
		.BYTE >[_msg24]
		.BYTE >[_msg25]
		.BYTE >[_msg26]
		.BYTE >[_msg27]
		.BYTE >[_msg28]
		.BYTE >[_msg29]
		.BYTE >[_msg2A]
		.BYTE >[_msg2B]

; =============== S U B	R O U T	I N E =======================================
sub_27574:
		LDA		_nmi_counter
		BNE		locret_27581
		LDA		byte_32
		ORA		_ppu_queue_req
		ORA		_nmi_tlm_lib_idx
		BEQ		loc_27582
locret_27581:
		RTS
; ---------------------------------------------------------------------------
loc_27582:
		LDA		_tmp51w+1
		STA		_nmi_tlmB2_ram
		LDA		_tmp51w
		STA		byte_10C
		LDA		#$01
		STA		byte_10D
		LDA		#$01
		STA		byte_111
		LDA		#$FF
		STA		byte_10F
		LDY		#$00
		LDA		(_tmp53w),Y
		CMP		#$10
		BNE		loc_275B1
		LDA		#$00
		STA		byte_575
		LDA		#$03
		STA		byte_565
		STA		byte_56B
		RTS
; ---------------------------------------------------------------------------
loc_275B1:
		LDY		#$CA
		CMP		#$0F
		BEQ		loc_275BD
		LDY		#$C9
		CMP		#$0E
		BNE		loc_27600
loc_275BD:
		STY		byte_58
		LDA		_tmp53w
		CLC
		ADC		#$01
		STA		_tmp53w
		STA		_tmp20w
		BCC		loc_275CC
		INC		_tmp53w+1
loc_275CC:
		LDA		_tmp53w+1
		STA		_tmp20w+1
		LDY		#$00
		LDA		(_tmp53w),Y
		STA		byte_57
		LDA		#$FF
		STA		byte_113
		LDA		_tmp51w+1
		STA		byte_10F
		LDA		_tmp51w
		SEC
		SBC		#$20
		STA		byte_110
		BCS		loc_275ED
		DEC		byte_10F
loc_275ED:
		LDA		byte_58
		STA		byte_112
		LDA		byte_571
		SEC
		SBC		#$0C
		TAY
		LDA		byte_58
		STA		byte_13B,Y
		LDA		byte_57
loc_27600:
		STA		byte_10E
		LDY		byte_571
		STA		byte_13B,Y
		LDA		#$02
		STA		byte_32
		LDA		_tmp53w
		CLC
		ADC		#$01
		STA		_tmp53w
		BCC		loc_27618
		INC		_tmp53w+1
loc_27618:
		LDA		_tmp51w
		CLC
		ADC		#$01
		STA		_tmp51w
		BCC		loc_27623
		INC		_tmp51w+1
loc_27623:
		INC		byte_571
		INC		byte_572
		LDA		byte_572
		CMP		#$0A
		BNE		loc_27675
		LDA		#$00
		STA		byte_572
		LDA		byte_571
		CLC
		ADC		#$0E
		CMP		#$55
		BCC		loc_27667
		LDA		_tmp51w
		SEC
		SBC		#$0A
		STA		_tmp51w
		BCS		loc_2764A
		DEC		_tmp51w+1
loc_2764A:
		LDA		byte_571
		SEC
		SBC		#$0A
		STA		byte_571
		LDA		#$1E
		STA		_nmi_counter
		LDY		#$00
		STY		byte_573
		STY		byte_574
		INY
		STY		byte_56B
		INC		byte_565
		RTS
; ---------------------------------------------------------------------------
loc_27667:
		STA		byte_571
		LDA		_tmp51w
		CLC
		ADC		#$36
		STA		_tmp51w
		BCC		loc_27675
		INC		_tmp51w+1
loc_27675:
		LDA		#$08
		STA		_nmi_counter
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_2767A:
		LDA		byte_574
		BNE		loc_2769A
		INC		byte_574
		LDA		#$01
		STA		_tmp1Cw+1
		LDA		#$54
		STA		_tmp1Cw
		LDY		#$21
		LDX		#$A3
		LDA		byte_570
		BEQ		loc_276B4
		LDY		#$21
		LDX		#$B1
		JMP		loc_276B4
; ---------------------------------------------------------------------------
loc_2769A:
		LDA		#$00
		STA		byte_574
		LDA		#$01
		STA		_tmp1Cw+1
		LDA		#$78
		STA		_tmp1Cw
		LDY		#$22
		LDX		#$03
		LDA		byte_570
		BEQ		loc_276B4
		LDY		#$22
		LDX		#$11
loc_276B4:
		STY		_nmi_tlmB2_ram
		STY		byte_118
		STY		byte_125
		STX		byte_10C
		TXA
		CLC
		ADC		#$20
		STA		byte_119
		BCC		loc_276CC
		INC		byte_118
loc_276CC:
		CLC
		ADC		#$20
		STA		byte_126
		BCC		loc_276D7
		INC		byte_125
loc_276D7:
		LDA		#$0A
		STA		byte_10D
		STA		byte_11A
		STA		byte_127
		LDA		#$FF
		STA		byte_132
		LDY		#$09
loc_276E9:
		LDA		(_tmp1Cw),Y
		STA		byte_10E,Y
		DEY
		BPL		loc_276E9
		LDA		_tmp1Cw
		CLC
		ADC		#$0C
		STA		_tmp1Cw
		BCC		loc_276FC
		INC		_tmp1Cw+1
loc_276FC:
		LDY		#$09
loc_276FE:
		LDA		(_tmp1Cw),Y
		STA		byte_11B,Y
		DEY
		BPL		loc_276FE
		LDA		_tmp1Cw
		CLC
		ADC		#$0C
		STA		_tmp1Cw
		BCC		loc_27711
		INC		_tmp1Cw+1
loc_27711:
		LDY		#$09
loc_27713:
		LDA		(_tmp1Cw),Y
		LDX		byte_574
		BNE		loc_2771C
		LDA		#$2E
loc_2771C:
		STA		byte_128,Y
		DEY
		BPL		loc_27713
		LDA		_tmp1Cw
		CLC
		ADC		#$0C
		STA		_tmp1Cw
		BCC		loc_2772D
		INC		_tmp1Cw+1
loc_2772D:
		LDA		#$02
		STA		byte_32
		LDA		byte_574
		BNE		locret_27761
		LDA		byte_573
		EOR		#$01
		STA		byte_573
		LDY		#$00
loc_27740:
		LDA		byte_154,Y
		STA		byte_148,Y
		INY
		CPY		#$3A
		BNE		loc_27740
		LDY		#$09
		LDA		#$2E
loc_2774F:
		STA		byte_184,Y
		DEY
		BPL		loc_2774F
		LDA		#$08
		STA		_nmi_counter
		LDA		byte_573
		BNE		locret_27761
		DEC		byte_565
locret_27761:
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_27762:
		LDA		_nmi_counter
		BNE		locret_2776E
		DEC		byte_56B
		BNE		locret_2776E
		INC		byte_565
locret_2776E:
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_2776F:
		LDY		#$10
loc_27771:
		LDA		byte_277DC,Y
		STA		_nmi_tlmB2_ram,Y
		DEY
		BPL		loc_27771
		LDA		byte_575
		BNE		loc_27792
		INC		byte_575
		LDY		#$21
		LDA		#$82
		LDX		byte_570
		BEQ		loc_277A7
		LDY		#$21
		LDA		#$90
		JMP		loc_277A7
; ---------------------------------------------------------------------------
loc_27792:
		LDA		#$00
		STA		byte_566
		DEC		byte_575
		LDY		#$22
		LDA		#$02
		LDX		byte_570
		BEQ		loc_277A7
		LDY		#$22
		LDA		#$10
loc_277A7:
		STY		_nmi_tlmB2_ram
		STY		byte_10F
		STY		byte_113
		STY		byte_117
		STA		byte_10C
		CLC
		ADC		#$20
		STA		byte_110
		BCC		loc_277C1
		INC		byte_10F
loc_277C1:
		CLC
		ADC		#$20
		STA		byte_114
		BCC		loc_277CC
		INC		byte_113
loc_277CC:
		CLC
		ADC		#$20
		STA		byte_118
		BCC		loc_277D7
		INC		byte_117
loc_277D7:
		LDA		#$02
		STA		byte_32
		RTS
; ---------------------------------------------------------------------------
byte_277DC:
		.BYTE $00,$00,$4C,$2F,$00,$00,$4C,$2F,$00,$00,$4C,$2F,$00,$00,$4C,$2F
		.BYTE $FF

; =============== S U B	R O U T	I N E =======================================
sub_277ED:
		LDA		#$00
		STA		byte_565
loc_277F2:
		JSR		sub_27834
		JSR		_sync
		JMP		loc_277F2

; =============== S U B	R O U T	I N E =======================================
sub_277FB:
		LDY		#$00
		STY		_title_push_start_toggle
		STY		byte_565
		STY		byte_551
		STY		byte_556
		INY
		STY		_tmp4Bb
		STY		byte_566
		JSR		sub_27828
		LDA		#$B4
		STA		_nmi_counter
loc_27816:
		JSR		sub_2808B
		JSR		_sync
		LDA		_nmi_counter
		BNE		loc_27816
		LDY		#$00
		STY		byte_56A
		JMP		sub_27298

; =============== S U B	R O U T	I N E =======================================
sub_27828:
		JSR		sub_27834
		JSR		sub_2808B
		JSR		_sync
		JMP		sub_27828

; =============== S U B	R O U T	I N E =======================================
sub_27834:
		LDA		byte_565
		JSR		_switch
; ---------------------------------------------------------------------------
		.WORD sub_27495
		.WORD sub_27574
		.WORD sub_2767A
		.WORD sub_27842

; =============== S U B	R O U T	I N E =======================================
sub_27842:
		PLA
		PLA
		RTS
; ---------------------------------------------------------------------------
_msg00:
		.BYTE $2E,$EA,$0E,$DC,$F2,$E6,$C3,$0E,$B3,$B9,$BA,$0E,$E9,$C2,$F1,$CE
		.BYTE $E7,$0E,$B4,$D0,$B5,$0E,$EA,$FD,$E7,$E5,$EF,$D4,$FE,$C3,$DE,$E2
		.BYTE $F2,$D2,$DC,$EF,$DD,$C7,$10
_msg01:
		.BYTE $2E,$02,$04,$BD,$E7,$DB,$FD,$D6,$D8,$D9,$D2,$FE,$C3,$0F,$B1,$CC
		.BYTE $CE,$B2,$E4,$F6,$0E,$EB,$EF,$DD,$C7,$10
_msg02:
		.BYTE $2E,$D6,$D8,$0F,$B1,$CC,$CE,$B2,$EA,$C3,$01,$D6,$F7,$01,$02,$E7
		.BYTE $0E,$EA,$FD,$0E,$DA,$D3,$0E,$E3,$D1,$F7,$FC,$DC,$EF,$DD,$C7,$10
_msg03:
		.BYTE $2E,$0E,$B4,$D0,$B5,$E7,$EF,$D4,$E6,$C3,$D1,$D6,$C3,$DC,$FB,$C3
		.BYTE $DF,$FA,$0E,$DF,$FA,$E7,$BD,$BE,$FE,$C3,$01,$05,$BD,$C3,$0F,$B1
		.BYTE $CC,$CE,$B2,$E6,$E5,$F7,$0E,$ED,$EF,$DD,$C7,$10
_msg04:
		.BYTE $2E,$D1,$E5,$E0,$EA,$DC,$FB,$E7,$BD,$BE,$FE,$C3,$D1,$D2,$E3,$EA
		.BYTE $D1,$D6,$E7,$BD,$BE,$FE,$C3,$D3,$0E,$DA,$D6,$DC,$EF,$DD,$C7,$10
_msg05:
		.BYTE $2E,$DC,$FB,$E7,$BD,$BE,$EA,$C3,$DA,$E7,$EE,$D3,$DA,$D3,$E6,$DD
		.BYTE $DD,$F2,$EF,$DD,$10
_msg06:
		.BYTE $2E,$D1,$D6,$E7,$BD,$BE,$EA,$C3,$0E,$D7,$C4,$D8,$E7,$EE,$D3,$DA
		.BYTE $D3,$E6,$DD,$DD,$F2,$EF,$DD,$C7,$10
_msg07:
		.BYTE $2E,$DD,$0E,$ED,$E3,$E7,$BD,$BE,$FE,$C3,$0E,$DC,$0E,$EC,$FD,$E7
		.BYTE $CC,$CE,$CF,$D0,$0E,$B1,$D0,$0E,$B2,$E6,$D1,$E2,$F2,$E3,$C3,$EA
		.BYTE $F4,$D8,$D1,$0E,$D6,$F8,$E6,$DC,$E0,$EE,$D3,$0E,$D6,$C3,$D6,$E1
		.BYTE $0E,$E3,$DD,$C7,$10
_msg08:
		.BYTE $2E,$EF,$0E,$DD,$C3,$01,$E2,$0E,$DD,$E2,$0E,$B0,$CC,$B6,$FE,$EC
		.BYTE $F8,$EF,$DD,$C7,$10
_msg09:
		.BYTE $2E,$D5,$D5,$D7,$D2,$F2,$FE,$0E,$E0,$DC,$E0,$EB,$E4,$0E,$D6,$C3
		.BYTE $BD,$BE,$FE,$D3,$0E,$DA,$D6,$DC,$EF,$DD,$C7,$10
_msg0A:
		.BYTE $2E,$04,$E7,$F2,$0E,$E3,$C3,$DA,$E7,$BD,$BE,$FE,$D3,$0E,$DA,$D6
		.BYTE $DD,$DA,$E4,$E6,$DC,$EF,$DD,$C7,$10
_msg0B:
		.BYTE $2E,$02,$E7,$F2,$0E,$E3,$EA,$C3,$DA,$E7,$BD,$BE,$FE,$D3,$0E,$DA
		.BYTE $D6,$DD,$DA,$E4,$E6,$DC,$EF,$DD,$C7,$10
_msg0C:
		.BYTE $2E,$DA,$E7,$F6,$D3,$E6,$C3,$BD,$BE,$0E,$D6,$02,$BD,$D2,$0E,$DC
		.BYTE $C5,$D3,$D2,$F9,$0F,$B1,$CC,$CE,$B2,$FE,$C3,$0E,$B7,$B8,$B9,$BA
		.BYTE $0F,$B1,$CC,$CE,$B2,$E4,$D2,$D2,$EF,$DD,$C7,$2E,$2E,$2E,$0E,$B7
		.BYTE $B8,$B9,$BA,$0F,$B1,$CC,$CE,$B2,$E6,$EA,$C3,$D1,$D2,$E3,$E7,$BD
		.BYTE $BE,$EA,$C3,$DD,$DD,$F5,$DA,$E4,$0E,$D6,$0E,$E3,$D7,$EF,$DE,$FD
		.BYTE $C7,$10
_msg0D:
		.BYTE $2E,$02,$D6,$D2,$F2,$D6,$F7,$EA,$C3,$02,$BD,$E7,$0E,$B0,$CC,$B6
		.BYTE $FE,$EC,$F8,$EF,$DD,$10
_msg0E:
		.BYTE $2E,$05,$E7,$F2,$0E,$E3,$C3,$DA,$E7,$BD,$BE,$FE,$D3,$0E,$DA,$D6
		.BYTE $DD,$DA,$E4,$E6,$DC,$EF,$DD,$C7,$10
_msg0F:
		.BYTE $2E,$02,$E7,$F2,$0E,$E3,$EA,$C3,$DA,$E7,$BD,$BE,$FE,$D3,$0E,$DA
		.BYTE $D6,$DD,$DA,$E4,$E6,$DC,$EF,$DD,$C7,$10
_msg10:
		.BYTE $2E,$E3,$D7,$E7,$BD,$BE,$0E,$D6,$C3,$01,$BD,$DC,$D6,$E5,$D2,$0F
		.BYTE $B1,$CC,$CE,$B2,$E6,$C3,$0E,$DC,$0E,$EC,$FD,$E7,$BD,$BE,$0E,$D6
		.BYTE $DD,$DD,$F5,$E4,$C3,$E3,$D7,$E7,$BD,$BE,$FE,$C3,$EC,$F8,$0E,$E0
		.BYTE $DC,$E6,$F3,$0E,$E4,$DD,$DA,$E4,$0E,$D6,$0E,$E3,$D7,$EF,$DD,$C7
		.BYTE $2E,$2E,$2E,$2E,$2E,$2E,$DA,$FA,$FE,$C3,$BB,$B9,$B2,$E4,$D2,$D2
		.BYTE $EF,$DD,$C7,$10
_msg11:
		.BYTE $2E,$BB,$B9,$B2,$DB,$FA,$E0,$BD,$BE,$EA,$0E,$B3,$D0,$E6,$D5,$D6
		.BYTE $FA,$EF,$DD,$C7,$10
_msg12:
		.BYTE $2E,$0E,$B3,$D0,$E6,$BD,$BE,$0E,$D6,$D1,$F9,$0E,$EA,$D1,$D2,$EA
		.BYTE $C3,$EF,$0E,$DD,$C3,$0E,$B3,$D0,$E7,$BD,$BE,$FE,$D3,$0E,$DA,$D6
		.BYTE $DB,$E5,$D9,$FA,$0E,$EA,$E5,$F8,$EF,$DE,$FD,$C7,$10
_msg13:
		.BYTE $2E,$0E,$B3,$D0,$E7,$BD,$BE,$EA,$C3,$D1,$D2,$E3,$E7,$CC,$CE,$CF
		.BYTE $D0,$0E,$B1,$D0,$0E,$B2,$E7,$E5,$D6,$E6,$C3,$F3,$0E,$E4,$DC,$EF
		.BYTE $DD,$C7,$10
_msg14:
		.BYTE $2E,$04,$E7,$F2,$EA,$C3,$DC,$FB,$E7,$BD,$BE,$E6,$0E,$B7,$B8,$B9
		.BYTE $BA,$DB,$FA,$E3,$D2,$F9,$E7,$0E,$E3,$C3,$E2,$D6,$D4,$EF,$DE,$FD
		.BYTE $10
_msg15:
		.BYTE $2E,$DA,$DA,$EA,$C3,$01,$E7,$F2,$FE,$E2,$D6,$C6,$E3,$C3,$0E,$B3
		.BYTE $D0,$D6,$F7,$BD,$BE,$FE,$F3,$0E,$E4,$DC,$EF,$DD,$C7,$10
_msg16:
		.BYTE $2E,$02,$E2,$E7,$0E,$B0,$CC,$B6,$E7,$F2,$0E,$D6,$D5,$E5,$0E,$DC
		.BYTE $0E,$EA,$D1,$D2,$EA,$C3,$0E,$B0,$CC,$B6,$E7,$F2,$FE,$02,$0E,$EA
		.BYTE $D2,$E2,$D6,$D4,$EF,$DD,$C7,$2E,$2E,$2E,$2E,$2E,$2E,$2E,$2E,$DA
		.BYTE $E7,$0E,$EA,$D1,$D2,$EA,$C3,$01,$E7,$F2,$FE,$04,$D6,$D2,$D3,$0E
		.BYTE $DA,$D6,$DE,$EF,$DD,$C7,$10
_msg17:
		.BYTE $2E,$0E,$B0,$CC,$B6,$FE,$EC,$F9,$EF,$D4,$E6,$0E,$B0,$0E,$B7,$BF
		.BYTE $FE,$DE,$FD,$0E,$D9,$FD,$DC,$E3,$DF,$E7,$0E,$B4,$D0,$B5,$E7,$0F
		.BYTE $B1,$CC,$CE,$B2,$FE,$02,$0E,$EA,$D2,$E6,$DD,$F9,$DA,$E4,$0E,$D6
		.BYTE $0E,$E3,$D7,$EF,$DD,$C7,$2E,$2E,$2E,$2E,$2E,$2E,$DA,$E7,$0E,$EA
		.BYTE $D1,$D2,$C3,$0E,$B0,$0E,$B7,$F0,$CE,$0E,$BA,$E9,$FF,$D0,$0E,$B7
		.BYTE $E7,$02,$E7,$F2,$FD,$FE,$D3,$D4,$E6,$DC,$E3,$C3,$D1,$D2,$E3,$E6
		.BYTE $DB,$DC,$0E,$E0,$DC,$EF,$DD,$C7,$10
_msg18:
		.BYTE $2E,$0E,$B0,$0E,$B7,$BF,$FE,$D6,$D9,$F7,$FA,$E0,$EE,$D3,$EA,$C3
		.BYTE $D3,$D9,$F9,$D6,$C3,$D5,$F8,$F9,$D6,$FE,$C3,$DE,$FD,$E0,$D8,$0E
		.BYTE $E3,$D7,$EF,$DD,$C7,$10
_msg19:
		.BYTE $2E,$E2,$0E,$D7,$D6,$F7,$E7,$0E,$B0,$0E,$B7,$BF,$EA,$0E,$B0,$0E
		.BYTE $B7,$BF,$FE,$D3,$D9,$E0,$EB,$E4,$0E,$E0,$D9,$0E,$D6,$0E,$E3,$D7
		.BYTE $EF,$DD,$C7,$10
_msg1A:
		.BYTE $2E,$0E,$B3,$D0,$E7,$BD,$BE,$EA,$C3,$06,$E7,$F2,$0E,$E3,$F3,$C3
		.BYTE $04,$E7,$F2,$0E,$E3,$F3,$C3,$D3,$0E,$DA,$D6,$DD,$DA,$E4,$0E,$D6
		.BYTE $0E,$E3,$D7,$EF,$DE,$FD,$C7,$2E,$2E,$2E,$2E,$2E,$2E,$2E,$2E,$DC
		.BYTE $FB,$EA,$C3,$BD,$BE,$FE,$D3,$0E,$DA,$D6,$DD,$DA,$E4,$0E,$D6,$0E
		.BYTE $E3,$D7,$E5,$D2,$E7,$0E,$E3,$C3,$D1,$D6,$E7,$0E,$EA,$FD,$E6,$D3
		.BYTE $E2,$F8,$EF,$DD,$C7,$10
_msg1C:
		.BYTE $2E,$FA,$FD,$0E,$DF,$D8,$DC,$E0,$06,$BD,$E7,$0E,$B7,$B8,$B9,$BA
		.BYTE $FE,$C3,$0F,$B7,$C0,$CC,$B5,$E4,$D2,$D2,$EF,$DD,$C7,$2E,$2E,$2E
		.BYTE $2E,$2E,$0F,$B7,$C0,$CC,$B5,$FE,$E2,$D8,$F9,$E4,$D1,$D2,$E3,$E7
		.BYTE $BD,$BE,$0E,$D6,$C3,$0F,$B7,$C0,$CC,$B5,$FE,$DA,$D4,$E3,$C3,$E6
		.BYTE $0E,$D9,$0E,$E0,$DE,$E5,$D8,$E5,$F8,$EF,$DD,$C7,$10
_msg1D:
		.BYTE $2E,$DD,$0E,$ED,$E3,$E7,$BD,$BE,$0E,$D6,$C3,$0E,$DC,$0E,$EC,$FD
		.BYTE $E7,$CC,$CE,$CF,$D0,$0E,$B1,$D0,$0E,$B2,$E6,$EA,$D2,$F9,$E4,$C3
		.BYTE $BD,$BE,$FE,$D1,$0E,$D6,$F8,$E6,$DD,$F9,$DA,$E4,$0E,$D6,$0E,$E3
		.BYTE $D7,$EF,$DD,$C7,$10
_msg1E:
		.BYTE $2E,$0E,$B0,$CC,$B6,$E7,$F2,$E6,$C3,$D2,$C6,$E1,$DD,$F9,$0E,$EA
		.BYTE $FD,$0E,$DA,$D3,$E7,$0F,$B1,$CC,$CE,$B2,$E7,$BD,$BE,$FE,$C3,$D1
		.BYTE $0E,$D6,$F8,$E6,$DC,$EF,$DD,$C7,$10
_msg1F:
		.BYTE $2E,$BD,$BE,$FE,$D1,$0E,$D6,$F8,$E6,$0E,$E3,$D7,$E5,$D2,$0E,$EA
		.BYTE $D1,$D2,$F4,$C3,$BB,$B9,$B2,$DB,$FA,$F9,$E7,$FE,$DB,$D9,$F9,$E0
		.BYTE $F2,$E6,$C3,$D1,$0E,$D6,$F8,$E6,$DC,$E0,$D8,$E5,$D2,$E4,$D7,$EA
		.BYTE $C3,$DF,$E7,$F2,$E7,$D6,$0E,$DD,$0E,$E0,$D9,$DD,$DD,$F2,$EF,$DD
		.BYTE $C7,$10
_msg23:
		.BYTE $2E,$D1,$D2,$E3,$E7,$BD,$BE,$FE,$BB,$B9,$B2,$DC,$E3,$D2,$E3,$C3
		.BYTE $CC,$CE,$CF,$D0,$0E,$B1,$D0,$0E,$B2,$FE,$DD,$0E,$ED,$E3,$0E,$B7
		.BYTE $B8,$B9,$BA,$DC,$E0,$0E,$DC,$C5,$D3,$E0,$D2,$FE,$C3,$BA,$B8,$D0
		.BYTE $0E,$B6,$CB,$CD,$B2,$E4,$D2,$D2,$EF,$DD,$C7,$10
_msg24:
		.BYTE $2E,$BA,$B8,$D0,$0E,$B6,$CB,$CD,$B2,$DB,$FA,$E3,$D2,$F9,$E4,$D7
		.BYTE $EA,$C3,$0E,$B3,$D0,$E7,$BD,$BE,$EA,$C3,$D3,$0E,$DA,$D6,$DD,$DA
		.BYTE $E4,$0E,$D6,$0E,$E3,$D7,$E5,$D2,$E7,$0E,$E3,$C3,$0E,$B0,$CC,$B6
		.BYTE $FE,$EC,$FA,$E5,$D8,$E5,$F8,$EF,$DD,$10
_msg25:
		.BYTE $2E,$06,$E7,$0F,$B1,$CC,$CE,$B2,$E6,$EA,$BD,$BE,$0E,$D6,$E5,$D8
		.BYTE $C3,$DF,$E7,$D6,$0E,$DD,$0E,$E0,$D9,$DD,$DD,$F2,$F9,$DA,$E4,$F3
		.BYTE $0E,$E3,$D7,$E5,$D2,$E7,$0E,$E3,$C3,$F3,$C6,$E4,$F3,$D5,$D5,$D7
		.BYTE $D2,$0F,$B1,$CC,$CE,$B2,$E6,$D2,$F9,$BD,$BE,$FE,$D1,$0E,$D6,$F8
		.BYTE $E6,$DC,$EF,$DD,$10
_msg26:
		.BYTE $2E,$DC,$FB,$E7,$BD,$BE,$0E,$D6,$C3,$DD,$0E,$ED,$E3,$D1,$0E,$D6
		.BYTE $C6,$E0,$E7,$0E,$E3,$C3,$DC,$FB,$E7,$D6,$E1,$0E,$E3,$C3,$0E,$B4
		.BYTE $D0,$B5,$EA,$D5,$FC,$F8,$0E,$E3,$DD,$C7,$10
_msg27:
		.BYTE $2E,$0E,$B0,$0E,$B7,$F0,$CE,$0E,$BA,$E9,$FF,$D0,$0E,$B7,$E6,$DC
		.BYTE $F2,$DB,$FA,$E0,$DD,$D3,$0E,$DC,$E6,$F6,$F8,$C3,$DC,$FB,$0E,$D6
		.BYTE $C3,$02,$0F,$B1,$CC,$CE,$B2,$E4,$C6,$E0,$DA,$E4,$E6,$E5,$F8,$EF
		.BYTE $DD,$C7,$10
_msg1B:
		.BYTE $2E,$D1,$E4,$01,$BD,$E7,$BD,$BE,$0E,$D6,$C3,$0E,$B3,$D0,$D6,$F7
		.BYTE $D3,$0E,$DA,$D9,$E5,$D2,$E7,$0E,$E3,$C3,$EE,$D6,$E7,$BD,$BE,$F3
		.BYTE $D3,$0E,$DA,$D6,$DE,$EF,$DE,$FD,$C7,$10
_msg22:
		.BYTE $2E,$D1,$0E,$D6,$F8,$E7,$E4,$E1,$C8,$D3,$0E,$E3,$BD,$BE,$FE,$BB
		.BYTE $B9,$B2,$DB,$FA,$F9,$E4,$DF,$E7,$BD,$BE,$0E,$D6,$C3,$0E,$DC,$0E
		.BYTE $EC,$FD,$E7,$CC,$CE,$CF,$D0,$0E,$B1,$D0,$0E,$B2,$E6,$F3,$0E,$E4
		.BYTE $C6,$E3,$D8,$F9,$EF,$0E,$E3,$C3,$E7,$DA,$F8,$E7,$BD,$BE,$EA,$C3
		.BYTE $D1,$0E,$D6,$F8,$E6,$0E,$E3,$D7,$EF,$DE,$FD,$C7,$10
_msg20:
		.BYTE $2E,$BB,$B9,$B2,$DB,$FA,$E5,$D2,$F6,$D3,$E6,$C3,$05,$E7,$F2,$0E
		.BYTE $E3,$DA,$E7,$BD,$BE,$FE,$E6,$0E,$D6,$DC,$E0,$D2,$E7,$0E,$E3,$DD
		.BYTE $0E,$D6,$D1,$D2,$E3,$E6,$0E,$B7,$B8,$B9,$BA,$DB,$FA,$E3,$D2,$F9
		.BYTE $E7,$0E,$E3,$C3,$DD,$DD,$F2,$F9,$DA,$E4,$0E,$D6,$0E,$E3,$D7,$EF
		.BYTE $DE,$FD,$C7,$10
_msg21:
		.BYTE $2E,$05,$E7,$F2,$0E,$E3,$DA,$E7,$BD,$BE,$FE,$D1,$0E,$D6,$F8,$E6
		.BYTE $DC,$E5,$D9,$FA,$0E,$EA,$D2,$D9,$EF,$DE,$FD,$C7,$10
_msg28:
		.BYTE $2E,$0E,$DE,$FD,$0E,$EC,$E7,$BD,$BE,$FE,$D1,$0E,$D6,$F8,$E6,$DC
		.BYTE $E0,$E4,$D7,$C3,$D1,$D2,$E3,$0E,$D6,$01,$BD,$F3,$BD,$BE,$FE,$D1
		.BYTE $0E,$D6,$F8,$E6,$DC,$E3,$D2,$E5,$D2,$E4,$D7,$EA,$C3,$0E,$E9,$C2
		.BYTE $F1,$CE,$E4,$D2,$C6,$E3,$02,$0E,$EA,$D2,$E7,$D6,$E1,$0E,$E3,$DD
		.BYTE $C7,$10
_msg29:
		.BYTE $2E,$DA,$E7,$0E,$EA,$D1,$D2,$C3,$0E,$B0,$0E,$B7,$F0,$CE,$0E,$BA
		.BYTE $E9,$FF,$D0,$0E,$B7,$0E,$D6,$04,$E6,$E5,$C6,$E3,$D2,$F9,$E7,$0E
		.BYTE $E3,$C3,$08,$0F,$B1,$CC,$CE,$B2,$E7,$D6,$E1,$0E,$E3,$DD,$C7,$10
_msg2A:
		.BYTE $2E,$0E,$DE,$FD,$0E,$EC,$E7,$BD,$BE,$FE,$D1,$0E,$D6,$F8,$E6,$DC
		.BYTE $E0,$E4,$D7,$C3,$D1,$D2,$E3,$0E,$D6,$01,$BD,$F3,$BD,$BE,$FE,$D1
		.BYTE $0E,$D6,$F8,$E6,$DC,$E3,$D2,$E5,$D8,$E3,$C3,$DC,$D6,$F3,$D1,$E5
		.BYTE $E0,$E7,$CC,$CE,$CF,$D0,$0E,$B1,$D0,$0E,$B2,$D6,$0E,$B3,$D0,$E7
		.BYTE $E5,$D6,$E6,$BD,$BE,$FE,$E7,$DA,$DC,$E3,$D2,$F9,$0E,$EA,$D1,$D2
		.BYTE $E6,$EA,$C3,$0E,$B3,$B9,$BA,$0E,$E9,$C2,$F1,$CE,$E4,$D2,$C6,$E3
		.BYTE $03,$0E,$EA,$D2,$E7,$D6,$E1,$E6,$E5,$F8,$EF,$DD,$C7,$10
_msg2B:
		.BYTE $2E,$DA,$E7,$0E,$EA,$D1,$D2,$C3,$0E,$B0,$0E,$B7,$F0,$CE,$0E,$BA
		.BYTE $E9,$FF,$D0,$0E,$B7,$0E,$D6,$08,$E6,$E5,$C6,$E3,$D2,$F9,$E7,$0E
		.BYTE $E3,$C3,$02,$04,$0F,$B1,$CC,$CE,$B2,$E7,$D6,$E1,$0E,$E3,$DD,$C7
		.BYTE $10

; =============== S U B	R O U T	I N E =======================================
sub_2808B:
		LDY		byte_56A
		BNE		loc_28091
		RTS
; ---------------------------------------------------------------------------
loc_28091:
		DEY
		TYA
		JSR		_switch
; ---------------------------------------------------------------------------
		.WORD sub_280FE
		.WORD sub_280FE
		.WORD sub_280C4
		.WORD sub_280C9
		.WORD sub_280D3
		.WORD sub_280FE
		.WORD sub_280FE
		.WORD sub_280FE
		.WORD sub_280FE
		.WORD sub_280FE
		.WORD sub_280FE
		.WORD sub_280FE
		.WORD sub_280FE
		.WORD sub_280FE
		.WORD sub_280FE
		.WORD sub_280FE
		.WORD sub_280FE
		.WORD sub_280CE
		.WORD sub_280FE
		.WORD sub_280FE
		.WORD sub_280FE
		.WORD sub_280FE
		.WORD sub_280FE

; =============== S U B	R O U T	I N E =======================================
sub_280C4:
		LDA		#$04
		JMP		sub_280F5

; =============== S U B	R O U T	I N E =======================================
sub_280C9:
		LDA		#$01
		JMP		sub_280F5

; =============== S U B	R O U T	I N E =======================================
sub_280CE:
		LDA		#$03
		JMP		sub_280F5

; =============== S U B	R O U T	I N E =======================================
sub_280D3:
		LDA		byte_551
		BNE		loc_280E3
		INC		byte_551
		LDA		#$06
		STA		byte_55D
		JMP		sub_26ED7
; ---------------------------------------------------------------------------
loc_280E3:
		CMP		#$01
		BNE		sub_280FE
		LDA		byte_32
		ORA		_ppu_queue_req
		ORA		_nmi_tlm_lib_idx
		BNE		sub_280FE
		INC		byte_551
		LDA		#$84

; =============== S U B	R O U T	I N E =======================================
sub_280F5:
		STA		byte_55D
		JSR		sub_26ED7
		JMP		sub_280FE

; =============== S U B	R O U T	I N E =======================================
sub_280FE:
		DEC		_tmp4Bb
		BNE		locret_2811A
		LDA		_title_push_start_toggle
		EOR		#$01
		STA		_title_push_start_toggle
		BNE		loc_28113
		LDA		#$1E
		STA		_tmp4Bb
		JMP		loc_2811B
; ---------------------------------------------------------------------------
loc_28113:
		LDA		#$0F
		STA		_tmp4Bb
		JSR		sub_27298
locret_2811A:
		RTS
; ---------------------------------------------------------------------------
loc_2811B:
		LDY		byte_56A
		DEY
		LDA		off_28137,Y
		STA		_tmp20w
		LDA		off_2814E,Y
		STA		_tmp20w+1
		LDY		#$00
		LDA		(_tmp20w),Y
		TAY
loc_2812E:
		LDA		(_tmp20w),Y
		STA		_spr_buf+$4F,Y
		DEY
		BNE		loc_2812E
		RTS
; ---------------------------------------------------------------------------
off_28137:
		.BYTE <[byte_28165]
		.BYTE <[byte_2816E]
		.BYTE <[byte_28177]
		.BYTE <[byte_28188]
		.BYTE <[byte_28199]
		.BYTE <[byte_281BA]
		.BYTE <[byte_281D3]
		.BYTE <[byte_281D3]
		.BYTE <[byte_281EC]
		.BYTE <[byte_281F5]
		.BYTE <[byte_281FE]
		.BYTE <[byte_28207]
		.BYTE <[byte_28210]
		.BYTE <[byte_28219]
		.BYTE <[byte_28222]
		.BYTE <[byte_2822B]
		.BYTE <[byte_28244]
		.BYTE <[byte_2825D]
		.BYTE <[byte_2826E]
		.BYTE <[byte_28277]
		.BYTE <[byte_28280]
		.BYTE <[byte_28289]
		.BYTE <[byte_28292]
off_2814E:
		.BYTE >[byte_28165]
		.BYTE >[byte_2816E]
		.BYTE >[byte_28177]
		.BYTE >[byte_28188]
		.BYTE >[byte_28199]
		.BYTE >[byte_281BA]
		.BYTE >[byte_281D3]
		.BYTE >[byte_281D3]
		.BYTE >[byte_281EC]
		.BYTE >[byte_281F5]
		.BYTE >[byte_281FE]
		.BYTE >[byte_28207]
		.BYTE >[byte_28210]
		.BYTE >[byte_28219]
		.BYTE >[byte_28222]
		.BYTE >[byte_2822B]
		.BYTE >[byte_28244]
		.BYTE >[byte_2825D]
		.BYTE >[byte_2826E]
		.BYTE >[byte_28277]
		.BYTE >[byte_28280]
		.BYTE >[byte_28289]
		.BYTE >[byte_28292]
byte_28165:
		.BYTE $08
		.BYTE $A0,$F8,$80,$A0
		.BYTE $A0,$F8,$C0,$A8
byte_2816E:
		.BYTE $08
		.BYTE $48,$F8,$00,$20
		.BYTE $48,$F8,$40,$28
byte_28177:
		.BYTE $10
		.BYTE $A0,$F8,$80,$A0
		.BYTE $A0,$F8,$C0,$A8
		.BYTE $D4,$F0,$00,$A0
		.BYTE $D4,$F2,$00,$A8
byte_28188:
		.BYTE $10
		.BYTE $A0,$F8,$80,$D0
		.BYTE $A0,$F8,$C0,$D8
		.BYTE $D4,$F0,$00,$D0
		.BYTE $D4,$F2,$00,$D8
byte_28199:
		.BYTE $20
		.BYTE $48,$F8,$00,$80
		.BYTE $48,$F8,$40,$88
		.BYTE $48,$F8,$00,$A0
		.BYTE $48,$F8,$40,$A8
		.BYTE $10,$F0,$00,$80
		.BYTE $10,$F2,$00,$88
		.BYTE $10,$E2,$00,$A0
		.BYTE $10,$E4,$00,$A8
byte_281BA:
		.BYTE $18
		.BYTE $40,$EE,$00,$63
		.BYTE $40,$EE,$00,$83
		.BYTE $40,$EE,$00,$93
		.BYTE $40,$EE,$00,$A3
		.BYTE $40,$EE,$00,$B3
		.BYTE $40,$EE,$00,$C3
byte_281D3:
		.BYTE $18
		.BYTE $A8,$EE,$80,$83
		.BYTE $A8,$EE,$80,$93
		.BYTE $A8,$EE,$80,$A3
		.BYTE $A8,$EE,$80,$B3
		.BYTE $A8,$EE,$80,$C3
		.BYTE $A8,$EE,$80,$D3
byte_281EC:
		.BYTE $08
		.BYTE $A0,$F8,$80,$B0
		.BYTE $A0,$F8,$C0,$B8
byte_281F5:
		.BYTE $08
		.BYTE $60,$F8,$80,$70
		.BYTE $60,$F8,$C0,$78
byte_281FE:
		.BYTE $08
		.BYTE $40,$F8,$80,$70
		.BYTE $40,$F8,$C0,$78
byte_28207:
		.BYTE $08
		.BYTE $A0,$F8,$80,$50
		.BYTE $A0,$F8,$C0,$58
byte_28210:
		.BYTE $08
		.BYTE $88,$F8,$80,$80
		.BYTE $88,$F8,$C0,$88
byte_28219:
		.BYTE $08
		.BYTE $88,$F8,$80,$10
		.BYTE $88,$F8,$C0,$18
byte_28222:
		.BYTE $08
		.BYTE $28,$F8,$00,$70
		.BYTE $28,$F8,$40,$78
byte_2822B:
		.BYTE $18
		.BYTE $D8,$EE,$00,$83
		.BYTE $D8,$EE,$00,$93
		.BYTE $D8,$EE,$00,$A3
		.BYTE $D8,$EE,$00,$B3
		.BYTE $D8,$EE,$00,$C3
		.BYTE $D8,$EE,$00,$D3
byte_28244:
		.BYTE $18
		.BYTE $0A,$EE,$80,$83
		.BYTE $0A,$EE,$80,$93
		.BYTE $0A,$EE,$80,$A3
		.BYTE $0A,$EE,$80,$B3
		.BYTE $0A,$EE,$80,$C3
		.BYTE $0A,$EE,$80,$D3
byte_2825D:
		.BYTE $10
		.BYTE $48,$F8,$00,$B0
		.BYTE $48,$F8,$40,$B8
		.BYTE $10,$F0,$00,$B0
		.BYTE $10,$F2,$00,$B8
byte_2826E:
		.BYTE $08
		.BYTE $78,$F8,$80,$70
		.BYTE $78,$F8,$C0,$78
byte_28277:
		.BYTE $08
		.BYTE $48,$F8,$00,$90
		.BYTE $48,$F8,$40,$98
byte_28280:
		.BYTE $08
		.BYTE $48,$F8,$00,$80
		.BYTE $48,$F8,$40,$88
byte_28289:
		.BYTE $08
		.BYTE $60,$F8,$00,$E7
		.BYTE $60,$F8,$40,$EF
byte_28292:
		.BYTE $08
		.BYTE $90,$F8,$80,$90
		.BYTE $90,$F8,$C0,$98
