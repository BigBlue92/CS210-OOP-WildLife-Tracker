/* Ryan Mackenzie
 * August 15th, 2020
 * SNHU CS-210-T6594
 * TheZoo Project 3
 */



#include <iostream>
#include <jni.h>
#include <fstream>
#include <string>
#include <iomanip>
#include <exception>
#include <vector>
#include "Animal.h"
#include "Mammal.h"
#include "Oviparous.h"
using namespace std;
vector <Animal> animals;

void GenerateData()               //DO NOT TOUCH CODE IN THIS METHOD
{
     JavaVM *jvm;                      // Pointer to the JVM (Java Virtual Machine)
     JNIEnv *env;                      // Pointer to native interface
                                                              //================== prepare loading of Java VM ============================
     JavaVMInitArgs vm_args;                        // Initialization arguments
     JavaVMOption* options = new JavaVMOption[1];   // JVM invocation options
     options[0].optionString = (char*) "-Djava.class.path=";   // where to find java .class
     vm_args.version = JNI_VERSION_1_6;             // minimum Java version
     vm_args.nOptions = 1;                          // number of options
     vm_args.options = options;
     vm_args.ignoreUnrecognized = false;     // invalid options make the JVM init fail
                                                                          //=============== load and initialize Java VM and JNI interface =============
     jint rc = JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);  // YES !!
     delete options;    // we then no longer need the initialisation options.
     if (rc != JNI_OK) {
            // TO DO: error processing...
            cin.get();
            exit(EXIT_FAILURE);
     }
     //=============== Display JVM version =======================================
     cout << "JVM load succeeded: Version ";
     jint ver = env->GetVersion();
     cout << ((ver >> 16) & 0x0f) << "." << (ver & 0x0f) << endl;

     jclass cls2 = env->FindClass("ZooFileWriter");  // try to find the class
     if (cls2 == nullptr) {
            cerr << "ERROR: class not found !";
     }
     else {                                  // if class found, continue
            cout << "Class MyTest found" << endl;
            jmethodID mid = env->GetStaticMethodID(cls2, "createZooFile", "()V");  // find method
            if (mid == nullptr)
                   cerr << "ERROR: method void createZooFile() not found !" << endl;
            else {
                   env->CallStaticVoidMethod(cls2, mid);                      // call method
                   cout << endl;
            }
     }
     jvm->DestroyJavaVM();
     cin.get();
}

//Returns false if the string input has a letter in it. For validation of track #.
bool ValidateStringNum(string str) {
   for (unsigned int i = 0; i < str.length(); i++){
	   if (isdigit(str[i]) == false){
		   return false;
	   }
   }
   return true;
}

//Validates the amount of eggs input
int InputEggs() {
    bool valid = false;
    int num = -1;
    do {
        cout << "Enter number of eggs (0-9): " << flush;
        cin >> num;
        if (cin.good() && num < 10 && num > -1){
            valid = true;
        } else {
            //clear steam, invalid input
            cin.clear();
            cin.ignore(INT_MAX,'\n');
            cout << "Invalid input; please re-enter." << endl;
        }
    } while (!valid);
    cin.clear();
    cin.ignore(INT_MAX,'\n');
    return (num);
}

//Validates the input for nursing
int InputNursing() {
    bool valid = false;
    int num = -1;
    do {
        cout << "Nursing? 0 = No, 1 = Yes: " << flush;
        cin >> num;
        if (cin.good() && num < 2 && num > -1){
            valid = true;
        } else {
            //clear steam, invalid input
            cin.clear();
            cin.ignore(INT_MAX,'\n');
            cout << "Invalid input; please re-enter." << endl;
        }
    } while (!valid);
    cin.clear();
    cin.ignore(INT_MAX,'\n');
    return (num);
}

//Validates Name input
string InputName() {
	bool valid = false;
	string name = "";
	    do {
	        cout << "Name (Max 15 chars): " << flush;
	        cin >> name;
	        if (cin.good() && name.size() < 16 && name.size() > 0){
	        	valid = true;
	        	//for loop makes sure no non alphabet characters are entered.
	        	for (unsigned int i = 0; i < name.size(); i++) {
	        		if ((int)(name[i]) < 65 || ((int)(name[i]) > 90 && (int)(name[i]) < 97) || (int)(name[i]) > 122){
	        			valid = false;
	        			cout << "Alphabetical characters only, please try again.\n";
	        			break;
	        		}
	        	}
	        } else {
	            //clear steam, invalid input
	            cin.clear();
	            cin.ignore(INT_MAX,'\n');
	            cout << "Invalid input; please re-enter." << endl;
	        }
	    } while (!valid);
	    cin.clear();
	    cin.ignore(INT_MAX,'\n');
	return (name);
}

//Validates Subtype input
string InputSubtype() {
	bool valid = false;
	string sub = "";
	    do {
	        cout << "Subtype (Max 15 chars): " << flush;
	        cin >> sub;
	        if (cin.good() && sub.size() < 16 && sub.size() > 0){
	        	valid = true;
	        	//for loop makes sure no non alphabet characters are entered.
	        	for (unsigned int i = 0; i < sub.size(); i++) {
	        		if ((int)(sub[i]) < 65 || ((int)(sub[i]) > 90 && (int)(sub[i]) < 97) || (int)(sub[i]) > 122){
	        			valid = false;
	        			cout << "Alphabetical characters only, please try again.\n";
	        			break;
	        		}
	        	}
	        } else {
	            //clear steam, invalid input
	            cin.clear();
	            cin.ignore(INT_MAX,'\n');
	            cout << "Invalid input; please re-enter." << endl;
	        }
	    } while (!valid);
	    cin.clear();
	    cin.ignore(INT_MAX,'\n');
	return (sub);
}

//Validates input type
string InputType() {
	bool valid = false;
	string type = "";
	string ovi = "Oviparous";
	string mam = "Mammal";
	    do {
	        cout << "Type(Mammal or Oviparous only): " << flush;
	        cin >> type;
	        //If the input equals exactly Mammal or Oviparous, continue.
	        if (cin.good() && (type.compare(mam) == 0 || type.compare(ovi) == 0)){
	        	valid = true;
	        } else {
	            //clear steam, invalid input
	            cin.clear();
	            cin.ignore(INT_MAX,'\n');
	            cout << "Invalid input; please re-enter." << endl;
	        }
	    } while (!valid);
	    cin.clear();
	    cin.ignore(INT_MAX,'\n');
	return (type);
}

string InputTrack() {
	bool valid = false;
	string track = "";
	    do {
	        cout << "Track # (6 digits): " << flush;
	        cin >> track;
	        //ValidateStringNum ensures only digits are entered, returns true/false.
	        if (ValidateStringNum(track) && track.size() <= 6){
	        	valid = true;
	        } else {
	            //clear steam, invalid input
	            cin.clear();
	            cin.ignore(INT_MAX,'\n');
	            cout << "Invalid input; please re-enter." << endl;
	        }
	    } while (!valid);
	    cin.clear();
	    cin.ignore(INT_MAX,'\n');
	return (track);
}

void AddAnimal()
{
	cin.clear();
	string track, name, type, subtype;
	int eggs, nursing;
	char save;
	cout << "Please enter a new animal.\n";
	track = InputTrack();
	name = InputName();
	type = InputType();
	subtype = InputSubtype();

	//If else for Mammal or Oviparous. Creates a different object based on that factor.
	if (type.at(0) == 'M' || type.at(0) == 'm'){
		nursing = InputNursing();//validates input
		//Shows the user what they entered and asks them to save if they like.
		cout << "Animal Info\nTrack#: " << track << "  Name: " << name << "  Type: " << type
		     << "  Subtype: " << subtype << "  Nursing: " << nursing << "\nSave? (Y/N)";
		//Ask the user to save, if not returns to the main menu.
		cin >> save;
		if (save == 'y' || save == 'Y') {
			//Creates object and adds it to vector
			Mammal mam;
			mam.SetTrack(track);
			mam.SetName(name);
			mam.SetType(type);
			mam.SetSubtype(subtype);
			mam.SetNurse(nursing);
			animals.push_back(mam);
		} else {
			cout << "Save canceled.\n";
		}
	} else {
		eggs = InputEggs();
		cout << "Animal Info\nTrack#: " << track << "  Name: " << name << "  Type: " << type
		    << "  Subtype: " << subtype << "  Eggs: " << eggs << "\nSave? (Y/N)";
		cin >> save;
	    if (save == 'y' || save == 'Y') {
	    	Oviparous ovi;
	    	ovi.SetTrack(track);
	    	ovi.SetName(name);
	    	ovi.SetType(type);
	    	ovi.SetSubtype(subtype);
	    	ovi.SetEggs(eggs);
	    	animals.push_back(ovi);
	    } else {
	    	cout << "Save canceled.\n";
	    }
	}
}


void RemoveAnimal() {
   // loop through vector to find animal to delete, unless vector is empty.
   if (animals.size() != 0) {
	   string num = "";
	   char save;
	   RemoveAnimalMenu:
	   cout << "Enter 6 digit Track Number with zeros: ";
	   cin >> num;
	   for (unsigned int i = 0; i < animals.size(); i++) {
		   //If the track numbers match, remove.
		   if (num.compare(animals.at(i).GetTrack())== 0) {
			   //Allows the user to cancel.
			   cout << "Are you sure? (Y/N)\n";
			   cin >> save;
			   if (save != 'y' && save != 'Y') {
				   cout << "Delete canceled.\n";
				   break;
			   }
			   cout << "Removing " << animals.at(i).GetName();
			   animals.erase(animals.begin() + i);
			   cout << "\nTrack # " << num << " successfully removed.\n";
			   break;
		   //Else will allow user to try again if they didn't enter a valid track #
		   } else if (i == animals.size() - 1) {
			   cout << "Invalid Track Number" << endl;
			   goto RemoveAnimalMenu;
		   }
	   }
   } else {
	   cout << "No animals to delete. Please select another option.";
   }
}

void LoadDataFromFile(){
	string file = "zoodata.txt";
    ifstream in(file.c_str());
    //Verifies that the file exists
	if(!in){
		cerr << "File does not exist: " << file << endl;
    }
	string str;
	cout <<"Loading the following data: \n";
	//Reads the file by line and finds each value via string index
	while(getline(in,str)){
		string track, name, type, subtype;
		int eggs, nursing;
		cout <<  str << endl;
		if(str.size()>0) {
			track = str.substr(1, 6);//Provided Java code incorrectly produces a 7 digit track #, this fixes it.
			name = str.substr(8, 15);
			type = str.substr(25, 15);
			subtype = str.substr(42, 15);
			int eggs = str.at(59) - '0';//converting a char to an int
			int nursing = str.at(61) - '0';
			//If else creates the proper object type and adds it to the string.
			if (type.at(1) == 'm'||type.at(1) == 'M'){
				Mammal mam;
				mam.SetTrack(track);
				mam.SetName(name);
				mam.SetType(type);
				mam.SetSubtype(subtype);
				mam.SetNurse(nursing);
				animals.push_back(mam);
			} else {
				Oviparous ovi;
			    ovi.SetTrack(track);
			    ovi.SetName(name);
			    ovi.SetType(type);
		        ovi.SetSubtype(subtype);
			    ovi.SetEggs(eggs);
				animals.push_back(ovi);
			}
    	}
	}
	in.close();
}

//This function displays the vector data saved inside the current vector in a formatted table.
void DisplayData() {
	cout << "Track#   |      Name     |     Type     |   Subtype     | Eggs|Nursing|\n";
	for (unsigned int i=0; i < animals.size(); i++)
	   {
	       cout << animals.at(i).GetTrack() << "    " <<  animals.at(i).GetName() << animals.at(i).GetType() <<  animals.at(i).GetSubtype() << " "
	    		<< animals.at(i).GetEggs() << "      " << animals.at(i).GetNurse() << endl;
	   }
}


//Saves current vector data to txt file when called.
void SaveDataToFile()
{
	fstream file;
	string file_name = "zoodata.txt";
	file.open(file_name);
	//validates file exists
    if(file.fail()) {
    	cout << "File does not exist";
    } else if (animals.size() > 0){
		int i = 0;
		int size = animals.size() - 1;
		//While loop iterates through vector and saves each animal object to the txt file.
		while(size >= i) {
			cout << "Saving to file: " << animals[size].GetName() << endl;//Shows the names of the animals being saved.
			file << " " << animals.at(size).GetTrack() << " " << animals.at(size).GetName() << "  " <<  animals.at(size).GetType()
				 << animals.at(size).GetSubtype() << " "<< animals.at(size).GetEggs() << " " <<  animals.at(size).GetNurse() << endl;
		    size--;
		}
		cout << "Save complete.\n";
	} else {
		cout << "No data entered to save, please enter animals.\n";
	}

}


void DisplayMenu()
{
	cout << "Welcome to The Wildlife Zoo Animal Tracker.\n\n";
	int menuChoice;
	menu :
	cout << "Please enter one of the following options:\n"
		 << "---------------------------------------------\n"
	     << "|[1]Load Animal Data     [2]Generate Data   |\n|[3]Display Animal Data  [4]Add Record      |\n"
		 << "|[5]Delete Record        [6]Save Animal Data|\n|                [7] Quit                   |\n"
		 << "---------------------------------------------\n";
	ios init(NULL);
	init.copyfmt(cin);
	cin >> setw(1) >> menuChoice ;// setw prevents the unexpected results from inputs like "1 2"
	cin.copyfmt(init); //resets input formatting to prevent issues further on.
	//clear stream
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	//Selects function based on user input
	switch(menuChoice){
		   case 1:
		       LoadDataFromFile();
		       goto menu;
		   case 2:
		       GenerateData();
		       goto menu;
		   case 3:
		       DisplayData();
		       goto menu;
		   case 4:
		       AddAnimal();
		       goto menu;
		   case 5:
		       RemoveAnimal();
		       goto menu;
		   case 6:
		       SaveDataToFile();
		       goto menu;
		   case 7:
			   cout << "Quitting...";
			   break;
		   default:
			   cout << "Invalid option selected, please enter 1-7.\n\n";//input validation
			   goto menu;
		   }
}



int main()
{
	//Display menu handles all program functions
	DisplayMenu();
	return 1;
}
