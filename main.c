#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
	int fd;
	fd = open("image.ppm", O_CREAT | O_WRONLY, 0644);
	char* head = "P3 750 750 255\n";
	write(fd, head, strlen(head));
	char* buffer = malloc(50);
	int r,g,b;
	for (int i = 0; i<750; i++){
		for(int j = 0; j<750; j++){
			b = (i/3) % 255;
			g = (j/3) % 255;
			r = 255; 
			sprintf(buffer, "%d %d %d ", r, g, b);
			write(fd, buffer, strlen(buffer));
		}
	}
	return 0;
}