START:	LXI H, 0xEFFF
  		  MVI D, 0x00
  		  MVI C, 0x08
  		  DCR C
  		  INX H
CHECK:	MOV A, M
		    INX H
        CMP M
        JC NEXT
        MOV B, M
        MOV M, A
        DCX H
        MOV M, B
        INX H
        MVI D, 0x01
NEXT:	  DCR C
		    JNZ CHECK
        MOV A, D
        RRC
        JC START
        HLT
