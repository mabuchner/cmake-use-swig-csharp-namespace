%module MyLib

%{
#include <mylib.hpp>
%}

%nspace mylib::my_class_in_namespace;
%include <mylib.hpp>
