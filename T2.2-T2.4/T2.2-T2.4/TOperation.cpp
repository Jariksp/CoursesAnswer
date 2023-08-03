#include "TOperation.h"

std::vector<std::string> TOperation::Split(const std::string& str, const std::string& delimiter) {
    std::size_t start = 0;
    std::size_t end = 0;

    std::string token;
    std::vector<std::string> result;

    while( (end = str.find(delimiter, start) ) != std::string::npos) {
        token = str.substr(start, end - start);
        start = end + delimiter.length();
        result.push_back(token);
    }

    result.push_back( str.substr(start) );
    return result;
}

void TOperation::ReplaceAll(std::string& text, const std::string& from, const std::string& to) {
    if(from.empty()) return;

    std::size_t position = 0;
    while( (position = text.find(from, position) ) != std::string::npos) {
        text.replace(position, from.length(), to);
        position += to.length();
    }
}

std::vector<std::string> TOperation::SubStrsBetween(const std::string& text, const std::string& lhs, const std::string& rhs) {
    static unsigned s_uSplitSize = 2;

    std::vector<std::string> result;

    auto externToks = Split(text, lhs);
    if( externToks.size() >= s_uSplitSize) externToks.erase(externToks.begin() );

    for(auto& externTok : externToks) {
        auto innerToks = Split(externTok, rhs);
        if( innerToks.size()==s_uSplitSize) result.push_back(innerToks.front() );
    }

    return result;
}

std::string TOperation::ReadFile(const std::string& path) {
    std::ifstream file(path, std::ios::in | std::ios::binary);
    if(!file.is_open()) return {};

    std::string content( std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>{} );
    file.close();

    return content;
}

void TOperation::Reflactable(std::string& str) {
    auto tsome = std::make_unique<TOperation>();
    std::string modify;
    modify = tsome->SubStrsBetween(str, "REFLECTABLE(", ")")[0];
    modify += " ";
    modify += tsome->SubStrsBetween(str, ")", "{")[0];
    modify += ";\n";
    str = modify;
}

void TOperation::Function(std::string& str) {
    auto tsome = std::make_unique<TOperation>();
    std::string modify;
    tsome->ReplaceAll(str, ",", ":\n\t");
    tsome->ReplaceAll(str, " ", "");
    modify = tsome->SubStrsBetween(str, "FUNCTION(", ")")[0];
    str = modify;
    str += " ";

}