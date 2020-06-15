#include <mylib.hpp>

namespace mylib {

void my_class_in_namespace::add(int value) {
    sum_ += value;
}

int my_class_in_namespace::get_sum() const {
    return sum_;
}

} // namespace mylib
