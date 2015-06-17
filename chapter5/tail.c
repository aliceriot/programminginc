#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

/* 				This is going to be a simple implementation of tail, which accepts */
/* 				STDIN and one commandline argument -n num, where num is the number */
/* 				of lines at the end of the input to print. */

int mygetline(char s[], int lim);
								
void main(int argc, char *argv[])
{
				char line[MAXLINE];
				char *lines[2000];
				char *temp;
				int len;
				int numlines = 0;
				int printlines = 10;
				if (argc == 0)
								printf("usage: tail -n num\n");
				else {
								while (mygetline(line, MAXLINE) > 0) {
												temp = malloc(sizeof(line));
												strcpy(temp, line);
												lines[numlines++] = temp;
								}
								if (argc > 1 && strcmp(argv[1], "-n") == 0) {
												printlines = atoi(argv[2]);
								}
				}
				if (printlines > numlines)
								printlines = 0;
				else
								printlines = numlines - printlines;

				for (; printlines < numlines; printlines++)
								printf("%s", lines[printlines]);
}

int mygetline(char s[], int lim)
{
    int c,i;
    for (i=0; (c=getchar()) != EOF && c!='\n' && i < lim -1; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
