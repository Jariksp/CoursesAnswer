#include "TGenerationFile.h"

#define REFLECTABLE(...)
#define FUNCTION(...)
#define PROPERTY(...)

int main() {

    auto engine = TGenerationFile::GetInstance();
    engine->Run("\TObject.txt");
    engine->Rewrite();
    //engine->Remove("FUNCTION");
    //engine->Remove("REFLECTABLE");
    engine->WriteToFile("\TObject.reflection.cpp");
    return 0;
}



