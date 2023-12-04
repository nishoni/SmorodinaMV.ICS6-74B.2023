/*
 * algorithm_interface.c
 *
 *  Created on: Nov 28, 2023
 *      Author: Pizza Delivery
 */
#include "algorithm_interface.h"
void do_algorithm(int algorithm_id) {
	// hashing data with chosen algorithm
//	lcd_init();
//	int8_t *chosen_algorithm = "";

	lcd_clear();
	lcd_init();
	switch (algorithm_id) {
		case 0:
//			chosen_algorithm = "You chose sha256";
			lcd_init();
			lcd_puts(0, 0, (int8_t*)"You chose sha256");
			break;
		case 1:
//			chosen_algorithm = "You chose md5";
			lcd_init();
			lcd_puts(0, 0, (int8_t*)"You chose md5");
			break;
		case 2:
//			chosen_algorithm = "You chose crc16";
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

	lcd_clear();
//	lcd_init();
	lcd_puts(0, 0, (int8_t*)"Input data");
	HAL_Delay(1000);
//	HAL_UART_Transmit(&huart1, (uint8_t*)chosen_algorithm, strlen(chosen_algorithm), 1000);

//	int8_t *input_msg = "Input data you wish to hash:\r\n";
//	HAL_UART_Transmit(&huart1, (uint8_t*)input_msg, strlen(input_msg), 1000);

//	uint8_t *data = "";
	uint8_t data[8];
//
//	HAL_UART_Receive_IT(&huart1,(uint8_t*) str,8);
//	HAL_UART_Transmit(&huart1, (uint8_t*)"hiiiiiiiii2i", strlen("hiiiiiii2ii"), 1000);

//	lcd_clear();
//	lcd_init();
	int is_reading_data = 1;
	while (is_reading_data == 1) {
		HAL_Delay(100);

		if(huart1.RxXferCount == 0)
		{
			lcd_init();
			HAL_Delay(1000);
			lcd_clear();
			data[8] = 0;
			HAL_UART_Receive_IT(&huart1, (int8_t*)data, 8);
			lcd_init();
			lcd_puts(0, 0, (int8_t*) data);
//			HAL_UART_Transmit(&huart1, (uint8_t*)"\r\n", 2, 1000);

//			HAL_UART_AbortReceive(&huart1);
//			if (data[0] == 0x5A) {
//			HAL_UART_Abort_IT(&huart1);
//			is_reading_data = 0;
//				HAL_UART_Transmit(&huart1, (uint8_t*)"\r\n", 2, 1000);
//			lcd_clear();
//			lcd_puts(0, 0, (uint8_t*)"hiii");
//				HAL_UART_Transmit(&huart1, (uint8_t*)data, strlen(data), 1000);
//				HAL_UART_AbortReceive(&huart1);
//			if (data != "") break;
			break;
//			}
		}

//		if (data != "") is_reading_data = 0;
//			HAL_UART_AbortReceive(&huart1);
	}

	lcd_clear();
//	lcd_init();
	lcd_puts(0, 0, (int8_t*)"Your input is:");

	HAL_Delay(500);

	lcd_clear();
	lcd_init();
	lcd_puts(0, 0, (int8_t*) data);

	HAL_Delay(1000);
//	uint8_t result;
	int8_t *result;
	int8_t *output;
	int j = 0, i = 0, k = 0;
//	lcd_clear();
	switch (algorithm_id) {
			case 0:
				// sha256
				lcd_clear();
				lcd_init();
				lcd_puts(0, 0, (uint8_t*)"Starting sha256");
//				result = md5_start(data);
				sha256_context foo;
				unsigned char hash[32];

				sha256_init (&foo);
				sha256_update(&foo, "abc", 3);
				sha256_finish(&foo, hash);

				HAL_Delay(1000);
				lcd_clear();
				lcd_puts(0, 0, (uint8_t*)"Result of sha256:");
				HAL_Delay(1000);

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
				md5String("Hello World", md5_result);

				HAL_Delay(1000);
				lcd_clear();
				lcd_puts(0, 0, (uint8_t*)"Result of md5:");
				HAL_Delay(1000);

				lcd_clear();
				while (k < 16) {
					sprintf(output, "%02x", md5_result[k]);
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
				lcd_puts(0, 0, (uint8_t*)"Finished md5");
				break;
			case 2:
				// crc16

				lcd_clear();
				lcd_init();
				lcd_puts(0, 0, (uint8_t*)"Starting crc16");
				result = crc16("Hello World", strlen("Hello World"));

				HAL_Delay(1000);
				lcd_clear();
				lcd_puts(0, 0, (uint8_t*)"Result of crc16:");
				HAL_Delay(1000);

//				int8_t *output;
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
//	HAL_UART_Transmit(&huart1, (uint8_t*)result, strlen(result), 1000);
}

