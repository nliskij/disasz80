from bs4 import BeautifulSoup as BS
import re

def dec2hex(dec):
    hex_dict = {"10": "A",
                "11": "B",
                "12": "C",
                "13": "D",
                "14": "E",
                "15": "F"}
    if int(dec) < 10:
        return str(dec)
    else:
        return hex_dict[str(dec)]

def matches_regex(regex, string):
    return re.findall(regex, string)[0] == string

with open("opcodes.html", "r") as f:
    html = ''.join(f.readlines())

disas = open("disas_ops.c", "w")

soup = BS(html, "html.parser")

find_bytes = re.compile(r"\|[0-9]\|")
not_empty = re.compile("([0-9]|[A-F])([0-9]|[A-F]): .+")
for tr in soup.find_all("tr"):
    if tr.th == None or tr.td.text == "":
        continue
    first_digit = tr.th.text
    col_num = 0
    for td in tr.find_all("td"):
        """try:
            op_bytes = re.findall(find_bytes, str(td))[0][1]
        except IndexError:
            sec_digit = dec2hex(col_num)
            op_code = first_digit + sec_digit
            col_num += 1
            if td.a != None: 
                print("case 0x" + op_code + ": " + td.a.text)
            continue"""
        sec_digit = dec2hex(col_num)
        op_code = first_digit + sec_digit
        col_num += 1
        op_bytes = 
        oper = '"' + td.text.replace("**", "0x%02x%02x").replace("*", "0x%02x") + '"'
        if op_bytes == "2":
            oper += ", code[1]"
        elif op_bytes == "3":
            oper += ", code[2], code[1]"
        print('case 0x{op_num}: printf({op});\n\t\topbytes = {nbytes};\n\t\tbreak;'.format(op_num=op_code, nbytes=op_bytes, op=oper))
