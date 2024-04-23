#pragma once

#include <string>
#include <iostream>


class Cargo {
    public:
    Cargo() = default;
    Cargo(size_t amount, std::string name, size_t basePrice)
        : amount_(amount), name_(name), basePrice_(basePrice)
    {}
    virtual ~Cargo() = default;

    virtual size_t getPrice() const = 0;
    virtual std::string getName() const = 0;
    virtual size_t getAmount() const = 0;
    virtual size_t getBasePrice() const = 0;
    virtual Cargo& operator+=(size_t amount) = 0;
    virtual Cargo& operator-=(size_t amount) = 0;
    virtual void read() const = 0;

    protected:
    size_t amount_;
    std::string name_;
    size_t basePrice_;

};

class Fruit : public Cargo {  
    public:
    Fruit(size_t amount, const std::string& name, size_t basePrice, size_t expire_date, size_t time_elapsed)
        : Cargo(amount, name, basePrice), expire_date_(expire_date), time_elapsed_(time_elapsed)
    {}
    ~Fruit() override = default;

    size_t getPrice() const override {
        if (time_elapsed_ >= expire_date_)
            return 0;
        return static_cast<size_t>(
            basePrice_ * (expire_date_ - time_elapsed_) / expire_date_);
    }

    std::string getName() const override { return name_; }
    size_t getAmount() const override    { return amount_; }
    size_t getBasePrice() const override { return basePrice_; }

    Fruit& operator--() {
        --amount_;
        return *this;
    }
    Fruit& operator+=(size_t amount) override {
        amount_ += amount;
        return *this;
    }
    Fruit& operator-=(size_t amount) override {
        amount_ -= amount;
        return *this;
    }

    size_t getExpireDate() const { return expire_date_; }
    size_t getTimeElapsed() const { return time_elapsed_; }

    void read() const override {
        std::cout << "Amount: "  << getAmount() << "\n";
        std::cout << "Name: "  << getName() << "\n";
        std::cout << "Base Price: "  << getBasePrice() << "\n";
        std::cout << "Expiry date: "  << getExpireDate() << "\n";
        std::cout << "Time Elapse: "  << getTimeElapsed() << "\n";
    }

    protected:
    size_t expire_date_;
    size_t time_elapsed_{0};
};

class Alcohol : public Cargo {
    public:
    Alcohol(size_t amount, const std::string& name, size_t basePrice, size_t procentage)
        : Cargo(amount, name, basePrice), procentage_(procentage)
    {}
    ~Alcohol() override = default;

    size_t getPrice() const override { return basePrice_ * procentage_; }
    std::string getName() const override { return name_; }
    size_t getAmount() const override { return amount_; }
    size_t getBasePrice() const override { return basePrice_; }

    Alcohol& operator+=(size_t amount) override {
        amount_ += amount;
        return *this;
    }
    Alcohol& operator-=(size_t amount) override {
        amount_ -= amount;
        return *this;
    }

    size_t getProcentage() const { return procentage_; }

    void read() const override {
        std::cout << "Amount: "  << getAmount() << "\n";
        std::cout << "Name: "  << getName() << "\n";
        std::cout << "Base Price: "  << getBasePrice() << "\n";
        std::cout << "Procentage: "  << getProcentage() << "\n";
    }

    private:
    size_t procentage_;
};

class Item : public Cargo {
    public:
    enum class Rarity { common = 1,
                        rare = 3,
                        epic = 6,
                        legendary = 10 };
    
    Item(size_t amount, const std::string& name, size_t basePrice, Rarity rarity)
        : Cargo(amount, name, basePrice), rarity_(rarity)
    {}
    ~Item() override = default;

    size_t getPrice() const override { return basePrice_ * static_cast<int>(rarity_); }
    std::string getName() const override { return name_; }
    size_t getAmount() const override { return amount_; }
    size_t getBasePrice() const override {return basePrice_; }

    Item& operator+=(size_t amount) override {
        amount_ += amount;
        return *this;
    }
    Item& operator-=(size_t amount) override {
        amount_ -= amount;
        return *this;
    }

    void read() const override {
        std::cout << "Price afetr rar: " <<getPrice() << "\n";
        std::cout << "Amount: "  << getAmount() << "\n";
        std::cout << "Name: "  << getName() << "\n";
        std::cout << "Base Price: "  << getBasePrice() << "\n";
    }

    private:
    Rarity rarity_;
};

class DryFruit : public Fruit {
    public:

    std::string getName() const override { return "Dry Fruit"; }
    size_t getPrice() const override {
        if (time_elapsed_ >= expire_date_)
            return 0;
        return static_cast<size_t>(
            3 * basePrice_ * (expire_date_ - time_elapsed_) / expire_date_);
    }

    DryFruit& operator--() {
        if (++counter_ == 10) {
            time_elapsed_;
            counter_ = 0;
        }
        return *this;
    }

    private:
    size_t counter_{0};
};