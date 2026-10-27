import vector_algebra

print("--- ТЕСТИРОВАНИЕ ФУНКЦИЙ С std::vector ---")
v1 = [1.0, 2.0, 3.0]
v2 = [4.0, 5.0, 6.0]

print(f"Вектор 1: {v1}")
print(f"Вектор 2: {v2}")
print(f"Сложение: {vector_algebra.add_vectors(v1, v2)}")   
print(f"Вычитание: {vector_algebra.sub_vectors(v1, v2)}")  
print(f"Скалярное произведение: {vector_algebra.dot_product(v1, v2)}") 

print("\n--- ТЕСТИРОВАНИЕ КЛАССА Vector3D ---")
vec = vector_algebra.Vector3D(3.0, 4.0, 0.0)
print(f"Создан вектор Vector3D с координатами: ({vec.x}, {vec.y}, {vec.z})")
print(f"Длина вектора: {vec.length()}")

norm_vec = vec.normalize()
print(f"Нормализованный вектор: ({norm_vec.x}, {norm_vec.y}, {norm_vec.z})")
print(f"Длина нормализованного вектора: {norm_vec.length()}")
