
#pragma once
#include <stdio.h>
#include <string>
#include "base_component.h"
#include <map>

template <enum E>
class EnumPickerComponent : public BaseComponent<std::string, std::map<std::string, E>>
{
public:
	//BaseComponent();
	//~BaseComponent();

	virtual std::string process(std::map<std::string, E> map);
};

