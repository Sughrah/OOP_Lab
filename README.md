# OOP_Lab
Object-Oriented Programming (OOP) 
Object-Oriented Programming (OOP) is a programming paradigm that organizes software design around objects rather than functions and procedures. It promotes modularity, reusability, and scalability by structuring code into classes and objects.

This guide covers:
✅ Core Concepts of OOP
✅ Four Pillars of OOP
✅ Advantages & Disadvantages
✅ Real-World Examples
✅ OOP in Different Languages

1. What is OOP?
OOP is a way of structuring programs so that:

Data (attributes) and behavior (methods) are bundled into objects.

Objects interact with each other to perform tasks.

Code is organized into classes, which act as blueprints for objects.

Example: Car as an Object
Attribute (State)	Method (Behavior)
color = "Red"	accelerate()
model = "Tesla"	brake()
speed = 0	honk()
2. Core Concepts
2.1 Class & Object
Class: A template/blueprint for creating objects.

Object: An instance of a class.

Example in Python
python
class Car:  
    def __init__(self, color, model):  
        self.color = color  
        self.model = model  

    def accelerate(self):  
        print("Car is accelerating!")  

# Creating an object  
my_car = Car("Red", "Tesla")  
my_car.accelerate()  
2.2 Attributes & Methods
Attributes → Variables inside a class (color, model).

Methods → Functions inside a class (accelerate(), brake()).

3. Four Pillars of OOP
3.1 Encapsulation
Bundling data (attributes) and methods that operate on the data into a single unit (class).

Data hiding: Restricting direct access to certain attributes (using private/protected modifiers).

Example
python
class BankAccount:  
    def __init__(self, balance):  
        self.__balance = balance  # Private attribute  

    def deposit(self, amount):  
        self.__balance += amount  

    def get_balance(self):  # Controlled access  
        return self.__balance  
3.2 Inheritance
A child class inherits properties and methods from a parent class.

Promotes code reusability.

Example
python
class Animal:  
    def eat(self):  
        print("Eating...")  

class Dog(Animal):  # Inherits from Animal  
    def bark(self):  
        print("Barking...")  

dog = Dog()  
dog.eat()  # Inherited method  
dog.bark() # Child method  
3.3 Polymorphism
The ability of objects to take different forms.

Method Overriding: Same method name, different implementation in child class.

Method Overloading: Same method name, different parameters (not in Python by default).

Example (Method Overriding)
python
class Bird:  
    def fly(self):  
        print("Flying...")  

class Penguin(Bird):  
    def fly(self):  # Overriding  
        print("Penguins can't fly!")  

penguin = Penguin()  
penguin.fly()  # Output: "Penguins can't fly!"  
3.4 Abstraction
Hiding complex implementation details and exposing only essential features.

Achieved via abstract classes and interfaces.

Example (Python - Abstract Class)
python
from abc import ABC, abstractmethod  

class Shape(ABC):  
    @abstractmethod  
    def area(self):  
        pass  

class Circle(Shape):  
    def __init__(self, radius):  
        self.radius = radius  

    def area(self):  
        return 3.14 * self.radius ** 2  
4. Advantages of OOP
✔ Modularity – Code is organized into reusable classes.
✔ Reusability – Inheritance reduces redundant code.
✔ Scalability – Easier to maintain and extend.
✔ Security – Encapsulation protects data integrity.

5. Disadvantages of OOP
   
❌ Steeper learning curve compared to procedural programming.
❌ Slower execution in some cases due to abstraction.
❌ Overhead in small programs where OOP may be unnecessary.

7. OOP in Different Languages
Language	Class Syntax	Inheritance	Encapsulation
Python	class Car:	class Child(Parent):	self.__private_var
Java	class Car { ... }	class Child extends Parent	private int var;
C++	class Car { ... };	class Child : public Parent	private: int var;
8. Real-World Applications
Game Development (Characters, Items as Objects)

Banking Systems (Accounts, Transactions)

E-commerce (Products, Users, Orders)

Conclusion
OOP is a powerful paradigm for structuring large-scale applications. By understanding classes, objects, inheritance, polymorphism, encapsulation, and abstraction, you can write cleaner, reusable, and scalable code.
