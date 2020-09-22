#include <stdio.h>
#include <string.h>
#include <stdlib.h>




int main () {
   char command[50];

   strcpy( command, "find . > checkfiles.txt" );
   system(command);
   char *fname = NULL;
   //char *withoutex = NULL;
   
   FILE* file = fopen("checkfiles.txt", "r");
   char line[1024];

    while (fgets(line, sizeof(line), file)) {
        /* note that fgets don't strip the terminating \n, checking its
           presence would allow to handle lines longer that sizeof(line) */
   		if(line[1] == '\n' || (line[1] == '.' || line[0] == '\n')) continue;
   		//printf("line :-%s\n",line );
   		
   		fname = strrchr (line, '/') + 1;
   		char withoutex[strlen(fname)];
   		int i;
   		for( i =0;i<strlen(fname);i++)
   		{
   			if(fname[i] == '.') break;
   			//printf("%c\n",fname[i]);
   			withoutex[i] = fname[i];
   		}	 
   		withoutex[i] = '\0';
   		//if(strlen(fname) <=1) continue;
   		printf("filename:- %s\npath:- %s\n",withoutex,line);
        
    }

   

   return(0);
} 




