
//GPIO BTNS
#include "Drivers/gpiolib/gpiolib.h"

//CHANGE HERE PIN NUMBERS IF MIGRATED TO OTHER BOARD

//BTN GPIO pin numbers on PetaLinux
# define BTNU_pin 963 	//Zynq EMIO pin number 57 + chipcontroller(906)
# define BTNL_pin 964 	//Zynq EMIO pin number 58 + chipcontroller(906)
# define BTNC_pin 965 	//Zynq EMIO pin number 59 + chipcontroller(906)
# define BTNR_pin 966 	//Zynq EMIO pin number 56 + chipcontroller(906)
# define BTND_pin 962	//Zynq EMIO pin number 60 + chipcontroller(906)
# define btn_dir 0 		// 0 input, 1 output init value 0, 2 output init value 1

//Navigation options
# define nav_up 1
# define nav_left 2
# define nav_cntr 3
# define nav_right 4
# define nav_down 5



// Checking if a button is pressed
int poll_btns() {

        for (int i = 962; i <= 966; i = i + 1) {
                if (gpio_read(i)) {
                        if (i == BTNU_pin) return nav_up;
                        if (i == BTNL_pin) return nav_left;
                        if (i == BTNC_pin) return nav_cntr;
                        if (i == BTNR_pin) return nav_right;
                        if (i == BTND_pin) return nav_down;
                };

        };

        return 0;

};

int init_gpio_btns() {
        //Init GPIO Buttons
        gpio_export(BTNU_pin);
        gpio_export(BTNL_pin);
        gpio_export(BTNC_pin);
        gpio_export(BTNR_pin);
        gpio_export(BTND_pin);
        gpio_direction(BTNU_pin, btn_dir);
        gpio_direction(BTNL_pin, btn_dir);
        gpio_direction(BTNC_pin, btn_dir);
        gpio_direction(BTNR_pin, btn_dir);
        gpio_direction(BTND_pin, btn_dir);
        return 0;
};
