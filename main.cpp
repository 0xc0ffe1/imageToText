#include <SFML/Graphics.hpp>
#include <fstream>
char brightness(sf::Color pixel) {
	int MaxValue = std::max({ pixel.r, pixel.g, pixel.b });
	if (MaxValue < 15)
		return '.';
	else if (MaxValue >= 15 && MaxValue < 30)
		return ':';
	else if (MaxValue >= 30 && MaxValue < 45)
		return '!';
	else if (MaxValue >= 45 && MaxValue < 60)
		return '/';
	else if (MaxValue >= 60 && MaxValue < 75)
		return 'r';
	else if (MaxValue >= 75 && MaxValue < 90)
		return '(';
	else if (MaxValue >= 90 && MaxValue < 105)
		return 'l';
	else if (MaxValue >= 90 && MaxValue < 105)
		return '1';
	else if (MaxValue >= 105 && MaxValue < 120)
		return 'Z';
	else if (MaxValue >= 120 && MaxValue < 135)
		return '4';
	else if (MaxValue >= 135 && MaxValue < 150)
		return 'H';
	else if (MaxValue >= 150 && MaxValue < 165)
		return '9';
	else if (MaxValue >= 165 && MaxValue < 180)
		return 'W';
	else if (MaxValue >= 180 && MaxValue < 195)
		return 'B';
	else if (MaxValue >= 195 && MaxValue < 210)
		return '8';
	else if (MaxValue >= 210 && MaxValue < 255)
		return '$';
	else if (MaxValue == 255)
		return '@';
}

int main(int argc, char** argv) {
	if (argc < 2) return 1;
	std::ofstream file;
	file.open("out.txt");
	sf::Image img;
	img.loadFromFile(argv[1]);
	sf::Vector2u ImgSize = img.getSize();
	for (int i = 0; i < ImgSize.y; ++i) {
		for (int j = 0; j < ImgSize.x; ++j) {
			file << ' ' << brightness(img.getPixel(j, i));
		}
		file << '\n';
	}
	file.close();
	return 0;
}