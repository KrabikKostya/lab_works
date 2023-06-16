#ifndef SHOP_H
#define SHOP_H

#include <unordered_map>
#include <string>

class Shop {
public:
    void addItem(const std::string& key, const int& value);
    void removeItemByKey(const std::string& key);
    int findValueByKey(const std::string& key);
    std::string findKeyByValue(const std::int& value);

private:
    std::unordered_map<std::string, int> items;
};

#endif  // SHOP_H