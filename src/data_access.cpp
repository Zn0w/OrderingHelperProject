#include "data_access.h"

void get_elements(int page, int current_page, std::map<int, Element[10]>* elements)
{
	std::ifstream file_reader("resources/elements.txt");
	
	std::string line;
	
	while (std::getline(file_reader, line))
	{
		Element element;

		int page_id;

		std::string info = "";
		
		int counter = 0;
		for (int i = 0; i < line.size(); i++)
		{
			if (line.at(i) == ';')
			{
				counter++;
				
				if (counter == 1)
				{
					page_id = std::stoi(info);
				}
				else if (counter == 2)
				{
					if (info == "m")
						element.type = Menu;
					else if (info == "t")
						element.type = Text;
					else if (info == "b")
						element.type = Button;
					// else, handle error
				}

				info = "";
			}

			else
				info += line.at(i);
		}
	}
}