X86_64_ASM_SRC := $(shell find src/x86_64 -name *.asm)
X86_64_ASM_OBJ := $(patsubst src/x86_64/%.asm, build/x86_64/%.o, $(X86_64_ASM_SRC))

X86_64_C_SRC := $(shell find src/x86_64 -name *.c)
X86_64_C_OBJ := $(patsubst src/x86_64/%.c, build/x86_64/%.o, $(X86_64_C_SRC))

KERNEL_SRC := $(shell find src/kernel -name *.c)
KERNEL_OBJ := $(patsubst src/kernel/%.c, build/kernel/%.o, $(KERNEL_SRC))

X86_64_OBJ := $(X86_64_C_OBJ) $(X86_64_ASM_OBJ)

.PHONY: all build-x86_64 clean run

all: build-x86_64

$(X86_64_ASM_OBJ): build/x86_64/%.o : src/x86_64/%.asm
	mkdir -p $(dir $@)
	nasm -f elf64 $(patsubst build/x86_64/%.o, src/x86_64/%.asm, $@) -o $@

$(X86_64_C_OBJ): build/x86_64/%.o : src/x86_64/%.c
	mkdir -p $(dir $@)
	gcc -c -I src/include -ffreestanding $(patsubst build/x86_64/%.o, src/x86_64/%.c, $@) -o $@

$(KERNEL_OBJ): build/kernel/%.o : src/kernel/%.c
	mkdir -p $(dir $@)
	gcc -c -I src/include -ffreestanding $(patsubst build/kernel/%.o, src/kernel/%.c, $@) -o $@

build-x86_64: $(KERNEL_OBJ) $(X86_64_OBJ)
	mkdir -p dist/x86_64
	ld -n -o dist/x86_64/kernel.bin -T target/x86_64/linker.ld $(KERNEL_OBJ) $(X86_64_OBJ)
	cp dist/x86_64/kernel.bin target/x86_64/iso/boot/kernel.bin
	grub-mkrescue /usr/lib/grub/i386-pc -o dist/x86_64/kernel.iso target/x86_64/iso

clean:
	rm -rf build
	rm -rf dist

run:
	qemu-system-x86_64 -cdrom dist/x86_64/kernel.iso
