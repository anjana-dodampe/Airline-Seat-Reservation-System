#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>


using namespace std;

//Global Variables
int opt;
	int lcount = 0;

void displayAvailableFlights();
void viewFlight();
void setCount();



//Structure for Seat Arrangements
struct seat{
    int row_Num;
    char seat_class;
    char seat[6];
};

//Flight Class
class Flight{

	private:
		string m_flightNo;
		string m_depTime;
		string m_depAir;
		string m_arrAir;
		int rows;
		struct seat m_seat[60];


	public:
		void setFlightNo(string temp);
		void setDepTime(string temp);
		void setDepAir(string temp);
		void setArrAir(string temp);
		void setSeats(int i, int rw, char cl, string s);

		void seatCount(int x){
			rows = x;
		}

		void display(int size){

				int bseatCount=0;
				int eseatCount=0;

				cout <<"Flight No:"<<m_flightNo<<endl;
				cout <<"Departure Date  & Time : "<<m_depTime<<endl;
				cout <<"Departure Airport : "<<m_depAir<<endl;
				cout <<"Arrival Airport : "<<m_arrAir<<endl;
				cout << "Available Seats :"<<endl;


				for(int j=0; j<rows ; j++){

					cout<<"\t"<<"\t"<<this->m_seat[j].row_Num;
					cout<<"\t"<<"\t"<<this->m_seat[j].seat_class;
					cout<<"\t"<<"\t"<<this->m_seat[j].seat<<endl;

					if(m_seat[j].seat_class == 'B'){
						bseatCount = bseatCount + strlen(m_seat[j].seat);
					}
					else{
						eseatCount = eseatCount + strlen(m_seat[j].seat);
					}

				}
    						cout << "No. of Seats available in Economy Class : " << bseatCount<<endl;
    						cout << "No. of Seats available in Buisnes Class : " << eseatCount<<endl;

    						cout<<"--------------------------------------------------------------------------------------"<<"\n";
}
};

	//Setter Functions

		void Flight::setFlightNo(string temp){
			m_flightNo = temp;
		}

		void Flight::setDepTime(string temp){
			m_depTime = temp;
		}

		void Flight::setDepAir(string temp){
			m_depAir = temp;
		}

		void Flight::setArrAir(string temp){
			m_arrAir = temp;
		}

		void Flight::setSeats(int i, int rw, char cl, string str){
			this->m_seat[i].row_Num = rw;
			this->m_seat[i].seat_class = cl;
			strcpy(this->m_seat[i].seat, str.c_str());

		}


int main()
{
	 //Get Blank space Count
     int size = 0;
     int dump;
     string str_temp;
     ifstream fin;
     fin.open("flights.txt", ios::in);
     if(fin.is_open()){

   		  while(!fin.eof())
     		{
       			  getline(fin, str_temp);
       			  if(str_temp=="")
        		 {
           			  size++;
        		 }else{
        	 		dump++;
				 }
    	 	 }
     		fin.close();
     }
     else{
     	cout<<"File not Found";
	 }

     //cout<<size<<endl;

    Flight obj[size];
	int obIndex =0;
	int line = 0;
	int rwIndex = 0;
	int row;
	char ch;
	string seatNo;
	int count = 0;
		int sum;
	string buffer;
	ifstream theFile;
	theFile.open("flights.txt", ios::in);
	theFile.clear();
	theFile.seekg(0, ios::beg);

if(theFile.is_open()){
        //To get the Line Count of 1 Flight Object
	while(!theFile.eof())
    {
    	getline(theFile, buffer);
    	line++;
		if(buffer=="")
		{
			obj[count].seatCount(rwIndex);

			lcount=line;
			rwIndex = 0;
			line = 0;
			count++;

		}
		else if(line==1){
		    obj[count].setFlightNo(buffer);
		}
		else if(line ==2){
			obj[count].setDepTime(buffer);
		}
		else if(line ==3){
			obj[count].setDepAir(buffer);
		}
		else if(line ==4){
			obj[count].setArrAir(buffer);
		}
        else
        {
                //if(buffer!=""){
                    istringstream iss(buffer);
                    if(iss >> row >> ch >> seatNo){
                    	obj[count].setSeats(rwIndex, row, ch, seatNo);
                    	 rwIndex++;

                    }
                //}
        }
    }

    theFile.close();

}
    else{
        cout<<"File doesn't Open!";
    }
















	while(1){

	cout<<"**************Select Your Option***************"<<endl;
	cout<<"1. Display available Flights  "<<endl;
	cout<<"2. View Flight  "<<endl;
	cout<<"3. Seat Availability  "<<endl;
	cout<<"4. Seat Booking  "<<endl;
	cout<<"-----------------------------------------------"<<endl;
	cout<<"Enter your Option Number:";
	cin>>opt;
    switch(opt){

    case 1: for(int i=0; i<size ; i++)
	       {
		    obj[i].display( size);
	       }
	       break;



    }

	return 0;
    }
}
