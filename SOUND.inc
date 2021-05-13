
off_C303:
		.WORD sub_CDD6
		.WORD sub_CDC3
		.WORD sub_CE47
		.WORD sub_CDFF
		.WORD sub_CDBD
		.WORD sub_CDB8
		.WORD sub_CDBD
		.WORD sub_CDBD
off_C313:
		.WORD sub_CDDD
		.WORD sub_CDD0
		.WORD sub_CE58
		.WORD sub_CE15
		.WORD nullsub_2
		.WORD nullsub_2
		.WORD nullsub_2
		.WORD nullsub_2
off_C323:
		.WORD sub_CFBA
		.WORD sub_CF6C
		.WORD sub_CE70
		.WORD sub_CF47
		.WORD sub_CF02
		.WORD sub_CEC7
		.WORD sub_CE9D
		.WORD sub_CF54
off_C333:
		.WORD sub_CFD0
		.WORD sub_CF73
		.WORD sub_CE7C
		.WORD sub_CF4E
		.WORD sub_CF0F
		.WORD sub_CED3
		.WORD sub_CEA9
		.WORD sub_CF5B
off_C343:
		.WORD sub_D060
		.WORD sub_D0B5
		.WORD sub_CDBD
		.WORD sub_CDBD
		.WORD sub_CDBD
		.WORD sub_CDBD
		.WORD sub_D014
		.WORD sub_CFDD
off_C353:
		.WORD sub_D0E4
		.WORD sub_D0E4
		.WORD nullsub_2
		.WORD nullsub_2
		.WORD nullsub_2
		.WORD nullsub_2
		.WORD sub_D01B
		.WORD sub_CFE4
byte_C363:
		.BYTE $10,$7F,$00,$00
byte_C367:
		.BYTE $1F,$7F,$04,$28
byte_C36B:
		.BYTE $1F,$7F,$02,$18
byte_C36F:
		.BYTE $1F,$7F,$03,$20
byte_C373:
		.BYTE $98,$7F,$60,$80
byte_C377:
		.BYTE $99,$7F,$68,$80
byte_C37B:
		.BYTE $9A,$7F,$80,$80
byte_C37F:
		.BYTE $96,$7F,$80,$80
byte_C383:
		.BYTE $97,$7F,$88,$80
byte_C387:
		.BYTE $98,$7F,$A0,$80
byte_C38B:
		.BYTE $DF,$DB,$70,$80
byte_C38F:
		.BYTE $9A,$7F,$B0,$18
byte_C393:
		.BYTE $9B,$7F,$90,$18
byte_C397:
		.BYTE $00,$7F,$00,$00
byte_C39B:
		.BYTE $5F,$7F,$C0,$AB
byte_C39F:
		.BYTE $5F,$7F,$C9,$AB
byte_C3A3:
		.BYTE $88,$7F,$AB,$48
byte_C3A7:
		.BYTE $88,$7F,$D4,$48
byte_C3AB:
		.BYTE $88,$7F,$9F,$48
byte_C3AF:
		.BYTE $88,$7F,$8D,$48
byte_C3B3:
		.BYTE $88,$7F,$69,$48
byte_C3B7:
		.BYTE $95,$9B,$D0,$43
byte_C3BB:
		.BYTE $95,$9B,$E0,$43
byte_C3BF:
		.BYTE $94,$7F,$85,$80
byte_C3C3:
		.BYTE $95,$7F,$70,$18
byte_C3C7:
		.BYTE $07,$7F,$86,$08
byte_C3CB:
		.BYTE $07,$7F,$90,$08
byte_C3CF:
		.BYTE $9A,$7F,$53,$48
byte_C3D3:
		.BYTE $9A,$7F,$69,$48
byte_C3D7:
		.BYTE $9A,$7F,$53,$48
byte_C3DB:
		.BYTE $07,$7F,$00,$00
byte_C3DF:
		.BYTE $07,$7F,$50,$08
byte_C3E3:
		.BYTE $07,$7F,$4D,$08
byte_C3E7:
		.BYTE $07,$7F,$40,$08
byte_C3EB:
		.BYTE $07,$7F,$4A,$08
byte_C3EF:
		.BYTE $07,$7F,$3D,$08
;_unref_C3F3
;		.BYTE $07,$7F,$3D,$08

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

; =============== S U B	R O U T	I N E =======================================
_apu_play:
		JSR		sub_C499
		JSR		sub_CD27
		LDA		#$00
		STA		_apu_play_ctrlA
		STA		_apu_play_ctrlB
		STA		_apu_play_ctrlC
		STA		_apu_play_ctrlE
		STA		_apu_play_ctrlD
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_C41B:
		JSR		sub_C421
		JMP		sub_C431

; =============== S U B	R O U T	I N E =======================================
sub_C421:
		LDA		byte_775
		LSR
		BCS		sub_C467

; =============== S U B	R O U T	I N E =======================================
sub_C427:
		LSR
		BCS		sub_C45B

; =============== S U B	R O U T	I N E =======================================
sub_C42A:
		LSR
		BCS		sub_C44F

; =============== S U B	R O U T	I N E =======================================
sub_C42D:
		LSR
		BCS		sub_C443

; =============== S U B	R O U T	I N E =======================================
sub_C430:
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_C431:
		LDA		#$00
		STA		byte_78E
		STA		byte_78F
		STA		byte_790
		STA		byte_791
		STA		byte_792
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_C443:
		LDX		#$10
		STX		$4000
		LDX		#$7F
		STX		$4001
		BNE		sub_C430

; =============== S U B	R O U T	I N E =======================================
sub_C44F:
		LDX		#$10
		STX		$4004
		LDX		#$7F
		STX		$4005
		BNE		sub_C42D

; =============== S U B	R O U T	I N E =======================================
sub_C45B:
		LDX		#$00
		STX		$4008
		LDX		#$18
		STX		$400B
		BNE		sub_C42A

; =============== S U B	R O U T	I N E =======================================
sub_C467:
		LDX		#$10
		STX		$400C
		LDX		#$00
		STX		$400F
		BEQ		sub_C427

; =============== S U B	R O U T	I N E =======================================
sub_C473:
		LDA		byte_775
		BEQ		locret_C480
		JSR		sub_C41B
		LDA		#$00
		STA		byte_775
locret_C480:
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_C481:
		JSR		sub_C41B
		JSR		sub_C60A
		JSR		sub_C60E
		JSR		sub_C7AC
		JSR		sub_C830
		JMP		sub_C890

; =============== S U B	R O U T	I N E =======================================
_unref_0:
		LDA		#$00
		STA		byte_775
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_C499:
		LDA		_apu_play_ctrlA
		LSR
		BCS		sub_C481
		LSR
		BCS		sub_C473
		LDA		_apu_play_ctrlD
		BNE		loc_C4D4
		LDA		_apu_play_ctrlE
		BNE		loc_C4D9
		JSR		sub_D19B
		JSR		sub_C589
		JSR		sub_C6A8
		JSR		sub_C63B
		JSR		sub_C58D
		JSR		sub_C6B2
		JSR		sub_C645
		JSR		sub_C754
		JSR		sub_C6BC
		JSR		sub_C7D7
		JSR		sub_C7F1
		JSR		sub_C83C
		JSR		sub_C8C5
		RTS
; ---------------------------------------------------------------------------
loc_C4D4:
		LDX		#$00
		JMP		loc_C4DE
; ---------------------------------------------------------------------------
loc_C4D9:
		LDX		#$08
		JMP		loc_C4DE
loc_C4DE:
		LDY		#$00
		STY		byte_795
		STY		byte_793
		STY		byte_794
		LSR
		BCS		loc_C4EF
		INX
		BNE		loc_C4DE
loc_C4EF:
		TXA
		STA		byte_774
		ASL
		TAX
		LDA		off_D233,X
		STA		byte_EA
		LDA		off_D233+1,X
		STA		byte_EB
		LDY		#$00
loc_C501:
		LDA		(byte_EA),Y
		STA		byte_C0,Y
		CMP		#$00
		BEQ		loc_C549
loc_C50A:
		INY
		CPY		#$0A
		BNE		loc_C501
		LDA		(byte_EA),Y
		STA		byte_734
		LDA		#$00
		STA		byte_735
		STA		byte_721
		STA		byte_723
		STA		byte_725
		STA		byte_727
		STA		byte_729
		STA		byte_76A
		STA		byte_76C
		STA		byte_76E
		STA		byte_772
		LDA		#$01
		STA		byte_720
		STA		byte_722
		STA		byte_724
		STA		byte_726
		STA		byte_728
		JSR		sub_CA66
		RTS
; ---------------------------------------------------------------------------
loc_C549:
		CPY		#$00
		BEQ		loc_C55B
		CPY		#$02
		BEQ		loc_C567
		CPY		#$04
		BEQ		loc_C573
		CPY		#$08
		BEQ		loc_C57F
		BNE		loc_C50A
loc_C55B:
		LDA		#$10
		STA		$4000
		LDA		#$7F
		STA		$4001
		BNE		loc_C50A
loc_C567:
		LDA		#$10
		STA		$4004
		LDA		#$7F
		STA		$4005
		BNE		loc_C50A
loc_C573:
		LDA		#$00
		STA		$4008
		LDA		#$18
		STA		$400B
		BNE		loc_C50A
loc_C57F:
		LDA		#$80
		STA		$4080
		STA		$4084
		BNE		loc_C50A

; =============== S U B	R O U T	I N E =======================================
sub_C589:
		LDX		#$00
		BEQ		sub_C58F

; =============== S U B	R O U T	I N E =======================================
sub_C58D:
		LDX		#$02

; =============== S U B	R O U T	I N E =======================================
sub_C58F:
		LDA		byte_C1,X
		BEQ		locret_C609
		JSR		sub_C8F5
		BPL		locret_C609
		JSR		loc_C96C
		BCS		sub_C610
		STA		byte_EC
		CPX		#$00
		BNE		loc_C5AE
		LDA		byte_775
		LSR
		LSR
		LSR
		LSR
		BCS		sub_C624
		BCC		loc_C5B6
loc_C5AE:
		LDA		byte_775
		LSR
		LSR
		LSR
		BCS		sub_C624
loc_C5B6:
		LDA		byte_EC
		CMP		#$7F
		BEQ		sub_C616
		CLC
		ADC		byte_76A,X
		ASL
		TAY
		LDA		byte_CB9F,Y
		ORA		byte_736,X
		STA		byte_749,X
		STA		byte_E9
		LDA		byte_CB9F+1,Y
		STA		byte_748,X
		STA		byte_E8
		TXA
		ASL
		TAY
		LDA		byte_73A,X
		STA		$4001,Y
		LDA		byte_E8
		STA		$4002,Y
		LDA		byte_E9
		STA		$4003,Y
		LDA		#$00
		STA		byte_776
		LDA		#$00
		STA		byte_74F,X
		STA		byte_754,X
		LDA		byte_D1,X
		STA		byte_74E,X
		LDA		byte_CB,X
		BNE		sub_C62D
		LDA		byte_737,X
		STA		$4000,Y
		LDA		#$00
		STA		byte_73E,X
locret_C609:
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_C60A:
		LDX		#$00
		BEQ		sub_C610

; =============== S U B	R O U T	I N E =======================================
sub_C60E:
		LDX		#$02

; =============== S U B	R O U T	I N E =======================================
sub_C610:
		LDA		#$00
		STA		byte_C0,X
		STA		byte_C1,X

; =============== S U B	R O U T	I N E =======================================
sub_C616:
		LDA		#$10
		CPX		#$00
		BNE		loc_C621
		STA		$4000
		BEQ		sub_C624
loc_C621:
		STA		$4004

; =============== S U B	R O U T	I N E =======================================
sub_C624:
		LDA		#$00
		STA		byte_73E,X
		STA		byte_74E,X
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_C62D:
		LDA		#$00
		STA		byte_73F,X
		STA		byte_744,X
		LDA		#$01
		STA		byte_73E,X
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_C63B:
		LDX		#$00
		LDY		byte_73F,X
		LDA		(byte_CA),Y
		JMP		sub_C64C

; =============== S U B	R O U T	I N E =======================================
sub_C645:
		LDX		#$02
		LDY		byte_73F,X
		LDA		(byte_CC),Y

; =============== S U B	R O U T	I N E =======================================
sub_C64C:
		LDY		byte_73E,X
		BEQ		locret_C69E
		STA		byte_EC
		CMP		#$FF
		BEQ		loc_C67C
		DEC		byte_744,X
		BPL		loc_C67C
		LSR
		LSR
		LSR
		LSR
		TAY
		LDA		byte_D24F,Y
		STA		byte_744,X
		LDA		byte_EC
		AND		#$0F
		STA		byte_EC
		LDA		byte_737,X
		AND		#$C0
		ORA		#$30
		ORA		byte_EC
		STA		byte_745,X
		INC		byte_73F,X
loc_C67C:
		CPX		#$00
		BNE		loc_C690
		LDA		byte_775
		LSR
		LSR
		LSR
		LSR
		BCS		loc_C69F
		LDA		byte_745,X
		STA		$4000
		RTS
; ---------------------------------------------------------------------------
loc_C690:
		LDA		byte_775
		LSR
		LSR
		LSR
		BCS		loc_C69F
		LDA		byte_745,X
		STA		$4004
locret_C69E:
		RTS
; ---------------------------------------------------------------------------
loc_C69F:
		LDA		#$00
		STA		byte_73E,X
		STA		byte_74E,X
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_C6A8:
		LDX		#$00
		LDY		byte_74F,X
		LDA		(byte_D0),Y
		JMP		sub_C6C3

; =============== S U B	R O U T	I N E =======================================
sub_C6B2:
		LDX		#$02
		LDY		byte_74F,X
		LDA		(byte_D2),Y
		JMP		sub_C6C3

; =============== S U B	R O U T	I N E =======================================
sub_C6BC:
		LDX		#$04
		LDY		byte_74F,X
		LDA		(byte_D4),Y

; =============== S U B	R O U T	I N E =======================================
sub_C6C3:
		LDY		byte_74E,X
		BEQ		locret_C69E
		STA		byte_EC
		CMP		#$F8
		BEQ		locret_C72A
		CMP		#$E8
		BNE		loc_C6E4
		LDA		#$00
		STA		byte_74F,X
		STA		byte_754,X
		CPX		#$00
		BEQ		sub_C6A8
		CPX		#$02
		BEQ		sub_C6B2
		BNE		sub_C6BC
loc_C6E4:
		DEC		byte_754,X
		BPL		locret_C72A
		INC		byte_74F,X
		LSR
		LSR
		LSR
		LSR
		LSR
		TAY
		LDA		byte_D264,Y
		STA		byte_754,X
		LDA		byte_EC
		AND		#$1F
		ASL
		STA		byte_755,X
		LDY		byte_755,X
		LDA		byte_748,X
		CLC
		ADC		byte_D26D,Y
		STA		byte_E8
		LDA		byte_749,X
		ADC		byte_D26E,Y
		STA		byte_E9
		CPX		#$04
		BEQ		loc_C739
		CPX		#$02
		BEQ		loc_C72B
		LDA		byte_775
		LSR
		LSR
		LSR
		LSR
		BCS		loc_C74B
		LDA		byte_E8
		STA		$4002
locret_C72A:
		RTS
; ---------------------------------------------------------------------------
loc_C72B:
		LDA		byte_775
		LSR
		LSR
		LSR
		BCS		loc_C74B
		LDA		byte_E8
		STA		$4006
		RTS
; ---------------------------------------------------------------------------
loc_C739:
		LDA		byte_775
		LSR
		LSR
		BCS		locret_C72A
		LDA		byte_E8
		STA		$400A
		LDA		byte_E9
		STA		$400B
		RTS
; ---------------------------------------------------------------------------
loc_C74B:
		LDA		#$00
		STA		byte_73E,X
		STA		byte_74E,X
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_C754:
		LDA		byte_C5
		BEQ		locret_C7AB
		LDX		#$04
		JSR		sub_C8F5
		BPL		locret_C7AB
		JSR		loc_C96C
		BCS		sub_C7AC
		STA		byte_EC
		LDA		byte_775
		LSR
		LSR
		BCS		locret_C7AB
		LDA		byte_EC
		CMP		#$7F
		BEQ		sub_C7B2
		CLC
		ADC		byte_76A,X
		ASL
		TAY
		LDA		byte_CB9F,Y
		STA		byte_74D
		ORA		byte_75B
		STA		$400B
		LDA		byte_CB9F+1,Y
		STA		byte_74C
		STA		$400A
		LDA		#$00
		STA		byte_74F,X
		STA		byte_754,X
		LDA		byte_D1,X
		STA		byte_74E,X
		LDA		byte_75C
		BNE		sub_C7BE
		LDA		byte_75A
		STA		$4008
		LDA		#$00
		STA		byte_742
locret_C7AB:
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_C7AC:
		LDA		#$00
		STA		byte_C4
		STA		byte_C5

; =============== S U B	R O U T	I N E =======================================
sub_C7B2:
		LDA		#$00
		STA		$4008
		STA		byte_742
		STA		byte_752
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_C7BE:
		LDA		#$01
		STA		byte_742
		LDA		byte_75C
		STA		byte_743
		LDA		#$BF
		STA		$4008
		LDA		byte_74D
		ORA		#$08
		STA		$400B
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_C7D7:
		LDA		byte_742
		BEQ		locret_C7F0
		DEC		byte_743
		BNE		locret_C7F0
		LDA		byte_775
		LSR
		LSR
		BCS		locret_C7F0
		LDA		#$00
		STA		$4008
		STA		byte_742
locret_C7F0:
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_C7F1:
		LDA		byte_C7
		BEQ		sub_C83B
		LDX		#$06
		JSR		sub_C8F5
		BPL		sub_C83B
		JSR		loc_C96C
		BCS		sub_C830
		STA		byte_EC
		LDA		byte_775
		LSR
		BCS		sub_C83B
		LDA		byte_EC
		CMP		#$7F
		BEQ		sub_C836
		CMP		#$00
		BEQ		loc_C81D
		TAX
loc_C814:
		CMP		#$03
		BEQ		loc_C81D
		SEC
		SBC		#$03
		BCS		loc_C814
loc_C81D:
		LDA		byte_D343,X
		STA		$400C
		LDA		byte_D344,X
		STA		$400E
		LDA		byte_D345,X
		STA		$400F
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_C830:
		LDA		#$00
		STA		byte_C6
		STA		byte_C7

; =============== S U B	R O U T	I N E =======================================
sub_C836:
		LDA		#$10
		STA		$400C

; =============== S U B	R O U T	I N E =======================================
sub_C83B:
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_C83C:
		LDA		byte_C9
		BEQ		nullsub_6
		LDX		#$08
		JSR		sub_C8F5
		BPL		nullsub_6
		JSR		loc_C96C
		BCS		sub_C890
		CMP		#$7F
		BEQ		sub_C896
		JSR		sub_C8A4
		LDA		byte_ED
		CLC
		ADC		byte_76A,X
		ASL
		TAY
		LDA		byte_CC1F,Y
		STA		$4083
		LDA		byte_CC1F+1,Y
		STA		$4082
		LDA		byte_768
		BPL		loc_C882
		LDA		byte_761
		ORA		#$80
		STA		$4080
		LDA		byte_762
		BMI		loc_C87C
		STA		$4080
loc_C87C:
		LDA		#$00
		STA		byte_75D
		RTS
; ---------------------------------------------------------------------------
loc_C882:
		LDA		#$00
		STA		byte_75E
		STA		byte_75F
		LDA		#$01
		STA		byte_75D
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_C890:
		LDA		#$00
		STA		byte_C8
		STA		byte_C9

; =============== S U B	R O U T	I N E =======================================
sub_C896:
		LDA		#$80
		STA		$4080
		STA		$4084
		LDA		#$00
		STA		byte_75D
nullsub_6:
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_C8A4:
		LDA		byte_766
		STA		$4086
		LDA		byte_767
		STA		$4087
		LDA		byte_765
		STA		$4085
		LDA		byte_763
		ORA		#$80
		STA		$4084
		LDA		byte_764
		STA		$4084
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_C8C5:
		LDA		byte_75D
		BEQ		locret_C8F4
		LDY		byte_75E
		CPY		#$3F
		BEQ		loc_C8EC
		LDA		(byte_CE),Y
		STA		byte_EC
		CMP		#$FF
		BEQ		loc_C8EC
		DEC		byte_75F
		BPL		loc_C8EC
		LDA		byte_768
		STA		byte_75F
		LDA		byte_EC
		STA		byte_760
		INC		byte_75E
loc_C8EC:
		LDA		byte_760
		ORA		#$80
		STA		$4080
locret_C8F4:
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_C8F5:
		LDA		byte_720,X
		SEC
		SBC		byte_734
		STA		byte_720,X
		LDA		byte_721,X
		SBC		byte_735
		STA		byte_721,X
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_C909:
		LDA		byte_72A,X
		CLC
		ADC		byte_720,X
		STA		byte_720,X
		LDA		byte_72B,X
		ADC		byte_721,X
		STA		byte_721,X
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_C91D:
		CMP		#$7E
		BNE		loc_C928
		INY
		JSR		sub_C909
		JMP		loc_C976
; ---------------------------------------------------------------------------
loc_C928:
		JSR		sub_C909
		TYA
		SEC
		ADC		byte_EA
		STA		byte_C0,X
		LDA		byte_EB
		ADC		#$00
		STA		byte_C1,X
		LDA		byte_ED
		CLC
		RTS
; ---------------------------------------------------------------------------
loc_C93B:
		CMP		#$BF
		BEQ		loc_C95A
		CMP		#$BE
		BEQ		loc_C963
		STY		byte_EE
		AND		#$1F
		ASL
		TAY
		LDA		byte_CB75,Y
		STA		byte_72A,X
		LDA		byte_CB75+1,Y
		STA		byte_72B,X
		LDY		byte_EE
		JMP		loc_C976
; ---------------------------------------------------------------------------
loc_C95A:
		LDA		(byte_EA),Y
		STA		byte_734
		INY
		JMP		loc_C976
; ---------------------------------------------------------------------------
loc_C963:
		LDA		(byte_EA),Y
		STA		byte_76A,X
		INY
		JMP		loc_C976
; ---------------------------------------------------------------------------
loc_C96C:
		LDA		byte_C0,X
		STA		byte_EA
		LDA		byte_C1,X
		STA		byte_EB
		LDY		#$00
loc_C976:
		LDA		(byte_EA),Y
		STA		byte_ED
		BPL		sub_C91D
		INY
		CMP		#$C0
		BCC		loc_C93B
		CMP		#$E0
		BCS		loc_C990
		JMP		sub_CA80
; ---------------------------------------------------------------------------
loc_C988:
		LDA		#$00
		STA		byte_C1,X
		STA		byte_C0,X
		SEC
		RTS
; ---------------------------------------------------------------------------
loc_C990:
		STY		byte_EE
		CMP		#$FF
		BEQ		loc_C988
		CMP		#$FC
		BEQ		loc_CA0D
		CMP		#$EF
		BEQ		loc_C9C9
		CMP		#$FD
		BEQ		loc_C9ED
		CMP		#$FE
		BEQ		loc_CA1F
		LDY		byte_796,X
		AND		#$0F
		STA		byte_7A0,Y
		LDA		byte_EE
		STA		byte_7A1,Y
		LDA		byte_EA
		STA		byte_7A2,Y
		LDA		byte_EB
		STA		byte_7A3,Y
		JSR		sub_CA3E
loc_C9C0:
		TYA
		STA		byte_796,X
loc_C9C4:
		LDY		byte_EE
		JMP		loc_C976
; ---------------------------------------------------------------------------
loc_C9C9:
		LDY		byte_796,X
		JSR		sub_CA4E
		BCS		loc_C9C4
		LDA		byte_7A0,Y
		SEC
		SBC		#$01
		STA		byte_7A0,Y
		BEQ		loc_C9C0
		LDA		byte_7A2,Y
		STA		byte_EA
		LDA		byte_7A3,Y
		STA		byte_EB
		LDA		byte_7A1,Y
		TAY
		JMP		loc_C976
; ---------------------------------------------------------------------------
loc_C9ED:
		LDY		byte_796,X
		LDA		#$FF
		STA		byte_7A0,Y
		LDA		byte_EE
		STA		byte_7A1,Y
		LDA		byte_EA
		STA		byte_7A2,Y
		LDA		byte_EB
		STA		byte_7A3,Y
		JSR		sub_CA3E
		TYA
		STA		byte_796,X
		LDY		byte_EE
loc_CA0D:
		LDA		(byte_EA),Y
		STA		byte_EC
		INY
		LDA		(byte_EA),Y
		STA		byte_EB
		LDA		byte_EC
		STA		byte_EA
		LDY		#$00
		JMP		loc_C976
; ---------------------------------------------------------------------------
loc_CA1F:
		LDY		byte_796,X
		JSR		sub_CA4E
		BCS		loc_C9C4
		TYA
		STA		byte_796,X
		LDA		byte_7A2,Y
		STA		byte_EA
		LDA		byte_7A3,Y
		STA		byte_EB
		LDA		byte_7A1,Y
		TAY
		INY
		INY
		JMP		loc_C976

; =============== S U B	R O U T	I N E =======================================
sub_CA3E:
		TYA
		AND		#$F0
		STA		byte_EC
		INY
		INY
		INY
		INY
		TYA
		AND		#$0F
		ORA		byte_EC
		TAY
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_CA4E:
		TYA
		AND		#$F0
		STA		byte_EC
		TYA
		AND		#$0F
		BEQ		loc_CA64
		DEY
		DEY
		DEY
		DEY
		TYA
		AND		#$0F
		ORA		byte_EC
		TAY
		CLC
		RTS
; ---------------------------------------------------------------------------
loc_CA64:
		SEC
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_CA66:
		LDA		#$00
		STA		byte_796
		LDA		#$10
		STA		byte_798
		LDA		#$20
		STA		byte_79A
		LDA		#$30
		STA		byte_79C
		LDA		#$40
		STA		byte_79E
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_CA80:
		LDA		(byte_EA),Y
		STA		byte_E8
		INY
		LDA		(byte_EA),Y
		STA		byte_E9
		INY
		LDA		byte_ED
		CMP		#$C0
		BEQ		loc_CAA3
		CMP		#$C1
		BEQ		loc_CAA3
		CMP		#$C2
		BEQ		loc_CAD1
		CMP		#$C3
		BEQ		loc_CAF5
		CMP		#$C4
		BEQ		loc_CB02
		JMP		loc_C976
; ---------------------------------------------------------------------------
loc_CAA3:
		STY		byte_EE
		LDY		#$00
		LDA		(byte_E8),Y
		STA		byte_737,X
		INY
		LDA		(byte_E8),Y
		STA		byte_73A,X
		INY
		LDA		(byte_E8),Y
		STA		byte_736,X
		INY
		LDA		(byte_E8),Y
		STA		byte_CA,X
		INY
		LDA		(byte_E8),Y
		STA		byte_CB,X
		INY
		LDA		(byte_E8),Y
		STA		byte_D0,X
		INY
		LDA		(byte_E8),Y
		STA		byte_D1,X
		LDY		byte_EE
		JMP		loc_C976
; ---------------------------------------------------------------------------
loc_CAD1:
		STY		byte_EE
		LDY		#$00
		LDA		(byte_E8),Y
		STA		byte_75A
		INY
		LDA		(byte_E8),Y
		STA		byte_75B
		INY
		LDA		(byte_E8),Y
		STA		byte_75C
		INY
		LDA		(byte_E8),Y
		STA		byte_D4
		INY
		LDA		(byte_E8),Y
		STA		byte_D5
		LDY		byte_EE
		JMP		loc_C976
; ---------------------------------------------------------------------------
loc_CAF5:
		LDA		byte_E8
		STA		byte_769
		LDA		byte_E9
		STA		byte_76A
		JMP		loc_C976
; ---------------------------------------------------------------------------
loc_CB02:
		STY		byte_EE
		STX		byte_EF
		LDY		#$00
		LDX		#$07
loc_CB0A:
		LDA		(byte_E8),Y
		STA		byte_761,Y
		INY
		DEX
		BNE		loc_CB0A
		LDA		(byte_E8),Y
		STA		byte_768
		INY
		CMP		#$FF
		BEQ		loc_CB2E
		TYA
		CLC
		ADC		byte_E8
		STA		byte_CE
		LDA		#$00
		ADC		byte_E9
		STA		byte_CF
		TYA
		CLC
		ADC		#$40
		TAY
loc_CB2E:
		JSR		sub_CB3B
		JSR		sub_CB5D
		LDX		byte_EF
		LDY		byte_EE
		JMP		loc_C976

; =============== S U B	R O U T	I N E =======================================
sub_CB3B:
		LDA		#$81
		STA		$4089
		LDX		#$00
		LDY		#$00
		LDA		#>[byte_D392]
		STA		word_E0+1
		LDA		#<[byte_D392]
		STA		word_E0
loc_CB4C:
		LDA		(word_E0),Y
		STA		$4040,X
		INY
		INX
		CPX		#$40
		BNE		loc_CB4C
		LDA		#$00
		STA		$4089
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_CB5D:
		LDA		#$80
		STA		$4087
		LDX		#$00
loc_CB64:
		LDA		#$00
		STA		$4088
		INY
		INX
		CPX		#$20
		BNE		loc_CB64
		LDA		#$00
		STA		$4087
		RTS
; ---------------------------------------------------------------------------
byte_CB75:
		.BYTE $00,$06,$00,$03,$80,$01,$C0,$00,$60,$00,$30,$00,$18,$00,$00,$09
		.BYTE $80,$04,$40,$02,$20,$01,$90,$00,$48,$00,$00,$04,$00,$02,$00,$01
		.BYTE $80,$00,$40,$00,$20,$00,$38,$00,$30,$00
byte_CB9F:
		.BYTE $0F,$FF,$06,$AE,$06,$4E,$05,$F3,$05,$9E,$05,$4D,$05,$01,$04,$B9
		.BYTE $04,$75,$04,$35,$03,$F8,$03,$BF,$03,$89,$03,$57,$03,$27,$02,$F9
		.BYTE $02,$CF,$02,$A6,$02,$80,$02,$5C,$02,$3A,$02,$1A,$01,$FC,$01,$DF
		.BYTE $01,$C4,$01,$AB,$01,$93,$01,$7C,$01,$67,$01,$52,$01,$3F,$01,$2D
		.BYTE $01,$1C,$01,$0C,$00,$FD,$00,$EE,$00,$E1,$00,$D4,$00,$C8,$00,$BD
		.BYTE $00,$B2,$00,$A8,$00,$9F,$00,$96,$00,$8D,$00,$85,$00,$7E,$00,$76
		.BYTE $00,$70,$00,$69,$00,$63,$00,$5D,$00,$58,$00,$53,$00,$4F,$00,$4A
		.BYTE $00,$46,$00,$42,$00,$3E,$00,$3A,$00,$37,$00,$34,$00,$31,$00,$2E
byte_CC1F:
		.BYTE $00,$00,$00,$99,$00,$A2,$00,$AC,$00,$B6,$00,$C1,$00,$CC,$00,$D8
		.BYTE $00,$E5,$00,$F3,$01,$01,$01,$11,$01,$21,$01,$32,$01,$44,$01,$58
		.BYTE $01,$6C,$01,$82,$01,$99,$01,$B1,$01,$CB,$01,$E6,$02,$03,$02,$22
		.BYTE $02,$42,$02,$65,$02,$89,$02,$B0,$02,$D9,$03,$04,$03,$32,$03,$63
		.BYTE $03,$96,$03,$CD,$04,$07,$04,$44,$04,$85,$04,$CA,$05,$13,$05,$60
		.BYTE $05,$B2,$06,$08,$06,$64,$06,$C6,$07,$2D,$07,$9A,$08,$0E,$08,$88
		.BYTE $09,$0A,$09,$95,$0A,$26,$0A,$C0,$0B,$64,$0C,$11,$0C,$C9,$0D,$8C
		.BYTE $0E,$5A,$0F,$35

; =============== S U B	R O U T	I N E =======================================
sub_CC93:
		LDX		byte_D7
		STA		byte_777,X
		TXA
		BEQ		loc_CCB2
		CMP		#$00
		BEQ		loc_CCB2
		CMP		#$01
		BEQ		loc_CCA8
		CMP		#$02
		BEQ		loc_CCAD
		RTS
; ---------------------------------------------------------------------------
loc_CCA8:
		JSR		sub_CCC4
		BEQ		loc_CCB5
loc_CCAD:
		JSR		sub_CCC8
		BEQ		loc_CCB5
loc_CCB2:
		JSR		sub_CCCC
loc_CCB5:
		JSR		loc_CD92
		LDA		#$00
		STA		byte_77A,X
		STA		byte_77D,X
		STA		byte_780,X
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_CCC4:
		LDA		#$00
		BEQ		sub_CCD2

; =============== S U B	R O U T	I N E =======================================
sub_CCC8:
		LDA		#$08
		BNE		sub_CCD2

; =============== S U B	R O U T	I N E =======================================
sub_CCCC:
		LDA		#$0C
		BNE		sub_CCD2

; =============== S U B	R O U T	I N E =======================================
sub_CCD0:
		LDA		#$04

; !FALLTHROUGH!

; =============== S U B	R O U T	I N E =======================================
sub_CCD2:
		STA		word_E2
		LDA		#$40
		STA		word_E2+1
		STY		word_E4
		LDA		#>[byte_C363]
		STA		word_E4+1
		LDY		#$00
loc_CCE0:
		LDA		(word_E4),Y
		STA		(word_E2),Y
		INY
		TYA
		CMP		#$04
		BNE		loc_CCE0
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_CCEB:
		STA		byte_D8
		PHA
		STX		word_E2
		LDY		#>[off_C303]
		STY		word_E2+1
		LDY		#$00
loc_CCF6:
		ASL		byte_D8
		BCS		sub_CD0D
		INY
		INY
		TYA
		CMP		#$10
		BNE		loc_CCF6
		LDA		#<[nullsub_2]
		STA		word_E4
		LDA		#>[nullsub_2]
		STA		word_E4+1
loc_CD09:
		PLA
		STA		byte_D8
nullsub_2:
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_CD0D:
		LDA		(word_E2),Y
		STA		word_E4
		INY
		LDA		(word_E2),Y
		STA		word_E4+1
		JMP		loc_CD09
; ---------------------------------------------------------------------------
byte_CD19:
		.BYTE $DB,$D9,$D7,$D5,$D3,$D2,$00
byte_CD20:
		.BYTE $68,$63,$60,$58,$50,$48,$40

; =============== S U B	R O U T	I N E =======================================
sub_CD27:
		JSR		sub_CD31
		JSR		sub_CD52
		JMP		sub_CD75

; =============== S U B	R O U T	I N E =======================================
sub_CD31:
		LDX		#$00
		STX		byte_D7
		LDA		_apu_play_ctrlA
		BEQ		loc_CD44
		LDX		#$01
		STX		byte_775
		LDX		#<[off_C303]
		BNE		loc_CD6F
; ---------------------------------------------------------------------------
loc_CD44:
		LDA		byte_78E
		BEQ		locret_CD9E
		LDX		#$00
		STX		byte_D7
		LDX		#<[off_C313]
		BNE		loc_CD6F

; =============== S U B	R O U T	I N E =======================================
sub_CD52:
		LDX		#$01
		STX		byte_D7
		LDA		_apu_play_ctrlB
		BEQ		loc_CD65
		LDX		#$08
		STX		byte_775
		LDX		#<[off_C323]
		BNE		loc_CD6F
; ---------------------------------------------------------------------------
loc_CD65:
		LDA		byte_78F
		BEQ		locret_CD9E
		LDX		#<[off_C333]

; !FALLTHROUGH!

; =============== S U B	R O U T	I N E =======================================
loc_CD6F:
		JSR		sub_CCEB
		JMP		(word_E4)

; =============== S U B	R O U T	I N E =======================================
sub_CD75:
		LDA		#$02
		STA		byte_D7
		LDA		_apu_play_ctrlC
		BEQ		loc_CD88
		LDX		#$02
		STX		byte_775
		LDX		#<[off_C343]
		BNE		loc_CD6F
; ---------------------------------------------------------------------------
loc_CD88:
		LDA		byte_790
		BEQ		locret_CD9E
		LDX		#<[off_C353]
		BNE		loc_CD6F
; ---------------------------------------------------------------------------
loc_CD92:
		LDX		byte_D7
		LDA		byte_78E,X
		AND		#$00
		ORA		byte_D8
		STA		byte_78E,X
locret_CD9E:
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_CD9F:
		LDA		#$00
		STA		byte_D8
		BEQ		loc_CD92

; =============== S U B	R O U T	I N E =======================================
sub_CDA5:
		LDX		byte_D7
		INC		byte_77A,X
		LDA		byte_77A,X
		CMP		byte_777,X
		BNE		locret_CDB7
		LDA		#$00
		STA		byte_77A,X
locret_CDB7:
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_CDB8:
		LDA		#$01
		STA		byte_795

; =============== S U B	R O U T	I N E =======================================
sub_CDBD:
		LDA		#$00
		STA		byte_775
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_CDC3:
		LDY		#<[byte_C36F]
		LDA		#$01
		JSR		sub_CC93
		LDA		#$00
		STA		byte_77D
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_CDD0:
		JSR		sub_CDA5
		BEQ		loc_CDEE
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_CDD6:
		LDA		#$0A
		LDY		#<[byte_C367]
		JMP		sub_CC93

; =============== S U B	R O U T	I N E =======================================
sub_CDDD:
		JSR		sub_CDA5
		BEQ		loc_CDEE
		CMP		#$04
		BEQ		loc_CDE7
		RTS
; ---------------------------------------------------------------------------
loc_CDE7:
		LDA		#$03
		LDY		#<[byte_C36B]
		JMP		sub_CCCC
; ---------------------------------------------------------------------------
loc_CDEE:
		JSR		sub_CD9F
		LDA		#$10
		STA		$400C
		LDA		byte_775
		AND		#$FE
		STA		byte_775
locret_CDFE:
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_CDFF:
		LDA		#$01
		STA		byte_776
		LDA		#$02
		STA		byte_775
		LDY		#<[byte_C3C7]
		JSR		sub_CCC8
		LDA		#$01
		LDY		#<[byte_C363]
		JMP		sub_CC93

; =============== S U B	R O U T	I N E =======================================
sub_CE15:
		JSR		sub_CDA5
		BNE		locret_CDFE
		INC		byte_77D
		LDA		byte_77D
		CMP		#$01
		BEQ		loc_CE26
		BNE		loc_CE30
loc_CE26:
		LDA		#$0A
		STA		byte_777
		LDY		#<[byte_C3CB]
		JMP		sub_CCC8
; ---------------------------------------------------------------------------
loc_CE30:
		JMP		sub_D04A

; =============== S U B	R O U T	I N E =======================================
sub_CE33:
		LDA		byte_775
		AND		#$F7
		STA		byte_775
		LDA		#$10
		STA		$4000
		LDA		#$7F
		STA		$4001
		BNE		loc_CDEE

; =============== S U B	R O U T	I N E =======================================
sub_CE47:
		LDA		#$09
		STA		byte_775
		LDY		#<[byte_C3BF]
		JSR		sub_CCC4
		LDA		#$06
		LDY		#<[byte_C363]
		JMP		sub_CC93

; =============== S U B	R O U T	I N E =======================================
sub_CE58:
		JSR		sub_CDA5
		BNE		locret_CEC1
		LDA		byte_77D
		CMP		#$00
		BEQ		loc_CE66
		BNE		sub_CE33
loc_CE66:
		LDA		#$01
		STA		byte_77D
		LDY		#<[byte_C3C3]
		JMP		sub_CCC4

; =============== S U B	R O U T	I N E =======================================
sub_CE70:
		LDA		#$01
		STA		byte_776
		LDA		#$02
		LDY		#<[byte_C37F]
		JMP		sub_CC93

; =============== S U B	R O U T	I N E =======================================
sub_CE7C:
		JSR		sub_CDA5
		BNE		locret_CE94
		INC		byte_77E
		LDA		byte_77E
		CMP		#$01
		BEQ		loc_CE95
		CMP		#$02
		BEQ		loc_CE9A
		LDY		#<[byte_C383]
		JSR		sub_CCC4
locret_CE94:
		RTS
; ---------------------------------------------------------------------------
loc_CE95:
		LDY		#<[byte_C387]
		JMP		sub_CCC4
; ---------------------------------------------------------------------------
loc_CE9A:
		JMP		loc_CF31

; =============== S U B	R O U T	I N E =======================================
sub_CE9D:
		LDA		#$01
		STA		byte_776
		LDA		#$02
		LDY		#<[byte_C373]
		JMP		sub_CC93

; =============== S U B	R O U T	I N E =======================================
sub_CEA9:
		JSR		sub_CDA5
		BNE		locret_CEC1
		INC		byte_77E
		LDA		byte_77E
		CMP		#$01
		BEQ		loc_CEC2
		CMP		#$02
		BEQ		loc_CF31
		LDY		#<[byte_C377]
		JSR		sub_CCC4
locret_CEC1:
		RTS
; ---------------------------------------------------------------------------
loc_CEC2:
		LDY		#<[byte_C37B]
		JMP		sub_CCC4

; =============== S U B	R O U T	I N E =======================================
sub_CEC7:
		LDA		#$0C
		STA		byte_775
		LDA		#$0A
		LDY		#<[byte_C397]
		JMP		sub_CC93

; =============== S U B	R O U T	I N E =======================================
sub_CED3:
		JSR		sub_CDA5
		BEQ		loc_CEED
		LDA		byte_77E
		CMP		#$00
		BNE		locret_CF46
		LDY		#<[byte_C39B]
		JSR		sub_CCC4
		LDY		#<[byte_C39F]
		JSR		sub_CCD0
		INC		byte_77E
		RTS
; ---------------------------------------------------------------------------
loc_CEED:
		LDA		#$10
		STA		$4004
		LDA		#$7F
		STA		$4005
		LDA		byte_775
		AND		#$FB
		STA		byte_775
		JMP		loc_CF31

; =============== S U B	R O U T	I N E =======================================
sub_CF02:
		LDA		#$02
		LDY		#<[byte_C38B]
		JSR		sub_CC93
		LDA		#$06
		STA		byte_781
locret_CF0E:
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_CF0F:
		JSR		sub_CDA5
		BNE		locret_CF0E
		LDY		#<[byte_C38B]
		JSR		sub_CCC4
		LDY		byte_77E
		LDA		byte_CD20,Y
		STA		$4002
		LDA		byte_CD19,Y
		STA		$4000
		BNE		loc_CF2C
		BEQ		loc_CF31
loc_CF2C:
		INC		byte_77E
		BNE		locret_CF0E
loc_CF31:
		LDA		byte_775
		AND		#$F7
		STA		byte_775
		LDA		#$10
		STA		$4000
		LDA		#$7F
		STA		$4001
		JSR		sub_CD9F
locret_CF46:
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_CF47:
		LDA		#$02
		LDY		#<[byte_C38F]
		JMP		sub_CC93

; =============== S U B	R O U T	I N E =======================================
sub_CF4E:
		JSR		sub_CDA5
		BEQ		loc_CF31
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_CF54:
		LDA		#$02
		LDY		#<[byte_C393]
		JMP		sub_CC93

; =============== S U B	R O U T	I N E =======================================
sub_CF5B:
		JSR		sub_CDA5
		BEQ		loc_CF31
		RTS
; ---------------------------------------------------------------------------
byte_CF61:
		.BYTE $99,$97,$95,$93,$92,$91,$91,$91,$91,$00,$00

; =============== S U B	R O U T	I N E =======================================
sub_CF6C:
		LDA		#$04
		LDY		#<[byte_C3A3]
		JMP		sub_CC93

; =============== S U B	R O U T	I N E =======================================
sub_CF73:
		JSR		sub_CDA5
		BNE		locret_CFB6
		LDA		byte_781
		CMP		#$0A
		BEQ		loc_CFB7
		LDA		byte_77E
		CMP		#$00
		BEQ		loc_CF9F
		CMP		#$01
		BEQ		loc_CFA4
		CMP		#$02
		BEQ		loc_CFA9
		CMP		#$03
		BEQ		loc_CFAE
		LDY		byte_781
		LDA		byte_CF61,Y
		STA		$4000
		INC		byte_781
		RTS
; ---------------------------------------------------------------------------
loc_CF9F:
		LDY		#<[byte_C3A7]
		JMP		loc_CFB0
; ---------------------------------------------------------------------------
loc_CFA4:
		LDY		#<[byte_C3AB]
		JMP		loc_CFB0
; ---------------------------------------------------------------------------
loc_CFA9:
		LDY		#<[byte_C3AF]
		JMP		loc_CFB0
; ---------------------------------------------------------------------------
loc_CFAE:
		LDY		#<[byte_C3B3]
loc_CFB0:
		JSR		sub_CCC4
		INC		byte_77E
locret_CFB6:
		RTS
; ---------------------------------------------------------------------------
loc_CFB7:
		JMP		loc_CEED

; =============== S U B	R O U T	I N E =======================================
sub_CFBA:
		LDA		#$01
		STA		byte_776
		LDA		#$0C
		STA		byte_775
		LDY		#<[byte_C3B7]
		JSR		sub_CCD0
		LDA		#$20
		LDY		#<[byte_C3BB]
		JMP		sub_CC93

; =============== S U B	R O U T	I N E =======================================
sub_CFD0:
		JSR		sub_CDA5
		BNE		locret_CFB6
		LDA		#$7F
		STA		$4001
		JMP		loc_CEED

; =============== S U B	R O U T	I N E =======================================
sub_CFDD:
		LDA		#$09
		LDY		#<[byte_C3DB]
		JMP		sub_CC93

; =============== S U B	R O U T	I N E =======================================
sub_CFE4:
		JSR		sub_CDA5
		BNE		locret_CFB6
		INC		byte_77F
		LDA		byte_77F
		CMP		#$01
		BEQ		loc_CFF9
		CMP		#$02
		BEQ		loc_CFFF
		BNE		loc_D005
loc_CFF9:
		LDY		#<[byte_C3E3]
		LDA		#$03
		BNE		loc_D00E
loc_CFFF:
		LDY		#<[byte_C3E7]
		LDA		#$07
		BNE		loc_D00E
loc_D005:
		LDA		#$00
		STA		byte_77F
		LDY		#<[byte_C3DF]
		LDA		#$09
loc_D00E:
		STA		byte_779
		JMP		sub_CCC8

; =============== S U B	R O U T	I N E =======================================
sub_D014:
		LDA		#$12
		LDY		#<[byte_C3DF]
		JMP		sub_CC93

; =============== S U B	R O U T	I N E =======================================
sub_D01B:
		JSR		sub_CDA5
		BEQ		sub_D04A
		INC		byte_77F
		LDA		byte_77F
		CMP		#$06
		BEQ		loc_D03E
		CMP		#$0A
		BEQ		loc_D044
		CMP		#$0E
		BEQ		loc_D038
		LDY		#<[byte_C3EF]
		JSR		sub_CCC8
		RTS
; ---------------------------------------------------------------------------
loc_D038:
		LDY		#<[byte_C3EB]
		JSR		sub_CCC8
		RTS
; ---------------------------------------------------------------------------
loc_D03E:
		LDY		#<[byte_C3DF]
		JSR		sub_CCC8
		RTS
; ---------------------------------------------------------------------------
loc_D044:
		LDY		#<[byte_C3E3]
		JSR		sub_CCC8
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_D04A:
		LDA		byte_775
		AND		#$FD
		STA		byte_775
		LDA		#$00
		STA		$4008
		LDA		#$18
		STA		$400B
		JSR		sub_CD9F
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_D060:
		LDX		#$00
		LDY		#$00
loc_D064:
		LDA		byte_C1,X
		STA		byte_783,Y
		LDA		#$00
		STA		byte_C1,X
		CPX		#$06
		BEQ		loc_D08A
		LDA		byte_73E,X
		STA		byte_788,Y
		LDA		byte_74E,X
		STA		byte_78B,Y
		LDA		#$00
		STA		byte_73E,X
		STA		byte_74E,X
		INY
		INX
		INX
		BNE		loc_D064
loc_D08A:
		INY
		INX
		INX
		CPX		#$0A
		BEQ		loc_D09C
		LDA		byte_C1,X
		STA		byte_783,Y
		LDA		#$00
		STA		byte_C1,X
		BEQ		loc_D08A
loc_D09C:
		JSR		sub_D11C
		LDA		#$0F
		STA		byte_775
		LDA		#$01
		STA		byte_776
		LDY		#<[byte_C3CF]
		JSR		sub_CCC4
		LDY		#<[byte_C3DB]
		LDA		#$04
		JMP		sub_CC93

; =============== S U B	R O U T	I N E =======================================
sub_D0B5:
		LDX		#$00
		LDY		#$00
loc_D0B9:
		LDA		byte_783,Y
		STA		byte_C1,X
		CPX		#$06
		BEQ		loc_D0D3
		LDA		byte_788,Y
		STA		byte_73E,X
		LDA		byte_78B,Y
		STA		byte_74E,X
		INY
		INX
		INX
		BNE		loc_D0B9
loc_D0D3:
		INY
		INX
		INX
		CPX		#$0A
		BEQ		loc_D09C
		LDA		byte_786
		LDA		byte_783,Y
		STA		byte_C1,X
		BNE		loc_D0D3

; =============== S U B	R O U T	I N E =======================================
sub_D0E4:
		JSR		sub_CDA5
		BNE		locret_D11B
		LDA		byte_77F
		CMP		#$00
		BEQ		loc_D0FE
		CMP		#$01
		BEQ		loc_D106
		CMP		#$02
		BEQ		loc_D0FE
		CMP		#$03
		BEQ		loc_D10E
		BNE		sub_D11C
loc_D0FE:
		LDY		#<[byte_C3D3]
		JSR		sub_CCD0
		JMP		loc_D118
; ---------------------------------------------------------------------------
loc_D106:
		LDY		#<[byte_C3CF]
		JSR		sub_CCC4
		JMP		loc_D118
; ---------------------------------------------------------------------------
loc_D10E:
		LDY		#<[byte_C3D7]
		JSR		sub_CCD0
		LDA		#$02
		STA		byte_779
loc_D118:
		INC		byte_77F
locret_D11B:
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_D11C:
		JSR		sub_C421
		LDA		#$00
		STA		byte_775
		JMP		sub_C431
; ---------------------------------------------------------------------------
off_D127:
		.WORD byte_D133
		.WORD byte_D138
		.WORD byte_D13D
off_D12D:
		.WORD byte_D141
		.WORD byte_D16B
		.WORD byte_D18D
byte_D133:
		.BYTE $06,$04,$43,$01,$FF
byte_D138:
		.BYTE $04,$03,$42,$01,$FF
byte_D13D:
		.BYTE $03,$02,$01,$FF
byte_D141:
		.BYTE $06,$07,$06,$05,$05,$05,$05,$05,$05,$04,$04,$05,$05,$04,$04,$05
		.BYTE $06,$04,$03,$03,$04,$04,$04,$04,$04,$05,$04,$03,$03,$03,$04,$03
		.BYTE $02,$03,$02,$02,$02,$01,$01,$01,$00,$FF
byte_D16B:
		.BYTE $04,$05,$05,$04,$04,$05,$04,$04,$03,$03,$03,$03,$03,$03,$03,$03
		.BYTE $02,$02,$02,$02,$02,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01
		.BYTE $00,$FF
byte_D18D:
		.BYTE $03,$03,$03,$03,$02,$02,$02,$02,$01,$01,$01,$01,$00,$FF

; =============== S U B	R O U T	I N E =======================================
sub_D19B:
		LDA		byte_795
		CMP		#$00
		BEQ		locret_D209
		LDA		byte_794
		CMP		#$1F
		BNE		loc_D20A
		LDA		byte_793
		CMP		#$03
		BEQ		loc_D20F
		CMP		#$01
		BNE		loc_D1C8
		LDA		byte_775
		CMP		#$04
		BEQ		loc_D1BE
		JSR		sub_C7AC
loc_D1BE:
		LDA		byte_775
		CMP		#$08
		BEQ		loc_D1C8
		JSR		sub_C830
loc_D1C8:
		LDX		#$00
		LDY		#$00
loc_D1CC:
		CPX		byte_793
		BEQ		loc_D1D6
		INY
		INY
		INX
		BNE		loc_D1CC
loc_D1D6:
		LDX		#$00
		LDY		#$00
		LDA		off_D127,Y
		STA		byte_CA,X
		INY
		LDA		off_D127,Y
		STA		byte_CB,X
		LDX		#$02
		LDY		#$00
		LDA		off_D127,Y
		STA		byte_CA,X
		INY
		LDA		off_D127,Y
		STA		byte_CB,X
		LDY		#$00
		LDA		off_D12D,Y
		STA		byte_CE
		INY
		LDA		off_D12D,Y
		STA		byte_CF
		INC		byte_793
		LDA		#$00
		STA		byte_794
locret_D209:
		RTS
; ---------------------------------------------------------------------------
loc_D20A:
		INC		byte_794
		BNE		locret_D209
loc_D20F:
		LDA		byte_775
		CMP		#$01
		BEQ		loc_D220
		JSR		sub_C60A
		LDA		byte_775
		CMP		#$02
		BEQ		loc_D223
loc_D220:
		JSR		sub_C60E
loc_D223:
		JSR		sub_C890
		LDA		#$00
		STA		byte_795
		STA		byte_793
		STA		byte_794
		BEQ		locret_D209
; ---------------------------------------------------------------------------
off_D233:
		.WORD off_D3D2
		.WORD off_D66A
		.WORD off_DA5E
		.WORD off_DBB6
		.WORD off_DCD4
		.WORD off_DC64
		.WORD off_DC1C
		.WORD off_DD36
		.WORD off_D94F
		.WORD off_DDC0
		.WORD off_DE28
		.WORD off_DE75
		.WORD off_DEAD
		.WORD off_DF1C
byte_D24F:
		.BYTE $00,$01,$02,$03,$04,$05,$06,$07,$09,$0E,$13,$1D,$27,$31,$3B,$00
		.BYTE $01,$02,$07,$09,$00
byte_D264:
		.BYTE $00,$01,$02,$03,$04,$05,$06,$09,$27
byte_D26D:
		.BYTE $00
byte_D26E:
		.BYTE $00,$01,$00,$02,$00,$03,$00,$04,$00,$05,$00,$06,$00,$07,$00,$08
		.BYTE $00,$09,$00,$0A,$00,$0B,$00,$0C,$00,$0D,$00,$0E,$00,$0F,$00,$00
		.BYTE $00,$F1,$FF,$F2,$FF,$F3,$FF,$F4,$FF,$F5,$FF,$F6,$FF,$F7,$FF,$F8
		.BYTE $FF,$F9,$FF,$FA,$FF,$FB,$FF,$FC,$FF,$FD,$FF,$FE,$FF,$FF,$FF
byte_D2AD:
		.BYTE $C0
byte_D2AE:
		.BYTE $A0,$01,$40,$01,$20,$1F,$60,$21,$60,$3F,$20,$21,$40,$3F,$40,$21
		.BYTE $40,$3F,$40,$21,$60,$3F,$60,$21,$60,$3F,$60,$21,$60,$3F,$60,$21
		.BYTE $60,$3F,$60,$21,$60,$3F,$60,$21,$60,$3F,$60,$21,$60,$3F,$60,$21
		.BYTE $60,$3F,$60,$21,$60,$3F,$60,$21,$60,$3F,$60,$41,$60,$5F,$60,$41
		.BYTE $60,$5F,$20,$F8
byte_D2F2:
		.BYTE $8D,$1D,$10
		.WORD byte_D300
		.WORD byte_D2AE
byte_D2F9:
		.BYTE $CD,$1D,$10
		.WORD byte_D300
		.WORD byte_D2AE
byte_D300:
		.BYTE $0A,$08,$07,$25,$41,$FF
byte_D306:
		.BYTE $8D,$1D,$10
		.WORD byte_D30D
		.WORD byte_D2AD
byte_D30D:
		.BYTE $0B,$08,$47,$46,$25,$02,$FF
byte_D314:
		.BYTE $8D,$1D,$10
		.WORD byte_D31B
		.WORD byte_D2AD
byte_D31B:
		.BYTE $06,$04,$43,$02,$FF
byte_D320:
		.BYTE $8D,$1D,$10
		.WORD byte_D327
		.BYTE $00,$00
byte_D327:
		.BYTE $04,$05,$04,$84,$83,$42,$01,$FF
byte_D32F:
		.BYTE $55,$80,$00,$00,$00
byte_D334:
		.BYTE $75,$80,$0D,$00,$00
byte_D339:
		.BYTE $2F,$00,$C0
		.WORD byte_D2AD
byte_D33E:
		.BYTE $65,$80,$0D,$00,$00
byte_D343:
		.BYTE $00
byte_D344:
		.BYTE $0A
byte_D345:
		.BYTE $58,$19,$07,$28,$18,$03,$18,$05,$02,$C0,$00,$00,$00
byte_D352:
		.BYTE $03,$FE,$00,$02,$00,$00,$0C,$00,$0C,$0B,$06,$05,$07,$08,$06,$05
		.BYTE $05,$04,$04,$06,$05,$04,$05,$05,$05,$07,$05,$05,$05,$04,$05,$06
		.BYTE $06,$04,$03,$03,$04,$04,$04,$04,$04,$05,$04,$03,$03,$03,$04,$03
		.BYTE $02,$03,$03,$03,$04,$04,$02,$02,$02,$03,$02,$02,$02,$01,$00,$FF
byte_D392:
		.BYTE $3F,$3F,$3F,$3F,$3F,$3F,$3F,$3F,$3F,$3F,$3F,$3F,$3F,$3F,$3F,$3F
		.BYTE $00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
		.BYTE $00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
		.BYTE $3F,$3F,$3F,$3F,$3F,$3F,$3F,$3F,$3F,$3F,$3F,$3F,$3F,$3F,$3F,$3F
off_D3D2:
		.WORD byte_D49A
		.WORD byte_D4B2
		.WORD byte_D4D0
		.WORD byte_D4E5
		.WORD byte_D3DD
		.BYTE $0F
byte_D3DD:
		.BYTE $C4
		.WORD byte_D352
		.BYTE $80,$7F
byte_D3E2:
		.BYTE $FD
		.WORD byte_D4F1
		.BYTE $83,$23,$7F,$23,$20,$7F,$1C,$7F,$19,$7F,$19,$7F,$1C,$20,$7F,$23
		.BYTE $7F,$25,$7F,$25,$22,$7F,$1E,$7F,$1B,$7F,$1B,$7F,$1E,$22,$7F,$25
		.BYTE $7F,$23,$7F,$23,$20,$7F,$1C,$7F,$19,$7F,$19,$7F,$1C,$20,$7F,$27
		.BYTE $7F,$25,$7F,$25,$22,$7F,$1E,$7F,$1B,$7F,$1B,$7F,$1E,$22,$7F,$25
		.BYTE $7F,$27,$7F,$27,$23,$7F,$20,$7F,$1C,$7F,$1C,$7F,$20,$23,$7F,$27
		.BYTE $7F,$25,$7F,$25,$22,$7F,$1E,$7F,$1B,$7F,$1B,$7F,$1E,$22,$7F,$25
		.BYTE $7F,$23,$7F,$23,$20,$7F,$1C,$7F,$19,$7F,$19,$7F,$1C,$20,$7F,$23
		.BYTE $7F,$89,$22,$1E,$82,$7E,$81,$2A,$83,$7F,$27,$28,$2A,$2C,$7F,$2A
		.BYTE $28,$7F,$27,$88,$25,$83,$7F,$25,$27,$28,$2A,$7F,$28,$27,$7F,$25
		.BYTE $88,$24,$83,$7F,$24,$25,$27,$28,$7F,$27,$25,$7F,$23,$88,$22,$81
		.BYTE $27,$83,$27,$7F,$27,$7F,$7F,$89,$28,$84,$27,$7F,$83,$7F,$7F,$7F
		.BYTE $81,$7F,$FC
		.WORD byte_D3E2
byte_D49A:
		.BYTE $C0
		.WORD byte_D2F2
		.BYTE $80,$7F
byte_D49F:
		.BYTE $E2,$FD
		.WORD byte_D508
		.BYTE $EF,$E2,$FD
		.WORD byte_D527
		.BYTE $EF,$FD
		.WORD byte_D546
		.BYTE $FD
		.WORD byte_D583
		.BYTE $FC
		.WORD byte_D49F
byte_D4B2:
		.BYTE $C1
		.WORD byte_D2F2
		.BYTE $80,$7F
byte_D4B7:
		.BYTE $BE,$03,$E2,$FD
		.WORD byte_D508
		.BYTE $EF,$BE,$07,$E2,$FD
		.WORD byte_D527
		.BYTE $EF,$FD
		.WORD byte_D546
		.BYTE $BE,$00,$FD
		.WORD byte_D5AA
		.BYTE $FC
		.WORD byte_D4B7
byte_D4D0:
		.BYTE $C2
		.WORD byte_D33E
		.BYTE $80,$7F
byte_D4D5:
		.BYTE $E2,$FD
		.WORD byte_D5D1
		.BYTE $EF,$E2,$FD
		.WORD byte_D5EE
		.BYTE $EF,$FD
		.WORD byte_D60B
		.BYTE $FC
		.WORD byte_D4D5
byte_D4E5:
		.BYTE $83,$0C,$0C,$03,$0C,$0C,$03,$0C,$0C,$FC
		.WORD byte_D4E5
byte_D4F1:
		.BYTE $80,$7E,$80,$28,$80,$7E,$80,$27,$80,$7E,$80,$28,$80,$27,$89,$7F
		.BYTE $83,$1B,$1C,$1E,$20,$22,$FE
byte_D508:
		.BYTE $82,$23,$23,$83,$7F,$23,$7F,$23,$7F,$23,$7F,$23,$7F,$89,$23,$82
		.BYTE $22,$22,$83,$7F,$22,$7F,$22,$7F,$22,$7F,$22,$7F,$89,$22,$FE
byte_D527:
		.BYTE $82,$1C,$1C,$83,$7F,$1C,$7F,$1C,$7F,$1C,$7F,$1C,$7F,$89,$1C,$82
		.BYTE $1E,$1E,$83,$7F,$1E,$7F,$1E,$7F,$1E,$7F,$1E,$7F,$89,$1E,$FE
byte_D546:
		.BYTE $82,$20,$20,$83,$7F,$20,$7F,$20,$7F,$20,$7F,$20,$7F,$89,$20,$82
		.BYTE $1E,$1E,$83,$7F,$1E,$7F,$1E,$7F,$1E,$7F,$1E,$7F,$89,$1E,$82,$1C
		.BYTE $1C,$83,$7F,$1C,$7F,$1C,$7F,$1C,$7F,$1C,$7F,$89,$1C,$82,$1B,$1B
		.BYTE $83,$7F,$1B,$7F,$1B,$7F,$1B,$7F,$1B,$7F,$89,$1B,$FE
byte_D583:
		.BYTE $89,$23,$23,$82,$7E,$80,$1C,$89,$21,$21,$82,$7E,$80,$21,$89,$1C
		.BYTE $1C,$82,$7E,$80,$1E,$83,$1E,$7F,$1E,$7F,$7F,$89,$1F,$84,$1E,$7F
		.BYTE $83,$7F,$7F,$7F,$81,$7F,$FE
byte_D5AA:
		.BYTE $89,$27,$27,$82,$7E,$80,$25,$89,$25,$25,$82,$7E,$80,$24,$89,$23
		.BYTE $23,$82,$7E,$80,$22,$83,$22,$7F,$22,$7F,$7F,$89,$26,$84,$22,$7F
		.BYTE $83,$7F,$7F,$7F,$81,$7F,$FE
byte_D5D1:
		.BYTE $89,$18,$83,$1F,$81,$1F,$89,$18,$83,$1F,$89,$1F,$83,$18,$89,$17
		.BYTE $83,$1E,$81,$1E,$89,$17,$83,$1E,$89,$1E,$83,$17,$FE
byte_D5EE:
		.BYTE $89,$19,$83,$20,$81,$20,$89,$19,$83,$20,$89,$20,$83,$19,$89
byte_D5FD:
		.BYTE $1B,$83,$22,$81,$22,$89,$1B,$83,$22,$89,$22,$83,$1B,$FE
byte_D60B:
		.BYTE $89,$1C,$83,$23,$81,$23,$89,$1C,$83,$23,$89,$23,$83,$1C,$89,$1B
		.BYTE $83,$22,$81,$22,$89,$1B,$83,$22,$89,$22,$83,$1B,$89,$19,$83,$20
		.BYTE $81,$20,$89,$19,$83,$20,$89,$20,$83,$19,$89,$17,$83,$1E,$81,$1E
		.BYTE $89,$17,$83,$1E,$89,$1E,$83,$17,$89,$19,$19,$82,$7E,$80,$12,$89
		.BYTE $1B,$1B,$82,$7E,$80,$14,$89,$19,$19,$82,$7E,$80,$12,$83,$17,$7F
		.BYTE $17,$7F,$7F,$89,$18,$84,$17,$7F,$83,$7F,$7F,$7F,$81,$7F,$FE
off_D66A:
		.WORD byte_D696
		.WORD byte_D688
		.WORD byte_D6A4
		.WORD byte_D6B5
		.WORD byte_D675
		.BYTE $0D
byte_D675:
		.BYTE $C4
		.WORD byte_D352
		.BYTE $88,$7F,$84,$7F,$7F,$19,$19
byte_D67F:
		.BYTE $FD
		.WORD byte_D6F6
		.BYTE $FD
		.WORD byte_D74C
		.BYTE $FC
		.WORD byte_D67F
byte_D688:
		.BYTE $C1
		.WORD byte_D2F2
		.BYTE $80,$7F
byte_D68D:
		.BYTE $FD
		.WORD byte_D789
		.BYTE $FD
		.WORD byte_D7D2
		.BYTE $FC
		.WORD byte_D68D
byte_D696:
		.BYTE $C0
		.WORD byte_D2F2
		.BYTE $80,$7F
byte_D69B:
		.BYTE $FD
		.WORD byte_D81F
		.BYTE $FD
		.WORD byte_D868
		.BYTE $FC
		.WORD byte_D69B
byte_D6A4:
		.BYTE $C2
		.WORD byte_D32F
		.BYTE $80,$7F
byte_D6A9:
		.BYTE $C2
		.WORD byte_D32F
		.BYTE $FD
		.WORD byte_D89B
		.BYTE $FD
		.WORD byte_D8FE
		.BYTE $FC
		.WORD byte_D6A9
byte_D6B5:
		.BYTE $82,$0C,$0C,$0C,$83,$03,$84,$03,$03
byte_D6BE:
		.BYTE $E2,$E7,$83,$0C,$0C,$03,$0C,$EF,$EF,$82,$03,$7F,$03,$83,$7F,$84
		.BYTE $03,$03,$E8,$83,$0C,$0C,$03,$0C,$EF,$E4,$83,$0C,$0C,$03,$84,$0C
		.BYTE $0C,$EF,$83,$7F,$03,$7F,$03,$82,$03,$7F,$83,$7F,$03,$7F,$03,$7F
		.BYTE $03,$7F,$84,$03,$03,$FC
		.WORD byte_D6BE
byte_D6F6:
		.BYTE $83,$22,$22,$7F,$84,$19,$19,$83,$22,$22,$7F,$84,$19,$19,$83,$22
		.BYTE $23,$25,$7E,$83,$27,$25,$23,$22,$22,$23,$1F,$20,$7F,$7F,$7F,$84
		.BYTE $1B,$1B,$83,$22,$23,$1F,$20,$7F,$7F,$7F,$84,$1B,$1B,$83,$23,$23
		.BYTE $7F,$84,$1B,$1B,$83,$23,$23,$7F,$84,$1B,$1B,$83,$23,$25,$27,$7E
		.BYTE $83,$29,$27,$25,$23,$23,$82,$25,$83,$22,$81,$7F,$83,$7F,$1E,$1D
		.BYTE $1E,$20,$22,$23,$25,$FE
byte_D74C:
		.BYTE $80,$7E,$83,$27,$2F,$2F,$2E,$2E,$2C,$2C,$2A,$80,$7E,$83,$29,$31
		.BYTE $31,$2F,$2F,$2E,$2E,$31,$89,$1B,$84,$1D,$1E,$89,$20,$84,$22,$23
		.BYTE $89,$25,$84,$27,$29,$89,$2A,$84,$29,$2A,$88,$7E,$93,$31,$2F,$2E
		.BYTE $2C,$2A,$29,$94,$27,$88,$25,$83,$7F,$84,$19,$19,$FE
byte_D789:
		.BYTE $83,$7F,$25,$2A,$7F,$7F,$25,$29,$7F,$7F,$20,$28,$7F,$7F,$22,$27
		.BYTE $7F,$7F,$27,$23,$84,$7F,$27,$83,$2E,$2A,$27,$7F,$7F,$29,$26,$84
		.BYTE $7F,$29,$83,$2C,$29,$26,$23,$7F,$20,$20,$7F,$7F,$1F,$1F,$7F,$7F
		.BYTE $1E,$23,$7F,$7F,$1D,$20,$7F,$7F,$22,$1E,$7F,$7F,$84,$31,$2E,$2A
		.BYTE $25,$22,$1E,$82,$19,$7F,$81,$1C,$FE
byte_D7D2:
		.BYTE $C1
		.WORD byte_D320
		.BYTE $83,$7F,$2E,$2C,$2A,$29,$2A,$2E,$33,$89,$2C,$83,$2A,$89,$29,$83
		.BYTE $27,$83,$7F,$31,$2F,$2E,$2C,$2E,$31,$2C,$89,$2E,$83,$2C,$89,$2B
		.BYTE $83,$22,$89,$17,$84,$19,$1B,$89,$1D,$84,$1E,$20,$89,$1D,$84,$1E
		.BYTE $20,$89,$22,$84,$20,$22,$C1
		.WORD byte_D2F2
		.BYTE $83,$7F,$1E,$7F,$1E,$82,$1E,$7F,$83,$7F,$1D,$7F,$1D,$82,$1D,$7F
		.BYTE $FE
byte_D81F:
		.BYTE $83,$7F,$1E,$25,$7F,$7F,$1D,$25,$7F,$7F,$1C,$20,$7F,$7F,$1B,$1F
		.BYTE $7F,$7F,$1E,$1B,$84,$7F,$23,$83,$2A,$27,$23,$7F,$7F,$20,$23,$84
		.BYTE $7F,$26,$83,$29,$26,$23,$20,$7F,$1B,$17,$7F,$7F,$1B,$17,$7F,$7F
		.BYTE $1B,$1E,$7F,$7F,$19,$20,$7F,$7F,$1E,$19,$7F,$7F,$84,$2E,$2A,$25
		.BYTE $22,$1E,$19,$82,$16,$7F,$81,$16,$FE
byte_D868:
		.BYTE $83,$7F,$1E,$22,$7F,$82,$7F,$27,$83,$7F,$20,$27,$7F,$82,$7F,$23
		.BYTE $83,$7F,$20,$25,$7F,$82,$7F,$25,$83,$7F,$1F,$28,$7F,$82,$7F,$25
		.BYTE $7F,$1E,$7F,$23,$7F,$25,$7F,$25,$E2,$83,$7F,$17,$7F,$17,$82,$17
		.BYTE $7F,$EF,$FE
byte_D89B:
		.BYTE $82,$1E,$83,$7F,$84,$7F,$1E,$83,$1E,$1E,$82,$7F,$82,$1E,$83,$7F
		.BYTE $84,$7F,$1E,$83,$1F,$1F,$82,$7F,$82,$20,$83,$7F,$84,$7F,$20,$83
		.BYTE $20,$20,$82,$7F,$82,$19,$83,$7F,$84,$7F,$19,$83,$19,$19,$82,$7F
		.BYTE $82,$20,$83,$7F,$84,$7F,$20,$83,$1F,$1F,$82,$7F,$82,$1E,$83,$7F
		.BYTE $84,$7F,$1E,$83,$1D,$1D,$82,$7F,$82,$1E,$83,$7F,$84,$7F,$19,$83
		.BYTE $1E,$1E,$7F,$25,$C2
		.WORD byte_D334
		.BYTE $82,$1E,$7F,$C2
		.WORD byte_D339
		.BYTE $81,$1E,$C2
		.WORD byte_D32F
		.BYTE $FE
byte_D8FE:
		.BYTE $83,$17,$27,$2A,$17,$17,$17,$2A,$17,$1D,$23,$2F,$1D,$1D,$1D,$2C
		.BYTE $1D,$16,$29,$2C,$16,$16,$16,$2C,$16,$1B,$25,$2B,$1B,$1B,$1B,$28
		.BYTE $1B,$C2
		.WORD byte_D334
		.BYTE $84,$14,$7F,$14,$7F,$82,$27,$84,$19,$7F,$19,$7F,$82,$29,$84,$16
		.BYTE $7F,$16,$7F,$82,$2C,$84,$1B,$7F,$1B,$7F,$82,$2A,$83,$7F,$20,$7F
		.BYTE $20,$82,$20,$7F,$83,$7F,$19,$7F,$19,$82,$19,$7F,$FE
off_D94F:
		.WORD byte_D9C5
		.WORD byte_D9F0
		.WORD byte_DA1B
		.WORD byte_DA55
		.WORD byte_D95A
		.BYTE $10
byte_D95A:
		.BYTE $BE,$F4,$C4
		.WORD byte_D352
		.BYTE $80,$7F,$7F,$92,$7F
byte_D964:
		.BYTE $82,$2A,$2A,$28,$28,$26,$26,$90,$23,$7F,$20,$82,$23,$90,$27,$7F
		.BYTE $23,$7F,$7F,$7E,$81,$23,$80,$7F,$82,$2A,$2A,$28,$28,$26,$26,$90
		.BYTE $23,$7F,$27,$82,$23,$27,$90,$23,$7F,$20,$1E,$7F,$20,$1E,$7F,$1C
		.BYTE $1B,$7F,$1E,$20,$7F,$1E,$23,$7F,$27,$82,$7F,$25,$90,$27,$7F,$25
		.BYTE $82,$2A,$2A,$28,$26,$23,$21,$23,$90,$21,$7F,$1E,$20,$7F,$1E,$7F
		.BYTE $7F,$1B,$19,$7F,$1C,$20,$7F,$1C,$1E,$7F,$21,$23,$7F,$26,$FC
		.WORD byte_D964
byte_D9C5:
		.BYTE $C0
		.WORD byte_D306
		.BYTE $80,$7F,$7F
byte_D9CB:
		.BYTE $80,$1B,$1A,$1B,$88,$1B,$90,$7F,$7F,$7E,$80,$1A,$81,$1A,$1A,$80
		.BYTE $1B,$81,$1B,$90,$7F,$7F,$1E,$7F,$7F,$7E,$80,$1C,$1C,$81,$1B,$1E
		.BYTE $1D,$1C,$FC
		.WORD byte_D9CB
byte_D9F0:
		.BYTE $C1
		.WORD byte_D306
		.BYTE $80,$7F,$7F
byte_D9F6:
		.BYTE $80,$15,$14,$15,$88,$15,$90,$7F,$7F,$7E,$80,$14,$81,$14,$17,$80
		.BYTE $15,$81,$17,$90,$7F,$7F,$18,$7F,$7F,$7E,$80,$17,$16,$81,$15,$18
		.BYTE $17,$16,$FC
		.WORD byte_D9F6
byte_DA1B:
		.BYTE $C2
		.WORD byte_D334
		.BYTE $80,$7F,$7F
byte_DA21:
		.BYTE $82,$17,$1A,$1C,$1E,$1C,$1A,$17,$15,$17,$1A,$1C,$1E,$21,$1E,$1C
		.BYTE $1A,$1C,$1E,$1C,$1A,$1C,$20,$23,$26,$1E,$1C,$1B,$17,$1B,$1C,$1E
		.BYTE $20,$19,$1B,$1C,$1D,$1E,$1C,$1B,$19,$17,$1B,$1C,$20,$19,$1B,$1C
		.BYTE $1E,$FC
		.WORD byte_DA21
byte_DA55:
		.BYTE $82,$0C,$90,$00,$7F,$0C,$FC
		.WORD byte_DA55
off_DA5E:
		.WORD byte_DAE2
		.WORD byte_DB04
		.WORD byte_DA69
		.WORD byte_DB53
		.WORD byte_DB26
		.BYTE $16
byte_DA69:
		.BYTE $BE,$03,$C2
		.WORD byte_D339
		.BYTE $80,$7E,$80,$7E,$80,$28,$8E,$2A,$2B,$2D,$2F,$2A,$7E,$80,$7E,$80
		.BYTE $7E,$81,$28,$82,$7F,$84,$2A,$2B,$2A,$28,$80,$7E,$81,$23,$83,$7F
		.BYTE $21,$84,$23,$7F,$83,$7E,$83,$28,$26,$84,$28,$7F,$83,$7E,$83,$2F
		.BYTE $21,$84,$23,$7F,$83,$7E,$83,$28,$26,$84,$28,$7F,$83,$7E,$83,$2F
		.BYTE $2D,$84,$2F,$7F,$83,$7E,$80,$7E,$80,$34,$7E,$80,$3B,$84,$2A,$7F
		.BYTE $2A,$7F,$81,$7F,$84,$2A,$7F,$2A,$7F,$80,$7F,$C2
		.WORD byte_D32F
		.BYTE $E2,$FD
		.WORD byte_DB7B
		.BYTE $EF,$84,$2A,$7F,$2A,$7F,$81,$7F,$84,$2A,$7F,$2A,$7F,$80,$7F,$FC
		.WORD byte_DA69
byte_DAE2:
		.BYTE $C0
		.WORD byte_D2F9
		.BYTE $E2,$BE,$04,$FD
		.WORD byte_DB67
		.BYTE $BE,$01,$FD
		.WORD byte_DB67
		.BYTE $EF,$BE,$03,$84,$1A,$7F,$1A,$7F,$81,$7F,$84,$1A,$7F,$1A,$7F,$80
		.BYTE $7F,$FC
		.WORD byte_DAE2
byte_DB04:
		.BYTE $C1
		.WORD byte_D2F9
		.BYTE $E2,$BE,$08,$FD
		.WORD byte_DB67
		.BYTE $BE,$06,$FD
		.WORD byte_DB67
		.BYTE $EF,$BE,$03,$84,$23,$7F,$23,$7F,$81,$7F,$84,$23,$7F,$23,$7F,$80
		.BYTE $7F,$FC
		.WORD byte_DB04
byte_DB26:
		.BYTE $BE,$F7,$C4
		.WORD byte_D352
		.BYTE $E2,$FD
		.WORD byte_DB7B
		.BYTE $EF,$83,$10,$10,$81,$7F,$83,$10,$10,$80,$7F,$BE,$01,$E2,$FD
		.WORD byte_DB67
		.BYTE $FD
		.WORD byte_DB67
		.BYTE $EF,$BE,$03,$83,$10,$10,$81,$7F,$83,$10,$10,$80,$7F,$FC
		.WORD byte_DB26
byte_DB53:
		.BYTE $E8,$FD
		.WORD byte_DBA4
		.BYTE $EF,$83,$03,$03,$81,$7F,$83,$03,$03,$88,$7F,$82,$03,$FC
		.WORD byte_DB53
byte_DB67:
		.BYTE $83,$E2,$19,$7F,$19,$7F,$7F,$19,$7F,$19,$7F,$19,$7F,$19,$7F,$19
		.BYTE $7F,$7F,$EF,$FE
byte_DB7B:
		.BYTE $E2,$82,$10,$83,$7F,$17,$1A,$1E,$7F,$1A,$82,$1A,$83,$7F,$1A,$7F
		.BYTE $1A,$82,$17,$EF,$E2,$82,$0C,$83,$7F,$13,$1A,$1C,$7F,$1C,$7F,$1C
		.BYTE $7F,$82,$1A,$83,$7F,$17,$13,$EF,$FE
byte_DBA4:
		.BYTE $83,$06,$06,$03,$06,$06,$03,$06,$06,$03,$06,$06,$03,$06,$06,$03
		.BYTE $06,$FE
off_DBB6:
		.WORD byte_DBC8
		.WORD byte_DBD1
		.WORD byte_DBDC
		.WORD byte_DBED
		.WORD byte_DBC1
		.BYTE $0E
byte_DBC1:
		.BYTE $C4
		.WORD byte_D352
		.BYTE $FD
		.WORD byte_DC0A
		.BYTE $FF
byte_DBC8:
		.BYTE $BE,$0C,$C0
		.WORD byte_D2F2
		.BYTE $FD
		.WORD byte_DC0A
		.BYTE $FF
byte_DBD1:
		.BYTE $BE,$F4,$C1
		.WORD byte_D2F9
		.BYTE $92,$7F,$FD
		.WORD byte_DC0A
		.BYTE $FF
byte_DBDC:
		.BYTE $C2
		.WORD byte_D32F
		.BYTE $82,$19,$1A,$1B,$1D,$82,$19,$1B,$83,$20,$7F,$14,$7F,$FF
byte_DBED:
		.BYTE $84,$06,$7F,$06,$7F,$06,$7F,$06,$06,$7F,$06,$7F,$06,$06,$7F,$06
		.BYTE $06,$06,$7F,$06,$7F,$06,$7F,$06,$06,$82,$06,$06,$FF
byte_DC0A:
		.BYTE $83,$1D,$20,$22,$20,$24,$1B,$1F,$1D,$82,$19,$1B,$83,$20,$7F,$14
		.BYTE $7F,$FE
off_DC1C:
		.WORD byte_DC3A
		.WORD byte_DC41
		.WORD byte_DC4A
		.WORD $0000
		.WORD byte_DC27
		.BYTE $12
byte_DC27:
		.BYTE $C4
		.WORD byte_D352
		.BYTE $81,$7F,$83,$21,$22,$25,$29,$92,$2B,$88,$2C,$82,$2A,$80,$29,$FF
byte_DC3A:
		.BYTE $C0
		.WORD byte_D314
		.BYTE $FD
		.WORD byte_DC54
		.BYTE $FF
byte_DC41:
		.BYTE $C1
		.WORD byte_D314
		.BYTE $91,$7F,$FD
		.WORD byte_DC54
		.BYTE $FF
byte_DC4A:
		.BYTE $C2
		.WORD byte_D339
		.BYTE $80,$1E,$1D,$7E,$81,$1B,$FF
byte_DC54:
		.BYTE $82,$2A,$2E,$31,$35,$29,$2C,$30,$33,$27,$2A,$2E,$7E,$81,$31,$FE
off_DC64:
		.WORD byte_DC6F
		.WORD byte_DC96
		.WORD byte_DCCB
		.WORD $0000
		.WORD byte_DCB8
		.BYTE $13
byte_DC6F:
		.BYTE $C0
		.WORD byte_D2F2
		.BYTE $90,$20,$7F,$23,$27,$7F,$2A,$82,$29,$25,$90,$22,$7F,$25,$29,$7F
		.BYTE $2C,$82,$2A,$27,$90,$23,$7F,$20,$23,$7F,$27,$29,$7F,$20,$25,$7F
		.BYTE $29,$80,$2A,$FF
byte_DC96:
		.BYTE $C1
		.WORD byte_D2F2
		.BYTE $82,$27,$2A,$90,$29,$7F,$20,$25,$7F,$29,$82,$22,$2C,$90,$27,$7F
		.BYTE $25,$23,$7F,$22,$82,$20,$90,$22,$7F,$23,$82,$25,$29,$22,$FF
byte_DCB8:
		.BYTE $C4
		.WORD byte_D352
		.BYTE $82,$14,$1B,$19,$1D,$16,$20,$1B,$1E,$14,$1B,$19,$1D,$80,$1E,$FF
byte_DCCB:
		.BYTE $C2
		.WORD byte_D32F
		.BYTE $80,$7F,$7F,$7F,$1E,$FF
off_DCD4:
		.WORD byte_DCFE
		.WORD byte_DD12
		.WORD byte_DD24
		.WORD $0000
		.WORD byte_DCDF
		.BYTE $0D
byte_DCDF:
		.BYTE $C4
		.WORD byte_D352
		.BYTE $82,$1E,$84,$19,$1B,$83,$1D,$91,$1B,$1C,$1B,$19,$17,$14,$8A,$16
		.BYTE $84,$12,$82,$19,$8A,$1D,$84,$1E,$82,$7F,$12,$FF
byte_DCFE:
		.BYTE $C0
		.WORD byte_D2F2
		.BYTE $82,$19,$7F,$7F,$7F,$BF,$0D,$82,$7F,$8A,$1D,$84,$1E,$82,$7F,$12
		.BYTE $FF
byte_DD12:
		.BYTE $C1
		.WORD byte_D2F2
		.BYTE $82,$22,$7F,$7F,$7F,$82,$7F,$8A,$19,$84,$1E,$82,$7F,$12,$FF
byte_DD24:
		.BYTE $C2
		.WORD byte_D339
		.BYTE $82,$12,$7F,$7F,$7F,$82,$7F,$8A,$19,$84,$1E,$82,$7F,$12,$FF
off_DD36:
		.WORD byte_DD41
		.WORD byte_DD54
		.WORD byte_DD84
		.WORD $0000
		.WORD byte_DD67
		.BYTE $0C
byte_DD41:
		.BYTE $BE,$00,$C0
		.WORD byte_D306
		.BYTE $FD
		.WORD byte_DDB0
		.BYTE $82,$19,$19,$90,$1B,$7F,$1B,$82,$7F,$1C,$FF
byte_DD54:
		.BYTE $BE,$03,$C1
		.WORD byte_D306
		.BYTE $FD
		.WORD byte_DDB0
		.BYTE $82,$19,$19,$90,$1B,$7F,$1B,$82,$7F,$1D,$FF
byte_DD67:
		.BYTE $C4
		.WORD byte_D352
		.BYTE $90,$7F,$14,$16,$7F,$18,$82,$7F,$20,$7F,$21,$7F,$20,$7F,$1E,$82
		.BYTE $20,$20,$90,$24,$7F,$24,$82,$7F,$25,$FF
byte_DD84:
		.BYTE $C2
		.WORD byte_D334
		.BYTE $90,$7F,$20,$22,$7F,$24,$82,$25,$90,$7F,$7F,$25,$82,$27,$90,$7F
		.BYTE $7F,$27,$82,$28,$90,$7F,$7F,$28,$82,$27,$90,$7F,$7F,$27,$82,$25
		.BYTE $25,$90,$20,$7F,$20,$82,$7F,$19,$FF
byte_DDB0:
		.BYTE $90,$7F,$7F,$7F,$7F,$7F,$82,$7F,$19,$7F,$1B,$7F,$19,$7F,$18,$FE
off_DDC0:
		.WORD byte_DDE3
		.WORD byte_DDF9
		.WORD byte_DE0F
		.WORD $0000
		.WORD byte_DDCB
		.BYTE $11
byte_DDCB:
		.BYTE $C4
		.WORD byte_D352
		.BYTE $90,$7F,$7F,$7E,$82,$28,$27,$25,$82,$2B,$2B,$90,$2B,$7F,$2B,$7F
		.BYTE $7F,$7E,$80,$2A,$FF
byte_DDE3:
		.BYTE $C0
		.WORD byte_D306
		.BYTE $90,$7F,$7F,$7E,$88,$25,$82,$28,$28,$90,$28,$7F,$28,$7F,$7F,$7E
		.BYTE $80,$27,$FF
byte_DDF9:
		.BYTE $C1
		.WORD byte_D306
		.BYTE $90,$7F,$7F,$7E,$88,$23,$82,$22,$22,$90,$22,$7F,$22,$7F,$7F,$7E
		.BYTE $80,$22,$FF
byte_DE0F:
		.BYTE $C2
		.WORD byte_D339
		.BYTE $83,$19,$7F,$1B,$7F,$1C,$7F,$1D,$7F,$1E,$7F,$1C,$7F,$1B,$7F,$90
		.BYTE $19,$7F,$7E,$80,$17,$FF
off_DE28:
		.WORD byte_DE33
		.WORD byte_DE3C
		.WORD byte_DE45
		.WORD $0000
		.WORD $0000
		.BYTE $0C
byte_DE33:
		.BYTE $C0
		.WORD byte_D306
		.BYTE $82,$23,$FD
		.WORD byte_DE60
		.BYTE $FF
byte_DE3C:
		.BYTE $C1
		.WORD byte_D306
		.BYTE $82,$1E,$FD
		.WORD byte_DE60
		.BYTE $FF
byte_DE45:
		.BYTE $C2
		.WORD byte_D339
		.BYTE $90,$17,$7F,$17,$1B,$7F,$1B,$1C,$7F,$1C,$1D,$7F,$1D,$1E,$7F,$1E
		.BYTE $12,$7F,$17,$82,$7F,$81,$17,$FF
byte_DE60:
		.BYTE $84,$21,$23,$21,$1E,$90,$1C,$7F,$1A,$17,$7F,$15,$17,$7F,$12,$15
		.BYTE $7F,$17,$82,$7F,$FE
off_DE75:
		.WORD byte_DE92
		.WORD byte_DE9B
		.WORD byte_DE89
		.WORD $0000
		.WORD byte_DE80
		.BYTE $17
byte_DE80:
		.BYTE $BE,$FC,$C4
		.WORD byte_D352
		.BYTE $FD
		.WORD byte_DEA4
		.BYTE $FF
byte_DE89:
		.BYTE $BE,$FC,$C2
		.WORD byte_D32F
		.BYTE $FD
		.WORD byte_DEA4
		.BYTE $FF
byte_DE92:
		.BYTE $BE,$07,$C0
		.WORD byte_D2F2
		.BYTE $FD
		.WORD byte_DEA4
		.BYTE $FF
byte_DE9B:
		.BYTE $BE,$0C,$C1
		.WORD byte_D2F9
		.BYTE $FD
		.WORD byte_DEA4
		.BYTE $FF
byte_DEA4:
		.BYTE $83,$1D,$1E,$7F,$1F,$7F,$80,$20,$FE
off_DEAD:
		.WORD byte_DEC3
		.WORD byte_DECA
		.WORD $0000
		.WORD $0000
		.WORD byte_DEB8
		.BYTE $0B
byte_DEB8:
		.BYTE $BE,$0C,$C4
		.WORD byte_D352
		.BYTE $E2,$FD
		.WORD byte_DF00
		.BYTE $EF,$FF
byte_DEC3:
		.BYTE $C0
		.WORD byte_D314
		.WORD byte_D5FD
		.BYTE $DE,$FF
byte_DECA:
		.BYTE $C1
		.WORD byte_D314
		.BYTE $91,$7F,$92,$7F,$FD
		.WORD byte_DED5
		.BYTE $FF
byte_DED5:
		.BYTE $FD
		.WORD byte_DEE2
		.BYTE $35,$31,$2C,$29,$FD
		.WORD byte_DEE2
		.BYTE $81,$35,$FE
byte_DEE2:
		.BYTE $83,$19,$1D,$20,$24,$1B,$1E,$22,$25,$1D,$20,$24,$27,$1E,$22,$25
		.BYTE $29,$20,$25,$29,$2C,$20,$24,$27,$2A,$25,$29,$2C,$31,$FE
byte_DF00:
		.BYTE $81,$20,$89,$1D,$83,$1E,$81,$20,$82,$25,$1E,$81,$1D,$85,$1B,$1D
		.BYTE $1B,$1D,$1B,$1D,$1B,$1D,$83,$1B,$19,$80,$19,$FE
off_DF1C:
		.WORD byte_DF27
		.WORD byte_DF3C
		.WORD byte_DF51
		.WORD $0000
		.WORD byte_DF58
		.BYTE $0D
byte_DF27:
		.BYTE $C0
		.WORD byte_D306
		.BYTE $92,$7F,$FD
		.WORD byte_DF5F
		.BYTE $84,$25,$7F,$27,$7F,$25,$22,$83,$20,$82,$1E,$2A,$FF
byte_DF3C:
		.BYTE $C1
		.WORD byte_D306
		.BYTE $FD
		.WORD byte_DF5F
		.BYTE $92,$7F,$84,$2A,$7F,$27,$7F,$25,$22,$83,$20,$82,$1E,$2A,$FF
byte_DF51:
		.BYTE $C2
		.WORD byte_D334
		.BYTE $FD
		.WORD byte_DF91
		.BYTE $FF
byte_DF58:
		.BYTE $C4
		.WORD byte_D352
		.BYTE $FD
		.WORD byte_DF91
		.BYTE $FF
byte_DF5F:
		.BYTE $84,$1E,$22,$25,$1E,$22,$25,$1E,$22,$25,$1E,$22,$25,$1E,$22,$25
		.BYTE $7F,$1F,$22,$25,$1F,$22,$25,$1F,$22,$25,$1F,$22,$25,$1F,$22,$25
		.BYTE $7F,$20,$23,$27,$20,$23,$1B,$20,$23,$29,$20,$25,$29,$20,$25,$29
		.BYTE $7F,$FE
byte_DF91:
		.BYTE $83,$E2,$1E,$22,$19,$22,$EF,$E2,$1B,$22,$16,$22,$EF,$20,$23,$1B
		.BYTE $23,$19,$23,$20,$23,$82,$1E,$7F,$7F,$12,$FE
