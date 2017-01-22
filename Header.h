#pragma once
#include "stdafx.h"
#include <string>
#include "Header.h"
#include <vector>
#include <iostream>
#include <fstream>
#define DATABASE "BASE.txt"
class Timing
{
public:
	virtual std::string getTime() = 0;
};
class ConnectTime :public Timing
{
	std::vector<class ObserwingTiming*>look;
	std::string
		firstTempString
		, secondTemplateString
		, thirdTemplateString
		, fourthTemplateString
		, finaleString;


public:

	std::string testFirst()
	{
		return firstTempString;
	}
	std::string testSecond()
	{
		return secondTemplateString;
	}
	std::string testThird()
	{
		return thirdTemplateString;
	}
	std::string testFourth()
	{
		return fourthTemplateString;
	}

	virtual std::string getTime();
	void attach(ObserwingTiming *obj)
	{
		look.push_back(obj);
	}



};
class ObserwingTiming
{	//Obserwating Template 
	ConnectTime *connect;

public:
	ObserwingTiming(ConnectTime *c)
	{
		connect = c;

		c->attach(this);


	}
	virtual void updating() = 0;
protected:

	ConnectTime *forwarding()
	{
		return connect;
	}


};
class FinaleObserwing :public ObserwingTiming
{

public:
	FinaleObserwing(ConnectTime *c1) :ObserwingTiming(c1) {}

	void updating()
	{


		std::string finaleString = forwarding()->getTime();




		std::string
			firstTempString
			, secondTemplateString
			, thirdTemplateString
			, fourthTemplateString;


		firstTempString = forwarding()->testFirst();
		secondTemplateString = forwarding()->testSecond();
		thirdTemplateString = forwarding()->testThird();
		fourthTemplateString = forwarding()->testFourth();


		///Here is all test
		///std::cout<<firstTempString<<'\n'<<
		///secondTemplateString<<'\n';
		///int length=firstTempString.length();
		///std::cout<<"Length: "<<length<<'\n';

		///std::cin.get();


		int thirdTest = std::atoi(thirdTemplateString.c_str());
		int fourthTest = std::atoi(fourthTemplateString.c_str());///I don't know, why this gave a false

		if (thirdTest == 0 || fourthTest == 0)

		{
			std::cout << "Unrecognized time" << '\n';
			printf("%s", "Exit program\n");
			exit(1);
		}
		if (firstTempString.length()>3 || secondTemplateString.length()>3)
		{
			std::cout << "Something wrong..." << '\n';
			exit(1);
		}

	}


};
class Mainer
{


public:
	virtual void saving(std::string fileName, std::string nameItem, int unitPrice, int howMany) = 0;
	virtual void baseSaving(std::string fileName) = 0;




};
class VirtualForTest
{
public:
	virtual void doubleTest(double &in) = 0;
	virtual int doubleToInt(const double) = 0;
};
class Testing : public VirtualForTest
{


public:
	virtual void doubleTest(double &in);
	virtual int doubleToInt(const double);

};
class ClassForSaving :public Mainer
{
	std::vector<class Obserwer *>views;
	double multiplication;
public:
	void saving(std::string fileName, std::string nameItem, int unitPrice, int howMany)///unitPrice
	{
		std::ofstream ff;
		ff.open(fileName + ".txt", std::ofstream::out | std::ofstream::app);

		ff << nameItem << '\n';
		ff << unitPrice << '\n';
		ff << howMany << '\n';

		ff.close();

	}
	void baseSaving(std::string date)
	{
		std::ofstream ff;
		ff.open(DATABASE, std::ofstream::out | std::ofstream::app);


		ff << date << '\n';

		ff.close();
	}


	void push(Obserwer *o1)
	{
		views.push_back(o1);
	}
	void notify();
	void setVar(double var)
	{
		multiplication = var;
		notify();
	}
	double showValue()
	{
		return multiplication;
	}


};

class Obserwer
{
	ClassForSaving *model;
	double multiplitation;
public:
	Obserwer(ClassForSaving *objClassSaving, double m) :multiplitation(m), model(objClassSaving)
	{
		model->push(this);
	}
	virtual void update() = 0;
protected:
	ClassForSaving * forwarding()
	{
		return model;
	}
	double checkMultiplitation()
	{
		return multiplitation;
	}

};
class unexpectedBehavior :public Obserwer
{
public:
	unexpectedBehavior(ClassForSaving *s1, double var) :Obserwer(s1, var) {}
	virtual void update()
	{

		double multiply = forwarding()->showValue();
		double secondMultiply = checkMultiplitation();
		if (multiply == 0 || secondMultiply == 0)
		{
			std::cout << "This is no sense! Exit program! " << '\n';
			exit(1);
		}

	}

};

class VirtualOpening
{
public:
	virtual void opening(std::string, const bool = 0) = 0;
	virtual bool issetRecord(std::string, const bool) = 0;
	virtual std::string issetRecord(const int number) = 0;
	virtual int opening(int) = 0;

};

class ClassForOpening :public VirtualOpening
{

public:

	virtual void opening(std::string, const bool);
	virtual bool issetRecord(std::string concatenation, const bool);
	virtual std::string issetRecord(const int number);
	virtual int opening(int);

};
class VirtualForEnd
{
public:
	virtual void endProgram() = 0;
	virtual void incorrectEndOfProgram(int statusOfError) = 0;
};
class End :public VirtualForEnd
{
public:
	void endProgram();
	void incorrectEndOfProgram(int statusOfError);

};
class Stream
{
public:
	static void clearStream();
};
class Redict
{
public:
	static void redirect(VirtualForEnd *whereRed);
	static void where(Mainer *mObj, std::string fileName, std::string nameItem, int unitPrice, int howMany);

};