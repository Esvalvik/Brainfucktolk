#include <stdio.h>

FILE *filePath;

char Cells[256] = { 0 };
int CellPos = 0;

void logic(char c);
void printCells();
int main()
{   
	filePath = fopen("D:/Prosjekter/C/Brainfucktolk/test.bf", "r");
	if(filePath)
	{
		char c;
		while((c = getc(filePath)) != EOF)
		{
		   logic(c);
		}
	}
	else
		puts("Ingen fil å lese yo");
	fclose(filePath);

	printCells();
	return 0;
}

void logic(char c)
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
		case '+': Cells[CellPos]++; break;
		case '-': Cells[CellPos]--; break;
		case '.':
			printf("%c", (Cells[CellPos]));
		break;
		case ',':
		{
			int inChar;
			while ((inChar = getchar()) != EOF && inChar != '\n')
			{
				Cells[CellPos] = inChar;
			}
		}
		break;
		case '[':
		break;
		case ']':
		break;
	}
}	
void printCells()
{
	for(int i = 0; i < sizeof(Cells); i++)
	{
		printf("[%d]", Cells[i]);
	}
}