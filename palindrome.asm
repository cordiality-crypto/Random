LDA 0x8000
MVI C, 0x08
MOV H, A
LOOP:   RLC
        MOV H, A
        MOV A, D
        RAR
        MOV D, A
        DCR C
        JNZ LOOP
        MVI B, 0x00
        CMP H
        JZ CASE
BCK:    MOV A, B 
		    STA 0x80FF
        HLT
CASE:   MVI B, 0xFF
        JMP BCK
