#ifndef _Exceptions_H_
#define _Exceptions_H_

#include <exception>

class BadRequestEx : public std::exception
{
public:
    virtual char const * what() const noexcept { return "Bad Request"; } 
};

class NotFoundEx : public std::exception
{
public:
    virtual char const * what() const noexcept { return "Not Found"; }
};

class PermissionEx : public std::exception
{
public:
    virtual char const * what() const noexcept { return "Permission Denied"; }
};







#endif

