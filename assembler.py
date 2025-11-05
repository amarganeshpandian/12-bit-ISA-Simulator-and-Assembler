def assemble_line(line):
    line = line.split(';', 1)[0].strip()
    if not line:
        return None
    parts = line.replace(',', ' ').split()
    mnem = parts[0].upper()
    args = parts[1:]
    return mnem, args

OPCODES = {
    "MOV": 0b000,
    "ADD": 0b001,
    "SUB": 0b010,
    "LOAD":0b011,
    "STORE":0b100,
    "HALT":0b111
}

REGISTERS = {
    "R0": 0b000,
    "R1": 0b001,
    "R2": 0b010,
    "R3": 0b011,
    "R4": 0b100,
    "R5": 0b101,
    "R6": 0b110,
    "R7": 0b111
}

def encode_instruction(mnem, args):
    opcode = OPCODES.get(mnem)
    if opcode is None:
        raise ValueError("Unknown instruction")
    reg = REGISTERS.get(args[0].upper())
    if reg is None:
        raise ValueError("Unknown register")
    imm = int(args[1]) & 0xFF
    binary = (opcode<<9) | (reg<<6) | imm
    return f"{binary:012b}"
running = True
open("program.bin","w").close()
pass
while(running):
    instructions=[]
    instruction = input("Enter instructions: ")
    mnem, args = assemble_line(instruction)
    if mnem.upper() == "HALT":
        binary = "111000000000"
        with open("program.bin","a") as f:
            f.write(binary+"\n")
        continue
    binary = encode_instruction(mnem, args)
    print(binary)
    with open("program.bin","a") as f:
        f.write(binary + "\n")

