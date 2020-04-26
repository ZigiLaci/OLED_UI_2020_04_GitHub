/*
 * data_struct.h
 *
 *  Created on: Nov 26, 2019
 *      Author: diploma
 */

#ifndef SRC_DATA_STRUCT_H_
#define SRC_DATA_STRUCT_H_



#endif /* SRC_DATA_STRUCT_H_ */


#define STRMAX 50

struct sys_data_s{

		int opened_window_ID;

		char device_name [STRMAX];
		char serial_num[STRMAX] ;

		int bargraph_DAC[5];     // DAC Bargraph data for channel 1-5, integer range 0 to 180 (min -90 dBfs to max 0 dBfs)   ;
		int bargraph_IF[5];	     // IF Bargraph data for channel 1-5, integer range 0 to 180 ( -90dBm to 0dBm )   ;
		int bargraph_RF[5];	     // RF Bargraph data for channel 1-5, integer range 0 to 180 ( -90dBm to 0dBm )   ;

		char eth_mac[4] [STRMAX];
		char eth_ipv4_addr[4] [STRMAX];


		int eth_connected[4] ;		//not connected if ==0
		int eth_up_active[4] ;		//not active if ==0
		int eth_down_active[4];		//not active if ==0
		char eth_speed[4] [STRMAX];

		int fan_speed[4];
		double zynq_temp;

};
typedef struct sys_data_s sys_data;
sys_data * sys_data_init();
