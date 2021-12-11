#include <iostream>
#include <cstdlib>
#include <string>
#include "stringUtils.h"
#include "emoji.h"
#include <ctime>

int main() {
	srand(time(0));
	while(true) {
		cout << "Insert your command: ";
		std::string command;
		cin >> command;
		if(stringUtils::lowercase(command) == "alessia")
			cout << "Tell me my love " << emoji::heart << endl;
		else if(stringUtils::lowercase(command) == "quit") {
			string responses[] = {"At the next time", "See you soon", "Farewell"};
			string response = responses[rand() % size(responses)];
			cout << response;
			exit(0);
		}
		else
			cout << "This is not my command";
	}
}
