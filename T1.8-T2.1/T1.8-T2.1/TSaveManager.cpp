#include <algorithm>

#include "TSaveManager.h"
#include "TSaveInfo.h"

void TSaveManager::AddDate(std::shared_ptr<TSaveInfo> InputData) {
	vSavedInfoContainer.push_back(InputData);
}

void TSaveManager::RemoveDate(std::shared_ptr<TSaveInfo> Date) {
	auto filter = [Date](auto a) { return a->Date() == Date->Date(); };
	auto it = std::remove_if( vSavedInfoContainer.begin(), vSavedInfoContainer.end(), filter );
	vSavedInfoContainer.erase( it, vSavedInfoContainer.end() );
}

std::vector<std::shared_ptr<TSaveInfo>> TSaveManager::Sort(const TSaveFilter& filter) {
	auto OutVector = vSavedInfoContainer;
	std::sort( OutVector.begin(), OutVector.end(), filter );
	return OutVector;
}

std::vector<std::shared_ptr<TSaveInfo>> TSaveManager::Map(TMapFilter& filter) {
	std::vector<std::shared_ptr<TSaveInfo>> OutVector;
	for(auto& savedInfo : vSavedInfoContainer) if( filter(savedInfo) ) OutVector.push_back(savedInfo);
	return OutVector;
}
