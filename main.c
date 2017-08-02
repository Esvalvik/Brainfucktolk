#include <stdio.h>

FILE *filePath;

int Cells[256];
int CellPos = 0;
int main()
{   
    for(int i = 0; i < sizeof(Cells); i++)
    {
        Cells[i] = 0;
    }
	char fileName[64];
	if(fgets(fileName, sizeof(fileName), stdin))
	{
		printf("Du skrev %s", fileName );
		filePath = fopen("D:/Prosjekter/C/Brainfucktolk/test.bf", "r");
		if(filePath)
		{
			char c;
			while((c = getc(filePath)) != EOF)
			{
                switch(c)
                {
                    case '>':
                        if((CellPos + 1) < 254)
                            CellPos++;
                    break;
                    case '<':
                        if((CellPos - 1) >= 0)
                            CellPos--;
                    break;
                    case '+':
                        Cells[CellPos]++;
                    break;
                    case '-':
                        Cells[CellPos]--;
                    break;
                    case '.':
                        printf("%c", (Cells[CellPos]));
                    break;
                    case ',':
                        Cells[CellPos] = getchar();
                    break;
                    case '[':
                    break;
                    case ']':
                    break;
                }
			}
		}
		else
			puts("Ingen fil å lese yo");
		fclose(filePath);
	}
	return 0;
}