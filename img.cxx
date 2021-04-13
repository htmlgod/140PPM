#include <fstream>
#include <iostream>

struct pixel {
	float r;
	float g;
	float b;
};

constexpr size_t HEIGHT = 1024;
constexpr size_t WIDTH = 1024;

int main() {
	pixel* buffer = new pixel[HEIGHT*WIDTH];

	for (size_t i = 0; i < HEIGHT* WIDTH; i++) {
		buffer[i].r = 100;
		buffer[i].g = 0;
		buffer[i].b = 90;
	}

	std::ofstream img("out.ppm");
	img << "P3" << std::endl;
	img << HEIGHT << " " << WIDTH << std::endl;
	img << 255 << std::endl;

	for (size_t i = 0; i < HEIGHT* WIDTH; i++) {
		img << buffer[i].r << " " << buffer[i].g << " " << buffer[i].b << std::endl;
	}

	img.close();
	
	delete[] buffer;

	return 0; 
}
