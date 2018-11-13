#include <memory>

#include <vector>
#include <iostream>
#include <memory>

using namespace std;

class Object
{
public:
    Object()
    {
        cout << "constructor" << endl;
    };

    ~Object()
    {
        cout << "destructor" << endl;
    };
};

void test()
{
    shared_ptr<Object> obj(new Object);
    cout << obj.get() << endl;
    cout << obj.use_count() << endl;
    vector<shared_ptr<Object> > test;
    test.push_back(obj);
    cout << test.at(0).get() << endl;
    cout << test.at(0).use_count() << endl;
}

int main()
{
    test();
    return 0;
}