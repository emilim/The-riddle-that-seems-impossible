// The riddle that seems impossible.cpp : Defines the entry point for the application.
//

#include "The riddle that seems impossible.h"

using namespace std;

int main()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(100));

	const int trys = 1000;
	int founds = 0;
	for (int j = 0; j < trys; j++) 
	{
		const int size = 1000;
		int boxes[size];
		int prisoners[size];
		for (int i = 0; i < size; i++)
		{
			boxes[i] = i;
			prisoners[i] = i;
		}
		//shuflle randomly the array
		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
		shuffle(boxes, boxes + size, std::default_random_engine(seed));
		shuffle(prisoners, prisoners + size, std::default_random_engine(seed));
		
		//calculate number of circle that a given permutation has
		for (int i = 0; i < size; i++)
		{
			int value = boxes[i];
			int circleLenght = 0;
			while (value != i)
			{
				value = boxes[value];
				circleLenght++;
			}
			//cout << circleLenght << endl;
		}
		
		int didntFound = 0;
		int found = 0;
		for (int i = 0; i < size; i++)
		{
			int prisoner = prisoners[i];
			int value = boxes[prisoner];
			int count = 0;
			//cout << "Prisoner " << prisoner << " open box " << prisoner << " with value " << value << endl;
			while (value != prisoner && count < static_cast<int>(size * 0.5))
			{
				//cout << "Prisoner " << prisoner << " open box " << value;
				value = boxes[value];
				//cout << " with value " << value << endl;
				count++;
			}

			if (value == prisoner)
			{
				//cout << "Found it" << endl;
				//cout << "Prisoner " << prisoner << " open box " << prisoner << " with value " << value << " after " << count << " trys\n" << endl;
				found++;
			}
			else
			{
				//cout << "Prisoner " << prisoner << " didn't find his box" << " with " << count << " trys" << endl;
				didntFound++;
			}
		}
		//cout << "Found " << found << " boxes" << endl;
		if (found == size) {
			//cout << "found all boxes" << endl;
			founds++;
		}
	}
	double percent = (founds / static_cast<double>(trys)) * 100;
	cout << "Found " << founds << " times all boxes in " << trys << " trys" << endl;
	cout << "Percent " << percent << "%" << endl;

	return 0;
}
