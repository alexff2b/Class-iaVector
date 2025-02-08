/*
 ****************************************************************************************************
 *
 *    Компания    : iA
 *    @file       : iaVector.hpp
 *    @brief      : Заголовочный файл для класса iaVector.
 *    @author     : Александр Юшкевич
 *    @aka        : iA, alexff
 *    @project    : Все проекты iA. IA Projects
 *    @version    : 0.3.0 (Stable version - fully tested and optimized)
 *    @license    : MIT License
 *    @contact    : / alexff.2b@hotmail.com /
 *                   / alexff.2b@gmail.com   /
 *                   / alexff.2b@icloud.com  /
 *                   / alexff.2b@yandex.ru   /
 *    @tel        : Fr.+33658046456
 *                  rus. +79859751326
 *
 *    @created    : Октябрь 2021
 *    @modified   : Январь 2025
 *
 *    @note       : Изменения с предыдущей версии:
 *                  - Добавлен метод инверсии вектора.
 *                  - Исправлены ошибки и улучшена документация для ясности и полноты.
 *
 *    @description: Этот класс представляет вектор, который может использоваться для
 *                   выполнения различных математических операций. Он поддерживает
 *                   операции с векторами, такие как сложение, вычитание, скалярное произведение,
 *                   умножение на скаляр и инверсия вектора. Класс также включает методы для
 *                   работы с элементами вектора, инициализации и вывода. Класс может быть
 *                   использован в задачах линейной алгебры, обработки данных, машинного обучения
 *                   и других областях, где требуется работа с векторами.
 *
 *    @methods     :
 *                   - iaVector(); // Конструктор по умолчанию
 *                   - iaVector(int m); // Конструктор с размером
 *                   - iaVector(int m, const double values[]); // Конструктор со значениями
 *                   - iaVector(const iaVector& otherVector); // Конструктор копирования
 *                   - iaVector& operator=(const iaVector& otherVector) noexcept; // Оператор присваивания
 *                   - ~iaVector(); // Деструктор
 *                   - int sizeOfVector() const; // Возвращает размер вектора
 *                   - void printVector() const; // Печатает вектор
 *                   - double& operator[](int j); // Оператор доступа
 *                   - double* operator&(int j); // Оператор адреса
 *                   - iaVector operator+(const iaVector& otherVector) const; // Сложение
 *                   - iaVector operator-(const iaVector& otherVector) const; // Вычитание
 *                   - iaVector operator*(double scalar) const; // Умножение на скаляр
 *                   - double dotProduct(const iaVector& otherVector) const; // Скалярное произведение
 *                   - double L2norm() const; // Вычисление L2 нормы
 *                   - double sum() const; // Вычисление суммы элементов
 *                   - double maxElement() const; // Вычисление максимального элемента
 *                   - double minElement() const; // Вычисление минимального элемента
 *                   - double angleBetween(const iaVector& otherVector) const noexcept; // Вычисление угла между векторами
 *                   - void inverting() noexcept; // Инверсия вектора
 *
 *    @properties  :
 *                   - int m;            ///< Размер вектора
 *                   - double* value;    ///< Значения вектора
 *
 *    @copyright    : Этот файл является частью проектов iA. Он лицензирован под MIT License.
 *                   Вы можете использовать, изменять и распространять этот код, при условии,
 *                   что Вы предоставите соответствующее упоминание об авторе.
 * **************************************************************************************************
 */

#ifndef iaVector_hpp
#define iaVector_hpp

#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdexcept>

/**
 * @class iaVector
 * @brief Класс для работы с векторами.
 *
 * Этот класс предоставляет методы для создания, управления и выполнения операций с векторами.
 */
class iaVector {
public:
    iaVector(); // Конструктор по умолчанию
    iaVector(int m); // Конструктор с заданным размером
    iaVector(int m, const double values[]); // Конструктор с заданным размером и значениями
    iaVector(const iaVector& otherVector); // Конструктор копирования
    ~iaVector(); // Деструктор
    iaVector& operator=(const iaVector& otherVector) noexcept; // Оператор присваивания
    
    iaVector operator+(const iaVector& otherVector) noexcept; // Оператор сложения
    iaVector operator-(const iaVector& otherVector) noexcept; // Оператор вычитания
    iaVector operator*(const iaVector& otherVector) noexcept; // Оператор умножения с другим вектором
    iaVector operator*(double scal); // Оператор умножения на скаляр
    
    void inverting() noexcept; // Метод инверсии вектора
    int sizeOfVector() const; // Получить размер вектора
    void printVector() const; // Печать значений вектора
    double sum() const; // Вычисление суммы элементов вектора
    double L2norm() const; // Вычисление L2 нормы вектора
    double L1norm() const; // Вычисление L1 нормы вектора
    double LMnorm() const; // Вычисление L∞ нормы вектора
    iaVector normalize() const; // Нормализация вектора
    double dotProduct(const iaVector& otherVector) const; // Вычисление скалярного произведения
    double angleBetween(const iaVector& otherVector) const noexcept; // Вычисление угла между векторами
    void sortAscending(); // Сортировка по возрастанию
    void sortDescending(); // Сортировка по убыванию
    double maxElement() const; // Максимальный элемент
    double minElement() const; // Минимальный элемент
    double avverage() const; // Среднее значение
    
    double& operator[](int j); // Оператор доступа к элементам вектора
    bool operator==(const iaVector& otherVector) const noexcept; // Оператор сравнения на равенство
    bool operator!=(const iaVector& otherVector) const noexcept; // Оператор сравнения на неравенство
    iaVector operator||(const iaVector& otherVector) const noexcept; // Оператор нормализации вектора
    
    double* value; ///< Значения вектора
    
private:
    int m; ///< Размер вектора
};

#endif /* iaVector_hpp */
