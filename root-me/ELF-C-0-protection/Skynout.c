typedef unsigned char   undefined;

typedef unsigned char    bool;
typedef unsigned char    byte;
typedef unsigned char    dwfenc;
typedef unsigned int    dword;
typedef unsigned long    qword;
typedef unsigned int    uint;
typedef unsigned long    ulong;
typedef unsigned char    undefined1;
typedef unsigned int    undefined4;
typedef unsigned long    undefined8;
typedef unsigned short    ushort;
typedef unsigned short    word;
typedef struct eh_frame_hdr eh_frame_hdr, *Peh_frame_hdr;

struct eh_frame_hdr {
    byte eh_frame_hdr_version; // Exception Handler Frame Header Version
    dwfenc eh_frame_pointer_encoding; // Exception Handler Frame Pointer Encoding
    dwfenc eh_frame_desc_entry_count_encoding; // Encoding of # of Exception Handler FDEs
    dwfenc eh_frame_table_encoding; // Exception Handler Table Encoding
};

typedef struct fde_table_entry fde_table_entry, *Pfde_table_entry;

struct fde_table_entry {
    dword initial_loc; // Initial Location
    dword data_loc; // Data location
};

typedef void _IO_lock_t;

typedef struct _IO_marker _IO_marker, *P_IO_marker;

typedef struct _IO_FILE _IO_FILE, *P_IO_FILE;

typedef long __off_t;

typedef long __off64_t;

typedef ulong size_t;

struct _IO_FILE {
    int _flags;
    char * _IO_read_ptr;
    char * _IO_read_end;
    char * _IO_read_base;
    char * _IO_write_base;
    char * _IO_write_ptr;
    char * _IO_write_end;
    char * _IO_buf_base;
    char * _IO_buf_end;
    char * _IO_save_base;
    char * _IO_backup_base;
    char * _IO_save_end;
    struct _IO_marker * _markers;
    struct _IO_FILE * _chain;
    int _fileno;
    int _flags2;
    __off_t _old_offset;
    ushort _cur_column;
    char _vtable_offset;
    char _shortbuf[1];
    _IO_lock_t * _lock;
    __off64_t _offset;
    void * __pad1;
    void * __pad2;
    void * __pad3;
    void * __pad4;
    size_t __pad5;
    int _mode;
    char _unused2[15];
};

struct _IO_marker {
    struct _IO_marker * _next;
    struct _IO_FILE * _sbuf;
    int _pos;
};

typedef struct _IO_FILE FILE;

typedef enum Elf_ProgramHeaderType {
    PT_DYNAMIC=2,
    PT_GNU_EH_FRAME=1685382480,
    PT_GNU_RELRO=1685382482,
    PT_GNU_STACK=1685382481,
    PT_INTERP=3,
    PT_LOAD=1,
    PT_NOTE=4,
    PT_NULL=0,
    PT_PHDR=6,
    PT_SHLIB=5,
    PT_TLS=7
} Elf_ProgramHeaderType;

typedef struct Elf64_Dyn Elf64_Dyn, *PElf64_Dyn;

typedef enum Elf64_DynTag {
    DT_ANDROID_REL=1610612751,
    DT_ANDROID_RELA=1610612753,
    DT_ANDROID_RELASZ=1610612754,
    DT_ANDROID_RELR=1879040000,
    DT_ANDROID_RELRENT=1879040003,
    DT_ANDROID_RELRSZ=1879040001,
    DT_ANDROID_RELSZ=1610612752,
    DT_AUDIT=1879047932,
    DT_AUXILIARY=2147483645,
    DT_BIND_NOW=24,
    DT_CHECKSUM=1879047672,
    DT_CONFIG=1879047930,
    DT_DEBUG=21,
    DT_DEPAUDIT=1879047931,
    DT_FEATURE_1=1879047676,
    DT_FILTER=2147483647,
    DT_FINI=13,
    DT_FINI_ARRAY=26,
    DT_FINI_ARRAYSZ=28,
    DT_FLAGS=30,
    DT_FLAGS_1=1879048187,
    DT_GNU_CONFLICT=1879047928,
    DT_GNU_CONFLICTSZ=1879047670,
    DT_GNU_HASH=1879047925,
    DT_GNU_LIBLIST=1879047929,
    DT_GNU_LIBLISTSZ=1879047671,
    DT_GNU_PRELINKED=1879047669,
    DT_HASH=4,
    DT_INIT=12,
    DT_INIT_ARRAY=25,
    DT_INIT_ARRAYSZ=27,
    DT_JMPREL=23,
    DT_MOVEENT=1879047674,
    DT_MOVESZ=1879047675,
    DT_MOVETAB=1879047934,
    DT_NEEDED=1,
    DT_NULL=0,
    DT_PLTGOT=3,
    DT_PLTPAD=1879047933,
    DT_PLTPADSZ=1879047673,
    DT_PLTREL=20,
    DT_PLTRELSZ=2,
    DT_POSFLAG_1=1879047677,
    DT_PREINIT_ARRAY=32,
    DT_PREINIT_ARRAYSZ=33,
    DT_REL=17,
    DT_RELA=7,
    DT_RELACOUNT=1879048185,
    DT_RELAENT=9,
    DT_RELASZ=8,
    DT_RELCOUNT=1879048186,
    DT_RELENT=19,
    DT_RELR=36,
    DT_RELRENT=37,
    DT_RELRSZ=35,
    DT_RELSZ=18,
    DT_RPATH=15,
    DT_RUNPATH=29,
    DT_SONAME=14,
    DT_STRSZ=10,
    DT_STRTAB=5,
    DT_SYMBOLIC=16,
    DT_SYMENT=11,
    DT_SYMINENT=1879047679,
    DT_SYMINFO=1879047935,
    DT_SYMINSZ=1879047678,
    DT_SYMTAB=6,
    DT_TEXTREL=22,
    DT_TLSDESC_GOT=1879047927,
    DT_TLSDESC_PLT=1879047926,
    DT_VERDEF=1879048188,
    DT_VERDEFNUM=1879048189,
    DT_VERNEED=1879048190,
    DT_VERNEEDNUM=1879048191,
    DT_VERSYM=1879048176
} Elf64_DynTag;

struct Elf64_Dyn {
    enum Elf64_DynTag d_tag;
    qword d_val;
};

typedef struct Elf64_Shdr Elf64_Shdr, *PElf64_Shdr;

typedef enum Elf_SectionHeaderType {
    SHT_ANDROID_REL=1610612737,
    SHT_ANDROID_RELA=1610612738,
    SHT_CHECKSUM=1879048184,
    SHT_DYNAMIC=6,
    SHT_DYNSYM=11,
    SHT_FINI_ARRAY=15,
    SHT_GNU_ATTRIBUTES=1879048181,
    SHT_GNU_HASH=1879048182,
    SHT_GNU_LIBLIST=1879048183,
    SHT_GNU_verdef=1879048189,
    SHT_GNU_verneed=1879048190,
    SHT_GNU_versym=1879048191,
    SHT_GROUP=17,
    SHT_HASH=5,
    SHT_INIT_ARRAY=14,
    SHT_NOBITS=8,
    SHT_NOTE=7,
    SHT_NULL=0,
    SHT_PREINIT_ARRAY=16,
    SHT_PROGBITS=1,
    SHT_REL=9,
    SHT_RELA=4,
    SHT_SHLIB=10,
    SHT_STRTAB=3,
    SHT_SUNW_COMDAT=1879048187,
    SHT_SUNW_move=1879048186,
    SHT_SUNW_syminfo=1879048188,
    SHT_SYMTAB=2,
    SHT_SYMTAB_SHNDX=18
} Elf_SectionHeaderType;

struct Elf64_Shdr {
    dword sh_name;
    enum Elf_SectionHeaderType sh_type;
    qword sh_flags;
    qword sh_addr;
    qword sh_offset;
    qword sh_size;
    dword sh_link;
    dword sh_info;
    qword sh_addralign;
    qword sh_entsize;
};

typedef struct Gnu_BuildId Gnu_BuildId, *PGnu_BuildId;

struct Gnu_BuildId {
    dword namesz; // Length of name field
    dword descsz; // Length of description field
    dword type; // Vendor specific type
    char name[4]; // Build-id vendor name
    byte description[20]; // Build-id value
};

typedef struct Elf64_Ehdr Elf64_Ehdr, *PElf64_Ehdr;

struct Elf64_Ehdr {
    byte e_ident_magic_num;
    char e_ident_magic_str[3];
    byte e_ident_class;
    byte e_ident_data;
    byte e_ident_version;
    byte e_ident_osabi;
    byte e_ident_abiversion;
    byte e_ident_pad[7];
    word e_type;
    word e_machine;
    dword e_version;
    qword e_entry;
    qword e_phoff;
    qword e_shoff;
    dword e_flags;
    word e_ehsize;
    word e_phentsize;
    word e_phnum;
    word e_shentsize;
    word e_shnum;
    word e_shstrndx;
};

typedef struct Elf64_Rela Elf64_Rela, *PElf64_Rela;

struct Elf64_Rela {
    qword r_offset; // location to apply the relocation action
    qword r_info; // the symbol table index and the type of relocation
    qword r_addend; // a constant addend used to compute the relocatable field value
};

typedef struct Elf64_Phdr Elf64_Phdr, *PElf64_Phdr;

struct Elf64_Phdr {
    enum Elf_ProgramHeaderType p_type;
    dword p_flags;
    qword p_offset;
    qword p_vaddr;
    qword p_paddr;
    qword p_filesz;
    qword p_memsz;
    qword p_align;
};

typedef struct Elf64_Sym Elf64_Sym, *PElf64_Sym;

struct Elf64_Sym {
    dword st_name;
    byte st_info;
    byte st_other;
    word st_shndx;
    qword st_value;
    qword st_size;
};




void _DT_INIT(void)

{
  __gmon_start__();
  return;
}



void FUN_00101020(void)

{
                    // WARNING: Treating indirect jump as call
  (*(code *)(undefined *)0x0)();
  return;
}



// WARNING: Unknown calling convention yet parameter storage is locked

void free(void *__ptr)

{
  free(__ptr);
  return;
}



// WARNING: Unknown calling convention yet parameter storage is locked

int putchar(int __c)

{
  int iVar1;
  
  iVar1 = putchar(__c);
  return iVar1;
}



// WARNING: Unknown calling convention yet parameter storage is locked

double fmax(double __x,double __y)

{
  double dVar1;
  
  dVar1 = fmax(__x,__y);
  return dVar1;
}



// WARNING: Unknown calling convention yet parameter storage is locked

int puts(char *__s)

{
  int iVar1;
  
  iVar1 = puts(__s);
  return iVar1;
}



// WARNING: Unknown calling convention yet parameter storage is locked

size_t strlen(char *__s)

{
  size_t sVar1;
  
  sVar1 = strlen(__s);
  return sVar1;
}



// WARNING: Unknown calling convention yet parameter storage is locked

char * strchr(char *__s,int __c)

{
  char *pcVar1;
  
  pcVar1 = strchr(__s,__c);
  return pcVar1;
}



// WARNING: Unknown calling convention yet parameter storage is locked

int printf(char *__format,...)

{
  int iVar1;
  
  iVar1 = printf(__format);
  return iVar1;
}



// WARNING: Unknown calling convention yet parameter storage is locked

void * memset(void *__s,int __c,size_t __n)

{
  void *pvVar1;
  
  pvVar1 = memset(__s,__c,__n);
  return pvVar1;
}



// WARNING: Unknown calling convention yet parameter storage is locked

char * fgets(char *__s,int __n,FILE *__stream)

{
  char *pcVar1;
  
  pcVar1 = fgets(__s,__n,__stream);
  return pcVar1;
}



// WARNING: Unknown calling convention yet parameter storage is locked

void * malloc(size_t __size)

{
  void *pvVar1;
  
  pvVar1 = malloc(__size);
  return pvVar1;
}



// WARNING: Unknown calling convention yet parameter storage is locked

int fflush(FILE *__stream)

{
  int iVar1;
  
  iVar1 = fflush(__stream);
  return iVar1;
}



void __isoc99_sscanf(void)

{
  __isoc99_sscanf();
  return;
}



// WARNING: Unknown calling convention yet parameter storage is locked

void * realloc(void *__ptr,size_t __size)

{
  void *pvVar1;
  
  pvVar1 = realloc(__ptr,__size);
  return pvVar1;
}



void __cxa_finalize(void)

{
  __cxa_finalize();
  return;
}



void entry(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 in_stack_00000000;
  undefined auStack8 [8];
  
  __libc_start_main(main,in_stack_00000000,&stack0x00000008,FUN_00102d60,FUN_00102dc0,param_3,
                    auStack8);
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



// WARNING: Removing unreachable block (ram,0x00101153)
// WARNING: Removing unreachable block (ram,0x0010115f)

void FUN_00101140(void)

{
  return;
}



// WARNING: Removing unreachable block (ram,0x00101194)
// WARNING: Removing unreachable block (ram,0x001011a0)

void FUN_00101170(void)

{
  return;
}



void _FINI_0(void)

{
  if (DAT_001050b8 != '\0') {
    return;
  }
  __cxa_finalize(PTR_LOOP_00105088);
  FUN_00101140();
  DAT_001050b8 = 1;
  return;
}



// WARNING: Removing unreachable block (ram,0x00101194)
// WARNING: Removing unreachable block (ram,0x001011a0)

void _INIT_0(void)

{
  return;
}



// yo
// 

void * fun_z(char *str)

{
  size_t len;
  void *new_str;
  uint i;
  char *str_;
  
  len = strlen(str);
  if ((len & 1) == 0) {
    len = strlen(str);
    new_str = malloc((len >> 1) + 1);
    i = 0;
    str_ = str;
    while( true ) {
      len = strlen(str);
      if (len >> 1 < (ulong)i) break;
      __isoc99_sscanf(str_,"%2hhx",(ulong)i + (long)new_str);
      str_ = str_ + 2;
      i = i + 1;
    }
    len = strlen(str);
    *(undefined *)((long)new_str + (len >> 1)) = 0;
  }
  else {
    new_str = (void *)0x0;
  }
  return new_str;
}



undefined8 FUN_001012b9(char *param_1)

{
  size_t sVar1;
  uint local_1c;
  
  local_1c = 0;
  while( true ) {
    sVar1 = strlen(param_1);
    if (sVar1 <= local_1c) {
      return 1;
    }
    if (((byte)param_1[local_1c] < 0x20) || (0x7e < (byte)param_1[local_1c])) break;
    local_1c = local_1c + 1;
  }
  return 0;
}



undefined8 FUN_0010131c(char *param_1)

{
  size_t sVar1;
  uint local_1c;
  
  local_1c = 0;
  while( true ) {
    sVar1 = strlen(param_1);
    if (sVar1 <= local_1c) {
      return 1;
    }
    if ((param_1[local_1c] < '0') || ('9' < param_1[local_1c])) break;
    local_1c = local_1c + 1;
  }
  return 0;
}



int main(void)

{
  int iVar1;
  undefined8 uVar2;
  char buf [128];
  char *h;
  char *g;
  char *f;
  char *e;
  char *d;
  char *c;
  char *new_line;
  char *a;
  
  a = FUN_A(1);
  puts("=!= SKYNOUT DISARMAMENT CONTROL PANEL =!=");
  printf("PLEASE ENTER THE CODE TO START THE DISARMAMENT PROCEDURE: ");
  fgets(buf,128,stdin);
  new_line = strchr(buf,L'\n');
  if (new_line != (char *)0x0) {
    *new_line = '\0';
  }
  uVar2 = FUN_0010131c(buf);
  if ((char)uVar2 == '\x01') {
    puts("LET ME RUN GOVERNMENT-TIER SECURITY CHECK ...");
    fflush(stdout);
    c = FUN_0010171d(buf);
    d = FUN_A(2);
    FUN_00102aba(d,0x100);
    FUN_00102096(d,a);
    e = FUN_001017c0(PTR_DAT_00105090);
    f = FUN_00102b55(e,c,d);
    g = FUN_00101cad(f);
    h = (char *)fun_z(g);
    if (h == (char *)0x0) {
      puts("=!= ACCESS DENIED =!=");
      puts("=!= INCIDENT WILL BE REPORTED TO 42CTF =!=");
      iVar1 = -1;
    }
    else {
      uVar2 = FUN_001012b9(h);
      if ((char)uVar2 == '\x01') {
        puts("=v= SKYNOUT DISARMAMENT PROCEDURE STARTED =v=");
        printf("=v= CONFIRMATION CODE: %s =v=\n",h);
        free(g);
        free(h);
        FUN_001016f2(a);
        FUN_001016f2(c);
        FUN_001016f2(d);
        FUN_001016f2(e);
        FUN_001016f2(f);
        iVar1 = 0;
      }
      else {
        puts("=!= ACCESS DENIED =!=");
        puts("=!= INCIDENT WILL BE REPORTED TO 42CTF =!=");
        iVar1 = -1;
      }
    }
  }
  else {
    puts("=!= ACCESS DENIED =!=");
    puts("=!= INCIDENT WILL BE REPORTED TO 42CTF =!=");
    iVar1 = -1;
  }
  return iVar1;
}



undefined * FUN_001015b6(void)

{
  undefined *puVar1;
  void *pvVar2;
  
  puVar1 = (undefined *)malloc(0x18);
  *puVar1 = 0;
  pvVar2 = malloc(1);
  *(void **)(puVar1 + 8) = pvVar2;
  **(undefined **)(puVar1 + 8) = 0;
  *(undefined4 *)(puVar1 + 0x10) = 1;
  return puVar1;
}



char * FUN_A(uint param_1)

{
  int iVar1;
  char cVar2;
  char *pcVar3;
  void *pvVar4;
  int local_2c;
  uint local_c;
  
  pcVar3 = FUN_001015b6();
  if (param_1 != 0) {
    if ((int)param_1 < 0) {
      FUN_00101f39(pcVar3);
    }
    local_2c = (param_1 ^ (int)param_1 >> 0x1f) - ((int)param_1 >> 0x1f);
    local_c = 0;
    while (local_2c != 0) {
      pvVar4 = realloc(*(void **)(pcVar3 + 8),(ulong)(local_c + 1));
      *(void **)(pcVar3 + 8) = pvVar4;
      iVar1 = local_2c / 10;
      cVar2 = (char)local_2c;
      local_2c = local_2c / 10;
      *(char *)((ulong)local_c + *(long *)(pcVar3 + 8)) = cVar2 + (char)iVar1 * -10;
      local_c = local_c + 1;
    }
    *(uint *)(pcVar3 + 0x10) = local_c;
  }
  return pcVar3;
}



void FUN_001016f2(void *param_1)

{
  free(*(void **)((long)param_1 + 8));
  free(param_1);
  return;
}



char * FUN_0010171d(char *param_1)

{
  char *pcVar1;
  size_t sVar2;
  char *pcVar3;
  int local_c;
  
  pcVar1 = FUN_001015b6();
  sVar2 = strlen(param_1);
  local_c = (int)sVar2;
  while (local_c = local_c + -1, -1 < local_c) {
    pcVar3 = FUN_A((int)(char)(param_1[local_c] ^ 0x30));
    FUN_00101ab6((long)pcVar3,((int)sVar2 + -1) - local_c);
    FUN_00102096(pcVar1,pcVar3);
    FUN_001016f2(pcVar3);
  }
  return pcVar1;
}



char * FUN_001017c0(char *param_1)

{
  uint uVar1;
  char *pcVar2;
  size_t sVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  uint local_c;
  
  pcVar2 = FUN_001015b6();
  sVar3 = strlen(param_1);
  uVar1 = (uint)sVar3;
  for (local_c = 0; local_c < uVar1; local_c = local_c + 1) {
    pcVar4 = FUN_A(0x10);
    FUN_00102aba(pcVar4,(uVar1 - local_c) * 2 - 1);
    pcVar5 = FUN_A((int)param_1[local_c] >> 4 & 0xf);
    FUN_001025b0(pcVar5,pcVar4);
    FUN_00102096(pcVar2,pcVar5);
    FUN_001016f2(pcVar4);
    pcVar4 = FUN_A(0x10);
    FUN_00102aba(pcVar4,((uVar1 - local_c) + 0x7fffffff) * 2);
    pcVar6 = FUN_A((int)param_1[local_c] & 0xf);
    FUN_001025b0(pcVar6,pcVar4);
    FUN_00102096(pcVar2,pcVar6);
    FUN_001016f2(pcVar4);
    FUN_001016f2(pcVar5);
    FUN_001016f2(pcVar6);
  }
  return pcVar2;
}



void FUN_00101917(undefined *param_1,undefined *param_2)

{
  void *pvVar1;
  uint local_c;
  
  *param_1 = *param_2;
  free(*(void **)(param_1 + 8));
  pvVar1 = malloc((ulong)*(uint *)(param_2 + 0x10));
  *(void **)(param_1 + 8) = pvVar1;
  for (local_c = 0; local_c < *(uint *)(param_2 + 0x10); local_c = local_c + 1) {
    *(undefined *)(*(long *)(param_1 + 8) + (ulong)local_c) =
         *(undefined *)(*(long *)(param_2 + 8) + (ulong)local_c);
  }
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_2 + 0x10);
  return;
}



void FUN_001019ac(char *param_1)

{
  int local_c;
  
  if (*(int *)(param_1 + 0x10) != 0) {
    if (*param_1 != '\0') {
      putchar(0x2d);
    }
    local_c = *(int *)(param_1 + 0x10);
    while (local_c = local_c + -1, -1 < local_c) {
      printf("%01d",(uint)*(byte *)((long)local_c + *(long *)(param_1 + 8)));
    }
  }
  return;
}



void FUN_00101a1f(char *param_1)

{
  FUN_001019ac(param_1);
  putchar(10);
  return;
}



void FUN_00101a44(long param_1)

{
  int iVar1;
  void *pvVar2;
  int local_c;
  
  iVar1 = *(int *)(param_1 + 0x10);
  while ((local_c = iVar1 + -1, 0 < local_c &&
         (*(char *)((long)local_c + *(long *)(param_1 + 8)) == '\0'))) {
    pvVar2 = realloc(*(void **)(param_1 + 8),(long)local_c);
    *(void **)(param_1 + 8) = pvVar2;
    iVar1 = local_c;
  }
  *(int *)(param_1 + 0x10) = iVar1;
  return;
}



void FUN_00101ab6(long param_1,uint param_2)

{
  void *pvVar1;
  uint local_c;
  
  if (param_2 != 0) {
    pvVar1 = realloc(*(void **)(param_1 + 8),(ulong)(param_2 + *(int *)(param_1 + 0x10)));
    *(void **)(param_1 + 8) = pvVar1;
    memset((void *)(*(long *)(param_1 + 8) + (ulong)*(uint *)(param_1 + 0x10)),0,(ulong)param_2);
    local_c = param_2 + *(int *)(param_1 + 0x10);
    while (local_c = local_c - 1, param_2 <= local_c) {
      *(undefined *)(*(long *)(param_1 + 8) + (ulong)local_c) =
           *(undefined *)(*(long *)(param_1 + 8) + (ulong)(local_c - param_2));
      *(undefined *)((ulong)(local_c - param_2) + *(long *)(param_1 + 8)) = 0;
    }
    *(uint *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + param_2;
  }
  return;
}



void FUN_00101b97(long param_1,long param_2)

{
  int local_c;
  
  FUN_00101ab6(param_1,*(uint *)(param_2 + 0x10));
  local_c = *(int *)(param_2 + 0x10);
  while (local_c = local_c + -1, -1 < local_c) {
    *(undefined *)(*(long *)(param_1 + 8) + (long)local_c) =
         *(undefined *)(*(long *)(param_2 + 8) + (long)local_c);
  }
  FUN_00101a44(param_1);
  return;
}



undefined * FUN_00101c0a(long param_1,int param_2,int param_3)

{
  undefined *puVar1;
  void *pvVar2;
  uint local_c;
  
  puVar1 = (undefined *)malloc(0x18);
  *(int *)(puVar1 + 0x10) = param_3 - param_2;
  *puVar1 = 0;
  pvVar2 = malloc((ulong)*(uint *)(puVar1 + 0x10));
  *(void **)(puVar1 + 8) = pvVar2;
  for (local_c = 0; local_c < *(uint *)(puVar1 + 0x10); local_c = local_c + 1) {
    *(undefined *)(*(long *)(puVar1 + 8) + (ulong)local_c) =
         *(undefined *)
          (*(long *)(param_1 + 8) + (ulong)(local_c + (*(int *)(param_1 + 0x10) - param_3)));
  }
  return puVar1;
}



char * FUN_00101cad(undefined *param_1)

{
  char cVar1;
  bool bVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  char **ppcVar6;
  undefined8 uVar7;
  size_t sVar8;
  uint local_1c;
  uint local_14;
  char *local_10;
  
  local_10 = (char *)malloc(1);
  *local_10 = '\0';
  local_14 = 1;
  pcVar4 = FUN_A(0x10);
  pcVar5 = FUN_001015b6();
  FUN_00101917(pcVar5,param_1);
  bVar2 = false;
  while( true ) {
    ppcVar6 = FUN_001026d1(pcVar5,pcVar4);
    FUN_00101917(pcVar5,*ppcVar6);
    uVar3 = local_14 + 1;
    local_10 = (char *)realloc(local_10,(ulong)uVar3);
    if (*(int *)(ppcVar6[1] + 0x10) == 1) {
      local_10[local_14 - 1] = **(char **)(ppcVar6[1] + 8) + '0';
    }
    else {
      switch(**(char **)(ppcVar6[1] + 8) + *(char *)(*(long *)(ppcVar6[1] + 8) + 1) * '\n') {
      case '\n':
        local_10[local_14 - 1] = 'a';
        break;
      case '\v':
        local_10[local_14 - 1] = 'b';
        break;
      case '\f':
        local_10[local_14 - 1] = 'c';
        break;
      case '\r':
        local_10[local_14 - 1] = 'd';
        break;
      case '\x0e':
        local_10[local_14 - 1] = 'e';
        break;
      default:
        local_10[local_14 - 1] = 'f';
      }
    }
    local_10[local_14] = '\0';
    if (bVar2) break;
    uVar7 = FUN_00101f8a(pcVar5,pcVar4);
    local_14 = uVar3;
    if ((int)uVar7 < 0) {
      bVar2 = true;
    }
  }
  sVar8 = strlen(local_10);
  uVar3 = (uint)sVar8;
  for (local_1c = 0; local_1c < uVar3 >> 1; local_1c = local_1c + 1) {
    cVar1 = local_10[local_1c];
    local_10[local_1c] = local_10[(uVar3 - local_1c) - 1];
    local_10[(uVar3 - local_1c) - 1] = cVar1;
  }
  return local_10;
}



int FUN_00101f13(long param_1)

{
  return *(int *)(param_1 + 0x10) + -1;
}



void FUN_00101f27(undefined *param_1)

{
  *param_1 = 0;
  return;
}



void FUN_00101f39(char *param_1)

{
  *param_1 = *param_1 == '\0';
  return;
}



bool FUN_00101f62(long param_1)

{
  return (**(byte **)(param_1 + 8) & 1) != 0;
}



undefined8 FUN_00101f8a(char *param_1,char *param_2)

{
  undefined8 uVar1;
  int local_c;
  
  if ((*param_1 == '\0') || (*param_2 == '\x01')) {
    if ((*param_1 == '\x01') || (*param_2 == '\0')) {
      if (*(uint *)(param_1 + 0x10) < *(uint *)(param_2 + 0x10)) {
        uVar1 = 0xffffffff;
      }
      else {
        if (*(uint *)(param_2 + 0x10) < *(uint *)(param_1 + 0x10)) {
          uVar1 = 1;
        }
        else {
          local_c = *(int *)(param_1 + 0x10);
          do {
            local_c = local_c + -1;
            if (local_c < 0) {
              return 0;
            }
            if (*(byte *)((long)local_c + *(long *)(param_1 + 8)) <
                *(byte *)((long)local_c + *(long *)(param_2 + 8))) {
              return 0xffffffff;
            }
          } while (*(byte *)((long)local_c + *(long *)(param_1 + 8)) <=
                   *(byte *)((long)local_c + *(long *)(param_2 + 8)));
          uVar1 = 1;
        }
      }
    }
    else {
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



// WARNING: Removing unreachable block (ram,0x00102250)
// WARNING: Removing unreachable block (ram,0x0010227e)

void FUN_00102096(char *param_1,char *param_2)

{
  char cVar1;
  char cVar2;
  byte bVar3;
  char *pcVar4;
  void *pvVar5;
  double dVar6;
  uint local_10;
  bool local_9;
  
  if ((*param_1 == '\x01') || (*param_2 == '\0')) {
    if ((*param_1 == '\0') || (*param_2 == '\x01')) {
      local_9 = false;
      for (local_10 = 0;
          dVar6 = fmax((double)(ulong)*(uint *)(param_1 + 0x10),
                       (double)(ulong)*(uint *)(param_2 + 0x10)), local_10 < (uint)(long)dVar6;
          local_10 = local_10 + 1) {
        cVar1 = '\0';
        if (local_10 < *(uint *)(param_2 + 0x10)) {
          cVar1 = *(char *)((ulong)local_10 + *(long *)(param_2 + 8));
        }
        cVar2 = '\0';
        if (local_10 < *(uint *)(param_1 + 0x10)) {
          cVar2 = *(char *)((ulong)local_10 + *(long *)(param_1 + 8));
        }
        else {
          pvVar5 = realloc(*(void **)(param_1 + 8),(ulong)(local_10 + 1));
          *(void **)(param_1 + 8) = pvVar5;
          *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
        }
        bVar3 = local_9 + cVar2 + cVar1;
        if (bVar3 < 10) {
          *(byte *)(*(long *)(param_1 + 8) + (ulong)local_10) = bVar3;
        }
        else {
          *(byte *)((ulong)local_10 + *(long *)(param_1 + 8)) = bVar3 - 10;
        }
        local_9 = bVar3 >= 10;
      }
      if (local_9 != false) {
        pvVar5 = realloc(*(void **)(param_1 + 8),(ulong)(*(int *)(param_1 + 0x10) + 1));
        *(void **)(param_1 + 8) = pvVar5;
        *(undefined *)((ulong)*(uint *)(param_1 + 0x10) + *(long *)(param_1 + 8)) = 1;
        *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
      }
    }
    else {
      pcVar4 = FUN_001015b6();
      FUN_00101917(pcVar4,param_2);
      FUN_00102300(pcVar4,param_1);
      FUN_00101917(param_1,pcVar4);
      FUN_001016f2(pcVar4);
    }
  }
  else {
    FUN_00102300(param_1,param_2);
  }
  return;
}



// WARNING: Removing unreachable block (ram,0x001024f4)
// WARNING: Removing unreachable block (ram,0x00102522)

void FUN_00102300(char *param_1,char *param_2)

{
  char cVar1;
  char cVar2;
  char *pcVar3;
  undefined8 uVar4;
  void *pvVar5;
  double dVar6;
  uint local_10;
  bool local_9;
  
  if ((*param_1 == '\x01') || (*param_2 == '\0')) {
    uVar4 = FUN_00101f8a(param_1,param_2);
    if ((int)uVar4 == -1) {
      pcVar3 = FUN_001015b6();
      FUN_00101917(pcVar3,param_2);
      FUN_00102300(pcVar3,param_1);
      FUN_00101f39(pcVar3);
      FUN_00101917(param_1,pcVar3);
      FUN_001016f2(pcVar3);
    }
    else {
      local_9 = false;
      for (local_10 = 0;
          dVar6 = fmax((double)(ulong)*(uint *)(param_1 + 0x10),
                       (double)(ulong)*(uint *)(param_2 + 0x10)), local_10 < (uint)(long)dVar6;
          local_10 = local_10 + 1) {
        cVar2 = '\0';
        if (local_10 < *(uint *)(param_2 + 0x10)) {
          cVar2 = *(char *)((ulong)local_10 + *(long *)(param_2 + 8));
        }
        cVar1 = '\0';
        if (local_10 < *(uint *)(param_1 + 0x10)) {
          cVar1 = *(char *)((ulong)local_10 + *(long *)(param_1 + 8));
        }
        else {
          pvVar5 = realloc(*(void **)(param_1 + 8),(ulong)(local_10 + 1));
          *(void **)(param_1 + 8) = pvVar5;
          *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
        }
        cVar2 = (cVar1 - cVar2) - local_9;
        if (-1 < cVar2) {
          *(char *)(*(long *)(param_1 + 8) + (ulong)local_10) = cVar2;
        }
        else {
          *(char *)((ulong)local_10 + *(long *)(param_1 + 8)) = cVar2 + '\n';
        }
        local_9 = -1 >= cVar2;
      }
      if (local_9 != false) {
        pvVar5 = realloc(*(void **)(param_1 + 8),(ulong)(*(int *)(param_1 + 0x10) + 1));
        *(void **)(param_1 + 8) = pvVar5;
        *(undefined *)((ulong)*(uint *)(param_1 + 0x10) + *(long *)(param_1 + 8)) = 1;
        *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
      }
      FUN_00101a44((long)param_1);
    }
  }
  else {
    pcVar3 = FUN_001015b6();
    FUN_00101917(pcVar3,param_2);
    FUN_00101f39(pcVar3);
    FUN_00102096(param_1,param_2);
  }
  return;
}



void FUN_001025b0(char *param_1,char *param_2)

{
  char *pcVar1;
  char *pcVar2;
  int local_10;
  int local_c;
  
  pcVar1 = FUN_001015b6();
  local_c = *(int *)(param_1 + 0x10);
  while (local_c = local_c + -1, -1 < local_c) {
    local_10 = *(int *)(param_2 + 0x10);
    while (local_10 = local_10 + -1, -1 < local_10) {
      pcVar2 = FUN_A((uint)*(byte *)((long)local_10 + *(long *)(param_2 + 8)) *
                     (uint)*(byte *)((long)local_c + *(long *)(param_1 + 8)));
      FUN_00101ab6((long)pcVar2,local_10 + local_c);
      FUN_00102096(pcVar1,pcVar2);
      FUN_001016f2(pcVar2);
    }
  }
  if (*param_1 != *param_2) {
    FUN_00101f39(pcVar1);
  }
  FUN_00101917(param_1,pcVar1);
  FUN_001016f2(pcVar1);
  return;
}



char ** FUN_001026d1(char *param_1,char *param_2)

{
  uint uVar1;
  uint uVar2;
  char **ppcVar3;
  char *pcVar4;
  char *pcVar5;
  undefined8 uVar6;
  undefined *puVar7;
  char *pcVar8;
  char *pcVar9;
  int local_c;
  
  uVar1 = FUN_00101f13((long)param_1);
  uVar2 = FUN_00101f13((long)param_2);
  ppcVar3 = (char **)malloc(0x10);
  pcVar4 = FUN_001015b6();
  *ppcVar3 = pcVar4;
  pcVar4 = FUN_001015b6();
  ppcVar3[1] = pcVar4;
  if (uVar1 < uVar2) {
    FUN_00101917(ppcVar3[1],param_1);
  }
  else {
    if (uVar1 == uVar2) {
      pcVar4 = FUN_001015b6();
      pcVar5 = FUN_A(1);
      while( true ) {
        FUN_00102096(pcVar4,param_2);
        uVar6 = FUN_00101f8a(pcVar4,param_1);
        if (0 < (int)uVar6) break;
        FUN_00102096(*ppcVar3,pcVar5);
      }
      FUN_00102300(pcVar4,param_2);
      FUN_00101917(ppcVar3[1],param_1);
      FUN_00102300(ppcVar3[1],pcVar4);
      FUN_001016f2(pcVar5);
      FUN_001016f2(pcVar4);
    }
    else {
      puVar7 = FUN_001015b6();
      pcVar4 = FUN_A(1);
      pcVar5 = FUN_001015b6();
      local_c = *(int *)(param_1 + 0x10) + -1;
      do {
        pcVar8 = FUN_A((uint)*(byte *)((long)local_c + *(long *)(param_1 + 8)));
        FUN_00101b97((long)pcVar5,(long)pcVar8);
        FUN_001016f2(pcVar8);
        pcVar8 = FUN_001015b6();
        pcVar9 = FUN_001015b6();
        while( true ) {
          FUN_00102096(pcVar9,param_2);
          uVar6 = FUN_00101f8a(pcVar9,pcVar5);
          if (0 < (int)uVar6) break;
          FUN_00102096(pcVar8,pcVar4);
        }
        FUN_00102300(pcVar9,param_2);
        FUN_00101917(ppcVar3[1],pcVar5);
        FUN_00102300(ppcVar3[1],pcVar9);
        FUN_00101b97((long)*ppcVar3,(long)pcVar8);
        FUN_00101917(pcVar5,ppcVar3[1]);
        FUN_001016f2(pcVar8);
        FUN_001016f2(pcVar9);
        local_c = local_c + -1;
      } while (-1 < local_c);
      FUN_001016f2(pcVar5);
      FUN_001016f2(pcVar4);
      FUN_001016f2(puVar7);
      FUN_00101a44((long)*ppcVar3);
      FUN_00101a44((long)ppcVar3[1]);
    }
  }
  return ppcVar3;
}



void FUN_001029e7(void **param_1)

{
  FUN_001016f2(*param_1);
  FUN_001016f2(param_1[1]);
  free(param_1);
  return;
}



void FUN_00102a21(char *param_1,char *param_2)

{
  char **ppcVar1;
  
  ppcVar1 = FUN_001026d1(param_1,param_2);
  FUN_00101917(param_1,ppcVar1[1]);
  FUN_001029e7(ppcVar1);
  return;
}



void FUN_00102a6e(char *param_1,char *param_2)

{
  char **ppcVar1;
  
  ppcVar1 = FUN_001026d1(param_1,param_2);
  FUN_00101917(param_1,*ppcVar1);
  FUN_001029e7(ppcVar1);
  return;
}



void FUN_00102aba(char *param_1,uint param_2)

{
  char *pcVar1;
  uint local_c;
  
  if (param_2 == 0) {
    pcVar1 = FUN_A(1);
    FUN_00101917(param_1,pcVar1);
    FUN_001016f2(pcVar1);
  }
  else {
    pcVar1 = FUN_001015b6();
    FUN_00101917(pcVar1,param_1);
    for (local_c = 1; local_c < param_2; local_c = local_c + 1) {
      FUN_001025b0(param_1,pcVar1);
    }
    FUN_001016f2(pcVar1);
  }
  return;
}



char * FUN_00102b55(undefined *param_1,undefined *param_2,char *param_3)

{
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  char **ppcVar7;
  undefined8 uVar8;
  
  pcVar1 = FUN_001015b6();
  pcVar2 = FUN_A(1);
  pcVar3 = FUN_A(2);
  pcVar4 = FUN_001015b6();
  FUN_00101917(pcVar4,param_2);
  pcVar5 = FUN_001015b6();
  FUN_00101917(pcVar5,param_1);
  pcVar6 = FUN_A(1);
  while( true ) {
    uVar8 = FUN_00101f8a(pcVar4,pcVar1);
    if ((int)uVar8 == 0) break;
    ppcVar7 = FUN_001026d1(pcVar4,pcVar3);
    uVar8 = FUN_00101f8a(ppcVar7[1],pcVar1);
    if ((int)uVar8 == 0) {
      FUN_00101917(pcVar4,*ppcVar7);
      FUN_001025b0(pcVar5,pcVar5);
      FUN_00102a21(pcVar5,param_3);
    }
    else {
      uVar8 = FUN_00101f8a(pcVar4,pcVar2);
      if ((int)uVar8 == 0) {
        FUN_00101917(pcVar4,pcVar1);
      }
      else {
        FUN_00101917(pcVar4,*ppcVar7);
      }
      FUN_001025b0(pcVar6,pcVar5);
      FUN_00102a21(pcVar6,param_3);
      FUN_001025b0(pcVar5,pcVar5);
      FUN_00102a21(pcVar5,param_3);
    }
    FUN_001029e7(ppcVar7);
  }
  FUN_001016f2(pcVar1);
  FUN_001016f2(pcVar2);
  FUN_001016f2(pcVar3);
  FUN_001016f2(pcVar4);
  FUN_001016f2(pcVar5);
  return pcVar6;
}



void FUN_00102d60(undefined4 param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  
  _DT_INIT();
  lVar1 = 0;
  do {
    (*(code *)(&__DT_INIT_ARRAY)[lVar1])(param_1,param_2,param_3);
    lVar1 = lVar1 + 1;
  } while (lVar1 != 1);
  return;
}



void FUN_00102dc0(void)

{
  return;
}



void _DT_FINI(void)

{
  return;
}


