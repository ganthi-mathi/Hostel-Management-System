#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include <string.h>
#include<fstream>
using namespace std;
class boyshostel{
	protected:
		int rm;
		string ms;
		string ms2;
		//int fee;
		string mess;
		string wifi;
		string comp;
		string nam;
		string dep;
		string pl;
		string dob;
		int ad;
		string gen;
		public:
			int names(){
				fstream f;
				f.open("detail.txt",ios::out|ios::in|ios::app);
				cout<<"\nEnter name:";
				cin>>nam;	
				f<<"name:"<<nam<<endl;
				cout<<"\ngender:";
				cin>>gen;	
				f<<"gender:"<<gen<<endl;
				cout<<"enter department:";
				cin>>dep;
				f<<"department:"<<dep<<endl;
				cout<<"enter place:";
				cin>>pl;
				f<<"place:"<<pl<<endl;
				cout<<"enter date of birth:";
				cin>>dob;
				f<<" date of birth:"<<dob<<endl;
				cout<<"enter admission no:";
				cin>>ad;
				f<<"admission no:"<<ad<<endl;
				
				f.close();
		}
		void mess1(){
			fstream s;
			s.open("mess.txt",ios::out|ios::in|ios::app);
			cout<<"veg details:\n";
			cin>>ms;
			s<<"mess:"<<ms<<endl;
		}
			void messb(){
			fstream s;
			s.open("mess.txt",ios::in);
			string p;
			while(!s.eof()){
				s>>p;
				cout<<p<<""<<endl;
			}
			s.close();
		}
		void mess2(){
			fstream s;
			s.open("messn.txt",ios::out|ios::in|ios::app);
			cout<<"nonveg details:\n";
			cin>>ms2;
			s<<"mess:"<<ms2<<endl;
		}
		void messa(){
			fstream s;
			s.open("messn.txt",ios::in);
			string p;
			while(!s.eof()){
				s>>p;
				cout<<p<<""<<endl;
			}
			s.close();
		}
		void fees(){
			fstream h;
			h.open("fee.txt",ios::out|ios::in|ios::app);
			cout<<"hostel fee for veg:55000\n";
			cout<<"mess fee:15000\n";
			cout<<"hostel fee for non veg:65000\n";
			cout<<"mess fee:25000\n";
			cout<<"phone fee:10000\n";
			cout<<"management fee:30000\n";
			h<<"hostel fee for veg:55000\n"<<endl;
			h<<"mess fee:15000\n"<<endl;
		    h<<"hostel fee for non veg:65000\n"<<endl;
		   	h<<"mess fee:25000\n"<<endl;
		   	h<<"phone fee:10000\n"<<endl;
			h<<"management fee:30000\n"<<endl;
		}
		void fees2(){
			fstream h;
			h.open("fee.txt",ios::in);
			string m;
			while(!h.eof()){
				h>>m;
				cout<<m<<""<<endl;
			}
			h.close();
		}
		void complaint1(){
			fstream c;
			c.open("complaint.txt",ios::out|ios::app);
			cout<<"***********************************DROP YOUR COMPLIANTS************************************";
			cin>>comp;
			c<<"complaint:"<<comp;
			c.close();
		}
    	void complaint(){
			fstream c;
			c.open("complaint.txt",ios::out|ios::in|ios::app);
			string r;
			while(!c.eof()){
			c>>r;
			cout<<r<<""<<endl;
		}
		c.close();
		}
	};
		struct node
{
    int num = 1;
    int fill = 0;
    char name[3][10];
    node *next;
    node *prev;
};
class roombhostel:public boyshostel
{
    node *header[3];
    node *cn;

public:
    roombhostel()
    {
    //	fstream d;
	    //d.open("detail.txt",ios::out|ios::in|ios::app);
        for (int i = 0; i < 3; i++)
            header[i] = NULL;
    }
    void create()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                node *nn = new node;
                nn->next = NULL;
                nn->prev = NULL;
                if (header[i] == NULL)
                {
                    header[i] = nn;
                    nn->num = 1;
                }
                else
                {
                    node *cn = header[i];
                    while (cn->next != NULL)
                    {
                        cn = cn->next;
                    }
                    if (j == 3 || j == 5 || j == 7 || j == 8)
                    {
                        cn->num = 3;
                    }
                    if (j == 2 || j == 4 || j == 6)
                    {
                        cn->num = 2;
                    }
                    cn->next = nn;
                    nn->prev = cn;
                }
            }
        }
    }
    void display()
    {
        int j = 0, k = 0, l = 0;
        for (int i = 0; i < 48; i++)
        {
            cout << "--";
        }
        cout << "\n "
        ;
        for (int i = 1; i < 4; i++)
        {
            cout << "| Floor number : "<< i << " \t\t";
        }
        cout << "|\n" ;
        for (int i = 0; i < 48; i++)
        {
            cout << "--";
        }
        cn = header[j];
        node *sn = header[j + 1];
        node *tn = header[j + 2];
        cout << "\n ";
        while (cn != NULL)
        {
            if (cn->fill != cn->num && cn->num != 0)
            {
                j++;
                cout << "| room no : "<< j;
                cout << "->Vacant cots->"<< cn->num;
            }
            else
            {
                j++;
                cout << "| room no : "<< j;
                cout << "->Present ";
            }
            if (sn->fill != sn->num && sn->num != 0)
            {
                k++;
                cout << "\t | room no : "<< j;
                cout << "->Vacant cots->"<< sn->num;
            }
            else
            {
                k++;
                cout << " \t | room no : "<< j;
                cout << "->Present ";
            }
            if (tn->fill != tn->num && tn->num != 0)
            {
                l++;
                cout << "\t | room no : "<< j;
                cout << "->Vacant cots->"<< tn->num << "| ";
            }
            else
            {
                l++;
                cout << "\t | room no : "<< j;
                cout << "->Present "<< " | ";
            }
            cout << " \n ";
            for (int i = 0; i < 48; i++)
            {
                cout << "--" ;
            }
            cout << "\n ";
            cn = cn->next;
            sn = sn->next;
            tn = tn->next;
        }
    }
    void book(int people)
    {
    	fstream d;
	    d.open("detail.txt",ios::out|ios::in|ios::app);
        int floor, room;
        cout << "\nEnter the floor number : ";
        cin >> floor;
        d<<"floor number:"<<floor<<endl;
        try
        {
            if (floor < 0 || floor > 4)

            {
                throw(floor);
            }
            cn = header[floor - 1];

            cout << "\nEnter the room number : ";
            cin >> room;
            d<<"room number:"<<room<<endl;
            try
            {

                if (room < 0 || room > 10)
                {
                    throw(room);
                }
                else
                {
                    int i = 1;
                    while (i < room)
                    {
                        cn = cn->next;
                        i++;
                    }
                    if (cn->num >= people)
                    {
                        cout << "\nroom is vacant you can apply for room" ;

                        int count = 0;
                        while (cn->fill - 1 <= cn->num)
                        {
                            names();
                           // cout << "\nEnter name "<< cn -> fill + 1 << " : ";

                            //cin >> cn->name[cn->fill];
                            count++;
                            cn->fill++;
                            if (count >= people)
                            {
                                break;
                            }
                        }
                        cn->num = cn->num - people;
                    }

                    else
                    {
                        cout << "\nroom is not vacant... SORRY !!!";
                    }
                }
            }
            catch (int r)
            {
                cout << "\ninvalid room number : "<< r;
            }
        }
        catch (int r)
        {
            cout << " \ninvalid floor number : " << r;
        }
    }
    void cancle(int check)
    {
        char namecheck[10];
        int flag = 0;
        int room, i = 1;
        try
        {
            if (check < 0 || check > 4)

            {
                throw(check);
            }
            else
            {
                cout << " Enter the room no : ";
                cin >> room;
              //  d<<"room number:"<<room<<endl;
                try
                {
                    if (room < 0 || room > 10)
                    {
                        throw(room);
                    }
                    else
                    {
                        cout << " Enter the name to be delete :";

                        cin >> namecheck;
                        cn = header[check - 1];
                        while (i < room)
                        {
                            cn = cn->next;
                            i++;
                        }
                        i = 0;
                        while (i < 3)
                        {

                            if (!strcmp(namecheck, cn -> name[i]))

                            {
                                flag = 1;
                                break;
                                i = 0;
                            }
                            else
                                i++;
                        }
                        if (flag == 1 && cn->fill != 0)
                        {
                            cout << "\nrecord deleted : "<< cn -> name[i];

                            cn->name[i][0] ='A';
                            cn->name[i][1] ='\0';
                            cn->fill--;
                            cn->num++;
                        }
                        else

                            cout << "\nrecord not present ";
                    }
                }
                catch (int r)
                {
                    cout << "\ninvalid room number : " << r;
                }
            }
        }

        catch (int r)

        {
            cout << " \n floor dosn't exist : " << r;
        }
    }
    void upgrade(int check)
    {
        char namecheck[10];
        int room, i = 1;
        try
        {
            if (check < 0 || check > 4)

            {
                throw(check);
            }
            else
            {
                cout << " Enter the room no : ";
                cin >> room;
                try
                {
                    if (room < 0 || room > 10)

                    {
                        throw(room);
                    }
                    else
                    {
                        cout << "Enter the name to be updated :";

                        cin >> namecheck;
                        cn = header[check - 1];
                        while (i < room)
                        {
                            cn = cn->next;
                            i++;
                        }
                        i = 0;
                        while (i < 3)
                        {
                            if (!strcmp(namecheck, cn -> name[i]))

                            {
                                cout << "\nenter updated name : " ;

                                cin >> cn->name[i];
                                break;
                            }
                            else
                                i++;
                        }
                        if (i >= 3)
                            cout << "record not found ";
                        else
                        {
                            cout << "\nrecord updated\nprevious name : "<< namecheck << "\nupdated name : "<< cn->name[i];
                        }
                    }
                }
                catch (int r)
                {
                    cout << "\ninvalid room number : "<< r;
                }
            }
        }

        catch (int r)

        {
            cout << "\n floor dosn't exist : "<< r;
        }
    }
};
class girlshostel:public roombhostel
{
	protected:
		int rmg;
		string msg;
		string ms2g;
		//int fee;
		string messg;
		string wifig;
		string compg;
		string namg;
		string depg;
		string plg;
		string dobg;
		int adg;
		string geng;
		public:
			int namesg(){
				fstream f;
				f.open("detailg.txt",ios::out|ios::in|ios::app);
			
				cout<<"\nEnter name:";
				cin>>namg;	
				f<<"name:"<<namg<<endl;
				cout<<"\ngender:";
				cin>>geng;	
				f<<"gender:"<<geng<<endl;
				cout<<"enter department:";
				cin>>depg;
				f<<"department:"<<depg<<endl;
				cout<<"enter place:";
				cin>>plg;
				f<<"place:"<<plg<<endl;
				cout<<"enter date of birth:";
				cin>>dobg;
				f<<" date of birth:"<<dobg<<endl;
				cout<<"enter admission no:";
				cin>>adg;
				f<<"admission no:"<<adg<<endl;
				
				f.close();
		}
		void mess1g(){
			fstream s;
			s.open("messg.txt",ios::out|ios::in|ios::app);
			cout<<"veg details:\n";
			cin>>msg;
			s<<"mess:"<<msg<<endl;
		}
			void messbg(){
			fstream s;
			s.open("messg.txt",ios::in);
			string p;
			while(!s.eof()){
				s>>p;
				cout<<p<<""<<endl;
			}
			s.close();
		}
		void mess2g(){
			fstream s;
			s.open("messng.txt",ios::out|ios::in|ios::app);
			cout<<"nonveg details:\n";
			cin>>ms2g;
			s<<"mess:"<<ms2g<<endl;
		}
		void messag(){
			fstream s;
			s.open("messng.txt",ios::in);
			string p;
			while(!s.eof()){
				s>>p;
				cout<<p<<""<<endl;
			}
			s.close();
		}
		void feesg(){
			fstream h;
			h.open("feeg.txt",ios::out|ios::in|ios::app);
			cout<<"hostel fee for veg:55000\n";
			cout<<"mess fee:15000\n";
			cout<<"hostel fee for non veg:65000\n";
			cout<<"mess fee:25000\n";
			cout<<"phone fee:10000\n";
			cout<<"management fee:30000\n";
			h<<"hostel fee for veg:55000\n"<<endl;
			h<<"mess fee:15000\n"<<endl;
		    h<<"hostel fee for non veg:65000\n"<<endl;
		   	h<<"mess fee:25000\n"<<endl;
		   	h<<"phone fee:10000\n"<<endl;
			h<<"management fee:30000\n"<<endl;
		}
		void fees2g(){
			fstream h;
			h.open("feeg.txt",ios::in);
			string m;
			while(!h.eof()){
				h>>m;
				cout<<m<<""<<endl;
			}
			h.close();
		}
		void complaint1g(){
			fstream c;
			c.open("complaintg.txt",ios::out|ios::app);
			cout<<"@@@@@@@@ DROP YOUR COMPLAINTS @@@@@@@@";
			cin>>compg;
			c<<"complaint:"<<compg<<endl;
			c.close();
		}
    	void complaintg(){
			fstream c;
			c.open("complaintg.txt",ios::out|ios::in|ios::app);
			string r;
			while(!c.eof()){
			c>>r;
			cout<<r<<""<<endl;
		}
		c.close();
		}
	};
struct nodeg
{
    int num = 1;
    int fill = 0;
    char name[3][10];
    nodeg *next;
    nodeg *prev;
};
class roomghostel:public girlshostel
{
    nodeg *header[3];
    nodeg *cn;

public:
     roomghostel()
    {
    	//fstream d;
	   // d.open("detailg.txt",ios::out|ios::in|ios::app);
        for (int i = 0; i < 3; i++)
            header[i] = NULL;
    }
    void createg()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                nodeg *nn = new nodeg;
                nn->next = NULL;
                nn->prev = NULL;
                if (header[i] == NULL)
                {
                    header[i] = nn;
                    nn->num = 1;
                }
                else
                {
                    nodeg *cn = header[i];
                    while (cn->next != NULL)
                    {
                        cn = cn->next;
                    }
                    if (j == 3 || j == 5 || j == 7 || j == 8)
                    {
                        cn->num = 3;
                    }
                    if (j == 2 || j == 4 || j == 6)
                    {
                        cn->num = 2;
                    }
                    cn->next = nn;
                    nn->prev = cn;
                }
            }
        }
    }
    void displayg()
    {
        int j = 0, k = 0, l = 0;
        for (int i = 0; i < 48; i++)
        {
            cout << "--";
        }
        cout << "\n "
        ;
        for (int i = 1; i < 4; i++)
        {
            cout << "| Floor number : "<< i << " \t\t";
        }
        cout << "|\n" ;
        for (int i = 0; i < 48; i++)
        {
            cout << "--";
        }
        cn = header[j];
        nodeg *sn = header[j + 1];
        nodeg *tn = header[j + 2];
        cout << "\n ";
        while (cn != NULL)
        {
            if (cn->fill != cn->num && cn->num != 0)
            {
                j++;
                cout << "| room no : "<< j;
                cout << "->Vacant cots->"<< cn->num;
            }
            else
            {
                j++;
                cout << "| room no : "<< j;
                cout << "->Present ";
            }
            if (sn->fill != sn->num && sn->num != 0)
            {
                k++;
                cout << "\t | room no : "<< j;
                cout << "->Vacant cots->"<< sn->num;
            }
            else
            {
                k++;
                cout << " \t | room no : "<< j;
                cout << "->Present ";
            }
            if (tn->fill != tn->num && tn->num != 0)
            {
                l++;
                cout << "\t | room no : "<< j;
                cout << "->Vacant cots->"<< tn->num << "| ";
            }
            else
            {
                l++;
                cout << "\t | room no : "<< j;
                cout << "->Present "<< " | ";
            }
            cout << " \n ";
            for (int i = 0; i < 48; i++)
            {
                cout << "--" ;
            }
            cout << "\n ";
            cn = cn->next;
            sn = sn->next;
            tn = tn->next;
        }
    }
    void bookg(int people)
    {
    	fstream d;
	    d.open("detailg.txt",ios::out|ios::in|ios::app);
        int floor, room;
        cout << "\nEnter the floor number : ";
        cin >> floor;
        d<<"floor number:"<<floor<<endl;
        try
        {
            if (floor < 0 || floor > 4)

            {
                throw(floor);
            }
            cn = header[floor - 1];

            cout << "\nEnter the room number : ";
            cin >> room;
            d<<"room number:"<<room<<endl;
            try
            {

                if (room < 0 || room > 10)
                {
                    throw(room);
                }
                else
                {
                    int i = 1;
                    while (i < room)
                    {
                        cn = cn->next;
                        i++;
                    }
                    if (cn->num >= people)
                    {
                        cout << "\nroom is vacant you can apply for room" ;

                        int count = 0;
                        while (cn->fill - 1 <= cn->num)
                        {

                            //cout << "\nEnter name "<< cn -> fill + 1 << " : ";
                            namesg();
                            cin >> cn->name[cn->fill];
                            count++;
                            cn->fill++;
                            if (count >= people)
                            {
                                break;
                            }
                        }
                        cn->num = cn->num - people;
                    }

                    else
                    {
                        cout << "\nroom is not vacant... SORRY !!!";
                    }
                }
            }
            catch (int r)
            {
                cout << "\ninvalid room number : "<< r;
            }
        }
        catch (int r)
        {
            cout << " \ninvalid floor number : " << r;
        }
    }
    void cancleg(int check)
    {
        char namecheck[10];
        int flag = 0;
        int room, i = 1;
        try
        {
            if (check < 0 || check > 4)

            {
                throw(check);
            }
            else
            {
                cout << " Enter the room no : ";
                cin >> room;
                try
                {
                    if (room < 0 || room > 10)
                    {
                        throw(room);
                    }
                    else
                    {
                        cout << " Enter the name to be delete :";

                        cin >> namecheck;
                        cn = header[check - 1];
                        while (i < room)
                        {
                            cn = cn->next;
                            i++;
                        }
                        i = 0;
                        while (i < 3)
                        {

                            if (!strcmp(namecheck, cn -> name[i]))

                            {
                                flag = 1;
                                break;
                                i = 0;
                            }
                            else
                                i++;
                        }
                        if (flag == 1 && cn->fill != 0)
                        {
                            cout << "\nrecord deleted : "<< cn -> name[i];

                            cn->name[i][0] ='A';
                            cn->name[i][1] ='\0';
                            cn->fill--;
                            cn->num++;
                        }
                        else

                            cout << "\nrecord not present ";
                    }
                }
                catch (int r)
                {
                    cout << "\ninvalid room number : " << r;
                }
            }
        }

        catch (int r)

        {
            cout << " \n floor dosn't exist : " << r;
        }
    }
    void upgradeg(int check)
    {
        char namecheck[10];
        int room, i = 1;
        try
        {
            if (check < 0 || check > 4)

            {
                throw(check);
            }
            else
            {
                cout << " Enter the room no : ";
                cin >> room;
                try
                {
                    if (room < 0 || room > 10)

                    {
                        throw(room);
                    }
                    else
                    {
                        cout << "Enter the name to be updated :";

                        cin >> namecheck;
                        cn = header[check - 1];
                        while (i < room)
                        {
                            cn = cn->next;
                            i++;
                        }
                        i = 0;
                        while (i < 3)
                        {
                            if (!strcmp(namecheck, cn -> name[i]))

                            {
                                cout << "\nenter updated name : " ;

                                cin >> cn->name[i];
                                break;
                            }
                            else
                                i++;
                        }
                        if (i >= 3)
                            cout << "record not found ";
                        else
                        {
                            cout << "\nrecord updated\nprevious name : "<< namecheck << "\nupdated name : "<< cn->name[i];
                        }
                    }
                }
                catch (int r)
                {
                    cout << "\ninvalid room number : "<< r;
                }
            }
        }

        catch (int r)

        {
            cout << "\n floor dosn't exist : "<< r;
        }
    }
};
int main(){
	cout<<"***********************************HOSTEL MANAGEMENT*********************************"<<endl;
	int n;
   	cout<<"choose your choice:"<<endl;
	cout<<"      1-TO LOGIN AS WARDEN  "<<endl;
	cout<<"      2-TO LOGIN AS STUDENT "<<endl;
	cin>>n;
	int no;
	string pa;
	if(n==1){
		    //string pa;
			cout<<"enter the password";
			cin>>pa;
			if(pa=="123warden"){
				cout<<"congragulation your password is succeeded\n";
				cout<<"1-BOYSHOSTEL:\n";
	            cout<<"2-GIRLSHOSTEL:\n";
            	cout<<"ENTER YOUR CHOICE:";
            	cin>>no;
			}
			else{
			cout<<"sorry! wrong password"<<endl;
			cout<<"please try again!"<<endl;	
	}
}
	roomghostel ob;
    int key;
    char ch;
    int floorcheck;
    ob.create();
    if(no==1&&pa=="123warden"){
    do
    {
        cout << "1.Book a room for 1 person\n2.Book a room for 2 person\n3.Book a room for 3 person\n4.Display the current status of rooms\n5.Cancel Book\n6.Update current room\n7.mess details\n8.fee details\n9.student compliant"<< endl;
        cout << " Enter your choice : "   ;
        cin >> key;
        switch (key)
        {
        case 1:
        {
            ob.book(1);
            //ob.names();
            break;
        }
        case 2:
        {
            ob.book(2);
            break;
        }
        case 3:
        {
            ob.book(3);
            break;
        } 
        case 4:
        {
            ob.display();
            break;
        }
        case 5:
        {
            cout << "Enter floor number : ";
            cin >> floorcheck;
            ob.cancle(floorcheck);
            break;
        }
        case 6:
        {
            cout << "Enter floor number : ";
            cin >> floorcheck;
            ob.upgrade(floorcheck);
            break;
        }
        case 7:
        	{
        		int ans;
        		cout<<"1-veg\n";
        		cout<<"2-non veg\n";
        		cin>>ans;
        		if(ans==1){
        		ob.mess1();
        	}
        	else
        	{
        		ob.mess2();
			}
        		break;
			}
			case 8:
				{
					ob.fees();
					break;
				}
		case 9:
				{
					if(n==1)
					{
					ob.complaint();
			    	}
					break;
				}

        default:
            cout << "\nInvalid choice ";
        }
        cout << "\nDo you want to continue(Y / N) ";
        cin >> ch;
    } while (ch =='Y'|| ch =='y');
}
if(no==2){
    int key;
    char ch;
     char channels;
    int floorcheck;
    ob.createg();
    do
    {
        cout << "1.Book a room for 1 person\n2.Book a room for 2 person\n3.Book a room for 3 person\n4.Display the current status of rooms\n5.Cancel Book\n6.Update current room\n7.mess details\n8.fee details\n9.student compliant"<<endl;
        cout << " Enter your choice: ";
        cin >> key;
        switch (key)
        {
        case 1:
        {
            ob.book(1);
            break;
        }
        case 2:
        {
            ob.book(2);
            break;
        }
        case 3:
        {
            ob.book(3);
            break;
        }
        case 4:
        {
            ob.display();
            break;
        }
        case 5:
        {
            cout << "Enter floor number : ";
            cin >> floorcheck;
            ob.cancleg(floorcheck);
            break;
        }
        case 6:
        {
            cout << "Enter floor number : ";
            cin >> floorcheck;
            ob.upgradeg(floorcheck);
            break;
        }

        
        case 7:
        	{
        		int ansg;
        		cout<<"1-veg\n";
        		cout<<"2-non veg\n";
        		cin>>ansg;
        		if(ansg==1){
        		ob.mess1g();
        	}
        	else
        	{
        		ob.mess2g();
			}
        		break;
			}
			case 8:
				{
					ob.feesg();
					break;
				}
		case 9:
				{
					if(n==1)
					{
					ob.complaintg();
			    	}
					break;
				}

        default:
            cout << "\nInvalid choice ";
        }
        cout << "\nDo you want to continue(Y / N) ";
        cin >> channels;
    } while (channels =='Y'|| channels =='y');
}
if(n==2){
	char ch;
	int choice;
	do{
	cout<<"1.mess details\n2.fee details\n3.student compliant"<< endl;
	cout<<"Enter your choice:";
	cin>>choice;
	switch(choice){
		case 1:
			int ans1;
        		cout<<"1-veg\n";
        		cout<<"2-non veg\n";
        		cin>>ans1;
        		if(ans1==1){
        		ob.messb();
        	}
        	else
        	{
        		ob.messa();
			}
        		break;
        	
        case 2:
		    ob.fees2();
			break;
		case 3:
			ob.complaint1();
			break;
		default:
		   		cout << "\nInvalid choice ";
        }
        cout << "\nDo you want to continue(Y / N) ";
        cin >> ch;
    }while (ch =='Y'|| ch =='y');
	}
}



