/**
* @file gl.c
*
* @author Julian Garcia
*
* @date 12/04/2018
*
* Assignment: Game of Life
*
* @brief contains main function for game of life
*
* @details Contains main function for game of life
*
* @bugs none
*
* @todo Finish flag functions, fix capturing user input.
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>
#include "SDL2/SDL.h"
#include "sdl.h"
#include "life.h"

int main(int argc, char *argv[])
{

	int width;
	int height;
	int sprite_size; /* either 2, 4, 8, or 16 */
	int m;
	int n;
	char *s, *n1, *n2;
	//unsigned char **data;
	//int i = 0;
	//FILE *fp;
	/* colors are RGB model valid values [0, 255] */
	unsigned char red;
	unsigned char green;
	unsigned char blue;

	printf("Program Name Is: %s",argv[0]);
	if(argc==1)
    		printf("\nNo Extra Command Line Argument Passed Other Than Program Name");
		width = 800;
		height = 600;
		sprite_size = 4; /* either 2, 4, 8, or 16 */
		m = -66;
		n = -10;
		/* colors are RGB model valid values [0, 255] */
		red = 140;
		green = 145;
		blue = 250;
	if(argc>=2){

		int opt;

   		while((opt = getopt(argc, argv, ":w:h:e:r:g:b:s:f:o:H")) != -1)
   		{
       			switch(opt)
       			{
	   			case 'w':
					width = atoi(optarg);

	   			case 'h':
					height = atoi(optarg);
	   			case 'e':
	       				if(strcmp("torus", optarg)== 0){
						printf("torus\n");
					}else if(strcmp("hedge", optarg)== 0){
						printf("hedge\n");
					}else if(strcmp("klein", optarg)== 0){
						printf("klein\n");
					}
	       				break;
	   			case 'r':
	       				red = atoi(optarg);
	       				break;
				case 'g':
		       			green = atoi(optarg);
		       			break;
				case 'b':
		       			blue = atoi(optarg);
		       			break;
				case 's':
					sprite_size = atoi(optarg);
					break;
				case 'f':
					printf("filename: %s\n", optarg);
					//FILE *fopen (const char * restrict filename, const char * restrict mode);
					//fp = fopen(optarg, "r");

					break;
				case 'o':

					s = strtok(optarg, ",");
					n1 = get_data(s);
					s = strtok(NULL, "\n");
					n2 = get_data(s);
					m = atoi(n1);
					n = atoi(n2);
					break;
				case 'H':
					printf("-w: Width of screen\n");
					printf("-h: Height of screen\n");
					printf("-e type of edge");
					printf("\n-r: Red color value");
					printf("\n-g: Green color value");
					printf("\n-b: Blue color values");
					printf("\n-s: Size of sprite");
					printf("\n-f: filename");
					printf("\n-o: initial x,y coordinate");
					printf("\nH: Help, prints command arguments\n");
					break;
	   			case ':':
	       				printf("option needs a value\n");
	       				break;
	   			case '?':
	       				printf("unknown option: %c\n", optopt);
	       				break;
       			}
   		}

   		// optind is for the extra arguments
   		// which are not parsed
   		for(; optind < argc; optind++){
       		printf("extra arguments: %s\n", argv[optind]);
   		}

	}
	int row;
	int column;
	unsigned char **a, **b;
	row = find_size(width, sprite_size);
	column = find_size(height, sprite_size);
	a = init_matrix(row, column);
	if (!a){
		exit(EXIT_FAILURE);
	}
	b = init_matrix(row, column);
	if (!b){
		exit(EXIT_FAILURE);
	}

	/*int len = 200;
	char buf[len];
	while (fgets(buf, len, fp)) {
		data = realloc(data, (i + 1) * sizeof(int));
		*(data + i) = atoi(buf);
		i++;
	}*/

	//fclose(fp);

        struct sdl_info_t sdl_info; /* this is needed to graphically display the game */

        /* set up SDL -- works with SDL2 */
	init_sdl_info(&sdl_info, width, height, sprite_size, red, green, blue);

	/* your life initialization code here */
	sdl_render_life(&sdl_info, a);
        /* Main loop: loop forever. */
	while (1)
	{
		/* your game of life code goes here  */

		/* change the  modulus value to slow the rendering */
		 //if (SDL_GetTicks() % 50 == 0)
			//sdl_test(&sdl_info, m, n);

                 /* Poll for events, and handle the ones we care about.
                  * You can click the X button to close the window
                  */
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_KEYDOWN:
				break;
			case SDL_KEYUP:
                        /* If escape is pressed, return (and thus, quit) */
				if (event.key.keysym.sym == SDLK_ESCAPE)
					return 0;
				break;
			case SDL_QUIT:
				return(0);
			}
		}
	}

	free_matrix(a, row);
	free_matrix(b, row);

	return 0;
}
