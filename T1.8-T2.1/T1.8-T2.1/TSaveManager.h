#ifndef TSAVE_MANAGER_H
#define TSAVE_MANAGER_H

#include <vector>
#include <functional>
#include <memory>

class TSaveInfo;

class TSaveManager {	
	public:
	TSaveManager()=default;
	~TSaveManager()=default;

	public:
	void AddDate(std::shared_ptr<TSaveInfo> InputData);
	void RemoveDate(std::shared_ptr<TSaveInfo> Date);

	public:
	using TSaveFilter = std::function<bool(std::shared_ptr<TSaveInfo>,std::shared_ptr<TSaveInfo>)>;
	using TMapFilter = std::function<bool(std::shared_ptr<TSaveInfo>)>;

	public:
	std::vector <std::shared_ptr <TSaveInfo>> Sort(const TSaveFilter& filter);
	std::vector <std::shared_ptr<TSaveInfo>> Map(TMapFilter& filter);

	public:
	std::vector<std::shared_ptr<TSaveInfo>> vSavedInfoContainer;
};

#endif // TSAVE_MANAGER_H

