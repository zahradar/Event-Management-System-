#include<iostream>
#include <cstdlib> 
#include<string>
using namespace std;
void clearScreen() {
	// Clear screen:
    system("cls"); 
    }
    // to change the colour :
void changeColor(string colorCode) {
    string command = "color " + colorCode;
    system(command.c_str());}

struct Event {
	string name;
    string time;
    string date;
    string location;
    int budget;
    double foodCost;
    double lightingCost;
    double decorCost;
};

// Function prototypes:
void organizer();
void customer();
void viewEvent();
void deleteEvent();
void deleteSpecificDetail();
void addEvent();
void manageBudget();
void updateEvent();
void generateSlip();
int  const eventValue=10;
Event evt[eventValue];
int eventCount=0;//track the current number of events
void organizer(){
	    cout << "                                                            ============================================\n";
        cout << "                                                                              ORGANIZER MENU                \n";
        cout << "                                                            ============================================\n";
    int choice;
    do {
                    cout << "1. View Events"<<endl;
                    cout << "2. Delete Event"<<endl;
                    cout << "3. Delete Specific Detail from Event"<<endl;
                    cout << "4. Back to Main Menu"<<endl;
                    cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            viewEvent();
            break;
        case 2:
            deleteEvent();
            break;
        case 3:
            deleteSpecificDetail();
            break;
        case 4:
            return;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);
}

// User Menu
void customer() {
         cout << "                                                     ============================================\n";
         cout << "                                                                     CUSTOMER MENU                \n";
        cout << "                                                      ============================================\n";
    int choice;
    
    do {
         
                        cout << "1. Add Event\n";
                        cout << "2. Update Event\n";
                        cout << "3. View Events\n";
                        cout << "4. Generate Slip\n";
                        cout << "5. Manage Budget\n";
                        cout << "6. Back to Main Menu\n";
                        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addEvent();
            break;
        case 2:
            updateEvent();
            break;
        case 3:
            viewEvent();
            break;
        case 4:
            generateSlip();
            break;
            case 5:
             manageBudget();
             break;
        case 6:
            return;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);
}

void addEvent(){
	if(eventValue>eventCount){  //checks if there's still space in the arrays to add more events
	        cout << "Enter event name: ";
            cin.ignore();  
            getline(cin,evt[eventCount].name);
            cout << "Enter event date (DD/MM/YYYY): ";
            cin>>evt[eventCount].date;    
            cout << "Enter event location: ";
            cin.ignore(); 
            getline(cin,evt[eventCount].location); 
            cout << "Enter event type (Indoor/Outdoor): ";
             cin >> evt[eventCount].time;// Store event name in the current event index
            cout << "Enter food cost: ";
            cin >> evt[eventCount].foodCost;
            cout << "Enter lighting cost: ";
            cin >> evt[eventCount].lightingCost;
            cout << "Enter decor cost: ";
            cin >> evt[eventCount].decorCost;
            evt[eventCount].budget = evt[eventCount].foodCost + evt[eventCount].lightingCost + evt[eventCount].decorCost;
            eventCount++;
    cout << "Event added successfully.\n";
            cout << "Event added successfully!"<<endl;}
            else {
        cout << "Event list is full. Cannot add more events."<<endl;
    }}
    void viewEvent() {
    if (eventCount == 0) { //check if event is added or not
        cout << "No events Added yet\n";
    } else {
        cout << "\nList of Events:\n";
        for (int i = 0; i < eventCount; i++) {  // Loop through all events
            cout << "Event " << i + 1 << ":\n";
            cout << "  Name: " << evt[i].name << "\n";
            cout << "  Date: " << evt[i].date << "\n";
            cout << "Time: " << evt[i].time << "\n";
            cout << "  Location: " << evt[i].location << "\n";
            cout << "  Budget: " << evt[i].budget << "\n";
            cout << "Food Cost: " << evt[i].foodCost << "\n";
            cout << "Lighting Cost: " << evt[i].lightingCost << "\n";
            cout << "Decor Cost: " << evt[i].decorCost << "\n";
            cout << "Total Budget: " << evt[i].budget << "\n";
            cout << "-----------------------------\n";
        }
    }
}
    void updateEvent() {
    if (eventCount == 0) {
        cout << "No events to update." << endl;
    } else {
        int Eventnumber;
        cout << "Enter the event number to update (" << eventCount << "): ";
        cin >> Eventnumber;
        Eventnumber--; // Convert to 0-based index
        if (Eventnumber >= 0 && Eventnumber < eventCount) { //It check Eventnumber is within the range of existing events.
            cout << "Enter new name: ";
            cin.ignore();
            getline(cin,evt[Eventnumber].name);
            cout << "Enter new date (DD/MM/YYYY): ";
            string newDate;
            getline(cin, newDate);
            if (!newDate.empty()) evt[Eventnumber].date = newDate; //Checks if newDate is not empty
            cout << "Enter new location: ";
            string newLocation;
            getline(cin, newLocation);
            if (!newLocation.empty()) evt[Eventnumber].location = newLocation;
            cout << "Enter new food cost: ";
           cin >> evt[Eventnumber].foodCost;
           cout << "Enter new lighting cost: ";
           cin >> evt[Eventnumber].lightingCost;
           cout << "Enter new decor cost: ";
           cin >> evt[Eventnumber].decorCost;
           evt[Eventnumber].budget = evt[Eventnumber].foodCost + evt[Eventnumber].lightingCost + evt[Eventnumber].decorCost;
           cout << "Event updated successfully.\n";
}
            
            cout << "Event updated successfully!" << endl;
        } 
    }

void deleteEvent() {
    if (eventCount == 0) {
        cout << "No events to delete." << endl;
    } else {
        int Eventnumber;
        cout << "Enter the event number to delete (1-" << eventCount << "): ";
        cin >> Eventnumber;
        Eventnumber--; // Convert to 0-based index
        if (Eventnumber>= 0 && Eventnumber < eventCount) {
            for (int i = Eventnumber; i < eventCount - 1; i++) {// shift the events after the deleted one to fill the empty space
               evt[i] = evt[i + 1];

            }
            eventCount--;//Reduces the total number of events by 1 because one event has been deleted.
            cout << "Event deleted successfully!" << endl;
        } else {
            cout << "Invalid event number." << endl;
        }
    }
}
void deleteSpecificDetail() {
    if (eventCount == 0) {
        cout << "No events available.\n";
        return;
    }

    int eventNumber;
    cout << "Enter the event number to modify: ";
    cin >> eventNumber;

    if ( eventNumber < 1 ||  eventNumber > eventCount) {
        cout << "Invalid event number.\n";
        return;
    }

    int detailChoice;
    cout << "What would you like to delete?\n";
    cout << "1. Food Cost\n";
    cout << "2. Lighting Cost\n";
    cout << "3. Decor Cost\n";
    cout << "Enter your choice: ";
    cin >> detailChoice;

    switch (detailChoice) {
    case 1:
        evt[ eventNumber - 1].foodCost = 0;
        break;
    case 2:evt[ eventNumber- 1].lightingCost = 0;
        break;
    case 3:
        evt[ eventNumber - 1].decorCost = 0;
        break;
    default:
        cout << "Invalid choice.\n";
        return;
    }

    evt[ eventNumber - 1].budget = evt[ eventNumber - 1].foodCost + evt[ eventNumber - 1].lightingCost + evt[ eventNumber - 1].decorCost;
    cout << "Detail deleted successfully.\n";
}
void manageBudget() {
    if (eventCount == 0) {
        cout << "No events to manage budgets." << endl;
    } else {
        int Eventnumber;
        cout << "Enter the event number to manage budget" << eventCount ;
        cin >> Eventnumber;
        Eventnumber--; // Convert to 0-based index
        if (Eventnumber >= 0 && Eventnumber < eventCount) {//It check Eventnumber is within the range of existing events.
            cout << "Current budget for Event " << Eventnumber + 1 << " is " << evt[Eventnumber].budget << endl;
            cout << "Enter new budget Rs:    ";
            cin >> evt[Eventnumber].budget;
            cout << "Budget updated successfully!" << endl;
        } else {
            cout << "Invalid event number. please try again later!" << endl;
        }
    }
}
void generateSlip() {
    if (eventCount == 0) {
        cout << "No events available.\n";
        return;
    }

    int EventNumber;
    cout << "Enter the event number to generate slip for: ";
    cin >> EventNumber;

    if (EventNumber < 1 || EventNumber > eventCount) {
        cout << "Invalid event number.\n";
        return;
    }

    Event &event = evt[EventNumber - 1];
    cout << "\nEvent Slip:\n";
    cout << "Name: " << event.name << "\n";
    cout << "Type: " << event.time << "\n";
    cout << "Date: " << event.date << "\n";
    cout << "Time: " << event.time << "\n";
    cout << "Food Cost: " << event.foodCost << "\n";
    cout << "Lighting Cost: " << event.lightingCost << "\n";
    cout << "Decor Cost: " << event.decorCost << "\n";
    cout << "Total Budget: " << event.budget << "\n";
}


int main(){
	changeColor("9F");
	clearScreen();
	cout << "                                           ****************************************************" << endl;
    cout << "                                                                                         " << endl;
    cout << "                                                      WELCOME TO CLASSIC EVENT MANAGEMENT                                                " << endl;
    cout << "                                                                                        " << endl;
    cout << "                                           ****************************************************" << endl;
    cout << "                                                                                         " << endl;
    cout << "                                                     Plan | Organize | Celebrate | Remember           " << endl;
    cout << "                                                                                        " << endl;
    cout << "                                           ****************************************************" << endl;
    cout << "                                         Where every event is an opportunity to create a masterpiece!                         " << endl;
    cout << "                                                      Lets create moments that last forever                        " << endl;
    cout << "                                                               Planning with passion                                             " << endl;
    cout << "                                            ****************************************************" << endl;
	while(true){
	
    cout<<"                                                                                                 "<<endl;
	cout<<"                                                                    Menu:"<<endl;
    cout<<"                                                                  1.Organizer"<<endl;
    cout<<"                                                                  2.Customer"<<endl;
	cout<<"                                                                  3.Close The System"<<endl;                   
    cout <<"                                                                 Enter your choice: ";
    
    int choice;
	cin >> choice;
	switch(choice){
		case 1:
			clearScreen();
			organizer();
			break;
			case 2:
				clearScreen();
				customer();
				break;
		case 3:
	 clearScreen();
	cout<<"                                                             ********************************"<<endl;
    cout<<"                                                        Thank you for using the event management system!";
    cout<<"                                                                                                                            ********************************"<<endl;
								return 0;
								break;
			default :
			cout<<"invaild command";
		}
	}
	return 0;
	
}