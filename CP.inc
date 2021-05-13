
;		ORG $A980

; =============== S U B	R O U T	I N E =======================================
_j_cp_sub00:
		JMP		_cp_sub00

; =============== S U B	R O U T	I N E =======================================
_j_cp_sub01:
		JMP		_cp_sub01

; =============== S U B	R O U T	I N E =======================================
_j_cp_sub02:
		JMP		_cp_sub02

; =============== S U B	R O U T	I N E =======================================
_j_cp_sub03_field_and_dice_editor:
		JMP		_cp_sub03_field_and_dice_editor

; =============== S U B	R O U T	I N E =======================================
_cp_sub04:
		LDA		#$40
		STA		byte_B6
		LDA		#$00
		STA		byte_B5
		STA		byte_B4
		STA		byte_B3
		JSR		sub_1B58F
		LDA		_training_mode_flag
		BEQ		loc_1A9AC
		JSR		sub_1AAAC
		JSR		sub_1AEA7
		JSR		sub_1AC55
		JMP		sub_1AB07
; ---------------------------------------------------------------------------
loc_1A9AC:
		JSR		sub_1AA66
		JSR		sub_1AA47
		BCS		loc_1A9F6
		LDA		byte_5BF
		BNE		loc_1A9F6
		LDA		byte_5EC
		CMP		#$04
		BCS		loc_1A9CD
		CMP		#$02
		BCC		loc_1AA21
		LDA		byte_5DC
		BPL		loc_1AA21
		CMP		#$FA
		BCS		loc_1AA21
loc_1A9CD:
		LDA		byte_5EB
		BPL		loc_1A9E7
		JSR		sub_1AC2C
		JSR		sub_1AEA7
		JSR		sub_1AD48
		JSR		sub_1AC55
		JSR		sub_1AFC5
		JSR		sub_1AC8E
		JMP		sub_1B053
; ---------------------------------------------------------------------------
loc_1A9E7:
		JSR		sub_1AEA7
		JSR		sub_1AE5A
		JSR		sub_1AC55
		JSR		sub_1AC8E
		JMP		sub_1B053
; ---------------------------------------------------------------------------
loc_1A9F6:
		JSR		sub_1AAAC
		JSR		sub_1AAF1
		LDA		byte_5CD
		CMP		#$03
		BCS		loc_1AA1B
		LDA		byte_5EA
		CMP		#$04
		BCC		loc_1AA1E
		LDA		byte_419
		BNE		loc_1AA1B
		LDA		byte_5EC
		BEQ		loc_1AA1B
		CMP		#$04
		BCS		loc_1AA1B
		JSR		sub_1AAD7
loc_1AA1B:
		JMP		sub_1AB07
; ---------------------------------------------------------------------------
loc_1AA1E:
		JMP		sub_1AB10
; ---------------------------------------------------------------------------
loc_1AA21:
		JSR		sub_1AC2C
		JSR		sub_1AB28
		JSR		sub_1AB7E
		JSR		sub_1ABA7
		JSR		sub_1B053
		LDA		byte_5DE
		CMP		#$0E
		BCC		loc_1AA41
		LDA		byte_5EC
		CMP		#$02
		BCS		loc_1AA41
		JMP		sub_1AC06
; ---------------------------------------------------------------------------
loc_1AA41:
		JSR		sub_1ABB7
		JMP		sub_1ABDA

; =============== S U B	R O U T	I N E =======================================
sub_1AA47:
		LDA		byte_5BF
		CMP		byte_5DD
		BEQ		loc_1AA5D
		LDA		byte_5BE
		BPL		loc_1AA5F
		CMP		#$FE
		BCS		loc_1AA5F
		LDA		#$80
		JSR		sub_1B12D
loc_1AA5D:
		CLC
		RTS
; ---------------------------------------------------------------------------
loc_1AA5F:
		LDA		#$80
		JSR		sub_1B0CE
		SEC
locret_1AA65:
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_1AA66:
		LDA		byte_5EB
		BMI		locret_1AA65
		LDY		byte_5EE
		BEQ		locret_1AA65
		LDA		byte_41A
		BNE		locret_1AA65
		LDA		byte_5B5
		ASL
		CMP		byte_5B7
		BCS		locret_1AA65
		LDA		byte_5EB
		CMP		#$03
		BCC		loc_1AA8A
		CPY		byte_5EB
		BCC		locret_1AA65
loc_1AA8A:
		LDA		#$E0
		LDY		byte_5D0
		BEQ		loc_1AAA9
		LDA		byte_5F2
		SEC
		SBC		byte_5D4
		BEQ		loc_1AA9E
		ADC		#$D0
		BNE		loc_1AAA9
loc_1AA9E:
		LDA		byte_5C0
		SEC
		SBC		byte_5DE
		BEQ		locret_1AA65
		ADC		#$C0
loc_1AAA9:
		JMP		sub_1B0CE

; =============== S U B	R O U T	I N E =======================================
sub_1AAAC:
		LDX		#$01
loc_1AAAE:
		LDA		byte_1AABF-1,X
		STA		byte_B8
		LDA		byte_440,X
		JSR		sub_1B151
		INX
		CPX		#$19
		BNE		loc_1AAAE
nullsub_7:
		RTS
byte_1AABF:
		.BYTE $D0,$C8,$C0,$B8,$B0,$A8,$5F,$5A,$55,$50,$4B,$46,$23,$20,$1D,$1A
		.BYTE $17,$14,$06,$05,$04,$03,$02,$01

; =============== S U B	R O U T	I N E =======================================
sub_1AAD7:
		LDY		byte_5CE
		BNE		loc_1AAE1
		LDA		#$80
		JSR		sub_1B0F0
loc_1AAE1:
		LDA		byte_5D2
		CMP		#$02
		BCS		nullsub_7
		LDA		#$80
		JSR		sub_1B0F0
		LDA		#$10
		BNE		sub_1AAF3

; =============== S U B	R O U T	I N E =======================================
sub_1AAF1:
		LDA		#$01

; =============== S U B	R O U T	I N E =======================================
sub_1AAF3:
		PHA
		LDX		#$00
		LDY		#$13
loc_1AAF8:
		LDA		byte_440,Y
		BNE		loc_1AAFE
		INX
loc_1AAFE:
		INY
		CPY		#$19
		BNE		loc_1AAF8
		PLA
		JMP		sub_1B14F

; =============== S U B	R O U T	I N E =======================================
sub_1AB07:
		LDX		#$80
		LDA		byte_459
		ASL
		JMP		sub_1B0F2

; =============== S U B	R O U T	I N E =======================================
sub_1AB10:
		LDA		byte_459
		CLC
		ADC		#$01
		AND		#$1E
		LDX		#$80
		JSR		sub_1B0F2
		LDA		byte_5C0
		SEC
		SBC		#$13
		LDX		#$10
		JMP		sub_1B0F2

; =============== S U B	R O U T	I N E =======================================
sub_1AB28:
		LDA		byte_5C2
		CMP		#$06
		BEQ		locret_1AB7D
		LDX		#$07
loc_1AB31:
		LDA		byte_440,X
		CMP		#$01
		BNE		loc_1AB78
		CPX		#$13
		BCS		loc_1AB4C
		LDA		byte_460
		BEQ		loc_1AB4C
		CMP		#$02
		BCS		loc_1AB78
		LDA		byte_5C2
		CMP		#$05
		BCS		loc_1AB78
loc_1AB4C:
		TXA
		TAY
		LDA		#$06
		STA		byte_BD
loc_1AB52:
		LDA		byte_47F,Y
		CMP		#$06
		BEQ		loc_1AB78
		CPY		#$18
		BEQ		loc_1AB6E
		LDA		byte_461,Y
		BEQ		loc_1AB67
		LDA		#$10
		JSR		sub_1B139
loc_1AB67:
		INY
		DEC		byte_BD
		BNE		loc_1AB52
		BEQ		loc_1AB78
loc_1AB6E:
		LDA		byte_460
		BEQ		loc_1AB78
		LDA		#$10
		JSR		sub_1B139
loc_1AB78:
		INX
		CPX		#$19
		BNE		loc_1AB31
locret_1AB7D:
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_1AB7E:
		LDA		byte_47A
		BEQ		locret_1AB7D
		CMP		#$16
		BCS		loc_1AB94
		CMP		#$13
		BCS		loc_1AB8F
		LDA		#$50
		BNE		loc_1AB91
loc_1AB8F:
		LDA		#$30
loc_1AB91:
		JSR		sub_1B0F0
loc_1AB94:
		LDA		byte_5C2
		CMP		#$05
		BNE		locret_1AB7D
		CMP		byte_5E0
		BCC		locret_1AB7D
		BEQ		locret_1AB7D
		LDA		#$01
		JMP		sub_1B0DA

; =============== S U B	R O U T	I N E =======================================
sub_1ABA7:
		LDX		byte_5C8
		LDA		#$18
		JSR		sub_1B0F2
		LDX		byte_5C4
		LDA		#$10
		JMP		sub_1B0F2

; =============== S U B	R O U T	I N E =======================================
sub_1ABB7:
		LDX		byte_5C2
		LDA		#$18
		JSR		sub_1B0F2
		LDY		#$00
loc_1ABC1:
		LDA		byte_493,Y
		BEQ		loc_1ABCB
		INY
		CPY		#$06
		BNE		loc_1ABC1
loc_1ABCB:
		LDA		byte_1ABD3,Y
		LDX		#$10
		JMP		sub_1B0F2
; ---------------------------------------------------------------------------
byte_1ABD3:
		.BYTE $00,$10,$20,$30,$60,$70,$80

; =============== S U B	R O U T	I N E =======================================
sub_1ABDA:
		LDY		#$18
loc_1ABDC:
		LDA		byte_480,Y
		BEQ		loc_1ABE4
		DEY
		BNE		loc_1ABDC
loc_1ABE4:
		LDA		#$06
		STA		byte_BD
		LDX		#$00
loc_1ABEA:
		LDA		byte_440,Y
		CMP		#$02
		BEQ		loc_1ABF2
		INX
loc_1ABF2:
		DEY
		DEC		byte_BD
		BNE		loc_1ABEA
		LDA		byte_1ABFF,X
		LDX		#$0A
		JMP		sub_1B0F2
; ---------------------------------------------------------------------------
byte_1ABFF:
		.BYTE $00,$00,$01,$03,$04,$05,$06

; =============== S U B	R O U T	I N E =======================================
sub_1AC06:
		LDA		byte_5C0
		SEC
		SBC		byte_5DE
		BEQ		loc_1AC14
		LDX		#$04
		JSR		sub_1B0F2
loc_1AC14:
		LDY		byte_5C0
		LDA		byte_440,Y
		AND		#$01
		LDX		#$04
		JSR		sub_1B14F
		INY
		LDA		byte_440,Y
		AND		#$01
		LDX		#$02
		JMP		sub_1B14F

; =============== S U B	R O U T	I N E =======================================
sub_1AC2C:
		LDY		#$01
loc_1AC2E:
		LDX		byte_1AC3D-1,Y
		LDA		byte_440,Y
		JSR		sub_1B14F
		INY
		CPY		#$19
		BNE		loc_1AC2E
		RTS
; ---------------------------------------------------------------------------
byte_1AC3D:
		.BYTE $60,$4A,$40,$38,$30,$28,$22,$1E,$1A,$16,$13,$10,$0C,$0A,$08,$06
		.BYTE $05,$04,$00,$00,$00,$00,$00,$00

; =============== S U B	R O U T	I N E =======================================
sub_1AC55:
		LDX		#$1A
loc_1AC57:
		LDY		byte_460,X
		BEQ		locret_1AC75
		LDA		byte_1AC76-1,Y
		STA		byte_B8
		LDA		byte_420
		CMP		#$03
		BCC		loc_1AC6A
		LDA		#$03
loc_1AC6A:
		ASL
		ADC		#$06
		JSR		sub_1B0F4
		INX
		CPX		#$1F
		BNE		loc_1AC57
locret_1AC75:
		RTS
; ---------------------------------------------------------------------------
byte_1AC76:
		.BYTE $D0,$D0,$D0,$D0,$D0,$D0,$D0,$C0,$C0,$B0,$A0,$90,$70,$50,$40,$28
		.BYTE $1C,$18,$07,$03,$03,$03,$01,$01

; =============== S U B	R O U T	I N E =======================================
sub_1AC8E:
		LDX		#$1A
loc_1AC90:
		LDY		byte_460,X
		BEQ		locret_1AC75
		LDA		byte_5F3
		BNE		loc_1ACB8
		LDA		byte_5F1
		CMP		#$02
		BCC		loc_1ACA8
		LDA		byte_5DF
		CMP		#$0D
		BCS		loc_1ACB8
loc_1ACA8:
		LDA		byte_5C2
		CMP		byte_5E0
		BCS		loc_1ACB4
		LDY		#$E0
		BNE		loc_1AD09
loc_1ACB4:
		LDY		#$F8
		BNE		loc_1AD09
loc_1ACB8:
		LDY		byte_5C2
		LDA		byte_5C8
		CMP		#$04
		BCS		loc_1ACDF
		CPY		#$05
		BCS		loc_1ACDF
		CMP		#$03
		BEQ		loc_1ACD4
		CPY		#$04
		BEQ		loc_1ACE3
		CPY		#$03
		BEQ		loc_1ACEE
		BNE		loc_1ACF9
loc_1ACD4:
		LDA		byte_5C3
		CMP		#$05
		BCS		loc_1ACF9
		CMP		#$04
		BEQ		loc_1ACF9
loc_1ACDF:
		LDY		#$E1
		BNE		loc_1AD09
loc_1ACE3:
		LDA		byte_5C3
		CMP		#$04
		BCS		loc_1ACF9
		LDY		#$03
		BNE		loc_1AD09
loc_1ACEE:
		LDA		byte_5C3
		CMP		#$03
		BCS		loc_1ACF9
		LDY		#$01
		BNE		loc_1AD09
loc_1ACF9:
		JSR		sub_1AD39
		BCC		loc_1AD30
loc_1ACFE:
		LDA		#$20
		CPY		#$06
		BEQ		loc_1AD06
		LDA		#$01
loc_1AD06:
		JMP		sub_1B139
; ---------------------------------------------------------------------------
loc_1AD09:
		STY		byte_BD
		JSR		sub_1AD39
		BCS		loc_1ACFE
		LDA		byte_460,X
		CMP		#$13
		BCC		loc_1AD2B
		LDA		byte_5C2
		CMP		byte_5E0
		BCC		locret_1AD38
		LDA		byte_413
		CMP		#$02
		BCC		loc_1AD2B
		LDA		byte_493
		BEQ		locret_1AD38
loc_1AD2B:
		LDA		byte_BD
		JSR		sub_1B0DA
loc_1AD30:
		INX
		CPX		#$1F
		BEQ		locret_1AD38
		JMP		loc_1AC90
; ---------------------------------------------------------------------------
locret_1AD38:
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_1AD39:
		LDA		byte_5C9
		CMP		#$04
		BCC		locret_1AD47
		LDY		byte_5E0
		CPY		#$04
		BCC		locret_1AD47
locret_1AD47:
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_1AD48:
		LDX		#$00
		STX		byte_BD
		INX
loc_1AD4D:
		LDA		byte_440,X
		BEQ		loc_1ADC5
		CMP		#$01
		BEQ		loc_1AD6B
		LDY		byte_5F0
		CPY		#$02
		BCC		loc_1AD87
		CMP		#$02
		BEQ		loc_1AD87
		CMP		#$03
		BEQ		loc_1AD8D
		CMP		#$04
		BEQ		loc_1AD93
		BNE		loc_1AD99
loc_1AD6B:
		LDA		byte_1ADE1-1,X
		STA		byte_B8
		TXA
		SEC
		SBC		byte_BD
		CMP		#$06
		BCS		loc_1AD80
		LDA		byte_BD
		BEQ		loc_1AD80
		LDA		#$02
		BNE		loc_1AD82
loc_1AD80:
		LDA		#$00
loc_1AD82:
		STX		byte_BD
		JMP		loc_1ADC2
; ---------------------------------------------------------------------------
loc_1AD87:
		LDA		byte_1ADF9-1,X
		JMP		loc_1ADAC
; ---------------------------------------------------------------------------
loc_1AD8D:
		LDA		byte_1AE11-1,X
		JMP		loc_1ADAA
; ---------------------------------------------------------------------------
loc_1AD93:
		LDA		byte_1AE29-1,X
		JMP		loc_1ADAA
; ---------------------------------------------------------------------------
loc_1AD99:
		SEC
		SBC		#$05
		STA		byte_BE
		ASL		byte_BE
		LDA		byte_1AE41,X
		SEC
		SBC		byte_BE
		BCS		loc_1ADAA
		LDA		#$00
loc_1ADAA:
		STX		byte_BD
loc_1ADAC:
		STA		byte_B8
		LDY		#$03
		LDA		byte_441,X
		CMP		#$02
		BCC		loc_1ADB9
		INY
		INY
loc_1ADB9:
		LDA		byte_43F,X
		CMP		#$02
		BCC		loc_1ADC1
		INY
loc_1ADC1:
		TYA
loc_1ADC2:
		JSR		sub_1B0F4
loc_1ADC5:
		INX
		CPX		#$19
		BNE		loc_1AD4D
		LDA		byte_5F0
		BEQ		locret_1ADE0
		LDA		byte_413
		CMP		#$02
		BCC		locret_1ADE0
		LDA		byte_493
		BNE		locret_1ADE0
		LDA		#$03
		JMP		sub_1B139
; ---------------------------------------------------------------------------
locret_1ADE0:
		RTS
; ---------------------------------------------------------------------------
byte_1ADE1:
		.BYTE $08,$08,$00,$00,$00,$00,$04,$04,$04,$04,$04,$04,$06,$08,$08,$08
		.BYTE $08,$08,$06,$04,$02,$00,$00,$00
byte_1ADF9:
		.BYTE $18,$1C,$20,$24,$40,$28,$40,$29,$28,$28,$60,$70,$68,$70,$80,$98
		.BYTE $A0,$C8,$F0,$F0,$C8,$A0,$60,$50
byte_1AE11:
		.BYTE $18,$1C,$20,$24,$40,$28,$3F,$28,$27,$27,$5F,$6F,$67,$6F,$7F,$97
		.BYTE $9F,$C7,$EF,$EF,$C7,$70,$30,$28
byte_1AE29:
		.BYTE $18,$1C,$20,$24,$40,$28,$3D,$27,$26,$26,$5D,$6D,$65,$6D,$7D,$95
		.BYTE $9D,$C5,$ED,$ED,$C5,$40,$18,$10
byte_1AE41:
		.BYTE $00,$18,$1C,$20,$24,$40,$28,$3C,$26,$25,$25,$5C,$6C,$63,$6B,$7B
		.BYTE $93,$9B,$C3,$EB,$EB,$C2,$20,$0C,$08

; =============== S U B	R O U T	I N E =======================================
sub_1AE5A:
		LDX		#$01
loc_1AE5C:
		LDY		byte_440,X
		CPY		#$02
		BCC		loc_1AE89
		LDA		byte_1AE8F-1,X
		STA		byte_B8
		CPX		#$0D
		BCC		loc_1AE74
		CPY		#$02
		BEQ		loc_1AE74
		INC		byte_B8
		INC		byte_B8
loc_1AE74:
		LDY		#$03
		LDA		byte_441,X
		CMP		#$02
		BCC		loc_1AE7E
		INY
loc_1AE7E:
		LDA		byte_43F,X
		CMP		#$02
		BCC		loc_1AE86
		INY
loc_1AE86:
		JSR		sub_1B0F4
loc_1AE89:
		INX
		CPX		#$19
		BNE		loc_1AE5C
		RTS
; ---------------------------------------------------------------------------
byte_1AE8F:
		.BYTE $14,$16,$18,$1C,$20,$22,$24,$28,$30,$40,$50,$60,$68,$70,$80,$98
		.BYTE $A0,$B0,$C0,$C0,$DE,$DC,$DA,$D8

; =============== S U B	R O U T	I N E =======================================
sub_1AEA7:
		LDX		#$01
loc_1AEA9:
		LDA		byte_440,X
		CMP		#$01
		BNE		loc_1AEEF
		TXA
		PHA
		LDA		#$00
		STA		byte_B8
		LDY		#$06
loc_1AEB8:
		CPX		#$18
		BEQ		loc_1AEDE
		LDA		byte_461,X
		BEQ		loc_1AED8
		CMP		#$02
		BEQ		loc_1AECD
		CMP		#$01
		BNE		loc_1AED1
		LDA		#$12
		BNE		loc_1AED3
loc_1AECD:
		LDA		#$0C
		BNE		loc_1AED3
loc_1AED1:
		LDA		#$10
loc_1AED3:
		CLC
		ADC		byte_B8
		STA		byte_B8
loc_1AED8:
		INX
		DEY
		BNE		loc_1AEB8
		BEQ		loc_1AEEA
loc_1AEDE:
		LDA		byte_460
		BEQ		loc_1AEEA
		LDA		#$20
		CLC
		ADC		byte_B8
		STA		byte_B8
loc_1AEEA:
		PLA
		TAX
		JSR		sub_1AEF5
loc_1AEEF:
		INX
		CPX		#$19
		BNE		loc_1AEA9
nullsub_8:
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_1AEF5:
		LDA		byte_B8
		BEQ		nullsub_8
		CPX		#$13
		BCS		loc_1AF0D
		LDA		byte_460
		BEQ		loc_1AF0D
		CMP		#$02
		BCS		nullsub_8
		LDA		byte_5C2
		CMP		#$04
		BCS		nullsub_8
loc_1AF0D:
		LDY		byte_5E1
		CPY		#$06
		BEQ		loc_1AF29
		CPY		#$05
		BEQ		loc_1AF2D
		CPY		#$04
		BEQ		loc_1AF32
		LDY		byte_5C8
		CPY		#$04
		BCS		locret_1AF3C
		CPY		#$03
		BEQ		loc_1AF37
		BNE		loc_1AF3D
loc_1AF29:
		LDA		#$F0
		BNE		loc_1AF4A
loc_1AF2D:
		LDA		byte_1AF95-1,X
		BNE		loc_1AF4A
loc_1AF32:
		LDA		byte_1AF7D-1,X
		BNE		loc_1AF4A
loc_1AF37:
		LDA		byte_1AFAD-1,X
		BNE		loc_1AF4A
locret_1AF3C:
		RTS
; ---------------------------------------------------------------------------
loc_1AF3D:
		LDA		byte_1AF4D-1,X
		LDY		byte_5C0
		CPY		#$0D
		BCC		loc_1AF4A
		LDA		byte_1AF65-1,X
loc_1AF4A:
		JMP		sub_1B151
; ---------------------------------------------------------------------------
byte_1AF4D:
		.BYTE $00,$00,$00,$00,$00,$00,$01,$01,$02,$02,$03,$04,$05,$08,$0A,$0C
		.BYTE $0C,$0E,$10,$10,$10,$10,$10,$10
byte_1AF65:
		.BYTE $00,$00,$00,$00,$00,$00,$04,$04,$08,$08,$0C,$10,$14,$20,$28,$30
		.BYTE $30,$38,$40,$40,$40,$40,$40,$40
byte_1AF7D:
		.BYTE $00,$00,$00,$00,$00,$00,$02,$02,$04,$04,$06,$08,$08,$10,$18,$18
		.BYTE $18,$18,$20,$20,$20,$20,$20,$20
byte_1AF95:
		.BYTE $00,$00,$00,$00,$00,$00,$04,$04,$08,$08,$0C,$10,$14,$20,$28,$30
		.BYTE $30,$38,$40,$40,$40,$40,$40,$40
byte_1AFAD:
		.BYTE $00,$00,$00,$00,$00,$00,$01,$01,$02,$02,$03,$03,$04,$04,$05,$05
		.BYTE $06,$06,$06,$06,$06,$06,$06,$06

; =============== S U B	R O U T	I N E =======================================
sub_1AFC5:
		LDY		byte_5DE
		CPY		#$06
		BCC		loc_1AFCE
		LDY		#$06
loc_1AFCE:
		LDA		byte_5E7
		CMP		#$02
		BCC		locret_1B02F
		BNE		loc_1AFE1
		LDA		byte_5C9
		BNE		loc_1AFF4
		LDA		byte_1B030,Y
		BNE		loc_1B00D
loc_1AFE1:
		LDA		byte_5C9
		BEQ		loc_1AFEF
		CMP		#$01
		BNE		loc_1AFF4
		LDA		byte_1B037,Y
		BNE		loc_1B00D
loc_1AFEF:
		LDA		byte_1B03E,Y
		BNE		loc_1B00D
loc_1AFF4:
		LDA		byte_5E9
		CMP		byte_5CB
		BEQ		loc_1B010
		LDA		byte_5E7
		CMP		#$02
		BCC		loc_1B010
		BNE		loc_1B00A
		LDA		byte_1B045,Y
		BNE		loc_1B00D
loc_1B00A:
		LDA		byte_1B04C,Y
loc_1B00D:
		JMP		sub_1B0DA
; ---------------------------------------------------------------------------
loc_1B010:
		LDA		byte_5E7
		CMP		#$03
		BCC		locret_1B02F
		LDY		byte_5DE
		CPY		byte_5C0
		BEQ		loc_1B023
		LDA		#$02
		BNE		loc_1B00D
loc_1B023:
		LDA		byte_400,Y
		CMP		byte_440,Y
		BEQ		locret_1B02F
		LDA		#$01
		BNE		loc_1B00D
locret_1B02F:
		RTS
; ---------------------------------------------------------------------------
byte_1B030:
		.BYTE $10,$06,$05,$03,$01,$01,$01
byte_1B037:
		.BYTE $10,$08,$06,$04,$02,$01,$01
byte_1B03E:
		.BYTE $F0,$F0,$F0,$04,$02,$01,$01
byte_1B045:
		.BYTE $08,$05,$04,$03,$01,$01,$01
byte_1B04C:
		.BYTE $F0,$F0,$F0,$04,$02,$01,$01

; =============== S U B	R O U T	I N E =======================================
sub_1B053:
		LDY		byte_5C4
		LDX		byte_5C6
		LDA		byte_5E2
		CMP		#$06
		BCC		loc_1B0B5
		BNE		loc_1B076
		CPY		#$06
		BCC		loc_1B0AA
		BNE		loc_1B06F
		CPX		byte_5E4
		BNE		loc_1B081
		BEQ		loc_1B08B
loc_1B06F:
		CPX		byte_5E4
		BEQ		loc_1B081
		BNE		loc_1B08B
loc_1B076:
		CPY		#$06
		BCC		loc_1B0AA
		DEX
		DEX
		CPX		byte_5E4
		BCC		loc_1B08B
loc_1B081:
		LDA		byte_5E6
		BEQ		locret_1B0C8
		LDA		#$E0
		JMP		sub_1B0DA
; ---------------------------------------------------------------------------
loc_1B08B:
		LDA		byte_5C6
		CLC
		ADC		#$06
		TAY
		LDA		byte_440,Y
		CMP		#$02
		BCC		loc_1B09C
		LDA		byte_441,Y
loc_1B09C:
		CMP		#$01
		BNE		locret_1B0C8
		LDA		byte_5E6
		BEQ		locret_1B0C8
		LDA		#$80
		JMP		sub_1B0DA
; ---------------------------------------------------------------------------
loc_1B0AA:
		LDA		#$10
		JSR		sub_1B12D
		LDA		byte_1B0C9-1,Y
		JMP		sub_1B139
; ---------------------------------------------------------------------------
loc_1B0B5:
		CPY		#$06
		BCC		locret_1B0C8
		LDA		byte_5E6
		BEQ		loc_1B0C3
		LDA		#$01
		JMP		sub_1B0CE
; ---------------------------------------------------------------------------
loc_1B0C3:
		LDA		#$01
		JMP		sub_1B0DA
; ---------------------------------------------------------------------------
locret_1B0C8:
		RTS
; ---------------------------------------------------------------------------
byte_1B0C9:
		.BYTE $04,$03,$02,$01,$00

; =============== S U B	R O U T	I N E =======================================
sub_1B0CE:
		STA		byte_BC
		LDA		#$01
		STA		byte_BA
		LDA		#$00
		STA		byte_B9
		BEQ		sub_1B0E4

; =============== S U B	R O U T	I N E =======================================
sub_1B0DA:
		STA		byte_BC
		LDA		#$01
		STA		byte_B9
		LDA		#$00
		STA		byte_BA

; =============== S U B	R O U T	I N E =======================================
sub_1B0E4:
		STA		byte_B8
		BEQ		sub_1B0FC
		STA		byte_BC
		LDA		#$00
		STA		byte_B8
		BEQ		sub_1B0FA

; =============== S U B	R O U T	I N E =======================================
sub_1B0F0:
		LDX		#$01

; =============== S U B	R O U T	I N E =======================================
sub_1B0F2:
		STX		byte_B8

; =============== S U B	R O U T	I N E =======================================
sub_1B0F4:
		STA		byte_BC
		LDA		#$00
		STA		byte_B9

; =============== S U B	R O U T	I N E =======================================
sub_1B0FA:
		STA		byte_BA

; =============== S U B	R O U T	I N E =======================================
sub_1B0FC:
		STA		byte_BB

; =============== S U B	R O U T	I N E =======================================
sub_1B0FE:
		LDA		byte_BC
		BEQ		loc_1B12A
		LSR		byte_BC
		BCC		loc_1B11F
		LDA		byte_B8
		CLC
		ADC		byte_B3
		STA		byte_B3
		LDA		byte_B9
		ADC		byte_B4
		STA		byte_B4
		LDA		byte_BA
		ADC		byte_B5
		STA		byte_B5
		LDA		byte_BB
		ADC		byte_B6
		STA		byte_B6
loc_1B11F:
		ASL		byte_B8
		ROL		byte_B9
		ROL		byte_BA
		ROL		byte_BB
		JMP		sub_1B0FE
; ---------------------------------------------------------------------------
loc_1B12A:
		JMP		sub_96BC

; =============== S U B	R O U T	I N E =======================================
sub_1B12D:
		STA		byte_BC
		LDA		#$01
		STA		byte_BA
		LDA		#$00
		STA		byte_B9
		BEQ		sub_1B143

; =============== S U B	R O U T	I N E =======================================
sub_1B139:
		STA		byte_BC
		LDA		#$01
		STA		byte_B9
		LDA		#$00
		STA		byte_BA

; =============== S U B	R O U T	I N E =======================================
sub_1B143:
		STA		byte_B8
		BEQ		sub_1B159
		STA		byte_BC
		LDA		#$00
		STA		byte_B8
		BEQ		sub_1B157

; =============== S U B	R O U T	I N E =======================================
sub_1B14F:
		STX		byte_B8

; =============== S U B	R O U T	I N E =======================================
sub_1B151:
		STA		byte_BC
		LDA		#$00
		STA		byte_B9

; =============== S U B	R O U T	I N E =======================================
sub_1B157:
		STA		byte_BA

; =============== S U B	R O U T	I N E =======================================
sub_1B159:
		STA		byte_BB

; =============== S U B	R O U T	I N E =======================================
sub_1B15B:
		LDA		byte_BC
		BEQ		loc_1B12A
		LSR		byte_BC
		BCC		loc_1B17C
		LDA		byte_B3
		SEC
		SBC		byte_B8
		STA		byte_B3
		LDA		byte_B4
		SBC		byte_B9
		STA		byte_B4
		LDA		byte_B5
		SBC		byte_BA
		STA		byte_B5
		LDA		byte_B6
		SBC		byte_BB
		STA		byte_B6
loc_1B17C:
		ASL		byte_B8
		ROL		byte_B9
		ROL		byte_BA
		ROL		byte_BB
		JMP		sub_1B15B

; =============== S U B	R O U T	I N E =======================================
_cp_sub01:
		LDY		_cur_player_idx
		LDA		byte_5B1,Y
		BNE		loc_1B1D4
		JSR		sub_1B578
		JSR		sub_1B2E6
		LDA		byte_5CC
		BMI		loc_1B1D7
		CMP		#$07
		BCS		loc_1B1BD
		CMP		#$04
		BCS		loc_1B1B6
		CMP		byte_5EB
		BEQ		loc_1B1A8
		BCS		loc_1B222
loc_1B1A8:
		LDX		byte_479
		BNE		loc_1B1D4
		CMP		byte_5ED
		BEQ		loc_1B222
		BCC		loc_1B222
		BCS		loc_1B1D4
loc_1B1B6:
		CMP		byte_5EB
		BCS		loc_1B222
		BCC		loc_1B1C5
loc_1B1BD:
		CLC
		ADC		#$01
		CMP		byte_5EB
		BCS		loc_1B222
loc_1B1C5:
		LDX		byte_479
		BNE		loc_1B1D4
		LDX		byte_5C1
		BEQ		loc_1B222
		CMP		byte_5ED
		BCC		loc_1B222
loc_1B1D4:
		LDA		#$01
		RTS
; ---------------------------------------------------------------------------
loc_1B1D7:
		LDY		byte_5C9
		LDA		byte_5C8
		BEQ		loc_1B225
		CMP		#$03
		BEQ		loc_1B1F9
		CMP		#$04
		BEQ		loc_1B1FF
		CMP		#$05
		BEQ		loc_1B20A
		CMP		#$01
		BEQ		loc_1B222
		LDA		byte_440
		BNE		loc_1B222
		TYA
		BEQ		loc_1B20F
		BNE		loc_1B222
loc_1B1F9:
		CPY		#$02
		BCS		loc_1B222
		BCC		loc_1B20F
loc_1B1FF:
		CPY		#$03
		BCS		loc_1B222
		LDA		byte_5CA
		CMP		#$02
		BCC		loc_1B20F
loc_1B20A:
		LDX		byte_479
		BEQ		loc_1B222
loc_1B20F:
		LDX		byte_479
		CPX		#$0D
		BCS		loc_1B222
		CPX		#$06
		BCC		loc_1B1D4
		LDA		byte_5EA
		CMP		byte_5EB
		BCC		loc_1B1D4
loc_1B222:
		LDA		#$00
		RTS
; ---------------------------------------------------------------------------
loc_1B225:
		LDA		byte_5C9
		BNE		loc_1B222
		LDA		byte_440
		BNE		loc_1B222
		LDA		byte_5BF
		BEQ		loc_1B241
		LDA		byte_5EA
		CLC
		ADC		#$03
		CMP		byte_5EB
		BCC		loc_1B1D4
		BCS		loc_1B222
loc_1B241:
		LDX		byte_5BE
		BMI		loc_1B222
		CPX		#$0A
		BCS		loc_1B1D4
		BCC		loc_1B222

; =============== S U B	R O U T	I N E =======================================
_cp_sub02:
		JSR		sub_1B578
		JSR		sub_1B2E6
		LDA		byte_5CC
		BMI		loc_1B279
		CMP		#$07
		BCS		loc_1B26F
		CMP		#$04
		BCS		loc_1B268
		CMP		byte_5EB
		BEQ		loc_1B2E3
		BCC		loc_1B2E3
		BCS		loc_1B2E0
loc_1B268:
		CMP		byte_5EB
		BCS		loc_1B2E0
		BCC		loc_1B2E3
loc_1B26F:
		CLC
		ADC		#$01
		CMP		byte_5EB
		BCS		loc_1B2E0
		BCC		loc_1B2E3
loc_1B279:
		LDY		byte_5C9
		LDA		byte_5C8
		BEQ		loc_1B2BE
		CMP		#$03
		BEQ		loc_1B290
		CMP		#$04
		BEQ		loc_1B29D
		CMP		#$05
		BEQ		loc_1B2AA
		JMP		loc_1B2E0
; ---------------------------------------------------------------------------
loc_1B290:
		CPY		#$04
		BCS		loc_1B2E0
		LDA		byte_5CA
		CMP		#$03
		BCS		loc_1B2E3
		BCC		loc_1B2E0
loc_1B29D:
		CPY		#$04
		BCS		loc_1B2E0
		LDA		byte_5CA
		CMP		#$02
		BCS		loc_1B2E3
		BCC		loc_1B2E0
loc_1B2AA:
		CPY		#$03
		BCS		loc_1B2E0
		LDA		byte_5CA
		CMP		#$02
		BCS		loc_1B2E3
		LDA		byte_479
		CMP		#$07
		BCC		loc_1B2E3
		BCS		loc_1B2E0
loc_1B2BE:
		LDA		byte_5C9
		BEQ		loc_1B2C5
		BNE		loc_1B2E0
loc_1B2C5:
		LDA		byte_5BF
		BEQ		loc_1B2D7
		LDA		byte_5EA
		CLC
		ADC		#$02
		CMP		byte_5EB
		BCC		loc_1B2E3
		BCS		loc_1B2E0
loc_1B2D7:
		LDX		byte_5BE
		BMI		loc_1B2E0
		CPX		#$0A
		BCS		loc_1B2E3
loc_1B2E0:
		LDA		#$00
		RTS
; ---------------------------------------------------------------------------
loc_1B2E3:
		LDA		#$01
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_1B2E6:
		LDA		byte_5CC
		AND		#$7F
		STA		byte_5EA
		LDA		byte_5CD
		AND		#$7F
		STA		byte_5EB
		LDA		byte_5CE
		AND		#$7F
		STA		byte_5EC
		LDA		byte_5CF
		AND		#$7F
		STA		byte_5ED
		RTS

; =============== S U B	R O U T	I N E =======================================
_cp_sub00:
		LDY		#$01
		STY		_pause_mode_flag
		JSR		sub_1B51C
		JSR		sub_1B578
		LDA		byte_308
		BEQ		loc_1B31E
		LDA		byte_48
		BEQ		loc_1B360
		JMP		loc_1B446
; ---------------------------------------------------------------------------
loc_1B31E:
		LDA		#$FF
		STA		byte_A4
		STA		byte_A5
		STA		byte_A0
		STA		byte_A1
		LDA		byte_46
		LDY		byte_47
		CPY		byte_46
		BCC		loc_1B333
		TAY
		LDA		byte_47
loc_1B333:
		STA		byte_BD
		LDA		byte_1B4F9-1,Y
		CLC
		ADC		byte_BD
		ASL
		TAY
		LDA		byte_1B4FE,Y
		TAX
		AND		#$1F
		STA		byte_A2
		TXA
		LSR
		LSR
		LSR
		LSR
		LSR
		STA		byte_9E
		LDA		byte_1B4FE+1,Y
		TAX
		AND		#$1F
		STA		byte_A3
		TXA
		LSR
		LSR
		LSR
		LSR
		LSR
		STA		byte_9F
		JMP		loc_1B4EC
; ---------------------------------------------------------------------------
loc_1B360:
		LDA		byte_46
		STA		byte_AB
		LDA		byte_47
		STA		byte_AC
		LDA		#$00
		STA		byte_AF
		STA		byte_B0
		LDA		#$FF
		STA		byte_B1
		STA		byte_B2
		STA		byte_AD
		STA		byte_AE
loc_1B378:
		LDA		#$01
		JSR		sub_99A3
		LDA		byte_AB
		STA		byte_96
		LDX		byte_AF
		LDA		#$01
		JSR		sub_98D9
		BNE		loc_1B3BF
		STX		byte_AF
		LDA		byte_AC
		STA		byte_96
		LDX		byte_B0
		LDA		#$01
		JSR		sub_98D9
		BNE		loc_1B3AC
		STX		byte_B0
		LDA		#$02
		STA		byte_B7
		JSR		sub_1B53A
		INC		byte_B0
		LDA		byte_B0
		CMP		#$19
		BNE		loc_1B378
		BEQ		loc_1B3B3
loc_1B3AC:
		LDA		#$01
		STA		byte_B7
		JSR		sub_1B53A
loc_1B3B3:
		LDA		#$00
		STA		byte_B0
		INC		byte_AF
		LDA		byte_AF
		CMP		#$19
		BNE		loc_1B378
loc_1B3BF:
		LDA		byte_47
		STA		byte_AB
		LDA		byte_46
		STA		byte_AC
		LDA		#$00
		STA		byte_AF
		STA		byte_B0
loc_1B3CD:
		LDA		#$01
		JSR		sub_99A3
		LDA		byte_AB
		STA		byte_96
		LDX		byte_AF
		LDA		#$01
		JSR		sub_98D9
		BNE		loc_1B427
		STX		byte_AF
		LDA		byte_AC
		STA		byte_96
		LDX		byte_B0
		LDA		#$01
		JSR		sub_98D9
		BNE		loc_1B401
		STX		byte_B0
		LDA		#$02
		STA		byte_B7
		JSR		sub_1B53A
		INC		byte_B0
		LDA		byte_B0
		CMP		#$19
		BNE		loc_1B3CD
		BEQ		loc_1B41B
loc_1B401:
		LDA		byte_AA
		BEQ		loc_1B411
		CMP		#$01
		BNE		loc_1B41B
		LDA		byte_9E
		CMP		byte_AB
		BEQ		loc_1B414
		BCS		loc_1B41B
loc_1B411:
		JSR		sub_1B51C
loc_1B414:
		LDA		#$01
		STA		byte_B7
		JSR		sub_1B53A
loc_1B41B:
		LDA		#$00
		STA		byte_B0
		INC		byte_AF
		LDA		byte_AF
		CMP		#$19
		BNE		loc_1B3CD
loc_1B427:
		LDA		byte_A3
		CLC
		ADC		byte_9F
		CMP		byte_A2
		BNE		loc_1B440
		LDA		byte_9E
		LDX		byte_9F
		STX		byte_9E
		STA		byte_9F
		LDA		byte_A2
		LDX		byte_A3
		STX		byte_A2
		STA		byte_A3
loc_1B440:
		JMP		loc_1B4EC
; ---------------------------------------------------------------------------
loc_1B443:
		JMP		loc_1B4EC
; ---------------------------------------------------------------------------
loc_1B446:
		LDA		byte_46
		STA		byte_AB
		STA		byte_AC
		STA		byte_AD
		STA		byte_AE
		LDA		#$00
		STA		byte_AF
		STA		byte_B0
		STA		byte_B1
		STA		byte_B2
loc_1B45A:
		LDA		#$01
		JSR		sub_99A3
		LDA		byte_AB
		STA		byte_96
		LDX		byte_AF
		LDA		#$01
		JSR		sub_98D9
		BNE		loc_1B443
		STX		byte_AF
		LDA		byte_AC
		STA		byte_96
		LDX		byte_B0
		LDA		#$01
		JSR		sub_98D9
		BNE		loc_1B4D4
		STX		byte_B0
		LDA		byte_AD
		STA		byte_96
		LDX		byte_B1
		LDA		#$01
		JSR		sub_98D9
		BNE		loc_1B4BF
		STX		byte_B1
		LDA		byte_AE
		STA		byte_96
		LDX		byte_B2
		LDA		#$01
		JSR		sub_98D9
		BNE		loc_1B4AC
		STX		byte_B2
		LDA		#$04
		STA		byte_B7
		JSR		sub_1B53A
		INC		byte_B2
		LDA		byte_B2
		CMP		#$19
		BNE		loc_1B4E9
		BEQ		loc_1B4B3
loc_1B4AC:
		LDA		#$03
		STA		byte_B7
		JSR		sub_1B53A
loc_1B4B3:
		INC		byte_B1
		LDA		byte_B1
		STA		byte_B2
		CMP		#$19
		BNE		loc_1B4E9
		BEQ		loc_1B4C6
loc_1B4BF:
		LDA		#$02
		STA		byte_B7
		JSR		sub_1B53A
loc_1B4C6:
		INC		byte_B0
		LDA		byte_B0
		STA		byte_B1
		STA		byte_B2
		CMP		#$19
		BNE		loc_1B4E9
		BEQ		loc_1B4DB
loc_1B4D4:
		LDA		#$01
		STA		byte_B7
		JSR		sub_1B53A
loc_1B4DB:
		INC		byte_AF
		LDA		byte_AF
		STA		byte_B0
		STA		byte_B1
		STA		byte_B2
		CMP		#$19
		BEQ		loc_1B4EC
loc_1B4E9:
		JMP		loc_1B45A
; ---------------------------------------------------------------------------
loc_1B4EC:
		LDA		byte_9E
		CMP		byte_46
		BEQ		loc_1B4F6
		LDA		#$01
		STA		byte_49
loc_1B4F6:
		JMP		sub_99C4
; ---------------------------------------------------------------------------
byte_1B4F9:
		.BYTE $FE,$02,$05,$07,$08
byte_1B4FE:
		.BYTE $21,$4C
		.BYTE $33,$71
		.BYTE $21,$8C
		.BYTE $21,$AC
		.BYTE $31,$CC
		.BYTE $4C,$6C
		.BYTE $53,$91
		.BYTE $4C,$AC
		.BYTE $4C,$C1
		.BYTE $6C,$8C
		.BYTE $73,$B1
		.BYTE $6C,$C1
		.BYTE $8C,$AC
		.BYTE $C1,$87
		.BYTE $C1,$A7

; =============== S U B	R O U T	I N E =======================================
sub_1B51C:
		LDX		#$00
		STX		byte_AA
		STX		byte_A6
		STX		byte_A7
		STX		byte_A8
		STX		byte_A9
		DEX
		STX		byte_9E
		STX		byte_9F
		STX		byte_A0
		STX		byte_A1
		STX		byte_A2
		STX		byte_A3
		STX		byte_A4
		STX		byte_A5
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_1B53A:
		JSR		sub_96BC
		LDA		byte_B7
		CMP		byte_AA
		BCC		locret_1B577
		PHP
		JSR		_cp_sub04
		JSR		sub_96BC
		PLP
		BNE		loc_1B55C
		LDX		#$03
loc_1B54F:
		LDA		byte_A6,X
		CMP		byte_B3,X
		BEQ		loc_1B559
		BCS		locret_1B577
		BCC		loc_1B55C
loc_1B559:
		DEX
		BPL		loc_1B54F
loc_1B55C:
		LDY		byte_B7
		STY		byte_AA
		LDX		#$00
loc_1B562:
		LDA		byte_AB,X
		STA		byte_9E,X
		LDA		byte_AF,X
		STA		byte_A2,X
		INX
		DEY
		BNE		loc_1B562
		LDX		#$03
loc_1B570:
		LDA		byte_B3,X
		STA		byte_A6,X
		DEX
		BPL		loc_1B570
locret_1B577:
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_1B578:
		LDA		#$01
		JSR		sub_99A3
		JSR		sub_1B58F
		LDX		#$1E
		LDY		#$00
loc_1B584:
		LDA		byte_5BA,Y
		STA		byte_5D8,Y
		INY
		DEX
		BNE		loc_1B584
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_1B58F:
		JSR		sub_96BC
		JSR		sub_1B5F1
		JSR		sub_1B693
		JSR		sub_1B721
		JSR		sub_1B756
		JSR		sub_1B77D
		JSR		sub_96BC
		JSR		sub_1B869
		JSR		sub_1B8BC
		JSR		sub_1B8EB
		JSR		sub_1B96C
		JSR		sub_1B5B6
		JMP		sub_96BC

; =============== S U B	R O U T	I N E =======================================
sub_1B5B6:
		LDA		#$01
		LDY		byte_5D
loc_1B5BA:
		DEY
		BMI		loc_1B5C0
		ASL
		BCC		loc_1B5BA
loc_1B5C0:
		STA		byte_5B5
		LDY		_cur_player_idx
		LDA		byte_5B3,Y
		STA		byte_5B6
		LDX		#$00
		CMP		byte_5B5
		BEQ		loc_1B5D4
		BCS		loc_1B5D5
loc_1B5D4:
		INX
loc_1B5D5:
		STX		byte_5B8
		INY
		TYA
		AND		#$01
		TAY
		LDA		byte_5B3,Y
		STA		byte_5B7
		LDX		#$00
		CMP		byte_5B5
		BEQ		loc_1B5EC
		BCS		loc_1B5ED
loc_1B5EC:
		INX
loc_1B5ED:
		STX		byte_5B9
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_1B5F1:
		LDA		#$12
		JSR		sub_99A3
		LDA		#$00
		STA		byte_480
		STA		byte_499
		STA		byte_4A0
		STA		byte_4B9
		LDX		#$01
loc_1B606:
		LDA		#$01
		LDY		byte_480,X
		CPY		#$02
		BCS		loc_1B611
		LDA		#$00
loc_1B611:
		STA		byte_480,X
		LDA		#$01
		LDY		byte_4A0,X
		CPY		#$02
		BCS		loc_1B61F
		LDA		#$00
loc_1B61F:
		STA		byte_4A0,X
		INX
		CPX		#$19
		BNE		loc_1B606
		LDA		#$00
		STA		byte_5C4
		STA		byte_5C5
		LDX		#$01
loc_1B631:
		LDA		byte_480,X
		BEQ		loc_1B65F
		LDA		byte_47F,X
		STA		byte_480,X
		BNE		loc_1B64F
		TXA
		TAY
		INY
		INC		byte_480,X
loc_1B644:
		LDA		byte_480,Y
		BEQ		loc_1B64F
		INC		byte_480,X
		INY
		BNE		loc_1B644
loc_1B64F:
		LDA		byte_480,X
		CMP		byte_5C4
		BCC		loc_1B65F
		BEQ		loc_1B65F
		STA		byte_5C4
		STX		byte_5C6
loc_1B65F:
		LDA		byte_4A0,X
		BEQ		loc_1B68D
		LDA		byte_49F,X
		STA		byte_4A0,X
		BNE		loc_1B67D
		TXA
		TAY
		INY
		INC		byte_4A0,X
loc_1B672:
		LDA		byte_4A0,Y
		BEQ		loc_1B67D
		INC		byte_4A0,X
		INY
		BNE		loc_1B672
loc_1B67D:
		LDA		byte_4A0,X
		CMP		byte_5C5
		BCC		loc_1B68D
		BEQ		loc_1B68D
		STA		byte_5C5
		STX		byte_5C7
loc_1B68D:
		INX
		CPX		#$19
		BNE		loc_1B631
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_1B693:
		LDX		#$00
		STX		byte_5BA
		STX		byte_5BB
		STX		byte_5BC
		STX		byte_5BD
loc_1B6A1:
		LDY		byte_440,X
		BEQ		loc_1B6B8
loc_1B6A6:
		LDA		byte_1B6ED,X
		CLC
		ADC		byte_5BA
		STA		byte_5BA
		BCC		loc_1B6B5
		INC		byte_5BB
loc_1B6B5:
		DEY
		BNE		loc_1B6A6
loc_1B6B8:
		LDY		byte_460,X
		BEQ		loc_1B6CF
loc_1B6BD:
		LDA		byte_1B707,X
		CLC
		ADC		byte_5BC
		STA		byte_5BC
		BCC		loc_1B6CC
		INC		byte_5BD
loc_1B6CC:
		DEY
		BNE		loc_1B6BD
loc_1B6CF:
		INX
		CPX		#$19
		BNE		loc_1B6A1
		LDA		byte_5BC
		SEC
		SBC		byte_5BA
		STA		byte_5BE
		LDA		byte_5BD
		SBC		byte_5BB
		LSR
		ROR		byte_5BE
		LSR
		ROR		byte_5BE
		RTS
; ---------------------------------------------------------------------------
byte_1B6ED:
		.BYTE $19,$18,$17,$16,$15,$14,$13,$12,$11,$10,$0F,$0E,$0D,$0C,$0B,$0A
		.BYTE $09,$08,$07,$06,$05,$04,$03,$02,$01,$00
byte_1B707:
		.BYTE $19,$01,$02,$03,$04,$05,$06,$07,$08,$09,$0A,$0B,$0C,$0D,$0E,$0F
		.BYTE $10,$11,$12,$13,$14,$15,$16,$17,$18,$00

; =============== S U B	R O U T	I N E =======================================
sub_1B721:
		LDX		#$00
loc_1B723:
		LDA		byte_440,X
		BNE		loc_1B72B
		INX
		BNE		loc_1B723
loc_1B72B:
		STX		byte_5C0
		LDY		#$00
		LDA		byte_460
		BNE		loc_1B741
		LDY		#$18
loc_1B737:
		LDA		byte_460,Y
		BNE		loc_1B741
		DEY
		BNE		loc_1B737
		LDY		#$19
loc_1B741:
		STY		byte_5C1
		TXA
		BEQ		loc_1B752
		LDX		#$00
		TYA
		BEQ		loc_1B752
		CPY		byte_5C0
		BCS		loc_1B752
		INX
loc_1B752:
		STX		byte_5BF
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_1B756:
		LDX		#$00
		STX		byte_5C2
		STX		byte_5C3
		LDX		#$13
loc_1B760:
		LDA		byte_480,X
		BEQ		loc_1B768
		INC		byte_5C2
loc_1B768:
		INX
		CPX		#$19
		BNE		loc_1B760
		LDX		#$01
loc_1B76F:
		LDA		byte_4A0,X
		BEQ		loc_1B777
		INC		byte_5C3
loc_1B777:
		INX
		CPX		#$07
		BNE		loc_1B76F
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_1B77D:
		LDX		#$00
		STX		byte_5CA
		STX		byte_5CB
		STX		byte_5C8
		STX		byte_5C9
		LDY		byte_5C0
		CPY		#$06
		BCS		loc_1B7F3
		LDA		#$00
loc_1B794:
		CLC
		ADC		byte_440,Y
		INY
		CPY		#$06
		BNE		loc_1B794
		STA		byte_5CB
		LDY		#$05
loc_1B7A2:
		LDA		byte_440,Y
		BNE		loc_1B7AA
		DEY
		BPL		loc_1B7A2
loc_1B7AA:
		INY
		CPY		#$06
		BEQ		loc_1B7B4
		LDA		byte_4A0,Y
		BEQ		loc_1B7AA
loc_1B7B4:
		STY		byte_BF
		LDX		#$00
		STX		byte_BE
loc_1B7BA:
		LDX		#$00
		STX		byte_BD
		LDX		#$06
loc_1B7C0:
		LDA		byte_4A0,Y
		BEQ		loc_1B7C7
		INC		byte_BD
loc_1B7C7:
		INY
		DEX
		BNE		loc_1B7C0
		LDA		byte_BD
		CMP		byte_BE
		BCC		loc_1B7D3
		STA		byte_BE
loc_1B7D3:
		INC		byte_BF
		LDY		byte_BF
		CPY		#$07
		BCC		loc_1B7BA
		LDA		byte_BE
		SEC
		SBC		#$02
		BCC		loc_1B7F3
		STA		byte_5C9
		CMP		#$04
		BNE		loc_1B7F3
		LDA		byte_5C3
		CMP		#$06
		BNE		loc_1B7F3
		INC		byte_5C9
loc_1B7F3:
		LDY		byte_5C1
		BEQ		loc_1B7FE
		CPY		#$14
		BCC		locret_1B868
		BCS		loc_1B805
loc_1B7FE:
		LDA		byte_460
		LDY		#$18
		BNE		loc_1B807
loc_1B805:
		LDA		#$00
loc_1B807:
		CLC
		ADC		byte_460,Y
		DEY
		CPY		#$13
		BNE		loc_1B807
		STA		byte_5CA
		LDY		#$14
loc_1B815:
		LDA		byte_460,Y
		BNE		loc_1B81F
		INY
		CPY		#$19
		BNE		loc_1B815
loc_1B81F:
		DEY
		CPY		#$13
		BEQ		loc_1B829
		LDA		byte_480,Y
		BEQ		loc_1B81F
loc_1B829:
		STY		byte_BF
		LDX		#$00
		STX		byte_BE
loc_1B82F:
		LDX		#$00
		STX		byte_BD
		LDX		#$06
loc_1B835:
		LDA		byte_480,Y
		BEQ		loc_1B83C
		INC		byte_BD
loc_1B83C:
		DEY
		DEX
		BNE		loc_1B835
		LDA		byte_BD
		CMP		byte_BE
		BCC		loc_1B848
		STA		byte_BE
loc_1B848:
		DEC		byte_BF
		LDY		byte_BF
		CPY		#$13
		BCS		loc_1B82F
		LDA		byte_BE
		SEC
		SBC		#$02
		BCC		locret_1B868
		STA		byte_5C8
		CMP		#$04
		BNE		locret_1B868
		LDA		byte_5C2
		CMP		#$06
		BNE		locret_1B868
		INC		byte_5C8
locret_1B868:
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_1B869:
		LDA		byte_440
		LDX		#$06
loc_1B86E:
		CLC
		ADC		byte_440,X
		DEX
		BNE		loc_1B86E
		STA		byte_5D4
		LDA		#$00
		LDX		#$0C
loc_1B87C:
		CLC
		ADC		byte_446,X
		DEX
		BNE		loc_1B87C
		STA		byte_5D2
		LDA		#$0F
		SEC
		SBC		byte_5D4
		SBC		byte_5D2
		STA		byte_5D6
		LDA		byte_460
		LDX		#$06
loc_1B897:
		CLC
		ADC		byte_472,X
		DEX
		BNE		loc_1B897
		STA		byte_5D5
		LDA		#$00
		LDX		#$0C
loc_1B8A5:
		CLC
		ADC		byte_466,X
		DEX
		BNE		loc_1B8A5
		STA		byte_5D3
		LDA		#$0F
		SEC
		SBC		byte_5D5
		SBC		byte_5D3
		STA		byte_5D7
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_1B8BC:
		LDA		byte_441
		CLC
		ADC		byte_442
		ADC		byte_443
		LSR
		CLC
		ADC		byte_5D4
		SEC
		ADC		byte_440
		LSR
		STA		byte_5D0
		LDA		byte_478
		CLC
		ADC		byte_477
		ADC		byte_476
		LSR
		CLC
		ADC		byte_5D5
		SEC
		ADC		byte_460
		LSR
		STA		byte_5D1
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_1B8EB:
		LDA		#$00
		LDY		#$07
loc_1B8EF:
		PHA
		LDA		byte_440,Y
		STA		byte_BD
		PLA
loc_1B8F6:
		DEC		byte_BD
		BMI		loc_1B900
		CLC
		ADC		byte_1B954-7,Y
		BNE		loc_1B8F6
loc_1B900:
		INY
		CPY		#$13
		BNE		loc_1B8EF
		LSR
		LSR
		CLC
		ADC		#$01
		LSR
		STA		byte_5CE
		LDX		byte_5D0
		BEQ		loc_1B91F
		CLC
		ADC		byte_5D0
		ADC		byte_5D4
		ORA		#$80
		STA		byte_5CE
loc_1B91F:
		LDA		#$00
		LDY		#$12
loc_1B923:
		PHA
		LDA		byte_460,Y
		STA		byte_BD
		PLA
loc_1B92A:
		DEC		byte_BD
		BMI		loc_1B934
		CLC
		ADC		byte_1B960-7,Y
		BNE		loc_1B92A
loc_1B934:
		DEY
		CPY		#$06
		BNE		loc_1B923
		LSR
		LSR
		CLC
		ADC		#$01
		LSR
		STA		byte_5CF
		LDX		byte_5D1
		BEQ		locret_1B953
		CLC
		ADC		byte_5D1
		ADC		byte_5D5
		ORA		#$80
		STA		byte_5CF
locret_1B953:
		RTS
; ---------------------------------------------------------------------------
byte_1B954:
		.BYTE $0A,$0A,$09,$09,$08,$08,$06,$06,$05,$05,$04,$04
byte_1B960:
		.BYTE $04,$04,$05,$05,$06,$06,$08,$08,$09,$09,$0A,$0A

; =============== S U B	R O U T	I N E =======================================
sub_1B96C:
		LDA		byte_453
		CLC
		ADC		byte_454
		ADC		byte_455
		STA		byte_BD
		LSR		byte_BD
		CLC
		ADC		byte_BD
		ADC		byte_456
		ADC		byte_457
		SEC
		ADC		byte_458
		LSR
		STA		byte_5CC
		LDX		byte_5CE
		BEQ		loc_1B9A8
		CLC
		ADC		byte_5CE
		PHA
		LDA		byte_5D4
		SEC
		ADC		byte_5D2
		LSR
		STA		byte_BD
		PLA
		CLC
		ADC		byte_BD
		ORA		#$80
		STA		byte_5CC
loc_1B9A8:
		LDA		byte_466
		CLC
		ADC		byte_465
		ADC		byte_464
		STA		byte_BD
		LSR		byte_BD
		CLC
		ADC		byte_BD
		ADC		byte_463
		ADC		byte_462
		SEC
		ADC		byte_461
		LSR
		STA		byte_5CD
		LDX		byte_5CF
		BEQ		locret_1B9E4
		CLC
		ADC		byte_5CF
		PHA
		LDA		byte_5D5
		SEC
		ADC		byte_5D3
		LSR
		STA		byte_BD
		PLA
		CLC
		ADC		byte_BD
		ORA		#$80
		STA		byte_5CD
locret_1B9E4:
		RTS

; =============== S U B	R O U T	I N E =======================================
_cp_sub03_field_and_dice_editor:
		JSR		_apu_play_ctrlA_set02
		LDA		_cur_player_idx
		STA		byte_34D
		PHA
		LDA		byte_327
		PHA
		LDY		#$00
		STY		_cur_player_idx
		STY		byte_327
		STY		byte_34B
		STY		byte_34C
		INY
		STY		byte_34A
		JSR		sub_96C5
loc_1BA06:
		JSR		_spr_clear
		LDA		_pads_held
		AND		#$C0
		ORA		_pad_tmp2
		STA		byte_34E
		LDA		_pads_held
		AND		#$10
		CMP		#$10
		BNE		loc_1BA36
		LDA		byte_34B
		ORA		byte_34C
		BEQ		loc_1BA28
		JSR		_apu_play_ctrlB_set04
		JMP		loc_1BA36
; ---------------------------------------------------------------------------
loc_1BA28:
		JSR		sub_9713
		PLA
		STA		byte_327
		PLA
		STA		_cur_player_idx
		JSR		sub_96C5
		RTS
; ---------------------------------------------------------------------------
loc_1BA36:
		LDA		byte_34E
		BPL		loc_1BAB8
		LSR
		BCC		loc_1BA49
		DEC		byte_46
		BNE		loc_1BA46
		LDA		#$06
		STA		byte_46
loc_1BA46:
		JMP		loc_1BB7E
; ---------------------------------------------------------------------------
loc_1BA49:
		LSR
		BCC		loc_1BA5B
		INC		byte_46
		LDA		byte_46
		CMP		#$07
		BNE		loc_1BA58
		LDA		#$01
		STA		byte_46
loc_1BA58:
		JMP		loc_1BB7E
; ---------------------------------------------------------------------------
loc_1BA5B:
		LSR
		BCC		loc_1BA89
		LDY		byte_34A
		LDA		byte_400,Y
		BNE		loc_1BA69
		JMP		loc_1BB7E
; ---------------------------------------------------------------------------
loc_1BA69:
		CPY		#$00
		BEQ		loc_1BA79
		CPY		#$19
		BEQ		loc_1BA79
		LDA		byte_420,Y
		BEQ		loc_1BA79
		JMP		loc_1BB7E
; ---------------------------------------------------------------------------
loc_1BA79:
		INC		byte_34C
		LDX		byte_34A
		DEC		byte_400,X
		TXA
		JSR		sub_77DA
		JMP		loc_1BB7E
; ---------------------------------------------------------------------------
loc_1BA89:
		LSR
		BCS		loc_1BA8F
		JMP		loc_1BB7E
; ---------------------------------------------------------------------------
loc_1BA8F:
		LDA		byte_34C
		BNE		loc_1BA97
		JMP		loc_1BB7E
; ---------------------------------------------------------------------------
loc_1BA97:
		LDY		byte_34A
		BEQ		loc_1BAA8
		CPY		#$19
		BEQ		loc_1BAA8
		LDA		byte_420,Y
		BEQ		loc_1BAA8
		JMP		loc_1BB7E
; ---------------------------------------------------------------------------
loc_1BAA8:
		DEC		byte_34C
		LDX		byte_34A
		INC		byte_400,X
		TXA
		JSR		sub_77DA
		JMP		loc_1BB7E
; ---------------------------------------------------------------------------
loc_1BAB8:
		ASL
		BPL		loc_1BB36
		LSR
		LSR
		BCC		loc_1BACA
		DEC		byte_47
		BNE		loc_1BAC7
		LDA		#$06
		STA		byte_47
loc_1BAC7:
		JMP		loc_1BB7E
; ---------------------------------------------------------------------------
loc_1BACA:
		LSR
		BCC		loc_1BADC
		INC		byte_47
		LDA		byte_47
		CMP		#$07
		BNE		loc_1BAD9
		LDA		#$01
		STA		byte_47
loc_1BAD9:
		JMP		loc_1BB7E
; ---------------------------------------------------------------------------
loc_1BADC:
		LSR
		BCC		loc_1BB0A
		LDY		byte_34A
		LDA		byte_420,Y
		BNE		loc_1BAEA
		JMP		loc_1BB7E
; ---------------------------------------------------------------------------
loc_1BAEA:
		CPY		#$00
		BEQ		loc_1BAFA
		CPY		#$19
		BEQ		loc_1BAFA
		LDA		byte_400,Y
		BEQ		loc_1BAFA
		JMP		loc_1BB7E
; ---------------------------------------------------------------------------
loc_1BAFA:
		INC		byte_34B
		LDX		byte_34A
		DEC		byte_420,X
		TXA
		JSR		sub_77DA
		JMP		loc_1BB7E
; ---------------------------------------------------------------------------
loc_1BB0A:
		LSR
		BCS		loc_1BB10
		JMP		loc_1BB7E
; ---------------------------------------------------------------------------
loc_1BB10:
		LDA		byte_34B
		BNE		loc_1BB18
		JMP		loc_1BB7E
; ---------------------------------------------------------------------------
loc_1BB18:
		LDY		byte_34A
		BEQ		loc_1BB26
		CPY		#$19
		BEQ		loc_1BB26
		LDA		byte_400,Y
		BNE		loc_1BB7E
loc_1BB26:
		DEC		byte_34B
		LDX		byte_34A
		INC		byte_420,X
		TXA
		JSR		sub_77DA
		JMP		loc_1BB7E
; ---------------------------------------------------------------------------
loc_1BB36:
		LDA		byte_34E
		LSR
		BCC		loc_1BB56
		LDY		byte_34A
		CPY		#$0D
		BCC		loc_1BB4C
		CPY		#$19
		BEQ		loc_1BB7E
		INC		byte_34A
		BNE		loc_1BB7E
loc_1BB4C:
		CPY		#$00
		BEQ		loc_1BB7E
		DEC		byte_34A
		JMP		loc_1BB7E
; ---------------------------------------------------------------------------
loc_1BB56:
		LSR
		BCC		loc_1BB6A
		LDY		byte_34A
		CPY		#$0D
		BCC		loc_1BB65
		DEC		byte_34A
		BNE		loc_1BB7E
loc_1BB65:
		INC		byte_34A
		BNE		loc_1BB7E
loc_1BB6A:
		LSR
		BCC		loc_1BB7B
loc_1BB6D:
		LDA		byte_34A
		EOR		#$FF
		SEC
		ADC		#$19
		STA		byte_34A
		JMP		loc_1BB7E
; ---------------------------------------------------------------------------
loc_1BB7B:
		LSR
		BCS		loc_1BB6D
loc_1BB7E:
		LDA		#$00
		STA		byte_67
		STA		byte_69
		LDA		byte_34D
		STA		byte_6B
		LDA		#$E0
		STA		_spr_buf_pos
		LDA		#$98
		STA		byte_66
		LDA		#$6A
		STA		byte_68
		LDA		byte_46
		CLC
		ADC		#$11
		STA		_spr_lib_idx
		JSR		_spr_lib_insert
		LDA		#$D0
		STA		_spr_buf_pos
		LDA		#$90
		STA		byte_66
		LDA		#$8A
		STA		byte_68
		LDA		byte_47
		CLC
		ADC		#$11
		STA		_spr_lib_idx
		JSR		_spr_lib_insert
		LDA		#$00
		STA		_spr_buf_pos
		LDA		#$00
		STA		byte_6B
		LDA		#$01
		LDY		byte_34A
		JSR		sub_8655
		STX		byte_66
		STY		byte_68
		LDA		_cur_player_idx
		PHA
		LDA		#$20
		STA		_spr_lib_idx
		LDY		byte_34A
		CPY		#$0D
		BCS		loc_1BBD9
		INC		_cur_player_idx
loc_1BBD9:
		JSR		_spr_lib_insert
		PLA
		STA		_cur_player_idx
		LDA		#$00
		JSR		sub_77DA
		INC		_cur_player_idx
		LDA		#$19
		JSR		sub_77DA
		DEC		_cur_player_idx
		JSR		_sync
		JMP		loc_1BA06
