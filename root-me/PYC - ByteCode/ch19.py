# uncompyle6 version 3.5.0
# Python bytecode 3.1 (3151)
# Decompiled from: Python 3.6.8 (default, Nov 16 2020, 16:55:22) 
# [GCC 4.8.5 20150623 (Red Hat 4.8.5-44)]
# Embedded file name: crackme.py
# Compiled at: 2013-07-02 23:00:05

if __name__ == '__main__':
    print('Welcome to the RootMe python crackme')
    PASS = input('Enter the Flag: ')
    KEY = 'I know, you love decrypting Byte Code !'
    I = 5
    SOLUCE = [57, 73, 79, 16, 18, 26, 74, 50, 13, 38, 13, 79, 86, 86, 87]
    KEYOUT = []
    #for X in PASS:
    #    KEYOUT.append((ord(X) + I ^ ord(KEY[I])) % 255)
    #    I = (I + 1) % len(KEY)
    flag = ''
    for c in SOLUCE:
        print(c)
        flag = flag + chr(((c^ ord(KEY[I])) - I) % 255)
        I = (I + 1) % len(KEY)
    print(flag)
