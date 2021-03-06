#include <iostream>
#include "smartpointer.h"
#include "exception.h"
#include "object.h"
#include "list.h"
#include "seqlist.h"
#include "staticlist.h"
#include "dynamiclist.h"
#include "array.h"
#include "staticarray.h"
#include "dynamicarray.h"
#include "linklist.h"

using namespace std;
using namespace DSLib;

class Test  //Test class
{
public:
    Test()
    {
        cout << "Test()" << endl;
    }

    ~Test()
    {
        cout << "~Test()" << endl;
    }
};

class TestObj : public Object
{
public:
    int i;
    int j;
    ~TestObj();
};

TestObj::~TestObj() {}

class Child : public TestObj
{
public:
    int k;
    ~Child();
};

Child::~Child() {}

int main()
{
//    SmartPointer<Test> sp = new Test();
//    SmartPointer<Test> nsp;

//    nsp = sp;

//    cout << sp.isNull() << endl;
//    cout << nsp.isNull() << endl;
//    cout << "Hello World!" << endl;

//    SmartPointer<int>* sp = new SmartPointer<int>();

//    delete sp;

//    InvalidOperationException* e = new InvalidOperationException();

//    delete e;
//    Object* obj1 = new TestObj();
//    Object* obj2 = new Child();

//    cout << "obj1= " << obj1 << endl;
//    cout << "obj2= " << obj2 << endl;

//    delete obj1;
//    delete obj2;

//    try
//    {
//        THROW_EXCEPTION(InvalidOperationException, "Test");
//        //throw ArithmeticException("Test", __FILE__, __LINE__);
//    }
//    catch(const Exception& e)
//    {
//        cout << "catch(const Exception& e)" << endl;
//        cout << e.message() << endl;
//        cout << e.location() << endl;
//    }

//    DynamicList<int> l(5);
//    for(int i = 0; i < l.capacity(); i++)
//    {
//        l.insert(0,i);
//    }
//    for(int i = 0; i < l.length(); i++)
//    {
//        cout << l[i] << endl;
//    }

//    try {
//        l[5] = 6;
//    } catch (const Exception& e) {
//        cout << e.message() << endl;
//        cout << e.location() << endl;
//        l.resize(10);

//        l.insert(5,50);
//    }

//    for(int i = 0; i < l.length(); i++)
//    {
//        cout << l[i] << endl;
//    }

//    StaticArray<int, 5> s1;

//    for(int i = 0; i < s1.length(); i++)
//    {
//        s1[i] = i * i;
//    }

//    for(int i = 0; i < s1.length(); i++)
//    {
//        cout << s1[i] << endl;
//    }

//    StaticArray<int, 5> s2;

//    s2 = s1;

//    for(int i = 0; i < s1.length(); i++)
//    {
//        cout << s2[i] << endl;
//    }

//    try {
//        s2[6] = 1;
//    } catch (const Exception& e) {
//        cout << e.message() << endl;
//        cout << e.location() << endl;
//    }

//    DynamicArray<int> s3(10);
//    DynamicArray<int> s4(10);
//    for(int i = 0; i < s3.length(); i++)
//    {
//        s3[i] = i * i;
//    }

//    for(int i = 0; i < s3.length(); i++)
//    {
//        cout << s3[i] << endl;
//    }

//    s4 = s3;

//    s4.resize(5);
//    for(int i = 0; i < s4.length(); i++)
//    {
//        cout << s4[i] << endl;
//    }

//    cout << "LinkList Test" << endl;

//    LinkList<int> list;

//    for(int i = 0; i < 1; i++)
//    {
//        list.insert(i);
//    }

//    cout << "LinkList Test" << endl;

//    for(int i = 0; i < list.length(); i++ )
//    {
//        int v = 0;
//        list.get(i,v);
//        cout << v << endl;
//    }

//    list.remove(5);



//    for(int i = 0; i < list.length(); i++ )
//    {
//        int v = 0;
//        list.get(i,v);
//        cout << v << endl;
//    }

//    list.set(5,666);

//    for(int i = 0; i < list.length(); i++ )
//    {
//        int v = 0;
//        list.get(i,v);
//        cout << v << endl;
//    }


//    cout << list.find(666) << endl;


//    LinkList<int> list2;
//    for(int i = 0; i < 15; i++)
//    {
//        list2.insert(0,i);
//    }

    LinkList<int> list;

    for(int i = 0; i<5; i++)
    {
        list.insert(0,i);
    }

    //遍历时必须先调用move函数
    for(list.move(0,2); !list.end(); list.next())
    {
        cout << list.current() << endl;
    }


    return 0;
}
