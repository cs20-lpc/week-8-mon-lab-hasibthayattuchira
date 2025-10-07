template <typename T>
ArrayStack<T>::ArrayStack(int i) {
    // TODO
    if (i <= 0) {
        maxSize = 100; // base/default case
    }
    else {
        maxSize = i;
    }
    buffer = new T[maxSize];
    this->length = 0;
}

template <typename T>
ArrayStack<T>::ArrayStack(const ArrayStack<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
ArrayStack<T>& ArrayStack<T>::operator=(const ArrayStack<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
ArrayStack<T>::~ArrayStack() {
    clear();
}

template <typename T>
void ArrayStack<T>::clear() {
    // TODO
    delete[] buffer;
    buffer = new T[maxSize]; // should be able to create a ne empty array
    this->length = 0;
}

template <typename T>
void ArrayStack<T>::copy(const ArrayStack<T>& copyObj) {
    // TODO
    maxSize = copyObj.maxSize;
    this->length = copyObj.length;
    buffer = new T[maxSize];
    for (int i = 0; i < this->length; i++){ // copy process
        buffer[i] = copyObj.buffer[i];
    }
}

template <typename T>
int ArrayStack<T>::getLength() const {
    return this->length;
}

template <typename T>
int ArrayStack<T>::getMaxSize() const {
    return maxSize;
}

template <typename T>
bool ArrayStack<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
bool ArrayStack<T>::isFull() const {
    return this->length == maxSize;
}

template <typename T>
T ArrayStack<T>::peek() const {
    // TODO
    if(isEmpty()){
        throw string("Error, cannot peek empty stack");
    }
    return buffer[this->length - 1];
}

template <typename T>
void ArrayStack<T>::pop() {
    // TODO
    if(isEmpty()){
        throw string("Error, cannot pop from empty stack");
    }
    this->length--;
}

template <typename T>
void ArrayStack<T>::push(const T& elem) {
    // TODO
    if(isFull()){
        throw string("Error, cannot push full stack");
    }
    buffer[this->length++] = elem;
}

template <typename T>
void ArrayStack<T>::rotate(typename Stack<T>::Direction dir) {
    // TODO -- this was tricky for me to do so I needed outside help to work on some of this
    if(isEmpty()){
        throw string("Error, cannot rotate empty stack");

    }
    if(this->length == 1){ // base case no effect for one element stack
        return;
    }
    if(dir == Stack<T>::RIGHT){ // should be able to move top element to the bottom
        T top = buffer[this->length - 1]; // save top element
        for(int i = this->length - 1; i > 0; i--){ // shift of elements
            buffer[i] = buffer[i - 1]; 
        }
        buffer[0] = top; // top now becomes bottom
    }
    else if (dir == Stack<T>::LEFT){ // should be able to move bottom element to the top
        T bottom = buffer[0]; // save bottom element
        for(int i = 0; i < this->length - 1; i++){ // shift of elements
            buffer[i] = buffer[i + 1];
        }
        buffer[this->length - 1] = bottom; // bottom now becomes top
    }
}

template <typename T>
ostream& operator<<(ostream& outStream, const ArrayStack<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "Stack is empty, no elements to display.\n";
    }
    else {
        for (int i = myObj.length - 1; i >= 0; i--) {
            outStream << (i == myObj.length - 1 ? "top\t" : "\t")
                      << myObj.buffer[i] << endl;
        }
    }

    return outStream;
}

