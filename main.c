/*
Authors
Pruthvish Eshwar - PES1201701629
Harish P B - PES1201701435
Ashrith S - PES1201700649
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// declare a structure stringpair to hold filename as key and its path as the value
struct stringpair{
    char key[1000];
    char value[1000];
}myfiles[1000],temp;


int main()
{
    /*
    execute the command find . in the current directory to retrieve all the paths
    in the current directory and store them in checkfiles.txt
    */
    char command[50];
    strcpy( command, "find . > checkfiles.txt" );
    system(command);
    char *fname = NULL;
    int k = -1;
    /*
    open the file checkfiles.txt in read mode and read the file line by line
    */
    FILE* file = fopen("checkfiles.txt", "r");
    char line[1024];
    while(fgets(line, sizeof(line), file)){
        /*
        note that fgets don't strip the terminating \n, checking its
        presence would allow to handle lines longer that sizeof(line)
        */
        if(line[1] == '\n' || (line[1] == '.' || line[0] == '\n')) continue;
        /*
        retrieve the filename without the extension and store it in char array
        withoutex
        */
   	    fname = strrchr (line, '/') + 1;
        char withoutex[strlen(fname)];
   	    int i;
   		  for(i = 0;i < strlen(fname);i++){
   			if(fname[i] == '.')
            break;
   			withoutex[i] = fname[i];
   		  }
   		  withoutex[i] = '\0';
        k = k+1;
        /*
        store the file name without extension as the key and the path as the value
        */
        strcpy(myfiles[k].key,withoutex);
        strcpy(myfiles[k].value,line);
    }
    /*
    sort the array of structure myfiles based on filename
    */
    for (int i = 1; i < k; i++)
        for (int j = 0; j < k - i; j++){
            if (strcmp(myfiles[j].key, myfiles[j + 1].key) > 0){
                temp = myfiles[j];
                myfiles[j] = myfiles[j + 1];
                myfiles[j + 1] = temp;
            }
        }

    printf("filename :- %s\n",myfiles[0].key);
    printf("paths the file is present:-\n");
    printf("\t%s\n",myfiles[0].value);
    /*
    traverse the array of structure myfiles to output the filename and the path
    associated to the filename
    */
    for (int i = 1; i < k; i++){
        if(strcmp(myfiles[i-1].key,myfiles[i].key) == 0){
            printf("\t%s\n",myfiles[i].value);
        }
        else{
            printf("filename :- %s\n",myfiles[i].key);
            printf("paths the file is present:-\n");
            printf("\t%s\n",myfiles[i].value);
        }
    }
    return(0);
}
