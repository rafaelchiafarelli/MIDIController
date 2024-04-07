
#include "oActions.hpp"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <chrono>
#include <thread>
#include <string>

#include <iomanip>

#include <string.h>
#include <ctype.h>
#include <fcntl.h>

#include <keyNumber.hpp>
#include <textCharSets.hpp>

using namespace std;

oActions::oActions()
{
}
std::vector<std::string> oActions::words_seperate(std::string s){
    vector<string> ans;
    string w="";
    for(auto i:s){
        if(i==' '){
           ans.push_back(w);
           w="";
        }
        else{
           w+=i;
        }
    }
    ans.push_back(w);
    return ans;
}

void oActions::fillReport(namedKeyCodes key, char *report)
{
	switch(key.number)
	{
		case lAlt:
			report[0] |= 0x04;
		break;
		case rAlt:
			report[0] |= 0x40;
		break;
		case lControl:
			report[0] |= 0x01;
		break;
		case rControl:
			report[0] |= 0x10;
		break;
		case lShift:
			report[0] |= 0x02;
		break;
		case rShift:
			report[0] |= 0x20;
		break;
		default:
			report[3] = key.number; 
		break;
	}
}

/**
 * 
 */
void oActions::sendHotKey(std::vector<std::string> cmds)
{
	char report[8];
	memset(report,0,8);
	size_t to_send = 8;
	for(std::vector<std::string>::iterator str_it = cmds.begin();
	str_it != cmds.end();
	str_it++)
	{
		namedKeyCodes key = oneKeySet(str_it->c_str(),(*str_it).size());
		fillReport(key, report);
	}
	/*send hot key to keyboard*/
	//int sent = write(fd, report, to_send);
	memset(report, 0x0, sizeof(report));
	/*finish the hotkey to keyboard*/
	//sent = write(fd, report, to_send);
}
/**
 * 
 */ 
int oActions::keyboard_send(keyboardActions act)
{
	int key = 0;
	int i = 0;
    char report[8];
    memset(report,0,8);
	size_t to_send = 8;
	
	switch(act.type){

		case hotkey:
			// do stuff
			{
				//check if the hot key is spot <--spot should be in the worlds list of hotKeys
				if(act.data.compare("{spot}"))
				{
					std::vector<std::string> str_hotkey = words_seperate(act.data);
					sendHotKey(str_hotkey);
				}
				else
				{	
					keyboardActions act2;
					act2.data = std::to_string(act.spot);
					act2.type = keyType::text;
					keyboard_send(act2);
				}
			}
		break;
		case text:
		{
			//check if there is a {spot} (check with find... bad code, but works... )
			int spot_pos = act.data.find("{spot}");
			
			if(spot_pos != std::string::npos)
			{
				std::string spot = std::to_string(act.spot);
				act.data.replace(spot_pos,strlen("{spot}"),spot);
			}

			for(std::string::iterator str_it = act.data.begin();
				str_it != act.data.end();
				str_it++
				)
			{
				textCharSet cmd_to_send=textToCmdList[(unsigned int)(*str_it)];
				namedKeyCodes key;
				if(cmd_to_send.cmd)
				{
					key = oneKeySet(cmd_to_send.cmd,strlen(cmd_to_send.cmd));
					fillReport(key, report);
					//write(fd, report, to_send);
				}
				if(cmd_to_send.first)
				{
					key = oneKeySet(cmd_to_send.cmd,strlen(cmd_to_send.cmd));
					fillReport(key, report);
					key = oneKeySet(cmd_to_send.first,strlen(cmd_to_send.first));
					fillReport(key, report);
					//write(fd, report, to_send);
					memset(report, 0x0, sizeof(report));
					key = oneKeySet(cmd_to_send.cmd,strlen(cmd_to_send.cmd));
					fillReport(key, report);
					//write(fd, report, to_send);
				}
				if(cmd_to_send.second)
				{
					key = oneKeySet(cmd_to_send.cmd,strlen(cmd_to_send.cmd));
					fillReport(key, report);					
					key = oneKeySet(cmd_to_send.second,strlen(cmd_to_send.second));
					fillReport(key, report);
					//write(fd, report, to_send);
					memset(report, 0x0, sizeof(report));
					key = oneKeySet(cmd_to_send.cmd,strlen(cmd_to_send.cmd));
					fillReport(key, report);
					//write(fd, report, to_send);
				}
				if(cmd_to_send.third)
				{
					key = oneKeySet(cmd_to_send.cmd,strlen(cmd_to_send.cmd));
					fillReport(key, report);					
					key = oneKeySet(cmd_to_send.third,strlen(cmd_to_send.third));
					fillReport(key, report);
					//write(fd, report, to_send);
					memset(report, 0x0, sizeof(report));
					key = oneKeySet(cmd_to_send.cmd,strlen(cmd_to_send.cmd));
					fillReport(key, report);
					//write(fd, report, to_send);
				}
				if(cmd_to_send.fourth)
				{
					key = oneKeySet(cmd_to_send.cmd,strlen(cmd_to_send.cmd));
					fillReport(key, report);
					key = oneKeySet(cmd_to_send.fourth,strlen(cmd_to_send.fourth));
					fillReport(key, report);
					//write(fd, report, to_send);
					memset(report, 0x0, sizeof(report));
					key = oneKeySet(cmd_to_send.cmd,strlen(cmd_to_send.cmd));
					fillReport(key, report);
					//write(fd, report, to_send);					
				}
				memset(report, 0x0, sizeof(report));
				//int sent = write(fd, report, to_send);

			}
		}
		break;
		case oneKey:
			namedKeyCodes key=oneKeySet(act.data.c_str(),act.data.size());
			
			if(key.number){
				report[3] = key.number;
				to_send = 8;
				//int sent_data = write(fd, report, to_send);
				if (act.hold == not_hold) {
					memset(report, 0x0, sizeof(report));
					//int sent = write(fd, report, to_send);
				}
				if (act.hold == hold_delay) {
					if(act.delay > 0){
						std::this_thread::sleep_for(std::chrono::microseconds(act.delay));
					}
					memset(report, 0x0, sizeof(report));
					//int sent = write(fd, report, to_send);
				}
			}
		break;
	}
	return 0;
}


/*

*/
int oActions::mouse_fill_report(char report[8], char buf[BUF_LEN], bool *hold)
{

	return 3;
}


/*

*/
int oActions::joystick_fill_report(char report[8], char buf[BUF_LEN], bool *hold)
{
	
	return 4;
}



