#include <vector>


class Vector {
    public:
    Vector (std::initializer_list<double>);
    
};

class Container
{
public:
    virtual double &operator[](int) = 0;
    virtual int size() const = 0;
    virtual ~Container() {};
};

class Vector_container : public Container
{
    Vector v;

public:
    Vector_container(int s) :v(s) {}
    ~Vector_container(){}
    double& operator[](int i){return v[i];}
    int size ()const {return v.size ();}
};

