#pragma once

namespace mylib {

class my_class_in_namespace {
public:
    void add(int value);
    int get_sum() const;

private:
    int sum_ = 0;
};

} // namespace mylib
