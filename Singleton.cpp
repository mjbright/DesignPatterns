
#include<iostream>
#include<strings.h>
using namespace std;

// - BASE Singleton class:
class Singleton {
public:
    static Singleton* Instance();
    static Singleton* Instance(const char* type);
protected:
    Singleton() {};
    //~Singleton();
private:
    static Singleton* _instance;
};

Singleton* Singleton::_instance = 0;

Singleton* Singleton::Instance() {
    if (_instance == 0) {
        _instance = new Singleton;
    	//_instance = 0;
    }
    return _instance;
}

/*
// - DERIVED Singleton class:
class MyCounter : public Singleton {
public:
	//static MyCounter* Instance() {
	//	return Singleton::Instance();
	//}
    void dec() {
        counter--;
    }
    void inc() {
        counter++;
    }
    void print() {
        cout << "My counter is " << counter << endl;
    };
protected:
    MyCounter() { counter=0; };
private:
    int counter;
};
*/

Singleton* Singleton::Instance(const char* type) {
    if (_instance == 0) {
    	/*if (strcmp(type, "MyCounter") == 0) {
            _instance = new MyCounter;
    	}*/
    }
    return _instance;
}

int main(int argc, char **argv) {
	// Compile-time error: Singleton* s = new Singleton();
	cout << "Testing Singleton class" << endl;
	cout << "Create two instances and check they're the same object (same address)" << endl;
    Singleton* s = Singleton::Instance();
	Singleton* s2 = Singleton::Instance();

	if (s != s2) {
		cerr << "ERROR: s(0x" << s << ") != s2(0x" << s2 << ")" << endl;
	} else {
		cout << "OK: s(0x" << s << ") == s2(0x" << s2 << ")" << endl;
	}

	/*
	//MyCounter* myc = new MyCounter();
	//MyCounter* myc = (MyCounter*) MyCounter::Instance();
	MyCounter* myc = (MyCounter*) Singleton::Instance("MyCounter");

	myc->inc();
	myc->inc();
	myc->print();
*/

}


