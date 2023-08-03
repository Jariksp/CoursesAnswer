#ifndef TGENERATION_FILE_H
#define TGENERATION_FILE_H

#include "TOperation.h"

class TGenerationFile {
	public:
	TGenerationFile(TGenerationFile const&)=delete;
	void operator=(TGenerationFile const&)=delete;

	protected:
	TGenerationFile()=default;

	public:
	static TGenerationFile* GetInstance();

	public:
	void Run(const std::string& path);
	void Remove(const std::string StringToRemove);

	public:
	void Rewrite();
	int WriteToFile(const std::string OutputFile);

	public:
	std::unique_ptr<TOperation> Functional = std::make_unique<TOperation>();

	protected:
	std::vector<std::string> m_vContent;

	private:
	static TGenerationFile* m_pInstance;
};

#endif //TGENERATION_FILE_H


