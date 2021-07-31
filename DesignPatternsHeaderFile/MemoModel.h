/*
备忘录模式
Memento（Memo）存储内部状态的结构
Caretaker（MemoContainer）保存内部状态结构的容器
Originator（LinuxShell）创建和加载存储状态的对象
Client 用户
*/
#include<string>
#include<deque>

#define MAX_MEMO_SIZE 20
//数据保存类
class Memo
{
	public:
	Memo(std::string str = ""):m_str(str){
		
	}
	std::string getState() const;
	void SetState(std::string &str);
	private:
	std::string m_str;
};
//保存类容器
class MemoContainer
{
	public:
	MemoContainer():m_CurrentPos(0){}
	void Save(Memo memo);
	Memo GoBack();
	private:
	std::deque<Memo> m_MemoContainer;
	int m_CurrentPos;
};

class LinuxShell
{
	public:
	LinuxShell(){}
	Memo Execute();
	void Type(std::string str);
	void Load(Memo memo);
	private:
	std::string m_Str;
};

class MemoClient
{
	public:
	MemoClient(){}
	void Run();
};