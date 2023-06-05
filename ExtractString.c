#include <stdio.h>
#include <string.h>

unsigned long ExtractString(const char *source, const unsigned long sourceSize, char *destination, const unsigned long destinationMaxSize, const char *startsWith, const int startsWithSize, const char *endsWith, const int endsWithSize) {
  char c;
  unsigned long i = 0, numberOfCharsExtracted = 0;
  int startsIndex = 0;
  int endsIndex = 0;
  
  char tempStringBuffer[destinationMaxSize];
  tempStringBuffer[destinationMaxSize - 1] = '\0';

  do {
    c = source[i];
    printf("%ld. %c\n", numberOfCharsExtracted, c);
    if(startsIndex < startsWithSize) {
      if(c == startsWith[startsIndex]) {
	tempStringBuffer[numberOfCharsExtracted + startsIndex] = c;
	startsIndex++;
	if(startsIndex == startsWithSize) {
	  numberOfCharsExtracted = numberOfCharsExtracted + startsIndex;
	}
      } else { startsIndex = 0; }
    }
    else {
      tempStringBuffer[numberOfCharsExtracted] = c;
      numberOfCharsExtracted++;
      if(c == endsWith[endsIndex]) {
	endsIndex++;
	if(endsIndex == endsWithSize) startsIndex = 0;
      } else { endsIndex = 0; }
    }
    i++;
  } while(c != '\0' && numberOfCharsExtracted < destinationMaxSize - 1 && i < sourceSize);

  strcpy(destination, tempStringBuffer);
  return(numberOfCharsExtracted);
}

int main(void) {
  char input[] = "telefon";
  char output[20];
  unsigned long returnd = ExtractString(input, 7, output, 20, "lef", 3, "o", 1);
  printf("%s\n%s\n%ld",input,output,returnd);
}
