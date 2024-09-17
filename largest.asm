LXI H, 0xEFFF
MVI C, 0x08
INX H
MOV B, M
DCR C
LOOP:	INX H
		MOV A, M
        CMP B
        JC SKIP
        MOV B, A
SKIP:   DCR C
        JNZ LOOP
        LXI H, 0xF00C
        MOV M, B
        HLT
