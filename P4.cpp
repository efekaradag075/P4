#include <iostream>
#include <cstdlib>
#include <cctype>

char* read_dynamic_line() {
    std::size_t capacity = 10;
    std::size_t length = 0;
    
    char* buffer = static_cast<char*>(std::malloc(capacity * sizeof(char)));
    
    if (!buffer) {
        std::cerr << "Hafiza tahsis edilemedi!" << std::endl;
        return nullptr;
    }

    char c;
    while (std::cin.get(c) && c != '\n') {
        if (length + 1 >= capacity) {
            capacity *= 2;
            char* new_buffer = static_cast<char*>(std::realloc(buffer, capacity * sizeof(char)));
            if (!new_buffer) {
                std::cerr << "Hafiza genisletilemedi!" << std::endl;
                std::free(buffer);
                return nullptr;
            }
            buffer = new_buffer;
        }
        buffer[length++] = c;
    }

    buffer[length] = '\0';
    return buffer;
}

std::size_t get_string_length(const char* str) {
    if (!str) return 0;
    std::size_t len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

int main() {
    std::cout << "Lutfen C-style string metni giriniz: ";
    char* my_string = read_dynamic_line();

    if (my_string) {
        std::cout << "\n=== Laboratuvar Sonucu ===" << std::endl;
        std::cout << "Okunan Metin: " << my_string << std::endl;
        std::cout << "Metin Uzunlugu (Karakter Sayisi): " << get_string_length(my_string) << std::endl;
        
        std::free(my_string);
    }

    return 0;
}
