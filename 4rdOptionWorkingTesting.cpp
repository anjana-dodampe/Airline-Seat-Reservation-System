#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>



using namespace std;

int flightCheck=0;


//Structure for Seat Arrangements
struct seat{
    int row_Num;
    char seat_class;
    char seat[6];
};

//Flight Class
class Flight{

	private:
		
		string m_depTime;
		string m_depAir;
		string m_arrAir;
		int rows;
		struct seat m_seat[60];
		


	public:
		string m_flightNo;
	
		void setFlightNo(string temp);
		void setDepTime(string temp);
		void setDepAir(string temp);
		void setArrAir(string temp);
		void setSeats(int i, int rw, char cl, string s);

		void seatCount(int x){
			rows = x;
		}
//------------------Function for Option 1-------------------------------------------------------
		void displayAvailableFlights(int size){

				int bseatCount=0;
				int eseatCount=0;

				cout <<"Flight No:"<<m_flightNo<<endl;
				cout <<"Departure Date  & Time : "<<m_depTime<<endl;
				cout <<"Departure Airport : "<<m_depAir<<endl;
				cout <<"Arrival Airport : "<<m_arrAir<<endl;
				cout << "Available Seats :"<<endl;


				for(int j=0; j<rows ; j++){

					cout<<"\t"<<"\t"<<m_seat[j].row_Num;
					cout<<"\t"<<"\t"<<m_seat[j].seat_class;
					cout<<"\t"<<"\t"<<m_seat[j].seat<<endl;

					if(m_seat[j].seat_class == 'B'){
						bseatCount = bseatCount + strlen(m_seat[j].seat);
					}
					else{
						eseatCount = eseatCount + strlen(m_seat[j].seat);
					}

				}
    						cout << "No. of Seats available in Economy Class : " << eseatCount<<endl;
    						cout << "No. of Seats available in Buissnes Class : " << bseatCount<<endl;

    						cout<<"--------------------------------------------------------------------------------------"<<"\n";
}
//---------------------------Function for Option 2---------------------------------------------------------------------------
		void viewFlight(){
			
				int bseatCount=0;
				int eseatCount=0;
					cout<<"Available Seats : "<<"\t"<<"Row Number"<<"\t"<<"\t"<<"Class"<<"\t"<<"\t"<<"\t"<<"Seat "<<endl;
					cout<<"                  "<<"\t"<<"----------"<<"\t"<<"\t"<<"------"<<"\t"<<"\t"<<"\t"<<"----- "<<endl;
						for(int j=0; j<rows ; j++){

					cout<<"\t"<<"\t"<<"\t"<<m_seat[j].row_Num;
					cout<<"\t"<<"\t"<<"\t"<<m_seat[j].seat_class;
					cout<<"\t"<<"\t"<<"\t"<<m_seat[j].seat<<endl;
					
					if(m_seat[j].seat_class == 'B'){
						bseatCount = bseatCount + strlen(m_seat[j].seat);
					}
					else{
						eseatCount = eseatCount + strlen(m_seat[j].seat);
					}

				}
					cout << "Seats available in Economy Class : " << eseatCount<<endl;
    						cout << "Seats available in Buissnes Class : " << bseatCount<<endl;
					cout <<"Departure Date  & Time : "<<m_depTime<<endl;
					cout <<"Departure Airport : "<<m_depAir<<endl;
					cout <<"Arrival Airport : "<<m_arrAir<<endl;
					cout<<endl;
				}
//-----------------------------------Function for Option 3 ----------------------------------------------------				
			void seatAvailability(string tempFlNo){
					int bseatCount=0;
					int eseatCount=0;
					int reqNoSeats;
					string classType;
					
						cout <<"Enter the Number of Seats Required :";
						cin>>reqNoSeats;
						
						for(int j=0; j<rows ; j++){
							if(m_seat[j].seat_class == 'B'){
						bseatCount = bseatCount + strlen(m_seat[j].seat);
					}
					else{
						eseatCount = eseatCount + strlen(m_seat[j].seat);
					}
				}
				if(reqNoSeats<=(bseatCount + eseatCount) ){
						cout<<"Available Seats : "<<"\t"<<"Row Number"<<"\t"<<"\t"<<"Class"<<"\t"<<"\t"<<"\t"<<"Seat "<<endl;
					cout<<"                  "<<"\t"<<"----------"<<"\t"<<"\t"<<"------"<<"\t"<<"\t"<<"\t"<<"----- "<<endl;
						for(int j=0; j<rows ; j++){

					cout<<"\t"<<"\t"<<"\t"<<m_seat[j].row_Num;
					cout<<"\t"<<"\t"<<"\t"<<m_seat[j].seat_class;
					cout<<"\t"<<"\t"<<"\t"<<m_seat[j].seat<<endl;
				}
					cout << "No. of Seats available in Economy Class (E) : " << eseatCount<<endl;
    				cout << "No. of Seats available in Buissnes Class (B) : " << bseatCount<<endl;
				
					cout<<endl;
				}else{
					cout <<endl<<"*!!!Available Seats Count in Flight "<<tempFlNo<<" is insufficient as per your Requested Amount!!!*"<<endl;
				}
			cout<<"\n";
				
			}
			
//----------------------------------------------Function for Option 4 ------------------------------------------------------------
		void seatBooking( string tempFlNo){
			int rowNumber;
			int rwFlag;
			char pickSeat=0;
			int bookedSeat=0;
			int flag=0;
			int flag2=0;
			
			cout<<"Available Seats : "<<"\t"<<"Row Number"<<"\t"<<"\t"<<"Class"<<"\t"<<"\t"<<"\t"<<"Seats Available "<<endl;
					cout<<"                  "<<"\t"<<"----------"<<"\t"<<"\t"<<"------"<<"\t"<<"\t"<<"\t"<<"-------------- "<<endl;
						for(int j=0; j<rows ; j++){

					cout<<"\t"<<"\t"<<"\t"<<m_seat[j].row_Num;
					cout<<"\t"<<"\t"<<"\t"<<m_seat[j].seat_class;
					cout<<"\t"<<"\t"<<"\t"<<m_seat[j].seat<<endl;
				}
				cout<<"------------------------------------------------------------------------------------------------"<<endl;
			
				cout << "To Start Booking, As your preference - >"<<endl;
			cout << "Enter the Row Number :";
			cin>>rowNumber;
			
			    
//				cout<<"Available Seats : "<<"\t"<<"Row Number"<<"\t"<<"\t"<<"Class"<<"\t"<<"\t"<<"\t"<<"Seat "<<endl;
//					cout<<"                  "<<"\t"<<"----------"<<"\t"<<"\t"<<"------"<<"\t"<<"\t"<<"\t"<<"----- "<<endl;
				for(int j=0; j<rows ; j++){

//					cout<<"\t"<<"\t"<<"\t"<<m_seat[j].row_Num;
//					cout<<"\t"<<"\t"<<"\t"<<m_seat[j].seat_class;
//					cout<<"\t"<<"\t"<<"\t"<<m_seat[j].seat<<endl;
					
					if(rowNumber == m_seat[j].row_Num){
						rwFlag = j;
						flag=0;
						break;
					}else{
						flag++;  //To catch the invalid values
					}
				
				}
				if(flag>0){
				cout<<"*****************************Invalid Entry!!!**************************"<<endl;
				return;//Exit the Function
				
			    }
				
				
				
		    cout<<"------------------------------------------------------------------------------------------------"<<endl;
			
			cout<<"Selected Row : "<<"\t"<<"Row Number"<<"\t"<<"\t"<<"Class"<<"\t"<<"\t"<<"\t"<<"Seats Available "<<endl;
			cout<<"               "<<"\t"<<"----------"<<"\t"<<"\t"<<"------"<<"\t"<<"\t"<<"\t"<<"------------------ "<<endl;
			cout<<"\t"<<"\t"<<"     "<<m_seat[rwFlag].row_Num;
			cout<<"\t"<<"\t"<<"           "<<m_seat[rwFlag].seat_class;
			cout<<"\t"<<"\t"<<"        "<<m_seat[rwFlag].seat<<endl;
			
		    cout<<"------------------------------------------------------------------------------------------------"<<endl;
			
			cout << "Select the Seat You Prefered from the Available seats :";
			cin>>pickSeat;
			int letterCount;
			letterCount = strlen(m_seat[rwFlag].seat);
		
			for(int i=0; i<letterCount; i++){
				
					if(m_seat[rwFlag].seat[i]==pickSeat ){
							
							m_seat[rwFlag].seat[i] = ' ';
								flag2=0;
								break;
					}else{
						flag2++;
					}
		
			}	
				if(flag2>0){
				cout<<"*****************************Invalid Entry!!!**************************"<<endl;
				return;//Exit the Function
				
			    }
			
			cout<<"------------------------------------------------------------------------------------------------"<<endl;
			cout<<"******You have Successfully Booked Seat "<<pickSeat<<" in Row "<<rowNumber<<" in Flight "<<tempFlNo<<"******"<<endl;
			cout<<"------------------------------------------------------------------------------------------------"<<endl;
			cout<<"Currently available Seating Composition of Flight "<<tempFlNo<<endl;
				cout<<"                  : "<<"\t"<<"Row Number"<<"\t"<<"\t"<<"Class"<<"\t"<<"\t"<<"\t"<<"Seat "<<endl;
					cout<<"                  "<<"\t"<<"----------"<<"\t"<<"\t"<<"------"<<"\t"<<"\t"<<"\t"<<"----- "<<endl;
						for(int j=0; j<rows ; j++){

					cout<<"\t"<<"\t"<<"\t"<<m_seat[j].row_Num;
					cout<<"\t"<<"\t"<<"\t"<<m_seat[j].seat_class;
					cout<<"\t"<<"\t"<<"\t"<<m_seat[j].seat<<endl;
				}
				cout<<"------------------------------------------------------------------------------------------------"<<endl;
		
			
			
			
		}
			
		

};

//-------------------------------Setter Functions-------------------------------------------------------

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
	int opt;
	

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
	cout<<"5. Exit  "<<endl;
	cout<<"-----------------------------------------------"<<endl;
	cout<<"Enter your Option Number:";
	cin>>opt;
	
string inFlightNo;


    switch(opt){

    case 1: {
			for(int i=0; i<size ; i++)
	       {
		    obj[i].displayAvailableFlights( size);
	       }
	       break;
	       }
	       
	case 2: {

				int flag=0;
			
			cout <<"Insert the Flight Number :";
			cin>>inFlightNo;
			cout<<"\n";
			
			 for(int i=0; i<size ; i++)
	       {
	       		if(inFlightNo == obj[i].m_flightNo){
		   			 obj[i].viewFlight();
		   			 flag=0;
		   			 break;
	       		}
				else{
	       			flag++;
				}
	       	
		   }
		   	if(flag>0)
	       		{
	       			cout <<"\n"<<"Flight is Unavailable!"<<endl;
	       			cout<<"\n";
				}
		  	 break;
			}
		   
	case 3:{
				int flag=0;
			cout <<"Insert the Flight Number :";
			cin>>inFlightNo;
		
			
			 for(int i=0; i<size ; i++)
	       {
	       		if(inFlightNo == obj[i].m_flightNo){
		   			 obj[i].seatAvailability(inFlightNo);
		   			 flag=0;
		   			 break;
	       		}
				else{
	       			flag++;
				}
	       	
		   }
		   	if(flag>0)
	       		{
	       			cout <<"\n"<<"Flight is Unavailable!"<<endl;
	       			cout<<"\n";
				}
		   		break;
			}
			
	case 4 :{
			int flag=0;
			cout <<"Insert the Flight Number :";
			cin>>inFlightNo;
		
			
			 for(int i=0; i<size ; i++)
	       {
	       		if(inFlightNo == obj[i].m_flightNo){
		   			 obj[i].seatBooking(inFlightNo);
		   			 flag=0;
		   			 break;
	       		}
				else{
	       			flag++;
				}
	       	
		   }
		   	if(flag>0)
	       		{
	       			cout <<"\n"<<"Flight is Unavailable!"<<endl;
	       			cout<<"\n";
				}
		   	
		
		
		
		
		
		break;
	}
	
	





    }
}
	return 0;
    }

