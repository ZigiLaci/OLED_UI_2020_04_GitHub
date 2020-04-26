#include "Drivers/u8g2/u8g2.h"

//Logo info
# define u8g_logo_width 8	//number of bytes/row
# define u8g_logo_height 64 //number of rows

int draw_logo(u8g2_t* u8g2,int xpos, int ypos){

        for (int ver =0 ; ver< 4; ver=ver+1) {
        	for (int hor= 0; hor < 4; hor = hor+1){
        		u8g2_DrawBox(u8g2,xpos+(ver*12),(ypos+3+hor*12),2, 2);
        	}
        }
    	u8g2_SetFont(u8g2, u8g2_font_unifont_tf );
    	u8g2_DrawStr(u8g2, xpos+18,ypos+61, "Relcom");





        return 0;
}
