#include <iostream>
// Abstract Product
class Product { 
    public:
        virtual void display() = 0;
};

// Concrete Product A
class ConcreteProductA : public Product {
    public:
        void display() override {
            std::cout << "Concrete Product A" << std::endl;
        }
};

// Concrete Product B
class ConcreteProductB : public Product {
    public:
        void display() override {
            std::cout << "Concrete Product B" << std::endl;
        }
};

// Abstract Factory
class Factory {
    public:
        virtual Product* createProduct() = 0;
};

// Concrete Factory A
class ConcreteFactoryA : public Factory {
    public:
        Product* createProduct() override {
            return new ConcreteProductA();
        }
};

// Concrete Factory B
class ConcreteFactoryB : public Factory {
    public:
        Product* createProduct() override {
            return new ConcreteProductB();
        }
};

int main() {
    Factory* factoryA = new ConcreteFactoryA();
    Product* productA = factoryA->createProduct();
    productA->display();
    Factory* factoryB = new ConcreteFactoryB();
    Product* productB = factoryB->createProduct();
    productB->display();
    delete factoryA;
    delete factoryB;
    delete productA;
    delete productB;
    return 0;
}
