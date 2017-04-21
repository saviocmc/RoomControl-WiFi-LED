#include <stdio.h>
#include <stdlib.h>

// Creating the struct Color, just for puting the red, green and blue value
// in the same variable. It lets a color be writen by {r, g, b}
struct Color
{
	uint8_t r, g, b;
};

// Converts a giving numerical chachacter in the hexadecimal base from 0 to 15
// and returns the correspondent value as a integer value.
static inline uint8_t hex2dec(char hex)
{
	return
	(hex>='0' && hex<='9') ? (hex-48) :
	(hex>='A' && hex<='F') ? (hex-55) :
	(hex>='a' && hex<='f') ? (hex-87) : 0;
}

Color decodeColor(const char* hex_color) {
	return {
		(uint8_t)(hex2dec(hex_color[1]) * 16 + hex2dec(hex_color[2])),
		(uint8_t)(hex2dec(hex_color[3]) * 16 + hex2dec(hex_color[4])),
		(uint8_t)(hex2dec(hex_color[5]) * 16 + hex2dec(hex_color[6]))
	};
}

int main(){
	const char* s = "#FFFFFF";
	printf("%d %d %d",decodeColor(s).r,decodeColor(s).g,decodeColor(s).b);
}
