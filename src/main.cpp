#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <vector>
#include <cmath>
#include <stdexcept>

namespace py = pybind11;

// --- Функции для работы с векторами (std::vector) ---

std::vector<double> add_vectors(const std::vector<double>& v1, const std::vector<double>& v2) {
    if (v1.size() != v2.size()) throw std::invalid_argument("Vectors must have the same size");
    std::vector<double> result(v1.size());
    for (size_t i = 0; i < v1.size(); ++i) result[i] = v1[i] + v2[i];
    return result;
}

std::vector<double> sub_vectors(const std::vector<double>& v1, const std::vector<double>& v2) {
    if (v1.size() != v2.size()) throw std::invalid_argument("Vectors must have the same size");
    std::vector<double> result(v1.size());
    for (size_t i = 0; i < v1.size(); ++i) result[i] = v1[i] - v2[i];
    return result;
}

double dot_product(const std::vector<double>& v1, const std::vector<double>& v2) {
    if (v1.size() != v2.size()) throw std::invalid_argument("Vectors must have the same size");
    double result = 0.0;
    for (size_t i = 0; i < v1.size(); ++i) result += v1[i] * v2[i];
    return result;
}

// --- Класс Vector3D ---

class Vector3D {
public:
    double x, y, z;

    Vector3D(double x, double y, double z) : x(x), y(y), z(z) {}

    double length() const {
        return std::sqrt(x * x + y * y + z * z);
    }

    Vector3D normalize() const {
        double len = length();
        if (len == 0.0) throw std::runtime_error("Cannot normalize a zero vector");
        return Vector3D(x / len, y / len, z / len);
    }
};

// --- Экспорт модуля через Pybind11 ---

PYBIND11_MODULE(vector_algebra, m) {
    m.doc() = "Vector algebra module powered by C++ and Pybind11";

    m.def("add_vectors", &add_vectors, "Add two vectors element-wise");
    m.def("sub_vectors", &sub_vectors, "Subtract two vectors element-wise");
    m.def("dot_product", &dot_product, "Calculate the dot product of two vectors");

    py::class_<Vector3D>(m, "Vector3D")
        .def(py::init<double, double, double>())
        .def_readwrite("x", &Vector3D::x)
        .def_readwrite("y", &Vector3D::y)
        .def_readwrite("z", &Vector3D::z)
        .def("length", &Vector3D::length, "Calculate the length of the 3D vector")
        .def("normalize", &Vector3D::normalize, "Get the normalized 3D vector");
}
