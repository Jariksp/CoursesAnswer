#include "TGenerationFile.h"

TGenerationFile* TGenerationFile::m_pInstance = nullptr;

void TGenerationFile::Run(const std::string& path) {
	auto buffer = Functional->ReadFile(path);
	Functional->ReplaceAll(buffer, "\t", "");
	m_vContent = Functional->Split(buffer, "\n");
}

void TGenerationFile::Remove(const std::string RemovePath) {
    for(auto& StringFromContainer : m_vContent)
        if(StringFromContainer.find(RemovePath) != std::string::npos) StringFromContainer.clear();
}

void TGenerationFile::Rewrite() {
	for(auto i = 0;i < m_vContent.size();++i) {
        if( m_vContent[i].find("REFLECTABLE(") != std::string::npos ) Functional->Reflactable(m_vContent[i]);
        if( m_vContent[i].find("FUNCTION(") != std::string::npos ) Functional->Function(m_vContent[i]);
	}
}

int TGenerationFile::WriteToFile(const std::string OutputFile) {
    std::ofstream output_file(OutputFile);
    if( !output_file.is_open() ) return -1;
    for(auto string : m_vContent) output_file << string;
    output_file.close();
}

TGenerationFile* TGenerationFile::GetInstance() {
	if(!m_pInstance) m_pInstance = new TGenerationFile;
	return m_pInstance;
}
