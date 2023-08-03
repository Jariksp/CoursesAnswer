#ifndef ALLCLASSES_H
#define ALLCLASSES_H

#include <vector>
#include <string>

class TCommon {
	public:
	virtual std::string ToString();
};


class TBase : public TCommon {
	public:
	std::string ToString() override;

};

class TDerived : public TBase {
	public:
	std::string ToString() override;
};

class TDistributionGenerator : public TCommon {
	public:
	float GetRandomNumberFromZeroToOne();
	std::vector<float> GetRandomNumberWithSetRange(float max);
	std::string ToString() override;

	public:
	std::vector<float> vec;
};

class TParent : public TCommon {
	public:
	virtual std::string Name() { return "TBase"; }
	std::string ToString() override;
};

class TDerived1 : public TParent {
	public:
	std::string Name() override { return "TDerived1"; }
	std::string ToString() override;
};

class TDerived2 : public TParent {
	public:
	std::string Name() override { return "TDerived2"; }
	std::string ToString() override;
};

class TDerived3 : public TParent {
	public:
	std::string Name() override { return "TDerived3"; }
	std::string ToString() override;
};

#endif // !ALLCLASSES_H

