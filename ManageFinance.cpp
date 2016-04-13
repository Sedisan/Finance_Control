#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

#define AUTHOR "Szymon Ryl"
#define DATABASE "BASE.txt"
#define SUMMARYDAY "SUMMARY.txt"
using namespace std;

 class Timing
 {
public:
    virtual std::string getTime()=0;
 };
 class ConnectTime:public Timing
 {
     std::vector<class ObserwingTiming*>look;
     std::string
     firstTempString
    ,secondTemplateString
    ,thirdTemplateString
    ,fourthTemplateString
    ,finaleString;


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

 std::string ConnectTime::getTime()
 {




    time_t downloadTime;
    downloadTime=time(&downloadTime);
    std::string actualTime=ctime(&downloadTime);





    firstTempString=actualTime.substr(0,3);
    secondTemplateString=actualTime.substr(4,3);
    thirdTemplateString=actualTime.substr(8,2);
    fourthTemplateString=actualTime.substr(20,4);



    finaleString=firstTempString+"-"+secondTemplateString+"-"+thirdTemplateString+"-"+fourthTemplateString;


    ///std::cout<<finaleString<<'\n';

    return finaleString;

 }


 class ObserwingTiming
 {
     ConnectTime *connect;

     public:
     ObserwingTiming(ConnectTime *c)
     {
         connect=c;

         c->attach(this);


     }
     virtual void updating()=0;
     protected:

        ConnectTime *forwarding()
        {
            return connect;
        }


 };
 class FinaleObserwing:public ObserwingTiming
 {

   public:
       FinaleObserwing(ConnectTime *c1):ObserwingTiming(c1){}

        void updating()
        {



            std::string finaleString=forwarding()->getTime();




            std::string
            firstTempString
            ,secondTemplateString
            ,thirdTemplateString
            ,fourthTemplateString;




            firstTempString=forwarding()->testFirst();
            secondTemplateString=forwarding()->testSecond();
            thirdTemplateString=forwarding()->testThird();
            fourthTemplateString=forwarding()->testFourth();


        ///Here is all test
        ///std::cout<<firstTempString<<'\n'<<
       /// secondTemplateString<<'\n';
   /// int length=firstTempString.length();
    ///std::cout<<"Length: "<<length<<'\n';

            int thirdTest=std::atoi(thirdTemplateString.c_str());
            int fourthTest=std::atoi(fourthTemplateString.c_str());///I don't know, why this gave a false

            if(thirdTest==0 || fourthTest==0)

            {
                std::cout<<"Unrecognized time. I hope, that clock never reach 0 time"<<'\n';
                printf("%s","Exit program\n");
                exit(1);
            }
            if(firstTempString.length()>3 || secondTemplateString.length()>3)
            {
                std::cout<<"Something wrong..."<<'\n';
                exit(1);
            }






        }


 };


class Mainer
{


 public:
      virtual void saving(std::string fileName,std::string nameItem,int unitPrice,int howMany)=0;
        virtual void baseSaving(std::string fileName)=0;




};
class VirtualForTest
{
  public:
      virtual void doubleTest(double &in)=0;
      virtual int doubleToInt(const double)=0;
};
class Testing:VirtualForTest
{


  public:
      virtual void doubleTest(double &in);
        virtual int doubleToInt(const double);

};
int Testing::doubleToInt(const double changing)
{
    return static_cast<int>(changing);
}
void Testing::doubleTest(double &in)
{
    while(true)
    {

        std::cin>>in;

        if(std::cin.fail())
        {

            std::cerr<<"Unrecognized value. Try again..."<<'\n';

            std::cin.clear();
        std::cin.ignore(100,'\n');
        }
        else break;

    }


}
class ClassForSaving :public Mainer
{
    std::vector<class Obserwer *>views;
    double multiplication;
  public:
      void saving(std::string fileName,std::string nameItem,int unitPrice,int howMany)///unitPrice
      {
        std::ofstream ff;
        ff.open(fileName+".txt",std::ofstream::out|std::ofstream::app);

        ff<<nameItem<<'\n';
        ff<<unitPrice<<'\n';
        ff<<howMany<<'\n';



        ff.close();

      }
      void baseSaving(std::string date)
        {
            std::ofstream ff;
            ff.open(DATABASE,std::ofstream::out | std::ofstream::app);


            ff<<date<<'\n';

            ff.close();
        }




      void push(Obserwer *o1)
      {
          views.push_back(o1);
      }
      void notify();
      void setVar(double var)
      {
          multiplication=var;
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
      Obserwer(ClassForSaving *c1,double m)
        {
            multiplitation=m;
            model=c1;
            model->push(this);
        }
        virtual void update()=0;
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
class unexpectedBehavior:public Obserwer
{
public:
    unexpectedBehavior(ClassForSaving *s1,double var):Obserwer(s1,var){}
    virtual void update()
    {

    double multiply=forwarding()->showValue();
    double secondMultiply=checkMultiplitation();
    if(multiply==0 || secondMultiply ==0)
    {
        std::cout<<"This is no sense! Exit program! "<<'\n';
        exit(1);
    }




    }

};

class VirtualOpening
{
  public:
      virtual void opening(std::string,const bool=0)=0;
      virtual bool issetRecord(std::string,const bool)=0;
      virtual std::string issetRecord(const int number)=0;
      virtual void opening(int)=0;

};

class ClassForOpening:public VirtualOpening
{

  public:

    virtual void opening(std::string,const bool);
    virtual bool issetRecord(std::string concatenation,const bool);
    virtual std::string issetRecord(const int number);
    virtual void opening(int);

};
void ClassForOpening::opening(int howManyBack=30)
{
    std::ifstream ff;
    ff.open(SUMMARYDAY,std::ifstream::in);
    std::string whering;
    int number=1;
    int howManySpent=0;
    if(ff){
    while(std::getline(ff,whering))
    {

        number++;
    }
    ff.close();
    ff.clear();
    ff.open(SUMMARYDAY,std::ifstream::in);
    int actualNumber=1;
    while(std::getline(ff,whering))
    {
        switch(actualNumber)
        {
        default:

            {

                if(number-howManyBack<=actualNumber)howManySpent+=atoi(whering.c_str());
            }
        }
        actualNumber++;
    }

    std::cout<<"In last: "<<howManyBack<<" days, you spent: "<<howManySpent<<'\n';


    ff.close();
    }
    else std::cerr<<"Something error..."<<'\n';
}

std::string ClassForOpening::issetRecord(const int number)
{
    std::ifstream fileOpen;
    fileOpen.open(DATABASE,ifstream::in);


    if(fileOpen)
    {
        int which_Number=1;
        std::string whereGo;
        while(std::getline(fileOpen,whereGo))
        {

            switch(which_Number)
            {
            default:
                {

                if(which_Number==number)
                {
                    return whereGo;
                }

                }
            }
            which_Number++;
        }


    }
    else std::cout<<"Something error..."<<'\n';
    return "-1";
}
bool ClassForOpening::issetRecord(std::string concatenation,const bool show=false)
{
    std::ifstream fileOpen;
    fileOpen.open(DATABASE,ifstream::in);


    if(fileOpen)
    {
        int which_Number=1;
        std::string whereGo;
        while(std::getline(fileOpen,whereGo))
        {

            switch(which_Number)
            {
            default:
                {
                if(show)std::cout<<which_Number<<"."<<whereGo<<'\n';


                    if(whereGo==concatenation && !(show))
                    {

                        return true;
                        break;
                    }
                }
            }
            which_Number++;
        }


    }
    else std::cout<<"Something error..."<<'\n';
    return false;
}
void ClassForOpening::opening(std::string fileName,const bool showDate=0)
{

    std::ifstream fileOpen;
    fileOpen.open(fileName+".txt",ifstream::in);

    double howManyMoneySpent=0
    ,templateForDouble=1;
    if(fileOpen)
    {
        int
        nameIterator=1
        ,price=1
        ,muchOrMany=1;
        std::string whereGo;


        while(std::getline(fileOpen,whereGo))
        {






        if(nameIterator==1)
            {
                nameIterator-=3;

                if(!showDate)std::cout<<"Name item: "<<whereGo<<'\n';
            }
        if(price==2)
            {
                price-=3;



            templateForDouble=atoi(whereGo.c_str());




                templateForDouble/=100;

              if(!showDate) std::cout<<"Unit Price: "<<templateForDouble<<'\n';




            }
            if(muchOrMany==3)
            {
                muchOrMany-=3;
                double specialTemp;
                specialTemp=atoi(whereGo.c_str());



                specialTemp/=100;

                templateForDouble*=specialTemp;

               if(!showDate) std::cout<<"How Many: "<<specialTemp<<'\n';







            howManyMoneySpent+=templateForDouble;




            }


        nameIterator++;
        price++;
        muchOrMany++;







        }
        std::ofstream filefile;
        filefile.open(SUMMARYDAY,std::ofstream::out | std::ofstream::app);
        filefile<<howManyMoneySpent<<'\n';
      if(!showDate)  std::cout<<"In: "<<fileName<<" You spent: "<<howManyMoneySpent<<'\n';
        filefile.close();

    }
    else std::cout<<"Something error..."<<'\n';




}

void where(Mainer *m1,std::string fileName,std::string nameItem,int unitPrice,int howMany)
{
m1->saving( fileName, nameItem,unitPrice, howMany);

VirtualOpening *V_O;
ClassForOpening checkThisOut;
V_O=&checkThisOut;
if(!(V_O->issetRecord(fileName,0)))m1->baseSaving(fileName);
}

void ClassForSaving::notify()
{
    for(unsigned int i=0;i<views.size();i++)
    views[i]->update();
}
class VirtualForEnd
{
public:
    virtual void end_Program()=0;
};
class End:public VirtualForEnd
{
    public:
     void end_Program();

};
void End::end_Program()
{
    std::cout<<"Thank for use! Program has been created by: "<<AUTHOR<<'\n';
        exit(0);
}
void redict(VirtualForEnd *x)
{
    x->end_Program();
}

int main()
{
    std::cout<<"______________________________________________________________________________"<<'\n';
    ConnectTime c15;
    FinaleObserwing o(&c15);

    o.updating();


    Timing *time;
    time=&c15;
    std::string concatenation=time->getTime();



    std::cout<<"Local time was properly downloaded"<<'\n';


    Testing t1;
    double decision;
    std::cout<<"______________________________________________________________________________"<<'\n';
    std::cout<<"1.Open file\n2.Save File\n3.Exit Program"<<'\n';
    t1.doubleTest(decision);
    if(decision==1)
    {

        double userDecision;
        printf("%s","Show day, select 1.\n Show days, enter 2.\n Back? Press 3.\n");

        t1.doubleTest(userDecision);
        int property=t1.doubleToInt(userDecision);


        VirtualOpening *V_O;
        ClassForOpening oP;
        V_O=&oP;

        V_O->issetRecord(concatenation,1);

        if(property==1)
        {
            printf("%s","Which day show? \n");
            double which;
        t1.doubleTest(which);
        int convertWhicht=t1.doubleToInt(which);

            std::string fileName=V_O->issetRecord(convertWhicht);
        V_O->opening(fileName);


        //main();

        }
        if(property==2)
        {
            printf("%s","How many days? \n");
            double which;
        t1.doubleTest(which);
        int convertWhicht=t1.doubleToInt(which);
            V_O->opening(convertWhicht);
            for(int i=0;i<=convertWhicht;i++){
        std::string fileName=V_O->issetRecord(i);
        V_O->opening(fileName,1);
        }
        std::cout<<"______________________________________________________________________________"<<'\n';
        std::cout<<"\n\n\n\n\n\n\n\n\n"<<'\n';
        std::cout<<"______________________________________________________________________________"<<'\n';
        V_O->opening(convertWhicht);
       // main();
        }
        else
        {
            VirtualForEnd *V_End;

            End e1;

            V_End=&e1;
            redict(V_End);
        }
















    std::fstream( SUMMARYDAY, std::ios::trunc | std::ios::out ).flush();
    }
    if(decision!=2)
    {
        VirtualForEnd *V_End;

            End e1;

            V_End=&e1;
            redict(V_End);
    }



    std::cout<<'\n'<<'\n'<<'\n';
    std::cout<<"______________________________________________________________________________"<<'\n';
    std::string name="";
    std::cout<<"Enter, name your items: "<<'\n';
    while(name=="")std::getline(std::cin,name);
    double unitPrice;
    std::cout<<"______________________________________________________________________________"<<'\n';
   std::cout<<"Okay, now enter unit price this item: "<<'\n';

    t1.doubleTest(unitPrice);
    double howMany;
    std::cout<<"______________________________________________________________________________"<<'\n';
   std::cout<<"How many items you bought ?"<<'\n';
    t1.doubleTest(howMany);

    ClassForSaving c1;
    unexpectedBehavior o1(&c1,unitPrice);
    c1.setVar(howMany);





    int unitPriceInPennies=static_cast<int>(unitPrice*100);


   //std::cout<<"Pennies: "<<unitPriceInPennies<<'\n';
   //std::cout<<"Pennies: "<<(double)unitPriceInPennies/100<<'\n';

    int howManyInPenniesNumber=static_cast<int>(howMany*100);
    //std::cout<<"penniesNumber: "<<howManyInPenniesNumber<<'\n';
   // std::cout<<"penniesNumber: "<<(double)howManyInPenniesNumber/100<<'\n';

    Mainer *m1;
    m1=&c1;
    where(m1,concatenation,name,unitPriceInPennies,howManyInPenniesNumber);



    cout << "Hello world!" << endl;
    return 0;
}
