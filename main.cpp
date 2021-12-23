#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <cpr/cpr.h>
#include "stringUtils.h"
#include "emoji.h"
#include "constants.h"

bool botCommand(string message, string command){
	return stringUtils::lowercase(message) == stringUtils::lowercase(command);
}

int main() {
	srand(time(0));
	bool start = false;
	while(true) {
		if(!start) {
			time_t theTime = time(NULL);
			struct tm *aTime = localtime(&theTime);
			int currentYear = aTime->tm_year + 1900;
			cout << "Hi, I am " << botName + ", " + developer + "'s bot, to see the commands list, type:" << endl;
			cout << "!cmd" << endl;
			cout << developer + " " + emoji::copyright + " 2016-" << currentYear << stringUtils::emptyLines(2);
			start = true;
		}
		cout << "Insert your command: ";
		std::string command;
		cin >> command;
		if(botCommand(command, botName))
			cout << "Tell me my love " + emoji::heart << stringUtils::emptyLines(2);
		else if(botCommand(command, "clear")) {
			system("clear");
			cout << "Console cleaned!" << stringUtils::emptyLines(2);
		} else if(botCommand(command, "quit") || botCommand(command, "exit")) {
			string responses[] = {"At the next time", "See you soon", "Farewell"};
			cout << responses[rand() % size(responses)] << endl;
			exit(0);
		} else if(botCommand(command, "!cmd")) {
			cout << "Here bot mode available:" + stringUtils::emptyLines(2);
			cout << emoji::robot + ") €" + stringUtils::lowercase(botName) + "Bot - " + botName + " classic commands";
			cout << stringUtils::emptyLines(2);
			cout << emoji::robot + ") €teenyBot - TeenyBot mode commands" << stringUtils::emptyLines(2);
			cout << emoji::sosSignal + ") /covid - Check news about coronavirus in italy" + stringUtils::emptyLines(2);
		} else if(botCommand(command, "/covid")) {
			cpr::Response r = cpr::Get(cpr::Url{"https://api.covid19api.com/summary"});
			cout << r.text << endl;
		}
		else
			cout << "This is not my command" << stringUtils::emptyLines(2);
	}
}
