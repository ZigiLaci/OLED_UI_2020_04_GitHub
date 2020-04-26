
#include "u8g2.h"
#include <stdio.h>
	#include <fcntl.h>
	#include <unistd.h>
	#include <sys/ioctl.h>
	#include <linux/types.h>
	#include <linux/spi/spidev.h>

static const char *device = "/dev/spidev1.0";


int fd=-5;


uint8_t u8x8_byte_XILINX_hw_spi(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr) {


int mode = 0x03;
int bits = 8;
int speed = 5000000;
int ret =0;

  switch(msg) {
    case U8X8_MSG_BYTE_SEND:
    	write(fd,arg_ptr, arg_int);
    	if (fd < 0)
    			printf("can't write\n \r");

      break;

    case U8X8_MSG_BYTE_INIT:
    	printf("Initializing SPI...\n \r");
    	fd = open(device, O_RDWR);
    	if (fd < 0)
    	    			printf("can't init/open device\n \r");

    	ret=ioctl(fd, SPI_IOC_WR_MODE32, &mode); // SPI Mode
    	if (ret == -1)
    	        printf("can't set spi mode\n \r");
    	ret=ioctl(fd, SPI_IOC_WR_BITS_PER_WORD, &bits);// bits per word
    	if (ret == -1)
    	    	        printf("can't set spi bits");

    	ret=ioctl(fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed); //max write speed
    			if (ret == -1)
    			    	        printf("can't set spi speed");
    			 printf("Done\n \r");
      break;

    case U8X8_MSG_BYTE_SET_DC:
      u8x8_gpio_SetDC(u8x8, arg_int);

      break;

    case U8X8_MSG_BYTE_START_TRANSFER:

      break;

    case U8X8_MSG_BYTE_END_TRANSFER:
      break;

    default:
      return 0;
  }
  return 1;
}
