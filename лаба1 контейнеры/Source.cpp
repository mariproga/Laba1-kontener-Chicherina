#include <iostream>
#include <cmath>
#include <iomanip>

class Array
{
public:

    typedef double
        value_type;
    typedef double*
        iterator;
    typedef const double*
        const_iterator;
    typedef double&
        reference;
    typedef const double&
        const_reference;
    typedef std::size_t
        size_type;

    Array(const size_type n);
    Array(iterator f, iterator s);

    ~Array()
    {
        delete[]pt;
    }

    iterator begin() { return pt; }
    const_iterator begin() const { return pt; }
    iterator end() { return pt + cc; }
    const_iterator end() const { return pt + cc; }

    size_type size() const
    {
        return cc;
    }

    void resize(size_type newsize);

    bool empty() const
    {
        if (cc == 0)
            return true;
        else
            return false;
    }

    reference operator[](size_type index);
    const_reference operator[](size_type index) const;
    reference front() { return pt[0]; }
    const_reference front() const { return pt[0]; }

    reference back()
    {
        return pt[size() - 1];
    }

    const_reference back() const { return pt[size() - 1]; }

    void push_back(const value_type& v);

    void newdisplay()
    {
        int i = 0;

        for (i = 0; i < cc; i++)
        {
            std::cout.precision(5);

            std::cout << std::fixed << pt[i] << " ";
        }
        std::cout << '\n';
    }

    void pop_back()
    {
        pt[cc - 1] = 0;
        cc--;
    }

    void display()
    {
        int i = 0;

        for (i = 0; i < cc; i++)
        {
            std::cout.precision(3);

            std::cout << std::fixed << pt[i] << " ";
        }
        std::cout << '\n';
    }

private:

    size_type memorsize;

    value_type* pt;

    size_type cc;

};

double tosum(const Array& arr)
{
    double sum = 0;

    int i = 0;

    for (i = 0; i < arr.size(); i++)
        sum += arr[i];

    return sum;
}

double todif(const Array& arr)
{
    double dif = 0;

    int i = 0;

    for (i = 0; i < arr.size(); i++)
        dif -= arr[i];

    return dif;
}

double delenie(const Array& arr)
{
    double aver = tosum(arr) / arr.size();

    return aver;
}

void imp(Array& arr)
{
    int i = 0;

    double max = arr[0];

    for (i = 0; i < arr.size(); i++)
        if (arr[i] > max)
            max = arr[i];

    for (i = 0; i < arr.size(); i++)
        (arr.begin())[i] = (arr.begin())[i] - max;

}

void Array::push_back(const value_type& v)
{
    if (cc == memorsize)
        resize(memorsize * 2);

    pt[cc++] = v;
}

void Array::resize(size_type newsize)
{
    value_type* s = new value_type[newsize];

    for (size_type i = 0; i < cc; ++i)
        s[i] = pt[i];

    delete[] pt;

    pt = s;
    memorsize = newsize;
}

Array::Array(iterator first, iterator last)
{
    int i = 0;

    if (first < last)
    {
        memorsize = (first - last);
        pt = new value_type[memorsize];

        for (i = 0; i < memorsize; ++i)
            pt[i] = *(first + i);

        cc = memorsize;
    }
}

Array::Array(const size_type n)
{
    memorsize = n;

    pt = new value_type[n];

    cc = 0;
}

double& Array::operator[](size_type index)
{
    if (index < cc)
        return pt[index];
}

const double& Array::operator[](size_type index) const
{
    if (index < cc)
        return pt[index];
}

int main()
{
    int size, helper = 1;

    int i = 0;

    double el, s = 0, del = 0;

    std::cin >> size;

    Array arr(size);

    for (i = 0; i < size; i++)
    {
        std::cin >> el;

        arr.push_back(el);
    }

    std::cout << arr.size() << '\n';

    arr.display();
    s = tosum(arr);
    del = delenie(arr);
    arr.push_back(s);
    arr.push_back(del);
    arr.display();
    imp(arr);

    arr.display();

    while (true)
    {
        std::cin >> helper;

        if (helper == 0)
        {
            break;
        }

        else
        {
            switch (helper)
            {
            case 1:
                std::cin >> el;

                arr.push_back(el);

                std::cout << "+:" << arr.size() << '\n';

                arr.display();

                s = tosum(arr);
                del = delenie(arr);

                arr.push_back(s);
                arr.push_back(del);

                arr.display();

                imp(arr);

                arr.display();

                break;

            case 2:
                arr.pop_back();

                std::cout << "-:" << arr.size() << '\n';

                arr.display();

                s = tosum(arr);
                del = delenie(arr);

                arr.push_back(s);
                arr.push_back(del);

                arr.display();

                imp(arr);

                arr.display();
                break;
            }
        }
    }
    return 0;
}