#include <iostream>

#include <windows.h>

#include "element.h"

int current_page = 0;

// current_page = 0 is terminal's welcome screen
// current_page = 1 is terminal's initial screen
// current_page > 1 is the rest

bool running = true;

// Initial screen elements
Element init_scr_elems[3];

void close_terminal();

void display_welcomeScreen();
void display_initialScreen();

HANDLE hConsole; // For changing console text color

int main()
{
	init_scr_elems[0].type = Menu;
	init_scr_elems[0].selected = true;
	init_scr_elems[0].content = "Go user mode";

	init_scr_elems[1].type = Menu;
	init_scr_elems[1].selected = false;
	init_scr_elems[1].content = "Go edit mode";

	init_scr_elems[2].type = Text;
	init_scr_elems[2].selected = false;
	init_scr_elems[2].content = "See guide";

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	// Set console color to the light green (default)
	SetConsoleTextAttribute(hConsole, 2);
	
	while (running)
	{
		// clear the console screen
		system("cls");

		if (current_page == 0)
		{
			display_welcomeScreen();
		}
		else if (current_page == 1)
		{
			display_initialScreen();
		}

		// Pauses the execution until any key is pressed (">nul" means not to display 'Press any key to continue')
		system("pause>nul");

		// Process pressed key

		if (GetAsyncKeyState(VK_ESCAPE))
		{
			running = false;
		}
		else if (GetAsyncKeyState(VK_RETURN))
		{
			if (current_page == 0)
				current_page = 1;
		}
	}

	close_terminal();
	
	return 0;
}

void close_terminal()
{
	std::cout << "Terminal has been closed." << std::endl;
}

void display_welcomeScreen()
{
	std::cout << "Welcome to the ZOS!" << std::endl;
	std::cout << "***" << std::endl;
	std::cout << "ZOS - Znow Operating System is an alternative to the RobCo Industries' Unified Operating System (UOS)" << std::endl;
	std::cout << "***" << std::endl;
	std::cout << "ZOS is officially intended to work on a hardware supplied by RobCo Industries, namely:" << std::endl;
	std::cout << "RobCo NX-12 terminal, RobCo E-330 terminal, RobCo E-601 terminal, RobCo RX-6550 terminal, RobCo RX-9000 terminal" << std::endl;
	std::cout << "***" << std::endl;
	std::cout << "Press enter in order to proceed to the startup menu." << std::endl;
}

void display_initialScreen()
{
	for (int i = 0; i < sizeof(init_scr_elems) / sizeof(Element); i++)
	{
		if (init_scr_elems[i].selected)
		{
			SetConsoleTextAttribute(hConsole, 3);
			std::cout << init_scr_elems[i].content << std::endl;
			SetConsoleTextAttribute(hConsole, 2);
		}
		else
			std::cout << init_scr_elems[i].content << std::endl;
	}
}