
		ORG $C000

		BANK_START $03

		SECTION_START
		INCLUDE "..\BG-DEMO.inc"
		SECTION_END "BG-DEMO"

		SECTION_START
		INCLUDE "..\BG-MAIN.inc"
		SECTION_END "BG-MAIN"

		SECTION_START
		INCLUDE "..\CP.inc"
		SECTION_END "CP"

		INCBIN "..\copyrights.txt"

		LAST_BANK_END 3,$10000