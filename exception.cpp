#include "exception.h"
#include <stdio.h>
#include <cstring>
#include <cstdlib>

using namespace std;
namespace DSLib
{

void Exception::init(const char* message, const char* file, int line)
{
    m_message = strdup(message);

    if(file != nullptr)
    {
        char sl[32] = {0};

        sprintf(sl,"%d",line);

        m_location = static_cast<char*>(malloc(strlen(file) + strlen(sl) + 2));
        m_location = strcpy(m_location, file);
        m_location = strcat(m_location, ":");
        m_location = strcat(m_location, sl);
    }
    else
    {
        m_location = nullptr;
    }
}

Exception::Exception(const char* message)
{
    init(message,nullptr,0);
}

Exception::Exception(const char* file, int line)
{
    init(nullptr, file, line);
}

Exception::Exception(const char* message, const char* file,int line)
{
    init(message, file, line);
}

Exception::Exception(const Exception& e)
{
    m_message = strdup(e.m_message);
    m_location = strdup(e.m_location);
}

Exception& Exception::operator=(const Exception& e)
{
    if(this != &e)
    {
        free(m_message);
        free(m_location);
        m_message = strdup(e.m_message);
        m_location = strdup(e.m_location);
    }
    return *this;
}

const char* Exception::message() const
{
    return m_message;
}

const char* Exception::location() const
{
    return m_location;
}

Exception::~Exception()
{
    free(m_message);
    free(m_location);
}

ArithmeticException::~ArithmeticException()
{
    free(m_message);
    free(m_location);
}

NullPointerException::~NullPointerException()
{
    free(m_message);
    free(m_location);
}

IndexOutOfBoundsException::~IndexOutOfBoundsException()
{
    free(m_message);
    free(m_location);
}

NoEnoughMemoryException::~NoEnoughMemoryException()
{
    free(m_message);
    free(m_location);
}

InvalidParameterException::~InvalidParameterException()
{
    free(m_message);
    free(m_location);
}

InvalidOperationException::~InvalidOperationException()
{
    free(m_message);
    free(m_location);
}

}
