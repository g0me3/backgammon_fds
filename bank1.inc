
		ORG $8000

		BANK_START $01

		SECTION_START
		INCLUDE "..\SOUND.inc"
		SECTION_END "SOUND"

		BANK_END 1,$C000