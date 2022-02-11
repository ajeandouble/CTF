# Writeup

Trivial. Let's ghidra:

```
undefined4 main(void)
{
  size_t password_len;
  undefined4 i;
  char password [4];
  char l_a;
  char l_b;
  char l_c;
  char l_d;
  char local_4c [9];
  char l_f;
  char _g;
  undefined4 local_c;
  
  puts("crack-me for Root-me by s4r");
  puts("Enter password please");
  fgets(password,64,stdin);
  password_len = strlen(password);
  password[password_len - 1] = '\0';
  password_len = strlen(password);
  if (password_len == 19) {
    for (i = 8; i < 17; i = i + 1) {
      if (password[i] != 'i') {
        FUN_fail();
        return 0;
      }
    }
    if (_g == 's') {
      if (l_f == 'p') {
        if (l_d == 'm') {
          if ((password[2] == 'n') && (l_c == 'n')) {
            if (password[0] == 'c') {
              if (password[1] == 'a') {
                if (password[3] == 't') {
                  if (l_a == 'r') {
                    if (l_b == 'u') {
                      FUN_well_done();
                      return local_c;
                    }
                    FUN_fail();
                  }
                  else {
                    FUN_fail();
                  }
                }
                else {
                  FUN_fail();
                }
              }
              else {
                FUN_fail();
              }
            }
            else {
              FUN_fail();
            }
          }
          else {
            FUN_fail();
          }
        }
        else {
          FUN_fail();
        }
      }
      else {
        FUN_fail();
      }
    }
    else {
      FUN_fail();
    }
  }
  else {
    FUN_fail();
  }
  return 0;
}
```
Stack follows this order:

```
                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined main()
                               assume gp = 0x418d30
             undefined         v0:1           <RETURN>                                XREF[1]:     0040092c(W)  
             undefined4        v0:4           password_len                            XREF[1]:     0040092c(W)  
             undefined4        Stack[-0x4]:4  local_4                                 XREF[2]:     0040086c(W), 
                                                                                                   00400b78(R)  
             undefined4        Stack[-0x8]:4  local_8                                 XREF[2]:     00400870(W), 
                                                                                                   00400b7c(R)  
             undefined4        Stack[-0xc]:4  local_c                                 XREF[2]:     00400b6c(W), 
                                                                                                   00400b70(R)  
             undefined4        Stack[-0x10]:4 local_10                                XREF[12]:    00400954(W), 
                                                                                                   00400998(W), 
                                                                                                   004009e4(W), 
                                                                                                   00400a0c(W), 
                                                                                                   00400a34(W), 
                                                                                                   00400a6c(W), 
                                                                                                   00400a94(W), 
                                                                                                   00400abc(W), 
                                                                                                   00400ae4(W), 
                                                                                                   00400b0c(W), 
                                                                                                   00400b44(W), 
                                                                                                   00400b64(R)  
             undefined1        Stack[-0x42]:1 _g                                      XREF[1]:     004009c8(R)  
             undefined1        Stack[-0x43]:1 l_f                                     XREF[1]:     004009f0(R)  
             undefined1        Stack[-0x4c]:1 local_4c                                XREF[1]:     0040097c(R)  
             undefined1        Stack[-0x4d]:1 l_d                                     XREF[1]:     00400a18(R)  
             undefined1        Stack[-0x4e]:1 l_c                                     XREF[1]:     00400a50(R)  
             undefined1        Stack[-0x4f]:1 l_b                                     XREF[1]:     00400b18(R)  
             undefined1        Stack[-0x50]:1 l_a                                     XREF[2]:     00400af0(R), 
                                                                                                   00400b24(R)  
             undefined4        Stack[-0x54]:4 password                                XREF[1,3]:   00400a78(R), 
                                                                                                   00400aa0(R), 
                                                                                                   00400a40(R), 
                                                                                                   00400ac8(R)  
             undefined4        Stack[-0x58]:4 i                                       XREF[5]:     00400964(W), 
                                                                                                   00400970(R), 
                                                                                                   004009a4(R), 
                                                                                                   004009b0(W), 
                                                                                                   004009b4(R)  
             undefined4        Stack[-0x60]:4 local_60                                XREF[18]:    00400880(W), 
                                                                                                   0040089c(R), 
                                                                                                   004008b8(R), 
                                                                                                   004008ec(R), 
                                                                                                   00400908(R), 
                                                                                                   00400934(R), 
                                                                                                   00400950(R), 
                                                                                                   00400994(R), 
                                                                                                   004009e0(R), 
                                                                                                   00400a08(R), 
                                                                                                   00400a30(R), 
                                                                                                   00400a68(R), 
                                                                                                   00400a90(R), 
                                                                                                   00400ab8(R), 
                                                                                                   00400ae0(R), 
                                                                                                   00400b08(R), 
                                                                                                   00400b40(R), 
                                                                                                   00400b58(R)  
                             main                                            XREF[3]:     Entry Point(*), 
                                                                                          entry:00400628(*), 00410d58(*)  
        00400868 90 ff bd 27     addiu      sp,sp,-0x70
```

We just have to put everything in its [right place](https://www.youtube.com/watch?v=NUnXxh5U25Y)