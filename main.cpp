#include <iostream>
#include "../IAClasses/iaPerceptron.hpp"
#include "../MathClasses/iaVector.hpp"

int main() {
    
        // Создаем перцептрон с 2 входами
    iaPerceptron perceptron(2);
    
        // Печатаем начальные параметры перцептрона
    perceptron.printPerceptron();
    
        // Обучающие данные (входы и целевые значения)
    iaVector input1(2, new double[2]{0.0, 0.0});
    iaVector input2(2, new double[2]{0.0, 1.0});
    iaVector input3(2, new double[2]{1.0, 0.0});
    iaVector input4(2, new double[2]{1.0, 1.0});
    
    double target1 = 0.0; // Ожидаемый результат для (0, 0)
    double target2 = 0.0; // Ожидаемый результат для (0, 1)
    double target3 = 0.0; // Ожидаемый результат для (1, 0)
    double target4 = 1.0; // Ожидаемый результат для (1, 1)
    
        // Обучаем перцептрон
    for (int i = 0; i < 10000; i++) {
        perceptron.train(input1, target1, 0.01, 1.0);
        perceptron.train(input2, target2, 0.01, 1.0);
        perceptron.train(input3, target3, 0.01, 1.0);
        perceptron.train(input4, target4, 0.01, 1.0);
    }
    
        // Тестируем предсказания
    std::cout << "Prediction for (0, 0): " << perceptron.predict(input1) << std::endl;
    std::cout << "Prediction for (0, 1): " << perceptron.predict(input2) << std::endl;
    std::cout << "Prediction for (1, 0): " << perceptron.predict(input3) << std::endl;
    std::cout << "Prediction for (1, 1): " << perceptron.predict(input4) << std::endl;
    
        // Освобождаем память
    
    return 0;
}

