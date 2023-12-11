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
	HAL_UART_Transmit_IT(&huart2, (int8_t*)"\r\n\r\nYour data:\r\n", 15);
	HAL_Delay(100);
	HAL_UART_Transmit_IT(&huart2, (int8_t*)data, strlen(data));
	HAL_UART_Transmit_IT(&huart2, (int8_t*)"\r\n", 2);
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
				HAL_UART_Transmit_IT(&huart2, (int8_t*)"\r\nResult of sha256:\r\n", 24);
				HAL_Delay(500);

				lcd_clear();
				while (k < 32) {
					if (k == 16) {
						HAL_Delay(2000);
						lcd_clear();
						i = 0;
						j = 0;
						HAL_UART_Transmit_IT(&huart2, (int8_t*)"\r\n", 2);
					}
					sprintf(output, "%02x", hash[k]);
					if (i == 16) {
						i = 0;
						j = 1;
					}
					lcd_puts(j, i, (uint8_t*)output);
					HAL_UART_Transmit_IT(&huart2, (int8_t*)output, 2);
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
				HAL_UART_Transmit_IT(&huart2, (int8_t*)"\r\nResult of md5:\r\n", 20);
				HAL_Delay(500);

				lcd_clear();

				while (k < 16) {
					sprintf((char*)output, "%02x", md5_result[k]);
					if (i == 16) {
						i = 0;
						j = 1;
					}

					lcd_puts(j, i, (uint8_t*)output);
					HAL_UART_Transmit_IT(&huart2, (int8_t*)output, 2);
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
				HAL_UART_Transmit_IT(&huart2, (int8_t*)"\r\nResult of crc16:\r\n", 23);
				HAL_Delay(500);

				sprintf(output, "%hX", result);
				HAL_Delay(1000);
				lcd_clear();
				lcd_puts(0, 0, output);
				HAL_UART_Transmit_IT(&huart2, (int8_t*)output, 4);

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
	HAL_UART_Transmit_IT(&huart2, (int8_t*)"\r\n\r\n", 4);
	HAL_Delay(1000);
	state = 0;
	lcd_clear();
}

