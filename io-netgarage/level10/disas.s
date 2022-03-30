   0x00400700 <+0>:		lea    ecx,[esp+0x4]
   0x00400704 <+4>:		and    esp,0xfffffff0
   0x00400707 <+7>:		push   DWORD PTR [ecx-0x4]
   0x0040070a <+10>:	push   ebp
   0x0040070b <+11>:	mov    ebp,esp
   0x0040070d <+13>:	push   edi
   0x0040070e <+14>:	push   esi
   0x0040070f <+15>:	push   ebx
   0x00400710 <+16>:	push   ecx
   0x00400711 <+17>:	sub    esp,0x1b8
   0x00400717 <+23>:	call   0x4005d0 <__x86.get_pc_thunk.bx>
   0x0040071c <+28>:	add    ebx,0x18e4
   0x00400722 <+34>:	mov    esi,ecx
   0x00400724 <+36>:	sub    esp,0x8
   0x00400727 <+39>:	lea    eax,[ebx-0x1720]
   0x0040072d <+45>:	push   eax
   0x0040072e <+46>:	lea    eax,[ebx-0x171e]
   0x00400734 <+52>:	push   eax
   0x00400735 <+53>:	call   0x400550 <fopen@plt>
   0x0040073a <+58>:	add    esp,0x10
   0x0040073d <+61>:	mov    DWORD PTR [ebp-0x1c],eax
   0x00400740 <+64>:	lea    edx,[ebp-0x1c0]
   0x00400746 <+70>:	mov    eax,0x0
   0x0040074b <+75>:	mov    ecx,0x69
   0x00400750 <+80>:	mov    edi,edx
   0x00400752 <+82>:	rep stos DWORD PTR es:[edi],eax
   0x00400754 <+84>:	cmp    DWORD PTR [ebp-0x1c],0x0
   0x00400758 <+88>:	je     0x40075f <main+95>
   0x0040075a <+90>:	cmp    DWORD PTR [esi],0x2
   0x0040075d <+93>:	je     0x400769 <main+105>
   0x0040075f <+95>:	mov    eax,0xffffffff
   0x00400764 <+100>:	jmp    0x400847 <main+327>
   0x00400769 <+105>:	push   DWORD PTR [ebp-0x1c]
   0x0040076c <+108>:	push   0xdc
   0x00400771 <+113>:	push   0x1
   0x00400773 <+115>:	lea    eax,[ebp-0x1c0]
   0x00400779 <+121>:	push   eax
   0x0040077a <+122>:	call   0x400520 <fread@plt>
   0x0040077f <+127>:	add    esp,0x10
   0x00400782 <+130>:	sub    esp,0x8
   0x00400785 <+133>:	lea    eax,[ebp-0x1c0]
   0x0040078b <+139>:	push   eax
   0x0040078c <+140>:	lea    eax,[ebx-0x1705]
   0x00400792 <+146>:	push   eax
   0x00400793 <+147>:	call   0x400500 <printf@plt>
   0x00400798 <+152>:	add    esp,0x10
   0x0040079b <+155>:	mov    BYTE PTR [ebp-0xe5],0x0
   0x004007a2 <+162>:	mov    eax,DWORD PTR [esi+0x4]
   0x004007a5 <+165>:	add    eax,0x4
   0x004007a8 <+168>:	mov    eax,DWORD PTR [eax]
   0x004007aa <+170>:	sub    esp,0xc
   0x004007ad <+173>:	push   eax
   0x004007ae <+174>:	call   0x400570 <atoi@plt>
   0x004007b3 <+179>:	add    esp,0x10
   0x004007b6 <+182>:	mov    BYTE PTR [ebp+eax*1-0x1c0],0x0
   0x004007be <+190>:	push   DWORD PTR [ebp-0x1c]
   0x004007c1 <+193>:	push   0xc8
   0x004007c6 <+198>:	push   0x1
   0x004007c8 <+200>:	lea    eax,[ebp-0x1c0]
   0x004007ce <+206>:	add    eax,0xdc
   0x004007d3 <+211>:	push   eax
   0x004007d4 <+212>:	call   0x400520 <fread@plt>
   0x004007d9 <+217>:	add    esp,0x10
   0x004007dc <+220>:	sub    esp,0xc
   0x004007df <+223>:	push   DWORD PTR [ebp-0x1c]
   0x004007e2 <+226>:	call   0x400510 <fclose@plt>
   0x004007e7 <+231>:	add    esp,0x10
   0x004007ea <+234>:	mov    eax,DWORD PTR [esi+0x4]
   0x004007ed <+237>:	add    eax,0x4
   0x004007f0 <+240>:	mov    eax,DWORD PTR [eax]
   0x004007f2 <+242>:	sub    esp,0x8
   0x004007f5 <+245>:	push   eax
   0x004007f6 <+246>:	lea    eax,[ebp-0x1c0]
   0x004007fc <+252>:	add    eax,0xc8
   0x00400801 <+257>:	push   eax
   0x00400802 <+258>:	call   0x4004f0 <strcmp@plt>
   0x00400807 <+263>:	add    esp,0x10
   0x0040080a <+266>:	test   eax,eax
   0x0040080c <+268>:	jne    0x40082b <main+299>
   0x0040080e <+270>:	sub    esp,0x4
   0x00400811 <+273>:	push   0x0
   0x00400813 <+275>:	lea    eax,[ebx-0x16ff]
   0x00400819 <+281>:	push   eax
   0x0040081a <+282>:	lea    eax,[ebx-0x16fc]
   0x00400820 <+288>:	push   eax
   0x00400821 <+289>:	call   0x400560 <execl@plt>
   0x00400826 <+294>:	add    esp,0x10
   0x00400829 <+297>:	jmp    0x400842 <main+322>
   0x0040082b <+299>:	sub    esp,0xc
   0x0040082e <+302>:	lea    eax,[ebp-0x1c0]
   0x00400834 <+308>:	add    eax,0xdc
   0x00400839 <+313>:	push   eax
   0x0040083a <+314>:	call   0x400530 <puts@plt>
   0x0040083f <+319>:	add    esp,0x10
   0x00400842 <+322>:	mov    eax,0x0
   0x00400847 <+327>:	lea    esp,[ebp-0x10]
   0x0040084a <+330>:	pop    ecx
   0x0040084b <+331>:	pop    ebx
   0x0040084c <+332>:	pop    esi
   0x0040084d <+333>:	pop    edi
   0x0040084e <+334>:	pop    ebp
   0x0040084f <+335>:	lea    esp,[ecx-0x4]
   0x00400852 <+338>:	ret