/*
#include "kml.h"

void kmlbegin()
{


}

void kmlplacemark()
{

}

void kmlend()
{


}

void setcitystatecountry(int i)
{
	if(i < 4){
	} else
		p = strchr(buf, ',');
		s = strtok(buf, ",");
		//p = strtok(buf, ",");

		length = strlen(p);
		if(length - 1 == 2) {
			//data->data[i].state = s;
			data->data[i].state = malloc(length * sizeof(char*));
			strncpy(data->data[i].state, p, length);
			data->data[i].country = malloc(uslength * sizeof(char*));
			strncpy(data->data[i].state, p, length);
			//data->data[i].country = us;
		} else {
			data->data[i].country = malloc(length * sizeof(char*));
			strncpy(data->data[i].country, p, length);
			//data ->data[i].country = s;
		}
		//*p = '\0';

		length = strlen(s);
		data->data[i].city = malloc(length * sizeof(char*));
		strncpy(data->data[i].city, s, length);
		//data->data[i].city = s;

}

void setlatitude()
{


}

void setlongitude()
{


}
*/
