#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int string_length(char *pointer)
{
  int c = 0;

  while( *(pointer + c) != '\0' )
    c++;

  return c;
}

void reverse(char * s) {
  if(s!=NULL){
  int length, c;
  char *begin, *end, temp;
  length = string_length(s);
  begin  = s;
  end    = s;

  for (c = 0; c < length - 1; c++)
    end++;

  for (c = 0; c < length/2; c++)
    {
      temp   = *end;
      *end   = *begin;
      *begin = temp;

      begin++;
      end--;
    }
  }
}



int main(void) {
  char str0[] = "";
  char str1[] = "123";
  char str2[] = "abcd";
  char str3[] = "Captain's log, Stardate 42523.7";
  char str4[] = "Hello, my name is Inigo Montoya.";
  char str5[] = "You can be my wingman anyday!";
  char str6[] = "Executor Selendis! Unleash the full power of your forces! There may be no tomorrow!";
  char * array[] = {str0, str1, str2, str3, str4, str5, str6};
  for (int i = 0; i < 7; i++) {
    reverse(array[i]);
    printf("%s\n", array[i]);
  }
  return EXIT_SUCCESS;
}
