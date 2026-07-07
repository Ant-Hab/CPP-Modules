/*
** Default Constructor: Initializes base std::stack.
*/
template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

/*
** Destructor: Cleans up the MutantStack object.
*/
template <typename T>
MutantStack<T>::~MutantStack() {}

/*
** Copy Constructor: Copies the base std::stack.
*/
template <typename T>
MutantStack<T>::MutantStack(const MutantStack &other) : std::stack<T>(other) {}

/*
** Assignment Operator: Assigns base std::stack.
*/
template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack &other) {
    if (this != &other) {
        std::stack<T>::operator=(other);
    }
    return *this;
}

/*
** begin: Returns an iterator to the beginning of the container.
*/
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
    return this->c.begin();
}

/*
** end: Returns an iterator to the end of the container.
*/
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
    return this->c.end();
}