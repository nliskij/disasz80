.nolist
#include "ti83plus.inc"
#define ProgStart   $9D95
.list
.org    ProgStart - 2
    .db t2ByteTok, tAsmCmp
    bcall(_ClrLCDFull)
    ld  hl, 0h
    ld  (PenCol), hl
    ld  hl, msg
    bcall(_PutS)
    bcall(_NewLine)
    ret
msg:
    .db "Hello world!", 0
.end
.end
