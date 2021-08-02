//
// Created by jaewoo on 21. 8. 2..
//

#ifndef ASD_BOX_PROPERTY_H
#define ASD_BOX_PROPERTY_H

#include <utility>

namespace asd_box::tools {
    template <auto Getter, auto Setter>
    struct property {
        property& operator=(const auto& val) {
            Setter(val);
            return *this;
        };

        decltype(auto) value() const {
            return Getter();
        }

        explicit(false) operator decltype(auto)() const {
            return value();
        };
    };

    template <class T, auto Getter, auto Setter>
    struct member_property{
        explicit member_property(T* container): m_container{container}{}

        member_property& operator=(auto&& val) {
            set(std::forward<decltype(val)>(val));
            return *this;
        };

        member_property& operator += (auto && val){
            *this = get() + val;
        }
        member_property& operator -= (auto && val){
            *this = get() - val;
        }
        member_property& operator *= (auto && val){
            *this = get() * val;
        }
        member_property& operator /= (auto && val){
            *this = get() / val;
        }
        member_property& operator %= (auto && val){
            *this = get() % val;
        }
        member_property& operator &= (auto && val){
            *this = get() & val;
        }
        member_property& operator |= (auto && val){
            *this = get() | val;
        }
        member_property& operator ^= (auto && val){
            *this = get() ^ val;
        }
        member_property& operator <<= (auto && val){
            *this = get() << val;
        }
        member_property& operator >>= (auto && val){
            *this = get() >> val;
        }

        operator decltype(auto) () const {
            return get();
        };


        decltype(auto) get() const {
            return (m_container->*Getter) ();
        }

        void set(auto && val) {
            (m_container->*Setter)(std::forward<decltype(val)>(val));
        }


    private:
        T* m_container;
    };
}

#endif //ASD_BOX_PROPERTY_H
