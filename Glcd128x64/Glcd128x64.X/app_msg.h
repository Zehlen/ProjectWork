/*
 * app_msg.h
 *
 *  Created on: Jul 31, 2024
 *      Author: 91865
 */

#ifndef INC_APP_MSG_H_
#define INC_APP_MSG_H_

typedef struct _App_Messages
{
	unsigned char MessageLen;
	unsigned char Message[20];
}App_Messages;


const unsigned char  AppMessages[20][20] = {
		{"A"},
		{"NPWT VAC THERAPY"},			//1
		{"Leak Rate:"},				    //2
		{"mmHg"},						//3
		{"Dynamic"},					//4
		{"Continuous"},				    //5
		{"Therapy"},					//6
		{"VAC Version 1.0"},			//7
		{"Start"},						//8
		{"Settings"},					//9
		{">"},							//10
		{"Stop"},						//11
		{"min"},						//12
		{"Dynamic Cycle: min"},		    //13
		{"Pressure: mmHg"},			    //14
		{"Continuous Therapy"},         //15
		{"Dynamic Therapy"},            //16
		{"Pressure: "},			        //17
		{"Dynamic Cycle: "},			//18
		{"%"}							//19
};

#endif /* INC_APP_MSG_H_ */