/*
The MIT License (MIT)

Copyright (c) 2025-present mrcingo

Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the "Software"),
to deal in the Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish, distribute, sublicense,
and/or sell copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
*/

#include "animal.h"

class PyAnimal : public Animal, public pybind11::trampoline_self_life_support {
public:
    using Animal::Animal;
    std::string go(int n_times) override {
        PYBIND11_OVERRIDE_PURE(
            std::string,
            Animal,
            go,
            n_times
        );
    }
};

std::string Dog::go(int n_times) {
    std::string result;
    for (int i = 0; i < n_times; ++i)
        result += "woof! ";
    return result;
}

std::string call_go(Animal *animal) {
    return animal->go(3);
}

void init_animal(pybind11::module_ &m) {
    pybind11::class_<Animal, PyAnimal, pybind11::smart_holder>(m, "Animal")
        .def(pybind11::init<>())
        .def("go", &Animal::go);

    pybind11::class_<Dog, Animal, pybind11::smart_holder>(m, "Dog")
        .def(pybind11::init<>());

    m.def("call_go", &call_go);
}
