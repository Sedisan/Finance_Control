#include "stdafx.h"
#include <string>
#include "Header.h"
#include <chrono>
#include <vector>
#include <ctime>
#define AUTHOR "Szymon Ryl"
#define DATABASE "BASE.txt"
#define SUMMARYDAY "SUMMARY.txt"






std::string ConnectTime::getTime()//GetTime
{

	std::chrono::system_clock::time_point today = std::chrono::system_clock::now();
	time_t downloadTime = std::chrono::system_clock::to_time_t(today);

	char str[26];
	ctime_s(str, sizeof str, &downloadTime);

	auto convertCharTableToString = [](char const tableChar[]) {

		return std::string(tableChar);

	};

	std::string actualTime = convertCharTableToString(str);


	firstTempString = actualTime.substr(0, 3);

	secondTemplateString = actualTime.substr(4, 3);

	thirdTemplateString = actualTime.substr(8, 2);

	fourthTemplateString = actualTime.substr(20, 4);


	finaleString = firstTempString + "-" + secondTemplateString + "-" + thirdTemplateString + "-" + fourthTemplateString;


	///std::cout<<finaleString<<'\n';

	return finaleString;

}






int Testing::doubleToInt(const double changing)
{
	return static_cast<int>(changing);
}

void Stream::clearStream()
{
	using Limits = std::numeric_limits<std::streamsize>;
	std::cin.ignore(Limits::max(), '\n');
}
void Testing::doubleTest(double &in)
{
	while (true)
	{

		std::cin >> in;

		if (std::cin.fail())
		{

			std::cerr << "Unrecognized value. Try again..." << '\n';

			Stream::clearStream();

		}
		else break;

	}

}

int ClassForOpening::opening(int howManyBack = 30)
{
	std::ifstream ff;
	ff.open(SUMMARYDAY, std::ifstream::in);
	std::string whering;
	int number = 1
		, howManySpent = 0;
	if (ff) {
		while (std::getline(ff, whering))
		{

			number++;
		}
		ff.close();
		ff.clear();
		ff.open(SUMMARYDAY, std::ifstream::in);
		int actualNumber = 1;
		while (std::getline(ff, whering))
		{




			if (number - howManyBack <= actualNumber)howManySpent += atoi(whering.c_str());



			actualNumber++;
		}

		//std::cout<<"In last: "<<howManyBack<<" days, you spent: "<<howManySpent<<'\n';
		return howManySpent;

		ff.close();
	}
	else
		std::cerr << "Something error..." << '\n';
	return -1;

}

std::string ClassForOpening::issetRecord(const int number)
{
	std::ifstream fileOpen;
	fileOpen.open(DATABASE, std::ifstream::in);





	if (fileOpen)
	{
		int whichNumber = 1;
		std::string whereGo;
		while (std::getline(fileOpen, whereGo))
		{



			if (whichNumber == number)
			{
				return whereGo;
			}



			whichNumber++;
		}

	}
	else
		std::cout << "Something error..." << '\n';
	return "-1";

}
bool ClassForOpening::issetRecord(std::string concatenation, const bool show = false)
{
	std::ifstream fileOpen;
	fileOpen.open(DATABASE, std::ifstream::in);
#undef DATABASE

	if (fileOpen)
	{
		int whichNumber = 1;
		std::string whereGo;
		while (std::getline(fileOpen, whereGo))
		{


			if (show)std::cout << whichNumber << "." << whereGo << '\n';


			if (whereGo == concatenation && !(show))
			{

				return true;
				break;
			}

			whichNumber++;
		}


	}
	else
		std::cout << "Something error..." << '\n';
	return false;

}
void ClassForOpening::opening(std::string fileName, const bool showDate = 0)
{

	std::ifstream fileOpen;
	fileOpen.open(fileName + ".txt", std::ifstream::in);

	double howManyMoneySpent = 0
		, templateForDouble = 1;
	if (fileOpen.is_open())
	{
		int
			nameIterator = 1
			, price = 1
			, muchOrMany = 1;
		std::string whereGo;


		while (std::getline(fileOpen, whereGo))
		{
			if (nameIterator == 1)
			{
				nameIterator -= 3;

				if (!showDate)std::cout << "Name item: " << whereGo << '\n';
			}
			if (price == 2)
			{
				price -= 3;

				templateForDouble = atoi(whereGo.c_str());


				templateForDouble /= 100;

				if (!showDate) std::cout << "Unit Price: " << templateForDouble << '\n';

			}
			if (muchOrMany == 3)
			{
				muchOrMany -= 3;
				double specialTemp;
				specialTemp = atoi(whereGo.c_str());



				specialTemp /= 100;

				templateForDouble *= specialTemp;

				if (!showDate) std::cout << "How Many: " << specialTemp << '\n';


				howManyMoneySpent += templateForDouble;

			}


			nameIterator++;
			price++;
			muchOrMany++;

		}
		fileOpen.close();
		std::ofstream filefile;
		filefile.open(SUMMARYDAY, std::ofstream::out | std::ofstream::app);
		filefile << howManyMoneySpent << '\n';
		if (!showDate)  std::cout << "In: " << fileName << " You spent: " << howManyMoneySpent << '\n';
		filefile.close();

	}
	else
	{
		std::cerr << "Something error..." << '\n';

	}

}

void Redict::where(Mainer *mObj, std::string fileName, std::string nameItem, int unitPrice, int howMany)
{
	mObj->saving(fileName, nameItem, unitPrice, howMany);

	VirtualOpening *virtForOpen;
	ClassForOpening checkThisOut;
	virtForOpen = &checkThisOut;
	if (!(virtForOpen->issetRecord(fileName, 0)))mObj->baseSaving(fileName);
}

void ClassForSaving::notify()
{
	for (unsigned int i = 0; i<views.size(); i++)
		views[i]->update();
}

int main();
void End::incorrectEndOfProgram(int statusOfError)
{

	if (std::cin.fail()) Stream::clearStream();

	printf("%s", "Uncorrect Database. Starts for beggining");
	main();

}
void End::endProgram()
{
	std::cout << "Thank for use! Program has been created by: " << AUTHOR << '\n';
	if (std::cin.fail()) Stream::clearStream();
	std::cin.get();
#undef AUTHOR
	exit(0);
}
void Redict::redirect(VirtualForEnd *whereRed)
{
	whereRed->endProgram();
}
