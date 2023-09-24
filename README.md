# Plain-OS #

Plain-OS (pOS) is a plain and small operating system. By now, pOS is meant to be a fun project. Things may drastically change.
Since I am new to OS-Programming, pOS is heavily based on David Callanan's discontinued [OS-Series](https://github.com/davidcallanan/os-series).
Also note, that pOS is mainly developed on Linux, you may use a VM or an subsystem for windows.

## Tools ##

- Any sort of text-editor (I use [neovim](https://neovim.io/))
- [qemu](https://www.qemu.org/)
- [grub tools](https://www.gnu.org/software/grub/)
- [nasm](https://www.nasm.us/)
- [gcc compiler collection](https://gcc.gnu.org/)

## Build ##

- Clone the repo: `git clone https://github.com/tim-tm/plain-OS && cd plain-OS`
- Building the ISO: `make`
- Starting pOS in qemu: `make run`
- Cleaning the binaries: `make clean`
