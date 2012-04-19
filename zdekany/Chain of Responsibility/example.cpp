#include <iostream>
using namespace std;
// Abstract class called Handler
// It is abstract because it has a pure virtual function.
// This prevents instances of Handler being created directly.
class Handler {
    protected:
        Handler *next;
    public:
        // Constructor
        Handler() { next = NULL; }
 
        // Pure virtual function
        virtual void request(int value) = 0;
 
        // Sets next handler in the chain
        void setNextHandler(Handler *nextInLine) {
            next = nextInLine;
        }
};
 
 
// SpecialHandler is a type of Handler but has a limit and ID
// It also determines if it can handle the request or needs to send it on
// If it is the last in the chain and can't handle it, it lets the user know.
class specialHandler : public Handler {
    private:
        int limit;
        int ID;
    public:
        specialHandler(int theLimit, int theID) {
                limit = theLimit;
                ID = theID;
        }
        // Handles incoming request
        void request(int value) {
            if (value < limit) {
                cout << "Handler " << ID << " handled the request with a limit of " << limit << endl;
            }
            else if (next != NULL) {
                // Passes it on to the next in the chain
                next->request(value);
            }
            else {
                // Last in chain, so let the user know it was unhandled.
                cout << "Sorry, I am the last handler (" << ID << ") and I couldn't even handle that request." << endl;
            }
        }
};
 
int main ()
{
 
    // Create three special handlers with ids "1, 2 and 3"
    // Since a specialHandler is a type of "Handler" they are legal statements.
    Handler *h1 = new specialHandler(10, 1);
    Handler *h2 = new specialHandler(20, 2);
    Handler *h3 = new specialHandler(30, 3);
 
    // Chain up the handlers together
    h1->setNextHandler(h2);
    h2->setNextHandler(h3);
 
    // Handled by handler 2 because handler 1 couldn't handle it,
    // so it passed it on to handler 2 which could handle since it is less than 20
    h1->request(18);
 
    // No handler could handle this, so will trigger last handler's else
    // statement showing that it is the last and still couldn't handle the request.
    // You could also tack on a default version for the end if you like.
    h1->request(40);
 
    // Clean up our pointers
    delete h1;
    delete h2;
    delete h3;
     
    return 0;
}

