#include"header.h"

void  read_file(char* filename)
{
    system("cls||clear");
    FILE *filePointer = fopen(filename, "r");
    char dataToBeRead[50];

    if ( filePointer == NULL )
    {
        printf( "\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tError Opening Formula sheets 1" ) ;
    }
    else
    {
        while( fgets ( dataToBeRead, 50, filePointer ) != NULL )
        {
            printf( "%s" , dataToBeRead ) ;
        }
        fclose(filePointer) ;
    }
    return;
}
