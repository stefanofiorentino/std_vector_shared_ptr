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
    
    virtual void func() 
    {
        puts(__PRETTY_FUNCTION__);
    }

    ~Object()
    {
        cout << "destructor" << endl;
    };
};

class Child : public Object
{
    void func() final 
    {
        puts(__PRETTY_FUNCTION__);
    }
};

void test()
{
    shared_ptr<Object> obj(new Object);
    cout << obj.get() << endl;
    cout << obj.use_count() << endl;
    vector<shared_ptr<Object> > test;
    test.push_back(obj);
    cout << test.back().get() << endl;
    cout << test.back().use_count() << endl;
    test.back()->func();
    test.emplace_back(obj);
    cout << test.back().get() << endl;
    cout << test.back().use_count() << endl;
    test.back()->func();
    test.emplace_back(std::move(obj));
    cout << test.back().get() << endl;
    cout << test.back().use_count() << endl;
    test.back()->func();
    test.emplace_back(new Child);
    cout << test.back().get() << endl;
    cout << test.back().use_count() << endl;
    test.back()->func();
}

int main()
{
    test();
    return 0;
}