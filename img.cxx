#include <fstream>
#include <iostream>

struct pixel {
	float r;
	float g;
	float b;
};

constexpr size_t HEIGHT = 1024;
constexpr size_t WIDTH = 1024;

void render(const char* file, pixel* buffer) {
	std::ofstream img(file);
	img << "P3" << std::endl;
	img << HEIGHT << " " << WIDTH << std::endl;
	img << 255 << std::endl;

	for (size_t i = 0; i < HEIGHT* WIDTH; i++) {
		img << buffer[i].r << " " << buffer[i].g << " " << buffer[i].b << std::endl;
	}

	img.close();
}

int main() {
	pixel* framebuffer = new pixel[HEIGHT*WIDTH];

	for (size_t i = 0; i < HEIGHT* WIDTH; i++) {
		framebuffer[i].r = 100;
		framebuffer[i].g = 0;
		framebuffer[i].b = 90;
	}

	render("singlecolor.ppm", framebuffer);
	
	delete[] framebuffer;

	return 0; 
}
