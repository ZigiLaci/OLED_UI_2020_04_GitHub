/*
 * u8x8_gpio_and_delay_XILINX.c
 *
 *  Created on: 2019. okt. 8.
 *      Author: Laci
 */

#include <stdio.h>

#include "u8g2.h"
#include "../gpiolib/gpiolib.h"
#include <unistd.h>


#define DELAY 1

# define RST_pin 960 	//display reset pin, Zynq    emio gpio 54 pin + chipcontroller 906
# define DC_pin 961		 //display reset pin, Zynq    emio gpio 55 pin  + chipcontroller 906
# define dir  1 		// 0 input, 1 output init value 0, 2 output init value 1

uint8_t u8x8_gpio_and_delay_XILINX (u8x8_t * u8x8, uint8_t msg, uint8_t arg_int, void * arg_ptr) {
        switch (msg) {


        case U8X8_MSG_GPIO_AND_DELAY_INIT: // called once during init phase of u8g2/u8x8

                printf("GPIO Setup Running....\n\r ");

                	gpio_export(RST_pin);
                	gpio_export(DC_pin);
                	gpio_direction(RST_pin, dir);
                	gpio_direction(DC_pin, dir);

                printf("DONE! Pin DC and RST is ready\n\r ");
                break;


        case U8X8_MSG_DELAY_MILLI: // delay arg_int ms

        	usleep(arg_int*1000);



        	break;

        case U8X8_MSG_GPIO_DC: // DC (data/cmd, A0, register select) pin: Output level in arg_int

        	gpio_write(DC_pin, arg_int);


                break;

        case U8X8_MSG_GPIO_RESET: // Reset pin: Output level in arg_int
        	printf("setting RESET == %d, on GPIO!\n",arg_int );

        	gpio_write(RST_pin, arg_int);

                break;

        default:
                u8x8_SetGPIOResult(u8x8, 1); // default return value
                break;
        }
        return 1;
}
