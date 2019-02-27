#include "object.h"
#include <iostream>
#include <cstdlib>

using namespace std;

namespace DSLib
{
void* Object::operator new(size_t size) throw()
{
    return malloc(size);
}
void Object::operator delete(void* p)
{
    free(p);
}
void* Object::operator new[](size_t size) throw()
{
    return malloc(size);
}
void Object::operator delete[](void* p)
{
    free(p);
}

bool Object::operator == (const Object& obj)  //默认实现，地址比较
{
    return (this == &obj);
}

bool Object::operator != (const Object& obj)
{
    return (this != &obj);
}

Object::~Object()
{

}
}
