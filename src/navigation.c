/*
 * In the sys_data structure, the integer System_Data->opened_window_ID is the
 * currently displayed window's ID, which is changed according to the return value of the
 * navigation().
 *
 * 			[10] startup
 * 			    	V
 * 			[20] bargraph_DAC <-> [21] bargraph_IF <-> [22] bar_graph_RF
 *	 				V		V		    V
 * 			[30] ethernet_table1
 * 					V
 * 			[40] eth01_info	<->	  [41] eth02_info.....
 * 					V		    V	
 * 			[50] fan_info
 */


#include "data_struct.h"
#include <stdio.h>

//Navigation options
# define nav_up 1
# define nav_left 2
# define nav_cntr 3
# define nav_right 4
# define nav_down 5



void navigation (int nav, sys_data* System_Data) {
	int window =System_Data->opened_window_ID;
	int ret=10;

	switch (nav){

	    case nav_up:
	    		if(window==10){
	    			ret= 10;}

	    		else{
	    			ret=((window/10)*10)-10;

	    		};
	      break;



	    case nav_down:
	    		if(((window)/10)*10==50){
	    			ret= window;

	    		}
	    		else{

	    		   	ret=((window/10)*10)+10;
	    		}
	    		break;



	    case nav_left:
	    	if ((window/10)==2){
	    		if(window==20)
	    			ret= window;
	    		else
	    			ret= (window-1);
	    	}
	    	else if ((window/10)==4){
	    		if(window==40)
	    			ret= window;
    			else
    				ret= (window-1);
	    	}
	    	else	ret= window;
	    	break;



	    case nav_right:

	    	if ((window/10)==2)
	    	{
	    		if(window==22)
	    		{
	    			ret= window;
	    		}
	    		else{
	    			ret=(window+1);
	    		};
	    	}
	    	else if ((window/10)==4)
	    	{
	    		if(window==43)
	    		{
	    			ret= window;
	    		}
	    		else{
	    			ret=(window+1);
	    		};
	    	}else

	    		ret=window;
	    	break;

// Out of use for now, return to startup screen
	    case nav_cntr:

	    	break;



	    default:
	    	break;
	};

	System_Data->opened_window_ID=ret;
};
