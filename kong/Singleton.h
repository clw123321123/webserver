#ifndef KONG_SINGLETON_H
#define KONG_SINGLETON_H

#include <memory>

namespace kong {

namespace {

template<class T,class X,int N>
T& GetInstanceX() {
    static T v;
    return v;
}

template<class T,class X,int N>
std::shared_ptr<T> GetInsatncePtr() {
    static std::shared_ptr<T> v(new T);
    return v;
}
}

template<class T,class X = void,int N = 0>
class Singleton {
public:
    static T* GetInsatnce() {
        static T v;
        return &v;
    }
};

template<class T,class X = void,int N = 0>
class SingletonPtr {
public:
    static std::shared_ptr<T> GetInsatnce() {
        static std::shared_ptr<T> v(new T);
        return v;
    }

};
}


#endif 