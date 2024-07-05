#ifndef COMMAN_TRANSLATE_H
#define COMMAN_TRANSLATE_H

#define START_BYTE 			    0
#define START_BYTE_VALUE 	    '0'

#define STOP_BYTE 			    4
#define STOP_BYTE_VALUE 	    '0'

#define CHECK_SUM_START 	    1
#define CHECK_SUM_STOP 		    2
#define CHECK_SUM_INDEX 	    3

#define MEASSAGE_OPTION_BYTE    1
#define MEASSAGE_VALUE_BYTE     2

#define MESSAGE_CORRECT 	    0
#define MESSAGE_ERROR 		    1
#define MESSAGE_NO_AVALABLE	    2

#define VOLTAGE_OPTION          'v'
#define OPTION_UP               'r'
#define OPTION_CONFIRM          'z' 
#define NEXT_OPTION             'r'

#define DECODED_OPTION_BYTE     0
#define DECODED_VALUE_BYTE      1
      
#include <string>

using namespace std;

int isCommandValid(string cmd);
string translateCommand(string cmd);

#endif