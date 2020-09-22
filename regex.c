#include <stdio.h>
#include <libgen.h>
#include <string.h>



int main(int argc, char const *argv[])
{
char *path ="ab/cde/fg.out";
char *ssc;
int l = 0;
ssc = strstr(path, "/");
do{
    l = strlen(ssc) + 1;
    path = &path[strlen(path)-l+2];
    ssc = strstr(path, "/");
}while(ssc);
printf("%s\n", path);
	return 0;
}