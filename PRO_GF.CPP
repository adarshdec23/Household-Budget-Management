/*====================================================/*
      C++: HOUSEHOLD BUDGET
      By: A Adarsh
 ******************************************************
      Feedbacks are always welcome.
 ******************************************************
      Thank you! :D
/*====================================================*/

#include<fstream.h>
#include<conio.h>
#include<process.h>
#include<stdio.h>
#include<graphics.h>
#include<dos.h>

//***********GLOBAL CLASS*********

  class budget
{
  int max1,max2;
  float electric,tele,water,gas;
  float food,other,paper,gadget,avail;

   public:

  int month,year;
  float total_bill,total,savings;
  void modify();
  void analyse();
  float getspen()
  {
    return total;
  }
  float getsav()
  {
    return savings;
  }
  int getmonth()
  {
    return month;
  }
  int getyear()
  {
     return year;
  }
  //************Data enrty************
  void getdata()
{
  gotoxy(17,11);
  cout<<"Enter the details ";gotoxy(17,12);
  cout<<"Enter the month number(Jan=1,Feb=2....Dec=12) ";
  cin>>month;gotoxy(17,13);
  cout<<"Enter the year(Eg:10 for 2010) ";
  cin>>year;gotoxy(17,14);
  cout<<"Enter the monthly income ";
  cin>>avail;gotoxy(17,15);
  cout<<"Enter the electricity bill ";
  cin>>electric;gotoxy(17,16);
  cout<<"Enter the telephone bill ";
  cin>>tele;  gotoxy(17,17);
  cout<<"Enter the water bill ";
  cin>>water;gotoxy(17,18);
  cout<<"Enter the gas bill ";
  cin>>gas;gotoxy(17,19);
  cout<<"Enter the amount spent on gadgets ";
  cin>>gadget;gotoxy(17,20);
  cout<<"Enter the amount spent on paper ";
  cin>>paper;gotoxy(17,21);
  cout<<"Enter the amount spent on food items ";
  cin>>food;gotoxy(17,22);
  cout<<"Enter the amount spent on any other items ";
  cin>>other;
  calculate();

 }
//************Printing a record*******************
  void putdata()
{
  gotoxy(13,5);
  cout<<"Month/Year: "<<month<<"/"<<year;gotoxy(10,7);
  cout<<"The income of the month is :"<<avail; gotoxy(10,9);
  cout<<"Bills:"; gotoxy(10,10);
  cout<<"Current bill :"<<electric; gotoxy(10,11);
  cout<<"Telephone bill :"<<tele; gotoxy(10,12);
  cout<<"Water bill :"<<water; gotoxy(10,13);
  cout<<"Gas bill :"<<gas; gotoxy(14,14);
  cout<<"Total cost of bill :"<<total_bill; gotoxy(10,16);
  cout<<"Food :"<<food; gotoxy(10,17);
  cout<<"Paper :"<<paper; gotoxy(10,18);
  cout<<"Gadgets :"<<gadget; gotoxy(10,19);
  cout<<"Others :"<<other; gotoxy(14,20);
  cout<<"Total expenditure :"<<total; gotoxy(14,21);
  cout<<"Total savings :"<<savings;

}



   void calculate()  //Function to calculate the savings
  {


    total_bill=electric+tele+water+gas;
    total=total_bill+food+other+paper+gadget;
    savings=avail-total;

  }
};
/**********************************************************/
/*********************END OF CLASS*************************/



void budget::analyse()
 {
     max1=1;
     max2=electric;
     if(tele>max2)
    {
      max2=tele;
      max1=2;
    }

      if(water>max2)
    {
      max2=water;
      max1=3;
    }
     if(gas>max2)
    {
      max2=gas;
      max1=4;
    }
     if(food>max2)
    {
      max2=food;
      max1=5;
    }
     if(paper>max2)
    {
      max2=paper;
      max1=6;
    }
     if(gadget>max2)
    {
      max2=gadget;
      max1=7;
    }

     if(other>max2)
    {  max1=8;
       max2=other;
    }
    putdata();
    cout<<"\n\nThe maximum expenditure of the month is for";
    switch (max1)
  {
    case 1:cout<<" electricity.Make sure that you switch"
	       <<" the lights off to save on power. ";
	   break;
    case 2:cout<<" telephone.Dont talk for too long on the phone. ";
	   break;
    case 3:cout<<" water. Turn off the taps while brushing and"
	       <<" fix all the leaky taps. ";
	   break;
    case 5:cout<<" food.Cut on the extra junk food.";
	   break;
    case 4:cout<<" gas.Turn off the gas as soon as you finish cooking!";
	   break;
    case 6:cout<<" paper.Avoid buying the papers you dont read.";
	   break;
    case 7:cout<<" gadgets.No new gadget for you! ";
	   break;
    case 8:cout<<" miscellaneous items.Be careful next time!";
    }
    if(savings==0)
   cout<<"\nYour savings for the month is zero.Please be very careful from here on ";
  else if(savings<0)
  cout<<"\nYou have run into debt.Be penney-wise the next time!";

 }
/*************************************************/

  void budget::modify() //Function to modify and exitsting record
{


 float ele,tel,gass,wat,fod,gad,pap,oth,av;
 gotoxy(10,5);
 cout<<"Enter the new monthly income(for old one enter '-1') ";
 cin>>av; gotoxy(10,6);
 cout<<"Enter the new electric bill(for old one enter '-1') ";
 cin>>ele; gotoxy(10,7);
 cout<<"Enter the new telephone billfor old one enter '-1') ";
 cin>>tel; gotoxy(10,8);
 cout<<"Enter the new water bill(for old one enter'-1') ";
 cin>>wat; gotoxy(10,9);
 cout<<"Enter the new food bill(for old one enter '-1') ";
 cin>>fod; gotoxy(10,10);
 cout<<"Enter the new gas bill(for old one enter '-1') ";
 cin>>gass; gotoxy(10,11);
 cout<<"Enter the new paper bill(for old one enter'-1') ";
 cin>>pap; gotoxy(10,12);
 cout<<"Enter the new gadget bill(for old one enter'-1') ";
 cin>>gad; gotoxy(10,13);
 cout<<"Enter the new other costs(for old one enter'-1') ";
 cin>>oth;

  if(ele!=-1)
     electric=ele;
  if(tel!=-1)
     tele=tel;
  if(wat!=-1)
    water=wat;
  if(fod!=-1)
     food=fod;
  if(gass!=-1)
     gas=gass;
  if(pap!=-1)
     paper=pap;
  if(gad!=-1)
     gadget=gad;
  if(oth!=-1)
    other=oth;
  if(av!=-1)
     avail=av;
   calculate();

}
/******************************************
*************GRAPHIC FUNCTIONS*************
******************************************/

void init()
 {   int driver,mode;
     driver=DETECT;
     initgraph(&driver,&mode,"\\tc\\bgi");
  }

void border()
{
 setcolor(WHITE);
 setlinestyle(SOLID_LINE,0,THICK_WIDTH);
 rectangle(0,0,getmaxx(),getmaxy());
 rectangle(5,5,getmaxx()-5,getmaxy()-5);
}


void cover()
{
     border();
     setcolor(WHITE);
     settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
     rectangle(165,199,485,244);
     rectangle(220,420,420,440);
     outtextxy(170,200,"HOUSEHOLD Budget");
     settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
     outtextxy(240,418,"A DBMS program");
     getch();
     cleardevice();

 }
void load()
{

  setcolor(WHITE);
  settextstyle(SANS_SERIF_FONT,HORIZ_DIR,4);
  outtextxy(260,250,"LOADING ");
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
  setlinestyle(SOLID_LINE,0,NORM_WIDTH);
  rectangle(255,250,383,289);
  setcolor(WHITE);
  settextstyle(SANS_SERIF_FONT,HORIZ_DIR,4);
  rectangle(240,355,396,380);
  for(int i=242;i<395;i+=22)
 {
    rectangle(i,357,i+20,378);
    floodfill(i+2,359,WHITE);
    delay(150);
 }
 settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
 outtextxy(250,305,"Press any key ");

 getch();

 cleardevice();


}

void conclusion()
{
  cleardevice();
  border();
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
  outtextxy(70,130,"Thanks to everyone who helped me in this project!");
  outtextxy(400,400,"-Adarsh");
  getch();
  closegraph();
}

/******************************************
*********END OF GRAPHIC FUNCTIONS**********
******************************************/


    void create()    //Function to create
 {

       char ans='y';
       budget b;

       ofstream fout;
       fout.open("budget.dat",ios::out|ios::binary);
       while(ans=='y')
      {
       cleardevice();
       border();
       b.getdata();
       if(b.getmonth()>12||b.getyear()>99)
       {
	  cleardevice();border();
	  gotoxy(10,5);
	  cout<<"||ERROR|| An input error has been detected";
	  gotoxy(10,6);
	  cout<<"This record will not be written into the file please try again";
	  getch();
	  cleardevice();border();
	   continue;
       }
       fout.write((char*) &b,sizeof(b)); gotoxy(17,25);
       cout<<"Do you want to enter more records?(y/n) ";
       cin>>ans;
      }
       gotoxy(25,28);
      cout<<"|Record(s) written|";
      getch();
      fout.close();

 }



 /******************************************/
    void app() //Appends to the file
  {

   ofstream fout;
   fout.open("budget.dat",ios::out|ios::app|ios::binary);
   budget b;
   char ans='y';
   while(ans=='y')
 {
     cleardevice();
     border();
     b.getdata();
     if(b.getmonth()>12||b.getyear()>99)
     {	  cleardevice();border(); gotoxy(10,5);
	  cout<<"||ERROR|| An error in the input has been detected ";
	  gotoxy(10,6);
	  cout<<"This record will not be written into the file please try again";
	  getch();
	  continue;
     }
   fout.write((char*)&b,sizeof(b)); gotoxy(17,25);
   cout<<"Do you want to enter more records(y/n)?";
   cin>>ans;
 }  gotoxy(25,28);
   cout<<"|Record(s) written|";
   getch();
   fout.close();
   }

/*****************************************************/


/**************************************************/
 //MULTIPURPOSE FUNCTION TO SEARCH FOR A RECORD

    void modsearch(int a)
  {
     int x,flg=0,y,pos;
     budget b1;
     cleardevice();border();
     gotoxy(15,5);
     cout<<"Enter the month and year of the required record ";
     cin>>x>>y;
     fstream f;
     f.open("budget.dat",ios::in|ios::out|ios::binary);

     while(f.peek()!=EOF)
   {
      pos=f.tellg();
      f.read((char*)&b1,sizeof(b1));
      if(b1.getmonth()==x&&b1.getyear()==y)
      {   flg=1;
	 if(a==1)
	{ cleardevice();border();
	  b1.modify();
	  f.seekg(pos);
	  f.write((char*)&b1,sizeof(b1));gotoxy(30,25);
	  cout<<"Record modified ";
	  break;
	 }
	else if(a==2)
	{ cleardevice();border();
	  b1.putdata();
	}
       else if(a==3)
       {  cleardevice();
	  line(0,0,getmaxx(),0);
	  line(0,getmaxy(),getmaxx(),getmaxy());
	  line(0,5,getmaxx(),5);
	  line(0,getmaxy()-5,getmaxx(),getmaxy()-5);
	  b1.analyse();
      }}
    }

   if(flg==0)
 {  gotoxy(30,20);
    cout<<"Record not found";
  }
   getch();
   f.close();

   }

/*******************************************/

   void del()
{
	cleardevice();border();
	ifstream fin;
	fin.open("budget.dat",ios::in|ios::binary);
	ofstream file;
	file.open("temp.dat",ios::out|ios::binary);
	int x,y;
	budget b1;
	char found='f',confirm='n';
	gotoxy(12,5);
	cout<<"Enter month and year of the record which is to be deleted: ";
	cin>>x>>y;

	while(fin.peek()!=EOF)
	{
		fin.read((char *)&b1,sizeof(b1));
		if(b1.getmonth()==x&&b1.getyear()==y)
		{
			cleardevice();
			border();
			b1.putdata();
			found='t';
			gotoxy(15,25);
		cout<<"Are you sure you want to delete this record ? (y/n) : ";
			cin>>confirm;
			if(confirm=='n')
			{
				file.write((char *)&b1,sizeof(b1));
			}
		}
		else
			file.write((char *)&b1,sizeof(b1));
	}
	if(found=='f')
       {        gotoxy(29,17);
		cout<<"Record not found";
       }
	else
      {	  gotoxy(29,27);
	  cout<<"Record Deleted ";
      }
	getch();
	fin.close();
	file.close();
	remove("budget.dat");
	rename("temp.dat","budget.dat");

}
/******************************************/

   void insert()
{
	cleardevice();border();
	ifstream fin;
	fin.open("budget.dat",ios::in|ios::binary);
	ofstream flout("temp.dat",ios::out|ios::binary);
	char last='y';
	budget b,b1;
	b.getdata();
	while(fin.peek()!=EOF)
	{
		fin.read((char*)&b1,sizeof(b1));
		if (b.getmonth()<=b1.getmonth()&&b.getyear()==b1.getyear())
		{
			flout.write((char*)&b,sizeof(b));
			flout.write((char*)&b1,sizeof(b1));
			last='n';
			break;
		}
		else
			flout.write((char*)&b1,sizeof(b1));
	}

	if(last=='y')
		flout.write((char*)&b,sizeof(b));

	while(fin.peek()!=EOF)
		{
			fin.read((char*)&b1,sizeof(b1));
			flout.write((char*)&b1,sizeof(b1));
		}
	gotoxy(30,27);
	cout<<"Record Inserted ";
	getch();
	fin.close();
	flout.close();
	remove("budget.dat");
	rename("temp.dat","budget.dat");

   }
  /**********************************************/

   void report()
 {
   cleardevice();border();
   int x,y=0;
   double sum_spen=0,sum_sav=0;
   budget b;
   gotoxy(20,5);
   cout<<"Enter the year which is to be displayed ";
   cin>>x;
   ifstream fin;
   fin.open("budget.dat",ios::in|ios::binary);
   while(fin.peek()!=EOF)
   {
       fin.read((char*)&b,sizeof(b));
       if(x==b.getyear())
       { ++y;
	 sum_sav+=b.savings;
	 sum_spen+=b.total;
       }
   }
   gotoxy(17,15);
   cout<<"Data is available for "<<y<<" months of the year 20"<<x;gotoxy(17,16);
   cout<<"The total spending for the year is "<<sum_spen;gotoxy(17,17);
   cout<<"Total saving for the year is "<<sum_sav;
   getch();
   fin.close();
  }

 /********************************************/

     void compare()
  {  int i=8;
     cleardevice();border();
     budget b;
     ifstream fin;
     fin.open("budget.dat",ios::in|ios::binary);
     gotoxy(14,5);
     cout<<"Budget month\tBudget Year\tSpending\tSavings ";gotoxy(14,6);
     cout<<"------------\t-----------\t--------\t-------";
     while(fin.peek()!=EOF)
     {
	fin.read((char*)&b,sizeof(b));
	gotoxy(19,i);
	cout<<b.getmonth();gotoxy(33,i);
	cout<<"20"<<b.getyear();gotoxy(48,i);
	cout<<b.getspen();gotoxy(63,i);
	cout<<b.getsav();
	++i;
     }
     getch();
     fin.close();
  }

/******************************************
***************MENU FUNCTIONS**************
******************************************/

  void menu();
  void menu_op()
 {
   cleardevice();border();
   int o;
   gotoxy(34,8);
   cout<<"Operations";
   gotoxy(24,11);
   cout<<"1.Enter the next months record ";
   gotoxy(24,12);
   cout<<"2.Delete a particular record ";
   gotoxy(24,13);
   cout<<"3.Insert a particular record " ;
   gotoxy(24,14);
   cout<<"4.Modify a record ";
   gotoxy(24,15);
   cout<<"5.Return to the previous menu ";
   gotoxy(24,17);
   cout<<"Enter your choice ";
   cin>>o;

   switch (o)
  {
     case 1:app();
	    break;
     case 2:del();
	    break;
     case 3:insert();
	    break;
     case 4:modsearch(1);
	    break;
     case 5:menu();
	    break;
     default:gotoxy(12,19);
	     cout<<"An invalid choice has been entered.Returning to previous menu ";getch();
	     menu();
   }
   }

   void menu_c()
  {
    int c;
    cleardevice();border();
    gotoxy(26,8);
    cout<<"Analysis & Comparisions";
    gotoxy(24,11);
    cout<<"1.Analyse the monthly budget ";
    gotoxy(24,12);
    cout<<"2.Compare with past expenditures ";
    gotoxy(24,13);
    cout<<"3.Annual report ";
    gotoxy(24,14);
    cout<<"4.Return to the previous menu ";
    gotoxy(24,16);
    cout<<"Enter your choice ";
    cin>>c;


     switch (c)
  {
     case 1:modsearch(3);
	    break;
     case 2:compare();
	    break;
     case 3:report();
	    break;
     case 4:menu();
	    break;
     default:gotoxy(12,19);
	     cout<<"An invalid choice has been entered.Returning to previous menu ";getch();
	     menu();
   }
  }

 /********************************************************/
   void menu()
 {

   int a;
   char ans='y';
   while(ans=='y'||ans=='Y') //Repeating till a correct value is entered
   {
   cleardevice();border();
   gotoxy(35,8);
   cout<<"Menu";
   gotoxy(24,11);
   cout<<"1.Create a new budget";
   gotoxy(24,12);
   cout<<"2.Operations ";
   gotoxy(24,13);
   cout<<"3.Analysis and Comparisions ";
   gotoxy(24,14);
   cout<<"4.View a monthly budget ";
   gotoxy(24,15);
   cout<<"5.Exit the program ";
   gotoxy(24,17);
   cout<<"Enter your choice ";
   cin>>a;
   switch (a)
   {

     case 1:create();
	    break;

     case 2:menu_op();
	    break;

     case 3:menu_c();
	    break;

     case 4:modsearch(2);
	    break;

     case 5:conclusion();
	    exit(0);
	    break;

     default:gotoxy(22,20);
	     cout<<"Incorrect value entered.Try again";
	     getch();
	     continue;
   }

   }

 }
 void start()
{

     init();
     cover();
     border();
     load();
     menu();
 }

  void main()
  {
      start();

  }


