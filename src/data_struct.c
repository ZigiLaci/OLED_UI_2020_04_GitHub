#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "data_struct.h"
//SYSTEM DATA





//sys_data_init(): allocates memory for the data structure, fills up structure with random values for testing.


sys_data* sys_data_init(){

			sys_data *ret = calloc(1, sizeof *ret);

			strncpy(ret->device_name, "WBDF-AD01", STRMAX);
			strncpy(ret->serial_num , "xyz1-xyz2-xyz3-xyz4",STRMAX);

			for(int i=0;i<4; i=i+1){
			strncpy(&ret->eth_ipv4_addr[i][0], "123.123.123.123",STRMAX);
			strncpy(&ret->eth_mac[i][0], "EE-7E-F5-E4-04-C0",STRMAX);
			}

			ret->opened_window_ID=10;



			//bar_graph_DAC

			ret->bargraph_DAC[0]= 178;
			ret->bargraph_DAC[1]= 110;
			ret->bargraph_DAC[2]= 50;
			ret->bargraph_DAC[3]= 125;
			ret->bargraph_DAC[4]= 39;

			//bar_graph_IF
			ret->bargraph_IF[0]= 136;
			ret->bargraph_IF[1]= 11;
			ret->bargraph_IF[2]= 171;
			ret->bargraph_IF[3]= 19;
			ret->bargraph_IF[4]= 65;

			//bar_graph_IF
			ret->bargraph_RF[0]= 12;
			ret->bargraph_RF[1]= 11;
			ret->bargraph_RF[2]= 122;
			ret->bargraph_RF[3]= 60;
			ret->bargraph_RF[4]= 75;



			// ethernet_table1
		for(int i=0;i<5; i=i+1){
			ret->eth_up_active[i] = 1;
			ret->eth_down_active[i] = 1;
			ret->eth_connected[i]=1;
		}

		   strncpy(&ret->eth_speed[0][0], "10 Gbps",STRMAX);
		   strncpy(&ret->eth_speed[1][0], "10 Gbps",STRMAX);
		   strncpy(&ret->eth_speed[2][0], "1 Gbps",STRMAX);
		   strncpy(&ret->eth_speed[3][0], "1 Gbps",STRMAX);





			// fan_info
			ret->fan_speed[0]=1450;
			ret->fan_speed[1]=4581;
			ret->fan_speed[2]=521;
			ret->fan_speed[3]=5102;
			ret->zynq_temp = 162.112;

			return ret;
}

