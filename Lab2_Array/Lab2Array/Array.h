//#pragma once
#include <iostream>
using namespace std;




template<typename T>


class Array final
{
private:

    T* p;
    int size_;
    int capacity;

public:

    class Iterator final {
    public:
        friend Array;

        Iterator(int direction, T* pointer, Array* arr) {
            direction_ = direction;
            pointer_ = pointer;
            array_ = arr;

        }
        const T& get() const {
            return *pointer_;
        }
        void set(const T& value) {
            new (pointer_) T(value);
        }
        void next() {
            pointer_ += direction_;
        }
        bool hasNext() {
            return (pointer_ + direction_ >= array_->p
                && pointer_ + direction_ <= array_->p + array_->size_ - 1);
        }
    private:
        int direction_;
        T* pointer_;
        Array* array_;
    };
    class ConstIterator final {
    public:
        friend Array;
        ConstIterator(int direction, T* pointer, Array* arr) {
            direction_ = direction;
            pointer_ = pointer;
            array_ = arr;
        }


        const T& get() const {
            return *pointer_;
        }
        void next() {
            pointer_ += direction_;
        }
        bool hasNext() {
            return (pointer_ + direction_ >= array_->p
                && pointer_ + direction_ <= array_->p + array_->size_ - 1);
        }
    private:
        int direction_;
        T* pointer_;
        Array* array_;
    };


    Array()
    {
        p = (T*)malloc(sizeof(T));
        size_ = 0;
        capacity = 1;
    }

    Array(int capacity)
    {
        p = (T*)malloc(sizeof(T) * capacity);
        size_ = 0;
        this->capacity = capacity;
    }


    Array(const Array& other) {
        p = (T*)malloc(other.capacity * sizeof(T));
        for (int i = 0; i < other.size_; i++)
        {

            new (p + i) T(other.p[i]);
            p[i] = other.p[i];
        }
        size_ = other.size_;
        capacity = other.capacity;
    }

    Array(Array&& other) {

        p = other.p;
        size_ = other.size_;
        capacity = other.capacity;

        other.p = nullptr;
        other.size_ = 0;
        other.capacity = 0;

    }

    Array& operator= (const Array& other)
    {
      
        Array tmp(other);

        std::swap(p, tmp.p);
        std::swap(size_, tmp.size_);
        std::swap(capacity, tmp.capacity);

        return *this;

    }

    Array& operator=(Array&& other) {
        for (int i = 0; i < size_; i++) {
            p[i].~T();
        }

        p = other.p;
        size_ = other.size_;
        capacity = other.capacity;

        other.p = nullptr;
        other.size_ = 0;
        other.capacity = 0;

        return *this;
    }



    ~Array() {

        for (int i = 0; i < size_; i++)
        {
            p[i].~T();
        }
        free(p);
       // p = nullptr;
    }



    int insert(const T& value) {
        if (size_ >= capacity) {
            capacity *= 2;
            T* tmp = (T*)malloc(sizeof(T) * capacity);
            for (int i = 0; i < size_; ++i) {
                new(tmp + i) T(std::move(p[i]));
                p[i].~T();
            }

       

            free(p);
            p = tmp;
            tmp = nullptr;
        }


        new (p + size_) T(value);
        size_++;
        return size_ - 1;
    }
    int insert(int index, const T& value) {

        if (size_ >= capacity) {
            capacity *= 2;
            T* tmp = (T*)malloc(sizeof(T) * capacity);
            for (int i = 0; i < size_; ++i) {
                new(tmp + i) T(std::move(p[i]));
                p[i].~T();
            }

         

            free(p);
            p = tmp;
            tmp = nullptr;
        }


        //raw memory 
        for (int i = size_; i > index; i--)
        {

            new (p + i) T(std::move(p[i - 1]));
            p[i].~T();
        }

        new(p + index) T(value);
        size_++;
        return index;


    }

    void remove(int index) {

        if (index >= size_ || index < 0) {
            return;
        }
        p[index].~T();
        for (int i = index; i < size_ - 1; i++) {
            new (p + i) T(std::move(p[i + 1]));
            p[i].~T();
        }

        p[size_ - 1].~T();
        size_--;

    }


    const T& operator[](int index) const {

        return *(p + index);

    }



    T& operator[](int index) {
        return *(p + index);
    }

    int size() const {
        return size_;
    }
    void printl() {

        for (size_t i = 0; i < size_; i++)
        {
            cout << p[i];
        }

        cout << "\n";
    }

  

    Iterator iterator() {
        
        return Iterator(1,p,this);
    }
    ConstIterator iterator() const{
      
        return ConstIterator(1,p,this);
    }

    Iterator reverseIterator() {
        
        return Iterator(-1, p+size_-1, this);
    }
    ConstIterator reverseIterator() const {

        return ConstIterator(-1, p + size_ - 1, this);
    };


    
};