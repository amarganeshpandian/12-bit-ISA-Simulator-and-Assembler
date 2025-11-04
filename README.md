# 12-bit ISA Simulator

A simple 12-bit instruction set architecture simulator with immediate arithmetic instructions and an assembler.

## Architecture

**Instruction Format:** 12 bits total
- Bits 11-9: Opcode (3 bits)
- Bits 8-6: Register (3 bits)
- Bits 5-0: Immediate/Address (6 bits)

**Registers:** 8 general-purpose registers (R0-R7)

**Memory:** 64 bytes (8×8 array)

## Instruction Set

| Instruction | Opcode | Format | Description |
|-------------|--------|---------|-------------|
| MOV | 000 | MOV Rd, imm | Load immediate value into register |
| ADD | 001 | ADD Rd, imm | Add immediate to register |
| SUB | 010 | SUB Rd, imm | Subtract immediate from register |
| LOAD | 011 | LOAD Rd, addr | Load from memory to register (100ns delay) |
| STORE | 100 | STORE Rd, addr | Store register to memory (80ns delay) |
| HALT | 111 | HALT | Stop execution |

## Files

- `assembler.py` - Assembler that converts instructions to binary
- `iISAsim.cpp` - Simulator that executes binary programs

## Example Program
```assembly
MOV R0, 15      
ADD R0, 10      
SUB R0, 5       
STORE R0, 10    
LOAD R1, 10    
HALT           
```

## Technical Details

- 6-bit immediate values (0-63)
- 64 bytes addressable memory
- Memory access latency simulation (LOAD: 100ns, STORE: 80ns)
- Binary instruction format written to `program.bin`
