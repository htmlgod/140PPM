#include <fstream>
#include <iostream>
#include <string>
#include <random>

struct pixel {
	float r;
	float g;
	float b;

	pixel() : r(0), b(0), g(0) {}
};

constexpr size_t HEIGHT = 1080;
constexpr size_t WIDTH = 1920;

std::vector<std::vector<pixel>> transpose(const std::vector<std::vector<pixel>>& src);
void generateBuffer(std::vector<std::vector<pixel>>& buf);
void generateRandomBuffer(std::vector<std::vector<pixel>>& buf);
void render(const std::string& file, const std::vector<std::vector<pixel>>& buffer);

int main(int argc, char** argv) {
	if (argc == 2) {
    	std::vector<std::vector<pixel>> framebuffer;
		
		framebuffer.resize(HEIGHT);
	
		for (auto& row : framebuffer) {
			row.resize(WIDTH);
		}
		
		generateRandomBuffer(framebuffer);

		render(argv[1], framebuffer);
	}
	return 0; 
}

std::vector<std::vector<pixel>> transpose(const std::vector<std::vector<pixel>>& src) {
	std::vector<std::vector<pixel>> out;
	out.resize(WIDTH);
	for (auto& row : out) {
		row.resize(HEIGHT);
	}
	return {};
}
void generateBuffer(std::vector<std::vector<pixel>>& buf) {
	for (size_t i = 0; i < HEIGHT; i++) {
		for (size_t j = 0; j < WIDTH; j++) {
			buf[i][j].r = j/static_cast<float>(WIDTH);
			buf[i][j].b = (HEIGHT - i)/static_cast<float>(HEIGHT);
		}
			//buf[1][i].r = 255;
			//buf[2][i].g = 255;
			//buf[3][i].b = 255;
	}
}

void generateRandomBuffer(std::vector<std::vector<pixel>>& buf) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::mt19937 gen;

	for (size_t i = 0; i < HEIGHT; i++) {
		for (size_t j = 0; j < WIDTH; j++) {
			buf[i][j].r = (gen() % 256) / static_cast<float>(255);
			buf[i][j].g = (gen() % 256) / static_cast<float>(255);
			buf[i][j].b = (gen() % 256) / static_cast<float>(255);
		}
	}
}

void render(const std::string& file, const std::vector<std::vector<pixel>>& buffer) {
	std::ofstream img(file + ".ppm");
	img << "P3" << std::endl;
	img << WIDTH << " " << HEIGHT << std::endl;
	img << 255 << std::endl;

	for (size_t i = 0; i < HEIGHT; i++) {
		for (size_t j = 0; j < WIDTH; j++) {
			img << static_cast<int>(255 * buffer[i][j].r) 
				<< " " << static_cast<int>(255 * buffer[i][j].g) 
				<< " " << static_cast<int>(255 * buffer[i][j].b) << std::endl;
	    }
	}
	img.close();
}
