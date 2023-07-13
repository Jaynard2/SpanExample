#include <span>
#include <vector>
#include <iostream>
#include <ranges>

#define sizeofArray(arr) sizeof(arr) / sizeof(arr[0])

void doSomethingWithVec(const std::vector<int>& arr);
void doSomethingWithSpan(std::span<const int> arr);
void* operator new(std::size_t s);

int main()
{
    int arr[] = {1, 2, 3, 4};
    std::cout << "With Vectors\n";
    /*
        Vectors own the memory that that they operate over.
        Because of this, when a c-array is passed into a vector,
        the array is copied onto the heap.
    */
    doSomethingWithVec({arr, arr + sizeofArray(arr)});
    std::cout << "With Spans\n";
    /*
        Spans do not own the memory they have a view over.
        This prevents any memory allocations from occuring, no matter
        the type used to create it. 
    */
    doSomethingWithSpan({arr, arr + sizeofArray(arr)});
    return 0;
}

void doSomethingWithVec(const std::vector<int>& arr)
{
    auto s = arr | std::views::transform([](const auto& c){ return std::to_string(c) + ","; }) | std::views::join;
    for(const auto& c : s) std::cout << c;
    std::cout << std::endl;
}

void doSomethingWithSpan(std::span<const int> arr)
{
    auto s = arr | std::views::transform([](const auto& c){ return std::to_string(c) + ","; }) | std::views::join;
    for(const auto& c : s) std::cout << c;
    std::cout << std::endl;
}

void* operator new(std::size_t s)
{
    std::cout << "Allocating " << s << " bytes\n";
    return std::malloc(s);
}
