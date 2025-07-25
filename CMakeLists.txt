cmake_minimum_required(VERSION 3.4...3.18)
project(pets)

add_subdirectory(pybind11)
pybind11_add_module(pets
    pets/bindings.cc
    pets/pet.cc
    pets/animal.cc
)

# PETS_VERSION_INFO is defined by setup.py and passed into the C++ code as a
# define (VERSION_INFO) here.
target_compile_definitions(pets
                           PRIVATE VERSION_INFO=${PETS_VERSION_INFO})
