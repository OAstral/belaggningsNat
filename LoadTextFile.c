#include <stdio.h>
#include <stdlib.h>

#define PATHNAME_LENGTH 50
#define STANDARD_BUFFER_SIZE 16000000000

/* long LoadTextFile(const char *path, char **loadTo, unsigned long bufferSize); */

/* int main(void) { */
/*   /\*char *text = LoadTextFile("./testfil.txt", 220);*\/ */
/*   char *text; */
/*   long numberOfReads = LoadTextFile("./intel.gfs.log", &text, 0); */
/*   printf("%s\n", text); */
/*   printf("%ld\n", numberOfReads); */

/*   return 0; */
/* } */


long LoadTextFile(const char *path, char **loadTo, unsigned long bufferSize) {
  if(loadTo == NULL) return -1;
  
  char mode = 'r';
  FILE *fp = fopen(path, &mode);
  
  if(bufferSize < 1) bufferSize = STANDARD_BUFFER_SIZE;
  char *buffer = malloc(sizeof(char)*(bufferSize + 1));
  if(buffer == NULL) return -2;
  
  unsigned long numberOfReads = 0;
  char read;
  while(numberOfReads < bufferSize) {
    read = fgetc(fp);
    if(read == EOF) { break; } /* PROBLEM: Det här verkar inte fungera, läser alltid till bufferSize. UPPDATERING: Inte fel, fil innehöll cirka 1,7 miljoner tecken. */
    buffer[numberOfReads] = read;
    numberOfReads++;
  }
  buffer[numberOfReads] = '\0';
  *loadTo = realloc(buffer, sizeof(char)*(numberOfReads + 1));
  return numberOfReads;
}
