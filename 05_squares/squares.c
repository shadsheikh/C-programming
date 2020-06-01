#include <stdio.h>
#include <stdlib.h>

int isInRange(int coord , int offset ,int size)
{
  if(((offset<=coord)&&(coord<(offset+size) ) ) )
    {
      return 1;
    }
  else
    {
      return 0;
    }
}

int isAtBorder(int coord , int offset , int size )
{
  if(coord == offset || coord == (offset+size))
    {
      return 1;
    }
  else
    {
      return 0;
    }
}

int Max(int num1,int num2)
{
  if(num1 > num2)
    {
      return num1;
    }
  else
    {
      return num2;
    }
}


void squares( int size1 , int x_offset , int y_offset , int size2 )
{
  int w = Max(size1, (x_offset + size2));
  int h = Max(size1, (y_offset + size2));
  int y;
  int x;
  for(y = 0;y < h;y++)
  {
     for(x = 0;x < w;x++)
       {
	 if((isInRange(x,x_offset,size2)&&isAtBorder(y,y_offset,(size2-1)))||((isInRange(y,y_offset,size2))&&isAtBorder(x,x_offset,(size2-1))))
	   {
	     printf("*");
	   }

	   else
	     {
	       if((x < size1 && (y == 0 || y == (size1-1))) || (y < size1 && (x == 0 || x == (size1-1))) )
		   {
	             printf("#");
	           }
	       else
		   {
	             printf(" ");
	           }
	     }
	 }
	 printf("\n");
       }
  }



	    
