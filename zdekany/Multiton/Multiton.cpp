#ifndef MULTITON_H
#define MULTITON_H
 
#include <map>
 
template <typename Key, typename T> class Multiton {
  public:    
    static void destroy() {
            for (typename std::map<Key, T*>::iterator it = instances.begin(); it != instances.end(); ++it) {
                        delete (*it).second;
                    }
        }
 
    static T& getRef(const Key& key) {
            typename std::map<Key, T*>::iterator it = instances.find(key);
     
            if (it != instances.end()) {
                        return *(T*)(it->second);
                    }
     
            T* instance = new T;
            instances[key] = instance;
            return *instance;
        }
 
    static T* getPtr(const Key& key) {
            typename std::map<Key, T*>::iterator it = instances.find(key);
     
            if (it != instances.end()) {
                        return (T*)(it->second);
                    }
     
            T* instance = new T;
            instances[key] = instance;
            return instance;
        }
 
  protected:
    Multiton() {}
    virtual ~Multiton() {}
 
  private:
    Multiton(const Multiton&) {}
    Multiton& operator= (const Multiton&) { return *this; }
 
    static std::map<Key, T*> instances;
};
 
template <typename Key, typename T> std::map<Key, T*> Multiton<Key, T>::instances;
 
#endif


// Usage:
  
class Foo : public Multiton<std::string, Foo> {};

Foo& foo1 = Foo::getRef("foobar");
Foo* foo2 = Foo::getPtr("foobar");
Foo::destroy();



