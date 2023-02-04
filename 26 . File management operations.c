#include <stdio.h>
# include <string.h>

int main( )
{

	FILE *filePointer ;


	char dataToBeWritten[50]
		= "OPERATING SYSTEM LABORATORY";

	filePointer = fopen("balaji.c", "w") ;


	if ( filePointer == NULL )
	{
		printf( "balaji.c file failed to open." ) ;
	}
	else
	{

		printf("The file is now opened.\n") ;


		if ( strlen ( dataToBeWritten ) > 0 )
		{

			fputs(dataToBeWritten, filePointer) ;
			fputs("\n", filePointer) ;
		}
		fclose(filePointer) ;

		printf("Data successfully written in file balaji.c\n");
		printf("The file is now closed.") ;
	}
  return 0;
  }



/*    OUTPUT  


The file is now opened.
Data successfully written in file balaji.c
The file is now closed.
--------------------------------
