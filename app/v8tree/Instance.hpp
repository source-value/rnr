#pragma once
#include <stdexcept>
#include <memory>
#include <vector>
#include <functional>
#include <map>

#include <reflection/Variant.hpp>

namespace RNR {
class DataModel;

class Instance : public Reflection::Variant {
  HAS_REFLECTION_TABLE;
  VARIANT_DEFINE(Instance)

  Instance* parent;
  DataModel* datamodel;
  std::string name;
  std::vector<std::unique_ptr<Instance>> children;

public:
  Instance();
  virtual ~Instance() = default;

  /**
   * @brief this will set the parent of Instance to newparent
   * newparent will take ownership of this
   * 
   * @param newparent the new parent
   */
  void setParent(Instance* newparent);

  /**
   * @brief removes instance from children, ownership of the instance will be given to caller
   * 
   * @param child 
   * @return std::unique_ptr<Instance> 
   */
  std::unique_ptr<Instance> removeChild(Instance* child);

  /**
   * @brief adds a new child this will snatch ownership
   * 
   * @param new_child 
   */
  void addChild(std::unique_ptr<Instance> new_child);
};

typedef std::function<Instance* ()> InstanceConstructor;

class InstanceFactory {
  static std::map<std::string, InstanceConstructor> constructors;
public:
  static std::unique_ptr<Instance> create(std::string type);
};
} // namespace RNR