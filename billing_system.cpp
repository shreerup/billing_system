#include <iostream>
#include <fstream>
using namespace std;

class shopping
{
    private:
        int product_code;
        float price, dis;
        string product_name;

    public:
        void menu();
        void administrator();
        void customer();
        void add();
        void edit();
        void del();
        void list();
        void receipt();
};

void shopping :: menu()
{
    m:
    int choice;
    string email;
    string password;

    cout<<"\t\t\t\t________________________________________\n";
    cout<<"\t\t\t\t                                        \n";
    cout<<"\t\t\t\t       WELCOME TO THE SUPERMARKET       \n";
    cout<<"\t\t\t\t                                        \n";
    cout<<"\t\t\t\t               MAIN MENU                \n";
    cout<<"\t\t\t\t                                        \n";
    cout<<"\t\t\t\t________________________________________\n";
    cout<<"\n";
    cout<<"\t\t\t\t\t1) Administrator\n";
    cout<<"\n";
    cout<<"\t\t\t\t\t2) Customer\n";
    cout<<"\n";
    cout<<"\t\t\t\t\t3) Exit\n";
    cout<<"\n";
    cout<<"\t\t\t\t Please select your choice and Enter the number : ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        cout<<"\n\t Please Login\n\n";
        cout<<"\t Enter Email Address : ";
        cin>>email;
        cout<<"\t Enter Password : ";
        cin>>password;

        if(email=="shreerupikare2002@gmail.com" && password=="shree@123")
        {
            administrator();
        }
        else cout<<"\n\t\t\t\tInvalid email/password\n\n";
        break;

    case 2:
        {
            customer();
        }
    case 3:
        {
            exit(0);
        }
    default:
        cout<<" Please select from the given options";
    }
    goto m;
}


void shopping :: administrator()
{
    m:
    int choice;
    cout<<"\n\n\n\t\t\t\t Administrator OPTIONS";
    cout<<"\n\n\t\t\t\t 1) Add the product";
    cout<<"\n\n\t\t\t\t 2) Modify the product";
    cout<<"\n\n\t\t\t\t 3) Delete the product";
    cout<<"\n\n\t\t\t\t 4) Back to Main Menu";

    cout<<"\n\nPlease Enter your choice and Enter the number : ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        add();
        break;
    case 2:
        edit();
        break;
    case 3:
        del();
        break;
    case 4:
        menu();
        break;
    default:
        cout<<"Invalid choice!";
    }
    goto m;
}

void shopping :: customer()
{
    m:
    int choice;
    cout<<"\n\n\n\t\t\t\t Customer OPTIONS";
    cout<<"\n\n\t\t\t\t 1) Buy the product";
    cout<<"\n\n\t\t\t\t 2) Go Back to Main Menu";

    cout<<"\n\nPlease Enter your choice and Enter the number : ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        receipt();
        break;
    case 2:
        menu();
        break;
    default:
        cout<<"Invalid choice!";
    }
    goto m;
}

void shopping :: add()
{
    m:
    fstream data;
    int c;
    int token=0;
    float p,d;
    string n;

    cout<<"\n\t\t Add New Product";
    cout<<"\n\nProduct Code of the Product : ";
    cin>>product_code;
    cout<<"\nName of the Product : ";
    cin>>product_name;
    cout<<"\nPrice of the Product : ";
    cin>>price;
    cout<<"\nDiscount on the Product : ";
    cin>>dis;

    data.open("database.txt",ios::in);

    if(!data)
    {
        data.open("database.txt", ios::app|ios::out);
        data<<" "<<product_code<<" "<<product_name<<" "<<price<<" "<<dis<<endl;
        data.close();
    }
    else
    {
        data>>c>>n>>p>>d;

        while(!data.eof())
        {
            if(c == product_code)
            {
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();
    }
    if(token==1) goto m;
    else
        {
        data.open("database.txt", ios::app|ios::out);
        data<<" "<<product_code<<" "<<product_name<<" "<<price<<" "<<dis<<endl;
        data.close();
        }
    cout<<"\n\n\t\t Record Inserted !";
}

void shopping :: edit()
{
    m:
    fstream data,data1;
    int pkey;
    int c;
    int token=0;
    float p,d;
    string n;

    cout<<"\n\n\t\t\t Modify the Product";
    cout<<"\n\nProduct Code :";
    cin>>pkey;

    data.open("database.txt",ios::in);

    if(!data)
    {
        cout<<"\n\n File does not Exist !";
    }
    else
    {
        data1.open("database.txt",ios::in);
        data>>product_code>>product_name>>price>>dis;

        while(!data.eof())
        {
            if(pkey == product_code)
            {
                cout<<"\n\t\t Product New Code :";
                cin>>c;
                cout<<"\n\t\t Name of the Product :";
                cin>>n;
                cout<<"\n\t\t Price :";
                cin>>p;
                cout<<"\n\t\t Discount :";
                cin>>d;

                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<endl;
                cout<<"\n\n\t\t Record Edited !";
                token++;
            }
            else
            {
                data1<<" "<<product_code<<" "<<product_name<<" "<<price<<" "<<dis<<endl;
            }
            data>>product_code>>product_name>>price>>dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0)
        {
            cout<<"\n\n\t\t Record Not Found, Sorry !";
        }
    }
}

void shopping :: del()
{
    m:
    fstream data,data1;
    int pkey;
    int token=0;
    cout<<"\n\n\t Delete Product";
    cout<<"\n\n\t Product Code : ";
    cin>>pkey;
    data.open("database.txt",ios::in);

    if(!data)
    {
        cout<<"\n\n File does not Exist !";
    }
    else
    {
        data1.open("database1.txt",ios::in);
        data>>product_code>>product_name>>price>>dis;

        while(!data.eof())
        {
            if(product_code==pkey)
            {
                cout<<"\n\n\t\t Product Deleted Successfully !";
                token++;
            }
            else
            {
                data1<<" "<<product_code<<" "<<product_name<<" "<<price<<" "<<dis<<endl;
            }
            data>>product_code>>product_name>>price>>dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0)
        {
            cout<<"\n\n\t\t Record Not Found, Sorry !";
        }
    }
}

void shopping :: list()
{
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n______________________________________________________________\n";
    cout<<"Product No        Name              Price             Discount\n\n";
    cout<<"______________________________________________________________\n";
    data>>product_code>>product_name>>price>>dis;

    while(!data.eof())
    {
        cout<<product_code<<"\t\t"<<product_name<<"\t\t"<<price<<"\t\t"<<dis<<"\n";
        data>>product_code>>product_name>>price>>dis;
    }
    data.close();
}

void shopping :: receipt()
{
    fstream data;

    int arrc[100];
    int arrq[100];
    char choice;
    int c=0;
    float amount=0;
    float dis=0;
    float total=0;

    cout<<"\n\n\t\t\t\t PRODUCT LIST ";
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n Empty Database ";
    }
    else
    {
        data.close();
        list();
        cout<<"\n______________________________________________________________";
        cout<<"\n                                                              ";
        cout<<"\n                    PLEASE PLACE THE ORDER                    ";
        cout<<"\n                                                              ";
        cout<<"\n______________________________________________________________";
        do
        {
            m:
            cout<<"\n\nEnter Product Code : ";
            cin>>arrc[c];
            cout<<"\nEnter the Product Quantity : ";
            cin>>arrq[c];
            for(int i=0;i<c;i++)
            {
                if(arrc[c]==arrc[i])
                {
                    cout<<"\n\n Duplicate Product Code. Please try Again !";
                    goto m;
                }
            }
            c++;
            cout<<"\n\n Do you want to buy another product? If yes, then press y, else press n : ";
            cin>>choice;
        }
        while(choice == 'y');

        cout<<"\n";
        cout<<"\n_____________________________________________RECEIPT___________________________________\n";
        cout<<"\nProduct No   Product Name   Quantity     Price        Amount       Amount with discount\n";

        for(int i=0;i<c;i++)
        {
            data.open("database.txt",ios::in);
            data>>product_code>>product_name>>price>>dis;
            while(!data.eof())
            {
               if(product_code==arrc[i])
                {
                    amount=price*arrq[i];
                    dis=amount-(amount*dis/100);
                    total=total+dis;
                    cout<<"\n"<<product_code<<"\t\t"<<product_name<<"\t"<<arrq[i]<<"\t  "<<price<<"\t\t"<<amount<<"\t\t"<<dis;

                }
                    data>>product_code>>product_name>>price>>dis;
            }
            data.close();
        }
        data.close();

    }
    cout<<"\n\n_______________________________________________________________________________________";
    cout<<"\n Total Amount : "<<total;

}

int main()
{
    shopping s;
    s.menu();
}
