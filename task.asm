LDA 0x2404
MOV E, A
LDA 0x2403
MOV D, A
LDA 0x2402
MOV C, A
LDA 0x2405
MOV B, A
LDA 0x2401
ADD C
ADC D
ADC E
STA 0x2405
SUB C
STA 0x2403
SUB D
SUB E
ADD B
STA 0x2401
MOV D, A
ADD B
SUB D
SUB C
STA 0x2402
ADD E
SUB D
STA 0x2404
HLT