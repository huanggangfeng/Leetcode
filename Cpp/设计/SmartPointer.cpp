#include <iostream>

using namespace std;

class ref_count
{
private:
    int count = 0;
public:
    ref_count(int cnt = 0) {
        count = cnt;
    }
    void add_ref() {
        count++;
    }

    int ref_decrease() {
        return --count;
    }
    ~ref_count();
};


template <typename T>
class SmartPointer {
public:
    SmartPointer(T *pointer = nullptr) : _ptr(pointer) {
        if (_ptr != nullptr) {
            _count = new ref_count(1);
        }
    }

    SmartPointer (const SmartPointer &pointer) : _ptr(pointer->_ptr, _count(pointer->_count)) {
        if (_count)
            _count->add_ref();
    }

    virtual ~SmartPointer() {
        if (_count && _count->ref_decrease() <= 0) {
            if (_ptr) {
                delete _ptr;
                _ptr = nullptr;
            }

            if (_count) {
                delete _count;
                _count = nullptr;
            }
        }
    }

    T* operator ->() {
        return _ptr;
    }

    T& operator *() {return *_ptr;}
    SmartPointer<T> &operator=(const SmartPointer<T> &ptr) {
        if (&ptr != this) {
            if (_count && _count->ref_decrease() == 0) {
                delete _ptr;
                _ptr = nullptr;
                delete _count;
                _count = nullptr;
            }

            _ptr = ptr._ptr;
            _count = ptr._count;
            if (ptr._count)
                _count->add_ref();
        }
        return *this;
    }

private:
    ref_count *_count;
    T *_ptr;
};


int main(int argc, char const *argv[])
{
    SmartPointer<int> test1(new int(1));
    return 0;
}
