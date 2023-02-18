#include <stdio.h>
#include <stdlib.h>

int main()
{

    //1. Declare the file pointer or 'fp'
    FILE *filePointer;

    //2. Open the file (or create if it doesn't exist)
    filePointer=fopen("pruebaTexto.txt","w");

    //3. Get the data to be written in file
    char dataToBeWritten[50] = "Hey I'm data";

    //4. Check if this filePointer is null = the file does not exist
    if ( filePointer == NULL ){
        printf( "pruebaTexto.txt file failed to open." ) ;
    }
    else{

        printf("The file is now opened.\n") ;

        // 5. Writing in the file using fputs()
        fputs(dataToBeWritten, filePointer) ;
        fputs("\n", filePointer) ;

        // 6. Closing the file using fclose()
        fclose(filePointer) ;

        printf("Data successfully written in file \n");
        printf("The file is now closed.") ;
    }
    return 0;
}
