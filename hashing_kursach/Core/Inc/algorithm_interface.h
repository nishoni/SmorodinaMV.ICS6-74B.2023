/*
 * algorithm_interface.h
 *
 *  Created on: Nov 28, 2023
 *      Author: Pizza Delivery
 */

#ifndef INC_ALGORITHM_INTERFACE_H_
#define INC_ALGORITHM_INTERFACE_H_

#include "stm32f1xx_hal.h"
#include <string.h>
#include "lcd_txt.h"

// Алгоритмы
#include "md5.h"
#include "crc16.h"
#include "sha256.h"

extern UART_HandleTypeDef huart2;
extern unsigned char *data;
extern int state;

void do_algorithm(int8_t* data, int algorithm_id);

#endif /* INC_ALGORITHM_INTERFACE_H_ */
