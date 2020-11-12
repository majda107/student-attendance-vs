#include <iostream>
#include "handlers/ui_handler.h";


int main() {

	setlocale(LC_ALL, "");

	UIHandler ui;
	ui.student_handler->load("save.txt");

	while (!ui.should_exit()) {
		//        ui.render();
		//        ui.handle_keys();
		ui.process();
	}


	ui.student_handler->save("save.txt");

	std::cout << "Exiting app..." << std::endl;

	return 0;
}
