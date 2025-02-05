Understanding Class Composition and Inheritance

This is an exercise to help solidify your understanding of class composition and inheritance. You will experiment with using class methods and class members with varying access (e.g. public, private, and protected). There was an example used in class with the Robot class. You can review that as well if you need more practice. Finally, next week's lab05 will show you how you can frame inheritance to take advantage of polymorphism.

There are a total of 9 questions for you to consider, but you are not required to hand anything in. The next retrieval practice will cover composition and inheritance. Throughout the exercise, you will be asked to comment and uncomment certain lines of code to see what happens. A makefile has been included for your convenience, and the executable is called inherit.
ComposedClass

The ComposedClass has an ObjectClass object as a member variable (in other words, the ComposedClass HAS-A ObjectClass object). To start with, the ObjectClass has member variables var_a_ and var_b_.
Accessing the Embedded Object

In turn, comment out each of the cout statements within the Print() member function in composed.h, as shown below, and compile each time to see what happens.

Q1. Attempting to print var_a_ and var_b_ will result in a compilation error, which seems reasonable. Briefly explain why it doesn't compile.

Q2. The ComposedClass contains an ObjectClass object to which var_a_ and var_b_ belong, and yet when you try to print them out, those lines will not compile. Briefly explain why.

Q3. ComposedClass probably needs to interact with object_ members. How will you give ComposedClass access (and don't say "make them public")?

class ComposedClass {
public:
  void Print() {
    cout << "in ComposedClass... ";
    //cout << "var_a_ " << var_a_ << endl;
    //cout << "var_b_ " << var_b_ << endl;
    //cout << "object var_a_ " << object_.var_a_ << endl;
    //cout << "object var_b_ " << object_.var_b_ << endl;
    object_.Print();
  }
protected:
  //int var_b_;
private:
  ObjectClass object_;
  //int var_a_;
};

Scoping

Uncomment the declaration of var_a_ and var_b_ inside the ComposedClass definition under private and protected so that it now too has these variables.

Q4. State which of the 4 'cout' statements can now be successfully compiled? Briefly explain why they can now be compiled? And why doesn't the compiler get confused about which var_a_ and var_b_ is being referenced?
DerivedClass

The DerivedClass is inheriting from the ObjectClass (in other words, DerivedClass IS-A ObjectClass). When you start this exercise, the ObjectClass has member variables var_a_ and var_b_, but the DerivedClass does not (or does it??).

In turn, uncomment each of the 'cout' statements in derived.h, as shown below, and determine which successfully compiles.

Q5. For each line, explain why it does or does not compiles.

class DerivedClass : public ObjectClass {
public:
  //DerivedClass() : ObjectClass(1,2) {}
  /*{
    var_a_ = 20;
    var_b_ = 25;
  }*/
  void Print() {
    cout << "in derivedClass... ";
    //cout << "var_a_ " << var_a_ << endl;
    //cout << "var_b_ " << var_b_ << endl;
    //cout << "object var_a_ " << ObjectClass::var_a_ << endl;
    //cout << "object var_b_ " << ObjectClass::var_b_ << endl;
    ObjectClass::Print();
  }
private:
  /*
  int var_a_;
  int var_b_;
  */
};

Overriding Methods

Q6. How is it that you redefined print() in DerivedClass, and yet you can still call print() in the ObjectClass? Isn't the print in the DerivedClass scope replacing the print in the ObjectClass? Explain how that works.
Initializing Objects

Q7. In main, the declaration of isa_object_4_5(4,5) is commented out because it will not compile. Why not? There is a constructor that takes 2 parameters for ObjectClass from which it derives.

Comment out the default constructor for ObjectClass (the one with no parameters). And since there is no longer a default constructor, comment out the first collection of statements in main() that declare the base_object_default and print it out. Also comment out the object_ and corresponding print statement 'object_.Print()" in ComposedClass.

Q8. If you try to compile now, you will get an error in trying to declare a DerivedClass object. Why would removing the ObjectClass default constructor break the DerivedClass?
Constructors

    Put back all the code you just commented out: ObjectClass default constructor, the first collection of statements in main(), the object_ declaration in ComposedClass, as well as object_.Print().

    Add these constructors to DerivedClass:

DerivedClass() : var_a_(0), var_b_(0) {}
DerivedClass(int a, int b) : var_a_(a), var_b_(b) {}

    Uncomment these elements in the DerivedClass:

private:
  int var_a_;
  int var_b_;

cout << "var_a_ " << var_a_ << endl;
cout << "var_b_ " << var_b_ << endl;

    Uncomment the last section in main:

DerivedClass isa_object_4_5(4,5);
cout << "Derived 4,5 : ";
isa_object_4_5.Print();

Q9. Compile and run with inherit. For each of the four sections in main, look at the results and explain the values printed. It should look like this:

Base default: in ObjectClass. priv, prot =  10 15

Base 2,3 : in ObjectClass. priv, prot =  2 3

Composed default : in ComposedClass...
in ObjectClass. priv, prot =  10 15

Derived default : in derivedClass...
var_a_ 0
var_b_ 0
in ObjectClass. priv, prot =  10 15

Derived 4,5 : in derivedClass...
var_a_ 4
var_b_ 5
in ObjectClass. priv, prot =  10 15
