#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<cstring>
using namespace std;

struct Seats{
			int rowNo;
			char seatCatogery;
			char seat[6];
		};
class Flight{
	private:
		string flightNo;
		string dateAndTime;
		string departureAirport;
		string arrivalAirport;
		int noOfRows;
		struct Seats s[60];
		
	public:
		void setFlightNo(string line);
		void setDateAndTime(string line);
		void setDepartureAirport(string line);
		void setArrivalAirport(string line);
		void setseats(int i,int r, char c, string s);//strlen(seat)
		void seatSeatCount(int a)
		{
			noOfRows=a;
		}
		void display(int count)
		{
				//cout<<endl;
			int noOfSeatsB=0;
			int noOfSeatsE=0;
			cout<<flightNo<<endl;
			cout<<dateAndTime<<endl;
			cout<<departureAirport<<endl;
			cout<<arrivalAirport<<endl;
			//string flightNo;
			//int p = (sizeof(this->s.seat)/sizeof(*this->s.seat));
			for(int j=0;j<noOfRows;j++)
			{
				cout<<" "<<this->s[j].rowNo;
				cout<<" "<<this->s[j].seatCatogery;
				cout<<" "<<this->s[j].seat<<endl;
				//int q = strlen(seat);
				if(s[j].seatCatogery=='B'){
					noOfSeatsB = noOfSeatsB + strlen(s[j].seat);
				}
				else{
					noOfSeatsE = noOfSeatsE + strlen(s[j].seat);
				}
				
				//cout<<" "<< NoOfSeats;
				
			}
			cout<<"No of seats B:"<<noOfSeatsB<<endl;
			cout<<"No of seats E:"<<noOfSeatsE<<endl;
			cout<<"-----------------------"<<endl;
			
			
			
		}
};

void Flight::setFlightNo(string line){
	flightNo = line;
	//cout<<line<<endl;
}
void Flight::setDateAndTime(string line){
	dateAndTime = line;
	//cout<<line<<endl;
}
void Flight::setDepartureAirport(string line){
	departureAirport = line;
	//cout<<line<<endl;
}
void Flight::setArrivalAirport(string line){
	arrivalAirport = line;
	//cout<<line<<endl;
}
void Flight::setseats(int i, int r, char c, string s)
{
	this->s[i].rowNo=r;
	//cout<<" "<<this->s[i].rowNo;
	this->s[i].seatCatogery=c;
	//cout<<" "<<this->s[i].seatCatogery;
	strcpy(this->s[i].seat,s.c_str());
	//cout<<" "<<this->s[i].seat<<endl;
	
}

int main(){
	int count=0;
	int flag=0;
	int f;
	std::string buffer;
	ifstream file;
	file.open("flights.txt",ios::in);
	//cout<<count<<'\n';
	if(file.is_open()){
		while(! file.eof()){
			getline (file,buffer); //get one buffer from the file
			if(buffer==""){
				count++;
			}
			else{
				f++;
			}
		}
		file.close();
    }
    else{
		cout<<"file is not found";
    }
    	//cout<<count<<'\n';
    	string seatno;
    	int flag2=0;
    	int row;
    	char c;
		int lineNo = 0;
		int scount=0;
		//Flight Array[sizeof(Flight)*count];
		Flight Array[count];
		std::string line;
	    ifstream dataset;
	    dataset.open("flights.txt",ios::in);
	    dataset.clear();
		dataset.seekg(0, ios::beg);
	    if(dataset.is_open()){
		while(! dataset.eof()){
			getline (dataset,line);
			//cout<<line<<endl; //get one line from the file
			lineNo++;
			if(line==""){
				Array[flag].seatSeatCount(flag2);
				flag++;
				flag2=0;
				lineNo = 0;
				//cout<<"--------------------\n";
			}
			else if(lineNo==1){
				Array[flag].setFlightNo(line);
			}
			else if(lineNo==2){
				Array[flag].setDateAndTime(line);
			}
			else if(lineNo==3){
				Array[flag].setDepartureAirport(line);
			}
			else if(lineNo==4){
				Array[flag].setArrivalAirport(line);
			}
			else
			{
				istringstream iss(line);
				if(iss>>row>>c>>seatno)
				{
					Array[flag].setseats(flag2,row,c,seatno);
					flag2++;
				}
			}
			//cout<<line<< '\n';
		}
		dataset.close();
		
	}
	else{
		cout<<"file is not found";
    }
    //cout<<endl<<endl<<endl;
		for(int i=0;i<count;i++)
		{
			Array[i].display( count);
			
		}
	
}



