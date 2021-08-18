/*
访问者模式
AbstractVisitor 抽象访问者，定义访问具体元素visit**的接口
AbstractElement 抽象元素，声明一个接受操作的accept接口
ConcreteVisitor（Doctor Chef）访问者实例，实现抽象访问者中声明的访问操作
ConcreteElement（Hospital Resteraunt）元素实例，实现抽象元素提供的accept操作，通常是visitor.visit**(this)
Client 用户
*/
class Hospital;
class Resteraunt;
//抽象访问者
class AbstractVisitor 
{
	public:
	virtual void VisitHospital(Hospital *place) = 0;
	virtual void VisitResteraunt(Resteraunt *place) = 0;
};
//具体访问者
class Doctor:public AbstractVisitor
{
	public:
	Doctor(){};
	virtual void VisitHospital(Hospital *place);
	virtual void VisitResteraunt(Resteraunt *place);
};
class Chef:public AbstractVisitor
{
	public:
	Chef(){};
	virtual void VisitHospital(Hospital *place);
	virtual void VisitResteraunt(Resteraunt *place);
};

//抽象元素
class AbstractElement
{
	public:
	AbstractElement(){};
	inline string GetName(){return name;}
	virtual void Accept(AbstractVisitor *visitor) = 0;
	protected:
	string name;
};

class Hosptal::AbstractElemt
{
	public:
	Hospital(string name){this->name = name;}
	virtual void Accept(AbstractVisitor *visitor);
};
class Resteraunt::AbstractElemt
{
	public:
	Resteraunt(string name){this->name = name;}
	virtual void Accept(AbstractVisitor *visitor);
};