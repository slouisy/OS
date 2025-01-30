# Compiler and linker settings
CC = x86_64-elf-g++
NASM = nasm
LD = x86_64-elf-ld

# Flags for the compiler
CFLAGS = -m32 -ffreestanding -fno-exceptions
NASMFLAGS = -f elf32

# Linker flags (using a linker script)
LDFLAGS = -melf_i386

# Automatically find all source files in subdirectories
CXX_SOURCES = $(shell find . -name '*.cpp')
ASM_SOURCES = $(shell find . -name '*.asm')

# Generate object file names from source files
CXX_OBJECTS = $(CXX_SOURCES:.cpp=.o)
ASM_OBJECTS = $(ASM_SOURCES:.asm=.o)

# All object files
OBJECTS = $(CXX_OBJECTS) $(ASM_OBJECTS)

# Output kernel binary (BIN file)
KERNEL_BIN = kernel.bin

# Linker script
LINKER_SCRIPT = linker.ld

# Default target (all)
all: $(KERNEL_BIN)

# Rule to build the raw binary kernel
$(KERNEL_BIN): $(OBJECTS)
	$(LD) $(LDFLAGS) -T $(LINKER_SCRIPT) -o $@ $(OBJECTS)

# Rule to assemble assembly files
%.o: %.asm
	$(NASM) $(NASMFLAGS) -o $@ $<

# Rule to compile C++ files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files and the kernel binary
clean:
	rm -f $(OBJECTS) $(KERNEL_BIN)

# Run the kernel in QEMU using the BIN file
run: $(KERNEL_BIN)
	qemu-system-i386 -kernel $(KERNEL_BIN) -vga std -m 2G

.PHONY: all clean run
