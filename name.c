#include <stdio.h>
#include <stdlib.h>

void draw_circle(char **data, int x1, int y1) {
	int r = 10;

	for(int i=0+y1; i<=r*2+y1; i++)  {
		for(int j=0+x1; j<=r*2+x1; j++)  {
			float dist2 = (i-r-y1)*(i-r-y1) + (j-r-x1)*(j-r-x1);
			if (dist2 <= r*r) 
				data[i][j]= '*';
		}
	}

}

void draw_bar(char **data, int x1, int y1) {
        for(int i=0+y1; i<=20+y1; i++)  {
                for(int j=0+x1; j<=2+x1; j++)  {
			data[i][j]= '*';
                }

        }
}

void draw_rect(char **data, int x1, int y1) {
        for(int i=0+y1; i<=20+y1; i++)  {
                for(int j=0+x1; j<=20+x1; j++)  {
			data[i][j]= '*';
                }

        }
}

void draw_rect1(char **data) {
        for(int i=0; i<=20; i++)  {
                for(int j=0; j<=20; j++)  {
			data[i][j]= '*';
                }

        }
}



void draw_ga(char **data, int x1, int y1) {
        for(int i=0+y1; i<=2+y1; i++)  {
                for(int j=0+x1; j<=20+x1; j++)  {
			data[i][j]= '*';
                }
        }


        for(int i=0+y1; i<=20+y1; i++)  {
                for(int j=18+x1; j<=20+x1; j++)  {
			data[i][j]= '*';
                }
        }
}



void draw_all(char **data, int N) {
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) printf("%c", data[i][j]);
		printf("\n");
	}
}
	
int main(void) {
	int N = 100;
	char **data;
	data = (char **)malloc(N*sizeof(char *));
	for (int i=0; i<N; i++) data[i] = (char *)malloc(N*sizeof(char));


	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++) 
			data[i][j] = ' ';


	//draw_rect1(data);
	draw_rect(data, 5, 5);
	draw_bar(data, 35, 5);

	draw_circle(data, 5, 30);
	draw_bar(data, 35, 30);
	/*
	draw_circle(data, 0, 0);
	draw_bar(data, 30, 0);
	draw_rect(data, 10, 22);

	draw_rect(data, 0, 45);
	draw_bar(data, 30, 45);

	draw_ga(data, 0, 0);
	*/	

	draw_all(data, N);


}
