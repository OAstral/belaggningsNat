#include <stdlib.h>

#define STD_INITIAL_GRID_SIZE 2

int BuildOccupancyGrid(char **measurementData, char **positionData, char **combinedData, unsigned int dataRows, unsigned int measurementColumns, int initialGridSizeGuess) {
  if((measurementData == NULL || positionData == NULL) && combinedData == NULL) return -1;
  /* TODO: Expandera felkontroll, gör listigare också. */
  
  if(initialGridSizeGuess < STD_INITIAL_GRID_SIZE) initialGridSizeGuess = STD_INITIAL_GRID_SIZE;
  float **grid = malloc(sizeof(*grid)*initialGridSizeGuess);
  
  int row;
  for(row = 0; row < initialGridSizeGuess; row++) {
    grid[row] = malloc(sizeof(grid[row])*initialGridSizeGuess);
    /*if(grid[row] == NULL) */
  }
  
  
}
