 ;PC-G850V hello world 
 ;To run: assemble, then press CLS and type 'G0100'
 ORG 100H ;reserve mem
 JP MAIN ;skip data
MSG: DB 'HELLO WORLD' ;store our string 
PUTSTR EQU 0BFF1H ;inbuilt putstr routine
MAIN:LD HL, MSG ; entrypoint
 LD B, 11 ;num chars as param
 LD DE,0202H ; screen position
 CALL PUTSTR
 RET ; runs as a function, so return at end
 END ; end of program
