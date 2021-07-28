/*
责任链模式
Handler（AbstractManager）抽象接口
ConcreteHandler（JuniorManager IntermediateManager SeniorManager）实例处理者
Client 用户
*/
//抽象管理者
class AbstractManager{
	public:
	AbstractManager():m_supervisorManager(0),m_approvalLimit(0){}
	void SetNextManager(AbstractManager *manager);
	virtual void HandleRequest(const double &fee) = 0;

	protected:
	AbstractManager *m_supervisorManager;
	double m_approvalLimit;
};
//初级经理
class JuniorManager: public AbstractManager
{
	public:
	JuniorManager(const double &approvalLimit):AbstractManager()
	{
		m_approvalLimit = approvalLimit;
	}
	protected:
	void HandleRequest(const double &fee);
};
//高级经理
class SeniorManager:public AbstractManager
{
	public:
	SeniorManager(const double &approvalLimit):AbstractManager()
	{
		m_approvalLimit = approvalLimit;
	}
	protected:
	void HandleRequest(const double &fee);
};
class ChainOfPesponsibilityClient
{
	public:
	ChainOfPesponsibilityClient(){}

	void Run();
};