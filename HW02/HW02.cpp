// HW02 - OOP Summary

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Animal {
public:
    virtual ~Animal() {}
    virtual void makeSound() = 0;
};
class Dog : public Animal {
public:
    void makeSound() override {
        cout << "Dog : Woof! Woof!" << endl;
    }
};
class Cat : public Animal {
public:
    void makeSound() override {
        cout << "Cat : Meow! Meow!" << endl;
    }
};
class Cow : public Animal {
public:
    void makeSound() override {
        cout << "Cow : Moo! Moo!" << endl;
    }
};

class Zoo {
private:
    Animal* animals[10]; // 동물 객체를 저장하는 포인터 배열
    int animalCount = 0; // 동물원에 있는 동물의 수

public:
    // 동물을 동물원에 추가하는 함수
    void addAnimal(Animal* animal) {
        if (animalCount >= 10)
        {
            cout << "There's too many Animal in zoo" << endl;
            return;
        }

        animals[animalCount++] = animal;
        if (dynamic_cast<Dog*>(animal))
        {
            cout << "Add Dog in Zoo!" << endl;
        }
        else if (dynamic_cast<Cat*>(animal))
        {
            cout << "Add Cat in Zoo!" << endl;
        }
        else if (dynamic_cast<Cow*>(animal))
        {
            cout << "Add Cow in Zoo!" << endl;
        }
        else
        {
            cout << "Error Added" << endl;
        }
    }

    // 동물원에 있는 모든 동물의 행동을 수행하는 함수
    void performActions() {
        for (size_t i = 0; i < animalCount; i++)
            animals[i]->makeSound();
    }

    // Zoo 객체가 소멸될 때, 동물 벡터에 저장된 모든 동물 객체의 메모리를 해제합니다.
    ~Zoo() {
        for (size_t i = 0; i < animalCount; i++)
            delete animals[i];
    }
};

// 랜덤 동물을 생성하는 함수
Animal* createRandomAnimal() 
{
    Animal* newAnimal = nullptr;

    int num = rand();
    if (num % 3 == 0)
    {
        newAnimal = new Dog();
    }
    else if (num % 3 == 1) 
    {
        newAnimal = new Cat();
    }
    else
    {
        newAnimal = new Cow();
    }
    
    return newAnimal;
}

int main()
{
    // 필수 기능
    Animal* animals[3];
    animals[0] = new Dog();
    animals[1] = new Cat();
    animals[2] = new Cow();

    for (Animal* animal : animals)
    {
        animal->makeSound();
    }
    cout << endl;

    // 도전 기능 
    Zoo zoo;

    // 랜덤 함수가 시간 시드에 맞춰서 랜덤성을 잘 작동하도록
    srand((unsigned int)time(NULL));
    for (size_t i = 0; i < 11; i++)
    {
        zoo.addAnimal(createRandomAnimal());
    }

    // 동물원에 있는 동물의 행동을 실행
    zoo.performActions();

    return 0;
}
