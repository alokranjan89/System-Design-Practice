#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <vector>

class Employee {
public:
    virtual void show(int indent = 0) const = 0;
    virtual ~Employee() = default;
};

class IndividualContributor : public Employee {
private:
    std::string name;
    std::string role;

public:
    IndividualContributor(std::string name, std::string role)
        : name(std::move(name)), role(std::move(role)) {}

    void show(int indent = 0) const override {
        std::cout << std::string(indent, ' ') << name << " - " << role << '\n';
    }
};

class Manager : public Employee {
private:
    std::string name;
    std::vector<std::unique_ptr<Employee>> team;

public:
    explicit Manager(std::string name) : name(std::move(name)) {}

    void add(std::unique_ptr<Employee> employee) {
        team.push_back(std::move(employee));
    }

    void show(int indent = 0) const override {
        std::cout << std::string(indent, ' ') << name << " - Manager\n";
        for (const auto& employee : team) {
            employee->show(indent + 2);
        }
    }
};

int main() {
    auto ceo = std::make_unique<Manager>("Ava");
    auto engineering = std::make_unique<Manager>("Noah");
    auto design = std::make_unique<Manager>("Mia");

    engineering->add(std::make_unique<IndividualContributor>("Liam", "Developer"));
    engineering->add(std::make_unique<IndividualContributor>("Olivia", "Developer"));
    design->add(std::make_unique<IndividualContributor>("Ethan", "Designer"));

    ceo->add(std::move(engineering));
    ceo->add(std::move(design));

    ceo->show();
}
