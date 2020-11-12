#pragma once
template <class R, class T>
class BaseComponent
{
public:
	//BaseComponent();
	//~BaseComponent();

	virtual R process(T) = 0;
};

