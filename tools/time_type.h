//
// Created by jaewoo on 22. 2. 18..
//

#ifndef ASD_BOX_TIME_TYPE_H
#define ASD_BOX_TIME_TYPE_H

#include <iostream>

namespace asd_box {
    struct time {
    private:
        using inner_type = float;

    public:
        explicit constexpr time(inner_type val) : val{val} {}

        inner_type val;

        time& operator+=(const time& rhs) {
            val += rhs.val;
            return *this;
        }

        time& operator-=(const time& rhs) {
            val -= rhs.val;
            return *this;
        }

        time& operator*=(float rhs) {
            val *= rhs;
            return *this;
        }

        time& operator/=(float rhs) {
            val /= rhs;
            return *this;
        }
    };

    inline std::ostream& operator<<(std::ostream& os, const time& t) {
        return os << t.val;
    }

    inline time operator+(time a, const time& b) {
        a += b;
        return a;
    }

    inline time operator-(time a, const time& b) {
        a -= b;
        return a;
    }

    inline time operator*(time a, float b) {
        a *= b;
        return a;
    }

    inline time operator/(time a, float b) {
        a /= b;
        return a;
    }

    inline auto operator <=> (time a, time b) {
        return a.val <=> b.val;
    }
}


#endif //ASD_BOX_TIME_TYPE_H
