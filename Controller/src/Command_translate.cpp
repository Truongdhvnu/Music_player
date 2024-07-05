#include "Command_translate.h"
#include <string>
#include <iostream>

using namespace std;

int isCommandValid(string cmd) {
    // Check start & stop byte
    if (cmd[START_BYTE] != START_BYTE_VALUE
            || cmd[STOP_BYTE] != STOP_BYTE_VALUE) {
                return MESSAGE_ERROR;
            }

    // Check sum
    uint8_t check_sum = 0;
    for(int i = CHECK_SUM_START; i <= CHECK_SUM_STOP; i++) {
        check_sum += (uint8_t)cmd[i];
    }

    if (check_sum != (uint8_t)cmd[CHECK_SUM_INDEX]) {
        // std::cout << "in Valid 2: "<< (uint8_t)cmd[CHECK_SUM_INDEX] << " " << check_sum << std::endl;
        return MESSAGE_ERROR;
    }
    
	return MESSAGE_CORRECT;
}

string translateCommand(string cmd) {
    char command[3];
    command[0] = cmd[MEASSAGE_OPTION_BYTE];
    command[1] = cmd[MEASSAGE_VALUE_BYTE];
    command[2] = '\n';

    return string(command);       
}