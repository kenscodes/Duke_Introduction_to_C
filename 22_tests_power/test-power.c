#include<stdio.h>
 #include<stdlib.h>

 unsigned power(unsigned x,unsigned y);

int main()
{
  if( power(0,0) != 1)
    {printf("broken1  implementation");
      exit(EXIT_FAILURE);}
  
  if(power(30,0) != 1)
    {printf("broken2 implementation");
    exit(EXIT_FAILURE);}
  
  if(power(0,1) != 0)
    {printf("broken3 implementation");
      exit(EXIT_FAILURE);}
  
   if(power(45,1) != 45)
     {printf("broken4 implementation");
	  exit(EXIT_FAILURE);}
   
   if(power(2,3)== power(3,2))
     {printf("broken5 implementation");
       exit(EXIT_FAILURE);}
   
   if(power(4,2) != power(2,4))
     {printf("broken6 implementation");
       exit(EXIT_FAILURE);}

   if(power(2,3)==9)
     {printf("broken7 implementation");
       exit(EXIT_FAILURE);}
   
   if(power(2, -2) == 4)
     {printf("broken8 implementation");
       exit(EXIT_FAILURE);}
   
   if(power(64,3) !=262144 )
     {printf("broken10 implementation");
       exit(EXIT_FAILURE);}

   if(power(256, 2) != 65536)
     {printf("broken9 implementation");
       exit(EXIT_FAILURE);}

   if(power(2,4 ) != 16)
     {printf("broken11 implementation");
       exit(EXIT_FAILURE);}
   return EXIT_SUCCESS;
}
