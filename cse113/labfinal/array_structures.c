#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>

struct info_t {
	char *name;
	int date;
	int t; //in minutes

}

void printmovie(struct info_t info[]);
char *get_data(char *s);

int main() {
	FILE * input;
	char buffer[256];
	input = fopen("pixar.txt", "r");
	struct info_t info[20];
	int i;
	char *s, *movie, *t, *year;

	while (fgets(buffer, 256, input) != NULL) {
		//fill in the array of structures here

			/* remove new line in buf */
			rstrip(buf);

			s = strtok(buffer, ",");
			movie = get_data(s);
			info[i] -> name = movie;

			s = strtok(NULL, ",");
			year = get_data(s);
			info[i].date = atoi(year);

			s = strtok(NULL, "\n");
			t = get_data(s);
			info[i].t = atoi(t);
			i++;

	}

    //call the print function
    	for(i=0; i<20; i++){
	printmovie(info[i]);
	}
	return 0;
}

//add the function to print the shortest movie here
void printmovie(struct info_t info)
{
	printf("%c (%d): %d\n", info->name, info.date, info.t);
}

char *get_data(char *s)
{
	char *t = malloc((strlen(s) + 1) * sizeof(char));
	if (!t)
		end_prog(ENOMEM);
	return strncpy(t, s, strlen(s) + 1);
}
