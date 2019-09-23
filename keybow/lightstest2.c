#include "lights.h"

int main(int argc, char **argv) {
    int i = 1;
    int r,g,b;
    int counter = 0;
    initLights();

    lights_setAll(0,0,0);
    lights_show();
      
    do {
	int delta = 1; (millis() / (1000/60)) % height;
	printf("Frame: %d\n", delta);
	for( i = 1; i < argc; i+= 3, counter++ ){
	    if( i + 2 >= argc ) break;
	    r = atoi( argv[i] );
	    g = atoi( argv[i+1] );
	    b = atoi( argv[i+2] );
	    printf( "Updating %d with (%d %d %d)\n", counter , r,g,b );
	    lights_setPixel( counter, r, g, b );
	}
	lights_show();
	usleep(1000000/60);
    } while(0 );
    sleep( 10 );
    lights_cleanup();
}
