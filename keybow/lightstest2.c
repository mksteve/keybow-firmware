#include "lights.h"

int main(int argc, char **argv) {
  int i = 1;
  int r,g,b;
  int counter = 0;
  initLights();

  lights_show();
  lights_setAll(0,0,0);
      
  do {
    int delta = 1; (millis() / (1000/60)) % height;
    printf("Frame: %d\n", delta);
    int offset = atoi( argv[1] );
    for( i = 2; i < argc; i+= 3, counter++ ){
      if( i + 2 >= argc ) break;
      r = atoi( argv[i] );
      g = atoi( argv[i+1] );
      b = atoi( argv[i+2] );
      printf( "Updating %d with (%d %d %d)\n", counter + offset, r,g,b );
      lights_setPixel( counter + offset, r, g, b );
    }
    lights_show();
    usleep(10000000/60);
  } while(0 );
  sleep( 1 );
  lights_cleanup();
}
