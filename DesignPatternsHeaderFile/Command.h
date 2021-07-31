/*
命令模式
Receiver（TV）具体实施和执行一个请求的对象
Command（Command）声明执行请求的接口
ConcreteCommand（TurnOnCommand TurnOffCommand NextChannelCommand LastChannelCommand）请求的具体实例
Invoker（RemoteControl）要求命令执行请求
Client 用户
*/

//实施和执行请求对象
class TV
{
	public:
	TV():m_channel(0){};
	void TurnOn();
	void TurnOff();
	void NextChannel();
	void LastChannel();
	private:
	int m_channel;
};
//TV命令的抽象类
class Command
{
	public:
	virtual void execute() = 0;
	protected:
	TV *m_tv;
};
//具体的命令类
class TurnOnCommand:public Command
{
	public:
	TurnOnCommand(TV *nPTV):Command(){
		m_tv = nPTV;
	}
	virtual void execute();
};
class TurnOffCommand:public Command
{
	public:
	TurnOffCommand(TV *nPTV):Command(){
		m_tv = nPTV;
	}
	virtual void execute();
};
class NextChannelCommand : public Command
{
	public:
	NextChannelCommand(TV *nPTV):Command()
	{
		m_tv= nPTV;
	}
	virtual void execute();
};
class LastChannelCommand : public Command
{
	public:
	LastChannelCommand(TV *nPTV):Command()
	{
		m_tv= nPTV;
	}
	virtual void execute();
};
//控制器 执行请求命令的类
class RemoteControl
{
	public: 
	static void operate(Command *command);
};
//客户端
class CommandModelClient
{
	public:
	CommandModelClient(){}
	void Run();
};
