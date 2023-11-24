//THIS PROGRAM WILL TAKE A SODUKU PUZZLE FROM A USER AND SOLVE THE PUZZLE

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

char mnpzl[12][12]; //Original Unsolved Soduku Puzzle
char mnpzl2[12][12];//Copy of Original Unsolved Soduku Puzzle
char newpzl[12][12];//New Solved Soduku Puzzle
char curROW[12];
char curCOL[12];
char curGRD[12];

takepuzzle()
{
	printf("\nKindly enter the characters of the cells of the Unsolved Puzzle. If the cell is blank, enter '*'.\n");
	int i,j;
	char now;
	for(i=0;i<12;i++)
	{
		for(j=0;j<12;j++)
		{
			printf("Row %d, Column %d: ",i+1,j+1);
			scanf(" %c",&mnpzl[i][j]);
			now=mnpzl[i][j];
			//make every letter uppercase
			if(now>=97&&now<=122)
			{
				mnpzl[i][j]=now-32;
			}
			mnpzl2[i][j]=mnpzl[i][j];
		}
	}
}

char randlet()
{
	char newlet;
	
	newlet='A'+(rand()%25);
	
	return newlet;
}

output()
{
	printf("\nThank you for trusting us to solve the puzzle.\n");
	
	int oki,noki;
	
	//PRINT UNSOLVED PUZZLE
	printf("\nUNSOLVED PUZZLE\n");
	printf("+------------+------------+------------+\n");
	for(oki=0;oki<12;oki++)
	{
		for(noki=0;noki<12;noki++)
		{			
			if(noki==0)
			{
				printf("|");
			}
			printf(" %c ",mnpzl2[oki][noki]);
			if((noki==3)||(noki==7)||(noki==11))
			{
				printf("|");
			}
		}
		printf("\n");
		if((oki==2)||(oki==5)||(oki==8)||(oki==11))
		{
			printf("+------------+------------+------------+");
			printf("\n");
		}
	}
	
	
	//PRINT SOLVED PUZZLE
	printf("\nSOLVED PUZZLE\n");
	printf("+------------+------------+------------+\n");
	for(oki=0;oki<12;oki++)
	{
		for(noki=0;noki<12;noki++)
		{			
			if(noki==0)
			{
				printf("|");
			}
			printf(" %c ",newpzl[oki][noki]);
			if((noki==3)||(noki==7)||(noki==11))
			{
				printf("|");
			}
		}
		printf("\n");
		if((oki==2)||(oki==5)||(oki==8)||(oki==11))
		{
			printf("+------------+------------+------------+");
			printf("\n");
		}
	}
}

int main()
{
	printf("Welcome to this Program.\nThis program will take a 12x12 Soduku Puzzle from you and solve it.\nIt will output both the unsolved and solved puzzle.\n");	
	takepuzzle();
	
	int i,j;
	int row,col,grid;
	int nrow,ncol;
	int check;//check if cell is empty
	char current;
	char newlet;//new randomly generated letter
	char temp;
	char test;
	int R,C;//variables for row and column
	int g,h;
	int r1,r2,c1,c2;
	int A,testy;
	
	for(i=0;i<12;i++)
	{
		for(j=0;j<12;j++)
		{
			current=mnpzl[i][j];//determine the current cell
			row=i;//determine the current row
			col=j;//determine the current col
			
			//determine the current grid
			if((row>=0&&row<=2)&&(col>=0&&col<=3))
			{
				grid=1;
			}
			if((row>=0&&row<=2)&&(col>=4&&col<=7))
			{
				grid=2;
			}
			if((row>=0&&row<=2)&&(col>=8&&col<=11))
			{
				grid=3;
			}
			if((row>=3&&row<=5)&&(col>=0&&col<=3))
			{
				grid=4;
			}
			if((row>=3&&row<=5)&&(col>=4&&col<=7))
			{
				grid=5;
			}
			if((row>=3&&row<=5)&&(col>=8&&col<=11))
			{
				grid=6;
			}
			if((row>=6&&row<=8)&&(col>=0&&col<=3))
			{
				grid=7;
			}
			if((row>=6&&row<=8)&&(col>=4&&col<=7))
			{
				grid=8;
			}
			if((row>=6&&row<=8)&&(col>=8&&col<=11))
			{
				grid=9;
			}
			if((row>=9&&row<=11)&&(col>=0&&col<=3))
			{
				grid=10;
			}
			if((row>=9&&row<=11)&&(col>=4&&col<=7))
			{
				grid=11;
			}
			if((row>=9&&row<=11)&&(col>=8&&col<=11))
			{
				grid=12;
			}
			
			//fill cell
			/*first, check if cell is empty*/
			if(current=='*')
			{
				check=0;
			}
			else
			{
				check=1;
				newpzl[i][j]=mnpzl[i][j];
			}
			
			if(check==0)
			{
				//Determining the current row elements
				for(C=0;C<12;C++)
				{
					curROW[C]=mnpzl[row][C];
				}
				//Determining the current column elements
				for(R=0;R<12;R++)
				{
					curCOL[R]=mnpzl[R][col];
				}
				//Determining the current grid elements
				if(grid==1)
				{
					r1=0;
					r2=2;
					c1=0;
					c2=3;
				}
				else if(grid==2)
				{
					r1=0;
					r2=2;
					c1=4;
					c2=7;
				}
				else if(grid==3)
				{
					r1=0;
					r2=2;
					c1=8;
					c2=11;
				}
				else if(grid==4)
				{
					r1=3;
					r2=5;
					c1=0;
					c2=3;
				}
				else if(grid==5)
				{
					r1=3;
					r2=5;
					c1=4;
					c2=7;
				}
				else if(grid==6)
				{
					r1=3;
					r2=5;
					c1=8;
					c2=11;
				}
				else if(grid==7)
				{
					r1=6;
					r2=8;
					c1=0;
					c2=3;
				}
				else if(grid==8)
				{
					r1=6;
					r2=8;
					c1=4;
					c2=7;
				}
				else if(grid==9)
				{
					r1=6;
					r2=8;
					c1=8;
					c2=11;
				}
				else if(grid==10)
				{
					r1=9;
					r2=11;
					c1=0;
					c2=3;
				}
				else if(grid==11)
				{
					r1=9;
					r2=11;
					c1=4;
					c2=7;
				}
				else if(grid==12)
				{
					r1=9;
					r2=11;
					c1=8;
					c2=11;
				}
				A=0;
				for(R=r1;R<=r2;R++)
				{
					for(C=c1;C<=c2;C++)
					{
						curGRD[A]=mnpzl[R][C];
						A++;
					}
				}
				
				//Solve the Puzzle
				testy=1;
				while(testy!=0)
				{
					temp=randlet();
					
					if((temp==curROW[0])||(temp==curROW[1])||(temp==curROW[2])||(temp==curROW[3])||(temp==curROW[4])||(temp==curROW[5])||(temp==curROW[6])||(temp==curROW[7])||(temp==curROW[8])||(temp==curROW[9])||(temp==curROW[10])||(temp==curROW[11])||(temp==curCOL[0])||(temp==curCOL[1])||(temp==curCOL[2])||(temp==curCOL[3])||(temp==curCOL[4])||(temp==curCOL[5])||(temp==curCOL[6])||(temp==curCOL[7])||(temp==curCOL[8])||(temp==curCOL[9])||(temp==curCOL[10])||(temp==curCOL[11])||(temp==curGRD[0])||(temp==curGRD[1])||(temp==curGRD[2])||(temp==curGRD[3])||(temp==curGRD[4])||(temp==curGRD[5])||(temp==curGRD[6])||(temp==curGRD[7])||(temp==curGRD[8])||(temp==curGRD[9])||(temp==curGRD[10])||(temp==curGRD[11]))
					{
						testy=1;
					}
					
					else
					{
						testy=0;
					}
				}
				mnpzl[i][j]=temp;
				newpzl[i][j]=temp;
			}
		}
	}

	output();	
}
