/*
 ****************************************************************************************************
 *
 *    Компания    : iA
 *    @file       : iaVector.cpp
 *    @brief      : Исполнительный файл для класса iaVector.
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
 *    @description: Этот файл содержит реализацию класса iaVector, который представляет вектор,
 *                   используемый для выполнения различных математических операций. Класс поддерживает
 *                   операции с векторами, такие как сложение, вычитание, скалярное произведение,
 *                   умножение на скаляр и инверсия вектора. Также включены методы для работы с
 *                   элементами вектора, инициализации и вывода.
 *
 *    @methods     :
 *                   - iaVector::iaVector(); // Конструктор по умолчанию
 *                   - iaVector::iaVector(int m); // Конструктор с размером
 *                   - iaVector::iaVector(int m, const double values[]); // Конструктор со значениями
 *                   - iaVector::iaVector(const iaVector& otherVector); // Конструктор копирования
 *                   - iaVector::~iaVector(); // Деструктор
 *                   - int iaVector::sizeOfVector() const; // Возвращает размер вектора
 *                   - void iaVector::printVector() const; // Печатает вектор
 *                   - double& iaVector::operator[](int j); // Оператор доступа
 *                   - iaVector iaVector::operator+(const iaVector& otherVector) const; // Сложение
 *                   - iaVector iaVector::operator-(const iaVector& otherVector) const; // Вычитание
 *                   - double iaVector::dotProduct(const iaVector& otherVector) const; // Скалярное произведение
 *                   - double iaVector::L2norm() const; // Вычисление L2 нормы
 *                   - double iaVector::sum() const; // Вычисление суммы элементов
 *                   - double iaVector::maxElement() const; // Вычисление максимального элемента
 *                   - double iaVector::minElement() const; // Вычисление минимального элемента
 *                   - double iaVector::angleBetween(const iaVector& otherVector) const noexcept; // Вычисление угла между векторами
 *                   - void iaVector::inverting() noexcept; // Инверсия вектора
 *
 *    @properties  :
 *                   - int m;            ///< Размер вектора
 *                   - double* value;    ///< Значения вектора
 *
 *    @copyright    : Этот файл является частью проектов iA. Он лицензирован под MIT License.
 *                   Вы можете использовать, изменять и распространять этот код, при условии,
 *                   что Вы предоставите соответствующее упоминание об авторе.
 * **************************************************************************************************
 */\
#include "iaVector.hpp"

/**
 * @brief Конструктор по умолчанию.
 * Инициализирует вектор с размером 0 и нулевым указателем на значения.
 */
iaVector::iaVector() : m(0), value(nullptr) {}

/**
 * @brief Конструктор с заданным размером.
 * @param m Размер вектора. Если m > 0, выделяется память для значений.
 */
iaVector::iaVector(int m) : m(m), value(m > 0 ? new double[m]() : nullptr) {}

/**
 * @brief Конструктор с заданным размером и значениями.
 * @param m Размер вектора.
 * @param values Массив значений, которые будут скопированы в вектор.
 */
iaVector::iaVector(int m, const double values[]) : m(m), value(nullptr) {
    if (m > 0) {
        value = new double[m](); // Выделение памяти для значений и инициализация нулями
        for (int i = 0; i < m; i++) {
            value[i] = values[i]; // Копирование значений из массива
        }
    }
}

/**
 * @brief Конструктор копирования.
 * @param otherVector Вектор, который будет скопирован.
 */
iaVector::iaVector(const iaVector& otherVector) : m(otherVector.m), value(nullptr) {
    if (m > 0) {
        value = new double[m](); // Выделение памяти для значений
        for (int i = 0; i < m; i++) {
            value[i] = otherVector.value[i]; // Копирование значений
        }
    }
}

/**
 * @brief Деструктор.
 * Освобождает выделенную память для значений вектора.
 */
iaVector::~iaVector() {
    delete[] value; // Освобождение памяти
}

/**
 * @brief Возвращает размер вектора.
 * @return Размер вектора.
 */
int iaVector::sizeOfVector() const {
    return m;
}

/**
 * @brief Печатает содержимое вектора.
 */
void iaVector::printVector() const {
//    std::cout << "Vector size : " << m << std::endl;
    std::cout << "|";
    for (int j = 0; j < m; j++) {
        std::cout << std::fixed << std::setprecision(2) << " " << value[j] << "|"; // Печать значений
    }
    std::cout << std::endl;
}

/**
 * @brief Вычисляет сумму элементов вектора.
 * @return Сумма элементов вектора.
 */
double iaVector::sum() const {
    double sum = 0.0; // Переменная для хранения суммы
    for (int i = 0; i < m; i++) {
        sum += value[i]; // Суммируем элементы вектора
    }
    return sum; // Возвращаем сумму
}

/**
 * @brief Вычисляет L2 норму вектора.
 * @return L2 норма вектора.
 */
double iaVector::L2norm() const {
    double sum = 0.0; // Переменная для хранения суммы квадратов
    for (int i = 0; i < m; i++) {
        sum += value[i] * value[i]; // Суммируем квадраты элементов
    }
    return sqrt(sum); // Возвращаем квадратный корень из суммы
}

/**
 * @brief Вычисляет L1 норму вектора.
 * @return L1 норма вектора.
 */
double iaVector::L1norm() const {
    double sum = 0.0; // Переменная для хранения суммы абсолютных значений
    for (int i = 0; i < m; i++) {
        sum += abs(value[i]); // Суммируем абсолютные значения элементов
    }
    return sum; // Возвращаем сумму
}
/*
iaVector iaVector::normalize() {
    iaVector result
    return
*/
/**
 * @brief Вычисляет L∞ норму вектора.
 * @return L∞ норма вектора.
 */
double iaVector::LMnorm() const {
    double max = abs(value[0]); // Инициализируем максимальное значение первым элементом
    for (int i = 1; i < m; i++) { // Начинаем с 1, так как 0 уже учтён
        if (abs(value[i]) > max) {
            max = abs(value[i]); // Обновляем максимальное значение
        }
    }
    return max; // Возвращаем максимальное значение
}

/**
 * @brief Вычисляет скалярное произведение двух векторов.
 * @param otherVector Вектор, с которым будет вычислено скалярное произведение.
 * @return Результат скалярного произведения.
 * @throws std::runtime_error Если размеры векторов не совпадают.
 */
double iaVector::dotProduct(const iaVector &otherVector) const {
    if (m != otherVector.m) {
        throw std::runtime_error("Ошибка: Размеры векторов не совпадают."); // Выбрасываем исключение
    }
    
    double result = 0.0; // Переменная для хранения результата
    for (int i = 0; i < m; i++) {
        result += value[i] * otherVector.value[i]; // Скалярное произведение
    }
    return result; // Возвращаем результат
}

/**
 * @brief Вычисляет угол между двумя векторами.
 * @param otherVector Вектор, с которым будет вычислен угол.
 * @return Угол между векторами в радианах.
 * @throws std::runtime_error Если размеры векторов не совпадают.
 */
double iaVector::angleBetween(const iaVector &otherVector) const noexcept {
    if (m != otherVector.m) {
        throw std::runtime_error("Ошибка: Размеры векторов не совпадают."); // Выбрасываем исключение
    }
    
    double dotProd = dotProduct(otherVector); // Скалярное произведение
    double l2vec1 = L2norm(); // Норма первого вектора
    double l2vec2 = otherVector.L2norm(); // Норма второго вектора
    
    double cosangle = dotProd / (l2vec1 * l2vec2); // Вычисление косинуса угла
    return acos(cosangle); // Возвращаем угол
}

/**
 * @brief Вычисляет среднее значение элементов вектора.
 * @return Среднее значение.
 *//*
double iaVector::avverage() const {
    if (m == 0) return 0.0; // Проверка на пустой вектор
    double sum = this->sum(); // Используем метод sum для вычисления суммы
    return sum / m; // Возвращаем среднее значение
}
*/
/**
 * @brief Сортирует элементы вектора по возрастанию.
 */
void iaVector::sortAscending() {
    if (m <= 0) {
        throw std::runtime_error("Ошибка: Вектор пуст."); // Выбрасываем исключение
    }
    
    double tmp = 0.0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m - 1 - i; j++) {
            if (value[j] > value[j + 1]) {
                    // Обмен значениями
                tmp = value[j];
                value[j] = value[j + 1];
                value[j + 1] = tmp;
            }
        }
    }
}

/**
 * @brief Сортирует элементы вектора по убыванию.
 */
void iaVector::sortDescending() {
    if (m <= 0) {
        throw std::runtime_error("Ошибка: Вектор пуст."); // Выбрасываем исключение
    }
    
    double tmp = 0.0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m - 1 - i; j++) {
            if (value[j] < value[j + 1]) {
                    // Обмен значениями
                tmp = value[j];
                value[j] = value[j + 1];
                value[j + 1] = tmp;
            }
        }
    }
}

/**
 * @brief Находит максимальный элемент вектора.
 *
 * @return Максимальный элемент вектора.
 * @throws std::runtime_error Если вектор пуст.
 */
double iaVector::maxElement() const {
    if (this->m == 0) { // Проверка на пустой вектор
        throw std::runtime_error("Ошибка: Вектор пуст."); // Выбрасываем исключение
    }
    
    double max = this->value[0]; // Инициализация максимального элемента
    for (int i = 1; i < this->m; i++) { // Начинаем с первого элемента
        if (this->value[i] > max) { // Сравниваем с текущим максимальным
            max = this->value[i]; // Обновляем максимальный элемент
        }
    }
    return max; // Возвращаем максимальный элемент
}

/**
 * @brief Находит минимальный элемент вектора.
 *
 * @return Минимальный элемент вектора.
 * @throws std::runtime_error Если вектор пуст.
 */
double iaVector::minElement() const {
    if (this->m == 0) { // Проверка на пустой вектор
        throw std::runtime_error("Ошибка: Вектор пуст."); // Выбрасываем исключение
    }
    
    double min = this->value[0]; // Инициализация минимального элемента
    for (int i = 1; i < this->m; i++) { // Начинаем с первого элемента
        if (this->value[i] < min) { // Сравниваем с текущим минимальным
            min = this->value[i]; // Обновляем минимальный элемент
        }
    }
    return min; // Возвращаем минимальный элемент
}


double iaVector::avverage() const {
    double sum=this->value[0];
    int size = this->m;
    for (int i = 1; i < this->m; i++) {
        sum += this->value[i];
    }
    
    return sum / size;
}


/**
 * @brief Оператор присваивания.
 * @param otherVector Вектор, который будет присвоен.
 * @return Ссылка на текущий объект.
 */
iaVector& iaVector::operator=(const iaVector& otherVector) noexcept {
    if (this != &otherVector) { // Проверка на самоприсваивание
        this->m = otherVector.m; // Копирование размера
        for (int i = 0; i< otherVector.m; i++) {
            this->value[i] = otherVector.value[i];
        }
    }
    return *this; // Возврат текущего объекта
}

/**
 * @brief Оператор сложения.
 * @param otherVector Вектор, который будет добавлен.
 * @return Новый вектор, представляющий сумму.
 */
iaVector iaVector::operator+(const iaVector &otherVector) noexcept {
    iaVector result(otherVector.m);
    if (this->m != otherVector.m) {
        return 0; // Возврат 0, если размеры не совпадают
    } else {
        for (int j = 0; j < this->m; j++) {
            result.value[j] = this->value[j] + otherVector.value[j]; // Сложение соответствующих элементов
        }
    }
    return result;
}

/**
 * @brief Оператор вычитания.
 * @param otherVector Вектор, который будет вычтен.
 * @return Новый вектор, представляющий разность.
 */
iaVector iaVector::operator-(const iaVector &otherVector) noexcept {
    iaVector result(this->m);
    if (this->m == otherVector.m) {
        for (int i = 0; i < this->m; i++) {
            result.value[i] = this->value[i] - otherVector.value[i]; // Вычитание соответствующих элементов
        }
    }
    return result;
}

/**
 * @brief Оператор умножения.
 * @param otherVector Вектор, который будет умножен.
 * @return Новый вектор, представляющий произведение.
 */
iaVector iaVector::operator*(const iaVector &otherVector) noexcept {
    iaVector result(this->m);
    if (this->m == otherVector.m) {
        for (int i = 0; i < this->m; i++) {
            result.value[i] = this->value[i] * otherVector.value[i]; // Умножение соответствующих элементов
        }
    }
    return result;
}

/**
 * @brief Оператор умножения на скаляр.
 * @param scal Скаляр, на который будет умножен вектор.
 * @return Новый вектор, представляющий произведение.
 */
iaVector iaVector::operator*(double scal) {
    iaVector result(this->m);
    for (int i = 0; i < this->m; i++) {
        result.value[i] = this->value[i] * scal; // Умножение каждого элемента на скаляр
    }
    return result;
}

/**
 * @brief Инвертирует элементы вектора.
 *
 * Этот метод меняет порядок элементов вектора на противоположный.
 * Если вектор пуст, выбрасывается исключение.
 *
 * @throws std::runtime_error Если вектор пуст.
 */
void iaVector::inverting() noexcept {
    int size = this->m;
    if (size == 0) {
        throw std::runtime_error("Ошибка: Вектор пуст."); // Выбрасываем исключение
    }
    int i = 0; // Индекс с начала вектора
    int j = size - 1; // Индекс с конца вектора
    do {
        double tmpvar = this->value[i]; // Сохраняем значение элемента с индексом i
        
        this->value[i] = this->value[j]; // Меняем местами элементы
        this->value[j] = tmpvar; // Восстанавливаем сохраненное значение
        i++; // Переходим к следующему элементу с начала
        j--; // Переходим к предыдущему элементу с конца
    } while (i < j); // Продолжаем, пока индексы не пересекутся
}

/**
 * @brief Оператор доступа по индексу.
 * @param j Индекс элемента.
 * @return Ссылка на элемент вектора.
 * @throws std::out_of_range Если индекс выходит за пределы.
 */
double& iaVector::operator[](int j) {
    if (j < 0 || j >= m) { // Проверка на выход за пределы
        throw std::out_of_range("Index out of bounds.");
    }
    return value[j]; // Возврат элемента
}

/**
 * @brief Оператор сравнения на равенство.
 * @param otherVector Вектор для сравнения.
 * @return true, если векторы равны; иначе false.
 */
bool iaVector::operator==(const iaVector &otherVector) const noexcept {
    if (this->m != otherVector.m) return false; // Проверка на равенство размеров
    for (int i = 0; i < this->m; i++) {
        if (this->value[i] != otherVector.value[i]) {
            return false; // Если хотя бы одно значение не совпадает
        }
    }
    return true; // Векторы равны
}

/**
 * @brief Оператор сравнения на неравенство.
 * @param otherVector Вектор для сравнения.
 * @return true, если векторы не равны; иначе false.
 */
bool iaVector::operator!=(const iaVector &otherVector) const noexcept {
    return !(*this == otherVector); // Используем оператор равенства
}

/**
 * @brief Оператор деления на норму.
 * @param otherVector Вектор для деления.
 * @return Новый вектор, представляющий результат деления.
 */
iaVector iaVector::operator||(const iaVector &otherVector) const noexcept {
    double norm = otherVector.L2norm();
        // Проверка на нулевую норму
    if (norm != 0) { // Включил проверку на нулевую норму
        std::cout << norm << std::endl;
        iaVector result(otherVector);
        
        for (int i = 0; i < this->m; i++) {
            std::cout << result.value[i] << std::endl;
            result.value[i] = result.value[i] / norm; // Деление каждого элемента на норму
            std::cout << result.value[i] << std::endl;
        }
        return result;
    } else {
            // Обработка случая, когда норма равна нулю
        std::cerr << "Ошибка: Норма равна нулю." << std::endl; // Вывод ошибки
        return iaVector(); // Возвращаем пустой вектор или можно выбросить исключение
    }
    
}


