/*
 * print_window.c
 *
 *  Created on: Nov 26, 2019
 *      Author: diploma
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Drivers/u8g2/u8g2.h"
#include <unistd.h>
#include "navigation.h"
#include "gpio_buttons.h"
#include "print_logo_serial.h"
#include "data_struct.h"


//WINDOW IDS

#define start_up 		10
#define bar_graph_DAC	20
#define bar_graph_IF	21
#define bar_graph_RF	22
#define ethernet_table1	30
#define eth01_info		40
#define eth02_info		41
#define eth03_info		42
#define eth04_info		43
#define fan_info		50

//BARGRAPH SETTINGS
#define frame_h 		8
#define frame_w			180
#define frame_xpos		73
#define text_xpos		1


void print_bargraph_scale(u8g2_t *u8g2);



int print_display(u8g2_t *u8g2, sys_data* System_Data)
{
    u8g2_ClearBuffer( u8g2);
    u8g2_SetPowerSave( u8g2, 0);
    char str[40];
	 printf("filling OLED buffer\n");


		switch (System_Data->opened_window_ID){
		    case start_up:

		    	draw_logo(u8g2 ,20,0);
		    	u8g2_SetFont(u8g2, u8g2_font_profont22_tf);
		    	u8g2_DrawStr(u8g2, 125,15,&System_Data->device_name[0]);
		    	u8g2_SetFont(u8g2,  u8g2_font_profont12_tf );
		    	u8g2_DrawStr(u8g2, 125,44,"Serial No.:");
		    	u8g2_DrawStr(u8g2, 125,60,&System_Data->serial_num[0]);
			    break;

		    case bar_graph_DAC:

			 	//DRAWING dB SCALE
	     	   	 print_bargraph_scale(u8g2);

				//WRITING OUT STRINGS
		    	u8g2_SetFont(u8g2, u8g2_font_profont12_tf );
		    	u8g2_DrawStr(u8g2,text_xpos,10,"DAC levels");
				for (int i = 0; i < 5; i=i+1){
						sprintf(str, "CH %d [dBfs] ", i+1);
						u8g2_DrawStr(u8g2,text_xpos,22+i*10,  str);}


		    	//DISPLAYING BAR GRAPH VALUES
		    	for(int i=0;i<5; i=i+1){
		    	u8g2_DrawBox(u8g2, frame_xpos, 15+(i*10), System_Data->bargraph_DAC[i], frame_h);
		    	};
				break;

		     case bar_graph_IF:

		    	 	//DRAWING dB SCALE
		    	 	 print_bargraph_scale(u8g2);
					//WRITING OUT STRINGS
					u8g2_SetFont(u8g2, u8g2_font_profont12_tf );
		    		u8g2_DrawStr(u8g2, text_xpos,10,"IF levels");
					for (int i = 0; i < 5; i=i+1){
							sprintf(str, "CH %d [dBm] ", i+1);
							u8g2_DrawStr(u8g2,text_xpos,22+i*10,  str);}

					//DISPLAYING BAR GRAPH VALUES
	        		for(int i=0;i<5; i=i+1){
						u8g2_DrawBox(u8g2, frame_xpos, 15+(i*10), System_Data->bargraph_IF[i], frame_h);
						};
					break;

	     case bar_graph_RF:

	    	 	 	 //DRAWING dB SCALE
	    	  	 	 print_bargraph_scale(u8g2);

	    	  	 	 //WRITING OUT STRINGS
					u8g2_SetFont(u8g2,u8g2_font_profont12_tf );
					u8g2_DrawStr(u8g2, text_xpos,10,"RF levels");
					for (int i = 0; i < 5; i=i+1){
						sprintf(str, "CH %d [dBm] ", i+1);
						u8g2_DrawStr(u8g2,text_xpos,22+i*10,  str);}

     				//DISPLAYING BAR GRAPH VALUES
					for(int i=0;i<5; i=i+1){
						u8g2_DrawBox(u8g2, frame_xpos, 15+(i*10), System_Data->bargraph_RF[i], frame_h);
					};
					break;

		case ethernet_table1:

				// DRAWING STATIC ELEMENTS
				u8g2_SetFont(u8g2,u8g2_font_profont15_tf);

				for (int i = 0; i < 5; i=i+1){
				sprintf(str, "Eth %d", i+1);
				u8g2_DrawStr(u8g2,5+(i*64) ,16,  str);}


				for(int i=1;i<5; i=i+1){
				u8g2_DrawVLine(u8g2,i*64, 3 ,61 );
				};
				u8g2_DrawHLine(u8g2,0, 18 ,254 );


				//DISPLAYING SYSTEM DATA
				for(int i=0;i<5; i=i+1){
					//PRINT ETHERNET SPEED
									u8g2_SetFont(u8g2,u8g2_font_profont12_tf );
									u8g2_DrawStr(u8g2,5+(i*64) ,30, &System_Data->eth_speed[i][0]);

					// PRINT "CONNECTED"
					if(System_Data->eth_connected[i]!=0){
						u8g2_SetFont(u8g2,u8g2_font_profont12_tf );
						u8g2_DrawStr(u8g2,5+(i*64) ,40, "connected");}

					//PRINT "ACTIVE" UP / DOWN TRAFFIC
					if((System_Data->eth_up_active[i]!=0) ||(System_Data->eth_down_active[i]!=0)){
							u8g2_SetFont(u8g2,u8g2_font_profont12_tf);
							u8g2_DrawStr(u8g2,5+(i*64) ,50, "active");
							u8g2_SetFont(u8g2,u8g2_font_open_iconic_all_1x_t );
						}
					//PRINT ACTIVE UP SYMBOL
					if(System_Data->eth_up_active[i]!=0)
						u8g2_DrawGlyph(u8g2,5+(i*64), 63, 0x008f);
					//PRINT ACTIVE DOWN SYMBOL
					if(System_Data->eth_down_active[i]!=0)
						u8g2_DrawGlyph(u8g2,20+(i*64), 63, 0x008e);

				}

				break;


		// IP & MAC FOR ETHERNET PORT 1-4
		case  eth01_info:
		case  eth02_info:
		case  eth03_info:
		case  eth04_info:

				u8g2_SetFont(u8g2,u8g2_font_profont15_tf);
				u8g2_DrawStr(u8g2,5, 42, "MAC:");
				u8g2_DrawStr(u8g2,5, 58, "IP:");
				switch (System_Data->opened_window_ID){

				case  eth01_info:
					u8g2_DrawStr(u8g2,5, 16, "Eth 1");
					u8g2_DrawStr(u8g2,70, 42, &System_Data->eth_mac[0][0]);
					u8g2_DrawStr(u8g2,70, 58, &System_Data->eth_ipv4_addr[0][0]);
					break;

				case  eth02_info:
					u8g2_DrawStr(u8g2,5, 16, "Eth 2");
					u8g2_DrawStr(u8g2,70, 42, &System_Data->eth_mac[1][0]);
					u8g2_DrawStr(u8g2,70, 58, &System_Data->eth_ipv4_addr[1][0]);
					break;

				case  eth03_info:
					u8g2_DrawStr(u8g2,5, 16, "Eth 3");
					u8g2_DrawStr(u8g2,70, 42, &System_Data->eth_mac[2][0]);
					u8g2_DrawStr(u8g2,70, 58, &System_Data->eth_ipv4_addr[2][0]);
					break;

			case  eth04_info:
					u8g2_DrawStr(u8g2,5, 16, "Eth 4");
					u8g2_DrawStr(u8g2,70, 42, &System_Data->eth_mac[3][0]);
					u8g2_DrawStr(u8g2,70, 58, &System_Data->eth_ipv4_addr[3][0]);
					break;
			}
			break;





	   case fan_info:

				//ZYNQ TEMP.:   XY.XY °C

				sprintf(str, "Zynq Temp.:  %.2f", System_Data->zynq_temp);

				u8g2_SetFont(u8g2,u8g2_font_profont15_tf);
				u8g2_DrawStr(u8g2,5, 16, str);
                u8g2_DrawGlyph(u8g2,165, 16, 0x00b0);
                u8g2_DrawGlyph(u8g2,175, 16, 0x0043);

				// Horizontal line
				u8g2_DrawHLine(u8g2,0, 20 ,254 );

				//FAN RPM INFO 1->4
				u8g2_SetFont(u8g2, u8g2_font_profont15_tf );
				u8g2_DrawStr(u8g2, 100,32,"Fan speed");

				u8g2_SetFont(u8g2, u8g2_font_profont12_tf );
				sprintf(str, "1:   %d  RPM", System_Data->fan_speed[0]);
				u8g2_DrawStr(u8g2, 5,48, str);
				sprintf(str, "2:   %d  RPM", System_Data->fan_speed[1]);
				u8g2_DrawStr(u8g2, 5,64, str);
				sprintf(str, "3:   %d  RPM", System_Data->fan_speed[2]);
				u8g2_DrawStr(u8g2, 128+5,48, str);
				sprintf(str, "4:   %d  RPM", System_Data->fan_speed[3]);
				u8g2_DrawStr(u8g2, 128+5,64, str);


	};
	u8g2_SendBuffer( u8g2);
	return System_Data->opened_window_ID;

};



void print_bargraph_scale(u8g2_t *u8g2){

    char str_TEMP[40];


	for (int i=0; i< 5; i=i+1){
	u8g2_DrawVLine(u8g2,frame_xpos+(i*40)-1, 15-7, 55);}
	for (int i=0; i< 5; i=i+1){
	u8g2_DrawVLine(u8g2,frame_xpos+20+(i*40)-1, 15-2, 50);
	u8g2_SetFont(u8g2, u8g2_font_profont12_tf );
	}

	for (int i = 0; i < 5; i=i+1){
					sprintf(str_TEMP, "%d", i*(-20));
					if(i==0)
						u8g2_DrawStr(u8g2,frame_xpos+180-3-(i*40),10,"0");
					else
					u8g2_DrawStr(u8g2,frame_xpos+180-11-(i*40),10,  str_TEMP);}



}




