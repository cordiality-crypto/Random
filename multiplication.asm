LXI H, 0x1000
MOV A, M
CPI 0x00
JZ ZE
MOV B, A
INX H
MOV A, M
CPI 0x00
JZ ZE
MVI A, 0x00
MVI C, 0x00
ML:	ADD M
	JC CR
ES: DCR B
    JZ EN
    JMP ML
CR:	INR C
	JMP ES
EN:	INX H
	MOV M, A
    INX H
    MOV M, C
    HLT
ZE:	INX H
	INX H
    MVI M, 0x00
    INX H
    MVI M, 0x00
    HLT
