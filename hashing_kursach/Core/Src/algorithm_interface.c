/*
 * algorithm_interface.c
 *
 *  Created on: Nov 28, 2023
 *      Author: Pizza Delivery
 */
#include "algorithm_interface.h"

void do_algorithm(int8_t* data, int algorithm_id) {
	// hashing data with chosen algorithm
	state = 2;
	lcd_clear();
	lcd_init();
	switch (algorithm_id) {
		case 0:
			lcd_init();
			lcd_puts(0, 0, (int8_t*)"You chose sha256");
			break;
		case 1:
			lcd_init();
			lcd_puts(0, 0, (int8_t*)"You chose md5");
			break;
		case 2:
			lcd_init();
			lcd_puts(0, 0, (int8_t*)"You chose crc16");
			break;
		default:
			lcd_init();
			int8_t *error_msg = "Unexpected algorithm chosen";
			lcd_puts(0, 0, (int8_t*) error_msg);
			HAL_Delay(1000);
			break;
	}

	HAL_Delay(1000);
	int8_t *result;
	char *output;
	int j = 0, i = 0, k = 0;
	lcd_init();
	switch (algorithm_id) {
			case 0:
				// sha256

				lcd_clear();
				lcd_init();
				lcd_puts(0, 0, (uint8_t*)"Starting sha256");
				sha256_context foo;
				unsigned char hash[32];

				sha256_init(&foo);
				sha256_update(&foo, data, strlen(data));
				sha256_finish(&foo, hash);

				HAL_Delay(1000);
				lcd_clear();
				lcd_puts(0, 0, (uint8_t*)"Result of sha256:");
				HAL_Delay(500);

				lcd_clear();
				while (k < 16) {
					sprintf(output, "%02x", hash[k]);
					if (i == 16) {
						i = 0;
						j = 1;
					}
					lcd_puts(j, i, (uint8_t*)output);
					++k;
					i += 2;
				}

				HAL_Delay(1000);
				lcd_clear();
				lcd_puts(0, 0, (uint8_t*)"Finished sha256");
				HAL_Delay(1000);
				break;
			case 1:
				// md5
				lcd_clear();
				lcd_init();
				lcd_puts(0, 0, (uint8_t*)"Starting md5");
				uint8_t md5_result[16];
				md5String(data, md5_result);

				HAL_Delay(1000);
				lcd_clear();
				lcd_puts(0, 0, (uint8_t*)"Result of md5:");
				HAL_Delay(500);

				lcd_clear();

				while (k < 16) {
					sprintf((char*)output, "%02x", md5_result[k]);
					if (i == 8) {
						i = 0;
						j = 1;
					}


					lcd_puts(j, i, (uint8_t*)output);
					k++;
					i += 2;
				}

				HAL_Delay(1000);
				lcd_clear();
				lcd_puts(0, 0, (uint8_t*)"Finished md5");
				break;
			case 2:
				// crc16

				lcd_clear();
				lcd_init();
				lcd_puts(0, 0, (uint8_t*)"Starting crc16");
				result = crc16(data, strlen(data));

				HAL_Delay(1000);
				lcd_clear();
				lcd_puts(0, 0, (uint8_t*)"Result of crc16:");
				HAL_Delay(500);

				sprintf(output, "%hX", result);
				HAL_Delay(1000);
				lcd_clear();
				lcd_puts(0, 0, output);

				HAL_Delay(1000);
				lcd_clear();
				lcd_puts(0, 0, (uint8_t*)"Finished crc16");
				break;
			default:
				lcd_init();
				int8_t *error_msg = "Unexpected error in algorithms\r\n";
				lcd_puts(0, 0, (int8_t*) error_msg);
				HAL_Delay(1000);
				break;
		}
	HAL_Delay(1000);
	state = 0;
	lcd_clear();
}

