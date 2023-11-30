#include <iostream>

class Product {
public:
    double getPrice(int productId, int quantity ) {
        // Fetch product price from the database
        // ...

        // Calculate the total price
        double price = 1.5 * quantity; /* some calculation */;
        return price;
    }
};

class PaymentProcessor {
public:
    void chargeCustomer(double amount) {
        // Implement logic to charge the customer
        // ...
        std::cout << "Customer charged: $" << amount << std::endl;
    }
};

class InventoryManager {
public:
    void updateInventory(int productId, int quantity) {
        // Implement logic to update inventory
        // ...
        std::cout << "Inventory updated for product " << productId << std::endl;
    }
};

class OrderProcessor {
private:
    Product product;
    PaymentProcessor paymentProcessor;
    InventoryManager inventoryManager;

    void sendConfirmation() {
        // Implement logic to send order confirmation
        // ...
        std::cout << "Order confirmation sent" << std::endl;
    }
public:
    void processOrder(int productId, int quantity) {
        // Fetch product details from the database
        // ...

        // Validate the order quantity
        if (quantity <= 0) {
            std::cout << "Invalid quantity. Order not processed." << std::endl;
            return;
        }

        // Calculate the total price
        double price = product.getPrice(productId, quantity );

        // Charge the customer
        paymentProcessor.chargeCustomer(price);

        // Update inventory
        inventoryManager.updateInventory(productId, quantity);

        // Send order confirmation
        sendConfirmation();
    }
};

int main() {
    OrderProcessor orderProcessor;
    orderProcessor.processOrder(1, 3);

    return 0;
}
