#include <stdio.h>
#include <string.h>

struct book {
	char title[100];
	int year;
	float price;
};

struct mahasiswa {
	char nama[50];
	int nim;
	char NoTelp[12];
};

int main(void) {
	struct book b;
	
	strcpy(b.title, "Literature");
	b.year = 2016;
	b.price = 10.85;
	printf("%s %d %.2f\n", b.title,b.year,b.price);

	struct  mahasiswa b2;
}
