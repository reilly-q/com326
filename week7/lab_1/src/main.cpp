/*
 * main.cpp
 *
 * Version Information v1.0
 * Author: Quinn Reilly
 * Date: 20 oct 2020
 *
 * Copyright notice
 */

// Include classes and headers
#include "../inc/common.h"

// Challenge Methods
void challenge1(); /* Warm up exercise. */
void challenge2(); /* Stack growth */
void challenge3(); /* Heap growth */
void challenge4(); /* More raw pointers */
void challenge5();
void challenge6();
void challenge7();

// Other methods
int* GetPointer();
void PrintStackArrayAddresses(uintptr_t[10]);

void SetFloatValues(float* floatArray);
void PrintHeapArrayAddresses(float* floatArray);

int HowMany();
int* CreateInts(int idx);
void ReadInts(int* arrayInt, int idx);
void DisplayInts(int* arrayInt, int idx);
void FindMaxInts(int* arrayInt, int idx);

void PopulateVector(std::vector<int>& v, int size);
void PrintVector(std::vector<int>& v, int size);

// Main loop
int main() {
    //challenge1();
    //challenge2();
    //challenge3();
    //challenge4();
    //challenge5();
    //challenge6();
    challenge7();

    // End program
    return 0;
}

void challenge1() {
    int* intPtr = GetPointer();
    std::cout << *intPtr << std::endl;

    delete intPtr;
    intPtr = nullptr;
}

void challenge2() {
    uintptr_t array[10];
    int a = 1, b = 2, c = 3, d = 4;
    for(int i = 0; i < 10; i++) {
        array[i] = i + 1;
        std::cout << array[i] << std::endl;
    }

    PrintStackArrayAddresses(array);
}

void challenge3() {
    float* floatPtr{ new float[10] };
    SetFloatValues(floatPtr);
}

void challenge4() {
    int idx = HowMany();
    int* arrIntsPtr = CreateInts(idx);
    ReadInts(arrIntsPtr, idx);
    DisplayInts(arrIntsPtr, idx);
    FindMaxInts(arrIntsPtr, idx);

    delete[] arrIntsPtr;
    arrIntsPtr = nullptr;
}

void challenge5() {
    std::unique_ptr<int> uniquePtr1 = std::make_unique<int>(32);
    std::cout << "The value stored in the memory location: " << *uniquePtr1 << std::endl;
    std::cout << "The address of the unique pointer: " << &uniquePtr1 << std::endl;
    std::cout << "The address of the memory location (&*): " << &*uniquePtr1 << std::endl;

    std::unique_ptr<int> uniquePtr2 = std::move(uniquePtr1);
    std::cout << "The value stored in the memory location: " << *uniquePtr2 << std::endl;
    std::cout << "The address of the unique pointer: " << &uniquePtr2 << std::endl;
    std::cout << "The address of the memory location (&*): " << &*uniquePtr2 << std::endl;
}

void challenge6() {
    std::shared_ptr<std::string> SharedPointerA = std::make_shared<std::string>();
    std::cout << "Please enter a string: ";
    getline(std::cin, *SharedPointerA);

    std::cout << std::endl;

    std::cout << "The address of the unique pointer: " << &SharedPointerA << std::endl;
    std::cout << "The address of the memory location (&*): " << &*SharedPointerA << std::endl;
    std::cout << "The value stored in the memory location: " << *SharedPointerA << std::endl;
    std::cout << "The reference count of the shared pointer: " << SharedPointerA.use_count() << std::endl;

    auto SharedPointerB(SharedPointerA);

    std::cout << "The address of the unique pointer: " << &SharedPointerB << std::endl;
    std::cout << "The address of the memory location (&*): " << &*SharedPointerB << std::endl;
    std::cout << "The value stored in the memory location: " << *SharedPointerB << std::endl;
    std::cout << "The reference count of the shared pointer: " << SharedPointerB.use_count() << std::endl;

    auto SharedPointerC(SharedPointerA);

    std::cout << "The address of the unique pointer: " << &SharedPointerC << std::endl;
    std::cout << "The address of the memory location (&*): " << &*SharedPointerC << std::endl;
    std::cout << "The value stored in the memory location: " << *SharedPointerC << std::endl;
    std::cout << "The reference count of the shared pointer: " << SharedPointerC.use_count() << std::endl;
}

void challenge7() {
    std::vector<int> v1;
    std::vector<int> v2;

    std::cout << "Size before: " << std::endl;
    std::cout << "v1: " << v1.size() << "\t" << v1.capacity() << std::endl;
    std::cout << "v2: " << v2.size() << "\t" << v2.capacity() << std::endl;

    PopulateVector(v1, 100);
    PopulateVector(v2, 100);
    //PrintVector(v1, 1000);
    //PrintVector(v2, 1000);

    std::cout << "Size after: " << std::endl;
    std::cout << "v1: " << v1.size() << "\t" << v1.capacity() << std::endl;
    std::cout << "v2: " << v2.size() << "\t" << v2.capacity() << std::endl;

    std::cout << "\nContent Before: " << std::endl;
    std::cout << "V1: " << std::endl;
    PrintVector(v1, 100);
    std::cout << std::endl;
    std::cout << "V2: " << std::endl;
    PrintVector(v2, 100);

    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());

    std::cout << "\nContent After: " << std::endl;
    std::cout << "V1: " << std::endl;
    PrintVector(v1, 100);
    std::cout << std::endl;
    std::cout << "V2: " << std::endl;
    PrintVector(v2, 100);

    v1.shrink_to_fit();
    v2.shrink_to_fit();

    
}

int* GetPointer() {
    int *x = new int(5);
    return x;
}

void PrintStackArrayAddresses(uintptr_t array[10]) {
    for(int i = 0; i < 10; i++) {
        std::cout << i << " " << array[i] << " " << &array[i] << " " << std::dec << uintptr_t(&array[i]) << std::endl;
    }
}

void SetFloatValues(float* floatArray) {
    float* arrayPtr = floatArray;
    float value{0.0f};

    for(int i = 0; i < 10; i++) {
        //value += 1.1;
        if(value < 10) {
            value += 1.1;
        } else {
            value += 1.0;
        }
        *(arrayPtr + i) = float(value);
        std::cout << floatArray[i] << std::endl;
    }
}

void PrintHeapArrayAddresses(float* floatArray) {
    //std::cout <<
}

int HowMany() {
    int idx = 0;
    std::cout << "How many elements in your integer array:\n";
    std::cin >> idx;
    return idx;
}

int* CreateInts(int idx) {
    int* arrIntsPtr{new int[idx]};
    return arrIntsPtr;
}

void ReadInts(int* arrayInt, int idx) {
    for(int i = 0; i < idx; i++) {
        std::cout << "Enter your integer:\n";
        std::cin >> *(arrayInt + i);
    }
}

void DisplayInts(int* arrayInt, int idx) {
    std::cout << "Your integer values:\n";
    for(int i = 0; i <  idx; i++) {
        std::cout << *(arrayInt + i) << " ";
    }
}

void FindMaxInts(int* arrayInt, int idx) {
    int max = arrayInt[0];
    for(int i = 0; i < idx; i++) {
        if(*(arrayInt + i) > max) {
            max = *(arrayInt + i);
        }
    }

    std::cout << "Max value: " << max << std::endl;
}

void PopulateVector(std::vector<int>& v, int size) {
    for(int i = 0; i < size; i++) {
        v.push_back(rand() % 1000);
    }
}

void PrintVector(std::vector<int>& v, int size) {
    for(int i = 0; i < size; i++) {
        std::cout << v.at(i) << " ";
    }
    std::cout << std::endl;
}
