#pragma once

#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <iostream>

#include "staff.hpp"
class Cargo;

class Ship {

    public:
    Ship()
        : id_(-1)
    {}
    Ship(int capacity, int maxCrew, int speed, const std::string& name, size_t id, size_t crew)
        : capacity_(capacity)
        , maxCrew_(maxCrew)
        , speed_(speed)
        , name_(name)
        , id_(id)
        , crew_(crew)
    {}
    Ship(int maxCrew, int speed, size_t id)
        : Ship(0, maxCrew, speed, "", id, 0)
    {}

    void setName(const std::string& name) { name_ = name; }

    size_t getCapacity() const  { return capacity_; }
    size_t getMaxCreaw() const  { return maxCrew_; }
    size_t getSpeed() const     { return speed_; }
    std::string getName() const { return name_; }
    size_t getId() const        { return id_; }
    size_t getCrew() const      { return crew_; }  

    Ship& operator+=(const int addPerson) {
        crew_ += addPerson;
        return *this;
    }
    Ship& operator-=(const int minusPerson) {
        crew_ -= minusPerson;
        return *this;
    }

    void addLoad(std::shared_ptr<Cargo> obj) {
        objects_.push_back(obj);
    }
    void unLoad(std::shared_ptr<Cargo> obj) {
        if (objects_.size() == 0) {
            std::cout << "Your loader is empty!!!" << "\n";
        }
        else {
            objects_.erase(std::remove(objects_.begin(), objects_.end(), obj), objects_.end());
        }
    }
    void read() const {
        std::cout << "Ship conteiner: " << "\n";
        for (const auto& element : objects_) {
            element->read();
        }
    }

    private:
    size_t capacity_;
    size_t maxCrew_;
    size_t speed_;
    std::string name_;
    const size_t id_;
    size_t crew_;

    std::vector<std::shared_ptr<Cargo>> objects_;

};