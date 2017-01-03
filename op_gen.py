import re

with open('listops', 'r') as f:
    lines = f.readlines()
lines = [line.upper() for line in lines]
reg = re.compile("( [A-Z]+ +[0-7]?,?\(?&?[A-Z0-9]*\+?0?\)?,?(->)?\(?&?[A-Z0-9]*\+?0?\)?'?)|-|(\[.+\])|([A-Z]+_?[A-Z]+)",re.IGNORECASE)

two_byte_ops = {line[0:2]: re.findall(reg, line[2:])[0][0]
        for line in lines}
dd_ops = {line[0:2] + 'DD': re.findall(reg, line[2:])[1][0]
        for line in lines}
dd_ops = {key: dd_ops[key] for key in dd_ops if dd_ops[key] != ''}
cb_ops = {line[0:2] + 'CB': re.findall(reg, line[2:])[2][0][1:0]
        for line in lines}
ed_ops = {line[0:2] + 'ED': re.findall(reg, line[2:])[4][0]
        for line in lines}

b10 = sorted([int(key, 16) for key in ed_ops])

for hx in sorted(dd_ops.keys()):
    print(hx + ": " + dd_ops[hx])
