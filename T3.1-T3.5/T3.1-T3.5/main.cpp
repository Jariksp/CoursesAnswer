#include <iostream>
#include <map>

namespace TReflection {

    template <typename T>
    struct TType {



        template <typename PropertyType>
        TType& Property(PropertyType T::* property) { return *this; }

        template <typename ReturnType, typename... ArgumentTypes>
        TType& Function(ReturnType(T::*)(ArgumentTypes...)) { return *this; }

        template <typename C>
        TType& Parent() { return *this; }


        class TProperty {
            public:
            static void Set(const std::string& name, T* obj, int data) {

            }
            static void Get(const std::string& name, T* obj, int* data) {

            }
        };

        class TFunction {
            public:
            static void Call(const std::string& name, T* obj) {

            }

        };
        

    };

} // namespace reflection

#define REFLECTABLE(...) struct _t { \
    using type = __VA_ARGS__; \
    _t() { TReflection::TType<type>()

#define PROPERTY(...) .Property(&type::__VA_ARGS__)
#define FUNCTION(...) .Function(&type::__VA_ARGS__)
#define PARENT(...) .Parent<__VA_ARGS__>()

#define REFLECTABLE_INIT() ;} }; static _t t;

struct TObject {
    void Foo() {}
    int Var = 0;
};

REFLECTABLE(TObject)
PROPERTY(Var)   
FUNCTION(Foo)
PARENT(TObject)
REFLECTABLE_INIT()
#include <any>
int main() {

    TObject obj;
    TReflection::TType<TObject>::TProperty::Set("Var", &obj, 123);

    int data = 0;
    TReflection::TType<TObject>::TProperty::Get("Var", &obj, &data); // data will be 123 

    TReflection::TType<TObject>::TFunction::Call("Foo", &obj); // will call TObject::Foo

    return 0;
}