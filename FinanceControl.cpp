// FinanceControl.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <mutex>
#include <thread>
#include "Header.h"

#define AUTHOR "Szymon Ryl"
#define DATABASE "BASE.txt"
#define SUMMARYDAY "SUMMARY.txt"


int main()
{
	
	std::mutex mtx;
	
	
	std::cout << "______________________________________________________________________________" << '\n';
	ConnectTime cObj;
	FinaleObserwing fObj(&cObj);

	fObj.updating();


	Timing *time;
	time = &cObj;
	std::string concatenation = time->getTime();

	std::cout << "HELLO!" << '\n';

	std::cout << "Local time was properly downloaded" << '\n';

	VirtualForTest *virtForTest;
	Testing t1;
	virtForTest = &t1;
	double decision;

	///MENU
	std::cout << "______________________________________________________________________________" << '\n';
	std::cout << "1.Show saved days\n2.Create new days, or add new records\n3.Exit Program" << '\n';
	
	virtForTest->doubleTest(decision);
	if (decision == 1)
	{
		std::thread threadForConvert;
		std::thread threadForIssetRecord;
		VirtualOpening *virtForOpen;
		ClassForOpening oP;
		virtForOpen = &oP;
		if (!std::cin)std::cin.ignore();
		double userDecision;
		printf("%s", "Show day, select 1.\n Show days, enter 2.\n Back? Press 3.\n");
		mtx.lock();
		threadForConvert=std::thread(virtForTest->doubleTest,userDecision);
		threadForIssetRecord = std::thread(virtForOpen->issetRecord,concatenation, 1);
		threadForConvert.join();
		threadForIssetRecord.join();
		int property = virtForTest->doubleToInt(userDecision);
		mtx.unlock();
		if (property == 3)main();

		

		

		if (property == 1)
		{
			printf("%s", "Which day show? \n");

			


			double which;
			virtForTest->doubleTest(which);
			int convertWhicht = virtForTest->doubleToInt(which);
			
			std::cin.get();
			std::string fileName = virtForOpen->issetRecord(convertWhicht);

			virtForOpen->opening(fileName);


			//main();

		}
		if (property == 2)
		{
			
			printf("%s", "How many days? \n");
			double which;
			virtForTest->doubleTest(which);

			int convertWhicht = virtForTest->doubleToInt(which);
			
			virtForOpen->opening(convertWhicht);

			if (std::cin.fail()) Stream::clearStream();

			


			for (int i = 0; i < convertWhicht; i++) {
				std::string fileName;
				(	typeid(virtForOpen->issetRecord(i)).name()==typeid(std::string).name()	) ? fileName= virtForOpen->issetRecord(i): exit(-1);

				

				if (fileName != "-1")virtForOpen->opening(fileName, 1);
			}

			std::cin.get();


			int howMany = virtForOpen->opening(convertWhicht);


			std::cout << "In this range, you spent: " << howMany << '\n';

			// main();
		}
		else
		{
			VirtualForEnd *virtForEnd;

			End endObj;

			virtForEnd = &endObj;
			Redict::redirect(virtForEnd);
		}



		std::fstream(SUMMARYDAY, std::ios::trunc | std::ios::out).flush();
	}
	if (decision != 2)
	{
		VirtualForEnd *virtForEnd;

		End endObj;

		virtForEnd = &endObj;
		Redict::redirect(virtForEnd);
	}


	
	std::cout << '\n' << '\n' << '\n';
	std::cout << "______________________________________________________________________________" << '\n';
	std::string name = "";
	std::cin.ignore();
	std::cout << "Enter, name your items: " << '\n';
	while (name == "")std::getline(std::cin, name);
	double unitPrice;
	std::cout << "______________________________________________________________________________" << '\n';
	std::cout << "Okay, now enter unit price this item: " << '\n';

	virtForTest->doubleTest(unitPrice);
	double howMany;
	std::cout << "______________________________________________________________________________" << '\n';
	std::cout << "How many items you bought ?" << '\n';
	///END OF MENU
	virtForTest->doubleTest(howMany);

	ClassForSaving objClassSaving;
	unexpectedBehavior o1(&objClassSaving, unitPrice);
	objClassSaving.setVar(howMany);
	
	int unitPriceInPennies = static_cast<int>(unitPrice * 100);


	int howManyInPenniesNumber = static_cast<int>(howMany * 100);


	Mainer *mObj;
	mObj = &objClassSaving;
	Redict::where(mObj, concatenation, name, unitPriceInPennies, howManyInPenniesNumber);



	return 0;
}
