//
// Created by Ruslan Sirazhetdinov on 04.03.2020.
//

template <typename T, std::size_t size>
void array_print(T(&array)[size]) {
    int last = size - 1;
    for (int i = 0; i < last; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << array[last] << std::endl;
}

int main()
{
    char a[5] = {"ASFD"};
    array_print(a);
}