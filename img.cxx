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

	// set color for framebuffer
	for (size_t i = 0; i < HEIGHT* WIDTH; i++) {
		framebuffer[i].r = 100;
		framebuffer[i].g = 0;
		framebuffer[i].b = 90;
	}
	//render("singlecolor.ppm", framebuffer);

	// draw green thick diagonal line
	framebuffer[0].r = 0;
	framebuffer[0].b = 0;
	framebuffer[0].g = 255;
	for (size_t y = 1; y < HEIGHT; y++) {
		for (size_t x = 1; x < WIDTH; x++) {
			if (x == y) { 
				framebuffer[x + y*WIDTH].r = 0;
				framebuffer[x + y*WIDTH].b = 0;
				framebuffer[x + y*WIDTH].g = 255;
				
				framebuffer[x-1 + y*WIDTH].r = 0;
				framebuffer[x-1 + y*WIDTH].b = 0;
				framebuffer[x-1 + y*WIDTH].g = 255;

				framebuffer[x + (y-1)*WIDTH].r = 0;
				framebuffer[x + (y-1)*WIDTH].b = 0;
				framebuffer[x + (y-1)*WIDTH].g = 255;
			}
		}
	}

	render("thickgreenline.ppm", framebuffer);
	
	delete[] framebuffer;

	return 0; 
}
