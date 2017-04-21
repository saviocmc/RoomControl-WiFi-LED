#include <Arduino.h>
#include <EEPROM.h>

// Definition of the PWM pins responsible to drive the LED strip
#define R_PIN 9   // The ping responsible for the Red leds
#define G_PIN 10  // The ping responsible for the Green leds
#define B_PIN 11  // The ping responsible for the Blue leds

// Sets the start index for saving the current color in the EEPROM memory to be recovery
// in case of reboot. The value should be between 0 and 1021 (not 1023),
// because it is necessary 3 bytes (3 position) for store a RGB color.
#define EEPROM_INDEX 0

// Set the PWM pins used for drive the led to OUTPUT mode
void initLED() {
	pinMode(R_PIN, OUTPUT);
	pinMode(G_PIN, OUTPUT);
	pinMode(B_PIN, OUTPUT);
}

// Creating the struct Color, just for puting the red, green and blue value
// in the same variable. It lets a color be writen by {r, g, b}
struct Color {
	uint8_t r, g, b;
};

// Converts a giving numerical chachacter in the hexadecimal base from 0 to 15
// and returns the correspondent value as a integer value.
static inline uint8_t hex2dec(char hex) {
	return
	(hex>='0' && hex<='9') ? (hex-48) :
	(hex>='A' && hex<='F') ? (hex-55) :
	(hex>='a' && hex<='f') ? (hex-87) : 0;
}

// Decodes a color writen in Hexadecimal form (e.g. "#RRGGBB") into a Color object.
Color decodeColor(char* hex_color) {
	return {
		(uint8_t)(hex2dec(hex_color[1]) * 16 + hex2dec(hex_color[2])),
		(uint8_t)(hex2dec(hex_color[3]) * 16 + hex2dec(hex_color[4])),
		(uint8_t)(hex2dec(hex_color[5]) * 16 + hex2dec(hex_color[6]))
	};
}

// Sets the RGB color received as the PWM value for the drivers pins
void updateColor(Color color) {
	analogWrite(R_PIN, color.r);
	analogWrite(G_PIN, color.g);
	analogWrite(B_PIN, color.b);
	EEPROM.put(EEPROM_INDEX, color);
}

void updateColor(char* hexColor){
	updateColor(decodeColor(hexColor));
}

void updateColor(){
	Color saved_color;
	EEPROM.get(EEPROM_INDEX, saved_color);
	updateColor(saved_color);
}

void setup() {
	initLED();
	updateColor();
}

void loop() {
}
