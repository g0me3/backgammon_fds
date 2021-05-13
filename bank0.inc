
		ORG $8000

		BANK_START $00

;		INCBIN "..\copyrights.txt"
		INCLUDE "..\BG-MAIN.inc"
		INCLUDE "..\CP.inc"
		INCLUDE "..\SOUND.inc"

		LAST_BANK_END 0,$10000
