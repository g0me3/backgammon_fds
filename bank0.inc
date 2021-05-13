
		ORG $8000

		ECHO "PROGRAM BEGIN"
		ECHO "-------------"

_total_free	SET 0

		BANK_START $00

		INCBIN "..\copyrights.txt"

		INCLUDE "..\BG-MAIN.inc"
		INCLUDE "..\CP.inc"
		INCLUDE "..\SOUND.inc"
		INCLUDE "..\BG-FINAL.inc"

		LAST_BANK_END 0,$10000
