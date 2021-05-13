
;-------------C-O-N-S-T-A-N-T-S-----------------

DEBUG			EQU		0
OPTIMIZATION	EQU		0
BUGFIXES		EQU		0

LANG_EN			EQU		0
LANG_JP			EQU		1
LANR_RU			EQU		2

LANGUAGE		EQU		LANG_EN

;-------------------F-O-N-T-S-------------------

_0 	EQU	$00
_1 	EQU	$01
_2 	EQU	$02
_3 	EQU	$03
_4 	EQU	$04
_5 	EQU	$05
_6 	EQU	$06
_7 	EQU	$07
_8 	EQU	$08
_9 	EQU	$09

_A 	EQU	$11
_B 	EQU	$12
_C 	EQU	$13
_D 	EQU	$14
_E 	EQU	$15
_F 	EQU	$16
_G 	EQU	$17
_H 	EQU	$18
_I 	EQU	$19
_J 	EQU	$1A
_K 	EQU	$1B
_L 	EQU	$1C
_M 	EQU	$1D
_N 	EQU	$1E
_O 	EQU	$1F
_P 	EQU	$20
_Q 	EQU	$21
_R 	EQU	$22
_S 	EQU	$23
_T 	EQU	$24
_U 	EQU	$25
_V 	EQU	$26
_W 	EQU	$27
_X 	EQU	$28
_Y 	EQU	$29
_ex	EQU	$2A
_dt	EQU	$2B
__  EQU $2E

;--------------------A-P-U----------------------

;--------------D-E-B-U-G-G-I-N-G----------------

; {1} - destination offset
; {2} - opcode size
; {3} - opcode name
;
	MAC	ASSERT_SHORT_OFS
#if DEBUG=1
TMP_CMD_PC	SET	.
TMP_OFS		SET	[{1}-TMP_CMD_PC-{2}]
	#if TMP_OFS<-128
		ECHO "long",{3},"at",TMP_CMD_PC,"jumps to",{1},"distance",TMP_OFS
	#endif
	#if TMP_OFS>127
		ECHO "long",{3},"at",TMP_CMD_PC,"jumps to",{1},"distance",TMP_OFS
	#endif
#endif
	ENDM

	MAC	ALERT_SHORT_OFS
#if DEBUG=1
TMP_CMD_PC	SET	.
TMP_OFS		SET	[{1}-TMP_CMD_PC-{2}]
	#if TMP_OFS>=-128&&TMP_OFS<=127
		ECHO "short",{3},"at",TMP_CMD_PC,"jumps to",{1},"distance",TMP_OFS
	#endif
#endif
	ENDM

;------------S-T-R-U-C-T-U-R-E-S----------------

;---------------S-C-R-I-P-T-S-------------------

;---------G-A-M-E--S-P-E-C-I-F-I-C--------------

;----------------C-O-M-M-O-N--------------------

	MAC BANK_START
CUR_PRG_BANK	SET {1}
CUR_BANK_START	SET .
CUR_SEC_START	SET $FFFFFFFF
		ECHO "BANK",CUR_PRG_BANK," ORG ",[CUR_BANK_START>>12],"{"
	ENDM

STUB_SIZE		EQU	1
LAST_STUB_SIZE	EQU	6

	MAC	BANK_END
	#if {1}=$00
_total_free	SET 0
	#endif
_bank{1}_free	SET	[{2}-.-STUB_SIZE]
_total_free	SET [_total_free+_bank{1}_free]
	#if .>{2}-STUB_SIZE
		ECHO "} s =",[.-CUR_BANK_START],"EXCEEDED =",[0-_bank{1}_free]
	#else
		ECHO "} s =",[.-CUR_BANK_START],"FREE =",_bank{1}_free
	#endif
	#if .<{2}-STUB_SIZE
		ORG		{2}-STUB_SIZE-1
		.BYTE	$FF
	#endif
		ORG		{2}-STUB_SIZE
		.BYTE	$FF
	ENDM

	MAC	LAST_BANK_END
	#if {1}=$00
_total_free	SET 0
	#endif
_bank{1}_free	SET	[{2}-.-LAST_STUB_SIZE]
_total_free	SET [_total_free+_bank{1}_free]
	#if .>[{2}-LAST_STUB_SIZE]
		ECHO "} s =",[.-CUR_BANK_START],"EXCEEDED =",[0-_bank{1}_free]
	#else
		ECHO "} s =",[.-CUR_BANK_START],"FREE =",_bank{1}_free
	#endif
		ECHO "-------------";
		ECHO "total free =",_total_free
		ECHO ""
	#if .<{2}-LAST_STUB_SIZE
		ORG		{2}-LAST_STUB_SIZE-1
		.BYTE	$FF
	#endif
		ORG		{2}-LAST_STUB_SIZE
		.WORD NMI
		.WORD RESET
		.WORD IRQ
	ENDM

	MAC SECTION_START
#if CUR_SEC_START == $FFFFFFFF
CUR_SEC_START	SET	.
#else
		ECHO "WARNING! previous block isn't closed!"
#endif
	ENDM

	MAC SECTION_END
#if CUR_SEC_START != $FFFFFFFF
_CUR_SEC_END	SET .
		ECHO " * block size =",_CUR_SEC_END-CUR_SEC_START,"[",{1},"]"
CUR_SEC_START	SET $FFFFFFFF
#else
		ECHO "WARNING! there is no block start!"
#endif
	ENDM

;---------------A-R-I-T-H-M---------------------

	; \t\tLDA\t\t(.*)\n\t\tSTA\t\t(.*)\n\t\tLDA\t\t\1\+1\n\t\tSTA\t\t\2\+1\n
	; \t\tMOVW\t\2,\1\n
	;
	MAC	MOVW
		LDA		{2}
		STA		{1}
		LDA		{2}+1
		STA		{1}+1
	ENDM

	MAC	MOVD
		LDA		{2}
		STA		{1}
		LDA		{2}+1
		STA		{1}+1
		LDA		{2}+2
		STA		{1}+2
	ENDM

	; \t\tLDA\t\t#<\[(.*)\]\n\t\tSTA\t\t(.*)\n\t\tLDA\t\t#>\[\1\]\n\t\tSTA\t\t\2\+1\n
	; \t\tMOVWO\t\2,\1\n
	;
	MAC	MOVWO
		LDA		#<[{2}]
		STA		{1}
		LDA		#>[{2}]
		STA		{1}+1
	ENDM

	; \t\tLDA\t\t#\$(..)\n\t\tSTA\t\t(.*)\n\t\tLDA\t\t#\$(..)\n\t\tSTA\t\t\2\+1\n
	; \t\tMOVWI\t\2,$\3\1\n
	;
	MAC	MOVWI
	#if {2}==0
		LDA		#0
		STA		{1}
		STA		{1}+1
	#else
		LDA		#[[{2}>>0]&$FF]
		STA		{1}
		LDA		#[[{2}>>8]&$FF]
		STA		{1}+1
	#endif
	ENDM

	; \t\tLDA\t\t#\$(..)\n\t\tSTA\t\t(.*)\n\t\tLDA\t\t#\$(..)\n\t\tSTA\t\t\2\+1\n\t\tLDA\t\t#\$(..)\n\t\tSTA\t\t\2\+2\n
	; \t\tMOVDI\t\2,$\4\3\1\n
	;
	MAC	MOVDI
	#if {2}==0
		LDA		#0
		STA		{1}
		STA		{1}+1
		STA		{1}+2
	#else
		LDA		#[[{2}>>0 ]&$FF]
		STA		{1}
		LDA		#[[{2}>>8 ]&$FF]
		STA		{1}+1
		LDA		#[[{2}>>16]&$FF]
		STA		{1}+2
	#endif
	ENDM

	; \t\tINC\t\t(.*)\n\t\tBNE\t\t(.*)\n\t\tINC\t\t\1\+1\n\2:\n
	; \t\tINCW\t\1\n\2:
	;
	MAC	INCW
		INC		{1}
		BNE		.1
		INC		{1}+1
.1:
	ENDM

	MAC	ADDB
	#if {2}==#$02
		INC		{1}
		INC		{1}
	#else
		LDA		{1}
		CLC
		ADC		{2}
		STA		{1}
	#endif
	ENDM

	MAC	MADDB
		LDA		{2}
		CLC
		ADC		{3}
		STA		{1}
	ENDM

	; \t\tLDA\t\t(.*)\n\t\tADC\t\t\#\$00\n\t\tSTA\t\t\1\n
	; \t\tADCH\t\1\n
	;
	; adjust high hibble of 16-bit value when 8bit argument added
	;
	MAC	ADCH
		BCC		.1
		INC		{0}
.1:
	ENDM

	; \t\tLDA\t\t(.*)\n\t\tCLC\n\t\tADC\t\t(.*)\n\t\tSTA\t\t\1\n\t\tBCC\t\t(.*)\n\t\tINC\t\t\1\+1\n\3:
	; \t\tADDWB\t\1,\2\n\3:
	;
	MAC	ADDWB
		LDA		{1}
		CLC
		ADC		{2}
		STA		{1}
		BCC		.1
		INC		{1}+1
.1:
	ENDM

	; Add two 16-bit integer or fixed point values and put it
	; in third arg.
	;
	MAC	MADDW
		LDA		{2}
		CLC
		ADC		{3}
		STA		{1}
		LDA		{2}+1
		ADC		{3}+1
		STA		{1}+1
	ENDM

	MAC CMPW
		LDA		{1}
		CMP		{2}
		LDA		{1}+1
		SBC		{2}+1
	ENDM

	MAC CMPWI
		LDA		{1}
		CMP		#[[{2}>>0]&$FF]
		LDA		{1}+1
		SBC		#[[{2}>>8]&$FF]
	ENDM

	MAC	MSUBW
		LDA		{2}
		SEC
		SBC		{3}
		STA		{1}
		LDA		{2}+1
		SBC		{3}+1
		STA		{1}+1
	ENDM

	MAC	SUBB
	#if {2}==#$02
		DEC		{1}
		DEC		{1}
	#else
		LDA		{1}
		SEC
		SBC		{2}
		STA		{1}
	#endif
	ENDM

	MAC	MSUBB
		LDA		{2}
		SEC
		SBC		{3}
		STA		{1}
	ENDM

	; \t\tLDA\t\t(.*)\n\t\tSEC\n\t\tSBC\t\t\#\$(..)\n\t\tSTA\t\t\1\n\t\tLDA\t\t\1\+1\n\t\tSBC\t\t\#\$(..)\n\t\tSTA\t\t\1\+1\n\t\tBCS\t\t(.*)\n\t\tDEC\t\t\1\+2\n\4\:\n
	; \t\tSUBDI16\t\1,\$\3\2\n\4\:\n
	;
	; Subtract 16-bit Word from 24-bit Dword
	; in third arg.
	;
	MAC	SUBDI16
		LDA		{1}
		SEC
		SBC		#<[{2}]
		STA		{1}
		LDA		{1}+1
		SBC		#>[{2}]
		STA		{1}+1
		BCS		.1
		DEC		{1}+2
.1:
	ENDM

	; \t\tLDA\t\t(.*)\n\t\tSBC\t\t\#\$00\n\t\tSTA\t\t\1\n
	; \t\tSBCH\t\1\n
	;
	; adjust high hibble of 16-bit value when 8bit argument added
	;
	MAC	SBCH
		BCS		.1
		DEC		{0}
.1:
	ENDM


	; \t\tLDA\t\t(.*)\n\t\tSEC\n\t\tSBC\t\t(.*)\n\t\tSTA\t\t\1\n\t\tLDA\t\t\1\+1\n\t\tSBC\t\t\2\+1\n\t\tSTA\t\t\1\+1\n\t\tBCS\t\t(.*)\n\t\tDEC\t\t\1\+2\n\3\:\n
	; \t\tSUBDW\t\1,\2\n\3\:\n
	;
	MAC	SUBDW
		LDA		{1}
		SEC
		SBC		{2}
		STA		{1}
		LDA		{1}+1
		SBC		{2}+1
		STA		{1}+1
		BCS		.1
		DEC		{1}+2
.1:
	ENDM

	MAC	SUBD
		LDA		{1}
		SEC
		SBC		{2}
		STA		{1}
		LDA		{1}+1
		SBC		{2}+1
		STA		{1}+1
		LDA		{1}+2
		SBC		{2}+2
		STA		{1}+2
	ENDM

	MAC	MSUBD
		LDA		{2}
		SEC
		SBC		{3}
		STA		{1}
		LDA		{2}+1
		SBC		{3}+1
		STA		{1}+1
		LDA		{2}+2
		SBC		{3}+2
		STA		{1}+2
	ENDM
