
#include <libc.h>

typedef	int		undefined4;
typedef	char	undefined;

int	main(int ac, char **av)
{
	long lVar1;
	undefined4 uVar2;
	char local_1e;
	char local_1d;
	char local_1c;
	char local_1b;
	char *local_14;
	// undefined *local_c;
	// local_c = &stack0x00000004;
	local_14 = "ksuiealohgy";
	// lVar1 = ptrace(PTRACE_TRACEME,0,1,0);
	puts("############################################################");
	puts("##        Bienvennue dans ce challenge de cracking        ##");
	puts("############################################################\n");
	printf("Password : ");
	fgets(&local_1e,9,(FILE *)stdin);
	if ((((local_1e == local_14[4]) && (local_1d == local_14[5])) && (local_1c == local_14[1])) &&
			(local_1b == local_14[10])) {
		puts("\nGood password !!!\n");
	}
	else {
		printf("[%c]", local_14[4]);
		printf("[%c]", local_14[5]);
		printf("[%c]", local_14[1]);
		printf("[%c]", local_14[10]);
		fflush(stdout);
		puts("\nWrong password.\n");
	}
	uVar2 = 0;
	return uVar2;
}