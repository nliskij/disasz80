#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int i = 0;
  int op_size = 0;
  FILE *fp = fopen(argv[1], "rb");
  fseek(fp, 0, SEEK_END);
  long fsize = ftell(fp);
  fseek(fp, 0, SEEK_SET);

  char *source = malloc(fsize + 1);
  fread(source, fsize, 1, fp);
  fclose(fp);

  source[fsize] = '\0';

  while (source[i] != '\0') {
    op_size = disas_op(source, i);
    i += op_size;
  }

  free(source);

  return 0;
}

int disas_op(unsigned char *code_buffer, int ptr) {
  unsigned char *code = code_buffer + ptr;
  int opbytes = 1;

  switch (*code) {
  case 0x00:
    printf("nop\n");
    opbytes = 1;
    break;
  case 0x01:
    printf("ld bc,%02x%02xh\n", code[2], code[1]);
    opbytes = 3;
    break;
  case 0x02:
    printf("ld (bc),a\n");
    opbytes = 1;
    break;
  case 0x03:
    printf("inc bc\n");
    opbytes = 1;
    break;
  case 0x04:
    printf("inc b\n");
    opbytes = 1;
    break;
  case 0x05:
    printf("dec b\n");
    opbytes = 1;
    break;
  case 0x06:
    printf("ld b,%02xh\n", code[1]);
    opbytes = 2;
    break;
  case 0x07:
    printf("rlca\n");
    opbytes = 1;
    break;
  case 0x08:
    printf("ex af,af'\n");
    opbytes = 1;
    break;
  case 0x09:
    printf("add hl,bc\n");
    opbytes = 1;
    break;
  case 0x0A:
    printf("ld a,(bc)\n");
    opbytes = 1;
    break;
  case 0x0B:
    printf("dec bc\n");
    opbytes = 1;
    break;
  case 0x0C:
    printf("inc c\n");
    opbytes = 1;
    break;
  case 0x0D:
    printf("dec c\n");
    opbytes = 1;
    break;
  case 0x0E:
    printf("ld c,%02xh\n", code[1]);
    opbytes = 2;
    break;
  case 0x0F:
    printf("rrca\n");
    opbytes = 1;
    break;
  case 0x10:
    printf("djnz (pc+%02xh)\n", code[1]);
    opbytes = 2;
    break;
  case 0x11:
    printf("ld de,%02x%02xh\n", code[2], code[1]);
    opbytes = 3;
    break;
  case 0x12:
    printf("ld (de),a\n");
    opbytes = 1;
    break;
  case 0x13:
    printf("inc de\n");
    opbytes = 1;
    break;
  case 0x14:
    printf("inc d\n");
    opbytes = 1;
    break;
  case 0x15:
    printf("dec d\n");
    opbytes = 1;
    break;
  case 0x16:
    printf("ld d,%02xh\n", code[1]);
    opbytes = 2;
    break;
  case 0x17:
    printf("rla\n");
    opbytes = 1;
    break;
  case 0x18:
    printf("jr (pc+%02xh)\n", code[1]);
    opbytes = 2;
    break;
  case 0x19:
    printf("add hl,de\n");
    opbytes = 1;
    break;
  case 0x1A:
    printf("ld a,(de)\n");
    opbytes = 1;
    break;
  case 0x1B:
    printf("dec de\n");
    opbytes = 1;
    break;
  case 0x1C:
    printf("inc e\n");
    opbytes = 1;
    break;
  case 0x1D:
    printf("dec e\n");
    opbytes = 1;
    break;
  case 0x1E:
    printf("ld e,%02xh\n", code[1]);
    opbytes = 2;
    break;
  case 0x1F:
    printf("rra\n");
    opbytes = 1;
    break;
  case 0x20:
    printf("jr nz,(pc+%02xh)\n", code[1]);
    opbytes = 2;
    break;
  case 0x21:
    printf("ld hl,%02x%02xh\n", code[2], code[1]);
    opbytes = 3;
    break;
  case 0x22:
    printf("ld (%02x%02xh),hl\n", code[2], code[1]);
    opbytes = 3;
    break;
  case 0x23:
    printf("inc hl\n");
    opbytes = 1;
    break;
  case 0x24:
    printf("inc h\n");
    opbytes = 1;
    break;
  case 0x25:
    printf("dec h\n");
    opbytes = 1;
    break;
  case 0x26:
    printf("ld h,%02xh\n", code[1]);
    opbytes = 2;
    break;
  case 0x27:
    printf("daa\n");
    opbytes = 1;
    break;
  case 0x28:
    printf("jr z,(pc+%02xh)\n", code[1]);
    opbytes = 2;
    break;
  case 0x29:
    printf("add hl,hl\n");
    opbytes = 1;
    break;
  case 0x2A:
    printf("ld hl,(%02x%02xh)\n", code[2], code[1]);
    opbytes = 3;
    break;
  case 0x2B:
    printf("dec hl\n");
    opbytes = 1;
    break;
  case 0x2C:
    printf("inc l\n");
    opbytes = 1;
    break;
  case 0x2D:
    printf("dec l\n");
    opbytes = 1;
    break;
  case 0x2E:
    printf("ld l,%02xh\n", code[1]);
    opbytes = 2;
    break;
  case 0x2F:
    printf("cpl\n");
    opbytes = 1;
    break;
  case 0x30:
    printf("jr nc,(pc+%02xh)\n", code[1]);
    opbytes = 2;
    break;
  case 0x31:
    printf("ld sp,%02x%02xh\n", code[2], code[1]);
    opbytes = 3;
    break;
  case 0x32:
    printf("ld (%02x%02xh),a\n", code[2], code[1]);
    opbytes = 3;
    break;
  case 0x33:
    printf("inc sp\n");
    opbytes = 1;
    break;
  case 0x34:
    printf("inc (hl)\n");
    opbytes = 1;
    break;
  case 0x35:
    printf("dec (hl)\n");
    opbytes = 1;
    break;
  case 0x36:
    printf("ld (hl),%02xh\n", code[1]);
    opbytes = 2;
    break;
  case 0x37:
    printf("scf\n");
    opbytes = 1;
    break;
  case 0x38:
    printf("jr c,(pc+%02xh)\n", code[1]);
    opbytes = 2;
    break;
  case 0x39:
    printf("add hl,sp\n");
    opbytes = 1;
    break;
  case 0x3A:
    printf("ld a,(%02x%02xh)\n", code[2], code[1]);
    opbytes = 3;
    break;
  case 0x3B:
    printf("dec sp\n");
    opbytes = 1;
    break;
  case 0x3C:
    printf("inc a\n");
    opbytes = 1;
    break;
  case 0x3D:
    printf("dec a\n");
    opbytes = 1;
    break;
  case 0x3E:
    printf("ld a,%02xh\n", code[1]);
    opbytes = 2;
    break;
  case 0x3F:
    printf("ccf\n");
    opbytes = 1;
    break;
  case 0x40:
    printf("ld b,b\n");
    opbytes = 1;
    break;
  case 0x41:
    printf("ld b,c\n");
    opbytes = 1;
    break;
  case 0x42:
    printf("ld b,d\n");
    opbytes = 1;
    break;
  case 0x43:
    printf("ld b,e\n");
    opbytes = 1;
    break;
  case 0x44:
    printf("ld b,h\n");
    opbytes = 1;
    break;
  case 0x45:
    printf("ld b,l\n");
    opbytes = 1;
    break;
  case 0x46:
    printf("ld b,(hl)\n");
    opbytes = 1;
    break;
  case 0x47:
    printf("ld b,a\n");
    opbytes = 1;
    break;
  case 0x48:
    printf("ld c,b\n");
    opbytes = 1;
    break;
  case 0x49:
    printf("ld c,c\n");
    opbytes = 1;
    break;
  case 0x4A:
    printf("ld c,d\n");
    opbytes = 1;
    break;
  case 0x4B:
    printf("ld c,e\n");
    opbytes = 1;
    break;
  case 0x4C:
    printf("ld c,h\n");
    opbytes = 1;
    break;
  case 0x4D:
    printf("ld c,l\n");
    opbytes = 1;
    break;
  case 0x4E:
    printf("ld c,(hl)\n");
    opbytes = 1;
    break;
  case 0x4F:
    printf("ld c,a\n");
    opbytes = 1;
    break;
  case 0x50:
    printf("ld d,b\n");
    opbytes = 1;
    break;
  case 0x51:
    printf("ld d,c\n");
    opbytes = 1;
    break;
  case 0x52:
    printf("ld d,d\n");
    opbytes = 1;
    break;
  case 0x53:
    printf("ld d,e\n");
    opbytes = 1;
    break;
  case 0x54:
    printf("ld d,h\n");
    opbytes = 1;
    break;
  case 0x55:
    printf("ld d,l\n");
    opbytes = 1;
    break;
  case 0x56:
    printf("ld d,(hl)\n");
    opbytes = 1;
    break;
  case 0x57:
    printf("ld d,a\n");
    opbytes = 1;
    break;
  case 0x58:
    printf("ld e,b\n");
    opbytes = 1;
    break;
  case 0x59:
    printf("ld e,c\n");
    opbytes = 1;
    break;
  case 0x5A:
    printf("ld e,d\n");
    opbytes = 1;
    break;
  case 0x5B:
    printf("ld e,e\n");
    opbytes = 1;
    break;
  case 0x5C:
    printf("ld e,h\n");
    opbytes = 1;
    break;
  case 0x5D:
    printf("ld e,l\n");
    opbytes = 1;
    break;
  case 0x5E:
    printf("ld e,(hl)\n");
    opbytes = 1;
    break;
  case 0x5F:
    printf("ld e,a\n");
    opbytes = 1;
    break;
  case 0x60:
    printf("ld h,b\n");
    opbytes = 1;
    break;
  case 0x61:
    printf("ld h,c\n");
    opbytes = 1;
    break;
  case 0x62:
    printf("ld h,d\n");
    opbytes = 1;
    break;
  case 0x63:
    printf("ld h,e\n");
    opbytes = 1;
    break;
  case 0x64:
    printf("ld h,h\n");
    opbytes = 1;
    break;
  case 0x65:
    printf("ld h,l\n");
    opbytes = 1;
    break;
  case 0x66:
    printf("ld h,(hl)\n");
    opbytes = 1;
    break;
  case 0x67:
    printf("ld h,a\n");
    opbytes = 1;
    break;
  case 0x68:
    printf("ld l,b\n");
    opbytes = 1;
    break;
  case 0x69:
    printf("ld l,c\n");
    opbytes = 1;
    break;
  case 0x6A:
    printf("ld l,d\n");
    opbytes = 1;
    break;
  case 0x6B:
    printf("ld l,e\n");
    opbytes = 1;
    break;
  case 0x6C:
    printf("ld l,h\n");
    opbytes = 1;
    break;
  case 0x6D:
    printf("ld l,l\n");
    opbytes = 1;
    break;
  case 0x6E:
    printf("ld l,(hl)\n");
    opbytes = 1;
    break;
  case 0x6F:
    printf("ld l,a\n");
    opbytes = 1;
    break;
  case 0x70:
    printf("ld (hl),b\n");
    opbytes = 1;
    break;
  case 0x71:
    printf("ld (hl),c\n");
    opbytes = 1;
    break;
  case 0x72:
    printf("ld (hl),d\n");
    opbytes = 1;
    break;
  case 0x73:
    printf("ld (hl),e\n");
    opbytes = 1;
    break;
  case 0x74:
    printf("ld (hl),h\n");
    opbytes = 1;
    break;
  case 0x75:
    printf("ld (hl),l\n");
    opbytes = 1;
    break;
  case 0x76:
    printf("halt\n");
    opbytes = 1;
    break;
  case 0x77:
    printf("ld (hl),a\n");
    opbytes = 1;
    break;
  case 0x78:
    printf("ld a,b\n");
    opbytes = 1;
    break;
  case 0x79:
    printf("ld a,c\n");
    opbytes = 1;
    break;
  case 0x7A:
    printf("ld a,d\n");
    opbytes = 1;
    break;
  case 0x7B:
    printf("ld a,e\n");
    opbytes = 1;
    break;
  case 0x7C:
    printf("ld a,h\n");
    opbytes = 1;
    break;
  case 0x7D:
    printf("ld a,l\n");
    opbytes = 1;
    break;
  case 0x7E:
    printf("ld a,(hl)\n");
    opbytes = 1;
    break;
  case 0x7F:
    printf("ld a,a\n");
    opbytes = 1;
    break;
  case 0x80:
    printf("add a,b\n");
    opbytes = 1;
    break;
  case 0x81:
    printf("add a,c\n");
    opbytes = 1;
    break;
  case 0x82:
    printf("add a,d\n");
    opbytes = 1;
    break;
  case 0x83:
    printf("add a,e\n");
    opbytes = 1;
    break;
  case 0x84:
    printf("add a,h\n");
    opbytes = 1;
    break;
  case 0x85:
    printf("add a,l\n");
    opbytes = 1;
    break;
  case 0x86:
    printf("add a,(hl)\n");
    opbytes = 1;
    break;
  case 0x87:
    printf("add a,a\n");
    opbytes = 1;
    break;
  case 0x88:
    printf("adc a,b\n");
    opbytes = 1;
    break;
  case 0x89:
    printf("adc a,c\n");
    opbytes = 1;
    break;
  case 0x8A:
    printf("adc a,d\n");
    opbytes = 1;
    break;
  case 0x8B:
    printf("adc a,e\n");
    opbytes = 1;
    break;
  case 0x8C:
    printf("adc a,h\n");
    opbytes = 1;
    break;
  case 0x8D:
    printf("adc a,l\n");
    opbytes = 1;
    break;
  case 0x8E:
    printf("adc a,(hl)\n");
    opbytes = 1;
    break;
  case 0x8F:
    printf("adc a,a\n");
    opbytes = 1;
    break;
  case 0x90:
    printf("sub b\n");
    opbytes = 1;
    break;
  case 0x91:
    printf("sub c\n");
    opbytes = 1;
    break;
  case 0x92:
    printf("sub d\n");
    opbytes = 1;
    break;
  case 0x93:
    printf("sub e\n");
    opbytes = 1;
    break;
  case 0x94:
    printf("sub h\n");
    opbytes = 1;
    break;
  case 0x95:
    printf("sub l\n");
    opbytes = 1;
    break;
  case 0x96:
    printf("sub (hl)\n");
    opbytes = 1;
    break;
  case 0x97:
    printf("sub a\n");
    opbytes = 1;
    break;
  case 0x98:
    printf("sbc a,b\n");
    opbytes = 1;
    break;
  case 0x99:
    printf("sbc a,c\n");
    opbytes = 1;
    break;
  case 0x9A:
    printf("sbc a,d\n");
    opbytes = 1;
    break;
  case 0x9B:
    printf("sbc a,e\n");
    opbytes = 1;
    break;
  case 0x9C:
    printf("sbc a,h\n");
    opbytes = 1;
    break;
  case 0x9D:
    printf("sbc a,l\n");
    opbytes = 1;
    break;
  case 0x9E:
    printf("sbc a,(hl)\n");
    opbytes = 1;
    break;
  case 0x9F:
    printf("sbc a,a\n");
    opbytes = 1;
    break;
  case 0xA0:
    printf("and b\n");
    opbytes = 1;
    break;
  case 0xA1:
    printf("and c\n");
    opbytes = 1;
    break;
  case 0xA2:
    printf("and d\n");
    opbytes = 1;
    break;
  case 0xA3:
    printf("and e\n");
    opbytes = 1;
    break;
  case 0xA4:
    printf("and h\n");
    opbytes = 1;
    break;
  case 0xA5:
    printf("and l\n");
    opbytes = 1;
    break;
  case 0xA6:
    printf("and (hl)\n");
    opbytes = 1;
    break;
  case 0xA7:
    printf("and a\n");
    opbytes = 1;
    break;
  case 0xA8:
    printf("xor b\n");
    opbytes = 1;
    break;
  case 0xA9:
    printf("xor c\n");
    opbytes = 1;
    break;
  case 0xAA:
    printf("xor d\n");
    opbytes = 1;
    break;
  case 0xAB:
    printf("xor e\n");
    opbytes = 1;
    break;
  case 0xAC:
    printf("xor h\n");
    opbytes = 1;
    break;
  case 0xAD:
    printf("xor l\n");
    opbytes = 1;
    break;
  case 0xAE:
    printf("xor (hl)\n");
    opbytes = 1;
    break;
  case 0xAF:
    printf("xor a\n");
    opbytes = 1;
    break;
  case 0xB0:
    printf("or b\n");
    opbytes = 1;
    break;
  case 0xB1:
    printf("or c\n");
    opbytes = 1;
    break;
  case 0xB2:
    printf("or d\n");
    opbytes = 1;
    break;
  case 0xB3:
    printf("or e\n");
    opbytes = 1;
    break;
  case 0xB4:
    printf("or h\n");
    opbytes = 1;
    break;
  case 0xB5:
    printf("or l\n");
    opbytes = 1;
    break;
  case 0xB6:
    printf("or (hl)\n");
    opbytes = 1;
    break;
  case 0xB7:
    printf("or a\n");
    opbytes = 1;
    break;
  case 0xB8:
    printf("cp b\n");
    opbytes = 1;
    break;
  case 0xB9:
    printf("cp c\n");
    opbytes = 1;
    break;
  case 0xBA:
    printf("cp d\n");
    opbytes = 1;
    break;
  case 0xBB:
    printf("cp e\n");
    opbytes = 1;
    break;
  case 0xBC:
    printf("cp h\n");
    opbytes = 1;
    break;
  case 0xBD:
    printf("cp l\n");
    opbytes = 1;
    break;
  case 0xBE:
    printf("cp (hl)\n");
    opbytes = 1;
    break;
  case 0xBF:
    printf("cp a\n");
    opbytes = 1;
    break;
  case 0xC0:
    printf("ret nz\n");
    opbytes = 1;
    break;
  case 0xC1:
    printf("pop bc\n");
    opbytes = 1;
    break;
  case 0xC2:
    printf("jp nz,(%02x%02xh)\n", code[2], code[1]);
    opbytes = 3;
    break;
  case 0xC3:
    printf("jp (%02x%02xh)\n", code[2], code[1]);
    opbytes = 3;
    break;
  case 0xC4:
    printf("call nz,(%02x%02xh)\n", code[2], code[1]);
    opbytes = 3;
    break;
  case 0xC5:
    printf("push bc\n");
    opbytes = 1;
    break;
  case 0xC6:
    printf("add a,%02xh\n", code[1]);
    opbytes = 2;
    break;
  case 0xC7:
    printf("rst 0h\n");
    opbytes = 1;
    break;
  case 0xC8:
    printf("ret z\n");
    opbytes = 1;
    break;
  case 0xC9:
    printf("ret\n");
    opbytes = 1;
    break;
  case 0xCA:
    printf("jp z,(%02x%02xh)\n", code[2], code[1]);
    opbytes = 3;
    break;
  case 0xCC:
    printf("call z,(%02x%02xh)\n", code[2], code[1]);
    opbytes = 3;
    break;
  case 0xCD:
    printf("call (%02x%02xh)\n", code[2], code[1]);
    opbytes = 3;
    break;
  case 0xCE:
    printf("adc a,%02xh\n", code[1]);
    opbytes = 2;
    break;
  case 0xCF:
    printf("rst 8h\n");
    opbytes = 1;
    break;
  case 0xD0:
    printf("ret nc\n");
    opbytes = 1;
    break;
  case 0xD1:
    printf("pop de\n");
    opbytes = 1;
    break;
  case 0xD2:
    printf("jp nc,(%02x%02xh)\n", code[2], code[1]);
    opbytes = 3;
    break;
  case 0xD3:
    printf("out (%02xh),a\n", code[1]);
    opbytes = 2;
    break;
  case 0xD4:
    printf("call nc,(%02x%02xh)\n", code[2], code[1]);
    opbytes = 3;
    break;
  case 0xD5:
    printf("push de\n");
    opbytes = 1;
    break;
  case 0xD6:
    printf("sub %02xh\n", code[1]);
    opbytes = 2;
    break;
  case 0xD7:
    printf("rst 10h\n");
    opbytes = 1;
    break;
  case 0xD8:
    printf("ret c\n");
    opbytes = 1;
    break;
  case 0xD9:
    printf("exx\n");
    opbytes = 1;
    break;
  case 0xDA:
    printf("jp c,(%02x%02xh)\n", code[2], code[1]);
    opbytes = 3;
    break;
  case 0xDB:
    printf("in a,(%02xh)\n", code[1]);
    opbytes = 2;
    break;
  case 0xDC:
    printf("call c,(%02x%02xh)\n", code[2], code[1]);
    opbytes = 3;
    break;
  case 0xDE:
    printf("sbc a,%02xh\n", code[1]);
    opbytes = 2;
    break;
  case 0xDF:
    printf("rst 18h\n");
    opbytes = 1;
    break;
  case 0xE0:
    printf("ret po\n");
    opbytes = 1;
    break;
  case 0xE1:
    printf("pop hl\n");
    opbytes = 1;
    break;
  case 0xE2:
    printf("jp po,(%02x%02xh)\n", code[2], code[1]);
    opbytes = 3;
    break;
  case 0xE3:
    printf("ex (sp),hl\n");
    opbytes = 1;
    break;
  case 0xE4:
    printf("call po,(%02x%02xh)\n", code[2], code[1]);
    opbytes = 3;
    break;
  case 0xE5:
    printf("push hl\n");
    opbytes = 1;
    break;
  case 0xE6:
    printf("and %02xh\n", code[1]);
    opbytes = 2;
    break;
  case 0xE7:
    printf("rst 20h\n");
    opbytes = 1;
    break;
  case 0xE8:
    printf("ret pe\n");
    opbytes = 1;
    break;
  case 0xE9:
    printf("jp (hl)\n");
    opbytes = 1;
    break;
  case 0xEA:
    printf("jp pe,(%02x%02xh)\n", code[2], code[1]);
    opbytes = 3;
    break;
  case 0xEB:
    printf("ex de,hl\n");
    opbytes = 1;
    break;
  case 0xEC:
    printf("call pe,(%02x%02xh)\n", code[2], code[1]);
    opbytes = 3;
    break;
  case 0xEE:
    printf("xor %02xh\n", code[1]);
    opbytes = 2;
    break;
  case 0xEF:
    printf("rst 28h\n");
    opbytes = 1;
    break;
  case 0xF0:
    printf("ret p\n");
    opbytes = 1;
    break;
  case 0xF1:
    printf("pop af\n");
    opbytes = 1;
    break;
  case 0xF2:
    printf("jp p,(%02x%02xh)\n", code[2], code[1]);
    opbytes = 3;
    break;
  case 0xF3:
    printf("di\n");
    opbytes = 1;
    break;
  case 0xF4:
    printf("call p,(%02x%02xh)\n", code[2], code[1]);
    opbytes = 3;
    break;
  case 0xF5:
    printf("push af\n");
    opbytes = 1;
    break;
  case 0xF6:
    printf("or %02xh\n", code[1]);
    opbytes = 2;
    break;
  case 0xF7:
    printf("rst 30h\n");
    opbytes = 1;
    break;
  case 0xF8:
    printf("ret m\n");
    opbytes = 1;
    break;
  case 0xF9:
    printf("ld sp,hl\n");
    opbytes = 1;
    break;
  case 0xFA:
    printf("jp m,(%02x%02xh)\n", code[2], code[1]);
    opbytes = 3;
    break;
  case 0xFB:
    printf("ei\n");
    opbytes = 1;
    break;
  case 0xFC:
    printf("call m,(%02x%02xh)\n", code[2], code[1]);
    opbytes = 3;
    break;
  case 0xFE:
    printf("cp %02xh\n", code[1]);
    opbytes = 2;
    break;
  case 0xFF:
    printf("rst 38h\n");
    opbytes = 1;
    break;
  case 0xED:
    switch (*(code + 1)) {
    case 0x40:
      printf("in b,(c)\n");
      opbytes = 2;
      break;
    case 0x41:
      printf("out (c),b\n");
      opbytes = 2;
      break;
    case 0x42:
      printf("sbc hl,bc\n");
      opbytes = 2;
      break;
    case 0x43:
      printf("ld (%02%02xh),bc\n", code[2], code[1]);
      opbytes = 4;
      break;
    case 0x44:
      printf("neg\n");
      opbytes = 2;
      break;
    case 0x45:
      printf("retn\n");
      opbytes = 2;
      break;
    case 0x46:
      printf("im 0\n");
      opbytes = 2;
      break;
    case 0x47:
      printf("ld i,a\n");
      opbytes = 2;
      break;
    case 0x48:
      printf("in c,(c)\n");
      opbytes = 2;
      break;
    case 0x49:
      printf("out (c),c\n");
      opbytes = 2;
      break;
    case 0x4A:
      printf("adc hl,bc\n");
      opbytes = 2;
      break;
    case 0x4B:
      printf("ld bc,(%02%02xh)\n", code[2], code[1]);
      opbytes = 4;
      break;
    case 0x4C:
      printf("neg\n");
      opbytes = 2;
      break;
    case 0x4D:
      printf("reti\n");
      opbytes = 2;
      break;
    case 0x4E:
      printf("im 0/1\n");
      opbytes = 2;
      break;
    case 0x4F:
      printf("ld r,a\n");
      opbytes = 2;
      break;
    case 0x50:
      printf("in d,(c)\n");
      opbytes = 2;
      break;
    case 0x51:
      printf("out (c),d\n");
      opbytes = 2;
      break;
    case 0x52:
      printf("sbc hl,de\n");
      opbytes = 2;
      break;
    case 0x53:
      printf("ld (%02%02xh),de\n", code[2], code[1]);
      opbytes = 4;
      break;
    case 0x54:
      printf("neg\n");
      opbytes = 2;
      break;
    case 0x55:
      printf("retn\n");
      opbytes = 2;
      break;
    case 0x56:
      printf("im 1\n");
      opbytes = 2;
      break;
    case 0x57:
      printf("ld a,i\n");
      opbytes = 2;
      break;
    case 0x58:
      printf("in e,(c)\n");
      opbytes = 2;
      break;
    case 0x59:
      printf("out (c),e\n");
      opbytes = 2;
      break;
    case 0x5A:
      printf("adc hl,de\n");
      opbytes = 2;
      break;
    case 0x5B:
      printf("ld de,(%02%02xh)\n", code[2], code[1]);
      opbytes = 4;
      break;
    case 0x5C:
      printf("neg\n");
      opbytes = 2;
      break;
    case 0x5D:
      printf("retn\n");
      opbytes = 2;
      break;
    case 0x5E:
      printf("im 2\n");
      opbytes = 2;
      break;
    case 0x5F:
      printf("ld a,r\n");
      opbytes = 2;
      break;
    case 0x60:
      printf("in h,(c)\n");
      opbytes = 2;
      break;
    case 0x61:
      printf("out (c),h\n");
      opbytes = 2;
      break;
    case 0x62:
      printf("sbc hl,hl\n");
      opbytes = 2;
      break;
    case 0x63:
      printf("ld (%02%02xh),hl\n", code[2], code[1]);
      opbytes = 4;
      break;
    case 0x64:
      printf("neg\n");
      opbytes = 2;
      break;
    case 0x65:
      printf("retn\n");
      opbytes = 2;
      break;
    case 0x66:
      printf("im 0\n");
      opbytes = 2;
      break;
    case 0x67:
      printf("rrd\n");
      opbytes = 2;
      break;
    case 0x68:
      printf("in l,(c)\n");
      opbytes = 2;
      break;
    case 0x69:
      printf("out (c),l\n");
      opbytes = 2;
      break;
    case 0x6A:
      printf("adc hl,hl\n");
      opbytes = 2;
      break;
    case 0x6B:
      printf("ld hl,(%02%02xh)\n", code[2], code[1]);
      opbytes = 4;
      break;
    case 0x6C:
      printf("neg\n");
      opbytes = 2;
      break;
    case 0x6D:
      printf("retn\n");
      opbytes = 2;
      break;
    case 0x6E:
      printf("im 0/1\n");
      opbytes = 2;
      break;
    case 0x6F:
      printf("rld\n");
      opbytes = 2;
      break;
    case 0x70:
      printf("in f,(c) / in (c)\n");
      opbytes = 2;
      break;
    case 0x71:
      printf("out (c),0\n");
      opbytes = 2;
      break;
    case 0x72:
      printf("sbc hl,sp\n");
      opbytes = 2;
      break;
    case 0x73:
      printf("ld (%02%02xh),sp\n", code[2], code[1]);
      opbytes = 4;
      break;
    case 0x74:
      printf("neg\n");
      opbytes = 2;
      break;
    case 0x75:
      printf("retn\n");
      opbytes = 2;
      break;
    case 0x76:
      printf("im 1\n");
      opbytes = 2;
      break;
    case 0x78:
      printf("in a,(c)\n");
      opbytes = 2;
      break;
    case 0x79:
      printf("out (c),a\n");
      opbytes = 2;
      break;
    case 0x7A:
      printf("adc hl,sp\n");
      opbytes = 2;
      break;
    case 0x7B:
      printf("ld sp,(%02%02xh)\n", code[2], code[1]);
      opbytes = 4;
      break;
    case 0x7C:
      printf("neg\n");
      opbytes = 2;
      break;
    case 0x7D:
      printf("retn\n");
      opbytes = 2;
      break;
    case 0x7E:
      printf("im 2\n");
      opbytes = 2;
      break;
    case 0xA0:
      printf("ldi\n");
      opbytes = 2;
      break;
    case 0xA1:
      printf("cpi\n");
      opbytes = 2;
      break;
    case 0xA2:
      printf("ini\n");
      opbytes = 2;
      break;
    case 0xA3:
      printf("outi\n");
      opbytes = 2;
      break;
    case 0xA8:
      printf("ldd\n");
      opbytes = 2;
      break;
    case 0xA9:
      printf("cpd\n");
      opbytes = 2;
      break;
    case 0xAA:
      printf("ind\n");
      opbytes = 2;
      break;
    case 0xAB:
      printf("outd\n");
      opbytes = 2;
      break;
    case 0xB0:
      printf("ldir\n");
      opbytes = 2;
      break;
    case 0xB1:
      printf("cpir\n");
      opbytes = 2;
      break;
    case 0xB2:
      printf("inir\n");
      opbytes = 2;
      break;
    case 0xB3:
      printf("otir\n");
      opbytes = 2;
      break;
    case 0xB8:
      printf("lddr\n");
      opbytes = 2;
      break;
    case 0xB9:
      printf("cpdr\n");
      opbytes = 2;
      break;
    case 0xBA:
      printf("indr\n");
      opbytes = 2;
      break;
    case 0xBB:
      printf("otdr\n");
      opbytes = 2;
      break;
    }
  case 0xCB:
    switch (*(code + 1)) {
    case 0x00:
      printf("rlc b\n");
      opbytes = 2;
      break;
    case 0x01:
      printf("rlc c\n");
      opbytes = 2;
      break;
    case 0x02:
      printf("rlc d\n");
      opbytes = 2;
      break;
    case 0x03:
      printf("rlc e\n");
      opbytes = 2;
      break;
    case 0x04:
      printf("rlc h\n");
      opbytes = 2;
      break;
    case 0x05:
      printf("rlc l\n");
      opbytes = 2;
      break;
    case 0x06:
      printf("rlc (hl)\n");
      opbytes = 2;
      break;
    case 0x07:
      printf("rlc a\n");
      opbytes = 2;
      break;
    case 0x08:
      printf("rrc b\n");
      opbytes = 2;
      break;
    case 0x09:
      printf("rrc c\n");
      opbytes = 2;
      break;
    case 0x0A:
      printf("rrc d\n");
      opbytes = 2;
      break;
    case 0x0B:
      printf("rrc e\n");
      opbytes = 2;
      break;
    case 0x0C:
      printf("rrc h\n");
      opbytes = 2;
      break;
    case 0x0D:
      printf("rrc l\n");
      opbytes = 2;
      break;
    case 0x0E:
      printf("rrc (hl)\n");
      opbytes = 2;
      break;
    case 0x0F:
      printf("rrc a\n");
      opbytes = 2;
      break;
    case 0x10:
      printf("rl b\n");
      opbytes = 2;
      break;
    case 0x11:
      printf("rl c\n");
      opbytes = 2;
      break;
    case 0x12:
      printf("rl d\n");
      opbytes = 2;
      break;
    case 0x13:
      printf("rl e\n");
      opbytes = 2;
      break;
    case 0x14:
      printf("rl h\n");
      opbytes = 2;
      break;
    case 0x15:
      printf("rl l\n");
      opbytes = 2;
      break;
    case 0x16:
      printf("rl (hl)\n");
      opbytes = 2;
      break;
    case 0x17:
      printf("rl a\n");
      opbytes = 2;
      break;
    case 0x18:
      printf("rr b\n");
      opbytes = 2;
      break;
    case 0x19:
      printf("rr c\n");
      opbytes = 2;
      break;
    case 0x1A:
      printf("rr d\n");
      opbytes = 2;
      break;
    case 0x1B:
      printf("rr e\n");
      opbytes = 2;
      break;
    case 0x1C:
      printf("rr h\n");
      opbytes = 2;
      break;
    case 0x1D:
      printf("rr l\n");
      opbytes = 2;
      break;
    case 0x1E:
      printf("rr (hl)\n");
      opbytes = 2;
      break;
    case 0x1F:
      printf("rr a\n");
      opbytes = 2;
      break;
    case 0x20:
      printf("sla b\n");
      opbytes = 2;
      break;
    case 0x21:
      printf("sla c\n");
      opbytes = 2;
      break;
    case 0x22:
      printf("sla d\n");
      opbytes = 2;
      break;
    case 0x23:
      printf("sla e\n");
      opbytes = 2;
      break;
    case 0x24:
      printf("sla h\n");
      opbytes = 2;
      break;
    case 0x25:
      printf("sla l\n");
      opbytes = 2;
      break;
    case 0x26:
      printf("sla (hl)\n");
      opbytes = 2;
      break;
    case 0x27:
      printf("sla a\n");
      opbytes = 2;
      break;
    case 0x28:
      printf("sra b\n");
      opbytes = 2;
      break;
    case 0x29:
      printf("sra c\n");
      opbytes = 2;
      break;
    case 0x2A:
      printf("sra d\n");
      opbytes = 2;
      break;
    case 0x2B:
      printf("sra e\n");
      opbytes = 2;
      break;
    case 0x2C:
      printf("sra h\n");
      opbytes = 2;
      break;
    case 0x2D:
      printf("sra l\n");
      opbytes = 2;
      break;
    case 0x2E:
      printf("sra (hl)\n");
      opbytes = 2;
      break;
    case 0x2F:
      printf("sra a\n");
      opbytes = 2;
      break;
    case 0x30:
      printf("sll b\n");
      opbytes = 2;
      break;
    case 0x31:
      printf("sll c\n");
      opbytes = 2;
      break;
    case 0x32:
      printf("sll d\n");
      opbytes = 2;
      break;
    case 0x33:
      printf("sll e\n");
      opbytes = 2;
      break;
    case 0x34:
      printf("sll h\n");
      opbytes = 2;
      break;
    case 0x35:
      printf("sll l\n");
      opbytes = 2;
      break;
    case 0x36:
      printf("sll (hl)\n");
      opbytes = 2;
      break;
    case 0x37:
      printf("sll a\n");
      opbytes = 2;
      break;
    case 0x38:
      printf("srl b\n");
      opbytes = 2;
      break;
    case 0x39:
      printf("srl c\n");
      opbytes = 2;
      break;
    case 0x3A:
      printf("srl d\n");
      opbytes = 2;
      break;
    case 0x3B:
      printf("srl e\n");
      opbytes = 2;
      break;
    case 0x3C:
      printf("srl h\n");
      opbytes = 2;
      break;
    case 0x3D:
      printf("srl l\n");
      opbytes = 2;
      break;
    case 0x3E:
      printf("srl (hl)\n");
      opbytes = 2;
      break;
    case 0x3F:
      printf("srl a\n");
      opbytes = 2;
      break;
    case 0x40:
      printf("bit 0,b\n");
      opbytes = 2;
      break;
    case 0x41:
      printf("bit 0,c\n");
      opbytes = 2;
      break;
    case 0x42:
      printf("bit 0,d\n");
      opbytes = 2;
      break;
    case 0x43:
      printf("bit 0,e\n");
      opbytes = 2;
      break;
    case 0x44:
      printf("bit 0,h\n");
      opbytes = 2;
      break;
    case 0x45:
      printf("bit 0,l\n");
      opbytes = 2;
      break;
    case 0x46:
      printf("bit 0,(hl)\n");
      opbytes = 2;
      break;
    case 0x47:
      printf("bit 0,a\n");
      opbytes = 2;
      break;
    case 0x48:
      printf("bit 1,b\n");
      opbytes = 2;
      break;
    case 0x49:
      printf("bit 1,c\n");
      opbytes = 2;
      break;
    case 0x4A:
      printf("bit 1,d\n");
      opbytes = 2;
      break;
    case 0x4B:
      printf("bit 1,e\n");
      opbytes = 2;
      break;
    case 0x4C:
      printf("bit 1,h\n");
      opbytes = 2;
      break;
    case 0x4D:
      printf("bit 1,l\n");
      opbytes = 2;
      break;
    case 0x4E:
      printf("bit 1,(hl)\n");
      opbytes = 2;
      break;
    case 0x4F:
      printf("bit 1,a\n");
      opbytes = 2;
      break;
    case 0x50:
      printf("bit 2,b\n");
      opbytes = 2;
      break;
    case 0x51:
      printf("bit 2,c\n");
      opbytes = 2;
      break;
    case 0x52:
      printf("bit 2,d\n");
      opbytes = 2;
      break;
    case 0x53:
      printf("bit 2,e\n");
      opbytes = 2;
      break;
    case 0x54:
      printf("bit 2,h\n");
      opbytes = 2;
      break;
    case 0x55:
      printf("bit 2,l\n");
      opbytes = 2;
      break;
    case 0x56:
      printf("bit 2,(hl)\n");
      opbytes = 2;
      break;
    case 0x57:
      printf("bit 2,a\n");
      opbytes = 2;
      break;
    case 0x58:
      printf("bit 3,b\n");
      opbytes = 2;
      break;
    case 0x59:
      printf("bit 3,c\n");
      opbytes = 2;
      break;
    case 0x5A:
      printf("bit 3,d\n");
      opbytes = 2;
      break;
    case 0x5B:
      printf("bit 3,e\n");
      opbytes = 2;
      break;
    case 0x5C:
      printf("bit 3,h\n");
      opbytes = 2;
      break;
    case 0x5D:
      printf("bit 3,l\n");
      opbytes = 2;
      break;
    case 0x5E:
      printf("bit 3,(hl)\n");
      opbytes = 2;
      break;
    case 0x5F:
      printf("bit 3,a\n");
      opbytes = 2;
      break;
    case 0x60:
      printf("bit 4,b\n");
      opbytes = 2;
      break;
    case 0x61:
      printf("bit 4,c\n");
      opbytes = 2;
      break;
    case 0x62:
      printf("bit 4,d\n");
      opbytes = 2;
      break;
    case 0x63:
      printf("bit 4,e\n");
      opbytes = 2;
      break;
    case 0x64:
      printf("bit 4,h\n");
      opbytes = 2;
      break;
    case 0x65:
      printf("bit 4,l\n");
      opbytes = 2;
      break;
    case 0x66:
      printf("bit 4,(hl)\n");
      opbytes = 2;
      break;
    case 0x67:
      printf("bit 4,a\n");
      opbytes = 2;
      break;
    case 0x68:
      printf("bit 5,b\n");
      opbytes = 2;
      break;
    case 0x69:
      printf("bit 5,c\n");
      opbytes = 2;
      break;
    case 0x6A:
      printf("bit 5,d\n");
      opbytes = 2;
      break;
    case 0x6B:
      printf("bit 5,e\n");
      opbytes = 2;
      break;
    case 0x6C:
      printf("bit 5,h\n");
      opbytes = 2;
      break;
    case 0x6D:
      printf("bit 5,l\n");
      opbytes = 2;
      break;
    case 0x6E:
      printf("bit 5,(hl)\n");
      opbytes = 2;
      break;
    case 0x6F:
      printf("bit 5,a\n");
      opbytes = 2;
      break;
    case 0x70:
      printf("bit 6,b\n");
      opbytes = 2;
      break;
    case 0x71:
      printf("bit 6,c\n");
      opbytes = 2;
      break;
    case 0x72:
      printf("bit 6,d\n");
      opbytes = 2;
      break;
    case 0x73:
      printf("bit 6,e\n");
      opbytes = 2;
      break;
    case 0x74:
      printf("bit 6,h\n");
      opbytes = 2;
      break;
    case 0x75:
      printf("bit 6,l\n");
      opbytes = 2;
      break;
    case 0x76:
      printf("bit 6,(hl)\n");
      opbytes = 2;
      break;
    case 0x77:
      printf("bit 6,a\n");
      opbytes = 2;
      break;
    case 0x78:
      printf("bit 7,b\n");
      opbytes = 2;
      break;
    case 0x79:
      printf("bit 7,c\n");
      opbytes = 2;
      break;
    case 0x7A:
      printf("bit 7,d\n");
      opbytes = 2;
      break;
    case 0x7B:
      printf("bit 7,e\n");
      opbytes = 2;
      break;
    case 0x7C:
      printf("bit 7,h\n");
      opbytes = 2;
      break;
    case 0x7D:
      printf("bit 7,l\n");
      opbytes = 2;
      break;
    case 0x7E:
      printf("bit 7,(hl)\n");
      opbytes = 2;
      break;
    case 0x7F:
      printf("bit 7,a\n");
      opbytes = 2;
      break;
    case 0x80:
      printf("res 0,b\n");
      opbytes = 2;
      break;
    case 0x81:
      printf("res 0,c\n");
      opbytes = 2;
      break;
    case 0x82:
      printf("res 0,d\n");
      opbytes = 2;
      break;
    case 0x83:
      printf("res 0,e\n");
      opbytes = 2;
      break;
    case 0x84:
      printf("res 0,h\n");
      opbytes = 2;
      break;
    case 0x85:
      printf("res 0,l\n");
      opbytes = 2;
      break;
    case 0x86:
      printf("res 0,(hl)\n");
      opbytes = 2;
      break;
    case 0x87:
      printf("res 0,a\n");
      opbytes = 2;
      break;
    case 0x88:
      printf("res 1,b\n");
      opbytes = 2;
      break;
    case 0x89:
      printf("res 1,c\n");
      opbytes = 2;
      break;
    case 0x8A:
      printf("res 1,d\n");
      opbytes = 2;
      break;
    case 0x8B:
      printf("res 1,e\n");
      opbytes = 2;
      break;
    case 0x8C:
      printf("res 1,h\n");
      opbytes = 2;
      break;
    case 0x8D:
      printf("res 1,l\n");
      opbytes = 2;
      break;
    case 0x8E:
      printf("res 1,(hl)\n");
      opbytes = 2;
      break;
    case 0x8F:
      printf("res 1,a\n");
      opbytes = 2;
      break;
    case 0x90:
      printf("res 2,b\n");
      opbytes = 2;
      break;
    case 0x91:
      printf("res 2,c\n");
      opbytes = 2;
      break;
    case 0x92:
      printf("res 2,d\n");
      opbytes = 2;
      break;
    case 0x93:
      printf("res 2,e\n");
      opbytes = 2;
      break;
    case 0x94:
      printf("res 2,h\n");
      opbytes = 2;
      break;
    case 0x95:
      printf("res 2,l\n");
      opbytes = 2;
      break;
    case 0x96:
      printf("res 2,(hl)\n");
      opbytes = 2;
      break;
    case 0x97:
      printf("res 2,a\n");
      opbytes = 2;
      break;
    case 0x98:
      printf("res 3,b\n");
      opbytes = 2;
      break;
    case 0x99:
      printf("res 3,c\n");
      opbytes = 2;
      break;
    case 0x9A:
      printf("res 3,d\n");
      opbytes = 2;
      break;
    case 0x9B:
      printf("res 3,e\n");
      opbytes = 2;
      break;
    case 0x9C:
      printf("res 3,h\n");
      opbytes = 2;
      break;
    case 0x9D:
      printf("res 3,l\n");
      opbytes = 2;
      break;
    case 0x9E:
      printf("res 3,(hl)\n");
      opbytes = 2;
      break;
    case 0x9F:
      printf("res 3,a\n");
      opbytes = 2;
      break;
    case 0xA0:
      printf("res 4,b\n");
      opbytes = 2;
      break;
    case 0xA1:
      printf("res 4,c\n");
      opbytes = 2;
      break;
    case 0xA2:
      printf("res 4,d\n");
      opbytes = 2;
      break;
    case 0xA3:
      printf("res 4,e\n");
      opbytes = 2;
      break;
    case 0xA4:
      printf("res 4,h\n");
      opbytes = 2;
      break;
    case 0xA5:
      printf("res 4,l\n");
      opbytes = 2;
      break;
    case 0xA6:
      printf("res 4,(hl)\n");
      opbytes = 2;
      break;
    case 0xA7:
      printf("res 4,a\n");
      opbytes = 2;
      break;
    case 0xA8:
      printf("res 5,b\n");
      opbytes = 2;
      break;
    case 0xA9:
      printf("res 5,c\n");
      opbytes = 2;
      break;
    case 0xAA:
      printf("res 5,d\n");
      opbytes = 2;
      break;
    case 0xAB:
      printf("res 5,e\n");
      opbytes = 2;
      break;
    case 0xAC:
      printf("res 5,h\n");
      opbytes = 2;
      break;
    case 0xAD:
      printf("res 5,l\n");
      opbytes = 2;
      break;
    case 0xAE:
      printf("res 5,(hl)\n");
      opbytes = 2;
      break;
    case 0xAF:
      printf("res 5,a\n");
      opbytes = 2;
      break;
    case 0xB0:
      printf("res 6,b\n");
      opbytes = 2;
      break;
    case 0xB1:
      printf("res 6,c\n");
      opbytes = 2;
      break;
    case 0xB2:
      printf("res 6,d\n");
      opbytes = 2;
      break;
    case 0xB3:
      printf("res 6,e\n");
      opbytes = 2;
      break;
    case 0xB4:
      printf("res 6,h\n");
      opbytes = 2;
      break;
    case 0xB5:
      printf("res 6,l\n");
      opbytes = 2;
      break;
    case 0xB6:
      printf("res 6,(hl)\n");
      opbytes = 2;
      break;
    case 0xB7:
      printf("res 6,a\n");
      opbytes = 2;
      break;
    case 0xB8:
      printf("res 7,b\n");
      opbytes = 2;
      break;
    case 0xB9:
      printf("res 7,c\n");
      opbytes = 2;
      break;
    case 0xBA:
      printf("res 7,d\n");
      opbytes = 2;
      break;
    case 0xBB:
      printf("res 7,e\n");
      opbytes = 2;
      break;
    case 0xBC:
      printf("res 7,h\n");
      opbytes = 2;
      break;
    case 0xBD:
      printf("res 7,l\n");
      opbytes = 2;
      break;
    case 0xBE:
      printf("res 7,(hl)\n");
      opbytes = 2;
      break;
    case 0xBF:
      printf("res 7,a\n");
      opbytes = 2;
      break;
    case 0xC0:
      printf("set 0,b\n");
      opbytes = 2;
      break;
    case 0xC1:
      printf("set 0,c\n");
      opbytes = 2;
      break;
    case 0xC2:
      printf("set 0,d\n");
      opbytes = 2;
      break;
    case 0xC3:
      printf("set 0,e\n");
      opbytes = 2;
      break;
    case 0xC4:
      printf("set 0,h\n");
      opbytes = 2;
      break;
    case 0xC5:
      printf("set 0,l\n");
      opbytes = 2;
      break;
    case 0xC6:
      printf("set 0,(hl)\n");
      opbytes = 2;
      break;
    case 0xC7:
      printf("set 0,a\n");
      opbytes = 2;
      break;
    case 0xC8:
      printf("set 1,b\n");
      opbytes = 2;
      break;
    case 0xC9:
      printf("set 1,c\n");
      opbytes = 2;
      break;
    case 0xCA:
      printf("set 1,d\n");
      opbytes = 2;
      break;
    case 0xCB:
      printf("set 1,e\n");
      opbytes = 2;
      break;
    case 0xCC:
      printf("set 1,h\n");
      opbytes = 2;
      break;
    case 0xCD:
      printf("set 1,l\n");
      opbytes = 2;
      break;
    case 0xCE:
      printf("set 1,(hl)\n");
      opbytes = 2;
      break;
    case 0xCF:
      printf("set 1,a\n");
      opbytes = 2;
      break;
    case 0xD0:
      printf("set 2,b\n");
      opbytes = 2;
      break;
    case 0xD1:
      printf("set 2,c\n");
      opbytes = 2;
      break;
    case 0xD2:
      printf("set 2,d\n");
      opbytes = 2;
      break;
    case 0xD3:
      printf("set 2,e\n");
      opbytes = 2;
      break;
    case 0xD4:
      printf("set 2,h\n");
      opbytes = 2;
      break;
    case 0xD5:
      printf("set 2,l\n");
      opbytes = 2;
      break;
    case 0xD6:
      printf("set 2,(hl)\n");
      opbytes = 2;
      break;
    case 0xD7:
      printf("set 2,a\n");
      opbytes = 2;
      break;
    case 0xD8:
      printf("set 3,b\n");
      opbytes = 2;
      break;
    case 0xD9:
      printf("set 3,c\n");
      opbytes = 2;
      break;
    case 0xDA:
      printf("set 3,d\n");
      opbytes = 2;
      break;
    case 0xDB:
      printf("set 3,e\n");
      opbytes = 2;
      break;
    case 0xDC:
      printf("set 3,h\n");
      opbytes = 2;
      break;
    case 0xDD:
      printf("set 3,l\n");
      opbytes = 2;
      break;
    case 0xDE:
      printf("set 3,(hl)\n");
      opbytes = 2;
      break;
    case 0xDF:
      printf("set 3,a\n");
      opbytes = 2;
      break;
    case 0xE0:
      printf("set 4,b\n");
      opbytes = 2;
      break;
    case 0xE1:
      printf("set 4,c\n");
      opbytes = 2;
      break;
    case 0xE2:
      printf("set 4,d\n");
      opbytes = 2;
      break;
    case 0xE3:
      printf("set 4,e\n");
      opbytes = 2;
      break;
    case 0xE4:
      printf("set 4,h\n");
      opbytes = 2;
      break;
    case 0xE5:
      printf("set 4,l\n");
      opbytes = 2;
      break;
    case 0xE6:
      printf("set 4,(hl)\n");
      opbytes = 2;
      break;
    case 0xE7:
      printf("set 4,a\n");
      opbytes = 2;
      break;
    case 0xE8:
      printf("set 5,b\n");
      opbytes = 2;
      break;
    case 0xE9:
      printf("set 5,c\n");
      opbytes = 2;
      break;
    case 0xEA:
      printf("set 5,d\n");
      opbytes = 2;
      break;
    case 0xEB:
      printf("set 5,e\n");
      opbytes = 2;
      break;
    case 0xEC:
      printf("set 5,h\n");
      opbytes = 2;
      break;
    case 0xED:
      printf("set 5,l\n");
      opbytes = 2;
      break;
    case 0xEE:
      printf("set 5,(hl)\n");
      opbytes = 2;
      break;
    case 0xEF:
      printf("set 5,a\n");
      opbytes = 2;
      break;
    case 0xF0:
      printf("set 6,b\n");
      opbytes = 2;
      break;
    case 0xF1:
      printf("set 6,c\n");
      opbytes = 2;
      break;
    case 0xF2:
      printf("set 6,d\n");
      opbytes = 2;
      break;
    case 0xF3:
      printf("set 6,e\n");
      opbytes = 2;
      break;
    case 0xF4:
      printf("set 6,h\n");
      opbytes = 2;
      break;
    case 0xF5:
      printf("set 6,l\n");
      opbytes = 2;
      break;
    case 0xF6:
      printf("set 6,(hl)\n");
      opbytes = 2;
      break;
    case 0xF7:
      printf("set 6,a\n");
      opbytes = 2;
      break;
    case 0xF8:
      printf("set 7,b\n");
      opbytes = 2;
      break;
    case 0xF9:
      printf("set 7,c\n");
      opbytes = 2;
      break;
    case 0xFA:
      printf("set 7,d\n");
      opbytes = 2;
      break;
    case 0xFB:
      printf("set 7,e\n");
      opbytes = 2;
      break;
    case 0xFC:
      printf("set 7,h\n");
      opbytes = 2;
      break;
    case 0xFD:
      printf("set 7,l\n");
      opbytes = 2;
      break;
    case 0xFE:
      printf("set 7,(hl)\n");
      opbytes = 2;
      break;
    case 0xFF:
      printf("set 7,a\n");
      opbytes = 2;
      break;
    }
  case 0xDD:
    switch (*(code + 1)) {
    case 0x2E:
      printf("ld ixl,%02xh\n", code[1]);
      opbytes = 3;
      break;
    case 0x34:
      printf("inc (ix+%02xh)\n", code[1]);
      opbytes = 3;
      break;
    case 0x35:
      printf("dec (ix+%02xh)\n", code[1]);
      opbytes = 3;
      break;
    case 0x46:
      printf("ld b,(ix+%02xh)\n", code[1]);
      opbytes = 3;
      break;
    case 0x4E:
      printf("ld c,(ix+%02xh)\n", code[1]);
      opbytes = 3;
      break;
    case 0x56:
      printf("ld d,(ix+%02xh)\n", code[1]);
      opbytes = 3;
      break;
    case 0x5E:
      printf("ld e,(ix+%02xh)\n", code[1]);
      opbytes = 3;
      break;
    case 0x66:
      printf("ld h,(ix+%02xh)\n", code[1]);
      opbytes = 3;
      break;
    case 0x6E:
      printf("ld l,(ix+%02xh)\n", code[1]);
      opbytes = 3;
      break;
    case 0x70:
      printf("ld (ix+%02xh),b\n", code[1]);
      opbytes = 3;
      break;
    case 0x71:
      printf("ld (ix+%02xh),c\n", code[1]);
      opbytes = 3;
      break;
    case 0x72:
      printf("ld (ix+%02xh),d\n", code[1]);
      opbytes = 3;
      break;
    case 0x73:
      printf("ld (ix+%02xh),e\n", code[1]);
      opbytes = 3;
      break;
    case 0x74:
      printf("ld (ix+%02xh),h\n", code[1]);
      opbytes = 3;
      break;
    case 0x75:
      printf("ld (ix+%02xh),l\n", code[1]);
      opbytes = 3;
      break;
    case 0x77:
      printf("ld (ix+%02xh),a\n", code[1]);
      opbytes = 3;
      break;
    case 0x7E:
      printf("ld a,(ix+%02xh)\n", code[1]);
      opbytes = 3;
      break;
    case 0x86:
      printf("add a,(ix+%02xh)\n", code[1]);
      opbytes = 3;
      break;
    case 0x8E:
      printf("adc a,(ix+%02xh)\n", code[1]);
      opbytes = 3;
      break;
    case 0x96:
      printf("sub (ix+%02xh)\n", code[1]);
      opbytes = 3;
      break;
    case 0x9E:
      printf("sbc a,(ix+%02xh)\n", code[1]);
      opbytes = 3;
      break;
    case 0xA6:
      printf("and (ix+%02xh)\n", code[1]);
      opbytes = 3;
      break;
    case 0xAE:
      printf("xor (ix+%02xh)\n", code[1]);
      opbytes = 3;
      break;
    case 0xB6:
      printf("or (ix+%02xh)\n", code[1]);
      opbytes = 3;
      break;
    case 0xBE:
      printf("cp (ix+%02xh)\n", code[1]);
      opbytes = 3;
      break;
    }
  }
  return opbytes;
}
