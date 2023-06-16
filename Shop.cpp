#include "Shop.h"

using namespace std;

void Shop::addItem(const string& key, const int& value) {
    items[key] = value;
}

void Shop::removeItemByKey(const string& key) {
    items.erase(key);
}

int Shop::findValueByKey(const string& key) {
    auto it = items.find(key);
    if (it != items.end()) {
        return it->second;
    }
    throw invalid_argument("Kay dose not exist");
}

string Shop::findKeyByValue(const int& value) {
    for (const auto& item : items) {
        if (item.second == value) {
            return item.first;
        }
    }
    return "";
}