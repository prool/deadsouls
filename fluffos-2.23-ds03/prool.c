#include <stdio.h>
#include <sys/types.h>

#include "prool.h"

#define PROOL_LOG "/home/prool/DeadSouls/lib/log/prool.log"

char *ptime(void) // Возвращаемое значение: ссылка на текстовую строку с текущим временем
	{
	char *tmstr;
	time_t mytime;

	mytime = time(0);

	tmstr = (char *) asctime(localtime(&mytime));
	*(tmstr + strlen(tmstr) - 1) = '\0';

	return tmstr;

	}

void prool_log(char *str)
{
FILE *fp;
fp=fopen(PROOL_LOG,"a");
if (fp==NULL) return;
fprintf(fp,"%s %s\n",ptime(),str);
fclose(fp);
fflush(0);
}
