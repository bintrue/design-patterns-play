/* GUIFactory example -- */
 
#include<iostream>
using namespace std;


// "Abstract Product A" 
class Button {
public:
        virtual void paint() = 0;
        virtual ~Button(){
        }
};


// "Product A 1" 
class WinButton: public Button {
public:
        void paint() {
                cout << "I'm a WinButton";
        }
};

 
// "Product A 2" 
class OSXButton: public Button {
public:
        void paint() {
                cout << "I'm an OSXButton";
        }
};
 

// "Abstract Product B" 
class GUIFactory {
public:
        virtual Button * createButton() = 0;
        virtual ~GUIFactory(){
        }
};

 
// "Product B 1" 
class WinFactory: public GUIFactory {
public:
        Button * createButton() {
                return new WinButton();
        }
 
        ~WinFactory(){
        }
};
 

// "Product B 2" 
class OSXFactory: public GUIFactory {
public:
        Button * createButton() {
                return new OSXButton();
        }
 
        ~OSXFactory(){
        }
};

 
// "Abstract Factory"
GUIFactory * createOsSpecificFactory() {
        int sys;
        cout << endl << "Enter OS Type(0 - Win, 1 - OSX): ";
        cin >> sys;
 
        if (sys == 0) {
// "Concrete Factory 1"
                return new WinFactory();
        } else {
// "Concrete Factory 2"
                return new OSXFactory();
        }
}


// "Concrete Factory 1+2"
class Application {
public:
        Application(GUIFactory * factory) {
                Button * button = factory->createButton();
                button->paint();
                delete button;
                delete factory;
        }
};


// "Client"
int main(int argc, char **argv) {
        Application * newApplication = new Application(createOsSpecificFactory());
        delete newApplication;
        return 0;
}
