#ifndef __BASE_HPP__
# define __BASE_HPP__

class Base 
{
    protected:
        Base();
        Base(const Base &other);
        Base& operator=(const Base &other);

    public:
        virtual         ~Base();
        static Base     *generate(void);
        static void     identify(Base* p);
        static void     identify(Base& p);

};

class A : public Base {};
class B : public Base {};
class C : public Base {};

#endif