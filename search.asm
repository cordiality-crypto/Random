MVI C, 0x08
LXI H, 0xF007
MVI A, 0xFF
LOOP:	  CMP M
		    JZ TRUE
        DCX H
        DCR C
        JZ ENDE
     	  JMP LOOP
ENDE:	  MVI A, 0x00
		    STA 0xF010
        HLT
TRUE:	  MVI A, 0xFF
		    STA 0xF010
        HLT; A IS THE NUM TO BE SEARCHED
