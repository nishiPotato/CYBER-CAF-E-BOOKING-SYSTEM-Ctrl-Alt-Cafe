//Coder: Nurul Husna Nadhirah binti Azman, Adrianna Sofea binti Ahmad Nazmi, Nur Damia Maisarah binti Dzulkarnain, Nur Bahiyah binti Ahmad Fauzi


#include<iostream>
#include <string>
#include <cctype>

using namespace std;

void displayMenu();
void displaySnacks();

int main()
{
	int Pnumber, pax, fee, deposit, time, total_fee, amount, price, pay, snack_price, total_charges; //general variables
	int amountSolo = 0, soloPrice = 0, amountGaming = 0, gamingPrice = 0, amountPro = 0, proPrice = 0; //snacks variables
	string name, paymeth, set, date; //another general variables
	char setCode, answer; 

    //display menu
    displayMenu();
	
	//asking user's details
	cout<<"\nPlease enter your details below.";
	cout<<"\nEnter name: ";
	getline(cin,name);
	cout<<"Enter phone number: (+60)";
	cin >> Pnumber;
	
	// calculation of the fee
    do
	{
		cout<<"\nEnter number of pax: ";
		cin >> pax; 
				if (pax>=1 && pax<= 2)
			{
				cout<<"\nFee: RM 10 per person";
				fee = 10 * pax;
			}
			else if (pax >= 3 && pax <=4)
			{
				cout<<"\nFee: RM 7 per person";
				fee = 7 * pax;
			}
			else if (pax >= 5)
			{
				cout<<"\nFee: RM 5 per person";
				fee = 5 * pax;
			}
			else if (pax <= 0)
			{
				cout<<"\nInvalid input. Please try again.";
			}
	} while (pax<=0);
		
	cout<<"\nDeposit: RM 3 per person"<<endl;
	
	cout<<"\nEnter date of booking (dd/mm/yy): ";
	cin >> date;
	cout<<"\nEnter time in 24H format (e.g 12:50 pm = 1250): ";
	cin >> time;
	
	//snacks ordering
    displaySnacks();
	
	//*do-while loop for snacks*
	do
	{
		cout<<"\nWould you like to order some snacks? (Y/N): ";
		cin >> answer;
		if (toupper(answer) == 'Y')
		{
			do
			{
				if (toupper(answer) == 'Y')
				{
					do
					{
					cout<<"\nChoose your snack set (A/B/C): ";
					cin >> setCode;

					} while (toupper(setCode) != 'A' && toupper(setCode) != 'B' && toupper(setCode) != 'C');
					
					if (toupper(setCode) == 'A')
					{	
						cout<<"\nEnter amount: ";
						cin >> amount;
						if (amount <= 0)
						{
						cout<<"\nInvalid input.";
						}
						amountSolo = amount + amountSolo;
			            soloPrice = amountSolo * 8;
			                
					}
					else if (toupper(setCode) == 'B')
					{
						cout<<"\nEnter amount: ";
						cin >> amount;
						if (amount <= 0)
						{
						cout<<"\nInvalid input.";
						}
			            amountGaming = amount + amountGaming;
			        	gamingPrice = 12 * amountGaming;
			        
					}
					else if (toupper(setCode) == 'C')
					{
						cout<<"\nEnter amount: ";
						cin >> amount;
						if (amount <= 0)
						{
						cout<<"\nInvalid input.";
						}
			            amountPro = amount +amountPro;
			            proPrice = 25 * amountPro;
			               
					}
				}
					
				cout<<"\nWould you like to continue ordering? (Y/N): ";
				cin >> answer;
					
				}while(toupper(answer) == 'Y' && toupper(answer) != 'N');
			}
			
	}while (toupper(answer) != 'Y' && toupper(answer) != 'N');
	
	//payment method
	cout<<"\nSelect your preferred payment method.";
	cout<<"\n1. FPX";
	cout<<"\n2. CASH";
	cout<<"\n3. E-WALLET"<<endl;
	
	//payment method calc
	 while (pay != 1 && pay != 2 && pay != 3)
	{
		cout<<"\nEnter payment method (1/2/3): ";
		cin >> pay;
		if (pay == 1)
		{
			paymeth = "FPX";
		}
		else if (pay == 2)
		{
			paymeth = "CASH";
		}
		else if (pay == 3)
		{
			paymeth = "E-WALLET";
		}
		else
		{
			cout<<"\nNOT IDENTIFIED."<<endl;
			cout<<"\nChoose between the available payment method only. (1/2/3)";
		}
	}
	
	//charges calculation
	deposit = 3 * pax;
	total_fee = fee + deposit;
	snack_price = soloPrice + gamingPrice + proPrice;
	total_charges = total_fee + snack_price;
	
	//printing receipt
    cout << "\n________________________**____________________________";
    cout << "\n                                           RECEIPT                                                ";
    cout << "\n______________________________________________________";
    cout << "\nName: " << name <<"                           	                   Date : " << date;
    cout << "\nPhone Number: (+60)" << Pnumber << "                    Time : " << time;
    cout << "\nNumber of Pax: " << pax;
    cout << "\nFee: RM " << fee;
    cout << "\nDeposit: RM " << deposit<<endl;
    
    cout << "\n--------------------------SNACKS ORDER---------------------------" << endl;
    cout << "\n1. SOLO SET  x " << amountSolo << " RM " <<  soloPrice  << endl;
    cout << "\n2. GAMING BUDDY SET x " << amountGaming << " RM " << gamingPrice << endl;
    cout << "\n3. PRO GAMER SET  x " << amountPro << "  RM " << proPrice << endl;
    cout << "\n------------------------------------------------------------------------------" << endl;
    
    cout<<"\nPayment Method: "<<paymeth;
    cout<<"\nTotal Fee: RM "<<total_fee;
    cout<<"\nSnacks price: RM "<<snack_price<<endl;
	
    cout<<"\nTotal Charges: RM "<<total_charges<<endl;
    cout << "\n__________________________________________________"<<endl;
	
    cout<<"\nTHANK YOU FOR USING OUR SYSTEM :)";
	
return 0;
}

void displayMenu()
{
	cout<<"\n____________________________**____________________________";
	cout<<"\n        WELCOME TO OUR CYBER CAFE e-BOOKING SYSTEM   ";
	cout<<"\n_________________________________________________________";
	cout<<"\n NO.			PAX		FEE (PER PERSON)     ";
	cout<<"\n 1.			1-2		    RM10     ";
	cout<<"\n 2.			3-4		    RM7      ";
	cout<<"\n 3.			5+		    RM5      ";
	cout<<"\n_______________________________________________________"<<endl;
}

void displaySnacks()
{
cout<<"\n________________________**_____________________________";
cout<<"\n       		SNACKS ORDERING SYSTEM     ";
cout<<"\n_______________________________________________________"<<endl;
cout<<"\nA. SOLO SET (RM8)     B. GAMING BUDDY SET (RM12)      C.PRO GAMERS SET (RM25)";
cout<<"\n   Bottomless drink      Bottomless drink	             Bottomless drink";
cout<<"\n   Burger - 1	        Burgers - 2			  Burgers - 3";
cout<<"\n   Fries / Nugget - 1     Curly fries - 1			  Curly fries - 2";
cout<<"\n		                   Corndog - 1                  	  Corndogs - 2";
cout<<"\n______________________________________________________"<<endl;
}
