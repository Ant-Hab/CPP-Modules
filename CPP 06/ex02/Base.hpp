#pragma once

class Base {
public:
	/*
	** Virtual destructor required for polymorphism.
	*/
	virtual ~Base() = default;
};

/*
** Empty derived classes for dynamic_cast testing.
*/
class A : public Base {};
class B : public Base {};
class C : public Base {};