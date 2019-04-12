/* TITLE hw4_3.cpp
 * ABSTRACT: c++ project1, this program is a virtual vending machine 
 * which can ......
 * Author: Kyle Dilbeck 
 * ID: 1996
 * Date: 2/21/19
 */
 
#include <iostream>
#include <string>
using namespace std;


class VendingMachine
{
    public:
        string display(); //display machine name and ID 
        void setName(string c); //set machine name
        int setNumber(int x); //set vending machine ID, ID
        string status();//displays current status of vending machine 
        void refill(int f, int u , int c , int k);//refills machine
        string displayMenu(); //displays items and corresponding numbers
        bool payment();
        void selectItem();
        void displayReceipt();
        void deselect();
        void reset();
        bool isEmpty();  
        VendingMachine();//Constructor implicit declaration/ prototype 
        
    private:
        int ID , itemCount, itemPrice, count; //machine ID
        double totalPrice;
        string name; //machine loacation 
        int PIN; //payment only valid if
        int pay; 
        double water, 
        cashMoney, 
        coffee, 
        chips, 
        chocBar, 
        profit; //items in machine 
        int waterSold; 
        int coffeeSold;
        int chipsSold; 
        int chocoBarSold; 
        int waterCount;
        int coffeeCount;
        int chipCount; 
        int chocBarCount; 
        double waterR, coffeeR, chipsR, chocoR, myPrice, tax, taxx, totalTax; 
        
        
};



//constructor initialization
VendingMachine::VendingMachine() 
{
    waterR =0; coffeeR=0; chipsR = 0; chocoR = 0, tax=0.10 , taxx=0,totalTax=0; 
    totalPrice = 0; myPrice =0; 
    ID = 0; 
    itemCount=0;
    name ="UNKNOWN";
    itemPrice=0;
    PIN=7777;
    water=1.50;
    coffee=2.00 ;
    chips=1.00;
    chocBar=2.50;
    profit =0; 
    waterSold = 0; 
    coffeeSold = 0 ; 
    chipsSold = 0 ; 
    chocoBarSold = 0 ; 
    waterCount = 0; 
    coffeeCount = 0 ; 
    chipCount = 0 ; 
    chocBarCount = 0 ; 
    pay = 0 ;
    cashMoney = 0;
    
}

//===================M A I N===========================================
int main()
{
    cout << "Debug...Hello" << endl;
     
    
    
    VendingMachine machine1; 
    
    cout << machine1.display();
    cout << " " << endl ; //space line 
    
    cout << machine1.displayMenu();
    cout << " " << endl ; //space line
    
    machine1.setNumber(100);
	machine1.setName("BIT117");
	
	cout << machine1.display(); 
	cout<<endl<<endl<<endl;
	cout << "STATUs" << endl;
	machine1.status();
	
	cout<<endl<<endl<<endl;
	cout<<endl<<endl<<endl;
	//test set name/num
	machine1.setNumber(6969);
	machine1.setName("BIT6969");
	cout << machine1.display();
	
	cout<<endl<<endl<<endl;
	cout<<endl<<endl<<endl;
	//test refill 
	cout << "------refil test-------" << endl <<endl; 
	machine1.refill(5, 7, 3, 10); // A machine’s admin can refill the items.
	machine1.status(); 
	cout<<endl<<endl<<endl;	
	
	machine1.displayMenu();
	cout << endl;
	machine1.selectItem();
	cout<< endl; 
	if(machine1.payment() == true)
	{
	    cout << "\n===== Receipt (1) =====\n";
	    machine1.displayReceipt();
	}
	else
	{
	    cout << "Invalid payment. All selections are canceled. \n"<<endl; 
	}

	
	

    
    
}


//---------Function definitions-------------

string VendingMachine::display()//display ID and name of machine 
{
    string print; 
    //print = name ; 
    //string fill; 
    //fill = stoi(ID);
    //id2 = to_string(ID); // c++11 
    print =  "ID: " + to_string(ID) + " / Name: " + name; //c++11 tostring   
    //cout << "Number: "<<endl ;
    return print; 
}

string VendingMachine::displayMenu()
{
    string end; 
    end = "End Display(Debug)"; 
    cout << "===== Vending Machine Menu ====="  <<endl; 
    cout << "  1. Water............$"<< water   <<endl
         << "  2. Regular Coffee...$"<< coffee  <<endl
         << "  3. Sun Chips........$"<< chips   <<endl
         << "  4. Chocolate Bar....$"<< chocBar <<endl;
    return end;
}

string VendingMachine::status()
{
    cout << "=============MACHINE STATUS=================" << endl; 
    display(); 
    string end; 
    end = "END STATUS";
    //one line - items sold 
    cout << "SOLD: " 
         << "Water: "            << waterSold 
         << "/ Regular Coffee: " << coffeeSold
         << "/ Sun Chip: "       << chipsSold 
         << "/ Chocolate Bar:  " << chocoBarSold 
         << endl; 
    //one line - items reamining 
    cout << "REMAINING: "         
         << "Water: "            << waterCount 
         << "/ Regular Coffee: " << coffeeCount
         << "/ Sun Chip: "       << chipCount 
         << "/ Chocolate Bar:  " << chocBarCount
         << endl;
    //profit from items sold 
    cout << "Earnings: $"  << profit << endl; 
    return end;
}

bool VendingMachine::isEmpty()
{
    if(itemCount == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void VendingMachine::setName(string c)
{
    name = c; 
    cout << "Name set to: " << c << endl;
    //cout << "Debug test - name = " << name << endl;
}

int VendingMachine::setNumber(int x) //set ID
{
    ID = x; 
    cout << "Number set to: " << x  << endl;
    //cout << "Debug test - ID = " << ID << endl;
}

void VendingMachine::refill(int f, int u, int c, int k)
{
    waterCount   = f; 
    coffeeCount  = u;
    chipCount    = c;
    chocBarCount = k; 
}


//definition of select item=====================================
void VendingMachine::selectItem()
{
    
    int x; 
    char choice = 'Y';
    while(choice == 'Y')
    {
        cout << "Select item: ";
        cin >> x; 
        switch(x)
        {
            
            case 1: //water
                
                int c1;
                cout << "How many do you want to buy? " ;
                cin >> c1; 
                waterSold = waterSold + c1;
                if(c1 <= waterCount)
                {
                    waterR = c1; 
                    waterCount = waterCount - c1; 
                    totalPrice = totalPrice + (waterCount*c1) ;
                    break;
                }
                else
                {
                    cout << "NONE LEFT :(" << endl; 
                    break;
                }
                
                
            case 2: //coffee
                
                int c2; 
                cout << "How many do you want to buy? " ;
                cin >> c2; 
                coffeeSold = coffeeSold + c2;
                if(c2 <= coffeeCount)
                {
                    coffeeR = c2;
                    //coffeeCount = coffeeCount - c2; 
                    //totalPrice = totalPrice + (coffeeCount*c2) ;
                    break;
                }
                else
                {
                    cout << "NONE LEFT :(" << endl; 
                    break;
                }
                
            case 3: //chip
                
                int c3; 
                cout << "How many do you want to buy? " ;
                cin >> c3; 
                chipsSold = chipsSold + c3; 
               if(c3 <= chipCount)
                {
                    chipsR = c3; 
                    chipCount = chipCount - c3; 
                    //totalPrice = totalPrice + (chipCount*c3) ;
                    break;
                }
                else
                {
                    cout << "NONE LEFT :(" << endl; 
                    break;
                }
                
            case 4: //choco
                
                int c4;
                cout << "How many do you want to buy? " ;
                cin >> c4; 
                chocoBarSold = chocoBarSold +c4;
                if(c4 <= chocBarCount)
                {
                    chocoR=c4; 
                    chocBarCount = chocBarCount - c4; 
                    //totalPrice = totalPrice + (chocBar*c4) ;
                    break;
                }
                else
                {
                    cout << "NONE LEFT :(" << endl; 
                    break;
                }
                
            default:
                cout << " INVALID" << endl << endl << endl;
                break;
        }
        cout << endl << "Would you like to continue? (Y/N) ";
        cin >> choice; 
        if(choice == 'N')
        {
            taxx = totalPrice * .10;
            totalTax = totalPrice + taxx; 
            cout << "Total price of all items selected: $" << (totalPrice+taxx) <<endl
            <<endl<<endl<<endl;
            break; 
        }
    }
    
}
//definition of payment=========================================
bool VendingMachine::payment()
{
    int paymentOption, pin; //1=debit 2=cash
    //paymentOption = y; 
    totalPrice = totalPrice + (waterR * 1.50);
    totalPrice = totalPrice + (coffeeR * 2.00);
    totalPrice = totalPrice + (chipsR * 1.00);
    totalPrice = totalPrice + (chocoR * 2.50);
    
    taxx = totalPrice * .10;
    //totalTax = totalPrice + taxx; 
    cout << "Total price of all items selected: $" << (totalPrice+taxx) <<endl
    <<endl;
    
    cout<<"Please enter payment option(1:debit/2:cash): ";
    cin >> paymentOption;
    if(paymentOption == 1)
    {
        //debit selected
        cout<< "Please enter PIN:";
        cin >> pin; 
        if(pin == PIN) //PIN == 7777
        {
            profit = profit + (totalPrice+taxx);
            cout << "Payment accepted";
            coffeeCount = coffeeCount - c2;
            return true;
        }
        else
        {
            
            cout << endl << "INVALID-PAYMENT ERROR" <<endl;
            deselect();
            return false;
        }
    }
    if(paymentOption == 2)
    {
        
        cout << "Enter money amount: " ; 
        cin >> cashMoney; 
        if(cashMoney < (totalPrice+taxx))
        {
            cout << "insufficient funds for total, please try again";
            deselect();
            return false; 
        }
        if(cashMoney == (totalPrice+taxx))
        {
            profit = profit + (totalPrice+taxx);
            cout  << "accepted, thank you";
            
            return true; 
        }
        if(cashMoney > (totalPrice+taxx))
        {
            profit = (totalPrice+taxx);
            int change; 
            change = cashMoney - (totalPrice+taxx); 
            cout << "Change: " << change << endl; 
            profit = profit - change; 
            return true; 
        }
    }
   
}

//--------------definition for displayReceipt------------------
//=============================================================
void VendingMachine::displayReceipt()
{
    
    
    if(waterR > 0 )
    {
        cout << "Water(s): $1.50 x " << waterR << " = " <<(waterR*1.50) <<endl;
    }
    if(coffeeR > 0 )
    {
        cout << "Regular Coffee(s): $2.00 x " <<waterR <<" =" << (coffeeR*2.00) <<endl;
    }
    if(chipsR > 0 )
    {
        cout << "Sun Chip(s): $1.00 x " << chipsR << " =" << (chipsR * 1.00) <<endl;
    }
    if(chocoR > 0 )
    {
        cout << "Chocolate Bar(s): $2.50 x " << chocoR <<" ="<<(chocoR * 2.50) << endl;
    }
    
    cout << "Subtotal: $" <<totalPrice <<endl;
    cout << "Tax (10%): " << taxx <<endl;
    cout << "Total: $" << (totalPrice + taxx) << endl;
    
    /*
    totalPrice = 0 ; 
    taxx = 0 ; 
    totalTax =0 ; 
    */
    
    
    
    
    
    
}

void VendingMachine::deselect()
{
    cout << "You de-slected:" << endl;
    if(waterR > 0 )
    {
        cout << "Water (" << waterR<<")"<<endl;
    }
    if(coffeeR > 0 )
    {
        cout << "Regular Coffee (" <<waterR <<")"<<endl;
    }
    if(chipsR > 0 )
    {
        cout << "Sun Chip (" << chipsR << ")"<< endl;
    }
    if(chocoR > 0 )
    {
        cout << "Chocolate Bar (" << chocoR <<")"<< endl;
    }
    //reset values to buy
    waterR  = 0; 
    chipsR  = 0; 
    coffeeR = 0; 
    chocoR  = 0;
    
}

void VendingMachine::reset()
{
    waterR =0; coffeeR=0;
    chipsR = 0; 
    chocoR = 0, taxx=0,totalTax=0; 
    totalPrice = 0; myPrice =0; 
    //ID = 0; 
    itemCount=0;
    //name ="UNKNOWN";
    profit =0; 
    waterSold = 0; 
    coffeeSold = 0 ; 
    chipsSold = 0 ; 
    chocoBarSold = 0 ; 
    waterCount = 0; 
    coffeeCount = 0 ; 
    chipCount = 0 ; 
    chocBarCount = 0 ; 
    pay = 0 ;
    cashMoney = 0;
}
