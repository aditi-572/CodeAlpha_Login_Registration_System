#include <iostream>
#include <fstream>
#include<string>
using namespace std;

void registerUser(){


cout<<"\n=====REGISTATION=====\n";
  string username;
  cout << "Enter the username : ";
  getline(cin >> ws, username);
  
  //Check weather that username is valid or not
  
  if(username.empty()){
    cout<<"Username can't be empty! \n";
    return ;
  }
  
  
  string password;
  cout << "Enter the password : ";
  cin >> password;
  
  //Check weather that password is valid or not
  
  if(password.empty()){
    cout<<"Password can't be empty! \n";
    return ;  
  }
  
  // To check that the username already exists or not
  ifstream readFile("users.txt");
  
  string existingUsername;
  string existingPassword;
  
  while(readFile >> existingUsername >> existingPassword)
{
  if (existingUsername == username)
  {
    cout<<"-----Username already exists!-----"<<endl;
    readFile.close();
  return;
}}
readFile.close();

//Store new user 
ofstream file("users.txt", ios::app);

file << username << endl;
file << password << endl;

file.close();

cout<<"-----Registration Successful----- "<<endl;
}


//Login Function 

void loginUser()
{
  string username;
  string password;

  cout<<"\n=====LOGIN=====\n";

cout<<"Enter username : ";
cin>>username;

cout<<"Enter password : ";
cin>>password;

ifstream file("users.txt");

string storedUsername; 
string storedPassword; 

bool loginSuccessful = false;

while(file>> storedUsername >> storedPassword){
  if(storedUsername == username && storedPassword == password){
    loginSuccessful = true;
    break;
  }
}
file.close();

if(loginSuccessful){
  cout<<"-----Login successful!-----" <<"\n";
}
else{
  cout<<"-----Invalid username or password!-----\n";
}
}

int main(){
  int choice;

  while(true){
    cout <<"\n===================================\n";
    cout<<"  LOGIN & REGISTRATION SYSTEM\n";
    cout <<"===================================\n";

    cout<<"1.Register\n";
    cout<<"2.Login\n";
    cout<<"3.Exit\n";
     
    cout<<"Enter your choice : ";
    cin>>choice;

    if(choice ==1){
      registerUser();
    }
    else if (choice ==2){
      loginUser();
    }
    else if(choice == 3){
cout<<"Thank You for using the system!\n";
break;
    }
    else{
      cout<<"Invalid choice! Please try again.\n";
    }
  }
  return 0 ;
}