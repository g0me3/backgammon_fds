		PROCESSOR 6502

		ORG	$0000

		.BYTE	"NES", $1A
		.BYTE	$04				; prg 16k banks
		.BYTE	$00				; chr 8k banks
		.BYTE	$20				; mapper lo
		.BYTE	$00				; mapper hi
		.BYTE	0, 0, 0, 0, 0, 0, 0, 0