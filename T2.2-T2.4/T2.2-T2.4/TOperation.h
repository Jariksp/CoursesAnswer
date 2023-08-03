#ifndef TOPERATION_H 
#define TOPERATION_H

#include <cstddef> // size_t
#include <fstream> // ifstream, istreambuf_iterator, ios
#include <string> // string
#include <vector> // vector

class TOperation {
    public:
    // Split("ab::cd::ef", "::") => {"a", "b", "c", "d", "e", "f"}
    // Split("Hello, World!", "XYZ") => {"Hello, World!"}
    static std::vector<std::string> Split(const std::string& str, const std::string& delimiter);

    // ReplaceAll("ab::cd::ef", "::", "->") => "ab->cd->ef"
    static void ReplaceAll(std::string& text, const std::string& from, const std::string& to);

    // SubStrsBetween("dummy_;data: %value_; 10% with %percent_;%", "%", "_;") => {"value", "percent"}
    // SubStrsBetween("auto f = [](){};", "}", "[") => {}
    static std::vector<std::string> SubStrsBetween(const std::string& text, const std::string& lhs, const std::string& rhs);

    // ReadFile("C://main.cpp") => "int main() {\n\treturn 0;\n}\n"
    static std::string ReadFile(const std::string& path);

    void Reflactable(std::string& str);
    void Function(std::string& str);
};

#endif //TOPERATION_H
