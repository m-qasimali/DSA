#include<iostream>
using namespace std;

class RideNode{
    public :
        int charges;
        string riderName;
        int distance;
        RideNode *next;


        RideNode(int charges, string riderName, int distance){
            this->charges = charges;
            this->riderName = riderName;
            this->distance = distance;
            next = NULL;
        }
};
class Rides{
    public :
        int totalRides;
        int totalEarning;
        RideNode *headRide;
        RideNode *tailRide;

        Rides(){
            headRide = NULL;
            tailRide = NULL;
            totalRides = 0;
            totalEarning = 0;
        }
        RideNode* addNode(){
            cout<<"Enter Rider Name : ";
            string riderName;
            getline(cin,riderName);
            cout<<"Enter Ride Charges : ";
            int rideCharges;
            cin>>rideCharges;
            cout<<"Enter Distance : ";
            int distance;
            cin>>distance;
            getchar();
            RideNode *node = new RideNode(rideCharges,riderName,distance);
            if(headRide == NULL){
                headRide = node;
                tailRide = node;
            }
            else{
                tailRide->next = node;
                tailRide = node;
            }
            return node;
        }
    };
class Node{
    public : 
        string driverName;
        string carName;
        int regNumber;
        int carType;
        Node *next;
        Rides *details;

        Node(string driverName, string carName,int regNumber,int carType){
            this->driverName = driverName;
            this->carName = carName;
            this->regNumber = regNumber;
            this->carType = carType;
            next = NULL;
            details = NULL;
        }
};


class LinkedList{
    public :
        Node *head;
        Node *tail;
        int size;

        LinkedList(){
            head = NULL;
            tail = NULL;
            size = 0;
        }


        void registerCar(){
            bool ctrl =true;
            while(ctrl){
                cout<<"Enter Driver Name : ";
                string driverName;
                getline(cin,driverName);
                cout<<"Enter Car Name : ";
                string carName;
                getline(cin,carName);
                cout<<"Enter Registration Number : ";
                int regNumber;
                cin>>regNumber;
                cout<<"Enter Car Type : ";
                int carType;
                cin>>carType;


                Node *node = new Node(driverName,carName,regNumber,carType);
                if(head ==NULL){
                    head = tail = node;
                }
                else{
                    tail->next = node;
                    tail = node;
                }
                cout<<"Register Another Car\n1 = Yes \n2 = NO\n";
                int option;
                cin>>option;
                if(option != 1){
                    ctrl = false;
                }
                size++;
                getchar();
            }
        }

        void displayRegisteredCars(){
            Node *temp = head;
            while(temp){
                cout<<"Driver Name : "<<temp->driverName<<"\nCar Name : "<<temp->carName<<"\nCar Registration Number : "<<temp->regNumber<<"\nCar Type : "<<temp->carType<<endl;
                temp = temp->next; 
            }
        }

        int totalRegisteredCars(){
            return size;
        }

        void displayCarType(){
            Node *temp = head;
            while(temp){
                if(temp->carType == 2){
                    cout<<temp->carName<<endl;
                }
                temp = temp->next;
            }
        }

        void addRides(){
            bool ctrl =true;
            while(ctrl){
                cout<<"Enter Car Registration :";
                int regNumber;
                cin>>regNumber;
                getchar();
                Node *temp = head;
                while(temp){
                    if(temp->regNumber==regNumber){
                        if(temp->details == NULL){
                            Rides *r1 = new Rides();
                            RideNode *node = r1->addNode();
                            temp->details = r1;
                            r1->totalRides++;
                            r1->totalEarning = node->charges;
                        }
                        else{
                            RideNode *node = temp->details->addNode();
                            temp->details->totalRides++;
                            temp->details->totalEarning += node->charges;
                        }
                        break;
                    }
                    if(temp == NULL){
                        ctrl = false;
                        cout<<"Car Not found"<<endl;
                    }
                    temp = temp->next;
                }
                if(ctrl){
                    cout<<"Add Another Ride\n1 : YES\n2 : No\n";
                    int option;
                    cout<<"Select Option : ";
                    cin>>option;
                    if(option == 1){
                        ctrl = true;
                    }
                    else{
                        ctrl = false;
                    }
                    getchar();
                }
            }
        }
        int displayTotalRides(){
          Node *temp = head;
          cout<<"Enter Car Number To Check Rides : ";
          int regNum;
          cin>>regNum;
          while(temp){
            if(temp->regNumber == regNum){
                return temp->details->totalRides;
            }
            temp = temp->next;
          }
            return 0;
        }
        int displayCarEarning(){
           cout<<"Enter Registration Number To Check Car Earning : ";
           int regNum;
           cin>>regNum;

           Node *temp = head;
           while(temp){
            if(temp->regNumber == regNum){
                if(temp->details == NULL){
                   return 0;
                }
                else{
                    return temp->details->totalEarning;
                }
                break;
            }
            temp = temp->next;
           }
        }
        void displayRidesDetail(){
            Node *temp = head;
            RideNode *ptr = NULL;
            cout<<"Enter Registration To Chaeck Ride Details : ";
            int regNum;
            cin>>regNum;
            while(temp != NULL){
                if(temp->regNumber == regNum){
                    cout<<"REG NO :"<<temp->regNumber<<endl;
                    if(temp->details != NULL){
                        ptr = temp->details->headRide;
                        while(ptr != NULL){
                            cout<<"Rider Name : "<<ptr->riderName<<endl;
                            ptr = ptr->next;
                        }
                    }
                }
                temp = temp->next;
            }
        }
};
int main(){
    LinkedList l1;
    l1.registerCar();
    l1.displayRegisteredCars();

    cout<<"Total Cars Are : "<<l1.totalRegisteredCars()<<endl;
    l1.displayCarType();
    l1.addRides();

    int res = l1.displayCarEarning();
    cout<<"Total Earnings Are : "<<res<<endl;

    int res1 = l1.displayTotalRides();
    cout<<"Total Rides Are : "<<res1<<endl;

    l1.displayRidesDetail();


    return 0;
}