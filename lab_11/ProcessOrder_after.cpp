#include <iostream>

class Product {
public:
    double getPrice(int productId, int quantity) {
        double price = 1.5f * quantity;
        return price;
    }
};

class PaymentProcessor {
public:
    void chargeCustomer(double amount) {
        std::cout << "Customer charged: $" << amount << std::endl;
    }
};

class InventoryManager {
public:
    void updateInventory(int productId, int quantity) {
        std::cout << "Inventory updated for product " << productId << std::endl;
    }
};

class OrderProcessor {
private:
    Product product;
    PaymentProcessor paymentProcessor;
    InventoryManager inventoryManager;

    void sendConfirmation() {
        std::cout << "Order confirmation sent" << std::endl;
    }

public:
    void processOrder(int productId, int quantity) {
        //validate, get price, charge to customer,
        //update inventory, send confirmation

        if (quantity <= 0) {
            std::cout << "Invalid quantity. Order not processed." << std::endl;
            return;
        }

        double price = product.getPrice(productId, quantity);
        paymentProcessor.chargeCustomer(price);
        inventoryManager.updateInventory(productId, quantity);
        sendConfirmation();
    }
};

int main() {
    OrderProcessor orderProcessor;
    orderProcessor.processOrder(1, 3);
    return 0;
}
