#include <iostream>
#include <conio.h>
#include <string>
#include <math.h>
using namespace std;

class Quest
{
public:

	void quest_metody()
	{
		string first_command = "Podaj liczbe: ";

		std::cout << first_command << std::endl;

		int checked_number;

		cin >> checked_number;

		string false_warring = "FALSZ";

		string true_warring = "PRAWDA";

		int requirement = sqrt(checked_number);

		if (checked_number > 2)
		{
			for (int i = 2; i < requirement; ++i)
			{
				if (checked_number %  i == 0)
				{
					std::cout << false_warring << std::endl;
				}
				else
				{
					int second_requirement = requirement;
					second_requirement = 2 + 1;
					if (second_requirement > requirement )
					{
						std::cout << true_warring << std::endl;
					}

				}

			}
		}
		else
		{
			std::cout << false_warring << std::endl;
		}
	};

};
