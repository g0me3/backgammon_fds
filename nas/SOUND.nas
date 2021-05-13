
		PROCESSOR 6502

		SEG.u RAM
		INCLUDE "..\ram.inc"

		SEG.u BANK0
		INCLUDE "..\BG-MAIN.inc"

		SEG   BANK1
		INCLUDE "..\SOUND.inc"

		SEG.u BANK2
		INCLUDE "..\BG-DEMO.inc"

		SEG.u BANK3
		INCLUDE "..\CP.inc"

		SEG.u BANK4
		INCLUDE "..\BG-FINAL.inc"
