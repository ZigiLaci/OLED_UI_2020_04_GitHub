
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Drivers/u8g2/u8g2.h"
#include <unistd.h>
#include "navigation.h"
#include "gpio_buttons.h"
#include "print_logo_serial.h"
#include "data_struct.h"
#include "print_window.h"

//LCD Instance
static u8g2_t u8g2;

int main() {

    //VARIABLES
    int btn_pressed = 0;
    sys_data * System_Data = sys_data_init();

    // INITIALIZE
    init_gpio_btns();
    u8g2_Setup_ssd1322_nhd_256x64_f( &u8g2, U8G2_R0, u8x8_byte_XILINX_hw_spi, u8x8_gpio_and_delay_XILINX);
    u8g2_InitDisplay( &u8g2);				 // send init sequence to the display, display is in sleep mode after this,

    // PRINT STARTUP SCREEN FOR 3s
    u8g2_SetContrast(&u8g2,  255);  		 //setting up brightness, MAX==255,(255 not recommended by the datasheet)

    print_display( &u8g2, System_Data);
    sleep(3);

    //CHANGE FROM LOGO TO THE SECOND WINDOW
    System_Data->opened_window_ID = 20;
    print_display( &u8g2, System_Data);



    //POLL_BTNS() returns the ID of the pressed button, declared in GPIO_BUTTONS.C
    // NAVIGATION():  changes SYSTEM_DATA->OPENED_WINDOW-ID according to BTN ID  (1-5)




    while (1) {
        btn_pressed = poll_btns();
        if (btn_pressed > 0) {
            if (btn_pressed != 3) {
                printf("btn_pressed");
                printf("%d\n", btn_pressed);
                navigation(btn_pressed, System_Data);
                print_display( & u8g2, System_Data);
                usleep(100000);

             }

     }



    }
    //Powering off the display:
    u8g2_SetPowerSave( & u8g2, 1);
    return 0;

}
