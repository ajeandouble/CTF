#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
void reverse(char s[])
 {
     int i, j;
     char c;

     for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
         c = s[i];
         s[i] = s[j];
         s[j] = c;
     }
}  

void	itoa(long int n, char s[])
{
     int i, sign;

     if ((sign = n) < 0)  /* record sign */
         n = -n;          /* make n positive */
     i = 0;
     do {       /* generate digits in reverse order */
         s[i++] = n % 10 + '0';   /* get next digit */
     } while ((n /= 10) > 0);     /* delete it */
     if (sign < 0)
         s[i++] = '-';
     s[i] = '\0';
     reverse(s);
}

int	main()
{
	printf("%p %d\n", 0x574f4c46, 0x574f4c46 + ( long int)INT_MAX * 2 +2);
	long	int i;

	i = 0x574f4c46 ;

	while (i < LONG_MAX)
	{
		if ((int)i == 0x574f4c46)
		{
			char buffer[100];
			for (int i = 0; i < 100; ++i)
				buffer[i] = 0;
			itoa(i, buffer);
			printf("%ld %d %d\n", i, i, atoi(buffer));
		}
		i += ((long int)INT_MAX * 2 + 2) * 100;
	}
	printf("\n");
	return (0);
}