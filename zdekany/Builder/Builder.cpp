#include <string>
#include <iostream>
using namespace std;
 
// "Product"
class Pizza {
public:
        void dough(const string& dough) {
                dough_ = dough;
        }
 
        void sauce(const string& sauce) {
                sauce_ = sauce;
        }
 
        void topping(const string& topping) {
                topping_ = topping;
        }
 
        void open() const {
                cout << "Pizza with " << dough_ << " dough, " << sauce_ << " sauce and "
                        << topping_ << " topping. Mmm." << endl;
        }
 
private:
        string dough_;
        string sauce_;
        string topping_;
};
 
// "Abstract Builder"
class PizzaBuilder {
public:
        const Pizza& pizza() {
                return pizza_;
        }
 
        virtual void buildDough() = 0;
        virtual void buildSauce() = 0;
        virtual void buildTopping() = 0;
 
protected:
        Pizza pizza_;
};
 
//----------------------------------------------------------------
 
class HawaiianPizzaBuilder : public PizzaBuilder {
public:
        void buildDough() {
                pizza_.dough("cross");
        }
 
        void buildSauce() {
                pizza_.sauce("mild");
        }
 
        void buildTopping() {
                pizza_.topping("ham+pineapple");
        }
};
 
class SpicyPizzaBuilder : public PizzaBuilder {
public:
        void buildDough() {
                pizza_.dough("pan baked");
        }
 
        void buildSauce() {
                pizza_.sauce("hot");
        }
 
        void buildTopping() {
                pizza_.topping("pepperoni+salami");
        }
};
 
//----------------------------------------------------------------
 
class Cook {
public:
        Cook()
                : pizzaBuilder_(nullptr)
        {       }
 
        ~Cook() {
                if (pizzaBuilder_)
                        delete pizzaBuilder_;
        }
 
        void pizzaBuilder(PizzaBuilder* pizzaBuilder) {
                if (pizzaBuilder_)
                        delete pizzaBuilder_;
 
                pizzaBuilder_ = pizzaBuilder;
        }
 
        const Pizza& getPizza() {
                return pizzaBuilder_->pizza();
        }
 
        void constructPizza() {
                pizzaBuilder_->buildDough();
                pizzaBuilder_->buildSauce();
                pizzaBuilder_->buildTopping();
        }
 
private:
        PizzaBuilder* pizzaBuilder_;
};
 
int main() {
        Cook cook;
        cook.pizzaBuilder(new HawaiianPizzaBuilder);
        cook.constructPizza();
 
        Pizza hawaiian = cook.getPizza();
        hawaiian.open();
 
        cook.pizzaBuilder(new SpicyPizzaBuilder);
        cook.constructPizza();
 
        Pizza spicy = cook.getPizza();
        spicy.open();
}
