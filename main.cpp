#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using std::string;



class Date {
  private:
  int day;
  int month;
  int year;

  public:

  Date(int day, int month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;
  }
  int getday() { return day; }
  int getmonth() { return month; }
  int getyear() { return year; }
};

//comparing dates
bool operator<(const Date& lhs, const Date& rhs) {

  if (year < rhs.getyear()) {
    return true;
  } else if (lhs.getyear() == rhs.getyear() &&
	     lhs.getmonth() < rhs.getmonth()) {
    return true;
  } else if (lhs.getyear() == rhs.getyear() &&
	     lhs.getmonth() == rhs.getmonth() &&
	     lhs.getday() < rhs.getday()) {
    return true;
  }

  return false;
}

//printing dates
std::ostream& operator<<(std::ostream& out ,
			 Date date) {
  out << date.getday << '-' << date.getmonth << '-'
      << date.getyear();
  return out;
}

class Person{
private:
    string name;
    string address;
    string email;

public:
string getName(){
    return name;
};

void setName(string n){
name = n;
};

string getAddress(){
    return address;
};

void setAddress(string a){
address = a;
};

string getEmail(){
    return email;
};

void setEmail(string e){
email = e;
};

};

class Librarian:Person{
private:
    int staffid;
    string name;
    string address;
    string email;
    int salary;

public:
Librarian(int id, string n, string a, string e, int s){
    staffid = id;
    name = n;
    address = a;
    email = e;
    salary = s;
}

void addMember(){

};

int getStaffID(){
    return staffid;
};

void setStaffID(int id){
staffid = id;
};

int getSalary(){
    return salary;
};

void setSalary(int s){
salary = s;
};
};

class Member:Person{
private:
    int memberid;
    
};

int main() {
    
    std::ifstream inputFile("library_books.csv");

    
    if (!inputFile.is_open()) {
        std::cerr << "Error opening the file." << std::endl;
        return 1; 
    }

    
    std::string line;
    std::vector<std::string> tokens;

    
    while (std::getline(inputFile, line)) {
        
        std::stringstream ss(line);
        std::string token;

        
        while (std::getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        
        for (const auto& t : tokens) {
            std::cout << t << " | ";
        }

        
        tokens.clear();

        std::cout << std::endl;
    }

    
    inputFile.close();

        
    std::string userInput;

    
    std::cout << "Enter a string: ";

    
    std::getline(std::cin, userInput);

    
    std::cout << "You entered: " << userInput << std::endl;

    return 0;
}
