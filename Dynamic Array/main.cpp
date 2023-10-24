#include <bits/stdc++.h>
using namespace std;

template<typename _Type>
class dynamic_array {
private:
    _Type* table = nullptr;
    int _capacity = 0;
    int _size = 0;
    // modify the capacity of the array
    void reserve(int _new_capacity) {
        _Type* new_table = new _Type[_new_capacity];
        for (int i = 0; i < _new_capacity; ++i) {
            new_table[i] = i < this->_size ? table[i] : _Type();
        }
        delete[] table;
        table = new_table;
        this->_capacity = _new_capacity;
    }
    // the first significant bit of number
    constexpr int fsb(int number) const {
        for (int i = 0; i <= 4; ++i) {
            number |= number >> (1 << i);
        }
        return (number + 1) >> 1;
    }
    // the smallest power of two greater than number
    constexpr int nfsb(int number) const {
        return number ? fsb(number) << 1 : 1;
    }
    // the largest power of two smaller than number
    constexpr int lfsb(int number) const {
        return number ? fsb(number) >> 1 : 0;
    }
public:
    // empty constructor
    dynamic_array() {

    }
    // constructor with given size
    dynamic_array(int _size) {
        resize(_size);
    }
    // function to resize the array
    void resize(int _new_size) {
        reserve(nfsb(_new_size));
        _size = _new_size;
    }
    // function to resize the array and to fill it with the given value
    void assign(int _new_size, _Type _new_value) {
        resize(_new_size);
        for (int i = 0; i < _new_size; ++i) {
            table[i] = _new_value;
        }
    }
    // get the size
    int size() const {
        return _size;
    }
    // get the capacity
    int capacity() const {
        return _capacity;
    }
    // check if the array is empty
    bool empty() const {
        return _size == 0;
    }
    // access items at given locations
    _Type& operator[](int index) {
        assert(index < this->_size);
        return table[index];
    }
    // access the first element
    _Type& front() {
        assert(this->_size > 0);
        return table[0];
    }
    // access the last element
    _Type& back() {
        assert(this->_size > 0);
        return table[_size - 1];
    }
    // append an new element at the end of the array
    void push_back(_Type new_value) {
        if (_size == _capacity) {
            reserve(nfsb(_capacity));
        }
        table[_size++] = new_value;
    }
    // erase the last element of the array
    void pop_back() {
        assert(this->_size > 0);
        table[--_size] = _Type();
        if (_size == lfsb(_capacity)) {
            reserve(lfsb(_capacity));
        }
    }
    // clear the array
    void clear() {
        delete[] table;
        table = nullptr;
        _capacity = 0;
        _size = 0;
    }
    // destructor
    ~dynamic_array() {
        clear();
    }
};

int main() {
    dynamic_array<int> dynarr;
    // push_back
    dynarr.push_back(1);
    // resize
    dynarr.resize(3);
    // size
    cout << "Size: " << dynarr.size() << '\n';
    // capacity
    cout << "Capacity: " << dynarr.capacity() << '\n';
    // pop_back
    dynarr.pop_back();
    cout << "Size: " << dynarr.size() << '\n';
    cout << "Capacity: " << dynarr.capacity() << '\n';
    // operator[]
    for (int i = 0; i < dynarr.size(); ++i) {
        cout << dynarr[i] << ' ';
    }
    cout << '\n';
    // assign
    dynarr.assign(5, 7);
    dynarr.push_back(9);
    cout << "Size: " << dynarr.size() << '\n';
    // empty
    cout << "Empty: " << boolalpha << dynarr.size() << '\n';
    // front
    cout << "Front: " << dynarr.front() << '\n';
    // back
    cout << "Back: " << dynarr.back() << '\n';
    for (int i = 0; i < dynarr.size(); ++i) {
        cout << dynarr[i] << ' ';
    }
    cout << '\n';
    // clear
    dynarr.clear();
    cout << "Size: " << dynarr.size() << '\n';
    cout << "Empty: " << boolalpha << dynarr.size() << '\n';
}
