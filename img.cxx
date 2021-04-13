#include <fstream>
#include <iostream>
#include <random>

struct pixel {
	float r;
	float g;
	float b;
};

constexpr size_t HEIGHT = 1024;
constexpr size_t WIDTH = 1024;

void generateRandomBuffer(pixel* buf) {
	std::random_device rd;
	std::mt19937 gen(rd());

	for (size_t i = 0; i < HEIGHT* WIDTH; i++) {
		buf[i].r = gen() % 255;
		buf[i].g = gen() % 255;
		buf[i].b = gen() % 255;
	}

}

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

	generateRandomBuffer(framebuffer);
	render("marsenne_random.ppm", framebuffer);
	
	delete[] framebuffer;

	return 0; 
}
