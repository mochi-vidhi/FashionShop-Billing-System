#include<iostream>
#include<ctime>
#include<string.h>
#include<stdlib.h>
using namespace std;
class GarmentShop{    
    public:
    void login(){
          char u_name[5],pass[7];
         cout<<"User Name : user  && password : sys123"<<endl;
        while (true) {
        cout << "Enter the user name: ";
        cin >> u_name;
        cout << "Enter the password: ";
        cin >> pass;

        try {
            if (strcmp(u_name, "user") == 0) {
                if (strcmp(pass, "sys123") == 0) {
                    cout << "\n\t\t Welcome, Login Successful!\n";
                    break;  // Exit the loop on successful login
                } else {
                    throw std::runtime_error(" Password is incorrect.\n");
                }
            } else {
                throw std::runtime_error(" Username is incorrect.\n");
            }
        }
        catch (const std::runtime_error &e) {
            cout << e.what();
            cout << "Please try again.\n\n";
        }
    }
    }
    void  detailsAbout(){
        cout<<"\t\t<<<-------------Fashion Junction---------------->>>\t\t"<<endl;
        cout<<"Address:-Anand Vidhyanagar Road, Anand - 388001"<<endl;
        cout<<"Ph-no:- 9898786755"<<endl;
        cout<<"email id:-fashion123@gmail.com "<<endl;
        cout<<"Timings:-\n Mon - Sun 9:30 am - 8:30 pm"<<endl;
        cout<<"Quick Information:-\nMode of Payment"<<endl;
        cout<<"Cash, Cash on Delivery, Debit Cards"<<endl;
        cout<<" Credit Card, UPI, BHIM, Paytm,PhonePe "<<endl;
        cout<<"Master Card, RuPay Card, Visa Card, Amazon Pay"<<endl;
        cout<<"Services:-\n > Delivery Service\n> Shop In Store\n> Same Day Delivery"<<endl;
        cout<<"Category:-\n 1.Kids 2.Women 3.Men 4.Accessories 5.Footwear"<<endl;
    }
    void products(){
        cout<<"-------------------------------------------------------"<<endl;
        cout<<"\t\tTopWear\t\t\t\tBottomWear\t\t\tFootWear\t\t\tAccessories"<<endl;
        cout<<"---------------------------------------------------------------"<<endl;
        cout<<"Girls:-\tT-shirts,dresses,jumpsuits,sweaters\t\tskirts,pents,shorts\t";
        cout<<"Shoes,sandals,boots\t\tHats,belts,gloves,socks"<<endl;
        cout<<"-----------------------------------------------------------------"<<endl;
        cout<<"Boys:-\tT-shirts,shirts,jacket,sweaters\t";
        cout<<"\tpents,shorts,joggers,jeans\t";
        cout<<"Shoes,boots\t\t\tHats,belts,gloves,socks"<<endl;
        cout<<"-----------------------------------------------------------------"<<endl;
        cout<<"Women:-\tT-shirts,dresses,Denim,sweaters\t\tskirts,pents,shorts,jeans\t";
        cout<<"Shoes,sandals,boots\t\tHats,belts,gloves,socks"<<endl;
        cout<<"-----------------------------------------------------------------"<<endl;
        cout<<"Men:-\tT-shirts,shirts,sweaters,suit\t";
        cout<<"\tpents,shorts,joggers,jeans\t";
        cout<<"Shoes,boots\t\t\tHats,belts,gloves,socks"<<endl;
        cout<<"-----------------------------------------------------------------"<<endl;
    }
};
class CalcBill:public GarmentShop{
  protected:
  string product[30],payment,c_name;
  int price[20],qty[10],bill_no,age,n;
  float gst,subtotal,discount,total;
  time_t tm;
  public:
  void calcbill(){
    cout<<"Enter the bill no:";
    cin>>bill_no;
    cout<<"Enter the name of customer:"<<endl;
    cin>>c_name;
    cout<<"Enter age for purchase :"<<endl;
    cin>>age;
    cout<<"Enter the numbers of product:";
    cin>>n;
    for(int i=1;i<=n;i++){
    cout<<"Enter name of products:"<<i<<endl;
    cin>>product[i];
    cout<<"Enter the qty of product:"<<i<<endl;
    cin>>qty[i];
    cout<<"Enter the price of product:"<<endl;
    cin>>price[i];
    price[i]*=qty[i];
    subtotal+=price[i];
    discount=price[i]-(0.05*price[i]);
    }
    gst=0.05*discount;
    total=gst+subtotal-discount;
    cout<<"Enter payment Method:";
    cin>>payment;
    }
    void print(){
        cout<<"------------------------------------------"<<endl;
        cout<<"Bill No:-"<<bill_no<<endl;
        cout<< time(&tm);
        cout<<"Date:"<<ctime(&tm)<<endl;
        cout<<"To:-"<<c_name<<endl;
        cout<<"-------------------------------------------"<<endl;
        cout<<"No\t\tProduct\t\tQty\t\tprice"<<endl;
        cout<<"-------------------------------------------"<<endl;
        for(int i=1;i<=n;i++){
            cout<<i;
            cout<<"\t\t";
            cout<<product[i];
            cout<<"\t\t";
            cout<<qty[i];
            cout<<"\t\t";
            cout<<price[i];
            cout<<endl;         
        }
        cout<<"----------------------------------------"<<endl;
        cout<<payment<<endl;
        cout<<"\t\t\tSubtotal:- "<<subtotal<<endl;
        cout<<"\t\t\tDiscount:- "<<discount<<endl;
        cout<<"\t\t\tGst% :- "<<gst<<endl;
        cout<<"\t\t\tTotal:- "<<total<<endl;
        cout<<"--------------------------------------------"<<endl;
        cout<<"\t\t\tThank you...."<<endl;
        cout<<"\t\t\tVisit Again..."<<endl;
    }  
};
class PrintDetails:public CalcBill{
     public:
        void loginSite(){
          login(); 
        }
        void detailsAboutShop(){
         detailsAbout();
         products();
        }
       
        void calculateBill(){
           calcbill();
        }
        void PrintBill(){
           print();
        }
};
int main(){
  int op;
   PrintDetails p;
   p.loginSite();
   system("PAUSE");
   start:
   cout<<"\t\t\tWhat you want to do?"<<endl;
   cout<<"\t\t\t1.To show details about shop."<<endl;
   cout<<"\t\t\t2.Would you Like to buy something??"<<endl;
   cout<<"\t\t\t3.Exit."<<endl;
   cout<<"Select your option..."<<endl;
   cin>>op;
   switch(op){
        case 1:
        p.detailsAboutShop();
        goto start;
        case 2:
        p.calculateBill();
        p.PrintBill();
        case 3:
        exit(0);
        default:
        cout<<"Enter valid option..."<<endl;
     }
     return 0;  
}
